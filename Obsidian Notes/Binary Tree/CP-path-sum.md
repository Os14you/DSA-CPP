#recursion #problemsolving #binaryTree 

Given the root of a binary tree and an integer `targetSum`, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals `targetSum`.

A leaf is a node with no children.

![[hasPathSum.excalidraw|800]]

```cpp title:solution folded:true
bool isLeaf(TreeNode* node) {
	return node && !node->left && !node->right;
}

bool hasPathSum(TreeNode* root, int targetSum) {
	if(!root) return false;

	if(targetSum == root->val && isLeaf(root)) 
		return true;

	return hasPathSum(root->left, targetSum - root->val) ||
			hasPathSum(root->right, targetSum - root->val);
}
```

