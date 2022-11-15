#include "catch_amalgamated.hpp"
#include "../include/deque.hpp"

TEST_CASE("test deque.push_front function")
{
    SECTION("should return expected values")
    {
        Deque<int> deque;
        size_t expected_size = 10;

        for (size_t i = 0; i < expected_size; i++)
            deque.push_front(i + 1);

        REQUIRE(deque.get_size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == expected_size - i);
    }
}

TEST_CASE("test deque.push_back function")
{
    SECTION("should return expected values")
    {
        Deque<int> deque;
        size_t expected_size = 10;

        for (size_t i = 0; i < expected_size; i++)
            deque.push_back(i + 1);

        REQUIRE(deque.get_size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == i + 1);
    }
}

TEST_CASE("test deque.push_back and push_front functions")
{
    SECTION("should return expected values")
    {
        Deque<int> deque;
        size_t expected_size = 10;
        int expected_values[] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};

        for (size_t i = 0; i < expected_size / 2; i++)
            deque.push_back(i + 1);
        
        for (size_t i = 0; i < expected_size / 2; i++)
            deque.push_front(expected_size - i);
        
        REQUIRE(deque.get_size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == expected_values[i]);
    }

    SECTION("should return expected values")
    {
        Deque<int> deque;
        size_t expected_size = 10;
        int expected_values[] = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6};

        for (size_t i = 0; i < expected_size / 2; i++)
            deque.push_front(i + 1);
        
        for (size_t i = 0; i < expected_size / 2; i++)
            deque.push_back(expected_size - i);
        
        REQUIRE(deque.get_size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == expected_values[i]);
    }
}

TEST_CASE("test deque.pop_front function")
{
    SECTION("should return expected values")
    {
        Deque<int> deque;
        size_t size = 10;

        for (size_t i = 0; i < size; i++)
            deque.push_front(i + 1);

        for (size_t i = 0; i < 3; i++)
            deque.pop_front();

        size_t expected_size = 7;
        
        REQUIRE(deque.get_size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == expected_size - i);
    }

    SECTION("should return exception")
    {
        Deque<int> deque;
        REQUIRE_THROWS(deque.pop_front());
    }
}

TEST_CASE("test deque.pop_back function")
{
    SECTION("should return expected values")
    {
        Deque<int> deque;
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

    SECTION("should return exception")
    {
        Deque<int> deque;
        REQUIRE_THROWS(deque.pop_back());
    }
}
