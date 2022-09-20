
#include "Attribute.h"
#include <string>
#include <utility>
#include <algorithm>

namespace DND {
	
	std::string attributeToString(DND::Attribute attribute) {
		return entity_details::ATTRIBUTE_MAP.find(attribute)->second;
	}
	
	std::vector<Attribute> attributeValues() {
		std::vector<DND::Attribute> v;
		for each (auto it in entity_details::ATTRIBUTE_MAP) {
			v.push_back(it.first);
		}
		return v;
	}
	
	namespace entity_details {
		const std::unordered_map<Attribute, std::string> ATTRIBUTE_MAP = 
		 {
			std::make_pair(Attribute::Strength, "Strength"),
			std::make_pair(Attribute::Dexterity, "Dexterity"),
			std::make_pair(Attribute::Constitution, "Constitution"),
			std::make_pair(Attribute::Intelligence, "Intelligence"),
			std::make_pair(Attribute::Wisdom, "Wisdom"),
			std::make_pair(Attribute::Charisma, "Charisma"),
		};
	}
}
