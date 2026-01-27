## for each formula below, construct a truth table and then say whether or not the formula is satisfiable, and whether or not it is valid
a) $P$
- trivial

b) $P \land Q$
$$
\begin{array}{c|c|c}
P & Q & P \land Q \\
\hline
0 & 0 & 0 \\
0 & 1 & 0 \\
1 & 0 & 0 \\
1 & 1 & 1
\end{array}
$$
- therefore satisfiable from the 4th row
- not valid because of the rest of the rows

d) $(P \rightarrow Q) \rightarrow (P \land \neg Q) $


e) $P \rightarrow (Q \rightarrow P)$
$$
\begin{array}{c|c|c|c}
P & Q & Q \rightarrow P & P \rightarrow (Q \rightarrow P) \\
\hline
0 & 0 & 1 & 1 \\
0 & 1 & 0 & 1 \\
1 & 0 & 1 & 1 \\
1 & 1 & 1 & 1
\end{array}
$$
- satisfiable as there is a $1$
- valid as all $1$

# 2.1: prove axioms
