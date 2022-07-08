#pragma once
#include "AttributeSet.h"
#include "Spell.h"
#include "StatModifier.h"
#include "Item.h"
#include "Currency.h"

#include <string>
#include <list>
#include <unordered_map>

namespace DND {
	class PlayerBuilder;

	/**
	 * @brief An entity class managing all the information about a character's static information. It doesn't necessarily 
	 * reflect the state of the character during the game but rather the information that will be saved.
	 * 
	 * @author Dimitris Tsirmpas
	*/
	class PlayerData {

	public:

		/**
		 * @brief Return the score for the specified attribute.
		 * @param attr The attribute whose score will be returned
		 * @return The score of the attribute.
		*/
		int getAttributeScore(Attribute attr) const;

		/**
		 * @brief Get the amount of a specific currency currently held by the character.
		 * @param type the currency's type (e.g gold)
		 * @return the amount of this currency in the character's possesion
		*/
		int getCurrencyAmount(Currency type) const;

		int getSpeed() const;

		int getHP() const;

		int getAC() const;

		std::list<Spell> getSpells() const;

		std::string getRace() const;

		std::string getName() const;

		std::string getClass() const;

		std::string getSubclass() const;

		std::string getHdType() const;

		std::string getBackground() const;

		/**
		 * @brief Add a new item to the character's inventory.
		 * @param item the new item
		*/
		void addToInventory(Item& item);

		/**
		 * @brief Set the amount of currency this character posseses.
		 * @param type the type of the currency
		 * @param amt the new amount of the currency in the character's possesion
		*/
		void setCurrencyAmount(Currency type, int amt);

		/**
		 * @brief Add a new spell to the character's inventory.
		 * @param spell the new spell
		*/
		void addSpell(Spell spell);

		void setHP(int amt);

		void setSpeed(int speed);

		void setAC(int ac);

		void setLevel(int level);


	private:
		/// <summary>
		/// Creates a PlayerData instance by reading the character's name.
		/// </summary>
		/// <param name="charName">The name of the character.</param>
		
		/**
		 * @brief Creates a PlayerData instance by reading the character's name. To be used by a builder object.
		 * @see CharacterBuilder
		*/
		PlayerData(const std::string& charName, const StatModifier& race, const StatModifier& dndClass,
			const StatModifier& dndSubClass, const std::string& hdType, const std::string& background, const AttributeSet& baseStats,
			const AttributeSet& backgroundStats, const AttributeSet& proficiencyStats);

		friend class PlayerBuilder;

		int level = 1;
		int hp = 0;
		int ac = 0;
		int speed = 0;

		const StatModifier race;
		const StatModifier dndClass;
		const StatModifier dndSubClass;

		const std::string name;
		const std::string hdType;
		const std::string background;

		const AttributeSet baseStats;
		const AttributeSet backgroundStats;
		const AttributeSet proficiencyStats;

		std::unordered_map<Currency, int> currencyMap;
		std::list<Item> itemList;
		std::list<Spell> spellList;
	};

	/**
	 * @brief A builder that constructs PlayerData objects.
	 * @author Dimitris Tsirmpas
	*/
	class PlayerBuilder {

	public:
		PlayerBuilder(std::string name);

		PlayerData build() const;

		PlayerBuilder& setLevel(int level);

		PlayerBuilder& setHp(int hp);

		PlayerBuilder& setAc(int ac);

		PlayerBuilder& setSpeed(int speed);

		PlayerBuilder& setGold(int gold);

		PlayerBuilder& setElectrum(int electrum);

		PlayerBuilder& setSilver(int silver);

		PlayerBuilder& setCopper(int copper);

		PlayerBuilder& setRace(StatModifier race);

		PlayerBuilder& setClass(StatModifier _class);

		PlayerBuilder& setSubClass(StatModifier subClass);

		PlayerBuilder& setHdType(std::string hdType);

		PlayerBuilder& setBaseStats(AttributeSet baseStats);

		PlayerBuilder& setBackgroundStats(AttributeSet backgroundStats);

		PlayerBuilder& setProficiencyStats(AttributeSet proficiencyStats);


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
