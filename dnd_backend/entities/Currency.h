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
		extern const std::vector<Currency> CURRENCY_TYPES;
	}

}

namespace std {
	template <> struct hash<DND::Currency> {
		size_t operator() (const DND::Currency& t) const { return size_t(t); }
	};
}