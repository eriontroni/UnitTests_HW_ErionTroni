#include "pch.h"
#include "gtest/gtest.h"
#include "../MyFunctions/T01_IsValidEmail.h"

TEST(IsValidEmailTests, ValidEmail_ReturnsTrue)
{
    EXPECT_TRUE(IsValidEmail("user@example.com"));
}

TEST(IsValidEmailTests, MissingAt_ReturnsFalse)
{
    EXPECT_FALSE(IsValidEmail("userexample.com"));
}

TEST(IsValidEmailTests, NoLocalPart_ReturnsFalse)
{
    EXPECT_FALSE(IsValidEmail("@example.com"));
}

TEST(IsValidEmailTests, NoDotAfterAt_ReturnsFalse)
{
    EXPECT_FALSE(IsValidEmail("user@examplecom"));
}

TEST(IsValidEmailTests, TooShortDomain_ReturnsFalse)
{
    EXPECT_FALSE(IsValidEmail("u@domain.c"));
}
