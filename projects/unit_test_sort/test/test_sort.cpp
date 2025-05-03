#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "sort.hpp"

TEST(ArraysEqual, AnyElementsCount) 
{
    std::vector<int> actual {1,8,2,5,3,11};
    std::vector<int> expected {1,2,3,5,8,11};

    bubbleSort(actual);

    for (int i = 0; i < actual.size(); i++)
    {
        ASSERT_EQ(expected[i], actual[i])
            << "Ожидаемый и отсортированный массив отличаются на индексе: "
            << i
            << " значение ожидаемого и отсортированного соответсвенно: "
            << expected[i] << ' ' << actual[i];
    }
}

int main(int argc, char** argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}