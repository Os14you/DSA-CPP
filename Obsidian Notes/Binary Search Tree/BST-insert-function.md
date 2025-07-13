```cpp
TreeNode* insert(TreeNode* root, int value) {
	if(!root) return new TreeNode(value);
	
	if(root->data > value)
		root->left = insert(root->left, value);
	else if(root->data < value)
		root->right = insert(root->right, value);
	else return nullptr;

	return root;
}
```

```cpp
void insert(TreeNode* root, int value) {
	if(!root) {
		root = new TreeNode(value);
		return;
	}

	if(root->data > value) {
		if(!root->left) 
			root->left = new TreeNode(value);
		else insert(root->left, value);
		
	} else if(root->data < value) {
		if(!root->right) 
			root->right = new TreeNode(value);
		else insert(root->right, value);
	}
}
```