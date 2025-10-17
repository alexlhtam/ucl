# lecture notes 14-10-25
## amortised analysis I
- when an operation is usually fast but sometimes slow, we use amortised analysis to find the average time taken per operation over a sequence of operations
- the total cost of copying occurs at sizes $1, g, g^2, ... , g^k$ where $g$ is the growth factor and $N \approx g^{k+1}$
- the total number of copies is a geometric series, i.e.
$$C(N) = \sum g^i = \frac{g^{k+1}-1}{g-1}\approx \frac{N}{g-1}$$
- for a doubling strategy ($g=2$), the total copy cost is $\approx \frac{N}{2-1}=N$