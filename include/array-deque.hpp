#ifndef __ARRAY_DEQUE__
#define __ARRAY_DEQUE__

#include "aligned-storage.hpp"

#define m_assert(exp, msg) assert(((void)msg, !((bool)exp)))

template <class T>
class ArrayDeque
{
private:
    const static size_t M_MAX_SIZE = 4;
    AlignedStorage<T, M_MAX_SIZE> m_array;
    bool allow_push_from_front = false;
    T *begin = nullptr;
    T *end = nullptr;

public:
    ArrayDeque() = default;

    explicit ArrayDeque(std::initializer_list<T> list)
    {
        for (auto element : list)
            push_back(element);
    }

    ArrayDeque(const ArrayDeque &other)
    {
        for (size_t i = 0; i < other.size(); i++)
            push_back(other[i]);
    }

    ArrayDeque &operator=(const ArrayDeque &other)
    {
        if (this != &other)
            for (size_t i = 0; i < other.size(); i++)
                push_back(other[i]);

        return *this;
    }

    T &operator[](const size_t index)
    {
        return *(begin + index);
    }

    const T &operator[](const size_t index) const
    {
        return *(begin + index);
    }

    template <typename V>
    void push_front(const V &value)
    {
        m_assert(full(), "Array is full");
        if (empty()) {
            allow_push_from_front = true;
            begin = end = m_array.end();
        }

        m_assert(!allow_push_from_front, "Please create a new object of ArrayDeque for pushing elements to front");
        new (--begin) T(value);
    }

    template <typename V>
    void push_back(const V &value)
    {
        m_assert(full(), "Array is full");
        if (empty())
            end = begin = m_array.begin();

        m_assert(allow_push_from_front, "Please create a new object of ArrayDeque for pushing elements to back");
        new (end++) T(value);
    }

    void pop_front()
    {
        m_assert(empty(), "Array is empty");

        begin->~T();
        begin++;
    }

    void pop_back()
    {
        m_assert(empty(), "Array is empty");

        end--;
        end->~T();
    }

    void clear()
    {
        while (size() != 0)
            pop_front();
    }

    static size_t max_size()
    {
        return M_MAX_SIZE;
    }

    size_t size() const
    {
        return end - begin;
    }

    bool empty() const
    {
        return end - begin == 0;
    }

    bool full() const
    {
        return end - begin == M_MAX_SIZE;
    }

    ~ArrayDeque()
    {
        clear();
    }
};

#endif
