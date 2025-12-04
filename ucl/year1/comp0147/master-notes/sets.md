# set of natural numbers - von Neumann
- natural number = set of all smaller natural numbers
$$
\begin{align}
0 &:= \varnothing \nonumber \\
1 &:= \{0\} = \{\varnothing\} \nonumber \\
2 &:= \{0, 1\} = \{\varnothing, \{\varnothing\}\} \nonumber \\
&\vdots \nonumber \\
n &:= \{0, 1, 2, \dots, n-1\} \nonumber
\end{align}
$$
- the successor of $n$ is defined by $$ S(n):= n \cup \{n\}$$
- arith7metic and induction can be defined purely from set theory;
- foundation for mathematics where numbers are sets

# sets
- an unordered collection of well-defined objects, called `elements` or `members` of the set
- we write $ a \in A$ to indicate $a$ is in set $A$, and $a \notin A$ for the opposite
- it is convention to use uppercase for sets and lowercase for their elements
## ways of defining sets
- listing its elements inside curly braces:
$$
\begin{align}
S_1 &= \{\text{Ana}, \{\text{Bia}\}, \text{Carlos} \} \nonumber \\
S_2 &= \{\text{Jupiter}, \pi, \{200\} \} \nonumber
\end{align}
$$

- specifying a property that defines its elements, as in $S = \{x \vert P(x)\}$
$$ S_3 = \{x \in \R \vert -2 \leq x \leq 5\} $$

- using a recursive definition
$$
\begin{cases}
1 \in S_5 \\
\text{if } x \in S_5 \text{ and } x + 5 < 10, \text{ then } x + 2 \in S_5
\end{cases}
$$

- defining a characteristic function
$$
\mu_a(x) = \begin{cases}
1, \text{ if } x \in \N \text{ and } x \text{ is prime} \\
0, \text{ otherwise}
\end{cases}
$$

## some important sets
1. $\N$: the set of natural numbers
2. $\Z$: the set of integers
3. $\N^* = \Z^+$: the set of positive integers
4. $Q = { \frac{p}{q} \vert p \in \Z, q \in Z, q \neq 0 }$: the set of rational numbers
5. $\R$: the set of real numbers
6. $\R^*$: the set $\R$ not including 0
7. $\R_+$: the set of non-negative real numbers
8. $C$: the set of complex numbers

## set equality
- two sets are equal `if and only if` they contain the same elements:
$$ A = B \longleftrightarrow \forall x : (x \in A \leftrightarrow x \in B) $$
- this implies that:
  - the order in which elements are listed is irrelevant
  - the cardinality of elements in a set is irrelevant
    - i.e. $ \{a, a, a, a, b\} = \{a, b\}$

## subset
- $A$ is a subset of $B$ ($A \subseteq B$) `if and only if` every element of $A$ is also an element of $B$
$$ A \subseteq B \longleftrightarrow \forall x : (x \in A \rightarrow x \in B)$$
- $A$ is a `proper subset` of $B$ ($A \in B$) `if and only if` every element of $A$ is in $B$, but one element of $B$ is not in $A$ (i.e. $A \neq B$)

## the empty set
- the empty set contains no elements ($\{\} \text{ or } \varnothing$)
- theorem: the empty set is a subset of `every` set
    proof: let $A$ be any set; then $$ \forall x : (x \in \varnothing \longrightarrow x \in A) $$
    is true by vacuity, since the premise of the implication is always false.
    hence, $\varnothing \in A$