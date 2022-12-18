#include <string>
#include <list>
#include <deque>
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
        const size_t expected_size = array.get_max_size();

        for (size_t i = 0; i < expected_size; i++)
            array.push_front(i + 1);

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == expected_size - i);
    }

    SECTION("should return expected values")
    {
        Array<std::string> array;
        const size_t expected_size = array.get_max_size();

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
        const size_t expected_size = array.get_max_size();

        for (size_t i = 0; i < expected_size; i++)
            array.push_back(i + 1);

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == i + 1);
    }

    SECTION("should return expected values")
    {
        Array<std::string> array;
        const size_t expected_size = array.get_max_size();

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

        const size_t expected_size = 2;

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

        const size_t expected_size = 2;
        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == expected_values[expected_size - i - 1]);
    }

    SECTION("should return expected values")
    {
        Array<int> array;
        for (size_t i = 0; i < array.get_max_size(); i++)
            array.push_front(i + 1);

        for (size_t i = 0; i < array.get_max_size(); i++)
            array.pop_front();

        REQUIRE(array.empty());
    }

    SECTION("should return expected values")
    {
        Array<std::string> array;
        for (size_t i = 0; i < array.get_max_size(); i++)
            array.push_front(gen_random_str(10));

        for (size_t i = 0; i < array.get_max_size(); i++)
            array.pop_front();

        REQUIRE(array.empty());
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

        const size_t expected_size = 2;

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

        const size_t expected_size = 2;
        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < expected_size; i++)
            REQUIRE(array[i] == expected_values[i]);
    }

    SECTION("should return expected values")
    {
        Array<int> array;
        for (size_t i = 0; i < array.get_max_size(); i++)
            array.push_back(i + 1);

        for (size_t i = 0; i < array.get_max_size(); i++)
            array.pop_back();

        REQUIRE(array.empty());
    }
    
    SECTION("should return expected values")
    {
        Array<std::string> array;
        for (size_t i = 0; i < array.get_max_size(); i++)
            array.push_back(gen_random_str(10));

        for (size_t i = 0; i < array.get_max_size(); i++)
            array.pop_back();

        REQUIRE(array.empty());
    }
}

