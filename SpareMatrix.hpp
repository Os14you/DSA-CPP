#ifndef SPAREMATRIX_HPP
#define SPAREMATRIX_HPP

#include "SpareArray.hpp"
#include <vector>

struct Arr {
    SpareArray row;
    Arr *next;
    int idx;
    Arr(int size, int idx) : row(SpareArray(size)), idx(idx), next(nullptr) {}
};

class SpareMatrix {
private:
    int col_size, row_size;
    int col_capacity, row_capacity;
    Arr *head;
    std::unordered_set<int> indices;
    void print_zeros();
    bool isEmpty() const;
    bool isOccupied(int col_idxx) const;

public:
    SpareMatrix(int col_capacity, int row_capacity);
    void set(int col_idx, int row_idx, int value);
    int get(int col_idx, int row_idx) const;
    void print();
    void print_nonzero();
    void print_with_indices();
    ~SpareMatrix();
};

#endif /* SPAREMATRIX_HPP */