#include <gtest/gtest.h>
#include "../ip_out.h"

TEST(VectorTest, VectorIsNotEmpty) {
    std::vector<std::tuple<int, int, int, int>> list_of_tuples = {{1,1,1,1}, {2, 2, 2, 2}, {3,3,3,3}};
    EXPECT_EQ(ip_out(list_of_tuples), 0);
}

TEST(VectorTest, VectorIsEmpty) {
    std::vector<std::tuple<int, int, int, int>> list_of_tuples = {};
    EXPECT_EQ(ip_out(list_of_tuples), 1);
}

// Главная функция, которая запускает все тесты Google Test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}