#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "array.hpp"

template <class T>
class Deque
{
private:
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

        ~Node(){}
    };

    Node *head, *tail;
    size_t _size;

    T &search_from_head(const size_t index) const
    {
        Node *current = head;
        for (size_t i = 0; i < _size; i += current->arr.size(), current = current->p_next)
            for (size_t j = 0; j < current->arr.size(); j++)
                if (i + j == index)
                    return current->arr[j];

        throw std::invalid_argument("index not found");
    }

    T &search_from_tail(const size_t index) const
    {
        Node *current = tail;
        for (int i = _size - 1; i >= 0; i -= current->arr.size(), current = current->p_prev)
            for (int j = 0; j < current->arr.size(); j++)
                if (i - j == index)
                    return current->arr[current->arr.size() - 1 - j];

        throw std::invalid_argument("index not found");
    }

    bool is_faster_get_from_head(const size_t index) const
    {
        return (index / Array<T>::get_max_size()) < (_size / Array<T>::get_max_size());
    }

public:
    Deque() : head(nullptr), tail(nullptr), _size(0) {}

    size_t get_size() const { return _size; }

    bool empty() const { return _size == 0; }

    void push_front(const T &value)
    {
        if (empty())
            head = tail = new Node(value, nullptr, nullptr);
        else if (!head->arr.full())
            head->arr.push_front(value);
        else
            head = head->p_prev = new Node(value, nullptr, head);

        _size++;
    }

    void push_back(const T &value)
    {
        if (empty())
            head = tail = new Node(value, nullptr, nullptr);
        else if (!tail->arr.full())
            tail->arr.push_back(value);
        else
            tail = tail->p_next = new Node(value, tail, nullptr);

        _size++;
    }

    void pop_front()
    {
        if (empty())
            throw std::runtime_error("deque is empty");
        else if (head->arr.size() > 1)
            head->arr.pop_front();
        else
        {
            Node *temp = head->p_next;
            delete head;

            head = temp;
            head->p_prev = nullptr;
        }

        _size--;
    }

    void pop_back()
    {
        if (empty())
            throw std::runtime_error("deque is empty");
        else if (tail->arr.size() > 1)
            tail->arr.pop_back();
        else
        {
            Node *temp = tail->p_prev;
            delete tail;

            tail = temp;
            tail->p_next = nullptr;
        }

        _size--;
    }

    T &operator[](const size_t index)
    {
        if (is_faster_get_from_head(index))
            return search_from_head(index);

        return search_from_tail(index);
    }

    const T &operator[](size_t index) const
    {
        if (is_faster_get_from_head(index))
            return search_from_head(index);

        return search_from_tail(index);
    }

    T &at(const size_t index)
    {
        if (index >= _size)
            throw std::out_of_range("index out of range");

        return operator[](index);
    }

    const T &at(size_t index) const
    {
        if (index >= _size)
            throw std::out_of_range("index out of range");

        return operator[](index);
    }

    ~Deque() {}
};

#endif
