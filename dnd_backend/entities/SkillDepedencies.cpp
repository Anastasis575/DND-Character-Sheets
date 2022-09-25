#include "SkillDepedencies.h"

using namespace DND;

Attribute DND::getSkillDependency(Skill skill) {
	return entity_details::SKILL_DEPENDENCY_MAP.find(skill)->second;
}

const std::unordered_map<Skill, Attribute> entity_details::SKILL_DEPENDENCY_MAP = {
	{Skill::ATHLETICS, Attribute::Strength},
	{Skill::ACROBATICS, Attribute::Dexterity},
	{Skill::SLEIGHT_OF_HAND, Attribute::Dexterity},
	{Skill::STEALTH, Attribute::Dexterity},
	{Skill::ARCANA, Attribute::Intelligence},
	{Skill::HISTORY, Attribute::Intelligence},
	{Skill::INVESTIGATION, Attribute::Intelligence},
	{Skill::NATURE, Attribute::Intelligence},
	{Skill::RELIGION, Attribute::Intelligence},
	{Skill::ANIMAL_HANDLING, Attribute::Wisdom},
	{Skill::INSIGHT, Attribute::Wisdom},
	{Skill::MEDICINE, Attribute::Wisdom},
	{Skill::PERCEPTION, Attribute::Wisdom},
	{Skill::DECEPTION, Attribute::Charisma},
	{Skill::INTIMIDATION, Attribute::Charisma},
	{Skill::PERFORMANCE, Attribute::Charisma},
	{Skill::PERSUASION, Attribute::Charisma},
};