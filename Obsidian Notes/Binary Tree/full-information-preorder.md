```cpp
void print_full_info(TreeNode* root) {
	std::cout << root->data << " ";

	if(root->left)
		print_full_info(root->left);
	else
		std::cout << "-1 "; // indicates a null pointer

	if(root->right)
		print_full_info(root->right);
	else
		std::cout << "-1 "; // indicates a null pointer
}
```