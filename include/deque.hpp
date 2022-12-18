#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "array.hpp"

template <class T>
class Deque
{
public:
    Deque() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

    size_t size() const { return m_size; }

    bool empty() const { return m_size == 0; }

    void push_front(const T &value)
    {
        if (empty())
            m_head = m_tail = new Node(value, nullptr, nullptr);
        else if (!m_head->arr.full())
            m_head->arr.push_front(value);
        else
            m_head = m_head->p_prev = new Node(value, nullptr, m_head);

        m_size++;
    }

    void push_back(const T &value)
    {
        if (empty())
            m_head = m_tail = new Node(value, nullptr, nullptr);
        else if (!m_tail->arr.full())
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

    void insert(const size_t pos, const T &value)
    {
        if (pos == 0)
            push_front(value);
        else if (pos == m_size)
            push_back(value);
        else
        {
            Node *current = reach_node(pos);
            if (current == nullptr)
                throw std::runtime_error("invalid position for inserting value");
            else if (!current->arr.full())
                current->arr.insert(pos % Array<T>::get_max_size(), value);
            else
            {
                Node *p_prev = current->p_prev;
                Node *node = new Node(p_prev, current);
                current->p_prev = p_prev->p_next = node;

                for (size_t i = 0; i <= pos % Array<T>::get_max_size(); i++)
                    node->arr.push_back(current->arr[i]);
                
                for (size_t i = 0; i <= pos % Array<T>::get_max_size(); i++)
                    current->arr.pop_front();
                
                node->arr.insert(pos % Array<T>::get_max_size(), value);
            }

            m_size++;
        }
    }

    void erase(const size_t pos)
    {
        if (pos == 0)
            pop_front();
        else if (pos == m_size - 1)
            pop_back();
        else
        {
            Node *current = reach_node(pos);
            if (current == nullptr)
                throw std::runtime_error("invalid position for erasing value");
            else if(current->arr.size() > 1)
                current->arr.erase(pos % Array<T>::get_max_size());
            else
            {
                Node *p_prev = current->p_prev, *p_next = current->p_next;
                p_prev->p_next = p_next;
                p_next->p_prev = p_prev;

                delete current;
            }

            m_size--;
        }
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

    ~Deque() {}

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
        return (index / Array<T>::get_max_size()) < (m_size / Array<T>::get_max_size());
    }

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

        Node(Node *p_prev, Node *p_next) : p_prev{p_prev}, p_next{p_next} {}

        ~Node() {}
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

    Node *m_head, *m_tail;
    size_t m_size;
};

#endif
