#pragma once
#include "AttributeSet.h"
#include "ProficiencySet.h"
#include "ObjectCounter.h"
#include <unordered_map>
#include <unordered_set>

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
		// if you add any value here remember to also add it in the static class collections
	};

	typedef std::unordered_set<Skill> Skills;

	/**
	 * @brief A set holding the Skills of an individual Character
	 * @author Dimitris Tsirmpas
	*/
	class SkillSet {
	public:
		static Attribute SkillSet::getSkillDependency(Skill skill);
		static const Skills getAllSkills();

		/**
		 * @brief Add a new skill to this character.
		 * @param skill the new skill
		*/
		void addSkill(Skill skill);

		/**
		 * @brief Remove a skill from this character.
		 * @param skill the skill to be removed
		*/
		void removeSkill(Skill skill);

		/**
		 * @brief Return whether or not the character has a specific skill
		 * @param skill the skill 
		 * @return true if the character is skilled at the ... skill
		*/
		bool isSkilledAt(Skill skill) const;


	private:
		static const Skills SKILLS;
		static const std::unordered_map<Skill, Attribute> SKILL_DEPENDENCY_MAP;

		static const int YES = 1;
		static const int NO = 0;

		entity_details::ObjectCounter<Skill> skillMap;
	};
}
