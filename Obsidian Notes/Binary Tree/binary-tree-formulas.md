***Perfect tree:***
- From height find the $\#$ of **nodes**: $n = 2^{h+1}-1 : h+1 = levels$ 
- From $\#$ of nodes find the **height**: $h=\log(n+1)-1$ 

***In any binary tree:***
- Each level has max of $2^h$ nodes.
- For $L$ levels, No more than $2^L - 1$ nodes
- For $N$ nodes, the min $\#$ of levels is: ceil( $\log(N+1)$ )
- For $M$ leaves, the min $\#$ of levels is: ceil($\log(M)$) $+ 1$ 

> [!tip]
> How many **unlabeled** binary trees of 3 nodes? -> The **Catalan Number**
> How many **labeled** binary trees of n nodes? -> $\text{Catlan}(n) * n!$
> > Catalan Number is $C_n = \frac{(2n)!}{(n+1)!n!}$



