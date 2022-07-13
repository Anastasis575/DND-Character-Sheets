#pragma once

namespace DND {

	namespace entity_details {
		const int ATTRIBUTES_LENGTH = 6;
	}
	
	/**
	 * @brief The minimum accepted value for any Attribute.
	 * @see Attribute
	*/
	const int MIN_ATTRIBUTE_VALUE = 0;

	/**
	 * @brief The maximum accepted value for any Attribute.
	 * @see Attribute
	*/
	const int MAX_ATTRIBUTE_VALUE = 20;

	/**
	 * @brief An enum describing the basic stats of a character.
	 * @author Dimitris Tsirmpas
	*/
	enum Attribute { // weakly typed enum because we need implicit int conversion for array indexes
		Strength,
		Dexterity,
		Constitution,
		Intelligence,
		Wisdom,
		Charisma
	};
}
