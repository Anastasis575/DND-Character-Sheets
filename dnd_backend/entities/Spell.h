#pragma once
#include "Rules.h"
#include <string>
#include <boost/serialization/access.hpp>

namespace DND {
	
	/**
	 * @brief A class holding information about a spell.
	 * @author Dimitris Tsirmpas
	*/
	class Spell {
	public:

		/**
		 * @brief Construct a new Spell. By default the Spell is unprepared.
		 * @param name the name of the spell, acts as a unique id
		 * @param description the description of the spell
		 * @param level the level of the spell
		 * @throws std::invalid_argument if the spell's level isn't valid
		*/
		Spell(const std::string& name, const std::string& description, int level);

		/**
		 * @brief To be used by the serialization library DO NOT USE.
		*/
		Spell();

		std::string getName() const;
		std::string getDescription() const;
		int getLevel() const;
		bool isPrepared() const;

		void setPrepared(bool isPrepared);

	private:
		//must be non-const for the serialization library
		std::string name;
		std::string description;
		int level;
		bool prepared;

		void throwIfInvalidLevel() const;

		friend class boost::serialization::access;

		template<class Archive>
		void serialize(Archive& ar, const unsigned int file_version) {
			ar& name;
			ar& description;
			ar& level;
			ar& prepared;
		}
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