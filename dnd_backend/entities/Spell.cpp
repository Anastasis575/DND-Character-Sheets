#include "Spell.h"
#include <stdexcept>

using namespace DND;
using namespace DND::entity_details;

Spell::Spell(const std::string& name, const std::string& description, int level)
	: name(name), description(description), level(level), prepared(false) {
	throwIfInvalidLevel();
}

Spell::Spell() : level(entity_details::DEFAULT_SPELL_LEVEL), prepared(false) {
	throwIfInvalidLevel();
}

std::string Spell::getName() const { return name; }

std::string Spell::getDescription() const { return description; }

int Spell::getLevel() const { return level; }

bool Spell::isPrepared() const { return prepared; }

void Spell::setPrepared(bool isPrepared) { this->prepared = isPrepared; }

 void Spell::throwIfInvalidLevel() const {
	 if (level < entity_details::MIN_SPELL_LEVEL || level > entity_details::MAX_SPELL_LEVEL) {
		 throw std::invalid_argument("Spell levels can only be between " +
			 std::to_string(entity_details::MIN_SPELL_LEVEL) + " and " +
			 std::to_string(entity_details::MAX_SPELL_LEVEL));
	 }
}