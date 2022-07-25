#pragma once
#include <stdexcept>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>

namespace DND {
	namespace entity_details {

		/**
		 * @brief An internal class that manages the amount for each value of any object.
		 * @author Dimitris Tsirmpas
		*/
		template<typename T>
		class ObjectCounter {
		public:
			ObjectCounter(){}

			/**
			 * @brief Sets the object's amount to the provided amount.
			 * @param type the enum's type
			 * @param amount the amount
			*/
			void setAmount(T type, int amt);

			/**
			 * @brief Get how many units of the specified object the collection posseses.
			 * @param object the object
			 * @return the amount of the object, 0 if the object wasn't inserted into the collection 
			*/
			int getAmount(T object) const;

			bool operator==(ObjectCounter const&) const;

			bool operator!=(ObjectCounter const&) const;


		private:
			std::unordered_map<T, int> map;
		};
	}
}

template<typename T>
int DND::entity_details::ObjectCounter<T>::getAmount(T type) const {
	if (map.count(type) == 0)
		return 0;
	else
		return map.at(type);
}

template<typename T>
void DND::entity_details::ObjectCounter<T>::setAmount(T type, int amt) {
	if (amt < 0)
		throw std::invalid_argument("Object counter can't be less than 0");
	else if (amt == 0) 
		map.erase(type);
	else
		map[type] = amt;		
}

template<typename T>
bool DND::entity_details::ObjectCounter<T>::operator==(ObjectCounter const& other) const {
	return map == other.map;
}

template<typename T>
bool DND::entity_details::ObjectCounter<T>::operator!=(ObjectCounter const& other) const {
	return !(*this == other)
}