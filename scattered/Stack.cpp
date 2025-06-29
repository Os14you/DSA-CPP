#include "Stack.hpp"
#include <iostream>
#include <cassert>

template <typename dataType>
Stack<dataType>::Stack() : top(nullptr) { }

template <typename dataType>
dataType Stack<dataType>::peek() {
    assert(!isEmpty());
    return top->data;
}

template <typename dataType>
bool Stack<dataType>::isEmpty() {
    return top == nullptr;
}

template <typename dataType>
void Stack<dataType>::display() {
    assert(!isEmpty());

    for(Node<dataType>* current = top; current; current = current->next)
        std::cout << "| " << current->data << " |\n";
    
    std::cout << "----" << std::endl;
}

template <typename dataType>
void Stack<dataType>::push(dataType value) {
    Node<dataType>* new_node = new Node(value);
    new_node->next = top;
    top = new_node;
}

template <typename dataType>
dataType Stack<dataType>::pop() {
    assert(!isEmpty());

    dataType popped = top->data;
    Node<dataType>* to_pop = top;
    top = top->next;
    delete to_pop;

    return popped;
}

template <typename dataType>
Stack<dataType>::~Stack() {
    while(top) {
        pop();
    }
}

template class Stack<int>;
template class Stack<char>;