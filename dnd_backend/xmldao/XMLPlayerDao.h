#include "..\idao\IPlayerDao.h" //TODO: make this not relative

namespace DND {
	
	/**
	 * @brief A DAO packaging the PlayerData into local XML files.
	*/
	class XMLPlayerDao : IPlayerDao {
	public:
		virtual Character createPlayer(std::string name) override;

		virtual Character getPlayer(std::string name) override;

		virtual void updatePlayer(Character data) override;

		virtual void deletePlayer(std::string name) override;
	};
}
