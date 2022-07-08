#include "Spell.h"

DND::Spell::Spell(const std::string& name, const std::string& description, int level): name(name), description(description), level(level) {}

std::string DND::Spell::getName() const {
	return name;
}

std::string DND::Spell::getDescription() const {
	return description;
}

int DND::Spell::getLevel() const {
	return level;
}