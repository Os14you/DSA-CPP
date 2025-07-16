```cpp
AVLNode* AVLTree::right_rotate(AVLNode* root) {
    AVLNode* new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;
    
    root->update_height();
    new_root->update_height();
    
    return new_root;
}
```