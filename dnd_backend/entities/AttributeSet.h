#pragma once
#include "Attribute.h"
#include "EnumMap.h"

namespace DND {

	/**
	 * @brief A class representing the basic attributes of each character such as Strength, Charisma, Dexterity etc.
	 * @see Attribute
	 * @author Dimitris Tsirmpas
	*/
	class AttributeSet {

	public:

		/**
		 * @brief Create an AttributeSet with all-0 stats.
		*/
		AttributeSet();

		/**
		 * @brief Creates an AttributeSet inititalizing all the attributes with the specified amount
		 * @param amt the value of all stats
		 * @throws std::invalid_argument if any of the attributes go out of bounds
		*/
		AttributeSet(int amt);

		/**
		 * @brief Adds the scores for each attribute with that of another AttributeSet.
		 * @param The set whose attribute scores will be added.
		 * @return the modified AttributeSet for chaining
		 * @warning resulting AttributeSets MAY be out of bounds
		*/
		AttributeSet& operator+=(AttributeSet const&);
		
		/**
		 * @brief Adds the scores for each attribute with that of another AttributeSet.
		 * @param The set whose attribute scores will be added.
		 * @return the modified AttributeSet for chaining
		 * @warning resulting AttributeSets MAY be out of bounds
		*/
		AttributeSet operator+(AttributeSet const&) const;

		/**
		 * @brief Adds the scores for each attribute with a constant number each.
		 * @param The amount that will be added to each attribute's score.
		 * @return the modified AttributeSet for chaining
		 * @warning resulting AttributeSets MAY be out of bounds
		*/
		AttributeSet operator+(int) const;

		bool operator==(AttributeSet const &) const;

		bool operator!=(AttributeSet const&) const;

		/**
		 * @brief Return the score for the specified attribute.
		 * @param attr The attribute whose score will be returned.
		 * @return The score of the attribute.
		*/
		int getAttributeScore(Attribute attr) const;
		
		/**
		 * @brief Increase the score of the specified attribute by a constant amount.
		 * @param attr The attribute whose score will be increased.
		 * @param amt The amount that will be added to the attribute's score
		 * @throws std::invalid_argument if any of the attributes go out of bounds
		*/
		void setAttribute(Attribute attr, int amt);

	private:
		entity_details::EnumMap<Attribute> map;
	};
}
