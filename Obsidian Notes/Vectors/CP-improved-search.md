- Assume our vector is huge and we do many `{cpp}find()` calls for almost a few small
- repetitive values
- One way to improve the code speed is: each time you find the value, you
- shift it one step to the left
- Eventually, the values that are queried a lot, will move to the head of array
- Implement method: `{cpp}int find_transposition(int value)`
	- It returns the found position, but consider moving it one step to the left
- Example: `10 20 30 40 50`. `{cpp}find_transposition(30)`
	- New array `10 30 20 40 50`
	- Return `1`

```cpp title:solution fold
int find_transposition(int value) {
	int idx = find(value);	
	if(idx == -1) return -1;

	std::swap(arr[idx], arr[idx-1]);
	return idx - 1;
}
```

#vector #problemsolving 