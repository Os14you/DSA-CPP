#singlyLinkedList #problemsolving 

- Given a list, delete the first node with the given key value
	- E.g. $\{1, 2, 3, 4, 2, 6\}, (\text{key} = 2) ⇒ \{1, 3, 4, 2, 6\}$
- `{cpp}void delete_node_with_key(int value)`

```cpp title:solution folded:true
void delete_node_with_key(int value) {
	// O(n^2)
	int cnt { };
	
	for(Node* current=head; current; current=current->next, cnt++) {
		if(current->data == value) {
			delete_nth(cnt+1);
			return;
		}
	}
	std::cout << "Not such a key ..." << std::endl;
}

void delete_node_with_key(int value) {
	// O(n) time, O(1) memory
	
	for(Node* current=head, *previous=nullptr; current; previous = current, current=current->next) {
		if(current->data == value) {
			delete_next(previous);
			return;
		}
	}
	std::cout << "Not such a key ..." << std::endl;
}
```