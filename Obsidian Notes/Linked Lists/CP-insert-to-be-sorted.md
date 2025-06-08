#singlyLinkedList #problemsolving 

- Implement: `{cpp}void insert_sorted(int value)`
- It will always insert the value in position so that list is sorted
- Let’s insert values: $10, 2, 30, 4, 1$
	- `{cpp}insert(10) ⇒ {10}`
	- `{cpp}insert(2) ⇒ {2, 10}`
	- `{cpp}insert(30) ⇒ {2, 10, 30}`
	- `{cpp}insert(4) ⇒ {2, 4, 10, 30}`
	- `{cpp}insert(1) ⇒ {1, 2, 4, 10, 30}`

```cpp title:solution folded:true
void insert_sorted(int value) {
	if(!head) {
		insert_front(value);
		return;
	}
	
	Node* new_node = new Node(value);
	Node* previous = nullptr, *current = head;
	
	while(current && current->data < value) {
		previous = current;
		current = current->next;
	}
	
	if(!current) {
		tail->next = new_node;
		tail = new_node;
	} else if(!previous) {
		head = new_node;
		new_node->next = current;
	} else {
		previous->next = new_node;
		new_node->next = current;
	}
	
	++length;
}
```
