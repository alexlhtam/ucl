# first-order structures: overview
- we interpret a language $\Sigma = (\mathcal{F}, \mathcal{P})$ in a first-order structure $M$
- first we pick some set of objects $D$ called the domain
- function symbols $f$ in the language get interpreted as functions $f^M$ in the domain (of correct arity)
- predicate symbols $P$ in the domain get interpreted as relations $P^M$ in the domain (of correct arity)
- the first-order structure is then the tripe $M = (D, \mathcal{F}^M, \mathcal{P}^M)$

# cartesian products of sets
- if $X$ and $Y$ are sets then $X \times Y$ is their cartesian product
$$ X \times Y =_{\text{def}} \set{(x, y) | x \in X \text{ and } y \in D} $$
  - i.e. the set of all pairs of elements from $X$ and $Y$
- if $X$ is a set and $k \in \N$ then we write the abbreviation

$$\begin{align*}
X^k &=_{\text{def}} \overbrace{X \times \dots \times X}^{k \text{ times}} \\
&= \set{(x_1, \dots, x_k) | x_1 \in X, \dots, x_k \in X}
\end{align*}$$

# about relations
- for any $k \geq 0$, a k-ary relation on a set $X$ is a set 
$$ R \subseteq X^k$$
  - i.e. a set of k-tuples in $X$
- examples of relations on $\N$:
$$
\begin{align*}
&\set{n | n \text{ is prime}} &\text{(unary (1-ary) relation)} \\
&\set{(m, n) | \text{m divides n}} &\text{(binary (2-ary) relation)} \\
&\set{(m, n, p) | m \times n = p} &\text{(ternary (3-ary) relation)} \\
&\set{(x_1, \dots, x_k, y) |y = f(x_1, \dots, x_k)} &(k+1\text{-ary relation)} \\
\end{align*}
$$

# first-order structures: formal definition
- a first order structure for a language $\Sigma = (\mathcal{F}, \mathcal{P})$ is a triple 
$$ M = (D, \mathcal{F}^M, \mathcal{P}^M) $$
  - where:
    1) $D$ is a non-empty set (called the domain of $M$)
    2) for each function symbol $f \in \mathcal{F}$ of arity $k$, there is a $k$-ary function $f^M \in \mathcal{F}^M$,
    $$f^M: D^k \rightarrowtail D \qquad (\text{note: if } k = 0 \text{ then } f^M \in D)$$
    3) for each predicate symbol $P \in \mathcal{P}$ of arity $k$, there is a $k$-ary relation $P^M \in \mathcal{P}^M$,
    $$P^M \subseteq D^k$$

# example for arithmetic
$$M =_{\text{def}} (\N, \set{0^M, s^M, +^M, \times^M}, \set{=^M, <^M})$$
- notice that it meets the formal definition:
  - the domain $\N$ is a nonempty set;
  - $0^M$ is an element of $\N$;
  - $s^M$ is a unary (successor) function, of type $\N \rightarrow \N$;
  - $+^M, -^M$ are binary functions, of type $\N \times \N \rightarrowtail \N$
  - $=^M, <^M \subseteq \N \times \N$ are binary relations