#include <iostream>
#include "ArrayBasedQueue.hpp"
#include <cassert>

MyQueue::MyQueue(int capacity) : capacity(capacity) {
    assert(capacity > 0);
    arr = new int[capacity];
}

bool MyQueue::isEmpty() {
    return num_elements == 0;
}

bool MyQueue::isFull() {
    return num_elements == capacity;
}

int MyQueue::next(int idx) {
    // return (idx+1) % capacity;

    ++idx;
    if(idx == capacity) 
        idx = 0;

    return idx;
}

void MyQueue::enqueue(int value) {
    assert(!isFull());
    arr[rear] = value;
    rear = next(rear);
    ++num_elements;
}

int MyQueue::dequeue() {
    assert(!isEmpty());
    int temp = arr[front];
    front = next(front);
    --num_elements;
    return temp;
}

void MyQueue::display() {
    if(isEmpty()) std::cout << "Empty Queue, ADD MORE ELEMENTS" << std::endl;
    else {
        for(int current = front, step = 0; step < num_elements; ++step, current = next(current))
            std::cout << arr[current] << "\n";
    }
}

MyQueue::~MyQueue() {
    delete[] arr;
}