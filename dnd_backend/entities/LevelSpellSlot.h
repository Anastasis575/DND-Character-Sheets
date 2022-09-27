#pragma once
#include "ObjectCounter.h"
#include "Rules.h"

namespace DND {

	/**
	 * @brief A class holding the current and max spell slots for a certain level and character.
	 * @author Dimitris Tsirmpas
	*/
	class LevelSpellSlot {
	public:
		/**
		 * @brief Create a spell slot for a specific character level.
		 * @param maxSlots an array where maxSlots[spellLevel] = spellSlots for that spell level
		*/
		explicit LevelSpellSlot(const std::array<int, entity_details::MAX_SPELL_LEVEL>& maxSlots);

		/**
		 * @brief Get the spell slots for a spell level.
		 * @param spellLevel the spell level
		 * @return how many spell slots remain
		*/
		int getSpellSlots(int spellLevel) const;

		/**
		 * @brief Mark that a spell slot was temporarily consumed.
		 * @param spellLevel the level of the spell consumed
		*/
		void spellUsed(int spellLevel);

		/**
		 * @brief Reset the spell slots to the max slots.
		*/
		void refresh();


	private:
		entity_details::ObjectCounter<int> MAX_SLOTS; // effectively const, non-const because of serialization
		entity_details::ObjectCounter<int> currentSlots;
	};

}

