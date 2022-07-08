#pragma once
#include "Character.h"

namespace DND {

	/**
	 * @brief A builder that constructs PlayerData objects.
	 * @author Dimitris Tsirmpas
	*/
	class CharacterBuilder {

	public:
		CharacterBuilder(std::string name);

		Character build() const;

		CharacterBuilder& setLevel(int level);

		CharacterBuilder& setHp(int hp);

		CharacterBuilder& setAc(int ac);

		CharacterBuilder& setSpeed(int speed);

		CharacterBuilder& setGold(int gold);

		CharacterBuilder& setElectrum(int electrum);

		CharacterBuilder& setSilver(int silver);

		CharacterBuilder& setCopper(int copper);

		CharacterBuilder& setRace(StatModifier race);

		CharacterBuilder& setClass(StatModifier _class);

		CharacterBuilder& setSubClass(StatModifier subClass);

		CharacterBuilder& setHdType(std::string hdType);

		CharacterBuilder& setBaseStats(AttributeSet baseStats);

		CharacterBuilder& setBackgroundStats(AttributeSet backgroundStats);

		CharacterBuilder& setProficiencyStats(AttributeSet proficiencyStats);


	private:
		int level = 1;
		int hp = 0;
		int ac = 0;
		int speed = 0;

		int gold = 0;
		int	electrum = 0;
		int	silver = 0;
		int	copper = 0;

		StatModifier race;
		StatModifier dndClass;
		StatModifier dndSubClass;

		std::string name;
		std::string hdType;
		std::string background;

		AttributeSet baseStats;
		AttributeSet backgroundStats;
		AttributeSet proficiencyStats;
	};

}