TEST_CASE("test array.clear function")
{
    SECTION("should return empty array")
    {
        Array<int> array;
        for (size_t i = 0; i < array.get_max_size(); i++)
            array.push_back(i + 1);

        const size_t expected_size = 0;
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

TEST_CASE("test array.insert function")
{
    SECTION("insert values to middle of array")
    {
        Array<int> array;
        const size_t expected_size = array.get_max_size();

        std::deque<int> expected_values;

        for (size_t i = 0; i < expected_size / 2; i++)
        {
            int value = rand() % 40;

            array.push_back(value);
            expected_values.push_back(value);
        }

        for (size_t i = 0; i < expected_size / 2; i++)
        {
            int value = rand() % 40;
            std::deque<int>::const_iterator pos = expected_values.begin() + expected_size / 2 - 1;

            array.insert(expected_size / 2 - 1, value);
            expected_values.insert(pos, value);
        }

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < array.size(); i++)
            REQUIRE(array[i] == expected_values[i]);
    }

    SECTION("insert values to middle of deque")
    {
        Array<std::string> array;
        const size_t expected_size = array.get_max_size();

        std::deque<std::string> expected_values;

        for (size_t i = 0; i < expected_size / 2; i++)
        {
            std::string value(gen_random_str(10));

            array.push_back(value);
            expected_values.push_back(value);
        }

        for (size_t i = 0; i < expected_size / 2; i++)
        {
            std::string value(gen_random_str(10));
            std::deque<std::string>::const_iterator pos = expected_values.begin() + expected_size / 2 - 1;

            array.insert(expected_size / 2 - 1, value);
            expected_values.insert(pos, value);
        }

        REQUIRE(array.size() == expected_size);
        for (size_t i = 0; i < array.size(); i++)
            REQUIRE(array[i] == expected_values[i]);
    }
}

TEST_CASE("test array.erase function")
{
    SECTION("erase all values from begin of array")
    {
        Array<int> array;
        const size_t size = array.get_max_size();

        for (size_t i = 0; i < size; i++)
            array.push_back(i + 1);
        
        for (size_t i = 0; i < array.size(); i++)
            array.erase(0);

        REQUIRE(array.empty());
    }

    SECTION("erase all values from end of array")
    {
        Array<int> array;
        const size_t size = array.get_max_size();

        for (size_t i = 0; i < size; i++)
            array.push_back(i + 1);
        
        for (size_t i = 0; i < array.size(); i++)
            array.erase(array.size() - 1);

        REQUIRE(array.empty());
    }

    SECTION("erase values from middle of array")
    {
        Array<int> array;
        const size_t size = array.get_max_size();

        std::deque<int> expected_values;

        for (size_t i = 0; i < size; i++)
        {
            array.push_back(i + 1);
            expected_values.push_back(i + 1);
        }

        for (size_t i = 0; i < array.size() / 2; i++)
        {
            array.erase(array.size() / 2 - 1);
            expected_values.erase(expected_values.begin() + expected_values.size() / 2 - 1);
        }

        REQUIRE(array.size() == expected_values.size());
        for (size_t i = 0; i < array.size(); i++)
            REQUIRE(array[i] == expected_values[i]);
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

        std::string expected_values[expected_size];
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

        std::string expected_values[expected_size];
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
        int expected_values[] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};

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
        int expected_values[] = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6};

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
        std::list<std::string>::const_iterator it = expected_values.cbegin();
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
        std::list<std::string>::const_iterator it = expected_values.cbegin();
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

        std::string expected_values[size];
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

        std::string expected_values[size];
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

TEST_CASE("test deque.insert function")
{
    SECTION("insert values to begin of deque")
    {
        Deque<int> deque;

        size_t expected_size = 10;
        std::deque<int> expected_values;

        for (size_t i = 0; i < expected_size; i++)
        {
            int value = rand() % 10;

            deque.insert(0, value);
            expected_values.insert(expected_values.begin(), value);
        }

        REQUIRE(deque.size() == expected_size);
        for (size_t i = 0; i < deque.size(); i++)
            REQUIRE(deque[i] == expected_values[i]);
    }

    SECTION("insert values to begin of deque")
    {
        Deque<std::string> deque;

        size_t expected_size = 10;
        std::string expected_values[expected_size];
        init_str_array(expected_values, expected_size);

        for (size_t i = 0; i < expected_size; i++)
            deque.insert(0, expected_values[i]);

        REQUIRE(deque.size() == expected_size);
        for (size_t i = 0; i < deque.size(); i++)
            REQUIRE(deque[i] == expected_values[expected_size - i - 1]);
    }

    SECTION("insert values to end of deque")
    {
        Deque<int> deque;

        size_t expected_size = 10;
        std::deque<int> expected_values;

        for (size_t pos = 0; pos < expected_size; pos++)
        {
            int value = rand() % 10;

            deque.insert(pos, value);
            expected_values.insert(expected_values.end(), value);
        }

        REQUIRE(deque.size() == expected_size);
        for (size_t i = 0; i < deque.size(); i++)
            REQUIRE(deque[i] == expected_values[i]);
    }

    SECTION("insert values to end of deque")
    {
        Deque<std::string> deque;

        size_t expected_size = 10;
        std::string expected_values[expected_size];
        init_str_array(expected_values, expected_size);

        for (size_t pos = 0; pos < expected_size; pos++)
            deque.insert(pos, expected_values[pos]);

        REQUIRE(deque.size() == expected_size);
        for (size_t i = 0; i < deque.size(); i++)
            REQUIRE(deque[i] == expected_values[i]);
    }

    SECTION("insert values to middle of deque")
    {
        Deque<int> deque;

        size_t expected_size = 10;
        std::deque<int> expected_values;

        for (size_t i = 0; i < expected_size / 2; i++)
        {
            int value = rand() % 40;

            deque.push_back(value);
            expected_values.push_back(value);
        }

        for (size_t i = 0; i < expected_size / 2; i++)
        {
            int value = rand() % 40;
            std::deque<int>::const_iterator pos = expected_values.begin() + expected_size / 2;

            deque.insert(expected_size / 2, value);
            expected_values.insert(pos, value);
        }

        REQUIRE(deque.size() == expected_size);
        for (size_t i = 0; i < deque.size(); i++)
            REQUIRE(deque[i] == expected_values[i]);
    }

    SECTION("insert values to middle of deque")
    {
        Deque<std::string> deque;

        size_t expected_size = 10;
        std::deque<std::string> expected_values;

        for (size_t i = 0; i < expected_size / 2; i++)
        {
            std::string value(gen_random_str(10));

            deque.push_back(value);
            expected_values.push_back(value);
        }

        for (size_t i = 0; i < expected_size / 2; i++)
        {
            std::string value(gen_random_str(10));
            std::deque<std::string>::const_iterator pos = expected_values.begin() + expected_size / 2;

            deque.insert(expected_size / 2, value);
            expected_values.insert(pos, value);
        }

        REQUIRE(deque.size() == expected_size);
        for (size_t i = 0; i < deque.size(); i++)
            REQUIRE(deque[i] == expected_values[i]);
    }

    SECTION("should return exception")
    {
        Deque<int> deque;
        size_t incorrect_pos = 3, value = 5;

        REQUIRE_THROWS(deque.insert(incorrect_pos, value));
    }

    SECTION("should return exception")
    {
        Deque<std::string> deque;
        size_t incorrect_pos = 3;

        REQUIRE_THROWS(deque.insert(incorrect_pos, gen_random_str(10)));
    }
}
