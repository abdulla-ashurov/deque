#ifndef VECTOR_HPP
#define VECTOR_HPP

template <class T>
class Vector
{
    T *array;
    size_t size;
    size_t max_size;

public:
    Vector(const size_t max_size)
        : array(new T[max_size]), max_size(max_size), size(0) {}

    void push_back(const T &value)
    {
        if (!full())
        {
            array[size] = value;
            size++;
        }
    }

    void clear()
    {
        delete[] array;
    }

    bool full() const { return size == max_size; }

    ~Vector()
    {
        clear();
    }
};

#endif