Given node $x$, find node $y$ that is the smallest $y > x$ in O(h)
- In-order: $1, 6, 8, 9, 10, 14, 15, 20$, but O(n)

![[04 - Learning/Data Structure/Binary Search Tree/BST-successor.excalidraw|800]]  

```cpp
bool BinarySearchTree::find_chain(TreeNode* root, int value, std::vector<TreeNode*> &ancestors) {
	ancestors.push_back(root);

	if(value == root->data) return true;
	if(value > root->data) return find_chain(root->left, value, ancestors);
	return find_chain(root->right, value, ancestors);
}

TreeNode* BinarySearchTree::get_next(std::vector<TreeNode*> &ancestors) {
	if(!(int) ancestors.size())
		return nullptr;

	TreeNode* node = ancestors.back();
	ancestors.pop_back();
	return node;
}

pair<bool, int> BinarySearchTree::successor(TreeNode* root, int value) {
	std::vector<TreeNode* ancestors;
	if(!find_chain(root, value, ancestors))
		return {false, -1};

	TreeNode* child = get_next(ancestors);
	if(child->right)
		return {true, min(root->right)};

	TreeNode* perant = get_next(ancestors);
	while(perant && perant->right == child)
		child = perant, perant = get_next(ancestors);

	if(perant)
		return {true, perant->data};
	return {false, -1};
}
```