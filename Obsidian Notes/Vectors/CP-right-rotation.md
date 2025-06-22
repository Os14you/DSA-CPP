- Consider our Vector class. Add the function: `void right_rotate()`
- The function shifts every element 1 step towards the right.
- What about the rightmost element? It goes to the first `idx`
- Example
	- Assume the array content is: `0 1 2 3 4`
	- After a right rotation it will be: `4 0 1 2 3`
- Notice how, in this case, the '4' has been rotated to the head of the array!
- Ensure you avoid expanding the array's capacity

```cpp title:solution fold
void right_rotate() {
	int* new_arr = new int [size];

	for (int i=0; i<size; ++i)
		new_arr[(i+1)%size] = arr[i];

	std::swap(arr, new_arr);
	delete[] new_arr;
}
```

#vector #problemsolving

