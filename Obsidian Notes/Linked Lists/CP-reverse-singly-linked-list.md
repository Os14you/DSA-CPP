#singlyLinkedList #problemsolving 

- Given a list, reverse all its nodes (addresses)
- E.g. $\{1, 2, 3, 4, 5\} ⇒ \{5, 4, 3, 2, 1\}$
- `{cpp}void reverse()`
- Can you do it [[CP-reverse-singly-linked-list-recursive|recursively]]? 
```cpp title:"solution - data reverse" folded:true
void reverse() {
	if(length <= 1) return;
	int arr[length] { }, i { };
	
	for(Node* current=head; current; current=current->next)
		arr[i++]=current->data;

	for(Node* current=head; current; current=current->next)
		current->data=arr[--i];
}
```

```cpp title:"solution: nodes reverse" folded:true
void reverse() {
	if(!head || !head->next) return;
	
	tail = head;
	Node* previous = head;
	head = head->next;

	while(head) {
		Node* next = head->next;
		head->next = previous;

		previous = head;
		head = next;
	}

	head = previous;
	tail->next = nullptr;
}
```