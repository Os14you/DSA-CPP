#recursion #problemsolving #binaryTree 

- Given the `root` of a binary tree with unique values and the values of two different nodes of the tree `x` and `y`, return `true` _if the nodes corresponding to the values_ `x` _and_ `y` _in the tree are **cousins**, or_ `false` _otherwise._

- Two nodes of a binary tree are **cousins** if they have the same depth with different parents.

- Note that in a binary tree, the root node is at the depth `0`, and children of each depth `k` node are at the depth `k + 1`.

```cpp title:solution folded:true
TreeNode* findPerant(TreeNode* root, int value) {
	if(!root) return nullptr;

	if ((root->left && root->left->val == value) || 
		(root->right && root->right->val == value))
		return root;

	TreeNode* parentNode = findPerant(root->left, value);
	if (parentNode) {
		return parentNode;
	}
	
	parentNode = findPerant(root->right, value);
	if (parentNode) {
		return parentNode;
	}

	return nullptr; 
}

int findDepth(TreeNode* root, int value, int depth = 0) {
	if(!root) return 0;

	if(root->val == value) 
		return depth;

	return std::max(findDepth(root->left, value, depth + 1), 
			findDepth(root->right, value, depth + 1));
}

bool isCousins(TreeNode* root, int x, int y) {
	return findDepth(root, x) == findDepth(root, y) &&
			findPerant(root, x) != findPerant(root, y);
}
```