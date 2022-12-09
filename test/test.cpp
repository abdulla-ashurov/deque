#include <string>
#include "catch_amalgamated.hpp"
#include "../include/deque.hpp"

std::string gen_random_str(int len)
{
    std::string s;
    static const char characters[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; i++)
    {
        s += characters[rand() % (sizeof(characters) - 1)];
    }

    return s;
}

void init_str_array(std::string *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
        array[i] = gen_random_str(10);
}

////////////////////////////////////////////////////////////////////////////
/////////////////// TEST CASES FOR TESTING ARRAY_HPP ///////////////////////
////////////////////////////////////////////////////////////////////////////

TEST_CASE("test array.push_front function")
{
    SECTION("should return expected values")
    {
        Array<int> array;
        size_t expected_size = array.get_max_size();

        for (size_t i = 0; i < expected_size; i++)
            array.push_front(i + 1);

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == expected_size - i);
    }

    SECTION("should return expected values")
    {
        Array<std::string> array;
        size_t expected_size = array.get_max_size();

        std::string expected_values[expected_size];
        init_str_array(expected_values, expected_size);

        for (size_t i = 0; i < expected_size; i++)
            array.push_front(expected_values[i]);

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == expected_values[expected_size - i - 1]);
    }
}

TEST_CASE("test array.push_back function")
{
    SECTION("should return expected values")
    {
        Array<int> array;
        size_t expected_size = array.get_max_size();

        for (size_t i = 0; i < expected_size; i++)
            array.push_back(i + 1);

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == i + 1);
    }

    SECTION("should return expected values")
    {
        Array<std::string> array;
        size_t expected_size = array.get_max_size();

        std::string expected_values[expected_size];
        init_str_array(expected_values, expected_size);

        for (size_t i = 0; i < expected_size; i++)
            array.push_back(expected_values[i]);

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == expected_values[i]);
    }
}

TEST_CASE("test array.pop_front function")
{
    SECTION("should return expected values")
    {
        Array<int> array;
        for (size_t i = 0; i < array.get_max_size(); i++)
            array.push_front(i + 1);

        REQUIRE(array.size() == array.get_max_size());

        for (size_t i = 0; i < 2; i++)
            array.pop_front();

        size_t expected_size = 2;

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == expected_size - i);
    }

    SECTION("should return expected values")
    {
        Array<std::string> array;

        std::string expected_values[array.get_max_size()];
        init_str_array(expected_values, array.get_max_size());

        for (size_t i = 0; i < array.get_max_size(); i++)
            array.push_front(expected_values[i]);

        REQUIRE(array.size() == array.get_max_size());

        for (size_t i = 0; i < 2; i++)
            array.pop_front();

        size_t expected_size = 2;
        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == expected_values[expected_size - i - 1]);
    }
}

TEST_CASE("test array.pop_back function")
{
    SECTION("should return expected values")
    {
        Array<int> array;
        for (size_t i = 0; i < array.get_max_size(); i++)
            array.push_back(i + 1);

        REQUIRE(array.size() == array.get_max_size());

        for (size_t i = 0; i < 2; i++)
            array.pop_back();

        size_t expected_size = 2;

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == i + 1);
    }

    SECTION("should return expected values")
    {
        Array<std::string> array;

        std::string expected_values[array.get_max_size()];
        init_str_array(expected_values, array.get_max_size());

        for (size_t i = 0; i < array.get_max_size(); i++)
            array.push_back(expected_values[i]);

        REQUIRE(array.size() == array.get_max_size());

        for (size_t i = 0; i < 2; i++)
            array.pop_back();

        size_t expected_size = 2;
        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == expected_values[i]);
    }
}

TEST_CASE("test array.clear function")
{
    SECTION("should return empty array")
    {
        Array<int> array;
        for (size_t i = 0; i < array.get_max_size(); i++)
            array.push_back(i + 1);

        size_t expected_size = 0;
        array.clear();

        REQUIRE(array.size() == expected_size);
    }

    SECTION("should return empty array")
    {
        Array<std::string> array;
        for (size_t i = 0; i < array.get_max_size(); i++)
            array.push_back(gen_random_str(10));

        size_t expected_size = 0;
        array.clear();

        REQUIRE(array.size() == expected_size);
    }
}

////////////////////////////////////////////////////////////////////////////
/////////////////// TEST CASES FOR TESTING DEQUE_HPP ///////////////////////
////////////////////////////////////////////////////////////////////////////

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

        for (size_t i = 0; i < 3; i++)
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
