Some times we want to traverse on the nodes but not with depth, instead we want to make it **level by level**. This can be easy by a simple [[queue]].

This can be made by following these steps:
1. Add the root to the queue.
2. Pop the front and print it.
3. Add the children of the popped node to the queue.
4. repeat the processes 2 & 3 until the queue is empty.

```cpp title:"Coding example"
void print_level_order() {
	std::queue<TreeNode*> nodes_queue;
	nodes_queue.push(this->root);

	while(!nodes_queue.empty()) {
		TreeNode* current = nodes_queue.front();
		nodes_queue.pop();
		
		if(current->left)
			nodes_queue.push(current->left);
		if(current->right)
			nodes_queue.push(current->right);
		std::cout << "( " << current->data << " ) ";
	}
}
```