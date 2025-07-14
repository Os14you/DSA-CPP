When we get the post-order, pre-order or level-order [[traversal-terminology|traversal]] of a tree it will be unique even if it has the same values. **BUT it’s not applied otherwise.**

When you have one of the traversal methods (only one) you cannot guarantee it’s the only tree to make this traversal (you can make more than a tree with the same traversal). **BUT** you can make it using the **in-order** with one of the traversal methods - *post-order, pre-order, level-order* -.   

***e.g.*** Pre-order: $[1, 2, 4, 7, 8, 5, 9, 3, 6, 10]$ where root is the first value, In-order: $[\textcolor{yellow}{7}, \textcolor{yellow}{4}, \textcolor{yellow}{8}, \textcolor{yellow}{2}, \textcolor{yellow}{5}, \textcolor{yellow}{9}, 1, \textcolor{blue}{3}, \textcolor{blue}{10}, \textcolor{blue}{6}]$ where **1** (the root) split in-order to:
- $[\textcolor{yellow}{7}, \textcolor{yellow}{4}, \textcolor{yellow}{8}, \textcolor{yellow}{2}, \textcolor{yellow}{5}, \textcolor{yellow}{9}]$ left sub-tree.
- $[\textcolor{blue}{3}, \textcolor{blue}{10}, \textcolor{blue}{6}]$ right sub-tree.

So we goes like this the next in the pre-order is the root of the left sub-tree and it splits the left sub-tree into half and goes like this.


