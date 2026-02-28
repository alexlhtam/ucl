## alphabets
- alphabets can be arbitrarily large or small

# closure proofs

## DFAs/RLs are closed under certain operations
- if $L_1$ and $L_2$ are regular languages, then:
  - $L_3 = L_1 \cup L_2$ is also a regular language (union)
  - $L_3 = \set{s_1s_2 | s_1 \in L_1 \text{ and } s_2 \in L_2}$ is also a regular language (concatenation)
- if $L$ is a regular language, then:
  - $\overline L = \Sigma * \backslash L$ is also a regular language (complement)
  - $L*$ is also a regular language where $L* = $ the set of finite strings consisting of an arbitrary number of strings in $L$ concatenated together (zero or more) (Kleene star)

## closure
- closure under an operation $=$ applying this operation to a member of the set will always result in another member of the set
- can't start inside the set and end up outside the set after using the operations
- set = regular languages
- operation = union, concatenation, complement, Kleene star, etc.

## complement closure
- given an arbitrary DFA $M$, construct a DFA $N$ that accepts all strings $M$ rejects and rejects all that $M$ accepts
- more generally:
  - given ANY $M = (Q, \Sigma, \delta, q_0, F)$
  - $N$ = complement language = ?
  - $N = (Q, \Sigma, \delta, q_0, Q \backslash F)$

### complement closure proof
- $N$ is the same as $M$ except it accept states $F' = Q \backslash F$. Take an arbitrary string $w$
- when DFA $M$ processes $w$, it either accepts it or not.
- case 1: $w$ is accepted. That means it ended up in accept state $q_f$. Our DFA behaves identically, but now $q_f \not \in F$, so $w$ is rejected by $N$
- case 2: $w$ is not accepted. That means it ended up in non-accepting state $q_i$. That state is an accept state in $N$ so is accepted by $N$
- given a DFA $M$ recognising language $L$, you can always construct a DFA $N$ recognising $\overline L$. RLs are closed under the complement operation. $\Box$

## union closure 
### union closure proof
- given arbitrary DFAs $M_1$ and $M_2$, construct a DFA $N$ that recognises all strings either $M_1$ or $M_2$ does
- pointer to current state in both $M_1, M_2$
- keeps track when they transition
- accept the string at the end of input if EITHER $M_1$ or $M_2$ is in an accepting state
- more formally
  - given $M_1 = (Q_1, \Sigma_1, \delta_1, q_{01}, F_1)$ and $M_2 = (Q_2, \Sigma_2, \delta_2,  q_{02}, F_2)$, define $N$ like so:
    - $Q = Q_1 \times Q_2$
    - $\Sigma = \Sigma_1 \cup \Sigma_2$
    - $\delta((q_1, q_2), y) = (\delta_1(q_1, y), \delta_2(q_2, y))$
    - $q_0 = (q_{01}, q_{02})$
    - $F = \set{(q_1, q_2) | q_1 \in F_1 \text{ OR } q_2 \in F_2}$

## concatenation closure
- given arbitrary DFAs $M_1$ and $M_2$, construct a DFA $N$ that recognises all strings consisting of a string in $L(M_1)$ followed by a string in $L(M_2)$
- look at NFAs next time
