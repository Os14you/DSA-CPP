#recursion #problemsolving #binaryTree 

- `{c}bool is_perfect()`, It returns `{cpp}true` if the tree is perfect
- Develop it in 2 ways
	- Recursive way
	- A formula-based way
- Make sure to do proper testing

```cpp title:"my solution" folded:true
bool BinaryTree::_isPerfect(TreeNode* node, int height) {
    if(!node->left && !node->right) 
        return height == 0;
    
    if((!node->right && node->left) || 
		    (node->right && !node->left))
        return false;
    
    return _isPerfect(node->left, height-1) &&
			    _isPerfect(node->right, height-1);
}

bool BinaryTree::is_perfect() {
    return _isPerfect(root, max_depth() - 1);
}
```

```cpp title:"other good solution" folded:true
pair<bool,int> isPerfect(TreeNode* root) {
	if(!root) 
		return {false, 0};

	if(!root->right && !root->left) 
		return {true, 1};

	auto left = isPerfect(root->left);
	auto right = isPerfect(root->right);

	bool is_perfect = left.first && right.first 
						&& (left.second == right.second);
	
	return {is_perfect, 1 + left.second + right.second};
}
```