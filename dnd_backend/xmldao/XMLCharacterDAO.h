#include "ICharacterDao.h"
#include "LocalFileResolver.h"

namespace DND {
	
	/**
	 * @brief A DAO packaging the Character objects into local XML files.
	 * @author Dimitris Tsirmpas
	*/
	class XMLCharacterDAO : ICharacterDAO {
	public:

		void saveCharacter(const Character& updated) const override;

		std::unique_ptr<Character> loadCharacter(const std::string& characterName, const std::string& playerName) const override;

		void deleteCharacter(const Character& character) const override;

	private:
		serialization_details::LocalFileResolver resolver;

		void XMLCharacterDAO::createCharacter(const std::string& characterName, const std::string& playerName) const;

		void XMLCharacterDAO::updateCharacter(const Character& character) const;
	};
}
