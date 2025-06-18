What is the largest needed **memory** at any point of time during the program?

```cpp title:example
int* f(int n) { // Total O(n) memory, O(n^2) time
	// This line: O(n) time and O(n) memory
	int *p = new int[n] {};
	
	for (int i = 0; i < n; ++i)
		p[i] = i;
	
	int sum = 0; 
	
	// 0(n^2) time
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			sum += p[i];
		}
	}
	return p;
}
```

It’s all about [[Big-O-notation|Big O Notation]] again, but instead of the **number of steps** in time complexity we use the **largest memory** needed.

- Recursion is a bit tricky.
- If we have N recursive calls, then the variables in each call remains in memory.
	- E.g. we will have $N$ copies of subres variables.
- So $O(n)$ memory
- We call it **auxiliary space** in the stack (extra temporary space used by an algorithm)

> [!NOTE] Before and After recursive call
> Before the call, $p$ is created and removed. Creation itself is $O(n)$ any time But the $N$ recursive active calls, each has only $O(1)$ memory.

```cpp
int f10(int n) { // O(n^2)
	if(n <= 0)
		return;
	int* p = new int [n] { };
	f10(n-1); // O(n)
	delete[] p;
}

int f11(int n) { // O(n)
	if(n <= 0)
		return;
	int* p = new int [n] { };
	delete[] p;
	f11(n-1); // O(1)
}
```
