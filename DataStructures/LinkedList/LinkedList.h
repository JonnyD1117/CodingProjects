

#pragma once

#include <iostream>
#include <list>

template<typename T>
struct Node
{
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;

    Node();
    Node(T data) : data(data) {};
};

template <typename T>
class LinkedList {

private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    bool _init = false;

public:

    LinkedList() = default;
    LinkedList(T data)
    {
        head = new Node<T>(data);
        tail = head;
        _init = true;
    }

    class iterator
    {
        public:

            // Iterator Type Aliases
            using iterator_category = std::forward_iterator_tag;
            using value_type = Node<T>;
            using difference_type = std::ptrdiff_t;
            using pointer = Node<T>*;
            using reference = Node<T>&;

            // Iterator Constructor
            iterator(pointer ptr) : ptr_(ptr) {}

            // Dereference Operator
            reference operator*() const { return *ptr_; }
            pointer operator->() const { return ptr_; }

            // Pre / Post-Increment Operator
            iterator& operator++() { ptr_=ptr_->next; return *this; }
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
        using value_type = Node<T>;
        using difference_type = std::ptrdiff_t;
        using pointer = Node<T>*;
        using reference = Node<T>&;

        // Iterator Constructor
        reverse_iterator(pointer ptr) : ptr_(ptr) {}

        // Dereference Operator
        reference operator*() const { return *ptr_; }
        pointer operator->() const { return ptr_; }

        // Pre / Post-Increment Operator
        reverse_iterator& operator++() { ptr_=ptr_->prev; return *this; }
        reverse_iterator operator++(int) { reverse_iterator tmp = *this; ++(*this); return tmp; }

        // Equality / Inequality Operator
        bool operator== (const reverse_iterator& other) { return this->ptr_ == other.ptr_; }
        bool operator!= (const reverse_iterator& other) { return this->ptr_ != other.ptr_; }

    private:
        pointer ptr_;
    };

    iterator begin() { return iterator(head); }
    iterator end() { return iterator(tail->next); }
    reverse_iterator rbegin() { return reverse_iterator(tail); }
    reverse_iterator rend() { return reverse_iterator(head->prev); }

    Node<T>& getHead()
    {
        return *head;
    }

    void clear()
    {
        Node<T>* cur = head;
        Node<T>* tmp;

        do
        {
            tmp = cur->next;
            delete cur;
            cur = tmp;
        }
        while(cur->next != nullptr);

        head = tail = nullptr;
        _init = false;
    }

    bool empty()
    {
        if(size() > 0 )
        {
            return false;
        }
        return true;
    }

    int size()
    {
        int _size = 0;
        return (_init) ? std::distance(begin(), end()) : _size;
    }


    void Add(T data)
    {
        // Check if Head node has been initialized
        if(head == nullptr)
        {
            head = new Node<T>(data);
            tail = head;
            _init = true;
            return;
        }

        // Copy pointer to Lists current tail node
        Node<T>* current = tail;

        // Point the current tail's "next" pointer to new node
        current->next = new Node<T>(data);

        // Update Pointer to Previous Node
        current->next->prev = current;

        // Update pointer to tail node
        tail = current->next;
    }

    void Remove()
    {
        Node<T>* new_tail = tail->prev;
        new_tail->next = nullptr;
        delete tail;
        tail = new_tail;
    }

    void Print()
    {
        for(auto i : *this)
        {
            std::cout<< i.data << std::endl;
        }
    }
};