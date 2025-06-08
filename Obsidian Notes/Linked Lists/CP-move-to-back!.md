#singlyLinkedList #problemsolving 

- Given list of numbers (not sorted), and a key: move all the occurrence for this key to the end of the list
- $1, 2, 3, 2, 4, 1$ - key = 1 ⇒ $2, 3, 2, 4, 1, 1$
- $1, 2, 3, 1, 2, 4, 1, 7, 1, 8, 1, 1$ - key = 1 ⇒ $2, 3, 2, 4, 7, 8, 1, 1, 1, 1, 1, 1$

```cpp title:solution folded:true
void move_next_to_back(Node* prev) {
    if(!prev) return;

    tail->next = prev->next;
    prev->next = prev->next->next;
    tail = tail->next;
    tail->next = nullptr;
}

void move_to_back(int k) {
    if(!head || !head->next) return;

    Node* initTail = tail;

    while(head->data == k && head != initTail ) 
        head_to_tail();

    for(Node* current = head; current; current = current->next) {
        if(current->next && current->next->data == k) move_next_to_back(current);
    }
}
```