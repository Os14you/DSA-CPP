#include "Stack.hpp"
#include <iostream>
#include <cassert>

Stack::Stack() : Stack(10) { }
Stack::Stack(int size) : size(size), top(-1) {
    arr = new int[size] { };  
}

int Stack::peek() {
    return arr[top];
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == size - 1;
}

void Stack::display() {
    for (int i=top; i>=0; --i) {
        std::cout << " | " << arr[i] << " | \n";
    }
    std::cout << " ----- " << std::endl;
}

void Stack::push(int value) {
    assert(!isFull());
    arr[++top] = value;
}

int Stack::pop() {
    assert(!isEmpty());
    return arr[top--];
}

Stack::~Stack() {
    delete[] arr;
}