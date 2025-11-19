#include "gtest/gtest.h"
#include "../MyFunctions/T04_PassedExam.h"

TEST(PassedExamTests, ThrowsOnNegativePoints)
{
        EXPECT_THROW(PassedExam(-1, 0), std::invalid_argument);
}

TEST(PassedExamTests, ThrowsAbove100)
{
    EXPECT_THROW(PassedExam(120, 0), std::invalid_argument);
}

TEST(PassedExamTests, ExactlyPassLimit_ReturnsFalse)
{
    int passLimit = 40 + (0 % 21);
    EXPECT_FALSE(PassedExam(passLimit, 0));
}

TEST(PassedExamTests, AbovePassLimit_ReturnsTrue)
{
    int passLimit = 40 + (0 % 21);
    EXPECT_TRUE(PassedExam(passLimit + 1, 0));
}

TEST(PassedExamTests, BelowPassLimit_ReturnsFalse)
{
    int passLimit = 40 + (0 % 21);
    EXPECT_FALSE(PassedExam(passLimit - 1, 0));
}
