#include <string>
#include <list>
#include <deque>
#include <random>
#include "catch_amalgamated.hpp"
#include "../include/deque.hpp"

std::string gen_random_str(const size_t len)
{
    std::string s;
    static const char characters[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; i++)
    {
        s += characters[random() % (sizeof(characters) - 1)];
    }

    return s;
}

void init_str_array(std::deque<std::string> &deq, const size_t size)
{
    for (size_t i = 0; i < size; i++)
        deq.push_back(gen_random_str(10));
}

////////////////////////////////////////////////////////////////////////////
///////////////// TEST CASES FOR TESTING ARRAY_DEQUE.HPP ///////////////////
////////////////////////////////////////////////////////////////////////////

TEST_CASE("test ArrayDeque.push_front function")
{
    SECTION("should return expected values")
    {
        ArrayDeque<int> array;
        const size_t expected_size = ArrayDeque<int>::max_size();

        for (size_t i = 0; i < expected_size; i++)
            array.push_front(i + 1);

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < array.size(); i++)
            REQUIRE(array[i] == expected_size - i);
    }

    SECTION("should return expected values")
    {
        ArrayDeque<std::string> array;
        const size_t expected_size = ArrayDeque<std::string>::max_size();

        std::deque<std::string> expected_values;
        init_str_array(expected_values, expected_size);

        for (size_t i = 0; i < expected_size; i++)
            array.push_front(expected_values[i]);

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == expected_values[expected_size - i - 1]);
    }
}

TEST_CASE("test ArrayDeque.push_back function")
{
    SECTION("should return expected values")
    {
        ArrayDeque<int> array;
        const size_t expected_size = ArrayDeque<int>::max_size();

        for (size_t i = 0; i < expected_size; i++)
            array.push_back(i + 1);

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == i + 1);
    }

    SECTION("should return expected values")
    {
        ArrayDeque<std::string> array;
        const size_t expected_size = ArrayDeque<std::string>::max_size();

        std::deque<std::string> expected_values;
        init_str_array(expected_values, expected_size);

        for (size_t i = 0; i < expected_size; i++)
            array.push_back(expected_values[i]);

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == expected_values[i]);
    }
}

TEST_CASE("test ArrayDeque.pop_front() function")
{
    SECTION("should return expected values")
    {
        ArrayDeque<int> array;

        for (size_t i = 0; i < ArrayDeque<int>::max_size(); i++)
            array.push_front(i + 1);

        REQUIRE(array.size() == ArrayDeque<int>::max_size());

        for (size_t i = 0; i < 2; i++)
            array.pop_front();

        const size_t expected_size = 2;

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == expected_size - i);
    }

    SECTION("should return expected values")
    {
        ArrayDeque<std::string> array;
        const size_t max_size = ArrayDeque<std::string>::max_size();

        std::deque<std::string> expected_values;
        init_str_array(expected_values, max_size);

        for (size_t i = 0; i < max_size; i++)
            array.push_front(expected_values[i]);

        REQUIRE(array.size() == max_size);

        for (size_t i = 0; i < 2; i++)
            array.pop_front();

        const size_t expected_size = 2;
        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == expected_values[expected_size - i - 1]);
    }

    SECTION("should return expected values")
    {
        ArrayDeque<int> array;
        const size_t max_size = ArrayDeque<int>::max_size();
        for (size_t i = 0; i < ArrayDeque<int>::max_size(); i++)
            array.push_front(i + 1);

        for (size_t i = 0; i < max_size; i++)
            array.pop_front();

        REQUIRE(array.empty());
    }

    SECTION("should return expected values")
    {
        ArrayDeque<std::string> array;
        for (size_t i = 0; i < ArrayDeque<std::string>::max_size(); i++)
            array.push_front(gen_random_str(10));

        for (size_t i = 0; i < ArrayDeque<std::string>::max_size(); i++)
            array.pop_front();

        REQUIRE(array.empty());
    }
}

