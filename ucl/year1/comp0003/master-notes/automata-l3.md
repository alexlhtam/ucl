# nondeterministic finite automata/NFAs
- NFA = DFA with convenient features:
  - $\epsilon$ transitions: can change states without consuming input
  - multiple arrows with same input can leave a state to different destinations
  - missing arrows okay
- exact same power as DFAs

# example: $\epsilon$ transitions
$\Sigma= \set{a, b}$
create a finite automaton that accepts strings that optionally start with "$baba$" followed by an even number of $b$'s
![alt text](nfa-example-1.png)

# example: substring
$\Sigma = \set{A, \dots, Z, a, \dots, z, 0, \dots, 9}$
create a finite automaton that accepts any string containing "hello" as a substring.
![alt text](nfa-example-2.png)
not a valid DFA (multiple "h" transitions from $q_0$)
don't need backtracking

# nondeterminism
- multiple actions posisble at each state
- trace through them all simultaneously
- or somehow "know" the right path to take all along

# formal definition
An NFA $M$ is a 5-tuple $(Q, \Sigma, \delta, q_0, F)$, where:
- $Q \Sigma, q_0, F$ ... no change
- $\delta: Q \times \Sigma_\epsilon \to \mathcal{P}(Q)$
  - note: $\Sigma_\epsilon = \Sigma \cup \set{\epsilon}$
  - instead of spitting out one single state to go to, it spits out a subset of $Q$ states to go to

# NFA transition function
- NFAs can transition to any number of states when reading an input character.
![alt text](nfa-transition-function.png)

# NFA operation (acceptance)
## definition
NFA $N = (Q, \Sigma, \delta, q_0, F)$ accepts input string $w = w_1 w_2 \dots w_n (w_i \in \Sigma_\epsilon)$ if there exists a sequence of starts $r_0, r_1, \dots, r_n$ such that:
1. $r_0 = q_0$ (start in start state)
2. $r_{i+1} \in \delta(r_i, w_{i+1})$ for $i = 0, \dots, n-1$ (use valid transitions)
3. $r_n \in F$ (end in an accepting state)
- note: $abb, \epsilon abb, a \epsilon b \epsilon b \epsilon \epsilon \epsilon$ are all ways of writing the same string
- accept if there exists a valid path from start state to accepting state for this input string

# equivalent power
- NFAs are exactly as powerful as DFAs (no more and no less)
- proof: want to show any NFA can be implemented as DFA and vice versa
- easy case: any DFA can be implemented as an NFA. Any valid DFA is (pictorially) already a valid NFA. Mathematically, make the outputs of the DFA's transition function into 1-element sets and you have a valid NFA 
- hard case: any NFA can be implemented as a DFA (next)

# converting NFA to DFA
- want to show: any NFA $N$ can be implemented as a DFA $M$
- similar to union proof in automata lecture 2.
- instead of tracking a pair of states, we track which combination of states in our NFA $N$ we might currently be in
- whenever we read in new input, we update that set of states accordingly.
![alt text](nfa-example-1.png)
- at the beginning, having read in NO input, we could either be in state $q_0$ or $q_4$
![alt text](q0-q4-init-state.png)
- after reading a $b$, we could in $q_1$ or $q_5$
- after reading in an $a$, we are in no state (trash)
- from $q_{\set{1, 5}}$, after reading $b$, we could be in $q_4$; after reading an $a$, we could be in $q_2$; reading any $a$'s will land us in $q_\emptyset$
- and so on.