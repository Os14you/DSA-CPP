It’s about analyzing the [[time-complexity|time complexity]] when some times the algorithm perform in a slow way but on the other hand most of the time it performs in a fast way.

Instead of analyzing the worst-case time complexity of an algorithm (which gives an upper bound on the running time of a single operation), amortized analysis considers the cost of multiple operations performed over time.

Most of the time when this pattern appears -> $1, 1, 1, 1, 1, 6, 1, 1, 1, 1, 1, 6$  it indicates an amortize analysis.