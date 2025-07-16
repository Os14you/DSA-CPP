```cpp
AVLNode* AVLTree::balance(AVLNode* node) {
    if(node->balance_factor() == 2) {
        if(node->balance_factor(node->left) == -1)
            node->left = left_rotate(node->left);
        
        node = right_rotate(node);
            
    } else if(node->balance_factor() == -2) {
        if(node->balance_factor(node->right) == 1)
            node->right = right_rotate(node->right);
        
        node = left_rotate(node);
    }

    return node;
}
```

-> [[tree-right-rotation|Right rotation]], [[tree-left-rotation|Left rotation]] 