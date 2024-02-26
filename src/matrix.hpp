#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "array.hpp"

template <typename T>
class Matrix {
public:
    // Construct 0x0 matrix
    Matrix();

    // Construct matrix with given number of rows and columns.
    Matrix(int rows, int cols);

    // Get a particular row of the matrix.
    Array<T>& operator[](int row);
    const Array<T>& operator[](int row) const;

    // Get number of rows / columns
    int num_rows() const;
    int num_cols() const;

    // Fill every entry of the matrix with given value `val`.
    void fill(const T& val);

    // Fill matrix, set entry in row `i` and column `j`
    // to `fn(i, j)`.
    template <typename Fn>
    void fill_with_fn(Fn fn);

private:
    int rows, cols;
    Array<Array<T>> data;
};

// Print matrix to `out`.
// Each row should be printed as a separate line.
template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix);

// Read matrix from `in`.
// Assume the matrix is given in a format like
//      1 2 3
//      4 5 6
// for a 2-row, 3-column matrix.
template <typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& matrix);

#endif
