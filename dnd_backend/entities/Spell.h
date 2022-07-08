#pragma once
#include <string>

namespace DND {
	
	/**
	 * @brief A record type holding information about a spell.
	 * @author Dimitris Tsirmpas
	*/
	class Spell {
	public:
		Spell(const std::string& name, const std::string& description, int level);

		std::string getName() const;
		std::string getDescription() const;
		int getLevel() const;

	private:
		std::string name;
		std::string description;
		const int level;
	};
}
