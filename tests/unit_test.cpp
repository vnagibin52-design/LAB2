#include <gtest/gtest.h>
#include "../ip_out.h"

TEST(VectorTest, VectorIsNotEmpty) {
    EXPECT_EQ(ip_out({{1,1,1,1}, {2, 2, 2, 2}, {3,3,3,3}}), 0);
}

TEST(VectorTest, VectorIsEmpty) {
    EXPECT_EQ(ip_out({}), 1);
}

// Главная функция, которая запускает все тесты Google Test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}