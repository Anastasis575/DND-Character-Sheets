#include <string>

/**
 * @brief A class representing a DND item.
 * @author Dimitris Tsirmpas
*/
class Item {
public:
	Item(std::string itemName, std::string description) : name(itemName), description(description) {}

	std::string getName() const { return name; }
	std::string getDescription() const { return description; }

private:
	const std::string name;
	const std::string description;
};