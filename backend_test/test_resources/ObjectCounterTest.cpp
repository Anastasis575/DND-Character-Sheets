#include "pch.h"
#include "ObjectCounter.h"
#include "Currency.h"

using namespace DND::entity_details;
typedef ObjectCounter<DND::Currency> CurrencyCounter;

class ObjectCounterTest : public ::testing::Test {
protected:
	CurrencyCounter wallet = CurrencyCounter();

	virtual void setUp() {
		wallet = CurrencyCounter();
	}
};

bool contains(const std::list<std::pair<DND::Currency, int>>& items, const DND::Currency& item, int amount) {
	return std::find(items.begin(), items.end(), std::make_pair(item, amount)) != items.end();
}

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

TEST_F(ObjectCounterTest, GetAllTest) {
	wallet.setAmount(DND::Currency::COPPER, 1);
	EXPECT_EQ(wallet.getAll().size(), 1);

	wallet.setAmount(DND::Currency::GOLD, 2);
	EXPECT_EQ(wallet.getAll().size(), 2);

	wallet.setAmount(DND::Currency::COPPER, 3);
	EXPECT_EQ(wallet.getAll().size(), 2);

	wallet.setAmount(DND::Currency::ELECTRUM, 4);
	EXPECT_EQ(wallet.getAll().size(), 3);
	wallet.setAmount(DND::Currency::COPPER, 0);

	auto all = wallet.getAll();
	EXPECT_EQ(all.size(), 2);
	EXPECT_TRUE(contains(all, DND::Currency::ELECTRUM, 4));
	EXPECT_TRUE(contains(all, DND::Currency::GOLD, 2));
}

TEST_F(ObjectCounterTest, TestSerialization) {
	testSerialization<CurrencyCounter>(wallet,
		[](const CurrencyCounter & a, const CurrencyCounter & b) {
			return a == b;
		});
}