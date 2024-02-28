#ifndef INT_ARRAY_HPP
#define INT_ARRAY_HPP

#include <cstddef>
#include <iostream>
#include <sstream>
#include <utility>

class Array {
public:
    // Construct zero-length array.
    Array() : len(0), buf(nullptr) {}

    // Construct array of given length.
    explicit Array(int len) : len(len), buf(new int[len]) {}

    // Copy & move constructors (TODO: implement these).
    Array(const Array& other): buf(new int[other.len]) {
		for (int i=0; i<other.len; ++i) {
			buf[i] = other.buf[i];
		}
		len = other.len;
	}

    Array(Array&& other) {
		buf = other.buf;
		other.buf = nullptr;

		len = other.len;
		other.len = 0;
	}

    // Swap two arrays (without allocations).
    // Note: now a friend function,
    // which is the more common way to do it.
    friend void swap(Array& lhs, Array& rhs) noexcept {
        std::swap(lhs.len, rhs.len);
        std::swap(lhs.buf, rhs.buf);
    }

    // Copy & move assignment (TODO: implement these).
    Array& operator=(const Array& other) {
		if (this!= &other) {
			delete buf;
			int* newData = new int[other.len];
			for (int i=0; i<other.len; ++i) {
			newData[i] = other.buf[i];
			}
			this->buf = newData;
			this->len = other.len;

			}
		return *this;
		}

	
    Array& operator=(Array&& other) noexcept {
		if (this != &other) {
		delete buf;
		this->buf = other.buf;
		this->len = other.len;

		other.buf = nullptr;
		other.len = 0;
		}

		return *this;
	}

    // Destructor
    ~Array() {
    	delete[] buf;
		}

    // Get the length of the array.
    int length() const {
        return len;
    }

    // Get a particular element of the array
    // (TODO: add bounds check).
    int& operator[](int index) {
		if (!in_bounds(index)) {
			throw "Exception operator[](" + std::to_string(index) + ") Out Of Range";
		}
		return buf[index];

    }

    // Get a particular element of the array
    // (TODO: add bounds check).
    const int& operator[](int index) const {
		if (!in_bounds(index)) {
			throw "Exception operator[](" + std::to_string(index) + ") Out Of Range";
		}
		return buf[index];

    }

    // Set every element of the array to 'val'
    // (TODO: implement this).
    void fill(int val) {
		int curLength = this->length();
		for (int index = 0; index <= curLength; ++index) {
			buf[index] = val;
		}
	}
private:
    int len;
    int* buf;

    bool in_bounds(int index) const {
        return index >= 0 && index < len;
    }
};

// Print array to 'out' in a single line.
inline std::ostream& operator<<(std::ostream& out, const Array& array) {
    std::stringstream temp;
    // We don't want to set formatting flags globally.
    temp << std::setprecision(2) << std::fixed << std::right;

    for (int i = 0; i < array.length(); ++i) {
        temp << std::setw(8) << array[i];
    }

    out << temp.str();
    return out;
}

// Read array from 'in', entries should be separated by whitespace.
inline std::istream& operator>>(std::istream& in, Array& array) {
    for (int i = 0; i < array.length(); ++i) {
        in >> array[i];
    }
    return in;
}

#endif
