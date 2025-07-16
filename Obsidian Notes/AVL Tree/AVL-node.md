```cpp
struct Node {
	int data;
	// adding height to keep tracking balance state
	int height;
	Node* right;
	Node* left;

	Node(int data): data(data), left(nullptr), 
			right(nullptr), height(0) { }
	Node(): Node(0) { }

	int child_height(Node* child) {
		return child ? child->height : -1;
	}
	int update_height() {
		return height = 1 + std::max(child_height(left), 
									child_height(right));
	}
	int balance_factor() {
		return child_height(left) - child_height(right);
	}
};
```