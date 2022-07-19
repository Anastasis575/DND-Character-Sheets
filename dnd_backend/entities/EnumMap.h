#pragma once
#include "Currency.h"

#include <vector>
#include <unordered_map>
#include <utility>

namespace DND {
	namespace entity_details {

		/**
		 * @brief An internal class that manages the amount for each value of an enum.
		 * @author Dimitris Tsirmpas
		*/
		template<typename T>
		class EnumMap {
		public:
			/**
			 * @brief Constructs a map by assigning 0 to all values provided.
			 * @param values all the possible values of the enum
			*/
			EnumMap(const std::vector<T>& values);

			/**
			 * @brief Sets the enum value's amount to the provided amount.
			 * @param type the enum's type
			 * @param amount the amount
			*/
			void setAmount(T type, int amt);

			/**
			 * @brief Get how many units of the specified enum value the character posseses.
			 * @param type the enum's type
			 * @return the amount of the enum's type
			*/
			int getAmount(T type) const;

			bool operator==(EnumMap const&) const;

			bool operator!=(EnumMap const&) const;


		private:
			std::unordered_map<T, int> map;
		};
	}
}

template<typename T>
DND::entity_details::EnumMap<T>::EnumMap(const std::vector<T>& values) {
	for each (const T var in values) {
		map.insert(std::make_pair(var, 0));
	}
}

template<typename T>
int DND::entity_details::EnumMap<T>::getAmount(T type) const {
	return map.find(type)->second;
}

template<typename T>
void DND::entity_details::EnumMap<T>::setAmount(T type, int amt) {
	map.find(type)->second = amt;
}

template<typename T>
bool DND::entity_details::EnumMap<T>::operator==(EnumMap const& other) const {
	return map == other.map;
}

template<typename T>
bool DND::entity_details::EnumMap<T>::operator!=(EnumMap const& other) const {
	return !(*this == other)
}