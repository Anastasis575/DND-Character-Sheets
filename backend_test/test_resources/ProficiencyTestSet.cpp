#include "pch.h"
#include "ProficiencySet.h"

using namespace DND;

class ProficiencySetTest : public ::testing::Test {
protected:
	ProficiencySet set;

	virtual void setUp() {
		set = ProficiencySet();
	}

	static const std::vector<Attribute> getAllAttributes() {
		return attributeValues();
	}
};

TEST_F(ProficiencySetTest, TestProficiencies) {

	for each (Attribute attr in getAllAttributes()) {
		EXPECT_FALSE(set.hasProficiency(attr));
	}

	set.addProficiency(Attribute::CHARISMA);
	set.addProficiency(Attribute::CONSTITUTION);

	for each (Attribute attr in  getAllAttributes()) {
		if (attr != Attribute::CHARISMA && attr != Attribute::CONSTITUTION)
			EXPECT_FALSE(set.hasProficiency(attr));
		else 
			EXPECT_TRUE(set.hasProficiency(attr));
	}

	set.removeProficiency(Attribute::CHARISMA);
	for each (Attribute attr in getAllAttributes()) {
		if (attr != Attribute::CONSTITUTION)
			EXPECT_FALSE(set.hasProficiency(attr));
		else
			EXPECT_TRUE(set.hasProficiency(attr));
	}
}


TEST_F(ProficiencySetTest, TestBonusStats) {
	EXPECT_EQ(set.getBonusStats(2), AttributeSet());
	EXPECT_EQ(set.getBonusStats(5), AttributeSet());

	set.addProficiency(Attribute::DEXTERITY);
	set.addProficiency(Attribute::INTELLIGENCE);
	AttributeSet bonus = set.getBonusStats(5);

	EXPECT_EQ(bonus.getAttributeScore(Attribute::DEXTERITY), 3);
	EXPECT_EQ(bonus.getAttributeScore(Attribute::INTELLIGENCE), 3);
	
	for each (Attribute attr in getAllAttributes()) {
		if (attr != Attribute::DEXTERITY && attr != Attribute::INTELLIGENCE)
			EXPECT_EQ(bonus.getAttributeScore(attr), 0);
	}
}

TEST_F(ProficiencySetTest, TestSerialization) {
	testSerialization<ProficiencySet>(set,
		[](const ProficiencySet& a, const ProficiencySet& b) {

			for each (DND::Attribute attr in getAllAttributes()){
				if (a.hasProficiency(attr) != b.hasProficiency(attr)) {
					return false;
				}
			}
			return true;

		}
	);
}
