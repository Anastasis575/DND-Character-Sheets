#include "LocalFileResolver.h"
#include <stdexcept>
#include <fstream>

using namespace DND::serialization_details;
namespace fs = std::filesystem;

const std::string LocalFileResolver::EXTENSION = ".chr";

LocalFileResolver::LocalFileResolver(const Path& dataDirectory) :root(dataDirectory) {
	if (!fs::exists(dataDirectory)) {
		throw std::invalid_argument("Directory " + dataDirectory.string() + " does not exist");
	}
}

const Path LocalFileResolver::getCharacterFile(const std::string& characterName, const std::string& playerName) const {
	Path charPath = resolve(characterName, playerName);
	if (!fs::exists(charPath)) {
		throw std::invalid_argument("Directory " + charPath.string() + " does not exist");
	}
	return charPath;
}

const Path LocalFileResolver::createCharacterFile(const std::string& characterName, const std::string& playerName) const {
	Path charPath = resolve(characterName, playerName);
	
	if (fs::exists(charPath)) {
		throw std::invalid_argument("File " + charPath.string() + " already exists");
	}

	// create player directory if not exists
	fs::create_directories(charPath.parent_path());

	// create empty file
	std::ofstream file;
	file.open(charPath.string()); 
	file.close();

	return charPath;
}

Path LocalFileResolver::resolve(const std::string& characterName, const std::string& playerName) const {
	bool whiteSpacesOnly = std::all_of(playerName.cbegin(), playerName.cend(), [](char c) { return std::isspace(c); });
	
	if (whiteSpacesOnly) {
		throw std::invalid_argument("Cannot save character for a blank user name");
	}

	return root / playerName / characterName / EXTENSION;
}