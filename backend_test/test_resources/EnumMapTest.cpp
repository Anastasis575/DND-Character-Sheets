#include "pch.h"
#include "EnumMap.h"
#include "Currency.h"

using namespace DND::entity_details;

class EnumMapTest : public ::testing::Test {
protected:
	EnumMap<DND::Currency> wallet = EnumMap<DND::Currency>(CURRENCY_TYPES);

	virtual void setUp() {
		wallet = EnumMap<DND::Currency>(CURRENCY_TYPES);
	}
};

TEST_F(EnumMapTest, ConstructorTest) {
	for each (DND::Currency curr in CURRENCY_TYPES) {
		EXPECT_EQ(wallet.getAmount(curr), 0);
	}
}

TEST_F(EnumMapTest, SetterTest) {
	ASSERT_NO_THROW(CURRENCY_TYPES[0]);
	DND::Currency changed = CURRENCY_TYPES[0];

	wallet.setAmount(changed, 56);
	EXPECT_EQ(wallet.getAmount(changed), 56);

	for each (DND::Currency curr in CURRENCY_TYPES) {
		if (curr != changed) {
			EXPECT_EQ(wallet.getAmount(curr), 0);
		}
	}
}

