#ifndef __ALIGNED_STORAGE__
#define __ALIGNED_STORAGE__

template <typename T, size_t Size>
class AlignedStorage
{
private:
    uint8_t storage[sizeof(T) * Size + alignof(T)];

    inline T *begin()
    {
        uintptr_t padding = (uintptr_t)((void *)(storage)) % alignof(T);
        if (padding != 0)
            return (T *)(storage + alignof(T) - padding);

        return (T *)(storage);
    }

public:
    inline T *get(const size_t index)
    {
        return begin() + index;
    }
};

#endif
