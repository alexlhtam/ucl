# modal logic on transitive frames
## definition
A binary relation $R \subseteq W \times W$ is transitive if $Rxy$ and $Ryz$ imply $Rxz$ holds for all $x, y, z \in W$.
A frame $M = (W, R)$ is transitive if $R$ is transitive
## lemma
$\Box A \to \Box\Box A$ is valid in every transitive frame
## proof
Let $M = (W, R)$ be a transitive frame, $\rho$ a valuation, $w \in W$
require to prove:
$$ M, w \models_\rho \space \Box A \to \Box\Box A$$

So assuming $M, w \models_\rho \Box A \space (1)$, we have to show $M, w \models_\rho \Box\Box A$

We have to prove $M, w \models_\rho \Box\Box A$. That means, assuming $Rww'$, we have to prove $M, w' \models_\rho \Box A$
In turn, that means, assuming $Rw'w''$, we have to show $M, w'' \models_\rho A$
Now since $Rww'$ and $Rw'w''$, we have $Rww''$ by transitivity. so by $(1)$, we get $M, w'' \models_\rho A$, as required 
$\Box$


## lemma $(2)$
$\Box A \to \Box\Box A$ is valid only in transitive frame
## proof $(2)$
Supposing $M = (W, R)$ is not transitive, we show $\Box A \to \Box\Box A$ is not valid in $M$
Since $M$ isn't transitive, we have $Rxy$ and $Ryz$ but $\neg Rxz$ for some $x, y, z \in W$. Take $A = P$ and $\rho(P) = W \backslash \set z$
Now $M, x \models_\rho \Box P$ because $P$ is true at all worlds accessible (in one step) from $x$ (it is only false at $z$ and $\neg Rxz$ by assumption)
However, $M, x \not \models_\rho \Box \Box P$ because $P$ is false at $z$, which is accessible in two steps from $x$ ($Rxz$ and $Ryz$). So, the implication is false at $x$.
$\Box$

# modal logic $S4$
Combining the previous two results, we have

# Lemma
$M \models \Box A \to \Box \Box A \iff M \text{ is transitive}$
So again, the transitivity of modal frames is defined by the axiom $\Box A \to \Box \Box A$
One of the most popular modal logics, called $S4$, is the modal logic obtained by taking $\Box A \to A$ and $\Box A \to \Box \Box A$ as axioms, or, equivalently, considering only reflexive-transitive frames
Many other properties of frames can be defined by axioms - and some cannot be.

# Revision overview
## General study suggestions
- revision of lecture materials
- practice past exam paper
- coursework exercises
- consult textbooks and online resources
- peer discussion

## lecture topics
1. propositional logic/boolean algebra
    - syntax of formulas
    - translate to english to propositional formulas and vice versa
    - valuations and truth tables
    - satisfiability and validity
    - logic equivalences
    - disjunctive and conjunctive normal forms
    - definition of a boolean algebra
    - sum of products, sum of sums
2. first-order logic
    - first order languages, terms and formulas
    - translate to english to FOL and vice versa
    - first-order structures and valuations
    - semantics of formulas
    - satisfaction and validity (in a structure)
    - logical equivalences
    - prenex formulas
3. proof by induction
    - ordinary induction over $\N$
    - two step induction over $\N$
    - recursive functions over datatypes (lists, trees, etc.)
    - structural induction over datatypes
    - complete (strong) induction
    - infinite descent
4. modal logic
    - syntax of formulas
    - translate english to modal formulas and vice versa
    - frames and valuations
    - satisfaction and validity (in a frame)
    - logical equivalences
    - frame conditions defined by modal formulas