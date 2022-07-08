#include "..\idao\IPlayerDao.h" //TODO: make this not relative

namespace DND {
	
	/**
	 * @brief A DAO packaging the PlayerData into local XML files.
	*/
	class XMLPlayerDao : IPlayerDao {
	public:
		virtual PlayerData createPlayer(std::string name) override;

		virtual PlayerData getPlayer(std::string name) override;

		virtual void updatePlayer(PlayerData data) override;

		virtual void deletePlayer(std::string name) override;
	};
}
