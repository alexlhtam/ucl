# what are automata?
- automaton = something inorganic that acts of its own volition
- little machines: formal (mathematical) definition of certain types
- rigorously understand the power and limits of each type
- DFAs, PDAs, and TMs
  - first two are useful in language processing (used in compilers)
  - last is instantiated by modern computers

# data structure review
## sets
- set: unordered collection of things ($A = \set{x, y, z}$)
- finite list of elements
- OR use set-builder notation for infinite sets
  - ex: $\set{x | x \text{ is a prime number}}$
- empty set: $\emptyset$ (same as writing $\set{}$)

## tuples
- ordered collection of things ($v = (x, y)$)
- two things = duple (or ordered pair)
- three things: triple
- $n$ things = $n$-tuple

## functions
- mapping from a set (domain) to another set (range)
    $ f: D \to R; f(d) = r$

## cartesian product
- combine two sets to get all their tuples
    $(X \times Y = \set{(x,y) | x \in X \text{ and } y \in Y}$)

## power set
- set of all subsets

## graphs
- data structure featuring nodes and edges
- alternate depictions like adjacency matrix
- sometimes directions of edges are important (directed, or digraphs)

# deterministic finite automata (DFAs)

## finite automata
- aka finite state machines (FSM)
- specific type: deterministic finite automata (DFA)

## finite automata: example
![alt text](image.png)
- starting state, accepting state, transitions
- take in any string of input, one character at a time
- at the end, if you're in an accepting state, this is a string the DFA "likes", if not, it's a string the DFA doesn't like
- for example, the string $01101$ is disliked by the above FSM, where as the string $000100100$ is liked.
  - accepts strings with an even number of $1$s
- DFAs track one piece of information: current state
- reading a string always ends the same way
- if no appropriate arrow exists, auto-reject

## finite automata: formal definition
> definition
> a DFA $M$ is a 5-tuple $(Q, \Sigma, \delta, q_0, F)$

$Q$ is a finite set of states
$\Sigma$ is a finite set of input characters (alphabet)
$\delta : Q \times \Sigma \to Q$ is a transition function
- given a state and character, specifies next state to go to

$q_0 \in Q$ is the start state
$F \subseteq Q$ is a set of accept states

### example above
- $Q = \set{q_{\text{even}}, q_{\text{odd}}}$
- $\Sigma = \set{0, 1}$
- $q_0 = q_{\text{even}}$
- $F = \set{q_{\text{even}}}$
- $\delta(q, \sigma)$ = $$ \
\begin{array}{cc|c}
\mathbf{q} & \sigma & \delta \\
\hline
q_{even} & 0 & q_{even} \\
q_{even} & 1 & q_{odd} \\
q_{odd} & 0 & q_{odd} \\
q_{odd} & 1 & q_{even} \\
\end{array}
$$


## simplification
- technically, want function to be defined across its entire domain
- interpret missing transitions to got a "trash" state (new, non-accepting)

## DFA operation (acceptance)
> definition
> DFA $M = (Q, \Sigma, \delta, q_0, F)$ accepts input string $w = w_1w_2...w_n$ if there exists a sequence of states $r_0, r_1, \dots, r_n$ such that:
> 1. $r_0 = q_0$ (start in start state)
> 2. $\delta(r_i, w_{i+1})$ for $i = 0, \dots, n-1$ (use valid transitions)
> 3. $r_n \in F$ (end in an accepting state)

## language
- the language of a DFA is the set of all strings that DFA accepts

## empty string
- can send an empty string into a DFA
- what happens?
- empty strings can also be in a DFA's language
- write as $\epsilon$ rather than "" to avoid confusion

## regular languages
> definition
> regular languages are the set of languages recognised by DFAs
- i.e. language $L \in RL$ iff. there exists a DFA that accepts all $s \in L$ and rejects all $s \not \in L$