#include "MinHeap.hpp"

MinHeap::MinHeap() : MinHeap(100) {}
MinHeap::MinHeap(int capacity) : capacity(capacity), size(0) { heap = new int[capacity]; }

MinHeap::MinHeap(const std::vector<int>& values) : MinHeap(1000) {
    size = values.size();

    for(int i=0; i<size; ++i)
        heap[i] = values[i];

    heapify();
}

void MinHeap::heapify() {
    for(int i=(size/2) - 1; i>=0; --i)
        heapifyDown(i);
}

int MinHeap::left_child(int idx) { 
    return 2*idx + 1 > size ? -1 : 2*idx + 1; 
}
int MinHeap::right_child(int idx) { 
    return 2*idx + 2 > size ? -1 : 2*idx + 2;
}

int MinHeap::parent(int idx) { 
    return (idx-1)/2 >= 0 ? (idx-1)/2 : -1; 
}

int MinHeap::top() { return heap[0]; }

void MinHeap::heapifyUp(int child_idx) {
    int parent_idx = parent(child_idx);
    
    if(!child_idx || heap[parent_idx] < heap[child_idx]) 
        return;

    std::swap(heap[parent_idx], heap[child_idx]);
    heapifyUp(parent_idx);
}

void MinHeap::push(int value) {
    assert(!isFull());
    heap[size++] = value;
    heapifyUp(size-1);
}

void MinHeap::heapifyDown(int parent_idx) {
    int left_child_idx = left_child(parent_idx);
    int right_child_idx = right_child(parent_idx);

    if(left_child_idx == -1)
        return;
    
    int mn = min(left_child_idx, right_child_idx);
    if(mn == -1 || heap[parent_idx] < heap[mn])
        return;
    
    std::swap(heap[parent_idx], heap[mn]);
    heapifyDown(mn);
}

int MinHeap::pop() {
    assert(!isEmpty());
    int value = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return value;
}

bool MinHeap::isEmpty() { return size == 0; }
bool MinHeap::isFull() { return size == capacity; }

MinHeap::~MinHeap() { 
    delete[] heap; 
    heap = nullptr; 
}