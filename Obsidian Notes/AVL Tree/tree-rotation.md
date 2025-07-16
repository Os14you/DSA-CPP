Changing the structure of the tree without affecting the order of the elements.

![[Tree-Rotation.excalidraw|800]]

**Right rotation** (clockwise):
- *For memorization:* right node $(10)$ goes down
**Left rotation** (counter-clockwise):
- *For memorization:* left node $(5)$ goes down

```cpp 
AVLNode* right_rotate(AVLNode* root) {
    AVLNode* new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;
    root->update_height();
    new_root->update_height();
    return new_root;
}

AVLNode* left_rotate(AVLNode* root) {
    AVLNode* new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
    root->update_height();
    new_root->update_height();
    return new_root;
}
```
