#include "CharacterBuilder.h"

using namespace DND;

CharacterBuilder::CharacterBuilder(std::string name) : name(name) {}

CharacterBuilder& CharacterBuilder::setLevel(int level) {
	this->level = level;
	return *(this);
}

CharacterBuilder& CharacterBuilder::setHp(int hp) {
	this->hp = hp;
	return *(this);
}

CharacterBuilder& CharacterBuilder::setAc(int ac) {
	this->ac = ac;
	return *(this);
}

CharacterBuilder& CharacterBuilder::setSpeed(int speed) {
	this->speed = speed;
	return *(this);
}

CharacterBuilder& CharacterBuilder::setGold(int gold) {
	this->gold = gold;
	return *(this);
}

CharacterBuilder& CharacterBuilder::setElectrum(int electrum) {
	this->electrum = electrum;
	return *(this);
}

CharacterBuilder& CharacterBuilder::setSilver(int silver) {
	this->silver = silver;
	return *(this);
}

CharacterBuilder& CharacterBuilder::setCopper(int copper) {
	this->copper = copper;
	return *(this);
}

CharacterBuilder& CharacterBuilder::setRace(StatModifier race) {
	this->race = race;
	return *(this);
}

CharacterBuilder& CharacterBuilder::setClass(StatModifier dndClass) {
	this->dndClass = dndClass;
	return *(this);
}

CharacterBuilder& CharacterBuilder::setSubClass(StatModifier subClass) {
	this->dndSubClass = subClass;
	return *(this);
}

CharacterBuilder& CharacterBuilder::setHdType(std::string hdType) {
	this->hdType = hdType;
	return *(this);
}

CharacterBuilder& CharacterBuilder::setBaseStats(AttributeSet baseStats) {
	this->baseStats = baseStats;
	return *(this);
}

CharacterBuilder& CharacterBuilder::setBackgroundStats(AttributeSet backgroundStats) {
	this->backgroundStats = backgroundStats;
	return *(this);
}

CharacterBuilder& CharacterBuilder::setProficiencyStats(AttributeSet proficiencyStats) {
	this->proficiencyStats = proficiencyStats;
	return *(this);
}

Character CharacterBuilder::build() const {
	Character& data = Character(this->name, this->race, this->dndClass, this->dndSubClass,
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
