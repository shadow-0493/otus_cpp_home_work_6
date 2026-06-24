#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <map>
#include "proxy_array.hpp"

template <typename T, T default_value>
class Matrix
{
    std::map<unsigned long, Array<T, default_value>> data;

    class _MatrixProxy
    {
        Matrix &mat;
        unsigned long row;

    public:
        _MatrixProxy(Matrix &m, unsigned long r) : mat(m), row(r) {}

        auto operator[](unsigned long col)
        {
            return mat.data[row][col];
        }
    };

public:
    _MatrixProxy operator[](unsigned long row)
    {
        return _MatrixProxy(*this, row);
    }

    size_t size() const
    {
        size_t count = 0;
        for (const auto &[row, arr] : data)
        {
            count += arr.size();
        }
        return count;
    }

    size_t max_row() const
    {
        if (data.empty())
        {
            return 0;
        }

        return data.rbegin()->first;
    }

    size_t max_col() const
    {
        size_t max = 0;
        for (const auto &[row, arr] : data)
        {
            if (!arr.data.empty())
            {
                size_t last = arr.data.rbegin()->first;
                if (last > max)
                {
                    max = last;
                }
            }
        }
        return max;
    }

    auto begin() { return data.begin(); }
    auto end() { return data.end(); }
    auto begin() const { return data.begin(); }
    auto end() const { return data.end(); }
};

#endif // MATRIX_HPP