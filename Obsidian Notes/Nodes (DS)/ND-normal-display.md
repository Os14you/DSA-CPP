```cpp
void printNodes(Node* head) {
	while(head != nullptr) {
		std::cout << head->data << " -> ";
		head = head->next;
	}
}

void printForNodes(Node* head) {
	for(;head; head = head->next)
		std::cout << head->data << " -> ";
}
```