#pragma once

#include "ArrayIterator.h"
#include <exception>

class ArrayOutOfBoundsException : public std::exception
{

} BoundsException;

template <typename T, size_t len>
class Array
{

public:

    /*
     * Class Constructors & Destructors
     */

    Array() = default;
    //    ~Array();

    // Move & Copy Constructors

    /*
     * Operator Overloads
     */

    // Operator Overloading
    T& operator[](const size_t pos) {return _array[pos];}

    /*
     * Public Methods
     */

    T& at(const size_t pos)
    {
        // Check Array Boundsary
        if (pos < len)
        {
            return _array[pos];
        }

        throw BoundsException;
    }

    T* data() { return _array; }
    size_t size() { return len; }
    T& front() { return _array[0]; }
    T& back() { return _array[len-1]; }
    bool empty(){ return (len>0) ? false : true; }

    /*
     * Array Iterators
     */

    iterator<T> begin() { return iterator<T>(_array); }
    iterator<T> end() { return iterator<T>(_array+len); }
    reverse_iterator<T> rbegin() { return reverse_iterator<T>(_array + (len-1)); }
    reverse_iterator<T> rend() { return reverse_iterator<T>(_array-1); }

private:
    T _array[len] {};
};
















