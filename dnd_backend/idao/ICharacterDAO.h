#include <string>

class Character;

namespace DND {
	
	/**
	 * @brief An interface for objects that handle PlayerData's persistent storage.
	 * @author Dimitris Tsirmpas
	*/
	class ICharacterDAO {
	public:
		
		/**
		 * @brief Create a character with the specified name and default parameters.
		 * @param characterName the character's name
		 * @param playerName the name of the player who created it
		 * @return an empty, initialized Character object
		*/
		virtual Character createCharacter(const std::string& characterName, const std::string& playerName) = 0;

		/**
		 * @brief Retrieve the data of the character with the specified name from persistent storage.
		 * @param characterName the character's name
		 * @param playerName the name of the player who created it
		 * @return a character object initialized with all the saved data
		*/
		virtual Character getCharacter(const std::string& characterName, const std::string& playerName) = 0;
		
		/**
		 * @brief Write the contents of the characters with an XML file with the character's name as filename.
		 * @param data the character's data
		*/
		virtual void updateCharacter(Character& data) = 0;
		
		/**
		 * @brief Delete a character from persistent storage.
		 * @param characterName the character's name
		 * @param playerName the name of the player who created it
		*/
		virtual void deleteCharacter(const std::string& characterName, const std::string& playerName) = 0;
	};
}
