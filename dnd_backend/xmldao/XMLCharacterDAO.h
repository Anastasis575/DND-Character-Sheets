#include "ICharacterDao.h"

namespace DND {
	
	/**
	 * @brief A DAO packaging the PlayerData into local XML files.
	 * @author Dimitris Tsirmpas
	*/
	class XMLCharacterDAO : ICharacterDAO {
	public:

		virtual Character createCharacter(const std::string& characterName, 
			const std::string& playerName) override;

		virtual Character getCharacter(const std::string& characterName, 
			const std::string& playerName) override;

		virtual void updateCharacter(Character& data) override;

		bool void deleteCharacter(const std::string& characterName, const std::string& playerName) override;
	};
}
