#include "SkillDepedencies.h"

using namespace DND;

Attribute DND::getSkillDependency(Skill skill) {
	return entity_details::SKILL_DEPENDENCY_MAP.find(skill)->second;
}

const std::unordered_map<Skill, Attribute> entity_details::SKILL_DEPENDENCY_MAP = {
	{Skill::ATHLETICS, Attribute::STRENGTH},
	{Skill::ACROBATICS, Attribute::DEXTERITY},
	{Skill::SLEIGHT_OF_HAND, Attribute::DEXTERITY},
	{Skill::STEALTH, Attribute::DEXTERITY},
	{Skill::ARCANA, Attribute::INTELLIGENCE},
	{Skill::HISTORY, Attribute::INTELLIGENCE},
	{Skill::INVESTIGATION, Attribute::INTELLIGENCE},
	{Skill::NATURE, Attribute::INTELLIGENCE},
	{Skill::RELIGION, Attribute::INTELLIGENCE},
	{Skill::ANIMAL_HANDLING, Attribute::WISDOM},
	{Skill::INSIGHT, Attribute::WISDOM},
	{Skill::MEDICINE, Attribute::WISDOM},
	{Skill::PERCEPTION, Attribute::WISDOM},
	{Skill::DECEPTION, Attribute::CHARISMA},
	{Skill::INTIMIDATION, Attribute::CHARISMA},
	{Skill::PERFORMANCE, Attribute::CHARISMA},
	{Skill::PERSUASION, Attribute::CHARISMA},
};