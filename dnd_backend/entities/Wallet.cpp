#include "Wallet.h"
#include <stdexcept>

DND::entity_details::Wallet::Wallet() {
	for each (Currency var in DND::entity_details::currencyTypes) {
		map.insert({var, 0});
	}
}

int DND::entity_details::Wallet::getCurrencyAmount(Currency type) const {
	return map.find(type)->second;
}

void DND::entity_details::Wallet::setCurrencyAmount(Currency type, int amt) {
	if (amt < 0) {
		throw std::invalid_argument("Currency amount can not be less than 0");
	}

	map.find(type)->second = amt;
}