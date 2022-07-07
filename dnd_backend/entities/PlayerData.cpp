#include "PlayerData.h"
#include <cmath>
#include <algorithm> 

//TODO: add parameter value checking

PlayerData::PlayerData(const std::string& charName, const StatModifier& race, const StatModifier& dndClass,
	const StatModifier& dndSubClass, const std::string& hdType, const std::string& background, const AttributeSet& baseStats,
	const AttributeSet& backgroundStats, const AttributeSet& proficiencyStats):
	name(charName), race(race), dndClass(dndClass), dndSubClass(dndSubClass), hdType(hdType), background(background), baseStats(baseStats),
	backgroundStats(backgroundStats), proficiencyStats(proficiencyStats){}


int PlayerData::getAttributeScore(Attribute attr) const {
	AttributeSet& finalAttributes = race.getStats();

	finalAttributes += dndClass.getStats();
	finalAttributes += dndSubClass.getStats();
	finalAttributes += baseStats;
	finalAttributes += backgroundStats;
	finalAttributes += (AttributeSet(std::min((2 + static_cast<int>(floor((level - 1) / 4))), 6)) + proficiencyStats);

	return finalAttributes.getAttributeScore(attr);
}

int PlayerData::getCurrencyAmount(Currency type) const {
	// should never throw
	return currencyMap.find(type)->second;
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


void PlayerData::setSpeed(int speed) {
	this->speed = speed;
}

void PlayerData::setAC(int ac) {
	this->ac = ac;
}

void PlayerData::setLevel(int level) {
	this->level = level;
}

void PlayerData::addToInventory(Item& item) {
	itemList.push_back(item);
}

void PlayerData::setCurrencyAmount(Currency type, int amt) {
	currencyMap.find(type)->second += amt;
}

void PlayerData::addSpell(Spell spell) {
	spellList.push_back(spell);
}

void PlayerData::setHP(int amt) {
	hp += amt;
}

// ============= BUILDER ============= 

PlayerBuilder::PlayerBuilder(std::string name): name(name) {}

PlayerBuilder& PlayerBuilder::setLevel(int level) {
	this->level = level;
	return *(this);
}

PlayerBuilder& PlayerBuilder::setHp(int hp) {
	this->hp = hp;
	return *(this);
}

PlayerBuilder& PlayerBuilder::setAc(int ac) {
	this->ac = ac;
	return *(this);
}

PlayerBuilder& PlayerBuilder::setSpeed(int speed) {
	this->speed = speed;
	return *(this);
}

PlayerBuilder& PlayerBuilder::setGold(int gold) {
	this->gold = gold;
	return *(this);
}

PlayerBuilder& PlayerBuilder::setElectrum(int electrum) {
	this->electrum = electrum;
	return *(this);
}

PlayerBuilder& PlayerBuilder::setSilver(int silver) {
	this->silver = silver;
	return *(this);
}

PlayerBuilder& PlayerBuilder::setCopper(int copper) {
	this->copper = copper;
	return *(this);
}

PlayerBuilder& PlayerBuilder::setRace(StatModifier race) {
	this->race = race;
	return *(this);
}

PlayerBuilder& PlayerBuilder::setClass(StatModifier dndClass) {
	this->dndClass = dndClass;
	return *(this);
}

PlayerBuilder& PlayerBuilder::setSubClass(StatModifier subClass) {
	this->dndSubClass = subClass;
	return *(this);
}

PlayerBuilder& PlayerBuilder::setHdType(std::string hdType) {
	this->hdType = hdType;
	return *(this);
}

PlayerBuilder& PlayerBuilder::setBaseStats(AttributeSet baseStats) {
	this->baseStats = baseStats;
	return *(this);
}

PlayerBuilder& PlayerBuilder::setBackgroundStats(AttributeSet backgroundStats) {
	this->backgroundStats = backgroundStats;
	return *(this);
}

PlayerBuilder& PlayerBuilder::setProficiencyStats(AttributeSet proficiencyStats) {
	this->proficiencyStats = proficiencyStats;
	return *(this);
}

PlayerData PlayerBuilder::build() const {
	PlayerData& data = PlayerData(this->name, this->race, this->dndClass, this->dndSubClass,
		this->hdType, this->background, this->baseStats, this->backgroundStats, this->proficiencyStats);

	data.setLevel(this->level);
	data.setHP(this->hp);
	data.setAC(this->ac);
	data.setSpeed(this->speed);

	data.setCurrencyAmount(Currency::GOLD, this->gold);
	data.setCurrencyAmount(Currency::ELECTRUM, this->electrum);
	data.setCurrencyAmount(Currency::SILVER, this->silver);
	data.setCurrencyAmount(Currency::COPPER, this->copper);

	return data;
}
