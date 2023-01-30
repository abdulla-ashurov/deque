#ifndef __ARRAY_DEQUE__
#define __ARRAY_DEQUE__

#include "aligned-storage.hpp"

template <class T>
class ArrayDeque
{
private:
    const static size_t M_MAX_SIZE = 4;
    AlignedStorage<T, M_MAX_SIZE> m_array;
    size_t m_size = 0;

public:
    ArrayDeque() = default;
    explicit ArrayDeque(std::initializer_list<T> list);
    ArrayDeque(const ArrayDeque &other);

    ArrayDeque &operator=(const ArrayDeque &other);
    T &operator[](const size_t index);
    const T &operator[](const size_t index) const;

    template <typename V>
    void push_front(const V &value);

    template <typename V>
    void push_back(const V &value);

    void pop_front();
    void pop_back();

    void clear();

    static max_size() const;
    size_t size() const;

    bool empty() const;
    bool full() const;

    ~ArrayDeque();
};

#endif
