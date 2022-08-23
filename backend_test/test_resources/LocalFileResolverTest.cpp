#include "pch.h"
#include "LocalFileResolver.h"
#include <cstdio>

using namespace DND::serialization_details;

typedef LocalFileResolver Resolver;

class ResolverTest : public ::testing::Test {
protected:
	static const Path ROOT;

	Resolver* resolver = setUpImpl();

	virtual void setUp() {
		resolver = setUpImpl();
	}

	virtual void tearDown() {
		bool deleted = cleanUpDir();
		if (!deleted) {
			throw "Bad cleanup";
		}
		
		delete resolver;
	}

	virtual ~ResolverTest() {
		cleanUpDir();
	}

private:
	Resolver* setUpImpl() {
		//delete dir if last test run here was interrupted
		cleanUpDir();

		std::filesystem::create_directory(ROOT);
		return new Resolver(ROOT);
	}

	int cleanUpDir() {
		return std::filesystem::remove_all(ROOT.string().c_str());
	}
};

const Path ResolverTest::ROOT = Path(__FILE__).parent_path() / "temp_dir";


TEST_F(ResolverTest, TestNonExistent) {
	EXPECT_ANY_THROW(resolver->getCharacterFile("NotSexMan", "SexPlayer"));
	EXPECT_ANY_THROW(resolver->getCharacterFile("SexMan", "NotSexPlayer"));
}


TEST_F(ResolverTest, TestCreation) {
	resolver->createCharacterFile("SexMan", "SexPlayer");

	Path expectedPath = ROOT / "SexPlayer" / "SexMan.chr";
	EXPECT_TRUE(std::filesystem::exists(expectedPath));
}


TEST_F(ResolverTest, TestFetchPath) {
	resolver->createCharacterFile("SexMan", "SexPlayer");

	Path expectedPath = ROOT / "SexPlayer" / "SexMan.chr";
	EXPECT_EQ(expectedPath, resolver->getCharacterFile("SexMan", "SexPlayer"));
}