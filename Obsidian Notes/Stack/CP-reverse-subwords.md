#stack #problemsolving 

- Develop: `{cpp}string reverse_subwords(string line)`
- It takes a string of spaces, e.g. `{cpp}"abc d efg xy"`
- Then reverse each subword ⇒ `{cpp}“cba d gfe yx“`
- Find a stack-based idea

```cpp title:solution folded:true
std::string reverse_subwords(std::string line) {
	std::string res="";
	line += " ";
	std::stack<char> Stack;
	
	for(char c: line) {
	
		if(c != ' ') Stack.push(c);
		else {
			while(!Stack.empty()) res += Stack.top(), Stack.pop();
			res+=" ";
		}
	}
	return res;
}
```