#include "pch.h"
#include "LocalFileResolver.h"
#include <cstdio>

using namespace DND::serialization_details;

typedef LocalFileResolver Resolver;

class ResolverTest : public ::testing::Test {
protected:
	Resolver* resolver = setUpImpl();

	virtual void setUp() {
		resolver = setUpImpl();
	}

	virtual void tearDown() {
		bool deleted = cleanUpTempDir();
		if (!deleted) {
			throw "Bad cleanup";
		}
	
		delete resolver;
	}

	virtual ~ResolverTest() {
		cleanUpTempDir();
	}

private:
	Resolver* setUpImpl() {
		setUpTempDir();
		return new Resolver(ROOT);
	}

};

TEST_F(ResolverTest, TestCreation) {
	resolver->createCharacterFile("CexMan", "CexPlayer");

	Path expectedPath = ROOT / "CexPlayer" / "CexMan.chr";
	EXPECT_TRUE(std::filesystem::exists(expectedPath));
}


TEST_F(ResolverTest, TestFetchPath) {
	resolver->createCharacterFile("CexMan", "CexPlayer");

	Path expectedPath = ROOT / "CexPlayer" / "CexMan.chr";
	EXPECT_EQ(expectedPath, resolver->getCharacterFile("CexMan", "CexPlayer"));
}


TEST_F(ResolverTest, TestDoubleCreation) {
	resolver->createCharacterFile("CexMan", "CexPlayer");
	EXPECT_ANY_THROW(resolver->createCharacterFile("CexMan", "CexPlayer"));
}