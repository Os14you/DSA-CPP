It’s all like a [[singly-linked-list|singly linked list]], but with one more pointer which points to the previous [[node-DS|node]] (the actual change happens in the node structure).

The new node struct will be as following:
```cpp
struct Node {
	int data;
	Node* next { };
	Node* prev { };
	
	Node() : Node(0) { }
	Node(data) : data(data) { }
};
```

- In many scenarios, we need to get the **previous** node!
- We can easily get this node in $O(n)$!
- With previous connection, we can have it in $O(1)$

> [[doubly-linked-list-implement|Implementation]], [[doubly-linked-list-problems|Problems]]

