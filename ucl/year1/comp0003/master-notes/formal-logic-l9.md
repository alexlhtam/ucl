# mathematical proof by induction

## induction - overview
- proof by induction is a technique for establishing universal properties of mathematical structures (numbers, lists, trees, formulas, etc.)
- each inductively (sometimes "recursively") defined structure comes with its own induction principle, mirroring the structure's definition
- induction principles come in various different forms, but for the most part they are equivalent to one another
  
## a simple proof
### lemma
the sum of any two even numbers is even:
$$ \forall n, m \in \N (\text{even}(m) \land \text{even}(n)) \implies \text{even}(m+n)$$
### proof
let $m, n \in \N$ be even
thus $m = 2m'$ and $n = 2n'$ for some numbers $m', n'$
consequently, $m + n = 2m' + 2n' = 2(m' + n')$
thus $m + n$ is even $\square$


## inductive definition of $\N$
- 0 is a natural number; (base case)
- if $n$ is a natural number then so is its successor $s(n)$; (step case)
- nothing else is a natural number (usually implicit)

## ordinary induction on $\N$
to prove a universal property $P$ of natural numbers:
1. show that $P(0)$ holds (base case of the induction)
2. assume that $P(k)$ holds for some arbitrary $k \in \N$ (the induction hypothesis (IH))
3. using this assumption, show that $P(s(k))$ (step case of this induction)

as an inference rule:
$$ \frac
{P(0) \qquad P(k) \implies P(s(k))}
{\forall n \in \N . P(n)} \text{(k arbitrary)}
$$

## example (1)
consider the following inductive definition of $+$:
$$\begin{cases}
0 + y = y \\
s(x) + y = s(x+y)
\end{cases}$$
here $+$ is defined by induction on its first (left hand) argument
lemma: $\forall y \in \N. y + 0 = y$
proof: by induction on $y$ (here $P(y) = (y + 0 = y)$)
base case: $0 + 0 = 0$ holds by (1)
induction hypothesis: $k + 0 = k$
step case: using (2) and the IH, $s(k) + 0 = s(k + 0) = s(k)$

## example (2)
lemma: $\forall x, y \in \N. x + y = y + x$
proof: by induction on $x$. Here $P(x)$ is $\forall y \in \N. x + y = y + x$ (note the universal quantifier)
base case: we have to show $\forall y \in \N. k + y = y + k$ (done by previous lemma in example 1)
step case: 
induction hypothesis: $\forall y \in \N. k + y = y + k$
step case: we have to show $\forall y \in \N. s(k) + y = y + s(k)$. let $y \in \N$ be given. using (1) and the IH, we have 
$$ s(k) + y = s(k+y) = s(y + k) = s(y) + k $$

## example (3)
lemma: $\forall y, k \in \N. s(y) + k = y + s(k)$
proof: by induction on $y$
base case: we have to show $\forall k \in \N. s(0) + k = 0 + s(k)$. easy using (1), (2)
induction hypothesis: $\forall k \in \N. s(z) + k = z + s(k)$
step case: we need $s(s(z)) + k = s(z) + s(k)$
with this lemma we can complete the step case of the previous example $\square$