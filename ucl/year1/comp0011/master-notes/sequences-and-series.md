# Comp0011: Sequences and Series Notes

## 1. Limits of Sequences

### 1.1 Formal Definition ($\epsilon-N$)
A sequence $(a_n)$ converges to a limit $L$, written $\lim_{n \to \infty} a_n = L$, if for every $\epsilon > 0$, there exists a natural number $N \in \mathbb{N}$ such that for all $n > N$:
$$|a_n - L| < \epsilon$$

**Pointer for Proofs:**
1. Start with the inequality $|a_n - L| < \epsilon$.
2. Isolate $n$ to find a relationship (e.g., $n > f(\epsilon)$).
3. Set $N = \lceil f(\epsilon) \rceil$ and write the formal argument.

### 1.2 Monotonicity and Boundedness
*   **Increasing:** $a_{n+1} \geq a_n$ for all $n$.
*   **Decreasing:** $a_{n+1} \leq a_n$ for all $n$.
*   **Bounded Above:** There exists $M$ such that $a_n \leq M$ for all $n$.
*   **Bounded Below:** There exists $m$ such that $a_n \geq m$ for all $n$.

### 1.3 Monotone Convergence Theorem (MCT)
If a sequence is **monotone** (either increasing or decreasing) and **bounded**, then it is **convergent**.

### 1.4 Little "o" Notation
We say $f(n) = o(g(n))$ ("$f$ is little-o of $g$") as $n \to \infty$ if $g(n)$ grows significantly faster than $f(n)$:
$$\lim_{n \to \infty} \frac{f(n)}{g(n)} = 0$$

---

## 2. Arithmetic and Geometric Progressions

### 2.1 Arithmetic Sequences
Terms change by adding a common difference $d$.
*   **Recursive:** $u_n = u_{n-1} + d$
*   **Explicit:** $u_n = u_1 + (n-1)d$
*   **Finite Sum ($S_n$):** 
$$S_n = \frac{n}{2}(u_1 + u_n) = \frac{n}{2}[2u_1 + (n-1)d]$$

### 2.2 Geometric Sequences
Terms change by multiplying by a common ratio $r$.
*   **Recursive:** $u_n = r \cdot u_{n-1}$
*   **Explicit:** $u_n = u_1 \cdot r^{n-1}$ (or $u_n = u_0 \cdot r^n$ if starting at 0)
*   **Finite Sum ($S_n$):** 
$$S_n = \sum_{k=0}^{n-1} a r^k = a \frac{1-r^n}{1-r} \quad (r \neq 1)$$

---

## 3. Infinite Series

### 3.1 Definition of Convergence
A series $\sum_{n=1}^\infty a_n$ converges if the sequence of its **partial sums** $S_N = \sum_{n=1}^N a_n$ converges to a finite limit.

### 3.2 The Test for Divergence ($n$-th Term Test)
If $\lim_{n \to \infty} a_n \neq 0$, then the series $\sum a_n$ **must diverge**.
*   *Note: If the limit is 0, the test is inconclusive (e.g., the Harmonic Series).*

### 3.3 Geometric Series Test
The infinite geometric series $\sum_{n=0}^\infty a r^n$ converges if and only if:
$$|r| < 1$$
If it converges, the sum is:
$$S_\infty = \frac{a}{1-r}$$

---

## 4. Key Inequalities and Limits

### 4.1 Logarithmic Inequality
For $x \geq 0$:
$$x \geq \ln(1+x)$$
This is often used to prove the divergence of the **Harmonic Series** $\sum \frac{1}{n}$ by showing the partial sums grow without bound.

### 4.2 Telescoping Sums
A sum where middle terms cancel out. For example:
$$\sum_{k=1}^n [f(k+1) - f(k)] = f(n+1) - f(1)$$
In Section 4 of the sheet, you will encounter:
$$\sum_{k=1}^n \ln\left(\frac{k+1}{k}\right) = \sum_{k=1}^n [\ln(k+1) - \ln(k)]$$

### 4.3 Factorial Growth
The "Hierarchy of Growth" as $n \to \infty$:
$$\ln(n) \ll n^k \ll a^n \ll n! \ll n^n$$
This hierarchy helps determine the limits of ratios like $\frac{n!}{n^n}$ or $\frac{2^n}{n!}$.