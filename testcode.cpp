#include "colorcoder.h"
#include <gtest/gtest.h>

using namespace TelCoColorCoder;

// Test fixture class
class ColorCoderTest : public ::testing::Test {
protected:
    // Optional: Set up any shared resources or state here
    // that you want to use across multiple test cases
    void SetUp() override {
        // Called before each test case
    }

    void TearDown() override {
        // Called after each test case
    }
};

// Test case for converting pair number to color pair
TEST_F(ColorCoderTest, NumberToPairTest) {
    // Test cases for pair number to color pair conversion
    testNumberToPair(4, YELLOW, BROWN);
    testNumberToPair(5, VIOLET, SLATE);
}

// Test case for converting color pair to pair number
TEST_F(ColorCoderTest, PairToNumberTest) {
    // Test cases for color pair to pair number conversion
    testPairToNumber(RED, BLUE, 25);
    testPairToNumber(BLACK, ORANGE, 12);
}

// Main function to run tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
