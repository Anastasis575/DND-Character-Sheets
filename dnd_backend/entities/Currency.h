#pragma once
#include <vector>

namespace DND {

	/**
	 * @brief The currency types used in the DND economy.
	 * @author Dimitris Tsirmpas
	*/
	enum class Currency {
		GOLD,
		ELECTRUM,
		SILVER,
		COPPER
		// if you modify this enum remember to change the vector in the .hpp file
	};

	namespace entity_details {
		extern const std::vector<Currency> currencyTypes;
	}

}
