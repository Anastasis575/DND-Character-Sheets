#pragma once
#include <string>
/*	
* Straight up include this because implementing the save/load procedures 
* without the access would need to implement setters to all classes and break
* encapsulation
*/
#include <boost/serialization/access.hpp>

namespace DND {
	/**
	 * @brief A class representing a DND item.
	 * @author Dimitris Tsirmpas
	*/
	class Item {
	public:
		Item(const std::string& itemName, const std::string& description) : name(itemName), description(description) {}
		Item(){} 

		std::string getName() const { return name; }
		std::string getDescription() const { return description; }

		template<class Archive>
		void serialize(Archive& ar, const unsigned int version) {
			ar& description;
			ar& name;
		}

	private:
		std::string name;
		std::string description;

		friend class boost::serialization::access;
	};

	inline bool operator == (Item const& lhs, Item const& rhs) {
		return (lhs.getName() == rhs.getName());
	}

}

namespace std {
	template <> struct hash<DND::Item> {
		size_t operator() (const DND::Item& item) const {
			std::hash<std::string> hasher;
			return hasher(item.getName());
		}
	};
}
