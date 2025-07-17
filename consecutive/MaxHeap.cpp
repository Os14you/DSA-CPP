#include "MaxHeap.hpp"

MaxHeap::MaxHeap() : MaxHeap(100) {}
MaxHeap::MaxHeap(int capacity) : capacity(capacity), size(0) { heap = new int[capacity]; }

MaxHeap::MaxHeap(const std::vector<int>& values) : MaxHeap(1000) {
    size = values.size();

    for(int i=0; i<size; ++i)
        heap[i] = values[i];

    heapify();
}

void MaxHeap::heapify() {
    for(int i=(size/2) - 1; i>=0; --i)
        heapifyDown(i);
}

int MaxHeap::left_child(int idx) { 
    return 2*idx + 1 > size ? -1 : 2*idx + 1; 
}
int MaxHeap::right_child(int idx) { 
    return 2*idx + 2 > size ? -1 : 2*idx + 2;
}

int MaxHeap::parent(int idx) { 
    return (idx-1)/2 >= 0 ? (idx-1)/2 : -1; 
}

int MaxHeap::top() { return heap[0]; }

void MaxHeap::heapifyUp(int child_idx) {
    int parent_idx = parent(child_idx);
    
    if(!child_idx || heap[parent_idx] > heap[child_idx]) 
        return;

    std::swap(heap[parent_idx], heap[child_idx]);
    heapifyUp(parent_idx);
}

void MaxHeap::push(int value) {
    assert(!isFull());
    heap[size++] = value;
    heapifyUp(size-1);
}

void MaxHeap::heapifyDown(int parent_idx) {
    int left_child_idx = left_child(parent_idx);
    int right_child_idx = right_child(parent_idx);
    int largest_idx = parent_idx;

    if (left_child_idx != -1 && heap[left_child_idx] > heap[largest_idx])
        largest_idx = left_child_idx;
        
    if (right_child_idx != -1 && heap[right_child_idx] > heap[largest_idx])
        largest_idx = right_child_idx;

    if (largest_idx != parent_idx) {
        std::swap(heap[parent_idx], heap[largest_idx]);
        heapifyDown(largest_idx);
    }
}

int MaxHeap::pop() {
    assert(!isEmpty());
    int value = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return value;
}

bool MaxHeap::isEmpty() { return size == 0; }
bool MaxHeap::isFull() { return size == capacity; }

MaxHeap::~MaxHeap() { 
    delete[] heap; 
    heap = nullptr; 
}