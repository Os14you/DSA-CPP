#stack #problemsolving 
https://leetcode.com/problems/valid-parentheses

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

**Input:** `s = "()"`
**Output:** `true`

```cpp title:solution folded:true
bool isValid(std::string s) {
	std::stack<char> Stack;
	for(char c : s) {
		if(Stack.empty() && (c == ')' || c == '}' || c == ']')) return false;
		else if(c == '(' || c == '{' || c == '[') 
			Stack.push(c);
		else if(c == ')' && Stack.top() == '(') 
			Stack.pop();
		else if(c == '}' && Stack.top() == '{') 
			Stack.pop();
		else if(c == ']' && Stack.top() == '[') 
			Stack.pop();
		else return false;
	}
	return Stack.empty();
}
```