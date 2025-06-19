#include "LinkedList.hpp"
#include <iostream>
#include <climits>


LinkedList::LinkedList(): head(nullptr), tail(nullptr), length(0) {}
LinkedList::~LinkedList() {
    // O(n) time, O(1) memory
    for(Node* current = head; current; current = nullptr, current = head) {
        head = head->next;
        delete current;
    }

    head = tail = nullptr;
    std::cout << "List destroyed successfully" << std::endl;
}

int LinkedList::size() { return length; }

bool LinkedList::isEmpty() { return !length; }

void LinkedList::delete_node(Node* node) {
    delete node;
    --length;
    node = nullptr;
}

void LinkedList::delete_head() {
    // O(1) time, O(1) memory
    if(head) {
        Node* current = head;
        head = head->next;
        delete_node(current);
    }

    if(!head) tail = nullptr;
}

void LinkedList::delete_tail() {
    // O(n) time, O(1) memory
    if(length == 1) {
        delete_head();
        return;
    }

    Node* previous = get(length - 1); // O(n), O(1)
    delete_node(previous->next);
    tail = previous;
    tail->next = nullptr;

    if(!tail) head = nullptr;
}

void LinkedList::delete_nth(int idx) {
    // O(n) time, O(1) memory

    if(1 >= idx || idx >= length) {
        if(idx == 1) delete_head(); // O(n), O(1)
        else if(idx == length) delete_tail(); // O(n), O(1)
        else std::cout << "Error, not such an index." << std::endl;
        return;
    }

    Node* previous = get(idx - 1); // O(n), O(1)
    Node* current = previous->next;
    previous->next = previous->next->next;
    delete_node(current);
}

void LinkedList::delete_with_key(int value) {

	for(Node* current=head, *previous=nullptr; current; previous = current, current=current->next) {
		if(current->data == value) {
			delete_next(previous);
			return;
		}
	}
	std::cout << "Not such a key ..." << std::endl;
}

void LinkedList::delete_next(Node* node) {
    // O(1) time, O(1) memory
    Node* to_delete = node->next;
    bool is_tail = to_delete == tail;

    node->next = to_delete->next;
    delete_node(to_delete);

    if(is_tail) tail = node;
}

void LinkedList::insert_end(int value) {
    // O(1) time, O(1) memory

    Node* new_node = new Node(value);

    if(!head) { head = tail = new_node; }
    else {
        tail->next = new_node;
        tail = new_node;
    }
    
    ++length;
}

void LinkedList::insert_front(int value) {
    // O(1) time, O(1) memory

    Node* new_node = new Node(value);

    new_node->next = head;
    head = new_node;
    
    if(!head->next) tail = head;
     ++length;
}

void LinkedList::insert(int idx, int value) {
    // O(n) time, O(1) memory

    if(1>= idx || idx >= length) {
        if(idx == 1) insert_front(value);
        else if (idx == length) insert_end(value); 
        else std::cout << "Not such an idx." << std::endl;
        return;
    }

    Node* new_node = new Node(value), *previous = get(idx-1); // O(n), O(1)
    new_node->next = previous->next;
    previous->next = new_node;
    
    ++length;
}

void LinkedList::insert_after(Node* node, int value) {
    // O(1) time, O(1) memory
    if(node == tail) { insert_end(value); return; }

    Node* new_node = new Node(value);
    new_node->next = node->next;
    node->next = new_node;

    ++length;
}

void LinkedList::print() {
    // O(n) time, O(1) memory

    std::cout << "Printing..." << std::endl;
    std::cout << "~> ";
    for(Node* current = head; current; current=current->next) {
        std::cout << "(" << current->data << ")";
        if(current != tail) std::cout << " -> ";
    }
    std::cout << std::endl;
}

void LinkedList::print_with_address() {
    // O(n) time, O(1) memory

    std::cout << "Printing..." << std::endl;
    std::cout << "~> ";
    for(Node* current = head; current; current=current->next) {
        std::cout << "(" << current << ", " << current->data << ")";
        if(current != tail) std::cout << " -> ";
    }
    std::cout << std::endl;
}

Node* LinkedList::get(int idx) {
    // O(n) time, O(1) memory

    int cnt { };
    if(!length) return nullptr;

    for(Node* current = head; current; current=current->next) {
        if(++cnt == idx) return current;
    }
    
    return nullptr;
}

int LinkedList::search(int value) {
    // O(n) time, O(1) memory

    int idx { };
    for(Node* current = head; current; current=current->next, idx++) {
        if(current->data == value)
            return idx;
    }
    return -1;
}