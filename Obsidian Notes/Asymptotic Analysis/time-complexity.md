- Below code is doing `push_back` in Vector (of currently size elements)
	- It creates an array. It copies the old data. It adds the new element. Swap pointers. Remove old.
- If we tried to estimate the number of steps ⇒ ~ $5size + 7$
- It takes **linear number** of steps!

```cpp title:'push_back() code'
void push_back(int value) {
	int* new_arr = new int [size+1] { }; // size + 1
	for (int i=0; i<size; i++) // 3size + 1
		new_arr[i] = arr[i];

	new_arr[size++] = value; // 2
	std::swap(new_arr, arr); // 3

	delete[] new_arr; // size
}
```

We only care about function itself, if it’s linear .. quadratic and so on. And for that we ignore the factors of the steps if we get ~~5~~size + ~~7~~ we say it’s $size$ steps or $O(n)$ -> this is [[Big-O-notation]].

