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

    ~Deque()
    {
        // clear();
    }
};

#endif
