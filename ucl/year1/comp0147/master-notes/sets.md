# set of natural numbers - von Neumann
- natural number = set of all smaller natural numbers
$$
\begin{align}
0 &:= \varnothing \nonumber \\
1 &:= \{0\} = \{\varnothing\} \nonumber \\
2 &:= \{0, 1\} = \{\varnothing, \{\varnothing\}\} \nonumber \\
&\vdots \nonumber \\
n &:= \{0, 1, 2, \dots, n-1\} \nonumber
\end{align}
$$
- the successor of $n$ is defined by $$ S(n):= n \cup \{n\}$$
- arith7metic and induction can be defined purely from set theory;
- foundation for mathematics where numbers are sets

# sets
- an unordered collection of well-defined objects, called `elements` or `members` of the set
- we write $ a \in A$ to indicate $a$ is in set $A$, and $a \notin A$ for the opposite
- it is convention to use uppercase for sets and lowercase for their elements
## ways of defining sets
- listing its elements inside curly braces:
$$
\begin{align}
S_1 &= \{\text{Ana}, \{\text{Bia}\}, \text{Carlos} \} \nonumber \\
S_2 &= \{\text{Jupiter}, \pi, \{200\} \} \nonumber
\end{align}
$$
- specifying a property that defines its elements, as in $S = \{x \vert P(x)\}$