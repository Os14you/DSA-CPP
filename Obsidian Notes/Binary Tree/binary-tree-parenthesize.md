```cpp
std::string paranthesize(TreeNode* root) {
	if(!root) return "()";
	
	std::string res="(";
	res += std::to_string(root->data);

	res += paranthesize(root->left );
	res += paranthesize(root->right);

	res += ")";
	return res;
}
```