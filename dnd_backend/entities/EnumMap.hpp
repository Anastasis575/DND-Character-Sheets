#include "EnumMap.h"

template<typename T>
DND::entity_details::EnumMap<T>::EnumMap(const std::vector<T>& values) {
	for each (Currency var in values) {
		map.insert({var, 0});
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