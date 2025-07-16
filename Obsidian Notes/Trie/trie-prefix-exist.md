```cpp
bool prefix_exist(std::string prefix, int idx = 0) {
	if(idx == (int) prefix.size())
		return true;
		
	int cur = prefix[idx] - 'a';
	if(!child[cur])
		return false;

	return child[cur]->prefix_exist(prefix, idx + 1);
}
```