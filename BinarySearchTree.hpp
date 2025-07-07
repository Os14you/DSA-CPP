#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class BinarySearchTree {
private:
    TreeNode* root;
    void _insert(TreeNode* node, int value);
    void _print(TreeNode* node, std::string prefix, bool isRight);
    void _clear(TreeNode* node);
    int _max(TreeNode* node);
    int _min(TreeNode* node);
    bool isLeaf(TreeNode* node);
    bool _isPerfect(TreeNode* node, int height);
    bool _isFull(TreeNode* node);
    std::string _serialize(TreeNode* node);
    std::string _canonicalize(TreeNode* node);
    bool _search(TreeNode* node, int value);
    int count(TreeNode* node);
    TreeNode* get_next(std::vector<TreeNode*> &ancestors);
    bool find_chain(TreeNode* node, int value, std::vector<TreeNode*> &ancestors);
    TreeNode* _delete_node(TreeNode* node, int value);
    TreeNode* min_node(TreeNode* node);

public:
    BinarySearchTree();
    BinarySearchTree(int root_val);
    void insert(int value);
    void delete_node(int value);
    void print();
    TreeNode* getRoot() const;
    void print_level_order();
    void clear();
    int max();
    int min();
    bool is_perfect();
    bool is_full();
    std::string serialize();
    std::string canonicalize();
    bool search(int value);
    std::pair<bool, int> successor(int value);
    std::pair<bool, int> predecessor(int value);
    ~BinarySearchTree();
};

#endif /* BINARYSEARCHTREE_HPP */