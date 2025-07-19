We use a single array, but with some strategy to systematically use/change the array, by taking the first available position after the hash.

It has some types the normal and easy way is linear probing:
- If the index has no value add it.
- If it has a value then move to the **next** index.

