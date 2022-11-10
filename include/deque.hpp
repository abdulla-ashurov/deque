#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "vector.hpp"

template <class T>
class Deque
{
    class Node
    {
        const size_t max_size = 4;

    public:
        Vector<T> v(max_size);
        Node *p_prev, *p_next;

        Node(const T &value, const Node *p_prev, const Node *p_next)
        {
            v.push_back(value);
            this->p_prev = p_prev;
            this->p_next = p_next;
        }

        ~Node()
        {
            v.~Vector();
            p_prev = p_next = nullptr;
        }
    };

    Node *head, *tail;
    size_t size;

public:
    Deque() : head(nullptr), tail(nullptr), size(0) {}

    size_t size() const { return size; }
    bool empty() const { return size == 0; }

    void push_back(const T &value)
    {
        if (head == nullptr)
            head = tail = new Node(value, nullptr, nullptr);
        else if (!tail->array.full())
            tail = tail->p_next = new Node(value, tail, nullptr);
        else
            tail->array.push_back(value);

        size++;
    }

    ~Deque()
    {
        // clear();
    }
};

#endif