TEST_CASE("test ArrayDeque.pop_back function")
{
    SECTION("should return expected values")
    {
        ArrayDeque<int> array;
        for (size_t i = 0; i < ArrayDeque<int>::max_size(); i++)
            array.push_back(i + 1);

        REQUIRE(array.size() == ArrayDeque<int>::max_size());

        for (size_t i = 0; i < 2; i++)
            array.pop_back();

        const size_t expected_size = 2;

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == i + 1);
    }

    SECTION("should return expected values")
    {
        ArrayDeque<std::string> array;
        const size_t max_size = ArrayDeque<std::string>::max_size();

        std::deque<std::string> expected_values;
        init_str_array(expected_values, max_size);

        for (size_t i = 0; i < max_size; i++)
            array.push_back(expected_values[i]);

        REQUIRE(array.size() == max_size);

        for (size_t i = 0; i < 2; i++)
            array.pop_back();

        const size_t expected_size = 2;
        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == expected_values[i]);
    }

    SECTION("should return expected values")
    {
        ArrayDeque<int> array;
        for (size_t i = 0; i < ArrayDeque<int>::max_size(); i++)
            array.push_back(i + 1);

        for (size_t i = 0; i < ArrayDeque<int>::max_size(); i++)
            array.pop_back();

        REQUIRE(array.empty());
    }

    SECTION("should return expected values")
    {
        ArrayDeque<std::string> array;
        for (size_t i = 0; i < ArrayDeque<std::string>::max_size(); i++)
            array.push_back(gen_random_str(10));

        for (size_t i = 0; i < ArrayDeque<std::string>::max_size(); i++)
            array.pop_back();

        REQUIRE(array.empty());
    }
}

TEST_CASE("test ArrayDeque.clear function")
{
    SECTION("should return empty array")
    {
        ArrayDeque<int> array;
        for (size_t i = 0; i < ArrayDeque<int>::max_size(); i++)
            array.push_back(i + 1);

        const size_t expected_size = 0;
        array.clear();

        REQUIRE(array.size() == expected_size);
    }

    SECTION("should return empty array")
    {
        ArrayDeque<std::string> array;
        for (size_t i = 0; i < ArrayDeque<std::string>::max_size(); i++)
            array.push_back(gen_random_str(10));

        size_t expected_size = 0;
        array.clear();

        REQUIRE(array.size() == expected_size);
    }
}

TEST_CASE("test ArrayDeque constructor which accepts std::initializer_list")
{
    SECTION("should return expected values")
    {
        ArrayDeque<int> array({1, 2, 3, 4});
        size_t expected_size = 4;

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < array.size(); i++)
            REQUIRE(array[i] == i + 1);
    }

    SECTION("should return expected values")
    {
        std::deque<std::string> expected_values;
        init_str_array(expected_values, ArrayDeque<std::string>::max_size());

        ArrayDeque<std::string> array({expected_values[0], expected_values[1], expected_values[2], expected_values[3]});
        size_t expected_size = 4;

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < array.size(); i++)
            REQUIRE(array[i] == expected_values[i]);
    }
}

TEST_CASE("test ArrayDeque copy constructor")
{
    SECTION("should return expected values")
    {
        ArrayDeque<int> array1({1, 2, 3, 4});
        ArrayDeque<int> array2(array1);

        REQUIRE(array1.size() == array2.size());
        for (size_t i = 0; i < array1.size(); i++)
            REQUIRE(array1[i] == array2[i]);
    }

    SECTION("should return expected values")
    {
        std::deque<std::string> values;
        init_str_array(values, ArrayDeque<std::string>::max_size());

        ArrayDeque<std::string> array1({values[0], values[1], values[2], values[3]});
        ArrayDeque<std::string> array2(array1);

        REQUIRE(array1.size() == array2.size());
        for (size_t i = 0; i < array1.size(); i++)
            REQUIRE(array1[i] == array2[i]);
    }
}

