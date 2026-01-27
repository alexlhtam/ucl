# satisfaction relation
- suppose we have fixed a FO language $\Sigma$, a FO structure $M$ and a valuation $/rho$
- we write $M \models_\rho A$ to mean that $A$ is satisfied (made true) in the structure $M$ under the valuation $\rho$
- we have the following definition for atomic formulas:
$$ M \models_\rho P(t_1, \dots, t_k) \iff (\rho(t_1), \dots, \rho(t_k)) \in P^M $$
- e.g.
$$ 
\begin{align*} 
    M \models_\rho x = y \times z &\iff (\rho(x), \rho(y \times z)) \in =^M \\
    &\iff (\rho(x), \rho(y) \times^M \rho(z)) \in =^M
\end{align*}
$$

# valuation updates
- for any valuation $\rho: \text{Vars} \rightarrowtail D$, any variable $x$ and any $d \in D$, define the "updated" valuation $\rho[x\rightarrowtail d]$ by:
$$ \rho[ x \rightarrowtail d ](y) =_{def} \begin{cases} \end{cases}