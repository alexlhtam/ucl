# validity example (2)
## lemma
$ \neg \Box \iff \Diamond \neg A$ is valid.
## proof
let frame $M = (W, R)$, valuation $\rho$ and $w \in W$ be arbitrary. We need to show $M, w, \models_\rho \neg \Box A$ iff $M, w \models_\rho \Diamond \neg A$

$$
\begin{align*}
       & M, w \models_\rho \neg\Box A \\
  \iff & M, w \not\models_\rho \Box A \\
  \iff & \text{not } (\forall w' \in W .\ Rww' \text{ implies } M, w' \models_\rho A) \\
  \iff & \exists w' \in W .\ Rww' \text{ but } M, w' \not\models_\rho A \\
  \iff & \exists w' \in W .\ Rww' \text{ and } M, w' \models_\rho \neg A \\
  \iff & M, w \models_\rho \Diamond \neg A
\end{align*}
$$

# invalidity example
## lemma
$\Box A \implies \Diamond A$ is NOT valid
## proof
we have to find a formula $A$, a frame $M = (W, R)$, a valuation $/rho$ and a $w \in W$ such that $M, w \models_\rho \Box A$ but $M, w \not \models_\rho \Diamond A$

take $M = (\set w, \emptyset)$ where $\emptyset$ is the empty relation. 
then, trivially, $M, w \models_\rho \Box A$ is true (because there are no $w'$ with $Rww'$), 
whereas $M, w \models_\rho \Diamond A$ is false (for the same reason)
$\Box$

# motivating different modal logics
## lemma
$\Box A \implies A$ is not valid
## proof
almost the same counterexample as before will work
take $M = (\set w, \emptyset)$ as before, and now choose $A = P$, a proposition, and $\rho(P) = \emptyset$. Now, $M, w \models_\rho \Box P$ is still true, but $M, w \not \models_\rho P$, because $w \not \in \emptyset = \rho(P)$ 
$\Box$

but do we really want this to be invalid? $\Box A \implies A$ says "if $A$ is necessary, then it is true", which seems reasonable
in particular, it is equivalent to $A \implies \Diamond A$, "if $A$ is true, then it is possible", which also seems reasonable

- modal logic as defined up to now is (more or less) the simplest and weakest one, commonly called $K$ in the literature
- however, it might be that some principles that we want to be valid (philosophically or practically) are not valid in $K$
- we can get stronger logics, in which more formulas are valid, by requiring that our frames $(W, R)$ satisfy various extra mathematical properties

# nodal logic on reflexive frames
## definition
a binary relation $R \subseteq W \times W$ is reflexive if $Rww$ for all $w \in W$
a frame $M = (W, R)$ is reflexive if $R$ is reflexive
## lemma
$\Box A \to A$ is valid in every reflexive frame
## proof
let $M = (W, R)$ be a reflexive frame, $\rho$ a valuation, $w \in W$. we have to show that if $M, w \models_\rho \Box A$ then $M, w \models_\rho A$
Supposing $M = (W, R)$ is not reflexive, we must show $\Box A \to A$ is not valid in $M$. That is, we need a formula $A$, valuation $\rho$ and $w \in W$ such hat $M, w \models_\rho \Box A$ but $M, w \not \models_\rho A$
Since $M$ is not reflexive, there exists $w \in W$ such that $Rww$ does not hold. Take $A = P$ and valuation $\rho(P) = W \backslash \set{W}$
By construction, $w \not \in \rho(P)$, so $M, w \not \models_\rho P$. But we do have $M, w \models_\rho \Box P$ because $P$ holds at all worlds except $w$ (which isn't accessible from $w$).
Combining the previous two results, we have
## lemma
$M \models \Box A \to A \iff M \text{ is reflexive}$
- so there is no difference between $(a)$ restricting frames to be reflexive and $(b)$ taking $\Box A \to A$ to be an axiom of modal logic: either forces the other.