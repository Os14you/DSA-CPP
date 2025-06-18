- If a code takes $9n+17$ steps, we say it is $O(n)$ code
	- Order of $N$
- It means the code runs in linear time relative to $n$
	- Little more mathematically,
- Practically, the largest term in the equation is the one that dominates
	- All others are neglectable with large $N$
	- $5n^2 + 10n$ ⇒ $O(n^2)$. So we selected the largest term ($n^2$) as it will dominate
	- $17$ ⇒ $O(1)$: We say, this is constant time (largest is $n^0$).
- $O()$ is intended to be an **upper bound**. In other words considers **worst case**. But sometimes is **misleading**.
- Another type is called: **Average-Case Analysis**. This one computed the expected order. It involves probability and consider different cases. It is usually harder analysis

### Mathematically
---
We say that there is some **Constant** $C$ that confirms $f(x) ≤ C * g(x)$ where $f(x)$ is the function that represent the actual steps and $g(x)$ is the Big O of the code.

To make it more formally we take another constant $n_0$ and say that the equation will be $\forall x > n_0: \frac{f(x)}{g(x)} ≤ C$.

![[Big-O-Notation.excalidraw|center|800]]