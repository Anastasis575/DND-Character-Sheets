#include "Character.h"
#include <cmath>
#include <algorithm> 

using namespace DND;
//TODO: add parameter value checking

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

std::list<Spell> Character::getSpells() const {
	return spellList;
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
	this->speed = speed;
}

void Character::setAC(int ac) {
	this->ac = ac;
}

void Character::setLevel(int level) {
	this->level = level;
}

void Character::addToInventory(Item& item) {
	itemList.push_back(item);
}

void Character::setCurrencyAmount(Currency type, int amt) {
	currencyMap.find(type)->second += amt;
}

void Character::addSpell(Spell spell) {
	spellList.push_back(spell);
}

void Character::setHP(int amt) {
	hp += amt;
}
