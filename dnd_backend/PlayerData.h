#pragma once
#include "AttributeSet.h"
#include "Spell.h"
#include "StatModifier.h"

#include <string>
#include <list>

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

	int getCoins() const;

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
	/// <param name="itemName">The name of the item.</param>
	/// <param name="statChanges">The changes to the player's stats, default is all 0.</param>
	void addToInventory(std::string itemName, AttributeSet statChanges = AttributeSet::createEmpty());

	void changeCoins(int amt);

	void addSpell(Spell spell);

	void changeHP(int amt);

	/// <summary>
	/// Write the contents of the characters with an XML file with the character's name as filename.
	/// </summary>
	void toFile() const;

	/// <summary>
	/// Flushes the contents of the characters with an XML file with the character's name as filename.
	/// Unlike the toFile() function this method never throws and as such can exit without writing the data back to the file.
	/// Always use toFile() before destroying the object.
	/// </summary>
	~PlayerData();

private:
	int level;
	int hp;
	int ac;
	int speed;
	
	int coins;

	const StatModifier race;
	const StatModifier dndClass;
	const StatModifier dndSubClass;

	const std::string name;
	const std::string hdType;
	const std::string background;

	const AttributeSet baseStats;
	const AttributeSet backgroundStats;
	const AttributeSet proficiencyStats;

	std::list<AttributeSet> toolStatsList;
	std::list<std::string> inventory;
	std::list<Spell> spellList;
};