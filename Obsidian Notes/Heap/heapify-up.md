Starting from the new added node index as long as its parent is greater, shift the parent to the current child node and move up.

![[Heapify-UP.excalidraw]]

In this example, we need to fix the binary heap, so we start from the added element if it’s smaller than its parent we swap and move up.

```cpp
void heapify_up(int idx) {
	int parent_pos = perant(idx);
	if(parent_pos == -1 || heap[parent_pos] < heap[idx])
		return;

	swap(heap[parent_pos], heap[idx]);
	heapfiy_up(parent_pos);
}
```