When we append to the currant array we can make the following steps:
1) Create a new dynamic array with a $\text{size} + 1$.
2) Copy the elements from the previous array to the new one.
3) Add the new element at the end of the new array (Adjust the size value of the vector).
4) Swap the two arrays.
5) Remove the useless array.

**Coding e.g.**

``` cpp
void push_back(int value) {
	int* nArr = new int[size+1]; // 1

	for(int i=0; i<size; i++)
		nArr[i] = arr[i]; // 2

	nArr[size++] = value; // 3
	std::swap(arr, nArr); // 4

	delete[] nArr; // 5
}
```

**BUT,** there is a problem with this way. Consider it when you loop for 1 Million `push_back()` you will have approximately $n^2$ steps. To solve this problem we can use the **[[capacity-trick|capacity trick]]**.