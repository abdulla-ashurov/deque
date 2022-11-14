#ifndef ARRAY_HPP
#define ARRAY_HPP

template<class T>
class Array
{
    T *array;
    size_t size;
    const static size_t max_size = 4;

public:
    Array() : array{new T[max_size]}, size{0} {}

    bool full() const { return size == max_size; }

    bool empty() const { return size == 0; }

    size_t get_size() const { return size; }

    static size_t get_max_size() { return max_size; }

    void push_back(const T &value)
    {
        if (full())
            throw std::overflow_error("array overflow");

        array[size] = value;
        size++;
    }

    void pop_back()
    {
        if (empty())
            throw std::runtime_error("array is empty");

        array[size - 1] = 0;
        size--;
    }

    void clear()
    {
        delete[] array;
        array = nullptr;
        size = 0;
    }

    T &operator[](const size_t index)
    {
        if (index >= size)
            throw std::out_of_range("index out of range");

        return array[index];
    }

    ~Array()
    {
        clear();
    }
};

#endif
