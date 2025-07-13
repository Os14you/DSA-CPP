- The predecessor is simply the opposite of the successor!
	- Find node $y$ that is the largest $y < x$
- If the in-order traversal is $10, 20, 30, 40, 50$
	- Node 30's successor is $40$ (immediately after)
	- Node 30's predecessor is $20$ (directly before)

![[BST-predecessor.excalidraw|800]] 
```cpp
pair<bool, int> BinarySearchTree::predecessor(int value) {
	std::vector<TreeNode*> ancestors;
	
	if(!find_chain(root, value, ancestors))
		return {false, -1};

	TreeNode* child = get_next(ancestors);
	if(child->left)
		return {true, _max(root->left)};

	TreeNode* perant = get_next(ancestors);
	while(perant && perant->left == child)
		child = perant, perant = get_next(ancestors);

	if(perant) 
		return {true, perant->data};
	return {false, -1};
}
```