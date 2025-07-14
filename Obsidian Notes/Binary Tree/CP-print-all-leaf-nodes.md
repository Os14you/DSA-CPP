#recursion #binaryTree #problemsolving 

```cpp title:solution folded:true
void print_all_leaves(Node* root) {
	if(!root) return;

	if(!root->right && !root->left) {
		std::cout << "( " << root->data << " )" << ", ";
		return;
	}
	
	if(root->left ) print_all_leaves(root->left );
	if(root->right) print_all_leaves(root->right);
}
```