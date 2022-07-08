#include "AttributeSet.h"

DND::AttributeSet::AttributeSet(){
	for (int i = 0; i <= ATTRIBUTES_LENGTH; i++)
		attributes[i] = 0;
}

DND::AttributeSet::AttributeSet(int strengthValue, int dexterityValue,
	int constitutionValue, int inteligenceValue, int wisdomValue, int charismaValue) {
	attributes[Attribute::Charisma] = charismaValue;
	attributes[Attribute::Constitution] = constitutionValue;
	attributes[Attribute::Dexterity] = dexterityValue;
	attributes[Attribute::Inteligence] = inteligenceValue;
	attributes[Attribute::Strength] = strengthValue;
	attributes[Attribute::Wisdom] = wisdomValue;
}

DND::AttributeSet::AttributeSet(int amt) {
	for (int i = 0; i <= ATTRIBUTES_LENGTH; i++)
		attributes[i] = amt;
}

DND::AttributeSet& DND::AttributeSet::operator+=(DND::AttributeSet const& other) {
	*this + other;
	return *this;
}

DND::AttributeSet DND::AttributeSet::operator+(DND::AttributeSet const & other) {
	for (int i = 0; i <= ATTRIBUTES_LENGTH; i++)
		attributes[i] += other.attributes[i];

	return *this;
}

DND::AttributeSet DND::AttributeSet::operator+(int amt) {
	for (int i = 0; i <= ATTRIBUTES_LENGTH; i++)
		attributes[i] += amt;

	return *this;
}

int DND::AttributeSet::getAttributeScore(DND::Attribute attr) const {
	return attributes[attr];
}

void DND::AttributeSet::increaseAttribute(DND::Attribute attr, int amt) {
	attributes[attr] += amt;
}