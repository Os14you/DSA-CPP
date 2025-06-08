#singlyLinkedList #problemsolving 

- Given list of numbers (not sorted), for any repeated number, remove all except the first
- $1, 2, 1, 3, 2, 4, 3, 5, 2 ⇒ 1, 2, 3, 4, 5$
- $1, 2, 3, 4, 5 ⇒ 1, 2, 3, 4, 5$
- $1, 1, 1 ⇒ 1$

```cpp title:solution folded:true
void LinkedList::delete_duplicates() {
    if(!head || !head->next) return;

    int freq[1000] { };
    for(Node* cur = head; cur; ) {
        freq[cur->data]++;
        if(cur->next && freq[cur->next->data]) {
            delete_next(cur);
        }
        else 
            cur = cur->next;
    }
}
```