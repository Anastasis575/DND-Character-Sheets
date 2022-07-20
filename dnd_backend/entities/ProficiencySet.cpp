#include "ProficiencySet.h"
#include <stdexcept>
#include <cmath>

using namespace DND;

void ProficiencySet::addProficiency(Attribute attr) {
	set.setAttribute(attr, YES_PROF);
}

void ProficiencySet::removeProficiency(Attribute attr) {
	set.setAttribute(attr, NO_PROF);
}

bool ProficiencySet::hasProficiency(Attribute attr) const {
	return set.getAttributeScore(attr) == YES_PROF;
}

AttributeSet ProficiencySet::getBonusStats(int level) const {
	if (level <= 0) {
		throw std::invalid_argument("Level can't be less than 1");
	}

	//1 + (total level/4), rounded up
	int bonusPoints = 1 + std::ceil(level / 4);
	AttributeSet bonus;
	
	for each (Attribute attr in entity_details::attributeTypes) {
		if (hasProficiency(attr)) {
			bonus.setAttribute(attr, bonusPoints);
		}
	}

	return bonus;
}