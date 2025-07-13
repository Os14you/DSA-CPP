- We want to delete a specific value
	- The tree must remain a BST after deletion
- We have 3 cases:
	- 0 children ⇒ Direct
		- If our node is a leaf node, just remove it.
	- 1 child  ⇒ Almost Direct
		- We can connect the parent to the lone child.
	- 2 children ⇒ A bit tricky
		- Use the successor of the node.

```cpp
TreeNode* BinarySearchTree::_delete_node(TreeNode* node, int value) {
    if(!node) return nullptr;

    if(node->data > value)
        node->left = _delete_node(node->left, value);
    else if(node->data < value)
        node->right = _delete_node(node->right, value);
    else {
        if(!node->right) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        } else if (!node->left){
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else {
            TreeNode* mn = min_node(node->right);
            node->data = mn->data;
            node->right = 
	            _delete_node(node->right, node->data);
        }
    }

    return node;
}
```