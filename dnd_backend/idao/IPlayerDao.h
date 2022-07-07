#include "..\entities\PlayerData.h"

/// <summary>
/// An interface for objects that handle PlayerData's persistent storage.
/// </summary>
/// <author>
/// Dimitris Tsirmpas
/// </author>
class IPlayerDao {
public:

	/// <summary>
	/// Create a character with the specified name and default parameters.
	/// </summary>
	/// <param name="name">The character's name</param>
	virtual PlayerData createPlayer(std::string name) = 0;

	/// <summary>
	/// Get the data of the character with the specified name from persistent storage.
	/// </summary>
	/// <param name="name">The character's name</param>
	/// <returns>The data of the character</returns>
	virtual PlayerData getPlayer(std::string name) = 0;

	/// <summary>
	/// Write the contents of the characters with an XML file with the character's name as filename.
	/// </summary>
	virtual void updatePlayer(PlayerData data) = 0;

	/// <summary>
	/// Delete a character from persistent storage.
	/// </summary>
	/// <param name="name">The name of the character</param>
	virtual void deletePlayer(std::string name) = 0;
};