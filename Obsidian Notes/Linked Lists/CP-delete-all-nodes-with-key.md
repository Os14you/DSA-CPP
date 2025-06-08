#doublyLinkedList #problemsolving 

- Implement: `{cpp}void delete_all_nodes_with_key(int value)`
- It will delete all nodes of the given key
- $1, 2, 5, 4, 5, 4, 4$ - **key (5)** ⇒ $1, 2, 4, 4, 4$

```cpp title:solution folded:true
void delete_all_with_key(int value) {
	if(!head) return;
	
	while(head->data == value) delete_front();
	
	for(Node* current = head; current; current = current->next) {
		if(current->data == value) {
			delete_and_link(current);
			if(!current->next) tail = current;
		}
	}
}
```