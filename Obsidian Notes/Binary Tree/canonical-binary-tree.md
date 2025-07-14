If you have several arrays: how can you check if they have the same values?
-> [[binary-tree-parenthesize|Parenthesize]] and sort each array and compare them.

```cpp
std::string canonical(TreeNode* root) {
	if(!root) return "()";
	std::string res = "(" + std::to_string(root->data);

	std::vector<std::string> vec;
	
	vec.push_back(canonical(root->left ));
	vec.push_back(canonical(root->right));

	std::sort(vec.begin(), vec.end());
	for(auto n: vec) res += n;

	res += ")";
	return res;
}
```