/*File generated automatically by auto_enum.py https://github.com/dimits-exe/CppAutomationTools */ 
#include "Alignment.h"
#include <string>
#include <utility>
#include <algorithm>

namespace DND {
	
	std::string alignmentToString(DND::Alignment alignment) {
		return entity_details::ALIGNMENT_MAP.find(alignment)->second;
	}
	
	std::vector<Alignment> alignmentValues() {
		std::vector<DND::Alignment> v;
		for each (auto it in entity_details::ALIGNMENT_MAP) {
			v.push_back(it.first);
		}
		return v;
	}
	
	namespace entity_details {
		const std::unordered_map<Alignment, std::string> ALIGNMENT_MAP = 
		 {
			std::make_pair(Alignment::LAWFUL_GOOD, "Lawful Good"),
			std::make_pair(Alignment::NEUTRAL_GOOD, "Neutral Good"),
			std::make_pair(Alignment::CHAOTIC_GOOD, "Chaotic Good"),
			std::make_pair(Alignment::LAWFUL_NEUTRAL, "Lawful Neutral"),
			std::make_pair(Alignment::TRUE_NEUTRAL, "True Neutral"),
			std::make_pair(Alignment::CHAOTIC_NEUTRAL, "Chaotic Neutral"),
			std::make_pair(Alignment::LAWFUL_EVIL, "Lawful Evil"),
			std::make_pair(Alignment::NEUTRAL_EVIL, "Neutral Evil"),
			std::make_pair(Alignment::CHAOTIC_EVIL, "Chaotic Evil"),
		};
	}
}
