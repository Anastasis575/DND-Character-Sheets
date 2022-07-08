#include <string>


namespace DND {
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

	inline bool operator == (Item const& lhs, Item const& rhs) {
		return (lhs.getName() == rhs.getName());
	}

	struct ItemHasher {
		size_t operator()(const Item& item) const {
			std::hash<std::string> hasher;
			return hasher(item.getName());
		}
	};
}
