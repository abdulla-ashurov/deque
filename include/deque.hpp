#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "array.hpp"

class Deque
{
    class Node
    {
    public:
        Array arr;
        Node *p_prev, *p_next;

        Node(const int &value, Node *p_prev, Node *p_next)
            : p_prev{p_prev}, p_next{p_next}
        {
            arr.push_back(value);
        }

        ~Node()
        {
            p_prev = p_next = nullptr;
        }
    };

    Node *head, *tail;
    size_t size;

    int &search_from_head(const size_t index)
    {
        Node *current = head;
        for (size_t i = 0; i < size; i += current->arr.get_size(), current = current->p_next)
            for (size_t j = 0; j < current->arr.get_size(); j++)
                if (i + j == index)
                    return current->arr[j];

        throw std::invalid_argument("index not found");
    }

    int &search_from_tail(const size_t index)
    {
        Node *current = tail;
        for (int i = size - 1; i >= 0; i -= current->arr.get_size(), current = current->p_prev)
            for (int j = 0; j < current->arr.get_size(); j++)
                if (i - j == index)
                    return current->arr[current->arr.get_size() - 1 - j];

        throw std::invalid_argument("index not found");
    }

public:
    Deque() : head(nullptr), tail(nullptr), size(0) {}

    size_t get_size() const { return size; }

    bool empty() const { return size == 0; }

    void push_back(const int &value)
    {
        if (head == nullptr)
            head = tail = new Node(value, nullptr, nullptr);
        else if (!tail->arr.full())
            tail->arr.push_back(value);
        else
            tail = tail->p_next = new Node(value, tail, nullptr);

        size++;
    }

    int &operator[](const size_t index)
    {
        if (index / Array::get_max_size() < size / Array::get_max_size())
            return search_from_head(index);

        return search_from_tail(index);
    }

    int &at(const size_t index)
    {
        if (index >= size)
            throw std::out_of_range("index out of range");

        return operator[](index);
    }

    ~Deque() {}
};

#endif
