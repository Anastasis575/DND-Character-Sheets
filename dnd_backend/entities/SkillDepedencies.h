#pragma once
#include "Skill.h"
#include "Attribute.h"
#include <unordered_map>

namespace DND {

	Attribute getSkillDependency(Skill skill);

	namespace entity_details {
		extern const std::unordered_map<Skill, Attribute> SKILL_DEPENDENCY_MAP;
	}
}