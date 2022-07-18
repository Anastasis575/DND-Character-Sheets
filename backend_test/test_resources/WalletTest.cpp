#include "pch.h"
#include "Wallet.h"

using namespace DND::entity_details;

class WalletTest : public ::testing::Test {
protected:
	Wallet wallet;

	virtual void setUp() {
		wallet = Wallet();
	}
};

TEST_F(WalletTest, ConstructorTest) {
	for each (DND::Currency curr in currencyTypes) {
		EXPECT_EQ(wallet.getCurrencyAmount(curr), 0);
	}
}

TEST_F(WalletTest, SetterTest) {
	ASSERT_NO_THROW(currencyTypes[0]);
	DND::Currency changed = currencyTypes[0];

	wallet.setCurrencyAmount(changed, 56);
	EXPECT_EQ(wallet.getCurrencyAmount(changed), 56);

	for each (DND::Currency curr in currencyTypes) {
		if (curr != changed) {
			EXPECT_EQ(wallet.getCurrencyAmount(curr), 0);
		}
	}
}

