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

but do we really want this to be invalid? $Box A \implies A$ says "if $A$ is necessary, then it is true", which seems reasonable
in particular, it is equivalent to $A \implies \Diamond A$, "if $A$ is true, then it is possible", which also seems reasonable

- modal logic as defined up to now is (more or less) the simplest and weakest one, commonly called $K$ in the literature
- however, it might be that some principles that we want to be valid (philosophically or practically) are not valid in $K$
- we can get stronger logics, in which more formulas are valid, by requiring that our frames $(W, R)$ satisfy various extra mathematical properties