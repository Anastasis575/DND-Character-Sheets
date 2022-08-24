#include "ICharacterDAO.h"
#include "LocalFileResolver.h"

namespace DND {
	
	/**
	 * @brief A DAO packaging the Character objects into local XML files.
	 * @author Dimitris Tsirmpas
	*/
	class XMLCharacterDAO : public ICharacterDAO {
	public:
		XMLCharacterDAO(const std::string& root);

		void saveCharacter(const Character& updated) const override;

		std::unique_ptr<Character> loadCharacter(const std::string& characterName, const std::string& playerName) const override;

		bool deleteCharacter(const Character& character) const override;

	private:
		serialization_details::LocalFileResolver resolver;

		void createCharacter(const Character& character) const;

		void updateCharacter(const Character& character) const;
	};
}
