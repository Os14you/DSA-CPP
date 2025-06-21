```cpp
void printNodes(Node* head) {
	if(head == nullptr) return;

	printNodes(head->next);
	std::cout << head->data << " -> ";
}
```