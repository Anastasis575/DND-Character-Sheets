#pragma once
#include "Attribute.h"
#include <array>

/// <summary>
/// A class representing the basic attributes of each character such as Strength, Charisma, Dexterity etc.
/// </summary>
class AttributeSet {

public:
	
	/// <summary>
	/// Create an AttributeSet with 0 stats.
	/// </summary>
	/// <returns></returns>
	static AttributeSet createEmpty();

	/// <summary>
	/// Creates an AttributeSet inititalizing all the attributes with a default score of 0.
	/// </summary>
	AttributeSet(int strengthValue, int dexterityValue, 
		int constitutionValue, int inteligenceValue, int wisdomValue, int charismaValue);

	/// <summary>
	/// Creates an AttributeSet inititalizing all the attributes with the specified amount.
	/// </summary>
	AttributeSet(int amt);

	AttributeSet& operator+=(AttributeSet const&);

	/// <summary>
	/// Adds the scores for each attribute with that of another AttributeSet.
	/// </summary>
	/// <param name="other">The set whose attribute scores will be added.</param>
	/// <returns></returns>
	AttributeSet operator+(AttributeSet const&);

	/// <summary>
	/// Adds the scores for each attribute with a constant number each.
	/// </summary>
	/// <param name="amt">The amount that will be added to each attribute's score.</param>
	/// <returns></returns>
	AttributeSet operator+(int);

	/// <summary>
	/// Return the score for the specified attribute.
	/// </summary>
	/// <param name="attr">The attribute whose score will be returned.</param>
	/// <returns>The score of the attribute.</returns>
	int getAttributeScore(Attribute attr) const;

	/// <summary>
	/// Increase the score of the specified attribute by a constant amount.
	/// </summary>
	/// <param name="attr">The attribute whose score will be returned.</param>
	/// <param name="amt">The amount that will be added to the attribute's score.</param>
	void increaseAttribute(Attribute attr, int amt);

private:
	std::array<int, ATTRIBUTES_LENGTH> attributes;
};