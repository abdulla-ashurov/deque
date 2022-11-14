#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "array.hpp"

template <class T>
class Deque
{
    class Node
    {
    public:
        Array<T> arr;
        Node *p_prev, *p_next;

        Node(const T &value, Node *p_prev, Node *p_next)
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

    T &search_from_head(const size_t index)
    {
        Node *current = head;
        for (size_t i = 0; i < size; i += current->arr.get_size(), current = current->p_next)
            for (size_t j = 0; j < current->arr.get_size(); j++)
                if (i + j == index)
                    return current->arr[j];

        throw std::invalid_argument("index not found");
    }

    T &search_from_tail(const size_t index)
    {
        Node *current = tail;
        for (int i = size - 1; i >= 0; i -= current->arr.get_size(), current = current->p_prev)
            for (int j = 0; j < current->arr.get_size(); j++)
                if (i - j == index)
                    return current->arr[current->arr.get_size() - 1 - j];

        throw std::invalid_argument("index not found");
    }

    bool is_faster_get_from_head(const size_t index)
    {
        return (index / Array<T>::get_max_size()) < (size / Array<T>::get_max_size());
    }

public:
    Deque() : head(nullptr), tail(nullptr), size(0) {}

    size_t get_size() const { return size; }

    bool empty() const { return size == 0; }

    void push_back(const T &value)
    {
        if (empty())
            head = tail = new Node(value, nullptr, nullptr);
        else if (!tail->arr.full())
            tail->arr.push_back(value);
        else
            tail = tail->p_next = new Node(value, tail, nullptr);

        size++;
    }

    void pop_back()
    {
        if (empty())
            throw std::runtime_error("deque is empty");
        else if (tail->arr.get_size() > 1)
            tail->arr.pop_back();
        else
        {
            tail = tail->p_prev;
            delete tail->p_next;
            tail->p_next = nullptr;
        }

        size--;
    }

    T &operator[](const size_t index)
    {
        if (is_faster_get_from_head(index))
            return search_from_head(index);

        return search_from_tail(index);
    }

    T &at(const size_t index)
    {
        if (index >= size)
            throw std::out_of_range("index out of range");

        return operator[](index);
    }

    ~Deque() {}
};

#endif
