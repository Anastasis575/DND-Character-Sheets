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

	Skill skill1 = allSkills()[0];
	Skill skill2 = allSkills()[1];

	set.addSkill(skill1);
	set.addSkill(skill2);

	for each (Skill skill in  allSkills()) {
		if (skill != skill1 && skill != skill2)
			EXPECT_FALSE(set.isSkilledAt(skill));
		else
			EXPECT_TRUE(set.isSkilledAt(skill));
	}

	set.removeSkill(skill1);
	for each (Skill skill in allSkills()) {
		if (skill != skill2)
			EXPECT_FALSE(set.isSkilledAt(skill));
		else
			EXPECT_TRUE(set.isSkilledAt(skill));
	}
}