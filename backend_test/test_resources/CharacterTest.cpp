#include "pch.h"
#include "CharacterBuilder.h"

using namespace DND;

class CharacterTest : public ::testing::Test {

protected:
	const std::string NAME = "PANOS";
	const StatModifier RACE = StatModifier("LAMROUPOULI", AttributeSet(3)); //todo: make meaningful
	const StatModifier CLASS = StatModifier("WORKING", AttributeSet(4));
	const StatModifier SUBCLASS = StatModifier("KOMMOUNISTIS", AttributeSet(5));

	Character character = CharacterBuilder(NAME).build();

	virtual void setUp() {
		character = CharacterBuilder(NAME).setRace(RACE).setClass(CLASS).setSubClass(SUBCLASS).build();
	}
};

TEST_F(CharacterTest, BuilderTest) {
	EXPECT_EQ(character.getName(), NAME);

	EXPECT_EQ(character.getRace().getName(), RACE.getName());
	EXPECT_EQ(character.getRace().getStats(), RACE.getStats());

	EXPECT_EQ(character.getClass().getName(), CLASS.getName());
	EXPECT_EQ(character.getClass().getStats(), CLASS.getStats());

	EXPECT_EQ(character.getSubclass().getName(), SUBCLASS.getName());
	EXPECT_EQ(character.getSubclass().getStats(), SUBCLASS.getStats());
}

TEST_F(CharacterTest, GetAttributeScoreTest) {
	// EXPECT_EQ(character.getAttributeScore(Attribute::Charisma))
}