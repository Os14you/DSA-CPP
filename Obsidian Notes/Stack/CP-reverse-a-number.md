#stack #problemsolving 

- Implement a method that takes number $\ge 0$ and reverse its digits using a stack
- `{cpp}int reverse_num(int num)`
- E.g. Input: $1234$, Output: $4321$
- Find a stack-based idea

```cpp title:solution folded:true
int reverse_num(int num) {
	std::stack<int> pool;
	
	while(num)
		pool.push(num%10), num/=10;

	for(int i=1; !pool.empty(); ++i) 
		num+=(pool.top()*pow(10,i)), pool.pop();
	num/=10;
	return num;
}
```