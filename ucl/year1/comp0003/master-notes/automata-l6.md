# property of regular languages

## pumping lemma
- theorem:
  - all regular languages $A$ have a length $p$ (pumping length). Any string $s$ in the language longer than this length can be broken into an $s = xyz$ that fulfills the following 3 properties:
    1. $xy^iz \in A$ for any $i \geq 0$ (middle section can be pumped)
    2. $|y| > 0$ (non trivial pumping)
    3. $|xy| \leq p$ (useful trait for later)

## how do we know this?
- any RL $A$ can be implemented as a DFA $M$
- if $M$ has $n$ states, then $n$ is the pumping length
- any string with at least $n$ characters starts in one state and transitions $n$ times (visiting $n+1$ states)
- by the Pigeonhole Principle at least one state was visited twice, at $q_j$ and at $q_k$
- the path between $q_j$ and $q_k$ can be infinitely traversed (or skipped) to yield pumping behaviour

## summary of this property
- in regular languages, any sufficiently long string can be used to generate an infinite number of strings also in that regular language
- finite regular languages that don't seem to have this property have a pumping length longer than the longest string than the longest string in the languages, and the pumping lemma vacuously holds.

## other features
- $|y| > 0$: we know this because we specified to use a DFA, so at least one character was consumed between $q_j$ and $q_k$, so the pumped string contains at least one character
- $|xy| \leq p$: in the worst case, $q_j$ was the second to last state visited, and $q_k$ was the last
  - $x$ (the part visited up until $q_j$) has length $n-1$ and $y$ has length $1$ $\to$ $|xy| = n$

## why is this useful?
- if all RLs have this feature, we can concretely prove a language is NOT regular by showing this feature does not/cannot hold

# showing a language is not regular
- pumping lemma guarantees that:
    $\forall \text{RL} \space \exists p \text{ s.t.} \space \forall s (|s| \geq p)\space \exists \text{xyz} $ breakdown with properties 1-3
    $A \in \text{RL} \to \exists p \space \text{s.t.} \space \forall s (|s| \geq p) \space \exists \text{xyz}$ breakdown with properties 1-3
- contrapositive $(\neg q \to \neg p)$
    $\neg(\exists p \text{ s.t.} \space \forall s (|s| \geq p)\space \exists \text{xyz} $ breakdown with properties 1-3$)$ \to $A \not \in \text{RL}$
- to prove $A \not \in \text{RL}$, show:
    $\forall p \space \exists s \space (|s| \geq p) \space \text{ s.t. } \forall \text{xyz}$ breakdowns $\exists$ a property that DOESN'T hold

# example: proving non-regularity 
- prove $A = \set{0^n1^n | n \leq 0}$ is not a regular language
- proof: assume arbitrary pumping length $p$. Create an "evil string" of length $\leq p$:
$$0^p 1^p$$
show ALL breakdowns result in one of the properties being broken
- $s = \text{xyz}$, where $y$ only contains $0$s: pumping it would result in more $0$s than $1$s, creating a string NOT in $A$.
- $x = \text{xyz}$, where $y$ only contains $1$s: similar.
- $x = \text{xyz}$. where $y$ contains both $0$s and $1$s: pumping it would result in interleaved $0$s and $1$s, creating a string NOT in $A$
- these are the only possibilities!

  in all cases, the pumping lemma does not hold. Therefore, $A$ could not have been regular in the first place.

# example 
- prove $A = \set{w | w \text{ contains an equal number of 0's and 1's}}$ is not a regular language
- proof: given arbitrary pumping length $p$, we create "evil string" of length $\geq p$ that is in the language: $0^p1^p$ (again)
  assume third property holds: $|xy| \leq p$
  $Y$ can only contain zero(s) because $|xy|$ has to occur in the first $p$ characters of the string (the zero section)
  Pumping $y$ will result in an imbalance of $0$'s and $1$'s that means the resulting strings are NOT in $A$

# summary
- pumping lemma is a property that holds for all regular languages
  - based on underlying implementation of DFAs: member strings exceeding the number of states forces reuse of states (i.e. a cycle i.e. pumpable)
- conclusively show languages are non-regular by showing pumping lemma cannot hold for them
- next time: pushdown automata