#pragma once
#include "Currency.h"

#include <unordered_map>

namespace DND {
	namespace entity_details {
		/**
		 * @brief An internal class that manages the amount of the various currencies of a character.
		 * @author Dimitris Tsirmpas
		*/
		class Wallet {
		public:
			Wallet();

			/**
			 * @brief Sets the currency's amount to the provided amount.
			 * @param type the currency's type
			 * @param amount the amount
			 * @throws std::invalid_argument if the amt is less than 0
			*/
			void setCurrencyAmount(Currency type, int amt);

			/**
			 * @brief Get how many units of the specified currency the character posseses.
			 * @param type the currency's type
			 * @return the amount of this type of currency
			*/
			int getCurrencyAmount(Currency type) const;


		private:
			std::unordered_map<Currency, int> map;
		};
	}
}


