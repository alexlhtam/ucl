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

## power set
- given the set $A$, the power set of $A$ ($\mathcal{P}(A)$) is the set of all subsets of $A$
- theorem: if a finite set $A$ has $n$ elements, then $\mathcal{P}(A)$ has $2^n$ elements
proof: to form any subset $S$ of $A$, we can go through each element $a_i \in A$ ($ 1 \leq i \leq n)$, deciding whether $a_i \in S$ or $a_i \notin S$
since each element has two options (belongs or does not belong0 and there are $n$ elements in $A$, there are $2^n$ ways to form a subset $S$ of $A$
thus, $|\mathcal{P}(A)| = 2$

## tuples
- a tuple is a collection of objects where the `order matters` and `repetitions are allowed`
- we denote tuples by enclosing their elements in parentheses:
$$ (x_1, x_2, \dots, x_n) $$
- a tuple containing two elements is called a pair (or ordered pair); a tuple with three elements is a triple, and so on
- tuples are equal if and only if they have the `same number of elements` and the `corresponding elements are equal`
$$ (a_1, a_2, \dots, a_n) = (b_1, b_2, \dots, b_n) \longleftrightarrow \forall i, a_i = b_i $$
- tuples can have elements that are themselves sets, tuples, or other objects

## Cartesian product
- given two sets $A$ and $B$, the Cartesian product of $A$ and $B$ ($A \times B$) is the set of all ordered pairs ($a$, $b$) such that $a \in A$ and $b \in B$
- note that in general:
$$ A \times B \neq B \times A $$
- the Cartesian produc tof more than two sets can be defined analogously:
$$ A_1 \times A_2 \times \dots \times A_n = \{(a_1, a_2, \dots, a_n \vert a_i \in A_i, 1 \leq i \leq n \} $$
- if any of the sets is empty, the Cartesian product is also empty

# operation on sets
- let $A$ and $B$ be subsets of the universal set $U$:
  - `union`: 
    - $A \cup B = x \in U | x \in A \lor x \in B$
    - $x \in A \cup B \longleftrightarrow x \in A \lor x \in B$
  - `intersection`:
    - $A \cap B = x \in U \vert x \in A \land x \in B$
    - $x \in A \cap B \longleftrightarrow x \in A \land x \in B$
  - `difference`:
    - $A - B = x \in U \vert x \in A \land x \notin B$
    - $x \in A - B \longleftrightarrow x \in A \land x \notin B$
  - `complement`:
    - $\bar A = x \in U \vert x \notin A$
    - $x \in \bar A \longleftrightarrow x \notin A$

## equality of sets
- a way to show two sets are equal is to show that `each set is a subset of the other`
  $$ A = B \text{ iff } \forall x: (x \in A \leftrightarrow x\in B)$$
- theorem: $ A = B $ iff $A \subseteq B$ and $B \subseteq A$
  proof: writing $A \subseteq B$ and $B \subseteq A$ formally:
  $$\begin{align}
    &A = B \\
    \equiv \quad &\forall x : (x \in A \leftrightarrow x \in B) \\
    \equiv \quad &\forall x : ((x \in A \rightarrow x \in B) \land (x \in B \rightarrow x \in A)) \\
    \equiv \quad &(\forall x : (x \in A \rightarrow x \in B)) \land (\forall x : (x \in B \rightarrow x \in A)) \\
    \equiv \quad &A \subseteq B \land B \subseteq A
  \end{align}
  $$
  - 2: definition of equality
  - 3: definition of $\leftrightarrow$
  - 4: distributivity of $\forall$ over $\land$
  - 5: definition of $\subseteq$

## disjoint sets
- two sets are called disjoint if and only if they have no elements in common: 
$$ A \text{ and } B \text{ are disjoint } \longleftrightarrow A \cap B = \varnothing $$
- the sets $A_1, A_2, \dots, A_n$ are called mutually disjoint if and only if $A_i \cap A_j = \varnothing$ for all $i, j = 1, 2, \dots, n$ and $i \neq j$
- a collection of non-empty sets ${A_1, A_2, \dots, A_n}$ is a `partition` of set $A$ if and only if 
i) $A = A_1 \cup A_2 \cup \dots \cup A_n$ and 
ii) $A_1, A_2, \dots, A_n$ are mutually disjoint
- $\set{\set{1, 2, 5}, \set 3, \set 4}$ is a partition of $\set{1, 2, 3, 4, 5}$