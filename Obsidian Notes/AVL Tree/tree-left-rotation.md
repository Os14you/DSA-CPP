```cpp
AVLNode* AVLTree::left_rotate(AVLNode* root) {
    AVLNode* new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
    
    root->update_height();
    new_root->update_height();
    
    return new_root;
}
```