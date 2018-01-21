#ifndef SAMPLETESTCLASS_TEST_H
#define SAMPLETESTCLASS_TEST_H

#include "sampletestclass.h"
#include "gtest/gtest.h"
#include <QList>

class SampleTestClassTest : /*public ::testing::Test,*/ public::testing::TestWithParam<int>
{
protected:
    SampleTestClass *obj;

protected:
    virtual void SetUp() {
        obj = new SampleTestClass();
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete obj;
    }
};

TEST_F(SampleTestClassTest, addTwoValues)
{
    const int x = 4;
    const int y = 5;
    EXPECT_EQ(9, obj->additionTwoValues(x, y));
    EXPECT_EQ(5, obj->additionTwoValues(2, 3));
}

// Tests factorial()
// Tests some trivial cases
TEST_F(SampleTestClassTest, FactorialTrivial) {
    QList<int> vals = QList<int>() << 1 << 2 << 3 << 4;
    QList<int> rslt = QList<int>() << 1 << 2 << 6 << 24;
    for(int i = 0; i < vals.size(); i++)
        EXPECT_EQ(obj->factorial(vals[i]), rslt[i]);
}

// Tests isPrime()
// Tests negative input.
TEST_F(SampleTestClassTest, PrimeNumbersNegative) {
    // This test belongs to the SampleTestClassTest test case.

    EXPECT_FALSE(obj->isPrime(-1));
    EXPECT_FALSE(obj->isPrime(-2));
    EXPECT_FALSE(obj->isPrime(INT_MIN));
}

// Tests some trivial cases.
TEST_F(SampleTestClassTest, PrimeNumbersTrivial) {
    EXPECT_FALSE(obj->isPrime(0));
    EXPECT_FALSE(obj->isPrime(1));
    EXPECT_TRUE(obj->isPrime(2));
    EXPECT_TRUE(obj->isPrime(3));
}

// Tests positive input.
TEST_F(SampleTestClassTest, PrimeNumbersPositive) {
    EXPECT_FALSE(obj->isPrime(4));
    EXPECT_TRUE(obj->isPrime(5));
    EXPECT_FALSE(obj->isPrime(6));
    EXPECT_TRUE(obj->isPrime(23));
}

// Tests with multiple values
TEST_P(SampleTestClassTest, PrimeNumbersMultiPositiveValues) {
    int n = GetParam();
    EXPECT_TRUE(obj->isPrime(n));
}
//Instantiates all TEST_P cases in the class with the same values
INSTANTIATE_TEST_CASE_P(PrimeNumbersMultiValues, SampleTestClassTest, testing::Values(3, 5, 11, 23, 17));

#endif //SAMPLETESTCLASS_TEST_H
