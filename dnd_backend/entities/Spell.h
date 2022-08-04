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
	 * @brief A record type holding information about a spell.
	 * @author Dimitris Tsirmpas
	*/
	class Spell {
	public:
		Spell(const std::string& name, const std::string& description, int level) 
			: name(name), description(description), level(level) {}

		std::string getName() const { return name; }
		std::string getDescription() const { return description; }
		int getLevel() const { return level; }

	private:
		const std::string name;
		const std::string description;
		const int level;
	};

	inline bool operator == (Spell const& lhs, Spell const& rhs) {
		return (lhs.getName() == rhs.getName());
	}
}

namespace std {
	template <> struct hash<DND::Spell> {
		size_t operator() (const DND::Spell& spell) const {
			std::hash<std::string> hasher;
			return hasher(spell.getName());
		}
	};
}

namespace boost {
	namespace serialization {

		template<class Archive>
		void serialize(Archive& ar, DND::Spell& spell, const unsigned int version) {
			ar& spell.description;
			ar& spell.name;
		}

	}
}