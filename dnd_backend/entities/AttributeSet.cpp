#include "AttributeSet.h"
#include <stdexcept>
#include <string> 


DND::AttributeSet::AttributeSet(){
	for (int i = 0; i < DND::entity_details::ATTRIBUTES_LENGTH; i++)
		attributes[i] = 0;
	throwIfOutOfBounds();
}

DND::AttributeSet::AttributeSet(int strengthValue, int dexterityValue,
	int constitutionValue, int inteligenceValue, int wisdomValue, int charismaValue) {

	attributes[DND::Attribute::Charisma] = charismaValue;
	attributes[DND::Attribute::Constitution] = constitutionValue;
	attributes[DND::Attribute::Dexterity] = dexterityValue;
	attributes[DND::Attribute::Intelligence] = inteligenceValue;
	attributes[DND::Attribute::Strength] = strengthValue;
	attributes[DND::Attribute::Wisdom] = wisdomValue;

	throwIfOutOfBounds();
}

DND::AttributeSet::AttributeSet(int amt) {
	for (int i = 0; i < DND::entity_details::ATTRIBUTES_LENGTH; i++)
		attributes[i] = amt;
	throwIfOutOfBounds();
}

DND::AttributeSet& DND::AttributeSet::operator+=(DND::AttributeSet const& other) {
	*this + other;
	return *this;
}

DND::AttributeSet DND::AttributeSet::operator+(DND::AttributeSet const & other) {
	for (int i = 0; i < DND::entity_details::ATTRIBUTES_LENGTH; i++)
		attributes[i] += other.attributes[i];

	return *this;
}

DND::AttributeSet DND::AttributeSet::operator+(int amt) {
	for (int i = 0; i < DND::entity_details::ATTRIBUTES_LENGTH; i++)
		attributes[i] += amt;

	return *this;
}

int DND::AttributeSet::getAttributeScore(DND::Attribute attr) const {
	return attributes[attr];
}

void DND::AttributeSet::setAttribute(DND::Attribute attr, int amt) {
	if (amt < DND::MIN_ATTRIBUTE_VALUE || amt > MAX_ATTRIBUTE_VALUE) {
		throw std::invalid_argument("Character attributes must be between " + std::to_string(MIN_ATTRIBUTE_VALUE)
			+ " and " + std::to_string(MAX_ATTRIBUTE_VALUE));
	}

	attributes[attr] = amt;
}

void DND::AttributeSet::throwIfOutOfBounds() {
	for (int i = 0; i < DND::entity_details::ATTRIBUTES_LENGTH; i++) {

		if (attributes[i] < DND::MIN_ATTRIBUTE_VALUE || attributes[i] > MAX_ATTRIBUTE_VALUE) {
			throw std::invalid_argument("Character attributes must be between " + std::to_string(MIN_ATTRIBUTE_VALUE)
				+ " and " + std::to_string(MAX_ATTRIBUTE_VALUE));
		}

	}	
}