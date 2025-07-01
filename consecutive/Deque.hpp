#ifndef DEQUE_HPP
#define DEQUE_HPP

class Deque {
    private:
        int* arr { };
        int capacity { };
        int rear { };
        int front { };
        int num_elements { };
        int next(int idx);
        int prev(int idx);

    public:
        Deque(int capacity);
        bool isEmpty();
        bool isFull();
        void enqueue_front(int value);
        void enqueue_rear(int value);
        int dequeue_front();
        int dequeue_rear();
        void display();
        ~Deque();
};

#endif /* DEQUE_HPP */