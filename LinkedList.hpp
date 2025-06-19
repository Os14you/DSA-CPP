#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct Node {
    int data;
    Node* next;

    Node(int data) : Node(data, nullptr) {}
    Node(int data, Node* next) : data(data), next(next) {}
    Node(): Node(0) {}
};

class LinkedList {
    private:
        Node* head, *tail;
        int length;
        void delete_node(Node* node);
        void delete_next(Node* node);
        void insert_after(Node* node, int value);

    public:
        LinkedList();
        bool isEmpty();
        void delete_head();
        void delete_tail();
        void delete_nth(int idx);
        void delete_with_key(int key);
        int size();
        void insert_end(int value);
        void insert_front(int value);
        void insert(int idx, int value);
        void print();
        void print_with_address();
        Node* get(int idx);
        int search(int value);
        ~LinkedList();
};

#endif