#pragma once
#include <vector>

namespace DND {
	
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
	enum class Attribute {
		Strength,
		Dexterity,
		Constitution,
		Intelligence,
		Wisdom,
		Charisma
		// if you modify this enum remember to change the vector in the .hpp file
	};

	namespace entity_details {
		extern const std::vector<Attribute> attributeTypes;
	}

}


namespace std {
	template <> struct hash<DND::Attribute> {
		size_t operator() (const DND::Attribute& t) const { return size_t(t); }
	};
}