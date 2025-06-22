- Implement method `{cpp}int pop(int idx)` in the vector class
- It returns the deleted value
- Remove this element from the array
- Assume array is: `4 0 1 2 3`
- `{cpp}pop(2)`
	- Return value 1
	- New array: `4 0 2 3`

```cpp title:solution fold
int pop(int idx) {
	assert(idx >= 0 && idx < size);
	popVal = arr[idx];

	for (int i=idx; i<size; ++i)
		arr[i] = arr[i+1];
	arr[size--] { };
	return popVal;
}
```

#vector #problemsolving