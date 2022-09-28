#include "pch.h"
#include "Character.h"
#include <array>

using namespace DND;

class CharacterTest : public ::testing::Test {

protected:
	const AttributeSet& BASE_STATS = AttributeSet(2);
	const std::string& CHAR_NAME = "PANOS";
	const std::string& PLAYER_NAME = "SEX FROG";
	const Race& RACE = Race("LAMROUPOULI", AttributeSet(3));
	const std::string& CLASS = "WORKING";
	const std::string& SUBCLASS = "KOMMOUNISTIS";
	const std::array<int, entity_details::MAX_SPELL_LEVEL> VALUES = { 2, 1, 1, 0, 0, 0, 0, 0, 0 };

	Character* character = createCharacter();

	virtual void setUp() {
		createCharacter();
	}

	virtual void tearDown() {
		delete character;
	}

	Character * createCharacter() {
		character = new Character(CHAR_NAME, PLAYER_NAME);
		
		for each (Attribute attr in attributeValues()) {
			character->setBaseStats(attr, BASE_STATS.getAttributeScore(attr));
		}
		character->setRace(RACE);
		character->setClass(CLASS);
		character->setSubClass(SUBCLASS);
		character->setSpellSlots(VALUES);

		return character;
	}
};

bool contains(const Items& items, const Item& item, int amount);

TEST_F(CharacterTest, TestConstructor) {
	EXPECT_EQ(character->getPlayerName(), PLAYER_NAME);
	EXPECT_EQ(character->getCharacterName(), CHAR_NAME);

	EXPECT_EQ(character->getRace().getName(), RACE.getName());
	EXPECT_EQ(character->getRace().getStats(), RACE.getStats());

	EXPECT_EQ(character->getClass(), CLASS);

	EXPECT_EQ(character->getSubclass(), SUBCLASS);
}

TEST_F(CharacterTest, ProficiencyTest) {
	EXPECT_EQ(character->getProfiencies().size(), 0);
	
	character->setProfiency(Attribute::CHARISMA, true);
	character->setProfiency(Attribute::CONSTITUTION, true);
	character->setProfiency(Attribute::CHARISMA, true);
	auto profs = character->getProfiencies();

	EXPECT_EQ(profs.size(), 2);
	EXPECT_TRUE(profs.find(Attribute::CHARISMA) != profs.end());
	EXPECT_TRUE(profs.find(Attribute::CONSTITUTION) != profs.end());

	character->setProfiency(Attribute::CHARISMA, false);
	profs = character->getProfiencies();

	EXPECT_EQ(profs.size(), 1);
	EXPECT_TRUE(profs.find(Attribute::CHARISMA) == profs.end());
	EXPECT_TRUE(profs.find(Attribute::CONSTITUTION) != profs.end());
}

TEST_F(CharacterTest, GetAttributeScoreTest) {
	character->setProfiency(Attribute::CONSTITUTION, true);
	character->setLevel(1);

	EXPECT_EQ(character->getAttributeScore(Attribute::CHARISMA), 5);
	EXPECT_EQ(character->getAttributeScore(Attribute::CONSTITUTION), 7);

	character->setLevel(5);
	EXPECT_EQ(character->getAttributeScore(Attribute::CHARISMA), 5);
	EXPECT_EQ(character->getAttributeScore(Attribute::CONSTITUTION), 8);
}

TEST_F(CharacterTest, SetBaseStatsTest) {
	Attribute changed = Attribute::CHARISMA;
	character->setBaseStats(changed, 12);
	EXPECT_EQ(character->getAttributeScore(changed), 12 + RACE.getStats().getAttributeScore(changed));
}

TEST_F(CharacterTest, GetAttributeModifierTest) {
	Attribute changed = Attribute::CONSTITUTION;
	character->setBaseStats(changed, 12);
	EXPECT_EQ(character->getAttributeModifier(changed), 2);
}

TEST_F(CharacterTest, GetSkillTest) {
	Skill skill= Skill::ACROBATICS;
	EXPECT_EQ(character->getSkillModifier(skill), -2);

	character->setProfiency(getSkillDependency(skill), true);
	EXPECT_EQ(character->getSkillModifier(skill), 1);
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
	for each(Currency curr in currencyValues()) {
		EXPECT_EQ(character->getAmount(curr), 0);
	}

	Currency changed = Currency::COPPER;
	character->setAmount(changed, 45);

	for each (Currency curr in currencyValues()) {
		if(curr != changed)
			EXPECT_EQ(character->getAmount(curr), 0);
	}
	EXPECT_EQ(character->getAmount(changed), 45);
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

TEST_F(CharacterTest, TestAlignment) {
	EXPECT_EQ(character->getAlignment(), Alignment::TRUE_NEUTRAL);
	character->setAlignment(Alignment::CHAOTIC_EVIL);
	EXPECT_EQ(character->getAlignment(), Alignment::CHAOTIC_EVIL);
}

TEST_F(CharacterTest, TestGetSpellSlots) {
	for (unsigned int i = 0; i < VALUES.size(); i++) {
		EXPECT_EQ(character->getRemainingSpells(i), VALUES[i]);
	}
}

TEST_F(CharacterTest, TestRefresh) {
	Spell spell("Test spell", "descr", 0);
	character->spellUsed(spell);
	character->spellUsed(spell);

	character->refreshSpellSlots();

	for (unsigned int i = 0; i < VALUES.size(); i++) {
		EXPECT_EQ(character->getRemainingSpells(i), VALUES[i]);
	}
}

TEST_F(CharacterTest, TestSpellUsed) {
	Spell spell("Test spell", "descr", 0);
	character->spellUsed(spell);
	character->spellUsed(spell);

	EXPECT_EQ(character->getRemainingSpells(0), VALUES[0] - 2);

	for (unsigned int i = 1; i < VALUES.size(); i++) {
		EXPECT_EQ(character->getRemainingSpells(i), VALUES[i]);
	}
}

TEST_F(CharacterTest, TestSetSpellSlots) {
	const std::array<int, entity_details::MAX_SPELL_LEVEL> NEW_VALUES = { 3,2,2,2,2,2,2,0,9 };
	character->setSpellSlots(NEW_VALUES);

	for (unsigned int i = 0; i < NEW_VALUES.size(); i++) {
		EXPECT_EQ(character->getRemainingSpells(i), NEW_VALUES[i]);
	}
}

TEST_F(CharacterTest, TestSerialization) {
	testSerialization<Character>(*character,
		[](const Character& a, const Character& b) {
			/* 
			* There's little point in checking every field individually, as the 
			* test would need to be refactored every time someone added / removed one
			* Realistically at some point someone will forget and the whole test will
			* be rendered obsolete.
			*/
			return a.getCharacterName() == b.getCharacterName() &&
				a.getPlayerName() == b.getPlayerName();
		});
}

bool contains(const Items& items, const Item& item, int amount) {
	return std::find(items.begin(), items.end(), std::make_pair(item, amount)) != items.end();
}