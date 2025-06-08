#singlyLinkedList #problemsolving 

- Given a list, we would like swap the head node with the tail now
	- **NODES swap** (addresses) not just values swap
	- See the before and after before. Observe the addresses
- Tip: Draw step by step your procedure. This will save a lot of your time
- Make sure to print after the swap: once the values and also the addresses

```cpp title:solution folded:true
void LinkedList::swap_head_tail() {
    if(!head || !head->next) return;

    Node* previous = get_back(2);
    previous->next = head;
    tail->next = head->next;
    head->next = nullptr;

    std::swap(head, tail);
}
```



