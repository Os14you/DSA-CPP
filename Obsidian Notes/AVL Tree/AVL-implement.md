We will add some functions to the [[BST-implement|BST]] to make it self balanced.

-> starting from the [[AVL-node|node]] itself.
-> [[tree-rotation|tree rotation]] is the key to save the balance every time it fails.
-> 4 [[imbalance-cases|imbalance cases]] to handle
-> After [[AVL-insertion|insertion]] which is just like the [[BST-implement|BST]], we add 2 lines one is to update the height of the node and then balance it.

[[AVL-delete-node|Deleting]] is much simpler now, as we just have to update the height and the balance the tree after deleting.