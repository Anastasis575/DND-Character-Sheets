#include "pch.h"
#include "Race.h"

using namespace DND;

class RaceTest : public ::testing::Test {
protected:

	const std::string name = "TEST_NAME";
	const AttributeSet set = AttributeSet(6);
	Race original = Race(name, set);

	virtual void setUp() {
		original = Race(name, set);
	}
	
	void expectEqualStats(const AttributeSet& rhs, const AttributeSet& lhs) {
		EXPECT_TRUE(rhs == lhs);
	}

	void expectDifferentStats(const AttributeSet& rhs, const AttributeSet& lhs) {
		EXPECT_FALSE(rhs == lhs);
	}
};

TEST_F(RaceTest, NameTest) {
	 EXPECT_EQ(original.getName(), "TEST_NAME");
}

TEST_F(RaceTest, SetTest) {
	expectEqualStats(original.getStats(), AttributeSet(6));
}

TEST_F(RaceTest, TestImmutability) {
	std::string name  = "TEST_NAME";
	AttributeSet set = AttributeSet(6);

	Race s = Race(name, set);

	name = "CHANGED NAME";
	set = AttributeSet(1);

	EXPECT_EQ(s.getName(), "TEST_NAME");
	expectEqualStats(original.getStats(), AttributeSet(6));
}

TEST_F(RaceTest, TestSerialization) {
	testSerialization<Race>(original,
		[](const Race& a, const Race& b) {
			return a.getName() == b.getName() && a.getStats() == b.getStats();
		});
}