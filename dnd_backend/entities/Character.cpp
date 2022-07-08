#include "Character.h"
#include <cmath>
#include <algorithm> 

using namespace DND;

std::string outOfBoundsErrorMessage(std::string field, int min, int max);

Character::Character(const std::string& charName, const StatModifier& race, const StatModifier& dndClass,
	const StatModifier& dndSubClass, const std::string& hdType, const std::string& background, const AttributeSet& baseStats,
	const AttributeSet& backgroundStats, const AttributeSet& proficiencyStats):
	name(charName), race(race), dndClass(dndClass), dndSubClass(dndSubClass), hdType(hdType), background(background), baseStats(baseStats),
	backgroundStats(backgroundStats), proficiencyStats(proficiencyStats){}


int Character::getAttributeScore(Attribute attr) const {
	AttributeSet& finalAttributes = race.getStats();

	finalAttributes += dndClass.getStats();
	finalAttributes += dndSubClass.getStats();
	finalAttributes += baseStats;
	finalAttributes += backgroundStats;
	finalAttributes += (AttributeSet(std::min((2 + static_cast<int>(floor((level - 1) / 4))), 6)) + proficiencyStats);

	return finalAttributes.getAttributeScore(attr);
}

int Character::getCurrencyAmount(Currency type) const {
	// should never throw
	return currencyMap.find(type)->second;
}

int Character::getSpeed() const {
	return speed;
}

int Character::getHP() const {
	return hp;
}

int Character::getAC() const {
	return ac;
}

SpellIterator Character::getSpells() const {
	return spells.begin();
}

std::string Character::getRace() const {
	return race.getName();
}

std::string Character::getName() const {
	return name;
}

std::string Character::getClass() const {
	return dndClass.getName();
}

std::string Character::getSubclass() const {
	return dndSubClass.getName();
}

std::string Character::getHdType() const {
	return hdType;
}

std::string Character::getBackground() const {
	return background;
}


void Character::setSpeed(int speed) {
	if (this->speed < MIN_SPEED || this->speed > MAX_SPEED)
		throw std::invalid_argument(outOfBoundsErrorMessage("Speed", MIN_SPEED, MAX_SPEED));

	this->speed = speed;
}

void Character::setAC(int ac) {
	if (this->ac < MIN_AC || this->ac > MAX_AC)
		throw std::invalid_argument(outOfBoundsErrorMessage("Armor Class", MIN_AC, MAX_AC));

	this->ac = ac;
}

void Character::setLevel(int level) {
	if (this->level < MIN_LEVEL || this->level > MAX_LEVEL)
		throw std::invalid_argument(outOfBoundsErrorMessage("Level", MIN_LEVEL, MAX_LEVEL));

	this->level = level;
}

void Character::addToInventory(Item& item) {
	items.insert(item);
}

void Character::removeFromInventory(Item& item) {
	items.erase(item);
}

ItemIterator Character::getItems() const {
	return items.begin();
}

void Character::setCurrencyAmount(Currency type, int amt) {
	currencyMap.find(type)->second += amt;
}

void Character::addSpell(Spell& spell) {
	spells.insert(spell);
}

void Character::removeSpell(Spell& spell) {
	spells.erase(spell);
}

void Character::setHP(int amt) {
	if (this->hp < MIN_HP || this->hp > MAX_HP)
		throw std::invalid_argument(outOfBoundsErrorMessage("HP", MIN_HP, MAX_HP));

	hp = amt;
}

std::string outOfBoundsErrorMessage(std::string field, int min, int max) {
	return field + " can only be between " + std::to_string(min) + " and " + std::to_string(max);
}