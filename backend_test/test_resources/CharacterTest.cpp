#include "pch.h"
#include "Character.h"

using namespace DND;

class CharacterTest : public ::testing::Test {

protected:
	const std::string CHAR_NAME = "PANOS";
	const std::string PLAYER_NAME = "SEX FROG";
	const StatModifier RACE = StatModifier("LAMROUPOULI", AttributeSet(3)); //todo: make meaningful
	const StatModifier CLASS = StatModifier("WORKING", AttributeSet(4));
	const StatModifier SUBCLASS = StatModifier("KOMMOUNISTIS", AttributeSet(5));

	Character* character = createCharacter();

	virtual void setUp() {
		createCharacter();
	}

	virtual void tearDown() {
		delete character;
	}

	Character * createCharacter() {
		character = new Character(CHAR_NAME, PLAYER_NAME);
	
		character->setRace(RACE);
		character->setClass(CLASS);
		character->setSubClass(SUBCLASS);

		return character;
	}
};

TEST_F(CharacterTest, BuilderTest) {
	EXPECT_EQ(character->getPlayerName(), PLAYER_NAME);
	EXPECT_EQ(character->getCharacterName(), CHAR_NAME);

	EXPECT_EQ(character->getRace().getName(), RACE.getName());
	EXPECT_EQ(character->getRace().getStats(), RACE.getStats());

	EXPECT_EQ(character->getClass().getName(), CLASS.getName());
	EXPECT_EQ(character->getClass().getStats(), CLASS.getStats());

	EXPECT_EQ(character->getSubclass().getName(), SUBCLASS.getName());
	EXPECT_EQ(character->getSubclass().getStats(), SUBCLASS.getStats());
}

TEST_F(CharacterTest, GetAttributeScoreTest) {
	//EXPECT_EQ(character->getAttributeScore(Attribute::Charisma)
		 
}