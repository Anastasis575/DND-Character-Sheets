/*File generated automatically by auto_enum.py https://github.com/dimits-exe/CppAutomationTools */ 
#pragma once
#include <unordered_map>

namespace DND {
	/**
	* @brief An enum describing the basic stats of a character.
	* @author Dimitris Tsirmpas
	*/
	enum class Attribute {
		STRENGTH,
		DEXTERITY,
		CONSTITUTION,
		INTELLIGENCE,
		WISDOM,
		CHARISMA,
	};
	
	
	std::string attributeToString(DND::Attribute attribute);
	
	
	std::vector<Attribute> attributeValues();
	
	namespace entity_details {
		extern const std::unordered_map<Attribute, std::string> ATTRIBUTE_MAP;
	}
}
