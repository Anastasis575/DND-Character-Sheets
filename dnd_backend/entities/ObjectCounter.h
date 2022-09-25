#pragma once
#include <stdexcept>
#include <list>
#include <unordered_map>
#include <utility>
/*
* Straight up include this because implementing the save/load procedures
* without the access would need to implement setters to all classes and break
* encapsulation
*/
#include <boost/serialization/access.hpp>
#include <boost/serialization/unordered_map.hpp>

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

			/**
			 * @brief Get all the objects with their corresponding count.
			 * @return a list of <object, amount> stored in the collection
			*/
			std::list<std::pair<T, int>> getAll() const;

			bool operator==(ObjectCounter const&) const;

			bool operator!=(ObjectCounter const&) const;

			template<class Archive>
			void serialize(Archive& ar, const unsigned int file_version) {
				ar& map;
			}

		private:
			std::unordered_map<T, int> map;
			friend class boost::serialization::access;
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
		throw std::invalid_argument("Object's count can't be less than 0");
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
	return !(*this == other);
}

template<typename T>
std::list<std::pair<T, int>> DND::entity_details::ObjectCounter<T>::getAll() const {
	std::list<std::pair<T, int>> items;

	for each (auto object in map) {
		items.push_back(std::make_pair(object.first, object.second));
	}

	return items;
}