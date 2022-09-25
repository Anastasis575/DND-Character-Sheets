
#pragma once
/*File generated automatically by auto_enum.py https://github.com/dimits-exe/CppAutomationTools*/ 
#include <unordered_map>

namespace DND {
	/**
	* @brief An enum describing the basic stats of a character.
	* @author Dimitris Tsirmpas
	*/
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
