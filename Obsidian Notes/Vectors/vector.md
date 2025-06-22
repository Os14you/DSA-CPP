It should has a size and array BUT it’s a dynamic array:

``` cpp
#include <iostream>
#include <cassert>

class Vector {
	private:
		int* arr = nullptr;
		int size = 0;
	public:
		Vector (int size) : size(size) {
			if ( size <= 0 ) {
				std::cerr << "Error; Size must be > 0";
				return;
			}
			arr = new int[size] { };
		}
		~Vector () {
			delete[] arr;
			arr = nullptr;
		}
};
```

Adding set and get for the Vector:

``` cpp
void set(int idx, int value) {
	assert(idx >= 0 && idx < size);
	arr[idx] = value;
}

int get(int idx) {
	assert(idx >= 0 && idx < size);
	return arr[idx];
}
```

[[vector-implement|Vector Implementation]]
[[append2vector|Appending operation]]
[[insertion-vector|Insertion Operation]]
[[vector-problems|Problems]] 