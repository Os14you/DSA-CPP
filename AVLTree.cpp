#include "AVLTree.hpp"

AVLTree::AVLTree(): root(nullptr) { }
AVLTree::AVLTree(int value): root(new AVLNode(value)) { }

AVLNode* AVLTree::right_rotate(AVLNode* root) {
    AVLNode* new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;
    root->update_height();
    new_root->update_height();
    return new_root;
}

AVLNode* AVLTree::left_rotate(AVLNode* root) {
    AVLNode* new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
    root->update_height();
    new_root->update_height();
    return new_root;
}

AVLNode* AVLTree::balance(AVLNode* node) {
    if(node->balance_factor() == 2) {
        if(node->left->balance_factor() == -1)
            node->left = left_rotate(node->left);
        
        node = right_rotate(node);
            
    } else if(node->balance_factor() == -2) {
        if(node->right->balance_factor() == 1)
            node->right = right_rotate(node->right);
        
        node = left_rotate(node);
    }

    return node;
}

AVLNode* AVLTree::_insert(AVLNode* node, int value) {
    if(!node) {
        return new AVLNode(value);
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

void AVLTree::insert(int value) {
    root = _insert(root, value);
}

AVLNode* AVLTree::min_node(AVLNode* node) {
    if(!node || !node->left) return node;
    
    return min_node(node->left);
}

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

void AVLTree::remove(int value) {
    if(!root) return;
    
    root = remove(root, value);
}

bool AVLTree::isLeaf(AVLNode* node) {
    return node && !node->left && !node->right;
}

void AVLTree::clear(AVLNode* node) {
    if(!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
    node = nullptr;
}

AVLTree::~AVLTree() {
    clear(root);
}