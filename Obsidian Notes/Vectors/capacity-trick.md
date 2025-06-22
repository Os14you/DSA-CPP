Multiplying the capacity of the array by 2 every time a reach the capacity limit. this will reduce the number of steps.

**Coding (Data) e.g.**

``` cpp
class Vector {
	private:
		int* arr = nullptr;
		int capacity { 0 }; // actual size
		int size { }; // user size
};
```

**Coding (Constructor) e.g.**

``` cpp
Vector(int size) : size(size) {
	if(size < 0)
		size=1;
	capacity = size + 10;
	arr = new int [capacity] { };
}
```

**Coding (Push_back) e.g.**

``` cpp
private:
	void expand_capacity() {
		capacity *= 2;
		int* nArr = new int [capacity] { };

		for (int i=0; i<size; i++)
			nArr[i] = arr;

		std::swap(arr, nArr);
		delete[] nArr;
	}


public:
	void push_back(int value) {
		if (size == capacity)
			expand_capacity();
		arr[size++] = value;
	}
```