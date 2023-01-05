#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cassert>

#define assert_m(exp, msg) assert(((void)msg, !(bool(exp))))

template <class T>
class Array
{
public:
    Array() : m_array{new T[max_size]}, m_size{0} {}
    Array(const Array &other) = delete;

    bool full() const { return m_size == max_size; }

    bool empty() const { return m_size == 0; }

    size_t size() const { return m_size; }

    static size_t max_size() { return max_size; }

    void push_front(const T &value)
    {
        assert_m(full(), "array overflow");

        for (int i = m_size - 1; i >= 0; i--)
            std::swap(m_array[i], m_array[i + 1]);

        m_array[0] = value;
        m_size++;
    }

    void push_back(const T &value)
    {
        assert_m(full(), "array overflow");

        m_array[m_size] = value;
        m_size++;
    }

    void pop_front()
    {
        assert_m(empty(), "array is empty");

        for (size_t i = 0; i < m_size - 1; i++)
            std::swap(m_array[i], m_array[i + 1]);

        m_array[m_size - 1] = T();
        m_size--;
    }

    void pop_back()
    {
        assert_m(empty(), "array is empty");

        m_array[m_size - 1] = T();
        m_size--;
    }

    void insert(const size_t pos, const T &value)
    {
        assert_m(full(), "array overflow");
        assert_m(pos >= m_size, "index out of range");

        T val(value);
        for (size_t i = pos; i < m_size; i++)
            std::swap(m_array[i], val);
            
        m_array[m_size] = val;
        m_size++;
    }

    void erase(const size_t pos)
    {
        assert_m(empty(), "array is empty");
        assert_m(pos >= m_size, "index out of range");
        
        if (pos == 0)
            pop_front();
        else if (pos == m_size - 1)
            pop_back();
        else
        {
            for (size_t i = pos; i < m_size - 1; i++)
                std::swap(m_array[i], m_array[i + 1]);
            
            m_size--;
        }
    }

    void clear()
    {
        delete[] m_array;
        m_array = nullptr;
        m_size = 0;
    }

    Array& operator=(const Array &other) = delete;

    T &operator[](const size_t index)
    {
        assert_m(index >= m_size, "index out of range");
        
        return m_array[index];
    }

    ~Array()
    {
        clear();
    }

private:
    T *m_array;
    size_t m_size;
    const static size_t max_size = 4;
};

#endif
