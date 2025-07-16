It’s an m-ary tree[^1] - a [[trees-data-structure|tree]] with a lot of edges - where we store letters on the edges so we can search for words and prefixes very quickly.

![[Trie-Example.excalidraw|800]]
Like in this tree, we make a tree where each edge holds a letter, where the end of each word is colored.

This tree represent the following words:
- try
- by
- brw
- ac
- acy
- actr

There are some other much complex data structures e.g. [[suffix-tree]], [[suffix-array]].

> [[trie-implement|Implement]], [[trie-problems|Problems]]

[^1]: - A binary tree is a tree where a node has up to 2 children
	- A ternary tree is a tree where a node has up to 3 children
	- An m-ary tree is a tree where a node has up to m children
