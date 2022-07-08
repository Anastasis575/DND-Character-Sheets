#pragma once
#include "AttributeSet.h"
#include "Spell.h"
#include "StatModifier.h"
#include "Item.h"
#include "Currency.h"

#include <string>
#include <list>
#include <unordered_map>
#include <limits>
#include <stdexcept>

namespace DND {

	/**
	 * @brief An entity class managing all the information about a character's static information. It doesn't necessarily 
	 * reflect the state of the character during the game but rather the information that will be saved.
	 * 
	 * @author Dimitris Tsirmpas
	*/
	class Character {

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

		/**
		 * @brief Sets the hp to the specified amount.
		 * @param amt the amount
		 * @throws std::invalid_argument if amt is out of bounds
		*/
		void setHP(int amt);

		/**
		 * @brief Sets the speed to the specified amount.
		 * @param amt the amount
		 * @throws std::invalid_argument if the new speed is out of bounds
		*/
		void setSpeed(int speed);

		/**
		 * @brief Sets the Armor Class to the specified amount.
		 * @param amt the amount
		 * @throws std::invalid_argument if the new ac is out of bounds
		*/
		void setAC(int ac);

		/**
		 * @brief Sets the level to the specified amount.
		 * @param amt the amount
		 * @throws std::invalid_argument if the new level is out of bounds
		*/
		void setLevel(int level);


	private:
	
		/**
		 * @brief Creates a PlayerData instance by reading the character's name. To be used by a builder object.
		 * @see CharacterBuilder
		*/
		Character(const std::string& charName, const StatModifier& race, const StatModifier& dndClass,
			const StatModifier& dndSubClass, const std::string& hdType, const std::string& background, const AttributeSet& baseStats,
			const AttributeSet& backgroundStats, const AttributeSet& proficiencyStats);

		friend class CharacterBuilder; //realistically there is no reason for another builder to exist

		static const int MIN_LEVEL = 1;
		static const int MAX_LEVEL = 20;
		static const int MIN_HP = 0;
		static const int MAX_HP = std::numeric_limits<int>::max();
		static const int MIN_AC = -5;
		static const int MAX_AC = 32;
		static const int MIN_SPEED = 1;
		static const int MAX_SPEED = std::numeric_limits<int>::max();


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

}
