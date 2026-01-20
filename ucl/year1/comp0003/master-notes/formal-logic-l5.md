# first-order logic

## motivation
- propositional logic is not very expressive:
  - no access to the internal structure of propositions
  - no way of quantifying anything
- cannot explain why many Aristotelian-type arguments are valid
- in propositional logic, we would have to view these as three unrelated propositions

## overview: first-order logic vs propositional logic
- propositions $P$ are replaced by predicate formulas $P(t_1, \dots, t_n)$ where $n \geq 0$
- the arguments $t_i$ of the predicates are terms, formed from variables and function symbols
- we add two quantifiers as logical operators:
  - $\forall x$ "for all $x$, it is the case that..."
  - $\exists x$ "there exists an $x$ such that..."

- to understand whether a predicate formula $P(t1, \dots, t_k)$ is true or false, we have to define what we mean by:
    1. the terms $t_1, \dots, t_k$;
    2. the predicate symbol $P$
- roughly speaking, a model of FOL is an interpretation for all variables, function symbols and predicate symbols
- given a model, we can define the truth value of a formula in that model

## syntax of FOL: first-order languages
- assume an infinite set of variables: $x, y, z, \dots$
- a first-order language $\Sigma$ is given by two components:
  - a set $\mathcal{F} = \set{f_1, f_2, \dots}$ of function symbols, each with an associated arity $k \leq 0$ (number of arguments); a constant symbol is a function symbol of arity 0 
  - a set $\mathcal{P} = \set{f_1, f_2, \dots}$ of function symbols, each with an associated arity $k \leq 0$ (number of arguments); a constant symbol is a function symbol of arity 0 (takes no args)
- we can then write $\Sigma = (\mathcal{F}, \mathcal{P})$

## example: arithmetic
- a version of Peano arithmetic is given by:
  $$ \Sigma_{PA} =_{def} (\set{0, s, +, \times}, \set{=, <})$$

where
$$
\begin{array}{c|c|c|c} 
\text{Symbol} & \text{Arity} & \text{Type} & \text{Usual meaning} \\
\hline
0 & 0 & \text{constant} & \text{zero} \\
s & 1 & \text{function} & \text{successor } (+1) \\
{+} & 2 & \text{function} & \text{addition} \\
\times & 2 & \text{function} & \text{inequality} \\
= & 2 & \text{predicate} & \text{equality} \\
< & 2 & \text{predicate} & \text{inequality}
\end{array}
$$
- we might choose to write binary symbols using infix notation, e.g. $x + y$ instead of $+(x, y)$

## syntax of FOL: terms
- terms of a first-order language $\Sigma$ are given by the following inductive definition:
    1. any variable $x$ is a term;
    2. if $f$ is a function symbol in $\Sigma$ of arity $k$ and $t_1, \dots, t_k$ are terms, then $f(t_1, \dots, t_i)$ is also a term
- e.g. in arithmetic, the following are all terms:
$$ s(0), x + s(y), z \times s(x + s(y))$$
- formulas of a FO language $\Sigma$ are given by the grammar:
  $$
\begin{align*}
A &::= \quad P(t_1, \dots, t_k) &\text{(predicate formula)} \\
&| \quad \neg A &\text{(negation)} \\
&| \quad (A \land A) &\text{(conjunction)} \\
&| \quad (A \lor A) &\text{(disjunction)} \\
&| \quad (A \implies A) &\text{(implication)} \\
&| \quad (A \iff A) &\text{(equivalence)} \\
&| \quad \forall x (A) &\text{(universal)} \\
&| \quad \exists x (A) &\text{(existential)}
\end{align*}
$$
- here, $P$ ranges over predicate symbols (of arity $k$) and $t_1, \dots, t_k$ range over terms of $\Sigma$

## some notational conventions
1. if the outermost connective of a formula is a quantifier then we often write 
$$ \forall x. A \text{ for } \forall x(A) \\ \exists x. A \text{ for } \exists x (A)$$
2. we also apply the usual precedence order for propositional connectives
   1. $\neg$
   2. $\lor$ and $\land$
   3. $\implies$ and $\iff$

## syntax of FOL: free and bound variables
- an occurrence of a variable $x$ in a formula $A$ is called bound if it is within the scope of a quantifier $\forall x$ or $\exists x$. otherwise, the occurrence is free
- a formula with no free variables is called a sentence