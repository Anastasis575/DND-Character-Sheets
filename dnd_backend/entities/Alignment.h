/*File generated automatically by auto_enum.py https://github.com/dimits-exe/CppAutomationTools */ 
#pragma once
#include <unordered_map>

namespace DND {
	enum class Alignment {
		LAWFUL_GOOD,
		NEUTRAL_GOOD,
		CHAOTIC_GOOD,
		LAWFUL_NEUTRAL,
		TRUE_NEUTRAL,
		CHAOTIC_NEUTRAL,
		LAWFUL_EVIL,
		NEUTRAL_EVIL,
		CHAOTIC_EVIL,
		UNALIGNED,
	};
	
	
	std::string alignmentToString(DND::Alignment alignment);
	
	
	std::vector<Alignment> alignmentValues();
	
	namespace entity_details {
		extern const std::unordered_map<Alignment, std::string> ALIGNMENT_MAP;
	}
}
