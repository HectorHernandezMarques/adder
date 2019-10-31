#include <gtest/gtest.h>
#include <Adder.h>

class AdderTs : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {

    }
};

TEST_F(AdderTs, GIVEN_a_5_and_a_10_WHEN_add_THEN_15_is_returned) {
    ASSERT_EQ(add(5,10), 15);
}

TEST_F(AdderTs, GIVEN_a_5_and_a_minus_10_WHEN_add_THEN_minus_5_is_returned) {
    ASSERT_EQ(add(5,-10), -5);
}

TEST_F(AdderTs, GIVEN_a_5_and_a_minus_5_WHEN_add_THEN_0_is_returned) {
    ASSERT_EQ(add(5,-5), 0);
}