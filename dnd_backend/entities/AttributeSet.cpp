#include "AttributeSet.h"

AttributeSet::AttributeSet(){
	for (int i = 0; i <= ATTRIBUTES_LENGTH; i++)
		attributes[i] = 0;
}

AttributeSet::AttributeSet(int strengthValue, int dexterityValue,
	int constitutionValue, int inteligenceValue, int wisdomValue, int charismaValue) {
	attributes[Attribute::Charisma] = charismaValue;
	attributes[Attribute::Constitution] = constitutionValue;
	attributes[Attribute::Dexterity] = dexterityValue;
	attributes[Attribute::Inteligence] = inteligenceValue;
	attributes[Attribute::Strength] = strengthValue;
	attributes[Attribute::Wisdom] = wisdomValue;
}

AttributeSet::AttributeSet(int amt) {
	for (int i = 0; i <= ATTRIBUTES_LENGTH; i++)
		attributes[i] = amt;
}

AttributeSet& AttributeSet::operator+=(AttributeSet const& other) {
	*this + other;
	return *this;
}

AttributeSet AttributeSet::operator+(AttributeSet const & other) {
	for (int i = 0; i <= ATTRIBUTES_LENGTH; i++)
		attributes[i] += other.attributes[i];

	return *this;
}

AttributeSet AttributeSet::operator+(int amt) {
	for (int i = 0; i <= ATTRIBUTES_LENGTH; i++)
		attributes[i] += amt;

	return *this;
}

int AttributeSet::getAttributeScore(Attribute attr) const {
	return attributes[attr];
}

void AttributeSet::increaseAttribute(Attribute attr, int amt) {
	attributes[attr] += amt;
}