TEST_CASE("test ArrayDeque operator=")
{
    SECTION("should return expected values")
    {
        ArrayDeque<int> array1({1, 2, 3, 4});
        ArrayDeque<int> array2({5, 6});
        array2 = array1;

        REQUIRE(array1.size() == array2.size());
        for (size_t i = 0; i < array1.size(); i++)
            REQUIRE(array1[i] == array2[i]);
    }

    SECTION("should return expected values")
    {
        std::deque<std::string> values;
        init_str_array(values, ArrayDeque<std::string>::max_size());

        ArrayDeque<std::string> array1({values[0], values[1], values[2], values[3]});
        ArrayDeque<std::string> array2({gen_random_str(10), gen_random_str(10)});
        array2 = array1;

        REQUIRE(array1.size() == array2.size());
        for (size_t i = 0; i < array1.size(); i++)
            REQUIRE(array1[i] == array2[i]);
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

        REQUIRE(deque.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == expected_size - i);
    }

    SECTION("should return expected values")
    {
        Deque<std::string> deque;
        size_t expected_size = 10;

        std::deque<std::string> expected_values;
        init_str_array(expected_values, expected_size);

        for (size_t i = 0; i < expected_size; i++)
            deque.push_front(expected_values[i]);

        REQUIRE(deque.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == expected_values[expected_size - i - 1]);
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

        REQUIRE(deque.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == i + 1);
    }

    SECTION("should return expected values")
    {
        Deque<std::string> deque;
        size_t expected_size = 10;

        std::deque<std::string> expected_values;
        init_str_array(expected_values, expected_size);

        for (size_t i = 0; i < expected_size; i++)
            deque.push_back(expected_values[i]);

        REQUIRE(deque.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == expected_values[i]);
    }
}

TEST_CASE("test deque.push_back and push_front functions")
{
    SECTION("should return expected values")
    {
        Deque<int> deque;
        size_t expected_size = 10;
        std::deque<int> expected_values = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};

        for (size_t i = 0; i < expected_size / 2; i++)
            deque.push_back(i + 1);

        for (size_t i = 0; i < expected_size / 2; i++)
            deque.push_front(expected_size - i);

        REQUIRE(deque.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == expected_values[i]);
    }

    SECTION("should return expected values")
    {
        Deque<int> deque;
        size_t expected_size = 10;
        std::deque<int> expected_values = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6};

        for (size_t i = 0; i < expected_size / 2; i++)
            deque.push_front(i + 1);

        for (size_t i = 0; i < expected_size / 2; i++)
            deque.push_back(expected_size - i);

        REQUIRE(deque.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == expected_values[i]);
    }

    SECTION("should return expected values")
    {
        Deque<std::string> deque;
        size_t expected_size = 10;

        size_t str_length = 10;

        std::list<std::string> expected_values;

        for (size_t i = 0; i < expected_size / 2; i++)
        {
            std::string str(gen_random_str(str_length));
            deque.push_back(str);
            expected_values.push_back(str);
        }

        for (size_t i = 0; i < expected_size / 2; i++)
        {
            std::string str(gen_random_str(str_length));
            deque.push_front(str);
            expected_values.push_front(str);
        }

        REQUIRE(deque.size() == expected_size);
        auto it = expected_values.cbegin();
        for (size_t i = 0; i < expected_size || it != expected_values.cend(); i++, it++)
            REQUIRE(deque[i] == *it);
    }

    SECTION("should return expected values")
    {
        Deque<std::string> deque;
        size_t expected_size = 10;

        size_t str_length = 10;

        std::list<std::string> expected_values;

        for (size_t i = 0; i < expected_size / 2; i++)
        {
            std::string str(gen_random_str(str_length));
            deque.push_front(str);
            expected_values.push_front(str);
        }

        for (size_t i = 0; i < expected_size / 2; i++)
        {
            std::string str(gen_random_str(str_length));
            deque.push_back(str);
            expected_values.push_back(str);
        }

        REQUIRE(deque.size() == expected_size);
        auto it = expected_values.cbegin();
        for (size_t i = 0; i < expected_size || it != expected_values.cend(); i++, it++)
            REQUIRE(deque[i] == *it);
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

        size_t count_of_rm_elements = 3;
        for (size_t i = 0; i < count_of_rm_elements; i++)
            deque.pop_front();

        size_t expected_size = size - count_of_rm_elements;

        REQUIRE(deque.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == expected_size - i);
    }

    SECTION("should return expected values")
    {
        Deque<std::string> deque;
        size_t size = 10;

        std::deque<std::string> expected_values;
        init_str_array(expected_values, size);

        for (size_t i = 0; i < size; i++)
            deque.push_front(expected_values[i]);

        size_t count_of_rm_elements = 3;
        for (size_t i = 0; i < count_of_rm_elements; i++)
            deque.pop_front();

        size_t expected_size = size - count_of_rm_elements;

        REQUIRE(deque.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == expected_values[size - i - count_of_rm_elements - 1]);
    }

    SECTION("should return expected values")
    {
        Deque<int> deque;
        size_t size = 10;

        for (size_t i = 0; i < size; i++)
            deque.push_front(i + 1);

        for (size_t i = 0; i < size; i++)
            deque.pop_front();

        REQUIRE(deque.empty());
    }

    SECTION("should return expected values")
    {
        Deque<std::string> deque;
        size_t size = 10;

        for (size_t i = 0; i < size; i++)
            deque.push_front(gen_random_str(10));

        for (size_t i = 0; i < size; i++)
            deque.pop_front();

        REQUIRE(deque.empty());
    }

    SECTION("should return exception")
    {
        Deque<int> deque;
        REQUIRE_THROWS(deque.pop_front());
    }

    SECTION("should return exception")
    {
        Deque<std::string> deque;
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

        size_t count_of_rm_elements = 3;
        for (size_t i = 0; i < count_of_rm_elements; i++)
            deque.pop_back();

        size_t expected_size = size - count_of_rm_elements;

        REQUIRE(deque.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == i + 1);
    }

    SECTION("should return expected values")
    {
        Deque<std::string> deque;
        size_t size = 10;

        std::deque<std::string> expected_values;
        init_str_array(expected_values, size);

        for (size_t i = 0; i < size; i++)
            deque.push_back(expected_values[i]);

        size_t count_of_rm_elements = 3;
        for (size_t i = 0; i < count_of_rm_elements; i++)
            deque.pop_back();

        size_t expected_size = size - count_of_rm_elements;

        REQUIRE(deque.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(deque[i] == expected_values[i]);
    }

    SECTION("should return expected values")
    {
        Deque<int> deque;
        size_t size = 10;

        for (size_t i = 0; i < size; i++)
            deque.push_back(i + 1);

        for (size_t i = 0; i < size; i++)
            deque.pop_back();

        REQUIRE(deque.empty());
    }

    SECTION("should return expected values")
    {
        Deque<std::string> deque;
        size_t size = 10;

        for (size_t i = 0; i < size; i++)
            deque.push_back(gen_random_str(10));

        for (size_t i = 0; i < size; i++)
            deque.pop_back();

        REQUIRE(deque.empty());
    }

    SECTION("should return exception")
    {
        Deque<int> deque;
        REQUIRE_THROWS(deque.pop_back());
    }

    SECTION("should return exception")
    {
        Deque<std::string> deque;
        REQUIRE_THROWS(deque.pop_back());
    }
}

