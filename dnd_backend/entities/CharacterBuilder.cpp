#include "CharacterBuilder.h"

using namespace DND;

CharacterBuilder::CharacterBuilder(std::string name) : name(name), wallet(entity_details::currencyTypes){}

CharacterBuilder& CharacterBuilder::setLevel(int level) {
	this->level = level;
	return *this;
}

CharacterBuilder& CharacterBuilder::setHp(int hp) {
	this->hp = hp;
	return *this;
}

CharacterBuilder& CharacterBuilder::setAc(int ac) {
	this->ac = ac;
	return *this;
}

CharacterBuilder& CharacterBuilder::setSpeed(int speed) {
	this->speed = speed;
	return *this;
}

CharacterBuilder& CharacterBuilder::setCurrency(Currency currency, int amount) {
	wallet.setAmount(currency, amount);
	return *this;
}

CharacterBuilder& CharacterBuilder::setRace(StatModifier race) {
	this->race = race;
	return *this;
}

CharacterBuilder& CharacterBuilder::setClass(StatModifier dndClass) {
	this->dndClass = dndClass;
	return *this;
}

CharacterBuilder& CharacterBuilder::setSubClass(StatModifier subClass) {
	this->dndSubClass = subClass;
	return *this;
}

CharacterBuilder& CharacterBuilder::setHdType(std::string hdType) {
	this->hdType = hdType;
	return *this;
}

CharacterBuilder& CharacterBuilder::setBaseStats(AttributeSet baseStats) {
	this->baseStats = baseStats;
	return *this;
}

CharacterBuilder& CharacterBuilder::setProficiencyStats(ProficiencySet proficiencies) {
	this->proficiencies = proficiencies;
	return *this;
}

Character CharacterBuilder::build() const {
	Character& data = Character(this->name, this->race, this->dndClass, this->dndSubClass,
		this->hdType, this->background, this->baseStats, this->proficiencies, this->wallet);

	data.setLevel(this->level);
	data.setHP(this->hp);
	data.setAC(this->ac);
	data.setSpeed(this->speed);

	return data;
}
