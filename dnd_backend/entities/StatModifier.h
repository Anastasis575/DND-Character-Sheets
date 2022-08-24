#pragma once
#include "AttributeSet.h"
#include <string>
/*
* Straight up include this because implementing the save/load procedures
* without the access would need to implement setters to all classes and break
* encapsulation
*/
#include <boost/serialization/access.hpp>

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

		template<class Archive>
		void serialize(Archive& ar, const unsigned int file_version) {
			ar& name;
			ar& stats;
		}
		friend class boost::serialization::access;
	};
}
