#pragma once

namespace DND {

	namespace entity_details {
		const int ATTRIBUTES_LENGTH = 6;
	}
	

	/**
	 * @brief An enum describing the basic stats of a character.
	 * @author Dimitris Tsirmpas
	*/
	enum Attribute { // weakly typed enum because we need implicit int conversion for array indexes
		Strength,
		Dexterity,
		Constitution,
		Inteligence,
		Wisdom,
		Charisma
	};
}
