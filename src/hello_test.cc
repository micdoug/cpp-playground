#include <gtest/gtest.h>

TEST(HelloTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(6*7, 42);
}

TEST(HelloTest, OtherAssertions) {
    EXPECT_LT(3, 3);
}