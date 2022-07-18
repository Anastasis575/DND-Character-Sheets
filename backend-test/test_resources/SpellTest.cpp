#include "pch.h"
#include "Spell.h"

using namespace DND;

class SpellTest : public ::testing::Test {
protected:
	const std::string name = "TEST_NAME";
	const std::string description = "TEST_DESCRIPTION";
	const int level = 3;

	Spell* original = new Spell(name, description, level);

	virtual void setUp() {
		original = new Spell(name, description, level);
	}

	virtual void tearDown() {
		delete original;
	}
};


TEST_F(SpellTest, TestConstructor) {
	EXPECT_EQ(original->getName(), name);
	EXPECT_EQ(original->getDescription(), description);
	EXPECT_EQ(original->getLevel(), level);
}

TEST_F(SpellTest, TestEquality) {
	EXPECT_TRUE(*original == Spell(name, description, 6));
	EXPECT_FALSE(*original == Spell("ANOTHER NAME", description, 3));
}

TEST_F(SpellTest, TestImmutability) {
	std::string name = "Original";
	std::string description = "Original";
	int level = 3;
	Spell spell = Spell(name, description, level);

	name = "another name";
	description = "another description";
	level = 6;

	EXPECT_EQ(spell.getName(), "Original");
	EXPECT_EQ(spell.getDescription(), "Original");
	EXPECT_EQ(spell.getLevel(), 3);
}