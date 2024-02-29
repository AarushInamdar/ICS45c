#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>

template <typename T>
class Array {
public:
    // Implement all methods from int_array.hpp here
	Array() : len(0), buf(nullptr) {}

    // Construct array of given length.
    explicit Array(int len) : len(len), buf(new T[len]) {
	}

    // Copy & move constructors (TODO: implement these).
    Array(const Array& other): buf(new T[other.len]) {
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
			delete[] buf;
			T* newData = new T[other.len];
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
		delete[] buf;
		this->buf = other.buf;
		this->len = other.len;
		other.buf = nullptr;
		other.len = 0;
		}

		return *this;


	}
	
    ~Array() {
    	delete[] buf;
		}

    // Get the length of the array.
    int length() const {
        return len;
    }

    // Get a particular element of the array
    T& operator[](int index) {
		if (!in_bounds(index)) {
			throw "Exception operator[](" + std::to_string(index) + ") Out Of Range";
		}
		return buf[index];

    }

    // Get a particular element of the array
    const T& operator[](int index) const {
		if (!in_bounds(index)) {
			throw "Exception operator[](" + std::to_string(index) + ") Out Of Range";
		}
		return buf[index];

    }

    // Fill array by setting every entry `i` to `fn(i)`.
    template <typename Fn>
    void fill_with_fn(Fn fn) {
		for (int i =0; i < len; ++i) {
			buf[i] = fn(i);
		}
	}


private:
    int len;
    T* buf;

    bool in_bounds(int index) const {
        return index >= 0 && index < len;
    }
};

// Implement the free-standing operator<< and operator>> here.
// Because they are templates, you do not need the `inline`.
std::ostream& operator<<(std::ostream& out, const Array<auto>& array) {
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
std::istream& operator>>(std::istream& in, Array<auto>& array) {
    for (int i = 0; i < array.length(); ++i) {
        in >> array[i];
    }
    return in;
	}

#endif
