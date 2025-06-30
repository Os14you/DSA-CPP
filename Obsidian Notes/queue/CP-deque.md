#queue #problemsolving 

- Deque is a **Double ended queue** where you can add/remove from either rear or front. It is not FIFO anymore, but provides great flexibility
- Change the **circular queue** to include
	- `{cpp}void enqueue_rear(int value) [same old code]`
	- `{cpp}void enqueue_front(int value)`
	- `{cpp}int dequeue_front() [same old code]`
	- `{cpp}int dequeue_rear()`
- Front/Rear meanings shouldn’t change.
- $O(1)$ time complexity for all methods

```cpp title:solution folded:true
int Deque::prev(int idx) {
    --idx;
    if(idx < 0)
        idx = capacity - 1;
    
    return idx;
}

void Deque::enqueue_front(int value) {
    assert(!isFull());
    front = prev(front);
    arr[front] = value;
    ++num_elements;
}

int Deque::dequeue_rear() {
    assert(!isEmpty());
    rear = prev(rear);
    --num_elements;
    return arr[rear];
}
```