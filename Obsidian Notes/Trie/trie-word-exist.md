```cpp
bool word_exist(std::string word, int idx = 0) {
	if(idx == (int) word.size())
		return isLeaf;
		
	int cur = word[idx] - 'a';
	if(!child[cur])
		return false;

	return child[cur]->word_exist(word, idx + 1);
}
```
