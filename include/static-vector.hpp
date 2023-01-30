#ifndef __STATIC_ARRAY__
#define __STATIC_ARRAY__

#include "aligned-storage.hpp"

#define assert_m(exp, msg) assert(((void)msg, !(bool(exp))))

template<class T>
class static_vector
{
private:
    const static size_t m_max_size = 4;
    AlignedStorage<T, m_max_size> m_array;
    size_t m_size = 0;

public:
    static_vector() = default;
    static_vector(const static_vector& other) = delete;

    inline size_t size() const { return m_size; }
    inline static size_t max_size() { return m_max_size; }
    inline bool empty() const { return m_size == 0; }
    inline bool full() const { return m_size == m_max_size; }

    void push_front(const T &value)
    {
        assert_m(full(), "static_vector overflow");

        for (int i = m_size - 1; i >= 0; i--)
            std::swap(*m_array.get(i), *m_array.get(i + 1));

        new(m_array.get(0)) T(value);
        m_size++;
    }

    void push_back(const T &value)
    {
        assert_m(full(), "static_vector overflow");

        new(m_array.get(m_size)) T(value);
        m_size++;
    }

    void pop_front()
    {
        assert_m(empty(), "static_vector is empty");

        for (size_t i = 0; i < m_size - 1; i++)
            std::swap(*m_array.get(i), *m_array.get(i + 1));
        
        m_array.get(m_size - 1)->~T();
        m_size--;
    }

    void pop_back()
    {
        assert_m(empty(), "static_vector is empty");
        
        m_array.get(m_size - 1)->~T();
        m_size--;
    }

    void insert(const size_t pos, const T &value)
    {
        assert_m(full(), "array overflow");
        assert_m(pos >= m_size, "index out of range");

        if (pos == 0)
            push_front(value);
        else if (pos == m_size)
            push_back(value);
        else {
            T val(value);
            for (size_t i = pos; i < m_size; i++)
                std::swap(*m_array.get(i), val);
            
            new(m_array.get(m_size)) T(val);
            m_size++;
        }
    }

    void erase(const size_t pos)
    {
        assert_m(empty(), "array is empty");
        assert_m(pos >= m_size, "index out of range");

        if (pos == 0)
            pop_front();
        else if (pos == m_size - 1)
            pop_back();
        else {
            for (size_t i = pos; i < m_size - 1; i++)
                std::swap(*m_array.get(i), *m_array.get(i + 1));
            
            m_array.get(m_size - 1)->~T();
            m_size--;
        }
    }

    void clear()
    {
        for (int i = m_size - 1; i >= 0; i--)
            pop_back();
    }

    inline T &operator[](const size_t index)
    {
        assert_m(index >= m_size, "index out of range");

        return *m_array.get(index);
    }

    static_vector& operator=(const static_vector& other) = delete;
};

#endif
