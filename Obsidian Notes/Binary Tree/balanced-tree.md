![[Balanced-binary-tree.excalidraw]]

Because [[degenerate-tree|degenerate tree]] makes our code very slow, we want to make the height as small as possible. That’s by balanced tree.

A tree that satisfy the following conditions:
- Difference between heights of left sub-tree and right sub-tree is not more than $1$.
	- E.g. heights of (left, right): $(6, 6)$ or $(6, 5)$ or $(5, 6)$
- Left sub-tree is balanced.
- Right sub-tree is balanced.