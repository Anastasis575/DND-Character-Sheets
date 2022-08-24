#pragma once
#include "AttributeSet.h"
/*
* Straight up include this because implementing the save/load procedures
* without the access would need to implement setters to all classes and break
* encapsulation
*/
#include <boost/serialization/access.hpp>

namespace DND {

	/**
	 * @brief A class representing a Character's proficiencies and their effects on 
	 * the Character's stats.
	 * @author Dimitris Tsirmpas
	*/
	class ProficiencySet {
	public:

		/**
		 * @brief Build a new ProficiencySet with no proficiencies.
		*/
		ProficiencySet() {}

		/**
		 * @brief Adds a proficiency for a certain Attribute
		 * @param attr the attribute
		*/
		void addProficiency(Attribute attr);

		/**
		 * @brief Remove the proficiency for a certain Attribute
		 * @param attr the attribute
		*/
		void removeProficiency(Attribute attr);

		/**
		 * @brief Check if a character has proficiency in a certain attribute.
		 * @param attr the attribute
		 * @return true if the character has proficiency in that attribute
		*/
		bool hasProficiency(Attribute attr) const;

		/**
		 * @brief Get the the extra stats from the character's proficiencies
		 * @param level the level of the character
		 * @return an AttributeSet containing the extra stats from the character's proficiencies
		 * @throws std::invalid_argument if level is less than 1
		*/
		AttributeSet getBonusStats(int level) const;

	private:
		static const int NO_PROF = 0;
		static const int YES_PROF = 1;
		
		AttributeSet set;

		template<class Archive>
		void serialize(Archive& ar, const unsigned int file_version) {
			ar& set;
		}
		friend class boost::serialization::access;
	};
}

