#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <cassert>

class Vector {
    private:
        int* arr = nullptr;
        int size = 0;
        int capacity = 0;
        void expand_capacity();
    public:
        Vector(int s);
        int get(const int &idx);
        void set(const int &idx, const int &value);
        int getSize() const;
        void insert(const int &idx, const int &value);
        void push_back(const int &value);
        void shift_right(int times);
        void print();
        int pop(int idx); 
        int find(const int &value);
        int find_transposition(const int &value);
        ~Vector();
};

#endif // VECTOR_HPP