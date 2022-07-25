#include "pch.h"
#include "ProficiencySet.h"

using namespace DND;

class ProficiencySetTest : public ::testing::Test {
protected:
	ProficiencySet set;

	virtual void setUp() {
		set = ProficiencySet();
	}

	static const Attributes getAllAttributes() {
		return DND::AttributeSet::getAllAttributes();
	}
};

TEST_F(ProficiencySetTest, TestProficiencies) {

	for each (Attribute attr in AttributeSet::getAllAttributes()) {
		EXPECT_FALSE(set.hasProficiency(attr));
	}

	set.addProficiency(Attribute::Charisma);
	set.addProficiency(Attribute::Constitution);

	for each (Attribute attr in  getAllAttributes()) {
		if (attr != Attribute::Charisma && attr != Attribute::Constitution)
			EXPECT_FALSE(set.hasProficiency(attr));
		else 
			EXPECT_TRUE(set.hasProficiency(attr));
	}

	set.removeProficiency(Attribute::Charisma);
	for each (Attribute attr in getAllAttributes()) {
		if (attr != Attribute::Constitution)
			EXPECT_FALSE(set.hasProficiency(attr));
		else
			EXPECT_TRUE(set.hasProficiency(attr));
	}
}


TEST_F(ProficiencySetTest, TestBonusStats) {
	EXPECT_EQ(set.getBonusStats(2), AttributeSet());
	EXPECT_EQ(set.getBonusStats(5), AttributeSet());

	set.addProficiency(Attribute::Dexterity);
	set.addProficiency(Attribute::Intelligence);
	AttributeSet bonus = set.getBonusStats(5);

	EXPECT_EQ(bonus.getAttributeScore(Attribute::Dexterity), 3);
	EXPECT_EQ(bonus.getAttributeScore(Attribute::Intelligence), 3);
	
	for each (Attribute attr in getAllAttributes()) {
		if (attr != Attribute::Dexterity && attr != Attribute::Intelligence)
			EXPECT_EQ(bonus.getAttributeScore(attr), 0);
	}
}