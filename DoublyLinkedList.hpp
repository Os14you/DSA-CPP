#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node() : Node(0) { }
    Node(int data) : data(data), next(nullptr), prev(nullptr) { }
};

class DoublyLinkedList {
    private:
        int length { };
        Node* head, *tail;
        void link(Node* first, Node* second);
        void delete_node(Node* node);
        Node* delete_and_link(Node* middle);

    public:
        DoublyLinkedList();
        DoublyLinkedList(Node* head);
        int size();
        void insert_front(int value);
        void insert_end(int value);
        void insert_sorted(int value);
        void embed_after(Node* node, int value);
        void print();
        void print_reversed();
        void delete_front();
        void delete_end();
        void delete_with_key(int value);
        void delete_all_with_key(int value);
        void delete_even_positions();
        void delete_odd_positions();
        bool is_palindrome();
        ~DoublyLinkedList();
};



#endif /* DOUBLYLINKEDLIST_HPP */