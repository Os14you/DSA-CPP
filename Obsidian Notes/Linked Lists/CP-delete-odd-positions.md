#doublyLinkedList #problemsolving 

- Given a list, delete all nodes at odd positions (1, 3, 5, etc)
	- E.g. $\{1, 2, 3, 4, 10\}$ ⇒ $\{2, 4\}$
	- E.g. $\{1, 2, 3, 4, 5, 7\}$ ⇒ $\{2, 4, 7\}$
- Note: positions **NOT** values
- `{cpp}void delete_odd_positions()`

```cpp title:solution folded:true
void DoublyLinkedList::delete_odd_positions() {
	if(!head) return;

	if(!(length%2)) delete_end();

	delete_front();

	for(Node* current = head; current->next; current=current->next)
		delete_and_link(current->next);
}
```