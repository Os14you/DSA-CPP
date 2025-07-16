#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <iostream>

struct AVLNode {
    int data;
    int height;
    AVLNode* left;
    AVLNode* right;
    
    AVLNode(int data): data(data), height(0), left(nullptr), right(nullptr) { }
    AVLNode(): AVLNode(0) { }

    int child_height(AVLNode* node) {
        return node ? node->height : -1;
    }

    int balance_factor() {
        return child_height(left) - child_height(right);
    }

    int update_height() {
        return height = 1 + std::max(child_height(left), child_height(right));
    }
};

class AVLTree {
private:
    AVLNode* root;
    AVLNode* right_rotate(AVLNode* root);
    AVLNode* left_rotate(AVLNode* root);
    AVLNode* _insert(AVLNode* node, int value);
    AVLNode* remove(AVLNode* node, int value);
    AVLNode* balance(AVLNode* node);
    bool isLeaf(AVLNode* node);
    void clear(AVLNode* node);
    AVLNode* min_node(AVLNode* node);

public:
    AVLTree();
    AVLTree(int value);
    void insert(int value);
    void remove(int value);
    ~AVLTree();
};


#endif /* AVL_TREE_HPP */