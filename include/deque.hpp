#ifndef __DEQUE_HPP__
#define __DEQUE_HPP__

#include "array-deque.hpp"

template <class T>
class Deque
{
public:
    Deque() = default;

    Deque(const Deque &other) : Deque()
    {
        for (size_t i = 0; i < other.size(); i++)
            push_back(other[i]);
    }

    Deque &operator=(const Deque &other)
    {
        if (this != &other)
            for (size_t i = 0; i < other.size(); i++)
                push_back(other[i]);
        
        return *this;
    }

    void push_front(const T &value)
    {
        if (empty())
            m_head = m_tail = new Node(value, nullptr, nullptr);
        else if (!m_head->arr.full() && m_head->arr.allow_push_front())
            m_head->arr.push_front(value);
        else
            m_head = m_head->p_prev = new Node(value, nullptr, m_head);

        m_size++;
    }

    void push_back(const T &value)
    {
        if (empty())
            m_head = m_tail = new Node(value, nullptr, nullptr);
        else if (!m_tail->arr.full() && m_tail->arr.allow_push_back())
            m_tail->arr.push_back(value);
        else
            m_tail = m_tail->p_next = new Node(value, m_tail, nullptr);

        m_size++;
    }

    void pop_front()
    {
        if (empty())
            throw std::runtime_error("deque is empty");
        else if (m_head->arr.size() > 1)
            m_head->arr.pop_front();
        else
        {
            Node *temp = m_head->p_next;
            delete m_head;

            m_head = temp;
            if (m_head != nullptr)
                m_head->p_prev = nullptr;
        }

        m_size--;
    }

    void pop_back()
    {
        if (empty())
            throw std::runtime_error("deque is empty");
        else if (m_tail->arr.size() > 1)
            m_tail->arr.pop_back();
        else
        {
            Node *temp = m_tail->p_prev;
            delete m_tail;

            m_tail = temp;
            if (m_tail != nullptr)
                m_tail->p_next = nullptr;
        }

        m_size--;
    }

    void clear()
    {
        while(!empty())
            pop_back();
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
        if (index >= m_size)
            throw std::out_of_range("index out of range");

        return operator[](index);
    }

    const T &at(size_t index) const
    {
        if (index >= m_size)
            throw std::out_of_range("index out of range");

        return operator[](index);
    }

    size_t size() const 
    { 
        return m_size; 
    }

    bool empty() const 
    { 
        return m_size == 0; 
    }

    ~Deque() 
    { 
        clear(); 
    }

private:
    T &search_from_head(const size_t index) const
    {
        Node *current = m_head;
        for (size_t i = 0; i < m_size; i += current->arr.size(), current = current->p_next)
            if (index >= i && index < i + current->arr.size())
                return current->arr[index - i];

        throw std::invalid_argument("index not found");
    }

    T &search_from_tail(const size_t index) const
    {
        Node *current = m_tail;
        for (int i = m_size - 1; i >= 0; i -= current->arr.size(), current = current->p_prev)
            if (index <= i && index > i - current->arr.size())
                return current->arr[index - (i - current->arr.size()) - 1];

        throw std::invalid_argument("index not found");
    }

    bool is_faster_get_from_head(const size_t index) const
    {
        return (index / ArrayDeque<T>::max_size()) < (m_size / ArrayDeque<T>::max_size());
    }

    class Node
    {
    public:
        ArrayDeque<T> arr;
        Node *p_prev;
        Node *p_next;

        Node(const T &value, Node *p_prev, Node *p_next)
            : p_prev{p_prev}, p_next{p_next}
        {
            arr.push_back(value);
        }
    };

    Node *reach_node(const size_t index)
    {
        if (is_faster_get_from_head(index))
            return reach_from_head(index);

        return reach_from_tail(index);
    }

    Node *reach_from_head(const size_t index)
    {
        Node *current = m_head;
        for (size_t i = 0; i < m_size; i += current->arr.size(), current = current->p_next)
            if (index >= i && index < i + current->arr.size())
                return current;

        return nullptr;
    }

    Node *reach_from_tail(const size_t index)
    {
        Node *current = m_tail;
        for (int i = m_size - 1; i >= 0; i -= current->arr.size(), current = current->p_prev)
            if (index <= i && index > i - current->arr.size())
                return current;

        return nullptr;
    }

    Node *m_head = nullptr;
    Node *m_tail = nullptr;
    size_t m_size = 0;
};

#endif
