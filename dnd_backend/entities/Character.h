#pragma once
#include "AttributeSet.h"
#include "Spell.h"
#include "StatModifier.h"
#include "Item.h"
#include "Currency.h"
#include "ProficiencySet.h"
#include "ObjectCounter.h"

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <stdexcept>

namespace DND {
	typedef std::unordered_set<Item, ItemHasher> Items;
	typedef std::unordered_set<Spell, SpellHasher> Spells;
	typedef std::unordered_set<Attribute> Attributes;

	//typedef std::unordered_set<Item, ItemHasher>::end ItemIteratorEnd;

	/**
	 * @brief An entity class managing all the information about a character's static information. It doesn't necessarily 
	 * reflect the state of the character during the game but rather the information that will be saved.
	 * 
	 * @author Dimitris Tsirmpas
	*/
	class Character {

	public:

		/**
		 * @brief Creates a PlayerData instance by reading the character's name. To be used by a builder object.
		 * @see CharacterBuilder
		*/
		Character(const std::string& charName, const std::string& playerName);

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
		int getAmount(Currency type) const;

		int getSpeed() const;

		int getHP() const;

		int getAC() const;

		int getLevel() const;

		std::string getCharacterName() const;

		std::string getPlayerName() const;

		StatModifier getRace() const;

		StatModifier getClass() const;

		StatModifier getSubclass() const;

		std::string getHdType() const;

		std::string getBackground() const;

		/**
		 * @brief Add a new item to the character's inventory.
		 * @param item the new item
		*/
		void addItem(Item& item);

		/**
		 * @brief Remove an item from the character's inventory.
		 * @param item the item to be removed
		*/
		void removeItem(Item& item);

		/**
		 * @brief Get all the items this character posseses.
		 * @return a list of all the items
		*/
		Items getItems() const;

		/**
		 * @brief Set the amount of currency this character posseses.
		 * @param type the type of the currency
		 * @param amt the new amount of the currency in the character's possesion
		*/
		void setAmount(Currency type, int amt);

		/**
		 * @brief Add a new spell to the character's inventory.
		 * @param spell the new spell
		*/
		void addSpell(Spell& original);

		/**
		 * @brief Remove a spell from the character's inventory.
		 * @param spell the spell to be removed
		*/
		void removeSpell(Spell& original);

		/**
		 * @brief Get all the spells in the character's inventory.
		 * @return the spells
		*/
		Spells getSpells() const;

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

		void setRace(const StatModifier& race);

		void setClass(const StatModifier& dndClass);

		void setBackground(const std::string background);

		void setSubClass(const StatModifier& dndSubClass);

		/**
		 * @brief Set whether or not the character is proficient to an Attribute.
		 * @param attr the attribute
		 * @param isProficient true if the character is proficient, false otherwise
		*/
		void setProfiency(Attribute attr, bool isProficient);

		/**
		 * @brief Get all the Attributes to which the character is proficient with.
		 * @return a set with all the Attributes the character is proficient with
		*/
		Attributes getProfiencies() const;

	private:
		//limits
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
		int speed = 1;

		const std::string characterName;
		const std::string playerName;

		StatModifier race;
		StatModifier dndClass;
		StatModifier dndSubClass;

		std::string hdType;
		std::string background;

		AttributeSet baseStats;
		ProficiencySet proficiencies;

		entity_details::ObjectCounter<Currency> wallet;
		std::unordered_set<Item, ItemHasher> items;
		std::unordered_set<Spell, SpellHasher> spells;
	};

}
