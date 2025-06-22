![[vector-insertion.excalidraw|800]]

When we want to insert a value in an index we follow these steps:
1) Check for the capacity == size.
2) Shift the elements right of the index to the right.
3) Add the value in the index.

**Coding e.g.** 

``` cpp
void insert(int idx, int value) {
	if (capacity == size)
		expand_capacity();

	for (int i = size-1; i >= idx; --i)
		arr[i+1] = arr[i];

	arr[idx] = value;
	++size;
}
```