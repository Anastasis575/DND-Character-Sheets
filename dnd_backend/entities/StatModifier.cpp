#include "StatModifier.h"

DND::StatModifier::StatModifier(std::string& name, DND::AttributeSet& stats): name(name), stats(stats){}

DND::StatModifier::StatModifier():name(""), stats(AttributeSet()){}

std::string DND::StatModifier::getName() const {
	return name;
}

DND::AttributeSet DND::StatModifier::getStats() const {
	return stats;
}