#include "StatModifier.h"

StatModifier::StatModifier(std::string& name, AttributeSet& stats): name(name), stats(stats){}

StatModifier::StatModifier():name(""), stats(AttributeSet()){}

std::string StatModifier::getName() const {
	return name;
}

AttributeSet StatModifier::getStats() const {
	return stats;
}