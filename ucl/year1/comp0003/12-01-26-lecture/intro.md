# contents
1. overview with some history
2. propositional logic
   1. boolean algebra
3. first order logic
4. proof by induction
5. modal logic

# what is logic?
- logic is essentially a language for formalising arguments
- a logic typically has three components:
  - a syntax explaining what counts as a formula of the language
  - a semantics explaining how to understand formulae in some domain of discourse (maths, programs, people...);
  - inference rules explaining how to draw conclusions from a collection of premises
$$ \frac{\text{All men are mortal.}\qquad\text{Socrates is a man.}}{\text{Socrates is mortal.}}$$
- inference more focused in second year

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

<br>

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

# Russel's paradox
- consider the set of all sets that do not contain themselves:
  $$ R = \set {X \vert X \notin X} $$
- if $R \in R$ then $R \notin R$, and if $R \notin R$ then $R \in R$:
  - this is Russel's paradox, showing naive set theory to be inconsistent

# Hilbert's programme
- Hilbert's Programme (1920) aimed to find a logical system for all of mathematics which was 
  1. provably consistent (no contradiction is provable);
  2. complete (every true statement is provable)

# Godel's incompleteness theorem
- godel's famous incompleteness theorem showed that any logical statement that can describe arithmetic over $\N$ must either be:
  - incomplete (some statements are not provable), or else
  - inconsistent (a contradiction is provable)
- this rendered Hilbert's programme unachievable

# Alan Turing
- theoretical Turing machines (1936) were essentially stored-program computers with infinite memory and a very simple set of instructions
- Turing machines can describe all known computation
- all other notions fo computability have turned out to be equivalent to "computable by Turing machine"

## undecidability of the halting problem
- Halting problem:  given a program $P$ and an input $I$, decide whether $P$ halts when run on $I$
- Turing showed that using logic, this problem is undecidable
- there is no general algorithm for deciding whether programs terminate on a given input

# Hoare triples
- proposed (1969) a logic for reasoning about the correctness of computer programs, based on Hoare triples
$$ \set {A} C \set{B} $$
where $C$ is a program and $A$, $B$ are logical formulas describing the memory state (e.g. "$x = 1 \land y < 2$")

## Hoare logic for verification
- $\set{A} C \set{B}$ means that if the program $C$ is run in a memory state satisfying $A$ then, if it terminates, it final memory state satisfies $B$
- we can use this to construct a logical proof that a program has a particular property: this is called program verification
- recent advances have made it possible to do this for very large programs