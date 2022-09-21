#include "Race.h"

DND::Race::Race(const std::string& name, const DND::AttributeSet& stats): name(name), stats(stats){}

DND::Race::Race():name(""), stats(AttributeSet()){}

std::string DND::Race::getName() const {
	return name;
}

DND::AttributeSet DND::Race::getStats() const {
	return stats;
}