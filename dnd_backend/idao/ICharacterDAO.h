#pragma once
#include "Character.h"
#include <string>
#include <memory>

namespace DND {
	
	/**
	 * @brief An interface for objects that handle PlayerData's persistent storage.
	 * @author Dimitris Tsirmpas
	*/
	class ICharacterDAO {
	public:

		/**
		 * @brief Write the contents of the characters to persistent storage.
		 * @param data the character
		 * @throw if an IO error occurs
		*/
		virtual void saveCharacter(const Character& updated) const = 0;

		/**
		 * @brief Retrieve the data of the character with the specified name from persistent storage.
		 * @param characterName the character's name
		 * @param playerName the name of the player who created it
		 * @return a pointer to a character object initialized with all the saved data
		 * @throw if the player hasn't created a player with that name or if an IO error occurs 
		*/
		virtual std::unique_ptr<Character> loadCharacter(const std::string& characterName, const std::string& playerName) const = 0;
		
		/**
		 * @brief Delete a character from persistent storage.
		 * @param characterName the character's name
		 * @param playerName the name of the player who created it
		 * @return true if the file was deleted successfully
		*/
		virtual bool deleteCharacter(const Character& character) const = 0;

		virtual ~ICharacterDAO(){}
	};
}
