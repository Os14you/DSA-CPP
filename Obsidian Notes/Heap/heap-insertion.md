To insert in a heap we can take one of 2 approaches:
- Add to the tree the item, and then fix the corruption (not widely applicable)
- Add it in its correct position from the beginning.

The first way like said has 2 step the first is simply add the item in its order in the tree and the second is [[heapify-up|heapify the node]].