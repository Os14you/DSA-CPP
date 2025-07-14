#recursion #problemsolving #binaryTree 

- Given the `root` of a binary tree, return _the sum of all left leaves._
- A **leaf** is a node with no children. A **left leaf** is a leaf that is the left child of another node.

![[sum-of-left-leaves.excalidraw|800]]

```cpp title:solution folded:true
bool isLeaf(TreeNode* node) {
	return node && !node->right && !node->left;
}
int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
	int sum { };

	if(!root) return 0;

	if(isLeft && isLeaf(root)) return root->val;

	sum += sumOfLeftLeaves(root->right, false);
	sum += sumOfLeftLeaves(root->left, true);

	return sum;
}
```