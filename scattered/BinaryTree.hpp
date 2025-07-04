#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <vector>
#include <iostream>
#include <cassert>
#include <climits>
#include <queue>
#include <algorithm>

struct TreeNode {
    int data { };
    TreeNode* left { };
    TreeNode* right { };
    TreeNode(int data): data(data), left(nullptr), right(nullptr) { }
};

class BinaryTree {
private:
    TreeNode* root { };
    void _print(TreeNode* node, std::string prefix, bool isRight);
    void _clear(TreeNode* node);
    int _max(TreeNode* node);
    int _max_depth(TreeNode* node);
    bool isLeaf(TreeNode* node);
    bool _isPerfect(TreeNode* node, int height);
    bool _isFull(TreeNode* node);
    std::string _serialize(TreeNode* node);
    std::string _canonicalize(TreeNode* node);
    int _search(TreeNode* node, int value);
    int count(TreeNode* node);

public:
    BinaryTree();
    BinaryTree(int root_val);
    TreeNode* getRoot() const;
    void add(std::vector<int> values, std::vector<char> directions);
    void print();
    void print_level_order();
    void clear();
    int max();
    int max_depth();
    bool is_perfect();
    bool is_full();
    std::string serialize();
    std::string canonicalize();
    int search(int value);
    ~BinaryTree(); 
};

#endif /* BINARYTREE_HPP */