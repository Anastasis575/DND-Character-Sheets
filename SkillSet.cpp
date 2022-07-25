#include "SkillSet.h"
#include <assert.h>

using namespace DND;

DND::Attribute SkillSet::getSkillDependency(Skill skill) {
	auto result = SKILL_DEPENDENCY_MAP.find(skill);
	assert(result != SKILL_DEPENDENCY_MAP.end());
	return result->second;
}

const Skills SkillSet::getAllSkills() {
	return SKILLS;
}

SkillSet::SkillSet() : skillMap(SKILLS){}

void SkillSet::addSkill(Skill skill) {
	skillMap.setAmount(skill, YES);
}

void SkillSet::removeSkill(Skill skill) {
	skillMap.setAmount(skill, NO);
}

bool SkillSet::isSkilledAt(Skill skill) const {
	return skillMap.getAmount(skill) == YES;
}

const std::unordered_map<Skill, Attribute> SkillSet::SKILL_DEPENDENCY_MAP = {
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

const Skills SkillSet::SKILLS = {
		Skill::ATHLETICS,
		Skill::ACROBATICS,
		Skill::SLEIGHT_OF_HAND,
		Skill::STEALTH,
		Skill::ARCANA,
		Skill::HISTORY,
		Skill::INVESTIGATION,
		Skill::NATURE,
		Skill::RELIGION,
		Skill::ANIMAL_HANDLING,
		Skill::INSIGHT,
		Skill::MEDICINE,
		Skill::PERCEPTION,
		Skill::SURVIVAL,
		Skill::DECEPTION,
		Skill::INTIMIDATION,
		Skill::PERFORMANCE,
		Skill::PERSUASION,
};


