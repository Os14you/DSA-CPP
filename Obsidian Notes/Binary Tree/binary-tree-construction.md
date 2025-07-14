```cpp
void add(std::vector<int> values, std::vector<char> directions) {
	assert(values.size() == directions.size());
	TreeNode* current = this->root;

	for(int i=0; i<(int) values.size(); ++i) {
		if(directions[i] == 'L') {
			if(!current->left)
				current->left = new TreeNode(values[i]);
			else
				assert(current->left->data == values[i]);
			current = current->left;
		} else {
			if(!current->right)
				current->right = new TreeNode(values[i]);
			else
				assert(current->right->data == values[i]);
			current = current->right;
		}
	}
}
```