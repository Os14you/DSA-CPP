#include "SpareArray.hpp"

SpareArray::SpareArray(): SpareArray(10) {}
SpareArray::SpareArray(const int size): head(nullptr), tail(nullptr), length(0), capacity(size) {}

bool SpareArray::isEmpty() const { return length == 0; }

bool SpareArray::isFull() const { return length == capacity; }

bool SpareArray::isOccupied(int idx) {
    // O(1) time, O(1) memory
    return indices.find(idx) != indices.end();
}

void SpareArray::insert(Node* before, Node* node) {
    // O(1) time, O(1) memory
    node->next = before->next;
    before->next = node;

    ++length, indices.insert(node->idx); 
}

void SpareArray::insert_front(int idx, int val) {
    // O(1) time, O(1) memory
    Node* node = new Node(idx, val);
    node->next = head;
    if(!head) 
        tail = node;
    head = node;
    ++length, indices.insert(idx);
}

void SpareArray::insert_end(int idx, int val) {
    // O(1) time, O(1) memory
    Node* node = new Node(idx, val);
    tail->next = node;
    tail = node;
    ++length, indices.insert(idx);
}

void SpareArray::set_value(int idx, int val) {
    // O(n) time, O(1) memory
    if(!head) {
        insert_front(idx, val);
        return;
    }

    if(isOccupied(idx)) {
        Node* current = head;
        while(current->idx != idx) 
            current = current->next;
        
        current->val = val;
        return;
    }
    
    Node* cur = head, *prev = nullptr;

    while(cur && cur->idx < idx) {
        prev = cur;
        cur = cur->next;
    }

    if(!cur) 
        insert_end(idx, val);
    else if(!prev)
        insert_front(idx, val);
    else 
        insert(prev, new Node(idx, val));
}

int SpareArray::get_value(int idx) const {
    // O(n) time, O(1) memory
    Node* current = head;
    while(current && current->idx != idx)
        current = current->next;
    
    return current ? current->val : 0;
}

void SpareArray::add(SpareArray& other) {
    // O(n) time, O(1) memory
    Node* cur1 = head, *cur2 = other.head;
    while(cur1 && cur2) {
        if(cur1->idx == cur2->idx) {
            cur1->val += cur2->val;
            cur2 = cur2->next;
        }
        else if(cur1->idx < cur2->idx) 
            cur1 = cur1->next;
        else {
            insert(cur1, new Node(cur2->idx, cur2->val));
            cur2 = cur2->next;
        }
    }
    while(cur2) {
        insert_end(cur2->idx, cur2->val);
        cur2 = cur2->next;
    }
}

void SpareArray::print() {
    // O(n) time, O(1) memory
    std::cout << "Printing..." << std::endl;
    std::cout << "~> ";
    
    Node* current = head;
    for(int i=0; i<capacity; ++i) {
        if(!current || i != current->idx)
            std::cout << "0";
        else {
            std::cout << current->val;
            current = current->next;
        }
        std::cout << " | ";
    }
    std::cout << std::endl;
}

void SpareArray::print_zeros() {
    // O(n) time, O(1) memory
    std::cout << "Printing..." << std::endl;
    std::cout << "~> ";
    for(int i=0; i<capacity; ++i)
        std::cout << "0 | ";
    std::cout << std::endl;
}

void SpareArray::print_nonzero() {
    // O(n) time, O(1) memory
    std::cout << "Printing..." << std::endl;
    std::cout << "~> ";
    for(Node* current = head; current; current=current->next) {
        std::cout << "(" << current->idx << ": " << current->val << ")";
        std::cout << " ";
    }
    std::cout << std::endl;
}

void SpareArray::print_with_indices() {
    // O(n) time, O(1) memory
    std::cout << "Printing..." << std::endl;
    std::cout << "~> ";
    Node* current = head;
    for(int i=0; i<capacity; ++i) {
        if(!current || i != current->idx)
            std::cout << "(" << i << ": 0)";
        else {
            std::cout << "(" << i << ": " << current->val << ")";
            current = current->next;
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}

SpareArray::~SpareArray() {
    // O(n) time, O(1) memory
    for(Node* current = head; current; current = nullptr, current = head) {
        head = head->next;
        delete current;
    }

    head = tail = nullptr;
    // std::cout << "List destroyed successfully" << std::endl;
}