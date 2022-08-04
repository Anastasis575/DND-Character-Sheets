#pragma once
#include <string>
#include <iostream>
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

		std::string getName() const { return name; }
		std::string getDescription() const { return description; }

	private:
		const std::string name;
		const std::string description;

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

namespace boost {
	namespace serialization {

		template<class Archive>
		void serialize(Archive& ar, DND::Item& item, const unsigned int version) {
			ar& item.description;
			ar& item.name;
		}

	} 
}