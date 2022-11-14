#include "catch_amalgamated.hpp"
#include "../include/deque.hpp"

TEST_CASE("test deque.push_back function")
{
    SECTION("should return expected value")
    {
        Deque deque;
        size_t expected_size = 10;

        for (size_t i = 0; i < expected_size; i++)
            deque.push_back(i + 1);

        REQUIRE(deque.get_size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == i + 1);
    }
}

TEST_CASE("test deque.pop_back function")
{
    SECTION("should return expected value")
    {
        Deque deque;
        size_t size = 10;

        for (size_t i = 0; i < size; i++)
            deque.push_back(i + 1);

        for (size_t i = 0;  i < 3; i++)
            deque.pop_back();

        size_t expected_size = 7;
        
        REQUIRE(deque.get_size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == i + 1);
    }
}
