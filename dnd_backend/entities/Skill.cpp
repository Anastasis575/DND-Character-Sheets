#include "Skill.h"
#include <string>
#include <utility>
#include <algorithm>

namespace DND {
	
	std::string skillToString(DND::Skill skill) {
		return entity_details::SKILL_MAP.find(skill)->second;
	}
	
	std::vector<Skill> skillValues() {
		std::vector<DND::Skill> v;
		for each (auto it in entity_details::SKILL_MAP) {
			v.push_back(it.first);
		}
		return v;
	}
	
	namespace entity_details {
		const std::unordered_map<Skill, std::string> SKILL_MAP = 
		 {
			std::make_pair(Skill::ATHLETICS, "Athletics"),
			std::make_pair(Skill::ACROBATICS, "Acrobatics"),
			std::make_pair(Skill::SLEIGHT_OF_HAND, "Sleight_of_hand"),
			std::make_pair(Skill::STEALTH, "Stealth"),
			std::make_pair(Skill::ARCANA, "Arcana"),
			std::make_pair(Skill::HISTORY, "History"),
			std::make_pair(Skill::INVESTIGATION, "Investigation"),
			std::make_pair(Skill::NATURE, "Nature"),
			std::make_pair(Skill::RELIGION, "Religion"),
			std::make_pair(Skill::ANIMAL_HANDLING, "Animal_handling"),
			std::make_pair(Skill::INSIGHT, "Insight"),
			std::make_pair(Skill::MEDICINE, "Medicine"),
			std::make_pair(Skill::PERCEPTION, "Perception"),
			std::make_pair(Skill::SURVIVAL, "Survival"),
			std::make_pair(Skill::DECEPTION, "Deception"),
			std::make_pair(Skill::INTIMIDATION, "Intimidation"),
			std::make_pair(Skill::PERFORMANCE, "Performance"),
			std::make_pair(Skill::PERSUASION, "Persuasion"),
		};
	}
}