TEST_CASE("test deque copy constructor")
{
    SECTION("should be same")
    {
        Deque<int> first_deque;
        const size_t size = 10;

        for (size_t i = 0; i < size; i++)
            first_deque.push_back(i + 1);

        Deque<int> second_deque(first_deque);

        REQUIRE(first_deque.size() == second_deque.size());
        for (size_t i = 0; i < size; i++)
            REQUIRE(first_deque[i] == second_deque[i]);
    }

    SECTION("should be same")
    {
        Deque<std::string> first_deque;
        const size_t size = 10;

        for (size_t i = 0; i < size; i++)
            first_deque.push_back(gen_random_str(10));

        Deque<std::string> second_deque(first_deque);

        REQUIRE(first_deque.size() == second_deque.size());
        for (size_t i = 0; i < size; i++)
            REQUIRE(first_deque[i] == second_deque[i]);
    }
}

TEST_CASE("test deque operator=")
{
    SECTION("should be same")
    {
        Deque<int> first_deque;
        const size_t size = 10;

        for (size_t i = 0; i < size; i++)
            first_deque.push_back(i + 1);

        Deque<int> second_deque;
        for (size_t i = 0; i < 5; i++)
            second_deque.push_back(i + 1);

        second_deque = first_deque;

        REQUIRE(first_deque.size() == second_deque.size());
        for (size_t i = 0; i < size; i++)
            REQUIRE(first_deque[i] == second_deque[i]);
    }

    SECTION("should be same")
    {
        Deque<std::string> first_deque;
        const size_t size = 10;

        for (size_t i = 0; i < size; i++)
            first_deque.push_back(gen_random_str(10));

        Deque<std::string> second_deque;
        for (size_t i = 0; i < 5; i++)
            second_deque.push_back(gen_random_str(10));

        second_deque = first_deque;

        REQUIRE(first_deque.size() == second_deque.size());
        for (size_t i = 0; i < size; i++)
            REQUIRE(first_deque[i] == second_deque[i]);
    }
}
