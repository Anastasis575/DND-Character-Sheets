#pragma once
#include "AttributeSet.h"
#include <string>

namespace DND {

	/**
	 * @brief  An immutable (String, AttributeSet) tuple describing any stats modifier such as the character's job,
	 * his background or his class / subclass.
	 * @author Dimitris Tsirmpas
	*/
	class StatModifier {
	public:
		StatModifier();

		StatModifier(const std::string& name, const AttributeSet& stats);

		std::string getName() const;

		AttributeSet getStats() const;

	private:
		std::string name; // non-const to allow copy constructor to exist
		AttributeSet stats;
	};
}
