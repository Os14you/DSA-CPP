#include "BinaryTree.hpp"

BinaryTree::BinaryTree(): root(nullptr) { }
BinaryTree::BinaryTree(int root_val): root(new TreeNode(root_val)) { }

TreeNode* BinaryTree::getRoot() const {
    return root;
}

void BinaryTree::add(std::vector<int> values, std::vector<char> directions) {
    assert(values.size() == directions.size());
	TreeNode* current = this->root;

	for(int i=0; i<(int) values.size(); ++i) {
		if(directions[i] == 'L') {
			if(!current->left)
				current->left = new TreeNode(values[i]);
			else
				assert(current->left->data == values[i]);
			current = current->left;
		} else {
			if(!current->right)
				current->right = new TreeNode(values[i]);
			else
				assert(current->right->data == values[i]);
			current = current->right;
		}
	}
}

void BinaryTree::_print(TreeNode* node, std::string prefix, bool isRight) {
	if (!node) return;
        
    std::cout << prefix;
    std::cout << (isRight ? "├── " : "└── ");
    std::cout << "(" << node->data << ")" << std::endl;
    
    if (node->left || node->right) {
        if (node->right) {
            _print(node->right, prefix + (isRight ? "│   " : "    "), true);
        }
        if (node->left) {
            _print(node->left, prefix + (isRight ? "│   " : "    "), false);
        }
    }
}

void BinaryTree::print() {
    if(root)
        _print(root, "", false);
}

void BinaryTree::print_level_order() {
    std::queue<TreeNode*> q;
    q.push(root);

    int level = 1;
    while(!q.empty()) {
        int size = q.size();
        std::cout << "Level " << level++ << ": ";
        while(size--) {
            TreeNode* node = q.front();
            q.pop();
            std::cout << "( " << node->data << " ) ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        std::cout << std::endl;
    }
}

void BinaryTree::_clear(TreeNode* node) {
    if(!node) return;

    _clear(node->left);
    _clear(node->right);

    std::cout << "deleting node: (" << node << ") whose data is: " << node->data << std::endl;
    delete node;
}

void BinaryTree::clear() {
    _clear(root);
}

// int BinaryTree::_max(TreeNode* node) {
//     if(!node) return INT_MIN;

//     int maxVal = node->data;

//     maxVal = std::max(maxVal, _max(node->left));
//     return std::max(maxVal, _max(node->right));
// }


int BinaryTree::_max(TreeNode* node) {
    if(!node) return INT_MIN;
    
    return std::max(node->data, std::max(_max(node->left), _max(node->right)));
}

int BinaryTree::max() {
    return _max(root);
}

int BinaryTree::_max_depth(TreeNode* node) {
    if(!node) return 0;

    return 1 + std::max(_max_depth(node->left), _max_depth(node->right));
}

int BinaryTree::max_depth() {
    return _max_depth(root);
}

bool BinaryTree::_isPerfect(TreeNode* node, int height) {
    if(!node->left && !node->right) 
        return height == 0;
    
    if((!node->right && node->left) || (node->right && !node->left))
        return false;
    
    return _isPerfect(node->left, height-1) && _isPerfect(node->right, height-1);
}

int BinaryTree::count(TreeNode* node) {
    if(!node) return 0;
    
    return 1 + count(node->left) + count(node->right);
}

bool BinaryTree::is_perfect() {
    return _isPerfect(root, max_depth() - 1);
}

bool BinaryTree::isLeaf(TreeNode* node) {
    return node && !node->left && !node->right;
}

bool BinaryTree::_isFull(TreeNode* root) {
    if(isLeaf(root))
        return true;
    
    if(root->right && root->left)
        return _isFull(root->left) && _isFull(root->right);
    
    return false;
}

bool BinaryTree::is_full() {
    return _isFull(root);
}

std::string BinaryTree::_serialize(TreeNode* node) {
    if(!node) return "()";
    
    return "(" + std::to_string(node->data) + " " + _serialize(node->left) + " " + _serialize(node->right) + ")";
}

std::string BinaryTree::serialize() {
    return _serialize(root);
}

std::string BinaryTree::_canonicalize(TreeNode* node) {
    if(!node) return "()";
    
    std::string res = "(" + std::to_string(node->data);
    std::vector<std::string> vec;

    vec.push_back(_canonicalize(node->left));
    vec.push_back(_canonicalize(node->right));
    
    std::sort(vec.begin(), vec.end());

    for(int i = 0; i < vec.size(); i++) {
        res += vec[i];
    }

    return res + ")";
}

std::string BinaryTree::canonicalize() {
    return _canonicalize(root);
}

int BinaryTree::_search(TreeNode* node, int value) {
    if(!node) 
        return -1;
    
    if(node->data == value) 
        return node->data;

    return std::max(_search(node->left, value), _search(node->right, value));
}

int BinaryTree::search(int value) {
    return _search(root, value);
}

BinaryTree::~BinaryTree() {
    clear();
}