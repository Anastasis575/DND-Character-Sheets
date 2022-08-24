#include "XMLCharacterDAO.h"
#include <cstdio>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace DND;

XMLCharacterDAO::XMLCharacterDAO(const std::string& root): resolver(root){}

void XMLCharacterDAO::saveCharacter(const Character& character) const {
	serialization_details::Path file = resolver.getCharacterFile(character.getCharacterName(), character.getPlayerName());

	if (std::filesystem::exists(file)) {
		std::cout << "updated" << std::endl;
		updateCharacter(character);
	} else {
		std::cout << "created" << std::endl;
		createCharacter(character);
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


bool XMLCharacterDAO::deleteCharacter(const Character& character) const {
	serialization_details::Path file = resolver.getCharacterFile(character.getCharacterName(), character.getPlayerName());
	return std::remove(file.string().c_str()) == 0; // path::c_str doesn't actually return a c_str lol
}


void XMLCharacterDAO::updateCharacter(const Character& character) const {
	serialization_details::Path file = resolver.getCharacterFile(character.getCharacterName(), character.getPlayerName());

	std::ofstream ofs;
	ofs.open(file);
	boost::archive::text_oarchive oa(ofs);
	oa << character;
}


void XMLCharacterDAO::createCharacter(const Character& character) const {
	resolver.createCharacterFile(character.getCharacterName(), character.getPlayerName());
	updateCharacter(character);
}
