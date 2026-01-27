# paradoxes of material implication
- collective name for formulas involving $\implies$ which are valid, but not very intuitive:
- vacuous implication:
$$ B \implies (A \implies B) $$
- paradox of entailment:
$$ \neg A \implies (A \implies B) $$
- other weird-seeming consequences, like
$$ (P \implies Q) \lor (Q \implies R) $$

# relational definition of $\models$
- $v \models A$ can also be defined directly, as a relation
$$
\begin{align*}
v \models P &\iff v(P) = 1 \\
v \models \neg A &\iff v \not\models A \\
v \models A \land B &\iff v \models A \text{ and } v \models B \\
v \models A \lor B &\iff v \models A \text{ or } v \models B \\
v \models A \implies B &\iff v \not\models A \text{ or } v \models B \\
v \models A \iff B &\iff v \not\models A \text{ and } v \models B \text { or } v\not\models A \text{ and } v \not\models B\\
\end{align*}
$$
- it is easy to see that this definition coincides with the definition via truth tables

# minimal set of connectives of propositional logic
- we can define all connectives or propositional logic using just $\neg$ and $\implies$
- the following pairs of formulas are equivalent
$$
\begin{align*}
\neg\neg A &\equiv A \\
A \land B &\equiv B \land A &(\text{same for }\lor) \\
A \land (B \land C) &\equiv (A \land B) \land C &(\text{same for } \lor) \\
A \land (B \lor C) &\equiv (A \land B) \lor (A \land C) \\
A \lor (B \land C) &\equiv (A \lor B) \land (A \lor C) \\
\neg(A \lor B) &\equiv \neg A \land \neg B \\
\neg(A \land B) &\equiv \neg A \lor \neg B \\
A \implies B &\equiv \neg A \lor B \\
\neg (A \implies B) &\equiv A \land \neg B \\
A \implies B &\equiv \neg B \land \neg A \\
A \iff B &\equiv (A \implies B) \land (B \implies A)
\end{align*}
$$

# DNF formulas
- disjunctives normal form (DNF) formulas $D$ are in a special form, given by:
$$
\begin{align*}
    L &::= P | \neg P &\text{("literal")} \\
    C &::= L | L \lor C &\text{("conjunctive clause")} \\
    D &::= (C) | (C) \lor D &\text{("DNF")}
\end{align*}
$$
- example of a DNF:
$$ (P \land \neg Q \land R) \lor Q \lor (\neg P \land \neg R)$$
- every formula can be converted into an equivalent DNF formula

# applications of DNF
- useful for deciding (un)satisfiability of formulas:
  - given $A$, convert it to a DNF, say
$$ C_0 \lor C_1 \lor \dots C_{n-1} $$
  - note $A$ is satisfiable iff some $C_i$ is satisfiable. each $C_i$ is of the form
$$ L_{i, 0} \land L_{i, 1} \land \dots \land L_{i, m-1}$$
  - $C_i$ is satisfiable iff it doesn't contain $P$ and $\neg P$ for some $P$
- can also decide (in)validity, using the fact that $A$ is valid iff $\neg A$ is unsatisfiable

# extracting DNF from truth tables
- e.g. for $P \iff (\neg Q \implies R)$:
$$
\begin{array}{c|c|c|c|c}
P & Q & R & \neg Q \implies R & P \implies(\neg Q \implies R) \\
\hline
0 & 0 & 0 & 0 & 1 \\
0 & 0 & 1 & 1 & 0 \\
0 & 1 & 0 & 1 & 0 \\
0 & 1 & 1 & 1 & 0 \\
1 & 0 & 0 & 0 & 0 \\
1 & 0 & 1 & 1 & 1 \\
1 & 1 & 0 & 1 & 1 \\
1 & 1 & 1 & 1 & 1 
\end{array}
$$
DNF: 
$(\neg P \land \neg Q \land \neg R) \lor (P \land \neg Q \land R) \lor (P \land Q \land \neg R) \lor (P \land Q \land R)$

# construct DNF using logical equivalences
- remove $\iff$:
  - $A \iff B \equiv (A \implies B) \land (B \implies A)$
- remove $\implies$:
  - $A \implies B \equiv \neg A \lor B \text{ and } \neg(A \implies B) \equiv A \land \neg B $
- move negations inwards:
  - $\neg \neg A \equiv A$
  - $\neg(A \land B) \equiv \neg A \lor \neg B$
  - $\neg(A \lor B) \equiv \neg A \land \neg B$
- move disjunctions outwards:
  - $A \land (B \lor C) \equiv (A \land B) \lor (A \land C)$

# CNF
- conjunctive normal form is an "inverse" of DNF
$$
\begin{align*} 
    D &::= L | L \lor D &\text{("disjunctive clause")} \\
    C &::= (D) | (D) \land C &\text{("CNF)}
\end{align*}
$$
- every formula has a CNF equivalent
- can't read a CNF directly off a truth table, but can use equivalences
- CNF is quite useful for theorem proving ($A$ is valid iff every clause of the CNF is valid)