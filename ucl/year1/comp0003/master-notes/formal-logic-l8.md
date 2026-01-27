# substitution
- if $A$ is a formula, $x$ a variable and $t$ a term then we write $A[t/x]$ for the formula obtained from $A$ by replacing all free occurrences of $x$ by $t$. Examples:
$$ \begin{align*} 
(\exists x. P(x, y) \land Q(y, x))[t/x]\quad &= \exists x. \quad P(x, y) \land Q(y, x) \\
(\exists x. P(x, y) \land Q(y, x))[t/y]\quad &= \exists x. \quad P(x, t) \land Q(t, x) \\
((\exists x P(x, y)) \land Q(y, x))[t/x]\quad &= (\exists x P(x, y)) \land Q(y, t)
\end{align*}$$
- however, we have to watch for accidental free variable capture by a binder, e.g.:
$$ (\exists x. x \neg y)[x/y] = \exists x . x \neq x$$
- this behaviour is never wanted and we shall assume that we only use "good" substitutions

# equivalences
- two formulas $A$ and $B$ are equivalent, written $A \equiv B$, if, for any $M$ and $\rho$, $M \models_\rho A \iff M \models_\rho B$.
- all propositional equivalences of FOL too
- some basic, useful equivalences for quantifiers:
$$\begin{align*}
\forall x \forall y A \quad &\equiv \quad \forall y \forall x A \\
\exists x \exists y A \quad &\equiv \quad \exists y \exists x A \\
\forall x A \quad &\equiv \quad \forall z (A[z/x]) \\
\exists x A \quad &\equiv \quad \exists z(A[z/x]) \\
\forall x A \quad &\equiv \quad \text{ if } x \text{ does not occur free in } A \\
\exists x A \quad &\equiv \quad \text{ if } x \text{ does not occur free in } A \\
\neg \forall x A \quad &\equiv \quad \exists x \neg A \\
\neg \exists x A \quad &\equiv \quad \forall x \neg A \\
\forall x (A \land B) \quad &\equiv \quad (\forall x A) \land (\forall x B) \\
\exists x(A \lor B) \quad &\equiv \quad (\exists x A) \lor (\exists x B) \\
\forall (A \lor B) \quad &\equiv \quad (\forall x A) \lor B \quad \text{if } x \text{ does not occur free in } B \\
\exists (A \land B) \quad &\equiv \quad (\exists x A) \land B \quad \text{if } x \text{ does not occur free in } B
\end{align*}$$
- some notable non-equivalences:
$$\begin{align*}
\forall x \exists y A &\not \equiv \exists y \forall x A \\
\forall x(A \lor B) &\not \equiv (\forall x A) \lor (\forall x B) \\
\exists x(A \land B) &\not \equiv (\exists x A) \land (\exists x B)
\end{align*}$$

# prenex formula
- prenex formulas are in a special form, given by:
  $$ Q_0 x_0 Q_1 x_1 Q_2 x_2 \dots Q_k x_k A $$
where $k \geq 0$, each $Q_i$ is either $\forall$ or $\exists$, and $A$ is a quantifier-free formula
- in other words, all the quantifiers are on the outside of the formula
- fact: every formula can be converted into an equivalent prenex formula