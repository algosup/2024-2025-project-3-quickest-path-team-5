#include <cassert>
#include <cstdlib>
#include <cstring>
#include <array>
#include <iostream>

#include "gtest/gtest.h"


TEST(ExampleTest, Example) {
    ASSERT_EQ(1, 1);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}