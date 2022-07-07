#include "PlayerData.h"
#include <cmath>
#include <algorithm> 

//PlayerData::PlayerData(std::string charName){}


int PlayerData::getAttributeScore(Attribute attr) const {
	AttributeSet finalAttributes = race.getStats() + dndClass.getStats() +
		dndSubClass.getStats() + baseStats + backgroundStats +
		(AttributeSet(std::min((2 + static_cast<int>(floor((level - 1) / 4))), 6)) + proficiencyStats);

	for (auto tool : toolStatsList)
		finalAttributes += tool;

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

/// <summary>
/// Increases the level of the character by 1.
/// </summary>
void PlayerData::incrementLevel() {
	level++;
}

/// <summary>
/// Add an item to the character's inventory.
/// </summary>
/// <param name="itemName">The name of the item.</param>
/// <param name="statChanges">The changes to the player's stats, default is all 0.</param>
void PlayerData::addToInventory(std::string itemName, AttributeSet statChanges = AttributeSet::createEmpty()) {
	inventory.push_back(itemName);
	toolStatsList.push_back(statChanges);
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

/// <summary>
/// Write the contents of the characters with an XML file with the character's name as filename.
/// </summary>
void PlayerData::toFile() const {

}

/// <summary>
/// Flushes the contents of the characters with an XML file with the character's name as filename.
/// Unlike the toFile() function this method never throws and as such can exit without writing the data back to the file.
/// Always use toFile() before destroying the object.
/// </summary>
PlayerData::~PlayerData() {
	toFile();
}