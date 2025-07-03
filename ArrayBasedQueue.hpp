#ifndef ARRAYBASEDQUEUE_HPP
#define ARRAYBASEDQUEUE_HPP

class MyQueue {
    private:
        int *arr { };
        int front { };
        int rear { };
        int capacity { };
        int num_elements { };
        int next(int idx);

    public:
        MyQueue(int capacity);
        bool isEmpty();
        bool isFull();
        void enqueue(int value);
        int dequeue();
        void display();
        ~MyQueue();
};

#endif /* ARRAYBASEDQUEUE_HPP */