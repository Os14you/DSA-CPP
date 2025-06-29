#ifndef LINKEDLISTBASEDSTACK_HPP
#define LINKEDLISTBASEDSTACK_HPP

template <class dataType>
struct Node {
    dataType data;
    Node* next;
    Node(dataType data, Node* next) : data(data), next(next) {}
    Node(dataType data) : Node(data, nullptr) {}
    Node() : Node(0) {}
};

template <class dataType>
class Stack {
    private:
        Node<dataType>* top;

    public:
        Stack();
        dataType peek();
        bool isEmpty();
        void display();
        void push(dataType value);
        dataType pop();
        ~Stack();
};

#endif /* LINKEDLISTBASEDSTACK_HPP */