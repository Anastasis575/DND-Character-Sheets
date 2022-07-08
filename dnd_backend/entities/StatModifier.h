#pragma once
#include "AttributeSet.h"
#include <string>

namespace DND {
	/// <summary>
	/// An immutable (String, AttributeSet) tuple describing any stats modifier such as the character's job,
	///  his background or his class / subclass.
	/// </summary>
	class StatModifier {
	public:
		StatModifier();

		StatModifier(std::string& name, AttributeSet& stats);

		std::string getName() const;

		AttributeSet getStats() const;

	private:
		std::string name;
		AttributeSet stats;
	};
}
