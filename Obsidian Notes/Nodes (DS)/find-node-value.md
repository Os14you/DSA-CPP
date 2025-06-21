```cpp
Node* findNode(Node* head, int value) {
	for(;head; head=head->next) {
		if(head->data == value) return head;
	}
	return nullptr;
}
```