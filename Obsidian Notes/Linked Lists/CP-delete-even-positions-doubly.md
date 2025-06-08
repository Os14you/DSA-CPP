#doublyLinkedList #problemsolving 

- Given a list, delete all nodes at even positions (2, 4, 6, etc)
	- E.g. $\{1, 2, 3, 4, 10\}$ ⇒ $\{1, 3, 10\}$
	- E.g. $\{1, 2, 3, 4, 5, 6\}$ ⇒ $\{1, 3, 5\}$
- Note: positions **NOT** values
- `{cpp}void delete_even_positions()`

```cpp title:solution folded:true
void delete_even_positions() {
    if(!head || !head->next) return;
    
    if(length%2) delete_end();
    
    for(Node* current = head; current->next; current = current->next) {
        delete_and_link(current->next);
    }
}
```