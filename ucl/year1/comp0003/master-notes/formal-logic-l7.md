# valuations
- a valuation for $M = (D, \mathcal{F}^M, \mathcal{P}^M)$ is a function interpreting variables as elements of $D$:
$$ \rho: \text{Vars} \rightarrowtail D $$
- we extend valuations to interpret terms as follows:
$$ \rho(f(t_1, \dots, t_k)) =_\text{def} f^M(\rho(t_1), \dots, \rho(t_k)) $$
- the effect is that in $\rho(t)$ all variables $x$ are interpreted as $\rho(x)$ and all function symbols are interpreted as $f^M$

# valuations: example
- let $M = (\N, \set{0^M, s^M, +^M, \times^M}, \set{=^M, <^M})$
- let $\rho : \text{Vars} \rightarrowtail \N$ be a valuation of $M$ such that
$$ \rho(x) = 5, \rho(y) = 8, \text{ and } \rho(z) = 3$$
- the term $x \times s(s(y)+z)$ is interpreted in $\rho$ as follows:

$$\begin{align*} 
\rho(x \times s(s(y)+z)) &= \rho(x) \times^M s^M(s^M(\rho(y)) +^M \rho(z)) \\
&= t \times^M s^M(s^M(8) +^M 3) \\
&= 5 \times^M 13 = 65 
\end{align*} $$

# satisfaction relation
- suppose we have fixed a first-order language $\Sigma$, a first-order structure $M$ and a valuation $\rho$
- we write $M \models_p A$ to mean that $A$ is satisfied (made true) in the structure $M$ under the valuation $\rho$
- we have the following definition for atomic formulas:
$$ M \models_\rho P(t_1, \dots, t_k) \iff (\rho(t_1), \dots, \rho(t_k)) \in P^M$$
- e.g.,
$$\begin{align*}
M \models_\rho x = y \times z &\iff (\rho(x), \rho(y \times z)) \in =^M \\
&\iff (\rho(x), \rho(y) \times^M \rho(z)) \in =^M \\
\end{align*}$$

# valuation updates
- for any valuation $\rho: \text{Vars} \rightarrowtail D$, any variable $x$ and any $d \in D$, defined the "updated" valuation $\rho[x \rightarrowtail d]$ by:
$$ \rho[x \rightarrowtail d](y) =_\text{def} \begin{cases} \begin{align*}d \qquad &\text{if } x = y \\
\rho(y) \quad &\text{otherwise}\end{align*}
\end{cases} $$


- I.e. $\rho[x \rightarrowtail d]$ is exactly like $\rho$, except that its maps $x$ to $d$
- we will need this to interpret quantifiers

# definition of $M \models_\rho A$
$$ \begin{align*}
M \models_\rho(t_1, \dots, t_k) &\iff (\rho(t_1), \dots, \rho(t_k)) \in P^M \\
M \models_\rho \neg A &\iff M \not \models_\rho A \\
M \models_\rho A \land B &\iff M \models_\rho A \text{ and } M \models_\rho B \\
M \models_\rho A \lor B &\iff M \models_\rho \text{ or } M \models_\rho B \\
M \models_\rho A \rightarrow B &\iff M \not \models_\rho A \text{ or } M \models_\rho B \\
M \models_\rho A \leftrightarrow B &\iff M \models_\rho A \text{ and } M \models_\rho B, \text{ or } M \not \models_\rho A \text{ and } M \not \models_\rho B \\
M \models_\rho \forall x(A) &\iff M \models_{\rho[x\rightarrowtail d]} A \text{ for all } d \in D \\
M \models_\rho \exists x(A) &\iff M \models_{\rho[x\rightarrowtail d]} A \text{ for some } d \in D \\
\end{align*}
$$

# example of quantifier satisfaction
- let $M = (\N, \dots)$ as before, and $\rho$ be a valuation for $M$, then:
$$ \begin{align*}
&M \models_\rho \exists x.0 < x \\
\iff &M \models_{\rho [x \rightarrowtail n]} 0 < x \text{ for some } n \in \N \\
\iff &(\rho [x \rightarrowtail n](0), \rho [x \rightarrowtail n](x)) \in <^M \text{ for some } n \in \N \\
\iff &(0^M, n) \in <^M \text{ for some } n \in \N \\
\iff &0 < n \text{ for some } n \in \N \\
\iff &\text{TRUE}
\end{align*}$$

# satisfiability and validity
- $A$ is valid in $M$, written $M \models A$, if $M \models_\rho A$ for all possible valuations $\rho$ for $M$
- $A$ is valid, written $\models A$, if it s valid in all structures
- A formula $A$ is satisfiable in (structure) $M$ if there is a valuation $\rho$ such that $M \models_\rho A$