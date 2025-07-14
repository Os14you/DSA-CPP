Starting from the root node as long as one of its children is smaller, shift the parent to the smallest child node and move down.

![[Heapify-Down.excalidraw|800]]

In this example, we need to fix the binary heap after we make the first step, so we start from the root element if it’s greater than one of its children we swap it with the small one and move down.

```cpp
void heapify_down(int idx) {
	int child_left  = left(idx );
	int child_right = right(idx);

	int mn = std::min(child_left, child_right); 
	if(mn == -1 || heap[idx] < heap[mn])
		return;

	swap(heap[idx], heap[mn]);
	heapfiy_up(mn);
}
```