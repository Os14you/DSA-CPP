#ifndef LINKEDLISTBASEDQUEUE_HPP
#define LINKEDLISTBASEDQUEUE_HPP
#include "LinkedList.hpp"

class Queue {
    private:
        LinkedList ll;
    
    public:
        Queue();
        bool isEmpty();
        bool isFull();
        void enqueue(int value);
        int dequeue();
        void display();
};


#endif