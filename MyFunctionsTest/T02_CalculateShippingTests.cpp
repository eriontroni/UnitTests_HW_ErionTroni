#include "pch.h"
#include "gtest/gtest.h"
#include "../MyFunctions/T02_CalculateShipping.h"

TEST(CalculateShippingTests, ZeroWeight_ReturnsZero)
{
    EXPECT_DOUBLE_EQ(CalculateShipping(0.0, false, 1), 0.0);
}

TEST(CalculateShippingTests, SmallWeight_UsesBaseSmall)
{
    double result = CalculateShipping(0.5, false, 1);
    EXPECT_GT(result, 0.0);   // thjesht me u siguru qe s’eshte zero
}

TEST(CalculateShippingTests, MediumWeight_UsesBaseMedium)
{
    double result = CalculateShipping(2.0, false, 1);
    EXPECT_GT(result, 0.0);
}

TEST(CalculateShippingTests, HeavyWeight_CostIncreases)
{
    double a = CalculateShipping(3.0, false, 1);
    double b = CalculateShipping(10.0, false, 1);
    EXPECT_GT(b, a); // më e rëndë → më shtrenjtë
}

TEST(CalculateShippingTests, Express_IsMoreExpensive)
{
    double normal = CalculateShipping(3.0, false, 1);
    double express = CalculateShipping(3.0, true, 1);
    EXPECT_GT(express, normal);
}
