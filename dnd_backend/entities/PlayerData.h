#pragma once
#include "AttributeSet.h"
#include "Spell.h"
#include "StatModifier.h"
#include "Item.h"
#include "Currency.h"

#include <string>
#include <list>
#include <unordered_map>

/// <summary>
/// An entity class holding all the information about a character's runtime information.
/// </summary>
class PlayerData {

public:

	/// <summary>
	/// Creates a PlayerData instance by reading the character's name.
	/// </summary>
	/// <param name="charName">The name of the character.</param>
	PlayerData(std::string charName);
	
	/// <summary>
	/// Return the score for the specified attribute.
	/// </summary>
	/// <param name="attr">The attribute whose score will be returned.</param>
	/// <returns>The score of the attribute.</returns>
	int getAttributeScore(Attribute attr) const;

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

	/// <summary>
	/// Increases the level of the character by 1.
	/// </summary>
	void incrementLevel();

	/// <summary>
	/// Add an item to the character's inventory.
	/// </summary>
	/// <param name="item">The item</param>
	void addToInventory(Item& item);

	void changeCoins(Currency type, int amt);

	void addSpell(Spell spell);

	void changeHP(int amt);


private:
	int level;
	int hp;
	int ac;
	int speed;
	
	int gold;
	int	electrum;
	int	silver;
	int	copper;

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