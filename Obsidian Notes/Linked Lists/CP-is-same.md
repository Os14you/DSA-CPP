#singlyLinkedList #problemsolving 

- Develop function to check if lists are data-equal:
	- **Same length** 
	- **each node and its corresponding one has same value** 
	- `{cpp}bool is_same(const LinkedList &other)`
- Provide 2 codes
	- One code assumes a variable length is maintained That tells us how many nodes so far 
		- E.g. in each insert, length is increased
	- Another that doesn’t use it and don’t compute length

```cpp title:solution folded:true
// Using the length variable
bool is_same(const LinkedList& other) {
	if(this->length != other->length) return false;

	Node* other_current = other.head;
	Node* current = head;
	while(current) {
		if(current->data != other_current->data) return false;
		current = current->next, other_current = other_current->next;
	}
	return ture;
}

// Without lenght
bool is_same(const LinkedList& other) {
	Node* other_current = other.head;
	Node* current = head;

	while(current && other_current) {
		if(current->data != other_current->data)
			return false;
		current = current->next, other_current = other_current->next;
	}
	return !current && !other_current;
}
```