#include "AttributeSet.h"

DND::AttributeSet::AttributeSet(){
	for (int i = 0; i <= DND::entity_details::ATTRIBUTES_LENGTH; i++)
		attributes[i] = 0;
}

DND::AttributeSet::AttributeSet(int strengthValue, int dexterityValue,
	int constitutionValue, int inteligenceValue, int wisdomValue, int charismaValue) {
	attributes[DND::Attribute::Charisma] = charismaValue;
	attributes[DND::Attribute::Constitution] = constitutionValue;
	attributes[DND::Attribute::Dexterity] = dexterityValue;
	attributes[DND::Attribute::Inteligence] = inteligenceValue;
	attributes[DND::Attribute::Strength] = strengthValue;
	attributes[DND::Attribute::Wisdom] = wisdomValue;
}

DND::AttributeSet::AttributeSet(int amt) {
	for (int i = 0; i <= DND::entity_details::ATTRIBUTES_LENGTH; i++)
		attributes[i] = amt;
}

DND::AttributeSet& DND::AttributeSet::operator+=(DND::AttributeSet const& other) {
	*this + other;
	return *this;
}

DND::AttributeSet DND::AttributeSet::operator+(DND::AttributeSet const & other) {
	for (int i = 0; i <= DND::entity_details::ATTRIBUTES_LENGTH; i++)
		attributes[i] += other.attributes[i];

	return *this;
}

DND::AttributeSet DND::AttributeSet::operator+(int amt) {
	for (int i = 0; i <= DND::entity_details::ATTRIBUTES_LENGTH; i++)
		attributes[i] += amt;

	return *this;
}

int DND::AttributeSet::getAttributeScore(DND::Attribute attr) const {
	return attributes[attr];
}

void DND::AttributeSet::increaseAttribute(DND::Attribute attr, int amt) {
	attributes[attr] += amt;
}