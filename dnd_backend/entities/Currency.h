#pragma once
/*File generated automatically by auto-enum.pyhttps://github.com/dimits-exe/CppAutomationTools*/ 
#include <unordered_map>

namespace DND {
	enum class Currency {
		GOLD,
		ELECTRUM,
		SILVER,
		COPPER,
	};
	
	
	std::string currencyToString(DND::Currency currency);
	
	
	std::vector<Currency> currencyValues();
	
	namespace entity_details {
		extern const std::unordered_map<Currency, std::string> CURRENCY_MAP;
	}
}
