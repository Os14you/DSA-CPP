```cpp
void clear(TreeNode* node) {
	if(!node) return;
	
	clear(node->right);
	clear(node->left);

	delete node;
}
```