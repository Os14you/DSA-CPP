Assume we have 30 strings and the table of size 10
The best case is if every table cell has 30/10 = 3 elements
- Then we take O(3) to find an element
- Total_elements / table_size ⇒ this is called load_factor
- This means our hashed keys are almost uniform distribution
- If so ⇒ very short chain of nodes

What if a few buckets have almost all elements and most array is empty
- Then your hash-function is very bad!