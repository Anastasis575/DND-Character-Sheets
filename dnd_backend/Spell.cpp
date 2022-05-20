#include "Spell.h"

Spell::Spell(const std::string& name, const std::string& description, int level): name(name), description(description), level(level) {}

std::string Spell::getName() const {
	return name;
}

std::string Spell::getDescription() const {
	return description;
}

int Spell::getLevel() const {
	return level;
}