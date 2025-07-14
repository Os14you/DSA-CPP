We can represent the [[complete-binary-tree|complete binary tree]] in array structure using the [[tree-level-traversal|level traversal]] and some equations for getting the parent and its children.

![[Complete-Binary-Tree-Array.excalidraw|800]]

| $*0*$ | $*1*$ | $*2*$ | $*3*$ | $*4*$ | $*5*$ | $*6*$ | $*7*$ | $..$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :--: |
|   2   |   6   |   8   |  14   |   7   |  10   |  19   |  37   |  ..  |

### Indices relations
---
Given node $i$, its children are:
- $2*i + 1$
- $2*i + 2$

Given node $i$, its parent is:
- floor( $(i-1) / 2$ )