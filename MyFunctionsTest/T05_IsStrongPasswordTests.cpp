#include "pch.h"
#include "gtest/gtest.h"
#include "../MyFunctions/T05_IsStrongPassword.h"

TEST(IsStrongPasswordTests, TooShort_ReturnsFalse)
{
    EXPECT_FALSE(IsStrongPassword("Ab1", 8));
}

TEST(IsStrongPasswordTests, MissingUppercase_ReturnsFalse)
{
    EXPECT_FALSE(IsStrongPassword("password1!", 8));
}

TEST(IsStrongPasswordTests, MissingDigit_ReturnsFalse)
{
    EXPECT_FALSE(IsStrongPassword("Password!", 8));
}

TEST(IsStrongPasswordTests, EvenN_RequiresUpperAndDigit)
{
    int N = 8;
    if (N % 2 == 0)
    {
        EXPECT_TRUE(IsStrongPassword("Abcdef1", N));
        EXPECT_FALSE(IsStrongPassword("Abcdef!", N));
    }
}

TEST(IsStrongPasswordTests, OddN_RequiresUpperDigitSpecial)
{
    int N = 9;
    if (N % 2 == 1)
    {
        EXPECT_TRUE(IsStrongPassword("Abcdef1!", N));
        EXPECT_FALSE(IsStrongPassword("Abcdef1", N));
    }
}
