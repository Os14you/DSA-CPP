#ifndef MINHEAP_HPP
#define MINHEAP_HPP

#include <iostream>
#include <cassert>
#include <vector>

class MinHeap {
private:
    int* heap;
    int size;
    int capacity;
    int left_child(int idx);
    int right_child(int idx);
    int parent(int idx);
    void heapifyUp(int child_idx);
    void heapifyDown(int parent_idx);
    void heapify();

public:
    MinHeap();
    MinHeap(int capacity);
    MinHeap(const std::vector<int>& values);
    void push(int value);
    int top();
    int pop();
    bool isEmpty();
    bool isFull();
    ~MinHeap();
};


#endif /* MINHEAP_HPP */