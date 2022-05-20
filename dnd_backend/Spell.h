#pragma once
#include <string>

/// <summary>
/// A record type holding information about a spell.
/// </summary>
class Spell {
private:
	std::string name;
	std::string description;
	const int level;

public:
	Spell(const std::string& name,const std::string& description, int level);

	std::string getName() const;
	std::string getDescription() const;
	int getLevel() const;
};