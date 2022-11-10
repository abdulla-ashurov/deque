#include "catch_amalgamated.hpp"
#include "../include/deque.hpp"

#include <iostream>

TEST_CASE("test deque.push_back function")
{
    SECTION("should return expected value")
    {
        Deque<int> deque;

        std::cout << "Size: " << deque.size() << std::endl;
        deque.push_back(5);
        deque.push_back(10);
        deque.push_back(15);
        deque.push_back(20);
        std::cout << "Size: " << deque.size() << std::endl;
    }
}

