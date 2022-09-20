
#include "Currency.h"
#include <string>
#include <utility>
#include <algorithm>

namespace DND {
	
	std::string currencyToString(DND::Currency currency) {
		return entity_details::CURRENCY_MAP.find(currency)->second;
	}
	
	std::vector<Currency> currencyValues() {
		std::vector<DND::Currency> v;
		for each (auto it in entity_details::CURRENCY_MAP) {
			v.push_back(it.first);
		}
		return v;
	}
	
	namespace entity_details {
		const std::unordered_map<Currency, std::string> CURRENCY_MAP = 
		 {
			std::make_pair(Currency::GOLD, "Gold"),
			std::make_pair(Currency::ELECTRUM, "Electrum"),
			std::make_pair(Currency::SILVER, "Silver"),
			std::make_pair(Currency::COPPER, "Copper"),
		};
	}
}
