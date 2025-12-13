# relations

## relations in sets
- a relationship between objects can be represented through a `relation`, which is a subset of the Cartesian product of sets
- relations may involve several sets,  but for now we will focus on `binary relations`, which involve only two sets
- let $A$ and $B$ be two sets. A `binary relation` from $A$ to $B$ is a subset of $R$ of the Cartesian product $A \times B$, or more formally:
$$ R \subseteq \set{(x, y) \vert x \in A \land y \in B} $$

- when $(a, b) \in R$ we say that $a$ is related to $b$ via $R$
  - $aRb$ represents $(a, b) \in R$

can also represent relation $R$ in several alternate ways:
- through a `set of ordered pairs` taken from $A \times B$
- through an `arrow diagram` (`directed graph` or `digraph`)
- through a `table` or `Boolean matrix`

## functions as relations
- functions are a special case of relations between sets
- a function $f$ from a set $A$ to set $B$ is a `binary relation` from $A$ to $B$ satisfying the following constraints:
  1. every element $a \in A$ is part of at least one pair in the relation:
    $$ \forall a \in A. \exists b \in B. (a, b) \in f$$
  2. each element $a \in A$ is part of at most one pair in the relation:
    $$ \forall a \in A. \forall b, b' \in B.(a, b) \in f \land (a, b') \in f \rightarrow (b=b')$$

## relations on one set
- relations from a set to itself are of special interest
- a relation on set $A$ is a relation from $A$ to $A$

# properties of relations

## reflexivity
- a binary relation $R$ on a set $A$ is `reflexive` if and only if `each element is related to itself`:
$$ \forall x \in A. (a, a) \in R$$
- all vertices in a graph would have a self loop
- all elements in the matrix on the diagonal would contain a 1

## symmetry
- a binary relation $R$ on set $A$ is `symmetric` if and only if whenever an element is related to a second, that second element is also related to the first
$$ \forall a, b, \in A. (a, b) \in R \rightarrow (b, a) \in R$$
- all vertices with an arrow in between them has another pointing the opposite way
- matrix is symmetric on the diagonal

## antisymmetry
- a binary relation $R$ on a set $A$ is `antisymmetric` if and only if whenever an element is related to a second, the second element is related to the first only if they are equal
$$ \forall a, b \in A.(a, b) \in R \land (b, a) \in R \rightarrow a = b$$
- there are never two arrows in between vertices
- opposite elements with respect to the diagonal cannot both be 1 

## transitivity 
- a binary relation $R$ on a set $A$ is `transitive` if and only if for every element related to a second, if the second is related to a third, then the first is related to the third
$$ \forall a, b, c \in A. (a, b) \in R \land (b, c) \in R \rightarrow (a, c) \in R$$
- whenever there is an indirect path between two vertices, there is also a direct path

## verifying properties of relations
- sometimes we need to prove that a property holds for a relation defined on an infinite set
- let $R$ be a binary relation defined on an infinite set $A$. To prove that $R$ satisfies a certain property we must:
  1. clearly express what must be proven
    for example, for symmetry, we must write that we want to prove that $$ \forall a, b \in A, \text{ if } a R b \text { then } b R a$$ 
  2. Use the definitions of the set $A$ and the relation $R$ to rewrite the property
    for example, for the equality relation on the set of real numbers, we show that $$ \forall a, b \in A. \text{ if } a = b \text{ then } b = a $$therefore equality is a symmetric relation

## combining relations
- representing relations as matrices can make the computation of combined relations easier
- let $R$ be a relation from $A$ to $B$. The `Boolean Matrix` representing $R$ is defined as:
$$ M_R[a, b] = 
\begin{cases}
1, \text{ if } (a, b) \in R \\
0, \text{ if } (a, b) \notin R
\end{cases}
$$
- we can compute union, intersection and difference of relations as 
$$
\begin{align*}
M_{R_1 \cup R_2} &= M_{R_1} \lor M_{R_2} \\
M_{R_1 \cap R_2} &= M_{R_1} \land M_{R_2} \\
M_{R_1 - R_2} &= M_{R_1} \land \neg M_{R_2}
\end{align*}
$$

## composition of relations
- let $R$ be a relation from a set $A$ to a set $B$, and $S$ a relation from set $B$ to a set $C$.
  the `composition relation` of $R$ and $S$ consists of the ordered pairs $(a, c)$ where $a \in A$ and $c \in C$ for which there exists an element $b \in B$ such that $(a, b) \in R$ and $(b, c) \in S$
  the composition of of $R$ and $S$ is denoted by $S \circ R$

- <b>EXAMPLE</b>: let the sets be $A = \set{x, y, z}$, $B = \set{1, 2}$ and $C = \set{\alpha, \beta}$. 
  let $R$ be the relation from $A$ to $B$ and $S$ be the relation from $B$ to $C$ below:
$$
\begin{align*}
    R &= \set{(x, 1), (x, 2), (y, 1), (z, 2) } \\
    x &= \set{(1, \alpha), (1, \beta), (2, \beta)}
\end{align*}
$$

  determine the composite relation $S \circ R$

  <b>SOLUTION</b>: the relation $S \circ R$ is constructed by taking all the ordered pairs in $R$ and all the ordered pairs in $S$ where the second element of the pair in $R$ is the same as the first element of the pair in $S$. Thus, 
  $$ \begin{align*}
    S \circ R = \set{(x, \alpha), (x, \beta), (y, \alpha), (y, \beta), (z, \beta)}
  \end{align*}
  $$
- a relation on a set can be composed with itself
- let $H$ be the set of all people and $F$ be the relation on $H$ such that $(a, b) \in F)$ if and only if $a$ is the son/daughter of $b$
  we can compose $F$ with itself obtaining 
  $$
  F \circ F = \set{(a, c) \in H \times H \vert \exists b . \quad (a, b) \in F \land (b, c) \in F} $$ 
  intuitively, $(a, c) \in F \circ F$ if and only if $a$ is the son/daughter of a son/daughter of $c$, or if $a$ is a grandchild of $c$
