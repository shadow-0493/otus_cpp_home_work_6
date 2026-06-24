#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <map>
#include <iostream>

template <typename T, T default_value>
class Array
{
    std::map<unsigned long, T> data;

    class ArrayProxy_
    {
        Array &arr;
        unsigned long index;

    public:
        ArrayProxy_(Array &a, unsigned long i) : arr(a), index(i) {}

        operator T() const
        {
            auto it = arr.data.find(index);
            if (it != arr.data.end())
            {
                return it->second;
            }
            return default_value;
        }

        ArrayProxy_ &operator=(T value)
        {
            if (value == default_value)
            {
                arr.data.erase(index);
            }
            else
            {
                arr.data[index] = value;
            }
            return *this;
        }
    };

public:
    ArrayProxy_ operator[](unsigned long index)
    {
        return ArrayProxy_(*this, index);
    }

    size_t size() const { return data.size(); }

    auto begin() { return data.begin(); }
    auto end() { return data.end(); }
    auto begin() const { return data.begin(); }
    auto end() const { return data.end(); }
};

#endif // ARRAY_HPP