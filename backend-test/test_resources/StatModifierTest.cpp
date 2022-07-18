#include "pch.h"
#include "StatModifier.h"

using namespace DND;

class StatModifierTest : public ::testing::Test {
protected:

	const std::string name = "TEST_NAME";
	const AttributeSet set = AttributeSet(6);
	StatModifier original = StatModifier(name, set);

	virtual void setUp() {
		original = StatModifier(name, set);
	}
	
	void expectEqualStats(const AttributeSet& rhs, const AttributeSet& lhs) {
		EXPECT_TRUE(rhs == lhs);
	}

	void expectDifferentStats(const AttributeSet& rhs, const AttributeSet& lhs) {
		EXPECT_FALSE(rhs == lhs);
	}
};

TEST_F(StatModifierTest, NameTest) {
	 EXPECT_EQ(original.getName(), "TEST_NAME");
}

TEST_F(StatModifierTest, SetTest) {
	expectEqualStats(original.getStats(), AttributeSet(6));
}

TEST_F(StatModifierTest, TestImmutability) {
	std::string name  = "TEST_NAME";
	AttributeSet set = AttributeSet(6);

	StatModifier s = StatModifier(name, set);

	name = "CHANGED NAME";
	set = AttributeSet(1);

	EXPECT_EQ(s.getName(), "TEST_NAME");
	expectEqualStats(original.getStats(), AttributeSet(6));
}