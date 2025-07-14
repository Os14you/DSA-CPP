#problemsolving #binaryTree #recursion 

- Create a class `Solution`. Inside it function called `maxValue`
- It returns the maximum value in the whole tree
	- The function should be recursive
	- i.e. similar to the pre-order traversal
- You can assume we never call with a null tree

```cpp title:solution folded:true
int maxValue(TreeNode* root) {
	int maxVal = root->data;
	
	if(root->right) 
		maxVal = std::max(maxVal, maxValue(root->right));
	if(root->left)  
		maxVal = std::max(maxVal, maxValue(root->left ));
	return maxVal;
}
```