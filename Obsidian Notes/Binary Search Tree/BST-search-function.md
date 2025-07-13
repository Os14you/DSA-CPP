```cpp
bool search(TreeNode* root, int value) {
	if(!root) return false;

	if(root->data == value) return true;

	if(root->data > value) 
		return search(root->left, value);
	return search(root->right, value);
}
```