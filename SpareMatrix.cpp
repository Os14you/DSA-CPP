#include "SpareMatrix.hpp"

SpareMatrix::SpareMatrix(int col_capacity, int row_capacity): col_size(0), row_size(0), col_capacity(col_capacity), 
    row_capacity(row_capacity), head(nullptr) {}

bool SpareMatrix::isEmpty() const { return col_size == 0; }
bool SpareMatrix::isOccupied(int col_idx) const { return indices.find(col_idx) != indices.end(); }

void SpareMatrix::set(int col_idx, int row_idx, int value) {
    if (value == 0) return;
    if (col_idx < 0 || col_idx >= col_capacity || row_idx < 0 || row_idx >= row_capacity) {
        std::cerr << "Index out of bounds" << std::endl;
        return;
    }

    if (head == nullptr || head->idx > col_idx) {
        Arr* new_arr = new Arr(row_capacity, col_idx);
        new_arr->row.set_value(row_idx, value);
        new_arr->next = head;
        head = new_arr;
        col_size++;
        indices.insert(col_idx);
        return;
    }

    Arr* current = head;
    while (current->next != nullptr && current->next->idx < col_idx) {
        current = current->next;
    }

    if (current->next != nullptr && current->next->idx == col_idx)
        current->next->row.set_value(row_idx, value);

    else if (current->idx == col_idx)
        current->row.set_value(row_idx, value);

    else {
        Arr* new_arr = new Arr(row_capacity, col_idx);
        new_arr->row.set_value(row_idx, value);
        new_arr->next = current->next;
        current->next = new_arr;
        col_size++;
        indices.insert(col_idx);
    }
}

int SpareMatrix::get(int col_idx, int row_idx) const {
    Arr* current = head;
    while (current != nullptr && current->idx != col_idx)
        current = current->next;

    if (current == nullptr) 
        return -1;
    return current->row.get_value(row_idx);
}

void SpareMatrix::print_zeros() {
    for(int i = 0; i < col_capacity; i++)
        std::cout << "0 | ";
    std::cout << std::endl;
}

void SpareMatrix::print() {
    Arr* current_row_node = head;
    for (int i = 0; i < col_capacity; ++i) {
        if (current_row_node != nullptr && current_row_node->idx == i) {
            current_row_node->row.print();
            current_row_node = current_row_node->next;
        } else
            print_zeros();
    }
}

void SpareMatrix::print_nonzero() {
    for(Arr* current = head; current; current=current->next)
        current->row.print_nonzero();
}

void SpareMatrix::print_with_indices() {
    for(Arr* current = head; current; current=current->next)
        current->row.print_with_indices();
}

SpareMatrix::~SpareMatrix() {
    Arr* current = head;
    while (current != nullptr) {
        Arr* to_delete = current;
        current = current->next;
        delete to_delete;
    }
}