#include <iostream>
#include "Deque.hpp"
#include <cassert>

Deque::Deque(int capacity) : capacity(capacity) {
    assert(capacity > 0);
    arr = new int[capacity];
}

int Deque::next(int idx) {
    ++idx;
    if(idx == capacity)
        idx = 0;
    
    return idx;
}

int Deque::prev(int idx) {
    --idx;
    if(idx < 0)
        idx = capacity - 1;
    
    return idx;
}

bool Deque::isEmpty() {
    return num_elements == 0;
}


bool Deque::isFull() {
    return num_elements == capacity;
}


void Deque::enqueue_front(int value) {
    assert(!isFull());
    front = prev(front);
    arr[front] = value;
    ++num_elements;
}


void Deque::enqueue_rear(int value) {
    assert(!isFull());
    arr[rear] = value;
    rear = next(rear);
    ++num_elements;
}



int Deque::dequeue_front() {
    assert(!isEmpty());
    int value = arr[front];
    front = next(front);
    --num_elements;
    return value;
}


int Deque::dequeue_rear() {
    assert(!isEmpty());
    rear = prev(rear);
    --num_elements;
    return arr[rear];
}


void Deque::display() {
    if(isEmpty()) std::cout << "Empty queue, ADD MORE ELEMENTS" << std::endl;
    else {
        for(int current = front, step = 0; step < num_elements; ++step, current = next(current))
            std::cout << arr[current] << " | ";
        std::cout << std::endl;
    }
}


Deque::~Deque() {
    delete[] arr;
}

