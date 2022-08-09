#include "pch.h"
#include "SkillSet.h"

using namespace DND;
class SkillSetTest : public ::testing::Test {
protected:
	SkillSet set;

	virtual void setUp() {
		set = SkillSet();
	}

	static Skills allSkills() {
		return SkillSet::getAllSkills();
	}
};

TEST_F(SkillSetTest, TestProficiencies) {

	for each (Skill skill in allSkills()) {
		EXPECT_FALSE(set.isSkilledAt(skill));
	}
	
	set.addSkill(Skill::ANIMAL_HANDLING);
	set.addSkill(Skill::ACROBATICS);

	for each (Skill skill in  allSkills()) {
		if (skill != Skill::ANIMAL_HANDLING && skill != Skill::ACROBATICS)
			EXPECT_FALSE(set.isSkilledAt(skill));
		else
			EXPECT_TRUE(set.isSkilledAt(skill));
	}

	set.removeSkill(Skill::ANIMAL_HANDLING);
	for each (Skill skill in allSkills()) {
		if (skill != Skill::ACROBATICS)
			EXPECT_FALSE(set.isSkilledAt(skill));
		else
			EXPECT_TRUE(set.isSkilledAt(skill));
	}
}

TEST_F(SkillSetTest, TestSerialization) {
	testSerialization<SkillSet>(set,
		[](const SkillSet& a, const SkillSet& b) {
			for each (Skill skill in SkillSet::getAllSkills()){
				if (a.isSkilledAt(skill) != b.isSkilledAt(skill)) {
					return false;
				}
			}
			return true;
		});
}