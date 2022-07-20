#include "Character.h"
#include <cmath>

using namespace DND;

std::string outOfBoundsErrorMessage(std::string field, int min, int max);

Character::Character(const std::string& charName, const StatModifier& race, const StatModifier& dndClass,
	const StatModifier& dndSubClass, const std::string& hdType, const std::string& background, const AttributeSet& baseStats,
	const ProficiencySet& proficiencies, entity_details::EnumMap<Currency> wallet):
	name(charName), race(race), dndClass(dndClass), dndSubClass(dndSubClass), hdType(hdType),
	background(background), baseStats(baseStats), proficiencies(proficiencies), wallet(wallet){}


int Character::getAttributeScore(Attribute attr) const {
	AttributeSet& finalAttributes = race.getStats();

	finalAttributes += dndClass.getStats();
	finalAttributes += dndSubClass.getStats();
	finalAttributes += baseStats;
	finalAttributes += proficiencies.getBonusStats(level);

	return finalAttributes.getAttributeScore(attr);
}

int Character::getAmount(Currency type) const {
	// should never throw
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

SpellIterator Character::getSpells() const {
	return spells.begin();
}

std::string Character::getName() const {
	return name;
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
	if (this->hp < MIN_HP || this->hp > MAX_HP)
		throw std::invalid_argument(outOfBoundsErrorMessage("HP", MIN_HP, MAX_HP));

	hp = amt;
}

void Character::setProfiency(Attribute attr, bool isProficient) {
	if (isProficient) 
		proficiencies.addProficiency(attr);
	else 
		proficiencies.removeProficiency(attr);
}

std::unordered_set<Attribute> Character::getProfiencies() const {
	std::unordered_set<Attribute> set = std::unordered_set<Attribute>();
	
	//this is dumb but I want ProficiencySet to be as generic as it can be
	for each (Attribute attr in entity_details::attributeTypes) {
		if (proficiencies.hasProficiency(attr)) {
			set.insert(attr);
		}
	}

	return set;
}

std::string outOfBoundsErrorMessage(std::string field, int min, int max) {
	return field + " can only be between " + std::to_string(min) + " and " + std::to_string(max);
}