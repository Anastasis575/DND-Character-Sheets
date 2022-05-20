#pragma once
#include "AttributeSet.h"
#include <string>

/// <summary>
/// An immutable name, stats tuple describing any stats modifier such as a job, the background
/// or the class / subclass.
/// </summary>
class StatModifier {
private:
	std::string name;
	AttributeSet stats;

public:
	StatModifier(std::string& name, AttributeSet& stats);

	std::string getName() const;

	AttributeSet getStats() const;
};