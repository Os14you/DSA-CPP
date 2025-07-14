#problemsolving #binaryTree 

- Given the root of a binary tree, return its maximum depth.
- A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
- Below depth is $3$ like path $(3) - (20) - (7)$  

```cpp title:solution folded:true
int maxDepth(TreeNode* root) {
	if(!root) return 0;

	int l = maxDepth(root->left);
	int r = maxDepth(root->right);
	return std::max(r, l) + 1;
}
```