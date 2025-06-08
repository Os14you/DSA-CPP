#singlyLinkedList #problemsolving 

- Given a list, delete all nodes at even positions (2, 4, 6, etc)
	- E.g. $\{1, 2, 3, 4, 10\} ⇒ \{1, 3, 10\}$
	- E.g. $\{1, 2, 3, 4, 5, 6\} ⇒ \{1, 3, 5\}$
- Note: positions **NOT** values
- `{cpp}void delete_even_positions()`

```cpp title:solution folded:true
void delete_even_positions() {
	if(length <= 1) return;
	
	for(Node* current = head->next, *previous = head; current; previous = previous->next, current = previous->next) {
		previous->next = current->next;
		delete_node(current);
		
		if(!previous->next) {
			tail = previous;
			tail->next = nullptr;
			return;
		}
	}
}
```