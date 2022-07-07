#pragma once
#include "AttributeSet.h"
#include "Spell.h"
#include "StatModifier.h"
#include "Item.h"
#include "Currency.h"

#include <string>
#include <list>
#include <unordered_map>

class PlayerBuilder;

/// <summary>
/// An entity class holding all the information about a character's runtime information.
/// </summary>
class PlayerData {

public:
	
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
	/// Add an item to the character's inventory.
	/// </summary>
	/// <param name="item">The item</param>
	void addToInventory(Item& item);

	void setCurrencyAmount(Currency type, int amt);

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