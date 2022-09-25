#pragma once
#include <string>
#include <functional>
#include <cstdio>
#include <filesystem>
#include <fstream>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include "gtest/gtest.h"

typedef std::filesystem::path Path;

const Path ROOT = Path(__FILE__).parent_path() / "temp_dir";

/**
 * @brief Generate a random string
*/
std::string randomStr();

/**
 * @brief Delete temporary files used by a test case.
 * @return 1 if successfull
*/
int cleanUpTempDir();


/**
 * @brief Creates a new temp directory in ROOT to be used by a test case.
*/
void setUpTempDir();


/**
 * @brief Write an object to a file, then read it back and assert that their values are identical.
 * @tparam T the class of the object, needs to be default constructible
 * @param object an object with initialized custom values
 * @param comparator a function returning true if 2 objects are equal according to their values
*/
template<class T>
void testSerialization(const T & object, std::function<bool (const T&, const T&)> comparator) {
	std::string SERIALIZATION_FILE_NAME = randomStr();

	/*
	 * Text files need a terminating new line character at the end of the file which is appended when the archive 
	 * destructor is invoked. Be sure that an output archive on a stream is destroyed before opening an input archive 
	 * on that same stream.
	 * - library documentation
	 */
	{
		std::ofstream ofs;
		ofs.open(SERIALIZATION_FILE_NAME);
		boost::archive::text_oarchive oa(ofs);
		oa << object;
	}
	

	T other; //this does require a default constructor sadly
	{
		std::ifstream ifs;
		ifs.open(SERIALIZATION_FILE_NAME);
		boost::archive::text_iarchive ia(ifs);
		ia >> other;
	}
	

	EXPECT_TRUE(comparator(object, other));

	std::remove(SERIALIZATION_FILE_NAME.c_str());
}