#ifndef ARRAYBASEDSTACK_HPP
#define ARRAYBASEDSTACK_HPP

class Stack {
    private:
        int *arr { };
        int top { };
        int size { };

    public:
        Stack();
        Stack(int size);
        int peek();
        bool isEmpty();
        bool isFull();
        void display();
        void push(int value);
        int pop();
        ~Stack();
};

#endif /* ARRAYBASEDSTACK_HPP */