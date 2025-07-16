#ifndef MAXHEAP_HPP
#define MAXHEAP_HPP

#include <iostream>
#include <cassert>
#include <vector>

class MaxHeap {
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
    MaxHeap();
    MaxHeap(int capacity);
    MaxHeap(const std::vector<int>& values);
    void push(int value);
    int top();
    int pop();
    bool isEmpty();
    bool isFull();
    ~MaxHeap();
};


#endif /* MAXHEAP_HPP */