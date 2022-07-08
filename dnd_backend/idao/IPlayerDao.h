#include "..\entities\PlayerData.h"

namespace DND {
	
	/**
	 * @brief An interface for objects that handle PlayerData's persistent storage.
	 * @author Dimitris Tsirmpas
	*/
	class IPlayerDao {
	public:
		
		/**
		 * @brief Create a character with the specified name and default parameters.
		 * @param name The character's name
		 * @return the character's data
		*/
		virtual PlayerData createPlayer(std::string name) = 0;

		/**
		 * @brief Retrieve the data of the character with the specified name from persistent storage.
		 * @param name The character's name
		 * @return The data of the character
		*/
		virtual PlayerData getPlayer(std::string name) = 0;
		
		/**
		 * @brief Write the contents of the characters with an XML file with the character's name as filename.
		 * @param data the character's data
		*/
		virtual void updatePlayer(PlayerData data) = 0;
		
		/**
		 * @brief Delete a character from persistent storage.
		 * @param name The name of the character
		*/
		virtual void deletePlayer(std::string name) = 0;
	};
}
