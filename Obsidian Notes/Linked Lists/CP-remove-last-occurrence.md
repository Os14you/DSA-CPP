#singlyLinkedList #problemsolving 

- Given list of numbers (not sorted), and a key: remove the last occurrence for this key
- **1**, 2, 3 - key = $1 ⇒ 2, 3$
- 1, 2, 3, 4, **1** - key = $1 ⇒ 1, 2, 3, 4$
- 1, 2, 3, **1**, 4 - key = $1 ⇒ 1, 2, 3, 4$
- 1, 2, 3, 4 - key = $7 ⇒ 1, 2, 3, 4$

```cpp title:solution folded:true
void LinkedList::remove_last_occurrence(int k) {
    if(!head) return;
    if(!head->next && head->data != k) return;

    Node* lastOcc = new Node(), *prevForOcc = nullptr;
    for(Node* current = head; current; current = current->next) {
        if(current->next && current->next->data == k) prevForOcc = current;
        if(current->data == k) lastOcc = current;
    }

    if(lastOcc == head) delete_head();
    else if(prevForOcc) delete_next(prevForOcc);
}
```

