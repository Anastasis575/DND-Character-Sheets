#include "pch.h"
#include "AttributeSet.h"
#include "AttributeSet.cpp"

using namespace DND;

class AttributeSetTest : public ::testing::Test {
protected:
	AttributeSet original;

	virtual void SetUp() {
		original = AttributeSet(2);
	}

	virtual void TearDown() {

	}
};

bool allEqualTo(const AttributeSet set, int strengthValue, int dexterityValue,
	int constitutionValue, int intelligenceValue, int wisdomValue, int charismaValue);

bool allEqualTo(const AttributeSet set, int amt);

TEST_F(AttributeSetTest, TestConstructor) {
	AttributeSet set = AttributeSet();

	EXPECT_TRUE(allEqualTo(set, 0));
}

TEST_F(AttributeSetTest, TestCustomConstructor) {
	AttributeSet set = AttributeSet(1, 2, 3, 4, 5, 6);

	EXPECT_TRUE(allEqualTo(set, 1, 2, 3, 4, 5, 6));
}

TEST_F(AttributeSetTest, TestConstantConstructor) {
	EXPECT_TRUE(allEqualTo(original, 2));
}

TEST_F(AttributeSetTest, TestOperatorAssign) {
	original += 2;
	EXPECT_TRUE(allEqualTo(original, 4));
}

TEST_F(AttributeSetTest, TestOperatorAdditionAttributeSet) {
	AttributeSet set2 = AttributeSet(6);

	AttributeSet set3 = original +set2;
	EXPECT_TRUE(allEqualTo(set3, 8));
}

TEST_F(AttributeSetTest, TestOperatorAdditionInteger) {
	AttributeSet set = original +2;

	EXPECT_TRUE(allEqualTo(set, 4));
}

TEST_F(AttributeSetTest, TestConstructorOverflow) {
	EXPECT_ANY_THROW(AttributeSet(788));
	EXPECT_ANY_THROW(AttributeSet(-1));
	EXPECT_ANY_THROW(AttributeSet(0, 0, -1, 2, 2, 2));
	EXPECT_ANY_THROW(AttributeSet(10000, 0, 6, 2, 2, 2));
}

TEST_F(AttributeSetTest, TestSetAttribute) {
	EXPECT_ANY_THROW(original.setAttribute(Attribute::Charisma, 789));
	EXPECT_FALSE(original.getAttributeScore(Attribute::Charisma) == 789);

	EXPECT_ANY_THROW(original.setAttribute(Attribute::Charisma, -1));
	EXPECT_FALSE(original.getAttributeScore(Attribute::Charisma) == -1);
}

bool allEqualTo(const AttributeSet set, int amt) {
	bool success = true;

	success &= set.getAttributeScore(Attribute::Charisma) == amt;
	success &= set.getAttributeScore(Attribute::Dexterity) == amt;
	success &= set.getAttributeScore(Attribute::Constitution) == amt;
	success &= set.getAttributeScore(Attribute::Intelligence) == amt;
	success &= set.getAttributeScore(Attribute::Strength) == amt;
	success &= set.getAttributeScore(Attribute::Wisdom) == amt;

	return success;
}

bool allEqualTo(const AttributeSet set, int strengthValue, int dexterityValue,
	int constitutionValue, int intelligenceValue, int wisdomValue, int charismaValue) {

	bool success = true;

	success &= set.getAttributeScore(Attribute::Charisma) == charismaValue;
	success &= set.getAttributeScore(Attribute::Dexterity) == dexterityValue;
	success &= set.getAttributeScore(Attribute::Constitution) == constitutionValue;
	success &= set.getAttributeScore(Attribute::Intelligence) == intelligenceValue;
	success &= set.getAttributeScore(Attribute::Strength) == strengthValue;
	success &= set.getAttributeScore(Attribute::Wisdom) == wisdomValue;

	return success;
}