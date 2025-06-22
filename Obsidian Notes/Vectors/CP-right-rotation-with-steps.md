- Implement `{cpp}void right_rotate(int times)`
- This one applies the right rotation times time
	- Assume array content is: `0 1 2 3 4`
	- `{cpp}right_rotate(2)` ⇒ it will be: `3 4 0 1 2`
- The challenge: times can be up to: $2000000000$
- Your code should be efficient to some extent

```cpp title:solution fold
void right_rotate(int times) {
	times %= size;
	if(times == 0) return;
	
	int* new_arr = new int[size];
	
	for (int i=0; i<size; ++i) 
		new_arr[(times+i)%size] = arr[i];

	std::swap(arr, new_arr);
	delete[] new_arr;
}
```

#vector #problemsolving