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

    // Fill array by setting every entry `i` to `fn(i)`.
    template <typename Fn>
    void fill_with_fn(Fn fn);

private:
    int len;
    T* buf;

    bool in_bounds(int index) const {
        return index >= 0 && index < len;
    }
};

// Implement the free-standing operator<< and operator>> here.
// Because they are templates, you do not need the `inline`.

#endif
