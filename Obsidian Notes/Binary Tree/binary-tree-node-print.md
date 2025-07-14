```cpp
void print(TreeNode* node) {
	if(!node) return;

	print(node->right);
	cout << "<-" << node->data << "->";
	print(node->left);
}
```

### Extended
---
```cpp
void print(TreeNode* node, std::string prefix, bool isRight) {
	if (!node) return;
        
    std::cout << prefix;
    std::cout << (isRight ? "├── " : "└── ");
    std::cout << "(" << node->data << ")" << std::endl;
    
    if (node->left || node->right) {
        if (node->right) {
            print(node->right, prefix + (isRight ? "│   " : "    "), true);
        }
        if (node->left) {
            print(node->left, prefix + (isRight ? "│   " : "    "), false);
        }
    }
}
```