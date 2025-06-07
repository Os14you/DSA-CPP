The way of initializing a vector in c++:
``` cpp 
#include <iostream>
#include <vector>

int main() {
	std::vector<int> v1(5,7);
	// initialize a vector with 5 numbers all with 7 value
	
	for(int i = 0; i < (int) v1.size(); i++) 
		std::cout << v1[i] << " ";
	std::cout << std::endl;
	
	for(auto &val : v1)
		std::cout << val << " ";
	std::cout << std::endl;
	
	return 0;
}
```

Pointers overview:
``` cpp
#include <iostream>

int main() {
	int x = 10;
	int *p0 = &x; // never delete
	int *p1 {nullptr}; // never delete

	int *p2 = new int; // Dinamic Allocation
	*p2 = 20; // set a value

	int *p3 = new int {30}; 
	delete p2;
	delete p3;
	p2 = p3 = nullptr;

	int n = 20; // NOT const
	int *pArr = new int [n];

	for(int i=0; i<n; i++)
		pArr[i] = i;

	delete[] pArr;
}
```

