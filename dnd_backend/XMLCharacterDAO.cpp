#include "XMLCharacterDAO.h"
#include <cstdio>
#include <fstream>
#include <filesystem>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace DND;

void XMLCharacterDAO::saveCharacter(const Character& updated) const {
	serialization_details::Path file = resolver.getCharacterFile(updated.getCharacterName(), updated.getPlayerName());

	if (std::filesystem::exists(file)) {
		updateCharacter(updated);
	} else {
		createCharacter(updated.getCharacterName(), updated.getPlayerName());
	}
}


std::unique_ptr<Character> XMLCharacterDAO::loadCharacter(const std::string& characterName, 
	const std::string& playerName) const {
	serialization_details::Path file = resolver.getCharacterFile(characterName, playerName);

	Character* character = new Character(characterName, playerName);

	std::ifstream ifs;
	ifs.open(file);
	boost::archive::text_iarchive ia(ifs);
	ia >> *character;
	
	return std::unique_ptr<Character> (character);
}


void XMLCharacterDAO::deleteCharacter(const Character& character) const {
	serialization_details::Path file = resolver.getCharacterFile(character.getCharacterName(), character.getPlayerName());
	std::remove(file.string().c_str()); // path::c_str doesn't actually return a c_str lol
}


void XMLCharacterDAO::updateCharacter(const Character& character) const {
	serialization_details::Path file = resolver.getCharacterFile(character.getCharacterName(), character.getPlayerName());

	std::ofstream ofs;
	ofs.open(file);
	boost::archive::text_oarchive oa(ofs);
	oa << character;
}


void XMLCharacterDAO::createCharacter(const std::string& characterName, const std::string& playerName) const {
	resolver.createCharacterFile(characterName, playerName);
}
