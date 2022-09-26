/*File generated automatically by auto_enum.py https://github.com/dimits-exe/CppAutomationTools */ 
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
			std::make_pair(Attribute::STRENGTH, "Strength"),
			std::make_pair(Attribute::DEXTERITY, "Dexterity"),
			std::make_pair(Attribute::CONSTITUTION, "Constitution"),
			std::make_pair(Attribute::INTELLIGENCE, "Intelligence"),
			std::make_pair(Attribute::WISDOM, "Wisdom"),
			std::make_pair(Attribute::CHARISMA, "Charisma"),
		};
	}
}
