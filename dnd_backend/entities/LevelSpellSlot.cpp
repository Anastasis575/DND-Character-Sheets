#include "LevelSpellSlot.h"
#include <array>

using namespace DND;
using namespace DND::entity_details;

LevelSpellSlot::LevelSpellSlot(const std::array<int, entity_details::MAX_SPELL_LEVEL>& maxSlots) {
	for (unsigned int i=0; i < maxSlots.size(); i++) {
		MAX_SLOTS.setAmount(i, maxSlots[i]);
		currentSlots.setAmount(i, maxSlots[i]);
	}
}

void LevelSpellSlot::refresh() {
	currentSlots = MAX_SLOTS;
}

void LevelSpellSlot::spellUsed(int spellLevel) {
	int currLvl = getSpellSlots(spellLevel);
	if (currLvl > 0) {
		currentSlots.setAmount(spellLevel, currLvl - 1);
	}
}

int LevelSpellSlot::getSpellSlots(int spellLevel) const {
	return currentSlots.getAmount(spellLevel);
}