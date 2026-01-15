# what is logic?
- logic is essentially a language for formalising arguments
- a logic typically has three components:
  - a syntax explaining what counts as a formula of the language
  - a semantics explaining how to understand formulae in some domain of discourse (maths, programs, people...);
  - inference rules explaining how to draw conclusions from a collection of premises
$$ \frac{\text{All men are mortal.}\qquad\text{Socrates is a man.}}{\text{Socrates is mortal.}}$$
- inference more focused in second year

# aristotle
formal arguments based on special forms called `syllogisms`
- all men are mortal             (premise)
- Socrates is a man              (premise)
- therefore, Socrates is mortal  (conclusion)

# classical principles
- two fundamental classic principles, dating back to Aristotle:
  - law of non-contradiction
    - two directly contradictory statements cannot be true at the same time 
$$\vdash \neg(A \land \neg A) $$ 
  - law of excluded middle: 
    - every statement either true or false
$$\vdash A \lor \neg A$$

- a logic is inconsistent if it allows one to prove both $A$ and $\neg A$ for some statement $A$

# predicate logic
- 1848-1925, German mathematician Grottlob Frege, developed predicate logic:
$$\begin{align*} &\forall x. \text{  } \text{man}(x) \rightarrow \text{mortal}(x) \\
&\text{man}(\text{Socrates})  \\
&\text{man}(\text{Socrates}) \rightarrow \text{mortal}(\text{Socrates}) \\
&\text{mortal}(\text{Socrates})
\end{align*}
$$
- formal proof:

$$ 
\frac{\text{man}(\text{Socrates})
\qquad \frac{
\forall x .\text{man}(x) \rightarrow \text{mortal}(x) }
{\text{man}(\text{Socrates}) \rightarrow \text{mortal}(\text{Socrates})}}
{\text{mortal}(\text{Socrates})}
$$

- inference rules:
$$
\frac{\forall x \in S . P(x)}{P(B)} B \in S
$$

$$
\frac{A \rightarrow B \qquad A}{B}
$$

# naive set theory
- a very widely used language for the foundations of mathematics
- roughly speaking: "for any property, we can form the set of objects having that property"
- sets can be finite or infinite
- the set of objects having property $P$ is written $\set {x \vert P(x)}$
- $x \in Y$ means object $x$ is a member of set $Y$
- $X \subseteq Y$ means set $X$ is a subset of set $Y$
- virtually all of mathematics can be described using sets

# example of sets 
$$\begin{align*}
&\emptyset \qquad &\text{empty set} \\
&\set{a, b, c, d} &\text{(set of 4 objects)} \\
&\N =_{def} \set{0, 1, 2, 3, \dots} &\text{set of all natural numbers} \\
&\set{n \in \N | n > 3} = \set{4, 5, 6, \dots} \\
&\set{n \in \N | n \text{ is prime}} = \set{2, 3, 5, 7, \dots} \\
&\set{ X | X \subseteq \N } = \set{\emptyset, \set{0}, \set{1}, \set{2}, \dots, \set{0, 1}, \set{0, 2}, \dots ,}
\end{align*}
$$

# logic using sets
- define two sets by
$$
\begin{align*}
Y &= \set{ x | x \text{ is a man}} \\
Z &= \set{x | x \text{ is mortal}}
\end{align*}
$$
- then, we can write down the previous Aristotelian syllogism:
  - $Y \subseteq Z$ (premise)
  - $\text{Socrates} \in Y$ (premise)
  - therefore, $\text{Socrates} \in Z$ (conclusion)