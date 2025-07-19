```cpp
int hash(int value, int n = 100) {
	return value % n;
}

std::cout << hash(201) << ' ' << hash(301);
// 1 1
```

Here in this code we see that when we enters different values it give us same values which is not what we needs.

To solve this problem (reduce collisions) we can take some approaches that solve it a little. e.g. [[chaining-hash|chaining]] and [[probing-hash|probing]].