It is a function that convert input (number, array, string, object) to fixed-size
values, a way to encrypt data.

We can do the hash function in any way, as long as it satisfies the request: 
=> Same input ⇒ Same output

Simple example is this function:
```cpp
int hash(int value, int n = 139) {
	return value % n; // output will be in range [0, 138]
}
```

When `n` has small value (or with bigger range of `value`) [[collision]] happens.