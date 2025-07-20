#ifndef TRIE_HPP
#define TRIE_HPP

#include <iostream>
#include <vector>
#include <cstring>

class Trie {
private:
    static const int MAX_CHAR = 26;
    Trie* children[MAX_CHAR];
    bool isLeaf;
    void clear();
    
public:
    Trie();
    void insert(std::string word, int idx = 0);
    bool wordExists(std::string word, int idx = 0);
    void deleteWord(std::string word, int idx = 0);
    bool prefixExists(std::string prefix, int idx = 0);
    bool wordExistsWith_1_change(std::string word, int idx = 0);
    void print();
    ~Trie();
};

#endif /* TRIE_HPP */