#pragma once
#include <string>
#include <filesystem>

/// <summary>
/// An abstract class denoting any data class that can be written to a file.
/// All objects of this class will be written to their respective file at destruction.
/// </summary>
class Entity {

public:

	/// <summary>
	/// Write the contents of the characters with an XML file with the character's name as filename.
	/// </summary>
	virtual void toFile() = 0;

	/// <summary>
	/// Flushes the contents of the characters with an XML file with the character's name as filename.
	/// Unlike the toFile() function this method never throws and as such can exit without writing the data back to the file.
	/// Always use toFile() before destroying the object.
	/// </summary>
	virtual ~Entity() {
		toFile();
	}

protected:
	const static std::string baseDir;
};

const std::string Entity::baseDir = std::string(__FILE__).substr(0, std::string(__FILE__).find_last_of("/\\"));