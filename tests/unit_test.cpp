#include <gtest/gtest.h>
#include <cstdint>
#include "../isRightTuple.h"

TEST(VectorTest, VectorHasWrongData) {
    std::string line = "300";
    EXPECT_FALSE(isRightTuple(line));
}

TEST(VectorTest, VectorHasRightData) {
    std::string line = "100";
    EXPECT_TRUE(isRightTuple(line));
}

// Главная функция, которая запускает все тесты Google Test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}