# complete induction for $\N$
- complete induction (aka "strong induction") principle:

$$\frac{
    (\forall k' (k' < k \to P(k'))) \to P(k)
  }{
    \forall n \in \mathbb{N}.\ P(n)
  }
  \quad (k \text{ arbitrary})$$

that is, to prove a universal property $P$ of natural numbers:
1. pick some arbitrary $k \in \N$
2. assume $P(k')$ for all $k' < \N$;
3. show that $P(k)$ holds (step case);

this generalises previous induction schemes for $\N$: no explicit base case!

# complete induction example
## theorem
every natural number $n \geq 2$ can be written as a product of prime numbers

## proof
by complete induction $n$

inductive hypothesis: every $n' < n$ (with $n \geq 2$) can be written as a product 

step case: require to prove $n$ is a product of primes. If $n$ is prime then we are done, otherwise $n = m \times k$ where $m, k < n$. By $\text{(IH)}$ both $m, k$ can eb written as a product of primes. therefore so can $m \times k = n$

# Ackermann function
$$\begin{align*}
A(0, y) &= s(y) && (1) \\
A(s(x), 0) &= A(x, s(0)) && (2) \\
A(s(x), s(y)) &= A(x, A(s(x), y)) && (3)
\end{align*}$$
- this function grows fast: e.g. $A(4, 2) = 2^{65536} - 3$

## Lemma
$A(x, y)$ is defined for all $x, y \in \N$

## Proof
- define $(x`, y`) < (x, y) \text{ iff } x` < x \text{ and } y` < y$ (this is called a lexicographic ordering)
- then use complete induction on $(x, y)$, assuming $A(x', y')$, assuming $A(x', y')$ is defined for all $(x', y') < (x, y)$
- now consider cases on $(x, y)$: e.g. in case $(3)$, $A(s(x), y) = z$ (say) is defined by $\text{(IH)}$ since $y < s(y)$.
- then $A(x, z)$ is defined by $\text{(IH)}$ since $x < s(x)$

# infinite descent
- there are no infinite descending chains of natural numbers:
$$n_0 > n_1 > n_2 > \dots$$
- fermat-style infinite descent:
$$\frac{
    \neg P(k) \to \exists k' (k' < k \wedge \neg P(k'))
  }{
    \forall n \in \mathbb{N}.\ P(n)
  }
  \quad (k \in \mathbb{N} \text{ arbitrary})$$
- i.e. if there is a counterexample $k$ to $\forall n. \space P(n)$ then there is a strictly smaller  counterexample $k' < k$, and thus an infinite descending chain of counterexamples $k > k' > k'' > \dots$, a contradiction

# infinite descent: natural evens and odds$
## lemma
every natural number is either even or odd:
$$\forall n \in \N. \space \text{even}(n) \lor \text{odd}(n)$$

## proof
by infinite descent. suppose that some $k \in \N$ is a counterexample, i.e. $\neg(\text{even}(k) \vee \text{odd}(k)) = \neg\text{even}(k) \land \neg\text{odd}(k)$. Clearly $k > 0$, meaning $k = s(k')$ for some $k'$

now, since $\neg \text{even}(s(k'))$, we have $\neg \text{odd}(k')$,
and since $\neg\text{odd}(s(k'))$, we have $\neg \text{even}(k')$
therefore $\neg(\text{even}(k') \lor \text{odd}(k'))$

this gives infinite descent (starting from $k$), a contradiction
therefore $k$ cannot be a counterexample after all $\square$

# infinite descent: rationality of $\sqrt 2$
## theorem
$\sqrt 2$ is not rational. That is: $\neg \exists x, y, \in \N. \space \sqrt 2 = x/y$

## proof
suppose for contradiction that $\sqrt 2 = x/y$ for $x, y \in \N$. Then $x^2 = 2y^2$. 
Consequently $x(x-y) = y(2y - x)$, so that:
$$ \frac{2y - x}{x-y} = \frac{x}{y} = \sqrt 2$$
Define $x'=2y-x$ and $y' = x-y$. Then $x'/y'=\sqrt 2$
Now observe that $1 < x^2/y^2 < 4$, so $y < x <2y$, and so $0 < y' = x - y < y$
But then we have $x', y' \in \N$ such that $\sqrt 2 = x'/y'$, and $y' < y$.
This gives an infinite descent on $y$

# infinite descent $\equiv$ complete induction
infinite descent principle for $\N$:
$$\frac{
    \neg P(k) \to \exists k' (k' < k \wedge \neg P(k'))
  }{
    \forall n \in \mathbb{N}.\ P(n)
  }
  \quad (k \in \mathbb{N} \text{ arbitrary})$$

we can rewrite the premise, using logical equivalences:
$$
\begin{align*}
  & \neg P(k) \to \exists k' (k' < k \wedge \neg P(k')) \\
  \equiv \ & \neg(\exists k' (k' < k \wedge \neg P(k'))) \to \neg\neg P(k) && (\to / \neg) \\
  \equiv \ & \neg(\exists k' (k' < k \wedge \neg P(k'))) \to P(k) && (\neg\neg) \\
  \equiv \ & (\forall k' \neg(k' < k \wedge \neg P(k'))) \to P(k) && (\neg / \exists) \\
  \equiv \ & (\forall k' (k' < k \to P(k'))) \to P(k) && (\neg / \wedge / \to)
\end{align*}
$$
- this gives us complete induction again, and vice versa.