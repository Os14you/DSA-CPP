```cpp
void insert(std::string str, int idx = 0) {
	if(idx == (int) str.size())
		isLeaf = true;
	else {
		int cur = str[idx] - 'a';
		if(!child[cur])
			child[cur] = new Trie();
		child[cur]->insert(str, idx + 1);
	}
}
```