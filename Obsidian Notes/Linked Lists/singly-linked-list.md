It’s a sequence of [[node-DS|nodes]] that each one is linked to the next one and holds a data inside it. The first node is called a HEAD and the last node is called a TAIL.

```cpp
struct Node {...}

class LinkedList {
	private:
		Node* head { };
		Node* tail { };
		int length { };
	public:
		~LinkedList() {
			for(Node* current = head; current; ) {
				Node* nextNode = current->next
				delete current; 
				current = nextNode;
			}
			head = nullptr;
			tail = nullptr; 
			length = 0;
		}
}
```

> [[singly-linked-list-implement|Implementation]], [[singly-linked-list-problems|Problems]]