- the composition of a relation with itself can be generalised as follows
let $R$ be a relation on set $A$. the powers $R^n$, for $n = 1, 2, 3, \dots,$ are defined recursively as 
$$\begin{cases}
R^1 = R \\
R^{n+1} = R^n \circ R
\end{cases}
$$
thus 
$$\begin{align*}
R^2 &= R^1 \circ R = R \circ R, \\
R^3 &= R^2 \circ R = R \circ R \circ R, \\
R^4 &= R^3 \circ R = R \circ R \circ R\ \circ R, \\
\dots
\end{align*}
$$

## closure of a relation: introduction
- let $R$ be a relation on set $A$
  $R$ may or may not satisfy a certain property $P$ (reflexivity, symmetry, antisymmetry or transitivity)
- intuitively, the `closure of a relation` $R$ `with respect to property` $P$ is the smallest possible relation $S$ that includes $R$ and satisfies property $P$
  - i.e. the closure $S$ is obtained by adding $R$ to the minimum number of elements needed for property $P$ to hold
- formally, $S$ is `the closure of` $R$ `with respect to property` $P$ if these three are satisfied:  
  1. $S$ contains $R$,
  2. $S$ satisfies $P$, and
  3. $S$ is a subset of every other relation that also satisfies conditions $i$ and $ii$

## reflexive closure
- let the relation $R = \set{(1, 1), (1, 2), (2, 1), (3, 2)}$ on the set $A = \set{1, 2, 3}$
find the `reflexive closure` of $R$
solution: $R$ is not reflexive. To make it reflexive while adding the minimum number of elements, we add the pairs $(2, 2)$ and $(3, 3)$, since these are the only pairs of the form $(a, a)$ with $a \in A$ not already in $R$

- the reflexive closure of a relation $R$ on a set $A$ is given by the relation $$S = R \cup \Delta$$ where $\Delta = \set{(a, a) \space \vert \space a \in A}$ is the `diagonal relation` on $A$

## symmetric closure 
- the symmetric closure of a relation $R$ on set $A$ is given by the relation $$ S = R \cup R^{-1}$$ where $R^{-1}$ is the inverse relation of $R$ on $A$, defined as $$ R^{-1} = \set{(b, a) \space \vert \space (a, b) \in R}$$

## transitive closure
- check the pairs

# equivalence relations

## introduction
- there are several situations in which elements of a set are considered equivalent for some purpose
- e.g.
  1) in the standard $C$ language, variable names are considered distinct only up to 8 characters: any variables that agree in the first 8 characters are considered equal
  2) if we are only interested in the remainder of integer division by 3, then there are three types of equivalent integers: those with remainder 0, those with remainder 1, and those with remainder 2
- the examples above are equivalence relations, which partition a set into classes of equivalent elements 
<br/>
- a relation $R$ on a set $A$ is an `equivalence relation` if $R$ is `reflexive, symmetrical and transitive`.
- two elements $a, b \in A$ related by an equivalence relation are called `equivalent`
  we use the notation $a \sim b$ to denote that $a$ and $b$ are equivalent under a given equivalence relation
- for the notion of equivalence to make sense, it is natural to require:
  1. each element is equivalent to itself (reflexivity)
  2. if $a$ is equivalent to $b$, then $b$ is equivalent to $a$ (symmetry)
  3. if $a$ is equivalent to $b$ and $b$ is equivalent to $c$, then $a$ is equivalent to $c$ (transitivity)

