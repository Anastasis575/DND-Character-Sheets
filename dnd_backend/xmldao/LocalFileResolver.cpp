#include "LocalFileResolver.h"
#include <stdexcept>
#include <fstream>

using namespace DND::Serialization;
namespace fs = std::filesystem;

const std::string LocalFileResolver::EXTENSION = ".chr";

LocalFileResolver::LocalFileResolver(const Path& dataDirectory) :root(dataDirectory) {
	if (!fs::exists(dataDirectory)) {
		throw std::invalid_argument("Directory " + dataDirectory.string() + " does not exist");
	}
}

const Path LocalFileResolver::getCharacterFile(const Character& character) const {
	Path charPath = resolve(character);
	if (!fs::exists(charPath)) {
		throw std::invalid_argument("Directory " + charPath.string() + " does not exist");
	}
	return charPath;
}

const Path LocalFileResolver::createCharacterFile(const Character& character) const {
	Path charPath = resolve(character);
	
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

Path LocalFileResolver::resolve(const Character& character) const {
	return root / Path(character.getPlayerName()) / Path(character.getCharacterName()) / Path(EXTENSION);
}