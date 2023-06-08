#pragma once

#include <iostream>
#include <exception>
#include <iterator>


class DynamicArrayOutOfBounds : std::exception
{

}OutOfBounds;




template<typename T>
class DynamicArray
{
private:
    size_t cur_size = 0;
    size_t cur_capacity = 0;
    bool isEmpty = true;
    T* current = nullptr;
    T* array = nullptr;

public:

    /*
     * Constructor & Destructors
     */


    /*
     * Capacity Methods
     */
    bool empty() { return (cur_size == 0) ? true : false; }
    size_t size() { return cur_size; }
    size_t capacity() { return cur_capacity; }
    void shrink_to_fit()
    {
        T* tmp_arr  = new T[cur_size];

        for(int i=0; i<cur_size; i++) { tmp_arr[i] = array[i]; }

        delete[] array;
        array = tmp_arr;

        // Capacity needs to reflect resizing
        cur_capacity = cur_size;
    };

    // size_t max_size(){}; -> NOT IMPLEMENTED
    // reserver() -> NOT IMPLEMENTED

    /*
     * Modifier Methods
     */

    void clear()
    {
        for(int i=0; i<=cur_capacity; i++) { array[i] = 0; }
        cur_size = 0;
        isEmpty = true;
        current = nullptr;
    };

//    void insert(){};
//    void erase(){};

    void push_back(T&& data)
    {
        if(cur_size == 0)
        {
            cur_capacity++;
            array = new T[cur_capacity];

            array[cur_size] = data;
            current = &array[cur_size];
            cur_size++;
            return;
        }

        if(cur_size == cur_capacity)
        {
            T* tmp_arr = new T[2 * cur_capacity];

            // Move All Data from previous array to tmp array
            for(int i=0; i<=cur_capacity; i++) { tmp_arr[i] = array[i]; }

            // Update Capacity, Free prev array, & Assign tmp ptr to array
            cur_capacity *= 2;
            delete[] array;
            array = tmp_arr;
        }

        // Complete PushBack, Get current element, Incr size.
        array[cur_size] = data;
        current = &array[cur_size];
        cur_size++;
    };

    void Print()
    {
        for(int i=0; i < cur_capacity; i++)
        {
            std::cout <<"Index " << i << "  " << array[i] << std::endl;
        }
    }
    void pop_back()
    {
        array[cur_size] = 0;
        cur_size--;
        current = &array[cur_size];
    };

    void resize(size_t count, T value=0)
    {
        if(cur_size > count)
        {
            T* tmp_array = new T[count];
            for(int i=0; i< count; i++) { tmp_array[i] = array[i]; }
            delete[] array;
            array = tmp_array;
        }
        else
        {
            // Extend to count and default values to given value parameter
            T* tmp_array = new T[count];
            for(int i=0; i < count; i++)
            {
                if(i < cur_size)
                {
                    tmp_array[i] = array[i];
                }
                else
                {
                    tmp_array[i] = value;
                }

            }
            delete[] array;
            array = tmp_array;
        }

        cur_size = count;
        cur_capacity = count;
        current = &array[count];
    };

    // emplace_back(){} -> NOT IMPLEMENTED
    // emplace -> NOT IMPLEMENTED
    // swap() -> NOT IMPLEMENTED


    /*
     * Element Access Methods
     */

    T& at(size_t idx)
    {
        if( idx > cur_capacity) { throw OutOfBounds; }

        return array[idx];
    }

    T& front() {  return array[0]; }
    T& back() {  return *current; }
    // data(){};   ?????



    /*
     * Iterator Methods
     */

    class iterator {
    public:

        // Iterator Type Aliases
        using iterator_category = std::random_access_iterator_tag;
        using value_type = DynamicArray<T>;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T &;

        // Iterator Constructor
        iterator(pointer ptr) : ptr_(ptr) {}

        // Dereference Operator
        reference operator*() const { return *ptr_; }
        pointer operator->() const { return ptr_; }

        // Pre / Post-Increment Operator
        iterator& operator++() { ptr_ += 1; return *this; }
        iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }

        // Equality / Inequality Operator
        bool operator== (const iterator& other) { return this->ptr_ == other.ptr_; }
        bool operator!= (const iterator& other) { return this->ptr_ != other.ptr_; }

    private:
        pointer ptr_;
    };

    class reverse_iterator
    {
    public:

        // Reversed Iterator Type Aliases
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        // Iterator Constructor
        reverse_iterator(pointer ptr) : ptr_(ptr) {}

        // Dereference Operator
        reference operator*() const { return *ptr_; }
        pointer operator->() const { return ptr_; }

        // Pre / Post-Increment Operator
        reverse_iterator& operator++() { ptr_ -= 1; return *this; }
        reverse_iterator operator++(int) { reverse_iterator tmp = *this; ++(*this); return tmp; }

        // Equality / Inequality Operator
        bool operator== (const reverse_iterator& other) { return this->ptr_ == other.ptr_; }
        bool operator!= (const reverse_iterator& other) { return this->ptr_ != other.ptr_; }

    private:
        pointer ptr_;
    };

    iterator begin() { return iterator(&array[0]); }
    iterator end()
    {
        T* end_ptr = current + 1;
        return iterator(end_ptr);
    }

    reverse_iterator rbegin() { return reverse_iterator(current); }
    reverse_iterator rend()
    {
        T* end_ptr = &array[0] - 1;
        return reverse_iterator(end_ptr);
    }
};




