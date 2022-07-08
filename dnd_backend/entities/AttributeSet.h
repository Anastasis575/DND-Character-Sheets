#pragma once
#include "Attribute.h"
#include <array>

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
		 * @brief Creates an AttributeSet inititalizing all the attributes with a default score of 0.
		 * @param strengthValue the value of the Strength stat
		 * @param dexterityValue the value of the Dexterity stat
		 * @param constitutionValue the value of the Constitution stat
		 * @param inteligenceValue the value of the Intelligence stat
		 * @param wisdomValue the value of the Wisdom stat
		 * @param charismaValue the value of the Charisma stat
		*/
		AttributeSet(int strengthValue, int dexterityValue,
			int constitutionValue, int inteligenceValue, int wisdomValue, int charismaValue); //high coupling?

		/**
		 * @brief Creates an AttributeSet inititalizing all the attributes with the specified amount
		 * @param amt the value of all stats
		*/
		AttributeSet(int amt);

		AttributeSet& operator+=(AttributeSet const&);
		
		/**
		 * @brief Adds the scores for each attribute with that of another AttributeSet.
		 * @param The set whose attribute scores will be added.
		 * @return the modified AttributeSet for chaining
		*/
		AttributeSet operator+(AttributeSet const&);

		/**
		 * @brief Adds the scores for each attribute with a constant number each.
		 * @param The amount that will be added to each attribute's score.
		 * @return the modified AttributeSet for chaining
		*/
		AttributeSet operator+(int);

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
		*/
		void increaseAttribute(Attribute attr, int amt);

	private:
		std::array<int, entity_details::ATTRIBUTES_LENGTH> attributes;
	};
}
