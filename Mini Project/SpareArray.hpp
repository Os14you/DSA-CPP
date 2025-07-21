#ifndef SPAREARRAY_HPP
#define SPAREARRAY_HPP

#include <iostream>
#include <unordered_set>
#include <vector>

struct Node {
    int idx, val;
    Node* next;

    Node(int idx, int val) : idx(idx), val(val), next(nullptr) {}
    Node(int idx, int val, Node* next) : idx(idx), val(val), next(next) {}
    Node() : Node(0, 0) {}
};

class SpareArray {
private:
    Node* head, *tail;
    int length, capacity;
    std::unordered_set<int> indices;
    void insert(Node* before, Node* node);
    bool isOccupied(int idx);
    void insert_front(int idx, int val);
    void insert_end(int idx, int val);
    
public:
    SpareArray();
    SpareArray(int size);
    bool isEmpty() const;
    bool isFull() const;
    void set_value(int idx, int val);
    int get_value(int idx) const;
    void add(SpareArray& other);
    void print();
    void print_zeros();
    void print_nonzero();
    void print_with_indices();
    ~SpareArray();
};

#endif /* SPAREARRAY_HPP */