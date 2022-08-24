#include "pch.h"
#include "XMLCharacterDAO.h"

using namespace DND;

class XMLTest : public ::testing::Test {
protected:
	ICharacterDAO* dao = setUpImpl();
	Character character = Character("characterName", "playerName");

	virtual void setUp() {
		dao = setUpImpl();
	}

	virtual void tearDown() {
		cleanUpTempDir();
		delete dao;
	}

	virtual ~XMLTest() {
		cleanUpTempDir();
	}

private:

	XMLCharacterDAO* setUpImpl() {
		setUpTempDir();
		return new XMLCharacterDAO(ROOT.string());
	}
};

TEST_F(XMLTest, testInvalidLoad) {
	EXPECT_ANY_THROW(dao->loadCharacter(character.getCharacterName(), character.getPlayerName()));
}

TEST_F(XMLTest, testSerialization) {
	character.setAC(45);

	dao->saveCharacter(character);

	std::unique_ptr<Character> char2 = dao->
		loadCharacter(character.getCharacterName(), character.getPlayerName());

	EXPECT_EQ(character.getCharacterName(), char2->getCharacterName());
	EXPECT_EQ(character.getPlayerName(), char2->getPlayerName());
	EXPECT_EQ(character.getAC(), char2->getAC());
}

TEST_F(XMLTest, testDelete) {
	EXPECT_FALSE(dao->deleteCharacter(character));
	
	dao->saveCharacter(character);
	dao->deleteCharacter(character);

	Path path = ROOT / character.getPlayerName() / (character.getCharacterName() + ".chr"); // this needs to be hardcoded :(
	EXPECT_FALSE(std::filesystem::exists(path));
}


