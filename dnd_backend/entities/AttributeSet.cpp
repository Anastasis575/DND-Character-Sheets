#include "AttributeSet.h"
#include <stdexcept>
#include <string> 

const DND::Attributes DND::AttributeSet::getAllAttributes() {
	return Attributes(ATTRIBUTE_VALUES.begin(), ATTRIBUTE_VALUES.end());
}

DND::AttributeSet::AttributeSet(): map(entity_details::ObjectCounter<Attribute>() ){}

DND::AttributeSet::AttributeSet(int amt) : map(entity_details::ObjectCounter<Attribute>()) {
	for each (Attribute attribute in ATTRIBUTE_VALUES) {
		setAttribute(attribute, amt);
	}
}

DND::AttributeSet& DND::AttributeSet::operator+=(DND::AttributeSet const& other) {
	*this = *this + other;
	return *this;
}

DND::AttributeSet DND::AttributeSet::operator+(DND::AttributeSet const & other) const {
	AttributeSet newSet(*this);

	for each (Attribute attribute in ATTRIBUTE_VALUES) {
		newSet.setAttribute(attribute, getAttributeScore(attribute) + other.getAttributeScore(attribute));
	}

	return newSet;
}

DND::AttributeSet DND::AttributeSet::operator+(int amt) const {
	return *this + AttributeSet(amt);
}

bool DND::AttributeSet::operator==(DND::AttributeSet const& other) const {
	return other.map == this->map;
}

bool DND::AttributeSet::operator!=(DND::AttributeSet const& other) const {
	return !( *(this) == other );
}

int DND::AttributeSet::getAttributeScore(DND::Attribute attr) const {
	return map.getAmount(attr);
}

void DND::AttributeSet::setAttribute(DND::Attribute attr, int amt) {
	if (amt < MIN_ATTRIBUTE_VALUE || amt > MAX_ATTRIBUTE_VALUE) {
		throw std::invalid_argument("Character attributes must be between " + ::std::to_string(MIN_ATTRIBUTE_VALUE)
			+ " and " + ::std::to_string(MAX_ATTRIBUTE_VALUE));
	}

	map.setAmount(attr, amt);
}

const std::vector<DND::Attribute> DND::AttributeSet::ATTRIBUTE_VALUES = { 
		DND::Attribute::Strength,
		DND::Attribute::Dexterity,
		DND::Attribute::Constitution,
		DND::Attribute::Intelligence,
		DND::Attribute::Wisdom,
		DND::Attribute::Charisma
};