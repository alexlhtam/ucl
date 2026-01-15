# propositional logic
- one of the simplest logics and is in universal usage
- formulas built up from atomic propositions (formal statements) using logical connectives:
  - $\neg$: not
  - $\land$: and
  - $\lor$: lor
  - $\implies$: implies
  - $\iff$: if and only if

- roughly speaking, propositions are the smallest factual statements in an English sentence
- connectives connect propositions together:
  - and, but, or, either, if, unless
- not every sentence can be interpreted as a proposition

## satisfiability and validity
- we write $v \models A$ to mean that $A$ is true in the valuation $v$, and $v \not \models A$
- $A$ is called `satisfiable` if $v \models A$ for `some` valuation $v$, and unsatisfiable otherwise
- $A$ is said to be `valid` if $v \models A$ for `all` valuations $v$, and invalid otherwise