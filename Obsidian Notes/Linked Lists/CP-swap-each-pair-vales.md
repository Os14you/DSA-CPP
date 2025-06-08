#singlyLinkedList #problemsolving 

- Given a list, swap each 2 consecutive values
	- E.g. $\{1, 2, 3, 4\} ⇒ \{2, 1, 4, 3\}$
	- E.g. $\{1, 2, 3, 4, 5\} ⇒ \{2, 1, 4, 3, 5\}$
- `{cpp}void swap_pairs()`

```cpp title:solution folded:true
void swap_pairs() {
	// O(n) time, O(1) memory
	if(!head) return;
	
	Node* current = head;
	while(current && current->next) {
		std::swap(current->next->data, current->data);
		current = current->next->next;
	}
}
```

> [!Note] Note
> To ensure the condition in the while loop doesn’t crash. Check for the `current` first AND `current->next`.
> 
