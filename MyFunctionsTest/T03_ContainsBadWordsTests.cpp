#include "gtest/gtest.h"
#include "../MyFunctions/T03_ContainsBadWords.h"

TEST(ContainsBadWordsTests, NoBadWords_ReturnsFalse)
{
    EXPECT_FALSE(ContainsBadWords("Hello my friend", 3));
}

TEST(ContainsBadWordsTests, ContainsIdiot_ReturnsTrue)
{
    EXPECT_TRUE(ContainsBadWords("You are an IDIOT!", 3));
}

TEST(ContainsBadWordsTests, ContainsStupid_ReturnsTrue)
{
    EXPECT_TRUE(ContainsBadWords("That was stupid", 3));
}

TEST(ContainsBadWordsTests, ContainsBad3Word_ReturnsTrue)
{
    // bad3 = hate/noob/trash (varësisht nga N)
    EXPECT_TRUE(ContainsBadWords("He is a noob!", 3));
}
