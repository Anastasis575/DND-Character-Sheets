#pragma once
#include <stdexcept>
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
		class ObjectCounter {
		public:
			/**
			 * @brief Constructs a map by assigning 0 to all values provided.
			 * @param values all the possible values of the enum
			*/
			ObjectCounter(const std::vector<T>& values);

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

			bool operator==(ObjectCounter const&) const;

			bool operator!=(ObjectCounter const&) const;


		private:
			std::unordered_map<T, int> map;
		};
	}
}

template<typename T>
DND::entity_details::ObjectCounter<T>::ObjectCounter(const std::vector<T>& values) {
	for each (const T var in values) {
		map.insert(std::make_pair(var, 0));
	}
}

template<typename T>
int DND::entity_details::ObjectCounter<T>::getAmount(T type) const {
	auto result = map.find(type);
	if (result == map.end()) {
		throw std::invalid_argument("Provided type does not exist in the provided values");
	}
	return result->second;
}

template<typename T>
void DND::entity_details::ObjectCounter<T>::setAmount(T type, int amt) {
	auto result = map.find(type);
	if (result == map.end()) {
		throw std::invalid_argument("Provided type does not exist in the provided values");
	}
	result->second = amt;
}

template<typename T>
bool DND::entity_details::ObjectCounter<T>::operator==(ObjectCounter const& other) const {
	return map == other.map;
}

template<typename T>
bool DND::entity_details::ObjectCounter<T>::operator!=(ObjectCounter const& other) const {
	return !(*this == other)
}