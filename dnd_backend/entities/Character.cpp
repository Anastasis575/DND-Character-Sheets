#include "Character.h"
#include <cmath>

using namespace DND;

std::string outOfBoundsErrorMessage(std::string field, int min, int max);

Character::Character(const std::string& charName, const std::string& playerName):
	characterName(charName), playerName(playerName), wallet(entity_details::ObjectCounter<Currency>()),
	alignment(Alignment::TRUE_NEUTRAL) {}

Character::Character() : characterName("N/A"), playerName("NON INITIALIZED CHARACTER"), 
alignment(Alignment::TRUE_NEUTRAL) {}

int Character::getAttributeScore(Attribute attr) const {
	AttributeSet finalAttributes = baseStats;

	finalAttributes += race.getStats();
	finalAttributes += proficiencies.getBonusStats(level);

	return finalAttributes.getAttributeScore(attr);
}

int Character::getAttributeModifier(Attribute attr) const {
	return (getAttributeScore(attr) - 10) / 2;
}

int Character::getSkillModifier(Skill skill) const {
	// modifier + proficiency if proficient
	Attribute relatedAttribute = getSkillDependency(skill);
	int bonus = proficiencies.getBonusStats(level).getAttributeScore(relatedAttribute);
	return getAttributeModifier(relatedAttribute) + bonus;
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

Race Character::getRace() const {
	return race;
}

std::string Character::getClass() const {
	return dndClass;
}

std::string Character::getSubclass() const {
	return dndSubClass;
}

std::string Character::getHdType() const {
	return hdType;
}

std::string Character::getBackground() const {
	return background;
}

void Character::setBaseStats(Attribute attr, int amt) {
	baseStats.setAttribute(attr, amt);
}

void Character::setSpeed(int speed) {
	if (getSpeed() < entity_details::MIN_SPEED || getSpeed() > entity_details::MAX_SPEED)
		throw std::invalid_argument(
			outOfBoundsErrorMessage("Speed", entity_details::MIN_SPEED, entity_details::MAX_SPEED));

	this->speed = speed;
}

void Character::setAC(int ac) {
	if (getAC() < entity_details::MIN_AC || getAC() > entity_details::MAX_AC)
		throw std::invalid_argument(
			outOfBoundsErrorMessage("Armor Class", entity_details::MIN_AC, entity_details::MAX_AC));

	this->ac = ac;
}

void Character::setLevel(int level) {
	if (getLevel() < entity_details::MIN_LEVEL || getLevel() > entity_details::MAX_LEVEL)
		throw std::invalid_argument(
			outOfBoundsErrorMessage("Level", entity_details::MIN_LEVEL, entity_details::MAX_LEVEL));

	this->level = level;
}

void Character::addItem(const Item& item) {
	int prev = items.getAmount(item);
	items.setAmount(item, prev+1);
}

void Character::removeItem(const Item& item) {
	int prev = items.getAmount(item);
	if(prev > 0)
		items.setAmount(item, prev - 1);
}

Items Character::getItems() const {
	auto charItems = items.getAll();
	return Items(charItems.begin(), charItems.end());
}

void Character::setAmount(Currency type, int amt) {
	wallet.setAmount(type, amt);
}

void Character::addSpell(const Spell& original) {
	spells.insert(original);
}

void Character::removeSpell(const Spell& original) {
	spells.erase(original);
}

void Character::setHP(int amt) {
	if (getHP() < entity_details::MIN_HP || getHP() > entity_details::MAX_HP)
		throw std::invalid_argument(
			outOfBoundsErrorMessage("HP", entity_details::MIN_HP, entity_details::MAX_HP));

	hp = amt;
}

void Character::setRace(const Race& race) {
	this->race = race;
}

void Character::setClass(const std::string& dndClass) {
	this->dndClass = dndClass;
}

void Character::setBackground(const std::string background) {
	this->background = background;
}

void Character::setSubClass(const std::string& dndSubClass) {
	this->dndSubClass = dndSubClass;
}

void Character::setProfiency(Attribute attr, bool isProficient) {
	if (isProficient) 
		proficiencies.addProficiency(attr);
	else 
		proficiencies.removeProficiency(attr);
}

Attributes Character::getProfiencies() const {
	Attributes set;
	
	for each (Attribute attr in attributeValues()) {
		if (proficiencies.hasProficiency(attr)) {
			set.insert(attr);
		}
	}

	return set;
}

boost::optional<std::string> Character::getIcon() const {
	return charIconPath;
}

void Character::removeIcon() {
	charIconPath.reset();
}

void Character::setIcon(std::string iconPath) {
	charIconPath.emplace(iconPath);
}

Alignment Character::getAlignment() const {
	return alignment;
}

void Character::setAlignment(Alignment alignment) {
	this->alignment = alignment;
}

void Character::spellUsed(const Spell & spell) {
	spellSlot.spellUsed(spell.getLevel());
}

void Character::setSpellSlots(const std::array<int, entity_details::MAX_SPELL_LEVEL>& newSlots) {
	spellSlot = LevelSpellSlot(newSlots);
}

void Character::refreshSpellSlots() {
	spellSlot.refresh();
}

int Character::getRemainingSpells(int spellLevel) const {
	return spellSlot.getSpellSlots(spellLevel);
}

std::string outOfBoundsErrorMessage(std::string field, int min, int max) {
	return field + " can only be between " + std::to_string(min) + " and " + std::to_string(max);
}