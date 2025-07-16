We can make an array of pointers in each node to make it possible.

```cpp
class Trie {
private:
	static const int MAX_SIZE = 26;
	trie* child[MAX_SIZE];
	bool isLeaf;
	
public:
	trie(): isLeaf(false) {
		memset(child, nullptr, sizeof(child)); // cstring
	}
};
```

[[trie-insert|Insertion]] - [[trie-word-exist|Word exist]] - [[trie-prefix-exist|Prefix exist]] 