It’s about hashing the values to get an integer that helps us store and retrieve the value in the array in $O(1)$. 

It happens by these steps:
- Using a [[hash-function|hash function]] to hash the input.
- Take the hashed value as the index that will store the value.
- When we search .. just hash again and retrieve the value of the index.

> [[collision|Collision]], [[load-factor|Load Factor]], [[hash-table-problems|Problems]] 