#pragma once
#include<iterator>


/*
 * Random Access Iterator
 */

template<typename T>
class iterator
{
public:

    // Iterator Type Aliases
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    // Iterator Constructor
    iterator(pointer ptr) : ptr_(ptr) {}

    // Access Operators
    // -> , []
    reference operator[](const int pos) { return *(ptr_ + pos); }
    pointer operator->() const { return ptr_; }

    // Read Operators
    // =*i
    reference operator*() const { return *ptr_; }

    // Write/Assignment Operators
    // *i=
//    operator= () {  }




    // Iterate Operators
    // ++, --, +=, -==, + -
    iterator& operator++() { ptr_++; return *this; }
    iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }

    //Comparison Operators
    // ==, !=, <, >, ,+, >=

    bool operator== (const iterator& other) { return this->ptr_ == other.ptr_; }
    bool operator!= (const iterator& other) { return this->ptr_ != other.ptr_; }

private:
    pointer ptr_;
};

// Reverse Random Access Iterator

template<typename T>
class reverse_iterator
{
public:

    // Iterator Type Aliases
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    // Iterator Constructor
    reverse_iterator(pointer ptr) : ptr_(ptr) {}

    // Access Operators
    // -> , []

//    T& operator[](int pos) const { return *(ptr_ + pos); }

    // Read Operators
    // =*i

    // Write Operators
    // *i=

    // Iterate Operators
    // ++, --, +=, -==, + -

    //Comparison Operators
    // ==, !=, <, >, ,+, >=



    // Dereference Operator
    reference operator*() const { return *ptr_; }
    pointer operator->() const { return ptr_; }

    // Pre / Post-Increment Operator
    reverse_iterator& operator++() { ptr_ -= 1; return *this; }
    reverse_iterator operator++(int) { iterator tmp = *this; --(*this); return tmp; }

    // Equality / Inequality Operator
    bool operator== (const reverse_iterator& other) { return this->ptr_ == other.ptr_; }
    bool operator!= (const reverse_iterator& other) { return this->ptr_ != other.ptr_; }

private:
    pointer ptr_;
};