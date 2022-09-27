#include "pch.h"
#include "LevelSpellSlot.h"
#include "Rules.h"
#include <array>

using namespace DND;

class SpellSlotTest : public ::testing::Test {
protected:
	const std::array<int, 9> SLOT_VALUES{ 2,1,1,0,0,0,0,0,0 };
	LevelSpellSlot slot = LevelSpellSlot(SLOT_VALUES);

	virtual void setUp() {
		slot = LevelSpellSlot(std::array<int, 9>(SLOT_VALUES));
	}
};


TEST_F(SpellSlotTest, TestGetter) {
	for (unsigned int i = 0; i < SLOT_VALUES.size(); i++) {
		EXPECT_EQ(slot.getSpellSlots(i), SLOT_VALUES[i]);
	}
}

TEST_F(SpellSlotTest, TestSetter) {
	slot.spellUsed(0);
	EXPECT_EQ(slot.getSpellSlots(0), SLOT_VALUES[0] - 1);

	for (unsigned int i = 1; i < SLOT_VALUES.size(); i++) {
		EXPECT_EQ(slot.getSpellSlots(i), SLOT_VALUES[i]);
	}

	slot.spellUsed(8);
	EXPECT_EQ(slot.getSpellSlots(8), 0);
}

TEST_F(SpellSlotTest, TestRefresh) {
	slot.spellUsed(0);
	slot.spellUsed(0);
	slot.spellUsed(2);
	slot.spellUsed(4);

	slot.refresh();

	for (unsigned int i = 1; i < SLOT_VALUES.size(); i++) {
		EXPECT_EQ(slot.getSpellSlots(i), SLOT_VALUES[i]);
	}
}

TEST_F(SpellSlotTest, TestSerialization) {
	testSerialization<LevelSpellSlot>(slot,
		[this](const LevelSpellSlot& a, const LevelSpellSlot& b) {
			for (unsigned int i = 1; i < SLOT_VALUES.size(); i++) {
				if (a.getSpellSlots(i) != b.getSpellSlots(i))
					return false;
			}
			return true;
		});
}