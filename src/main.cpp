#include "proxy_matrix.hpp"
#include <iostream>

template <typename T, T default_value>
void print_fragment(Matrix<T, default_value> &matrix,
                    std::pair<unsigned long, unsigned long> rows,
                    std::pair<unsigned long, unsigned long> cols)
{
    for (unsigned long i = rows.first; i <= rows.second; ++i)
    {
        for (unsigned long j = cols.first; j <= cols.second; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}
template <typename T, T default_value>
void print_all_elements(Matrix<T, default_value> &matrix)
{
    for (const auto &[row, arr] : matrix)
    {
        for (const auto &[col, value] : arr)
        {
            std::cout << "cell" << "[" << row << "][" << col << "] = " << value << "\n";
        }
    }
}

int main()
{
    Matrix<int, -1> matrix;

    for (int i = 0; i <= 9; ++i)
    {
        matrix[i][i] = i;
    }

    for (int i = 0; i <= 9; ++i)
    {
        matrix[i][9 - i] = 9 - i;
    }

    std::cout << "Matrix [1,1] to [8,8]:\n";
    print_fragment(matrix, {1, 8}, {1, 8});

    std::cout << "\nOccupied cells: " << matrix.size() << "\n";

    // 5. Все занятые ячейки
    std::cout << "\nAll occupied cells:\n";
    print_all_elements(matrix);

    return 0;
}