#pragma once
/*File generated automatically by auto-enum.pyhttps://github.com/dimits-exe/CppAutomationTools*/ 
#include <unordered_map>

namespace DND {
	enum class Attribute {
		Strength,
		Dexterity,
		Constitution,
		Intelligence,
		Wisdom,
		Charisma,
	};
	
	
	std::string attributeToString(DND::Attribute attribute);
	
	
	std::vector<Attribute> attributeValues();
	
	namespace entity_details {
		extern const std::unordered_map<Attribute, std::string> ATTRIBUTE_MAP;
	}
}
