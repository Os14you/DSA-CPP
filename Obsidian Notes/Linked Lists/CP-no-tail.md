
#singlyLinkedList #problemsolving 

- Assume we will implement our linked list to only have head but no tail
- Implement and test these 3 methods:
	- Add element just add element to our current collection of numbers
		- O(1)
		- Tip: data will be reversed
	- Get tail get the last node
	- Print function

```cpp title:"solution of get_tail()" folded:true
Node* get_tail() {
	for(Node* current=head; current; current=current->next) {
		if(!current->next) return current;
	}
	return nullptr;
}
```

```cpp title:"solution of print()" folded:true
void print() {
	for(Node* current=head; current; current=current->next) {
		std::cout << current->data;
		if(!current->next) std::cout << " -> ";
	}
}
```

```cpp title:"solution of add_element()" folded:true
void add_element(int value) {
	Node* new_node = new Node(value);
	new_node->next = head;
	head = new_node;
}
```