#include "Trie.hpp"

Trie::Trie() : isLeaf(false) {
    memset(children, 0, sizeof(children));
}

void Trie::insert(std::string word, int idx) {
    if(word.size() == idx)
        isLeaf = true;
    else {
        int cur = word[idx] - 'a';
        if(!children[cur])
            children[cur] = new Trie();

        children[cur]->insert(word, idx + 1);
    }
}

bool Trie::wordExists(std::string word, int idx) {
    if(word.size() == idx)
        return isLeaf;
    
    int cur = word[idx] - 'a';
    if(!children[cur])
        return false;
        
    return children[cur]->wordExists(word, idx + 1);
}

bool Trie::prefixExists(std::string prefix, int idx) {
    if(prefix.size() == idx)
        return true;
    
    int cur = prefix[idx] - 'a';
    if(!children[cur])
        return false;
        
    return children[cur]->prefixExists(prefix, idx + 1);
}

void Trie::deleteWord(std::string word, int idx) {
    if(word.size() == idx)
        isLeaf = false;
    else {
        int cur = word[idx] - 'a';
        if(!children[cur])
            return;
        
        children[cur]->deleteWord(word, idx + 1);
    }
}

void Trie::clear() {
    if(isLeaf)
        return;
    
    for(int i = 0; i < MAX_CHAR; ++i) {
        if(children[i]) {
            children[i]->clear();
            delete children[i];
            children[i] = nullptr;
        }
    }
}

Trie::~Trie() {
    clear();
}