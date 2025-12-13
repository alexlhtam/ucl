# relations

## relations in sets
- a relationship between objects can be represented through a `relation`, which is a subset of the Cartesian product of sets
- realtions may involve several sets,  but for now we will focus on `binary relations`, which involve only two sets
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
- a function $f$ from a set $A$ to set $B$ is a `binary relation` from $A$ to $B$ statisfying the following constraints:
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
\begin{align}
M_{R_1 \cup R_2} &= M_{R_1} \lor M_{R_2} \\
M_{R_1 \cap R_2} &= M_{R_1} \land M_{R_2} \\
M_{R_1 - R_2} &= M_{R_1} \land \neg M_{R_2}
\end{align}
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

  <b>SOLUTION</b>: the relation $S \circ R$ is constructde by taking all the ordered pairs in $R$ and all the ordered piars in $S$ where the second element of the pair in $R$ is the same as the first element of the pair in $S$. Thus, 
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
- the compsotion of a relation with itself can be generalised as follows
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
- intuitively, the `closure of a relation` $R$ `with respect to property` $P$ is the smallest possilbe relation $S$ that includes $R$ and satisfies property $P$
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
  3. if $a$ is equivalent to $b$ and $b$ is equivalent to $c$, then $a$ is equivalent to $c$ (transivity)

## equivalence classes
- an equivalence relation $R$ on a set $A$ divides the elements of this set into classes of elements equivalent to one another
- let $R$ be an equivalence relation a set $A$
  the set of all elements related to an element $a$ of $A$ is called the `equivalence class` of $a$
  the equivalence class of $a$ with respect to $R$ is denoted by $[a]_R$
    - when it is clear from context what relation $R$ refers to, we may omit the subscript $R$ and use only $[a]$ to repressent the equivalence class $[a]_R$