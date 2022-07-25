#include "Character.h"
#include <cmath>

using namespace DND;

std::string outOfBoundsErrorMessage(std::string field, int min, int max);

Character::Character(const std::string& charName, const std::string& playerName):
	characterName(charName), playerName(playerName), wallet(entity_details::ObjectCounter<Currency>()) {}


int Character::getAttributeScore(Attribute attr) const {
	AttributeSet& finalAttributes = race.getStats();

	finalAttributes += dndClass.getStats();
	finalAttributes += dndSubClass.getStats();
	finalAttributes += baseStats;
	finalAttributes += proficiencies.getBonusStats(level);

	return finalAttributes.getAttributeScore(attr);
}

int Character::getAmount(Currency type) const {
	return wallet.getAmount(type);
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

int Character::getLevel() const {
	return level;
}

Spells Character::getSpells() const {
	return spells;
}

std::string Character::getCharacterName() const {
	return characterName;
}

std::string Character::getPlayerName() const {
	return playerName;
}

StatModifier Character::getRace() const {
	return race;
}

StatModifier Character::getClass() const {
	return dndClass;
}

StatModifier Character::getSubclass() const {
	return dndSubClass;
}

std::string Character::getHdType() const {
	return hdType;
}

std::string Character::getBackground() const {
	return background;
}


void Character::setSpeed(int speed) {
	if (getSpeed() < MIN_SPEED || getSpeed() > MAX_SPEED)
		throw std::invalid_argument(outOfBoundsErrorMessage("Speed", MIN_SPEED, MAX_SPEED));

	this->speed = speed;
}

void Character::setAC(int ac) {
	if (getAC() < MIN_AC || getAC() > MAX_AC)
		throw std::invalid_argument(outOfBoundsErrorMessage("Armor Class", MIN_AC, MAX_AC));

	this->ac = ac;
}

void Character::setLevel(int level) {
	if (getLevel() < MIN_LEVEL || getLevel() > MAX_LEVEL)
		throw std::invalid_argument(outOfBoundsErrorMessage("Level", MIN_LEVEL, MAX_LEVEL));

	this->level = level;
}

void Character::addItem(Item& item) {
	items.insert(item);
}

void Character::removeItem(Item& item) {
	items.erase(item);
}

Items Character::getItems() const {
	return items;
}

void Character::setAmount(Currency type, int amt) {
	wallet.setAmount(type, amt);
}

void Character::addSpell(Spell& original) {
	spells.insert(original);
}

void Character::removeSpell(Spell& original) {
	spells.erase(original);
}

void Character::setHP(int amt) {
	if (getHP() < MIN_HP || getHP() > MAX_HP)
		throw std::invalid_argument(outOfBoundsErrorMessage("HP", MIN_HP, MAX_HP));

	hp = amt;
}

void Character::setRace(const StatModifier& race) {
	this->race = race;
}

void Character::setClass(const StatModifier& dndClass) {
	this->dndClass = dndClass;
}

void Character::setBackground(const std::string background) {
	this->background = background;
}

void Character::setSubClass(const StatModifier& dndSubClass) {
	this->dndSubClass = dndSubClass;
}

void Character::setProfiency(Attribute attr, bool isProficient) {
	if (isProficient) 
		proficiencies.addProficiency(attr);
	else 
		proficiencies.removeProficiency(attr);
}

std::unordered_set<Attribute> Character::getProfiencies() const {
	std::unordered_set<Attribute> set = std::unordered_set<Attribute>();
	
	for each (Attribute attr in AttributeSet::getAllAttributes()) {
		if (proficiencies.hasProficiency(attr)) {
			set.insert(attr);
		}
	}

	return set;
}

std::string outOfBoundsErrorMessage(std::string field, int min, int max) {
	return field + " can only be between " + std::to_string(min) + " and " + std::to_string(max);
}