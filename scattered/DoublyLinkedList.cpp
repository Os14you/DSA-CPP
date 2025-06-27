#include "DoublyLinkedList.hpp"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() : DoublyLinkedList(nullptr) { }
DoublyLinkedList::DoublyLinkedList(Node* head) : head(head), tail(head) { ++length; }

int DoublyLinkedList::size() { return length; }

void DoublyLinkedList::link(Node* first, Node* second) {
    if(first)  first->next = second;
    if(second) second->prev = first;
}

void DoublyLinkedList::delete_node(Node* node) {
    delete node;
    node = nullptr;
    --length;
}

Node* DoublyLinkedList::delete_and_link(Node* middle) {
    Node* previous = middle->prev;
    link(middle->prev, middle->next);
    delete_node(middle);
    return previous;
}

void DoublyLinkedList::insert_end(int value) {
    if(!tail) { head = tail = new Node(value), ++length; return; }

    Node* new_node = new Node(value);
    link(tail, new_node);
    tail = new_node;
    
    ++length;
}

void DoublyLinkedList::insert_front(int value) {
    if(!head) { head = tail = new Node(value), ++length; return; }

    Node* new_node = new Node(value);
    link(new_node, head);
    head = new_node;
    
    ++length;
}

void DoublyLinkedList::insert_sorted(int value) {
    if(!head || head->data >= value) insert_front(value);
    else if (tail->data  <= value) insert_end(value);
    else {
        for(Node* current = head; current; current = current->next) {
            if(current->data > value) {
                embed_after(current->prev, value);
                break;
            }
        }   
    }
}

void DoublyLinkedList::embed_after(Node* node_before, int value) {
    // O(1) time, O(1) memory

    Node* middle = new Node(value);
    Node* node_after = node_before->next;

    link(node_before, middle);
    link(middle, node_after);
    ++length;
}


void DoublyLinkedList::print() {

    std::cout << "Printing..." << std::endl;
    std::cout << "~> ";

    for(Node* current = head; current; current = current->next) {
        std::cout << "(" << current->data << ")";
        if(current != tail) std::cout << " -> ";
    }

    std::cout << std::endl;
}

void DoublyLinkedList::print_reversed() {
    std::cout << "Printing in reversed order..." << std::endl;
    std::cout << "~> ";

    for(Node* current = tail; current; current = current->prev) {
        std::cout << "(" << current->data << ")";
        if(current != head) std::cout << " -> ";
    }

    std::cout << std::endl;
}

void DoublyLinkedList::delete_front() {
    if(!head) return;
    
    Node* current = head->next;
    delete_and_link(head);
    head = current;

    if(head) head->prev = nullptr;
    else if(!length) head = tail = nullptr;
}

void DoublyLinkedList::delete_end() {
    if(!tail) return;

    Node* current = tail->prev;
    delete_and_link(tail);
    tail = current;

    if(tail) tail->next = nullptr;
    else if(!length) head = tail = nullptr;
}

void DoublyLinkedList::delete_with_key(int value) {
    if(!head) return;

    if(head->data == value) delete_front();
    else {
        for(Node* current = head; current; current = current->next) {
            if(current->data == value) {
                current = delete_and_link(current);
                if(!current->next) tail = current;
                break;
            }
        }
    }
}

void DoublyLinkedList::delete_all_with_key(int value) {
    if(!head) return;

    while(head->data == value) delete_front();

    for(Node* current = head; current; current = current->next) {
        if(current->data == value) {
            delete_and_link(current);
            if(!current->next) tail = current;
        }
    }
}

void DoublyLinkedList::delete_even_positions() {
    if(!head || !head->next) return;

    if(length%2) delete_end();

    for(Node* current = head; current->next; current = current->next) {
        delete_and_link(current->next);
    }
}

void DoublyLinkedList::delete_odd_positions() {
    if(!head) return;

    if(!(length%2)) delete_end();

    delete_front();

    for(Node* current = head; current->next; current=current->next)
        delete_and_link(current->next);
}

bool DoublyLinkedList::is_palindrome(){
    if(!head || !head->next) return true;

    int cnt { };
    for(Node* froward = head, *backward = tail; cnt < length/2; froward=froward->next, backward=backward->prev) {
        if(froward->data != backward->data) return false;
        cnt++;
    }

    return true;
}

DoublyLinkedList::~DoublyLinkedList() {
    // O(n) time, O(1) memory
    for(Node* current = head; current; current = nullptr, current = head) {
        head = head->next;
        delete current;
    }

    head = tail = nullptr;
    std::cout << "List destroyed successfully" << std::endl;
}