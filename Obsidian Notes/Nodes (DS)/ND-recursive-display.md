```cpp
void printNodes(Node* head) {
	if(head == nullptr)
		return;
	std::cout << head->data << " -> ";
	printNodes(head->next);
}
```