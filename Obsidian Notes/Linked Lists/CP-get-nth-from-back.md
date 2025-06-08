#singlyLinkedList #problemsolving 

- We already implemented `{cpp}Node* get_nth(int n)`
- Now implement: `{cpp}Node* get_nth_back(int n)`
- Given 1-based position, find it from the back
	- E..g. if list is $1 \rightarrow 2 \rightarrow 3 \rightarrow 4 \rightarrow 5 \rightarrow 6$ 
	- `{cpp}get_nth_back(1)` should point to node with value $6$

```cpp title:solution folded:true
Node* get_nth_back(int idx) {
	int cnt = length;
	for(Node* current = head; current; current = current->next, --cnt) {
		if(cnt == idx) {
			return current;
		}
	}
	return nullptr;
}
```
