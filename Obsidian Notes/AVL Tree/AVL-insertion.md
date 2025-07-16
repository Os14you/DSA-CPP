```cpp
AVLTree* AVLTree::_insert(AVLNode* node, int value) {
    if(!node) {
        node = new AVLNode(value);
        return;
    }
    
    if(value < node->data) {
        if(node->left)
            _insert(node->left, value);
        else
            node->left = new AVLNode(value);
    } else {
        if(node->right)
            _insert(node->right, value);
        else 
            node->right = new AVLNode(value);
    }

    node->update_height();
    return balance(node);
}
```

-> [[AVL-balance|balance() Function]] 