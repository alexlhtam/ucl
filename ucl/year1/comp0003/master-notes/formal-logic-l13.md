# intro to Modal logic
- modal logic extends propositional logic with new connectives called modalities
  - still much less expressive than first-order logic
- many different modal logics, based on the choice of modalities and interpretations for them
- will examine just the most common one (with some variations)
- here, modalities capture possibility and necessity

# syntax of classical modal logic 
- formulas of modal logic are given by the grammar:
$$
\begin{align*}
  A \ &::= \ P && \text{(proposition)} \\
      &| \quad \neg A \\
      &| \quad (A \wedge A) \\
      &| \quad (A \vee A) \\
      &| \quad (A \to A) \\
      &| \quad (A \leftrightarrow A) \\
      &| \quad \Diamond A && \text{(``possibly'')} \\
      &| \quad \Box A && \text{(``necessarily'')}
\end{align*}
$$
where $P$ ranges over proposition letters
- $\Diamond$ and $\Box$ have higher precedence than binary connectives

# translating English to modal logic
- "it might rain later, and then again it might not"
$$ \Diamond R \land \Diamond \neg R$$
- "if you're in the pub then you must have skipped class"
$$ P \rightarrow \Box S$$
- "it must be possible for me to solve this problem"
$$ \Box \Diamond S $$
- "maybe my death is inevitable"
$$ \Diamond \Box D$$

# semantics of modal logic - frames
- to give a semantics for modal logic, we need to account for possibility ($\Diamond$) and necessity ($\Box$)
- a frame (or Kripke model) is a pair
$$ M = (W, R)$$
where $W$ is a nonempty set (of "worlds"), and $R \subseteq W \times W$ is a binary relation on $W$
- observe that $M = (W, R)$ is actually just a directed graph with vertices $W$ and edges $R$
- we usually write $Rww'$ instead of $(w, w') \in R$, and we say that $w'$ is accessible from $w$

# semantics of modal logic - valuations
- suppose we have fixed a frame $M = (W, R)$
- a valuation for $M$ tells us which propositions are true at which worlds (in $W$)
- formally, a valuation for $M$ is a function from proposition letters (in $L$) to sets of worlds:
$$ \rho : L \rightarrow \text{Pow}(W)$$
- intuitively, $\rho(P)$ is the set of worlds at which $P$ is true

# satisfaction relation
let $\rho$ be a valuation for frame $M = (W, R)$, and let $w \in W$
we write $M, w \models_\rho A$ to mean "A is true at world $w$ (in frame $M$ and valuation $\rho$)". Define $M, w \models_\rho A$ inductively:

$$
\begin{align*}
  M, w \models_\rho P       &\iff w \in \rho(P) \\
  M, w \models_\rho \neg A  &\iff M, w \not\models_\rho A \\
  M, w \models_\rho A \wedge B &\iff M, w \models_\rho A \text{ and } M, w \models_\rho B \\
                            &\ \vdots \\
  M, w \models_\rho \Diamond A &\iff {\color{red}\exists w'} \in W .\ Rww' \mathbin{\color{red}\text{and}} M, w' \models_\rho A \\
  M, w \models_\rho \Box A     &\iff {\color{red}\forall w'} \in W .\ {\color{red}\text{if }} Rww' {\color{red}\text{ then }} M, w' \models_\rho A
\end{align*}
$$

# validity and satisfiability
- $A$ is valid in $M$, written $M \models A$, if $M, w \models_\rho A$ for all possible valuations $\rho$ for $M$ and all $w \in W$
- $A$ is valid, written $\models A$, if it is valid all frames
- a formula $A$ is satisfiable in (frame) $M$ if there is a valuation $\rho$ and $w \in W$ such that $M, w \models_\rho A$
- $A$ is satisfiable if it is satisfiable in some frame
- validity $\implies$ validity in $M$ $\implies$ satisfiability in $M$ $\implies$ satisfiability

# validity example $(1)$
## lemma
$(\Box A \land \Box (A \rightarrow B)) \rightarrow \Box B \text{ is valid }$

## proof
let $M = (W, R)$ be a frame, $\rho$ a valuation, $w \in W$. require to prove:
$$ M , w \models_\rho (\Box A \land \Box (A \rightarrow B)) \rightarrow \Box B$$
so assume $M, w \models_\rho \Box A \space (1)$ and $M, w \models_\rho \Box(A \rightarrow B) \space (2)$. require to prove $M, w \models_\rho \Box B$. This means, assuming $Rww'$, showing that $M, w' \models_\rho B$
Now by $(1)$ and $Rww'$ we have $M, w' \models_\rho A$, and by $(2)$ and $Rww'$ we have $M, w' \models_\rho A \rightarrow B$. Hence, $M, w' \models_\rho B$ as required $\Box$