#include "pch.h"
#include "ObjectCounter.h"
#include "Currency.h"

using namespace DND::entity_details;

class ObjectCounterTest : public ::testing::Test {
protected:
	ObjectCounter<DND::Currency> wallet = ObjectCounter<DND::Currency>();

	virtual void setUp() {
		wallet = ObjectCounter<DND::Currency>();
	}
};

TEST_F(ObjectCounterTest, ConstructorTest) {
	for each (DND::Currency curr in CURRENCY_TYPES) {
		EXPECT_EQ(wallet.getAmount(curr), 0);
	}
}

TEST_F(ObjectCounterTest, SetterTest) {
	ASSERT_NO_THROW(CURRENCY_TYPES[0]);
	DND::Currency changed = CURRENCY_TYPES[0];

	EXPECT_ANY_THROW(wallet.setAmount(changed, -1));

	wallet.setAmount(changed, 56);
	EXPECT_EQ(wallet.getAmount(changed), 56);

	for each (DND::Currency curr in CURRENCY_TYPES) {
		if (curr != changed) {
			EXPECT_EQ(wallet.getAmount(curr), 0);
		}
	}

	wallet.setAmount(changed, 0);
	EXPECT_EQ(wallet.getAmount(changed), 0);
}

