/*File generated automatically by auto_enum.py https://github.com/dimits-exe/CppAutomationTools */ 
#pragma once
#include <unordered_map>

namespace DND {
	enum class Skill {
		ATHLETICS,
		ACROBATICS,
		SLEIGHT_OF_HAND,
		STEALTH,
		ARCANA,
		HISTORY,
		INVESTIGATION,
		NATURE,
		RELIGION,
		ANIMAL_HANDLING,
		INSIGHT,
		MEDICINE,
		PERCEPTION,
		SURVIVAL,
		DECEPTION,
		INTIMIDATION,
		PERFORMANCE,
		PERSUASION,
	};
	
	
	std::string skillToString(DND::Skill skill);
	
	
	std::vector<Skill> skillValues();
	
	namespace entity_details {
		extern const std::unordered_map<Skill, std::string> SKILL_MAP;
	}
}
