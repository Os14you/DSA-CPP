- Consider our Vector class. Add the function: `void left_rotate()`
- The function rotates the whole array 1 step to the left
- However, in this case, the leftmost element will be 'rotated' around to the back of the array!
- Example
	- Assume the array content is: `0 1 2 3 4`
	- After a left rotation, it will be: `1 2 3 4 0`
- Notice how the 0 has 'rotated' to the tail of the array after applying `left_rotate()`
- Ensure you avoid expanding the array's capacity.

```cpp title:solution fold
void left_rotate() {
	int first_element = arr[0];
	for (int i=size-1; i>0; --i)
		arr[i-1] = arr[i];

	arr[size-1] = first_element;
}
```

#vector #problemsolving