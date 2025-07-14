We have two approaches, the first one is composition and the second is only use the tree class in implementation.

```cpp title:composition
struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data): data(data), left(nullptr), right(nullptr) { }
};

class BinaryTree {
private:
	TreeNode* root;
public:
	BinaryTree(int root_val): root(new TreeNode(root_val)) { }
	void _printInOrder(TreeNode* current) {
		if(!current) return;

		_printInOrder(current->left);
		std::cout<<current->data<<" ";
		_printInOrder(current->right);
	}
	void printInOrder() {
		_printInOrder(root);
		std::cout<<"\n";
	}
};
```

```cpp title:"One Big Class"
class BinaryTree {
private:
	int data { };
	BinaryTree* left { };
	BinaryTree* right { };
	
public:
	void printInOrder() {
		if(left) left->printInOrder();
		std::cout<< data << " ";
		if(right) right->printInOrder();
	}
};
```

> [[binary-tree-construction|Construction]], [[tree-level-traversal|Level Traversal]], [[binary-tree-serialization|Serialization]] 