#recursion #singlyLinkedList #problemsolving 

```cpp title:solution folded:true
Node* reverse(Node* head) {
	if(!head || !head->next) return head;

	Node* new_head = reverse(head->next);
	head->next->next = head;
	head->next = nullptr;
	return new_head; 
}
```