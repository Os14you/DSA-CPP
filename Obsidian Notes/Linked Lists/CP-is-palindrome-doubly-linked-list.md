#doublyLinkedList #problemsolving 

- A palindrome number is read the same backward as forward (1221, 131, 0)
- Implement: `{cpp}bool is_palindrome()`
- It returns true if the current linked list is palindrome
- $\{1, 2, 2, 1\}$ ⇒ `{cpp}true` 

```cpp title:solution folded:true
bool is_palindrome(){
	if(!head || !head->next) return true;
	
	int cnt { };
	for(Node* froward = head, *backward = tail; cnt < length/2; froward=froward->next, backward=backward->prev) {
		if(froward->data != backward->data) return false;
		cnt++;
	}
	
	return true;
}
```
