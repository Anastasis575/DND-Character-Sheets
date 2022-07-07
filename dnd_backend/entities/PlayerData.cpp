#include "PlayerData.h"
#include <cmath>
#include <algorithm> 

//PlayerData::PlayerData(std::string charName){}


int PlayerData::getAttributeScore(Attribute attr) const {
	AttributeSet& finalAttributes = race.getStats();

	finalAttributes += dndClass.getStats();
	finalAttributes += dndSubClass.getStats();
	finalAttributes += baseStats;
	finalAttributes += backgroundStats;
	finalAttributes += (AttributeSet(std::min((2 + static_cast<int>(floor((level - 1) / 4))), 6)) + proficiencyStats);

	return finalAttributes.getAttributeScore(attr);
}

int PlayerData::getCoins() const {
	return coins;
}

int PlayerData::getSpeed() const {
	return speed;
}

int PlayerData::getHP() const {
	return hp;
}

int PlayerData::getAC() const {
	return ac;
}

std::list<Spell> PlayerData::getSpells() const {
	return spellList;
}

std::string PlayerData::getRace() const {
	return race.getName();
}

std::string PlayerData::getName() const {
	return name;
}

std::string PlayerData::getClass() const {
	return dndClass.getName();
}

std::string PlayerData::getSubclass() const {
	return dndSubClass.getName();
}

std::string PlayerData::getHdType() const {
	return hdType;
}

std::string PlayerData::getBackground() const {
	return background;
}

void PlayerData::incrementLevel() {
	level++;
}

void PlayerData::addToInventory(Item& item) {
	itemList.push_back(item);
}

void PlayerData::changeCoins(int amt) {
	coins += amt;
}

void PlayerData::addSpell(Spell spell) {
	spellList.push_back(spell);
}

void PlayerData::changeHP(int amt) {
	hp += amt;
}
