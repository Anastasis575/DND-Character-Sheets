#include "pch.h"
#include "Item.h"

using namespace DND;

class ItemTest : public ::testing::Test {
protected:
	Item original = Item("TEST_NAME", "TEST_DESCRIPTION");

	virtual void setUp() {
		original = Item("TEST_NAME", "TEST_DESCRIPTION");
	}
};

TEST_F(ItemTest, TestConstructor) {
	EXPECT_EQ(original.getName(), "TEST_NAME");
	EXPECT_EQ(original.getDescription(), "TEST_DESCRIPTION");
}

TEST_F(ItemTest, TestEquality) {
	EXPECT_TRUE(original == Item("TEST_NAME", "another description"));
	EXPECT_FALSE(original == Item("ANOTHER NAME", "TEST_DESCRPIPTION"));
}

TEST_F(ItemTest, TestImmutability) {
	std::string name = "Original";
	std::string description = "Original";
	Item item = Item(name, description);

	name = "another name";
	description = "another description";
	
	EXPECT_EQ(item.getName(), "Original");
	EXPECT_EQ(item.getDescription(), "Original");
}

TEST_F(ItemTest, TestSerialization) {
	testSerialization<Item>(original,
		[](const Item& a, const Item& b) {
			return a == b;
		}
	);
}