## equivalence classes
> an equivalence relation $R$ on a set $A$ divides the elements of this set into classes of elements equivalent to one another
- let $R$ be an equivalence relation a set $A$
  the set of all elements related to an element $a$ of $A$ is called the `equivalence class` of $a$
  the equivalence class of $a$ with respect to $R$ is denoted by $[a]_R$
    - when it is clear from context what relation $R$ refers to, we may omit the subscript $R$ and use only $[a]$ to represent the equivalence class $[a]_R$

## equivalence classes and partitions
- let $R$ be an equivalence relation on set $A$
each equivalence class of $R$ is a subset of $A$
let $a$ and $b$ be any two elements of $A$. the equivalence classes of these elements must satisfy exactly one of the conditions below:
  - $[a] = [b]$: the elements equivalent to $a$ and the elements equivalent to $b$ are exactly the same,

    OR

  - $[a] \cap [b] = \varnothing$: there is no element that is equivalent to both $a$ and $b$ at the same time
- this means that two distinct equivalent classes are always disjoint (have no intersection)
<br>
- a `partition on a set` $A$ is a collection of disjoint subsets of $A$ such that the union of these subsets is the set $A$ itself
- formally, a `partition of a set` $A$ is a collection of subsets $\set{A_1, A_2, \dots, A_n}$ of $A$ such that:
  1. for all $1 \leq 1 \leq i \leq j \leq n, A_i \cap A_j = \varnothing$; and 
  2. $A_1 \cup A_2 \cup \dots \cup A_n = A$
- the central idea of an equivalence relation is precisely to group together elements that are related to one another
equivalence classes and partitions are two sides of the same coin
- let $R$ be an equivalence relation on a set $S$. then:
  1. the equivalence classes of $R$ form a partition of $S$
  2. conversely, given a partition $\set{A_i \space \vert \space i \in I}$ of the set $S$, there exists an equivalence relation $R$ whose equivalence classes are exactly the sets $A_i$, for each $i \in I$

# partial order relations

## introduction

- many times we use relations to define precedence among elements of a set, ordering some (or all) elements of the set
- example of ordering or precedence relations:
  1. relation $(a, b)$ over the reals, where $a \leq b$
  2. relation $(x, y)$ over words, where $x$ precedes $y$ in the dictionary
  3. relation $(t_1, t_2)$ over tasks in a project, in which $t_2$ cannot start before $t_1$
- the above examples are `partial order relations`, which organise all or part of the elements of a set
<br>
> a relation $R$ on a set $A$ is a partial order relation (or partial ordering/partial order) if $R$ is reflexive, antisymmetric and transitive)
- for the notion of partial order to make sense, it is natural to require that:
  1. each element to be related to itself (reflexivity)
  2. the only situation in which an element $a$ precedes an element $b$ and at the same time $b$ precedes $a$ is when $a$ and $b$ are the same element (antisymmetry)
  3. when $a$ precedes $b$ and $b$ precedes $c$, then $a$ must precede $c$ (transitivity)
<br>
> a set $S$ coupled with a partial order $R$ is called a `partially ordered set`, or poset 
- examples of posets:
  1. $\R, \leq$: the set of real numbers with the relation $\leq$
  2. $\Z^+, \vert$: the set of positive integers with the relation "divides"
<br>
> two elements $a$ and $b$ of a poset $(S, \preceq)$ are `comparable` if either $ a \preceq b$ or $b \preceq a$
- otherwise, they are incomparable

> if any two elements $a$ and $b$ of a poset $(S, \preceq)$ are comparable, we say that $S$ is a `totally (or linearly) ordered set`
- in this case, the relation $\preceq$ is called `total order` or `linear order`

## lexicographic order
- let $S$ be a set with partial order relation, $\preceq$
  let $S^*$ be the Cartesian product of $S$ with itself
  one can define a lexicographic order ore dictionary order on the set $S^*$ as follows:
  $$(a_1, a_2, \dots, a_n) \preceq (b_1, b_2, \dots, b_n) \quad \text{ if}$$ 
  1. $m \leq n$ and $a_i = b_i$ for all $ 1 \leq i \leq m$
  2. there exists a $k$ satisfying $1 \leq k \leq \text{min}(m, n)$ such that $a_i = b_i$ for all $1 \leq i \leq k - 1$, and $a_k \preceq b_k$ but $a_k \neq b_k$
  3. if $(a_1, a_2, \times, a_m) = \lambda$ is the empty sequence

## Hasse diagram
- some edges in the graph that represents a partial order do not need ot be drawn, since they must necessarily exist
- a Hasse diagram is a simplification of the graph of a partial order that eliminates obvious edges
  1. loops are not drawn, their presence is inferred from the reflexivity of the partial order
  2. edges whose presence can be inferred by transitivity are omitted
  3. it is assumed that all edges point "upwards", edges are drawn as lines instead of arrows