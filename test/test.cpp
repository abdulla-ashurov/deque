#include "catch_amalgamated.hpp"
#include "../include/deque.hpp"

TEST_CASE("test deque.push_back function")
{
    SECTION("should return expected value")
    {
        Deque deque;
        size_t expected_size = rand() % 10;

        for (size_t i = 0; i < expected_size; i++)
            deque.push_back(i + 1);

        REQUIRE(deque.get_size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == i + 1);
    }
}
