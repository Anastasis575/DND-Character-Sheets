#include "pch.h"
#include "ProficiencySet.h"

using namespace DND;

class ProficiencySetTest : public ::testing::Test {
protected:
	ProficiencySet set;

	virtual void setUp() {
		set = ProficiencySet();
	}
};

TEST_F(ProficiencySetTest, TestProficiencies) {

	for each (Attribute attr in entity_details::ATTRIBUTE_TYPES) {
		EXPECT_FALSE(set.hasProficiency(attr));
	}

	Attribute attr1 = entity_details::ATTRIBUTE_TYPES[0];
	Attribute attr2 = entity_details::ATTRIBUTE_TYPES[1];

	set.addProficiency(attr1);
	set.addProficiency(attr2);

	for each (Attribute attr in entity_details::ATTRIBUTE_TYPES) {
		if (attr != attr1 && attr != attr2) 
			EXPECT_FALSE(set.hasProficiency(attr));
		else 
			EXPECT_TRUE(set.hasProficiency(attr));
	}

	set.removeProficiency(attr1);
	for each (Attribute attr in entity_details::ATTRIBUTE_TYPES) {
		if (attr != attr2)
			EXPECT_FALSE(set.hasProficiency(attr));
		else
			EXPECT_TRUE(set.hasProficiency(attr));
	}
}


TEST_F(ProficiencySetTest, TestBonusStats) {
	EXPECT_EQ(set.getBonusStats(2), AttributeSet());
	EXPECT_EQ(set.getBonusStats(5), AttributeSet());

	Attribute attr1 = entity_details::ATTRIBUTE_TYPES[0];
	Attribute attr2 = entity_details::ATTRIBUTE_TYPES[1];
	set.addProficiency(attr1);
	set.addProficiency(attr2);
	AttributeSet bonus = set.getBonusStats(5);

	EXPECT_EQ(bonus.getAttributeScore(attr1), 3);
	EXPECT_EQ(bonus.getAttributeScore(attr2), 3);
	
	for each (Attribute attr in entity_details::ATTRIBUTE_TYPES) {
		if (attr != attr1 && attr != attr2)
			EXPECT_EQ(bonus.getAttributeScore(attr), 0);
	}
}