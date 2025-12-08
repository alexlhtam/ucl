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
    for example, for the equality relation on the set of real numbers, we show that $$ \forall a, b \in A. \text{ if } a = b \text{ then } b = a $$
    therefore equality is a symmetric relation