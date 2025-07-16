```cpp
AVLNode* AVLTree::remove(AVLNode* node, int value) {
    if(!node) return nullptr;

    if(node->data > value)
        node->left = remove(node->left, value);
    else if(node->data < value)
        node->right = remove(node->right, value);
    else {
        if(!node->right) {
            AVLNode* temp = node->left;
            delete node;
            return temp;
        } else if (!node->left){
            AVLNode* temp = node->right;
            delete node;
            return temp;
        } else {
            AVLNode* mn = min_node(node->right);
            node->data = mn->data;
            node->right = remove(node->right, node->data);
        }
    }

    if(node)
        node->update_height(), node = balance(node);

    return node;
}
```