#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "array.hpp"

template <typename T>
class Matrix {
public:
    // Construct 0x0 matrix
    Matrix() : rows(0), cols(0), data() {
	}

    // Construct matrix with given number of rows and columns.
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
		data = Array<Array<T>>{rows};
		for (int r=0; r< rows; ++r) {
			data[r] = Array<T>{cols};
		}
	}

    // Get a particular row of the matrix.
    Array<T>& operator[](int row) {
		try {
			return data[row];
		} catch(std::string s) {
			std::cerr << s << std::endl;
		}
	}
		

	const Array<T>& operator[](int row) const {
		try {
			return data[row];
		} catch(std::string s) {
			std::cerr << s << std::endl;
		}
	}

    // Get number of rows / columns
    int num_rows() const {
		return this->rows;
	}
    int num_cols() const {
		return this->cols;
	}

    // Fill every entry of the matrix with given value `val`.
    void fill(const T& val) {
		for (int r = 0; r<this->rows; ++r) {
			for (int c = 0; c<cols; ++c) {
				data[r][c] = val;
			}
		}
	}

    // Fill matrix, set entry in row `i` and column `j`
    // to `fn(i, j)`.
    template <typename Fn>
    void fill_with_fn(Fn fn) {
	for (int r = 0; r<this->rows; ++r) {
			for (int c = 0; c<cols; ++c) {
				data[r][c] = fn(r , c);
			}
		}
	}
	


private:
    int rows, cols;
    Array<Array<T>> data;
};

// Print matrix to `out`.
// Each row should be printed as a separate line.
template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
	for (int r = 0; r<matrix.num_rows(); ++r) {
			for (int c = 0; c<matrix.num_cols(); ++c) {
				out << matrix[r][c] << ' ';
			}
			out << '\n';
		}
		return out;
	}
				

// Read matrix from `in`.
// Assume the matrix is given in a format like
//      1 2 3
//      4 5 6
// for a 2-row, 3-column matrix.
template <typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& matrix){
	T value;
	for (int i=0; i<matrix.num_rows(); ++i) {
		for (int c=0; c<matrix.num_cols(); ++c) {
			if (in >> value) {
				matrix[i][c] = value;
			}
		}
	}
	return in;
}

#endif
