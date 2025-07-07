#include "BinarySearchTree.hpp"

BinarySearchTree::BinarySearchTree() : root(nullptr) {}
BinarySearchTree::BinarySearchTree(int root_val) : root(new TreeNode(root_val)) {}

TreeNode* BinarySearchTree::getRoot() const {
    return root;
}

int BinarySearchTree::count(TreeNode* node) {
    if(!node) return 0;
    
    return 1 + count(node->left) + count(node->right);
}

bool BinarySearchTree::isLeaf(TreeNode* node) {
    return node && !node->left && !node->right;
}

bool BinarySearchTree::_search(TreeNode* node, int value) {
    if(!node) return false;
    
    if(node->data == value)
        return true;
    
    if(value < node->data)
        return _search(node->left, value);
    
    return _search(node->right, value);
}

bool BinarySearchTree::search(int value) {
    return _search(root, value);
}

TreeNode* BinarySearchTree::_delete_node(TreeNode* node, int value) {
    if(!node) return nullptr;

    if(node->data > value)
        node->left = _delete_node(node->left, value);
    else if(node->data < value)
        node->right = _delete_node(node->right, value);
    else {
        if(!node->right) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        } else if (!node->left){
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else {
            TreeNode* mn = min_node(node->right);
            node->data = mn->data;
            node->right = _delete_node(node->right, node->data);
        }
    }

    return node;
}

void BinarySearchTree::delete_node(int value) {
    root = _delete_node(root, value);
}

int BinarySearchTree::_max(TreeNode* node) {
    if(!node->right) return node->data;

    return _max(node->right);
}

int BinarySearchTree::max() {
    return _max(root);
}

int BinarySearchTree::_min(TreeNode* node) {
    if(!node->left) return node->data;

    return _min(node->left);
}

int BinarySearchTree::min() {
    return _min(root);
}

TreeNode* BinarySearchTree::min_node(TreeNode* node) {
    if(!node || !node->left) return node;
    
    return min_node(node->left);
}

void BinarySearchTree::_insert(TreeNode* node, int value) {
    if(!node) {
        root = new TreeNode(value);
        return;
    }
    
    if(value < node->data) {
        if(node->left)
            _insert(node->left, value);
        else
            node->left = new TreeNode(value);
    } else {
        if(node->right)
            _insert(node->right, value);
        else 
            node->right = new TreeNode(value);
    }
}

void BinarySearchTree::insert(int value) {
    _insert(root, value);
}

void BinarySearchTree::_print(TreeNode* node, std::string prefix, bool isRight) {
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

void BinarySearchTree::print() {
    _print(root, "", true);
}

void BinarySearchTree::print_level_order() {
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


bool BinarySearchTree::_isPerfect(TreeNode* node, int height) {
    if(!node->left && !node->right) 
        return height == 0;
    
    if((!node->right && node->left) || (node->right && !node->left))
        return false;
    
    return _isPerfect(node->left, height-1) && _isPerfect(node->right, height-1);
}

// bool BinarySearchTree::is_perfect() {
//     return _isPerfect(root, max_depth() - 1);
// }

bool BinarySearchTree::_isFull(TreeNode* root) {
    if(isLeaf(root))
        return true;
    
    if(root->right && root->left)
        return _isFull(root->left) && _isFull(root->right);
    
    return false;
}

bool BinarySearchTree::is_full() {
    return _isFull(root);
}

std::string BinarySearchTree::_serialize(TreeNode* node) {
    if(!node) return "()";
    
    return "(" + std::to_string(node->data) + " " + _serialize(node->left) + " " + _serialize(node->right) + ")";
}

std::string BinarySearchTree::serialize() {
    return _serialize(root);
}

std::string BinarySearchTree::_canonicalize(TreeNode* node) {
    if(!node) return "()";
    
    std::string res = "(" + std::to_string(node->data);
    std::vector<std::string> vec;

    vec.push_back(_canonicalize(node->left));
    vec.push_back(_canonicalize(node->right));
    
    sort(vec.begin(), vec.end());

    for(int i = 0; i < vec.size(); i++) {
        res += vec[i];
    }

    return res + ")";
}

std::string BinarySearchTree::canonicalize() {
    return _canonicalize(root);
}

bool BinarySearchTree::find_chain(TreeNode* node, int value, std::vector<TreeNode*> &ancestors) {
    if(!node) return false;
    
    ancestors.push_back(node);
    if(node->data == value) return true;
    
    if(value < node->data)
        return find_chain(node->left, value, ancestors);
    
    return find_chain(node->right, value, ancestors);
}

TreeNode* BinarySearchTree::get_next(std::vector<TreeNode*> &ancestors) {
    if(!ancestors.size()) return nullptr;
    
    TreeNode* node = ancestors.back();
    ancestors.pop_back();
    
    return node;
}

std::pair<bool, int> BinarySearchTree::successor(int value) {
    std::vector<TreeNode*> ancestors;
    if(!find_chain(root, value, ancestors)) return {false, -1};
    
    TreeNode* child = get_next(ancestors);
    if(child->right)
        return {true, _min(child->right)};
    
    TreeNode* parent = get_next(ancestors);
    while(parent && parent->right == child)
        child = parent, parent = get_next(ancestors);

    if(!parent) 
        return {false, -1};
    return {true, parent->data};
}

std::pair<bool, int> BinarySearchTree::predecessor(int value) {
	std::vector<TreeNode*> ancestors;
	
	if(!find_chain(root, value, ancestors))
		return {false, -1};

	TreeNode* child = get_next(ancestors);
	if(child->left)
		return {true, _max(root->left)};

	TreeNode* parent = get_next(ancestors);
	while(parent && parent->left == child)
		child = parent, parent = get_next(ancestors);

	if(parent) 
		return {true, parent->data};
	return {false, -1};
}

void BinarySearchTree::_clear(TreeNode* node) {
    if(!node) return;

    _clear(node->left);
    _clear(node->right);

    delete node;
}

void BinarySearchTree::clear() {
    _clear(root);
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    clear();
}