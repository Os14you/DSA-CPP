#include <iostream>
#include "LinkedListBasedQueue.hpp"


Queue::Queue() {
    ll = LinkedList();
}

bool Queue::isEmpty() {
    return ll.isEmpty();
}

bool Queue::isFull() {
    return false;
}

void Queue::enqueue(int value) {
    ll.insert_end(value);
}

int Queue::dequeue() {
    int temp = ll.get(1)->data;
    ll.delete_head();
    return temp;
}

void Queue::display() {
    ll.print();
}