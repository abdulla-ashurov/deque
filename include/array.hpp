#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array
{
    int *array;
    size_t size;
    const static size_t max_size = 4;

public:
    Array() : array{new int[max_size]}, size{0} {}

    bool full() const { return size == max_size; }
    
    size_t get_size() const { return size; }

    void push_back(const int &value)
    {
        if (full())
            throw std::overflow_error("array overflow");

        array[size] = value;
        size++;
    }

    void clear() { delete[] array; }

    int &operator[](const size_t index)
    {
        if (index >= size)
            throw std::invalid_argument("invalid index");

        return array[index];
    }

    ~Array() { clear(); }
};

#endif
