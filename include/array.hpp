#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cassert>

#define assert_m(exp, msg) assert(((void)msg, !(bool(exp))))

template <class T>
class Array
{
private:
    T *array;
    size_t _size;
    const static size_t max_size = 4;

public:
    Array() : array{new T[max_size]}, _size{0} {}
    Array(const Array &other) = delete;

    bool full() const { return _size == max_size; }

    bool empty() const { return _size == 0; }

    size_t size() const { return _size; }

    static size_t get_max_size() { return max_size; }

    void push_front(const T &value)
    {
        assert_m(full(), "array overflow");

        for (int i = _size - 1; i >= 0; i--)
            array[i + 1] = array[i];

        array[0] = value;
        _size++;
    }

    void push_back(const T &value)
    {
        assert_m(full(), "array overflow");

        array[_size] = value;
        _size++;
    }

    void pop_front()
    {
        assert_m(empty(), "array is empty");

        for (size_t i = 0; i < _size - 1; i++)
            array[i] = array[i + 1];

        array[_size - 1] = T();
        _size--;
    }

    void pop_back()
    {
        assert_m(empty(), "array is empty");

        array[_size - 1] = T();
        _size--;
    }

    void clear()
    {
        delete[] array;
        array = nullptr;
        _size = 0;
    }

    Array& operator=(const Array &other) = delete;

    T &operator[](const size_t index)
    {
        assert_m(index >= _size, "index out of range");
        
        return array[index];
    }

    ~Array()
    {
        clear();
    }
};

#endif
