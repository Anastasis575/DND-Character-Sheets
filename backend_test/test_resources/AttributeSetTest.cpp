#include "pch.h"
#include "AttributeSet.h"

#include <iostream>

using namespace DND;

class AttributeSetTest : public ::testing::Test {
protected:
	AttributeSet original;

	virtual void SetUp() {
		original = AttributeSet(2);
	}

};

void expectAllEqualTo(const AttributeSet& set, int strengthValue, int dexterityValue,
	int constitutionValue, int intelligenceValue, int wisdomValue, int charismaValue);

void expectAllEqualTo(const AttributeSet& set, int amt);

TEST_F(AttributeSetTest, TestConstructor) {
	AttributeSet set = AttributeSet();

	expectAllEqualTo(set,0);
}

TEST_F(AttributeSetTest, TestConstantConstructor) {
	expectAllEqualTo(original, 2);
}

TEST_F(AttributeSetTest, TestOperatorAssign) {
	original += 2;
	expectAllEqualTo(original, 4);
}

TEST_F(AttributeSetTest, TestOperatorAdditionAttributeSet) {
	AttributeSet set2 = AttributeSet(6);
	AttributeSet set3 = original + set2;

	expectAllEqualTo(set2, 6);
	expectAllEqualTo(original, 2);
	expectAllEqualTo(set3, 8);
}

TEST_F(AttributeSetTest, TestOperatorAdditionInteger) {
	AttributeSet set = original + 2;

	expectAllEqualTo(original, 2);
	expectAllEqualTo(set, 4);
}

TEST_F(AttributeSetTest, TestConstructorOverflow) {
	EXPECT_ANY_THROW(AttributeSet(788));
	EXPECT_ANY_THROW(AttributeSet(-1));
	EXPECT_ANY_THROW(AttributeSet(10000));
}

TEST_F(AttributeSetTest, TestSetAttribute) {
	EXPECT_ANY_THROW(original.setAttribute(Attribute::Charisma, 789));
	EXPECT_FALSE(original.getAttributeScore(Attribute::Charisma) == 789);

	EXPECT_ANY_THROW(original.setAttribute(Attribute::Charisma, -1));
	EXPECT_FALSE(original.getAttributeScore(Attribute::Charisma) == -1);
}

TEST_F(AttributeSetTest, TestEqualsOperator) {
	AttributeSet same = AttributeSet(original);
	AttributeSet other = (original + 2);

	EXPECT_TRUE(original == same);
	expectAllEqualTo(original, 2);
	EXPECT_FALSE(original == other);
}

TEST_F(AttributeSetTest, TestNotEqualsOperator) {
	EXPECT_FALSE(original != AttributeSet(original));
	EXPECT_TRUE(original != (original + 2));
}

TEST_F(AttributeSetTest, TestSerialization) {
	testSerialization<AttributeSet>(original,
		[](const AttributeSet& a, const AttributeSet& b) {
			return a == b;
		});
}

void expectAllEqualTo(const AttributeSet& set, int amt) {
	return expectAllEqualTo(set, amt, amt, amt, amt, amt, amt);
}

void expectAllEqualTo(const AttributeSet& set, int strengthValue, int dexterityValue,
	int constitutionValue, int intelligenceValue, int wisdomValue, int charismaValue) {

	bool success = true;

	success &= set.getAttributeScore(Attribute::Charisma) == charismaValue;
	success &= set.getAttributeScore(Attribute::Dexterity) == dexterityValue;
	success &= set.getAttributeScore(Attribute::Constitution) == constitutionValue;
	success &= set.getAttributeScore(Attribute::Intelligence) == intelligenceValue;
	success &= set.getAttributeScore(Attribute::Strength) == strengthValue;
	success &= set.getAttributeScore(Attribute::Wisdom) == wisdomValue;

	std::cout << success << std::endl;
	EXPECT_TRUE(success);
}