#stack #problemsolving 

You are given a string `s` consisting of lowercase English letters. A **duplicate removal** consists of choosing two **adjacent** and **equal** letters and removing them.

We repeatedly make **duplicate removals** on `s` until we no longer can.

Return _the final string after all such duplicate removals have been made_. It can be proven that the answer is **unique**.

**Example 1:**
- **Input:** s = `{cpp}"abbaca"`
- **Output:** `{c}"ca"`
- **Explanation:** For example, in `{c}"abbaca"` we could remove `{c}"bb"` since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is `{c}"aaca"`, of which only `{c}"aa"` is possible, so the final string is `{c}"ca"`.

```cpp title:solution folded:true
std::string removeDuplicates(std::string s) {
	stack<char> stackChar, tmp;
	std::string res="";
	
	for(char c :s) {
		if(!stackChar.empty() && c == stackChar.top()) stackChar.pop();
		else
			stackChar.push(c);
	}
	
	while(!stackChar.empty()) 
		tmp.push(stackChar.top()), stackChar.pop();
	
	while(!tmp.empty()) 
		res+=tmp.top(), tmp.pop();

	return res;
}  
```