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

bool contains(const Items& items, const Item& item, int amount);

TEST_F(CharacterTest, TestConstructor) {
	EXPECT_EQ(character->getPlayerName(), PLAYER_NAME);
	EXPECT_EQ(character->getCharacterName(), CHAR_NAME);

	EXPECT_EQ(character->getRace().getName(), RACE.getName());
	EXPECT_EQ(character->getRace().getStats(), RACE.getStats());

	EXPECT_EQ(character->getClass().getName(), CLASS.getName());
	EXPECT_EQ(character->getClass().getStats(), CLASS.getStats());

	EXPECT_EQ(character->getSubclass().getName(), SUBCLASS.getName());
	EXPECT_EQ(character->getSubclass().getStats(), SUBCLASS.getStats());
}

TEST_F(CharacterTest, ProficiencyTest) {
	EXPECT_EQ(character->getProfiencies().size(), 0);
	
	character->setProfiency(Attribute::Charisma, true);
	character->setProfiency(Attribute::Constitution, true);
	character->setProfiency(Attribute::Charisma, true);
	auto profs = character->getProfiencies();

	EXPECT_EQ(profs.size(), 2);
	EXPECT_TRUE(profs.find(Attribute::Charisma) != profs.end());
	EXPECT_TRUE(profs.find(Attribute::Constitution) != profs.end());

	character->setProfiency(Attribute::Charisma, false);
	profs = character->getProfiencies();

	EXPECT_EQ(profs.size(), 1);
	EXPECT_TRUE(profs.find(Attribute::Charisma) == profs.end());
	EXPECT_TRUE(profs.find(Attribute::Constitution) != profs.end());
}

TEST_F(CharacterTest, GetAttributeScoreTest) {
	character->setProfiency(Attribute::Constitution, true);
	character->setLevel(1);

	EXPECT_EQ(character->getAttributeScore(Attribute::Charisma), 12);
	EXPECT_EQ(character->getAttributeScore(Attribute::Constitution), 14);

	character->setLevel(5);
	EXPECT_EQ(character->getAttributeScore(Attribute::Charisma), 12);
	EXPECT_EQ(character->getAttributeScore(Attribute::Constitution), 15);
}

TEST_F(CharacterTest, ItemTest) {
	EXPECT_EQ(character->getItems().size(), 0);
	Item item1 = Item("TEST_ITEM1", "does stuff");
	Item item2 = Item("TEST_ITEM2", "does other stuff");
	Item item1_copy = Item(item1);

	character->addItem(item1);
	character->addItem(item2);
	character->addItem(item1_copy);
	Items items = character->getItems();

	EXPECT_EQ(items.size(), 2);
	EXPECT_TRUE(contains(items, item1, 2));
	EXPECT_TRUE(contains(items, item2, 1));

	character->removeItem(item2);
	items = character->getItems();

	EXPECT_TRUE(contains(items, item1, 2));
	EXPECT_FALSE(contains(items, item2, 1));
	EXPECT_EQ(items.size(), 1);
}

TEST_F(CharacterTest, SpellTest) {
	EXPECT_EQ(character->getItems().size(), 0);
	Spell spell1 = Spell("TEST_SPELL1", "does stuff", 1);
	Spell spell2 = Spell("TEST_SPELL2", "does other stuff", 4);

	character->addSpell(spell1);
	character->addSpell(spell2);
	Spells spells = character->getSpells();

	EXPECT_EQ(spells.size(), 2);
	EXPECT_NE(spells.find(spell1), spells.end());
	EXPECT_NE(spells.find(spell2), spells.end());

	character->removeSpell(spell1);
	spells = character->getSpells();

	EXPECT_EQ(spells.find(spell1), spells.end());
	EXPECT_NE(spells.find(spell2), spells.end());
	EXPECT_EQ(spells.size(), 1);
}

TEST_F(CharacterTest, TestCurrency) {
	for each(Currency curr in entity_details::CURRENCY_TYPES) {
		EXPECT_EQ(character->getAmount(curr), 0);
	}

	Currency changed = entity_details::CURRENCY_TYPES[0];
	character->setAmount(changed, 45);

	for each (Currency curr in entity_details::CURRENCY_TYPES) {
		if(curr != changed)
			EXPECT_EQ(character->getAmount(curr), 0);
	}
	EXPECT_EQ(character->getAmount(changed), 45);
}

TEST_F(CharacterTest, TestSkills) {
	Skills skills;
	EXPECT_EQ(character->getSkills().size(), 0);

	character->setSkill(Skill::ACROBATICS, true);
	character->setSkill(Skill::HISTORY, true);
	character->setSkill(Skill::INSIGHT, true);
	character->setSkill(Skill::ACROBATICS, true);

	skills = character->getSkills();

	EXPECT_EQ(skills.size(), 3);
	EXPECT_TRUE(skills.find(Skill::ACROBATICS) != skills.end());
	EXPECT_TRUE(skills.find(Skill::HISTORY) != skills.end());
	EXPECT_TRUE(skills.find(Skill::INSIGHT) != skills.end());

	character->setSkill(Skill::DECEPTION, false);
	skills = character->getSkills();

	EXPECT_EQ(skills.size(), 3);
	EXPECT_TRUE(skills.find(Skill::ACROBATICS) != skills.end());
	EXPECT_TRUE(skills.find(Skill::HISTORY) != skills.end());
	EXPECT_TRUE(skills.find(Skill::INSIGHT) != skills.end());

	character->setSkill(Skill::ACROBATICS, false);
	skills = character->getSkills();

	EXPECT_EQ(skills.size(), 2);
	EXPECT_TRUE(skills.find(Skill::ACROBATICS) == skills.end());
	EXPECT_TRUE(skills.find(Skill::HISTORY) != skills.end());
	EXPECT_TRUE(skills.find(Skill::INSIGHT) != skills.end());
}

TEST_F(CharacterTest, TestIcon) {
	EXPECT_FALSE(character->getIcon());

	std::string newIcon = "icon.ico";
	std::string altIcon = "icon2.ico";

	character->setIcon(newIcon);
	EXPECT_EQ(newIcon, character->getIcon());

	character->removeIcon();
	EXPECT_FALSE(character->getIcon());

	character->setIcon(newIcon);
	character->setIcon(altIcon);
	EXPECT_EQ(altIcon, character->getIcon());
}

bool contains(const Items& items, const Item& item, int amount) {
	return std::find(items.begin(), items.end(), std::make_pair(item, amount)) != items.end();
}