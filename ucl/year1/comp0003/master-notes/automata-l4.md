# recursive definition of regular expressions
- definition:
  - a regular expression is any of the following:
    - $a$ for some $a \in \Sigma$
    - $\epsilon$
    - $\emptyset$
    - $(R_1 \cup R_2)$
    - $(R_1 \circ R_2)$
    - $R_1*$

# Regex equivalence with DFAs/NFAs/RLs

## equivalence with DFAs/NFAs
- regexes have the exact same expressive powers as DFAs/NFAs
- proof: two directions:
  - regex -> DFA
  - DFA -> regex

## regex -> DFA
- given a regex, construct a DFA that recognise the exact same strings that the regex allows
- proof: by structural induction, using NFAs:
  - base case:
    1. $a$: single arrow from starting state to accepting state
    2. $\epsilon$: start state is accepting state
    3. $\emptyset$: set of languages that accept nothing (no accepting states)
  - inductive hypothesis: assume a DFA can be constructed for regexes $R_1$ and $R_2$
  - inductive cases:
    1. $(R_1 \cup R_2)$:
    2. $(R_1 \circ R_2)$:
    3. $R_1*$:
    all same as closure proofs!

## DFA -> regex
- need help from another convenience tool: generalise nondeterministic finite automata (GNFAs)
  - transition labels indicate the set of strings (language) that will allow you to get from each state to the next
- special requirements on start and accept state:
  - start state has NO incoming arrows
  - only ONE accept state that has NO outgoing arrows
- to prove DFA -> regex, we will show DFA -> equivalent GNFA -> equivalent two-state GNFA -> single regex

- fix start state to have no incoming arrows
- fix accept state to be singular and with no outgoing arrows
- all missing arrows are assumed to have $\emptyset$ on them

## GNFA -> two-state GNFA
- pick any non-start/accept state to remove $(q_r)$
- for every pair of states $q_i, q_j$ (including when $i = j$) update the label of the transition arrow between them ($R_{i \to j}$) to be: $R_{i \to j} \cup R_{i \to r} \circ R_{r \to r}* \circ R_{r\to j}$
  - "I can either go directly to $q_j$ or I could have gone through $q_r$"

## preservation of acceptance behaviour
- as long as you're careful, removing states this way will accurately preserve the set of strings that get you from one state to another
- takes advantage of regex-like structure to DFas:
  - serial sequence of states linked by arrows - concatenation
  - branching (multiple arrows coming from one state) - union
  - cycles and self-loops - star
- need to be thorough and not miss any 2-transition paths, and always work at the simplest level, removing one state and updating one transition at a time

# summary
- can build an NFA from any regex
- can construct a regex from any DFA
- regular expressions can express the regular languages.

# limits of DFAs/regular languages
## pumping lemma
- theorem:
  - all regular languages $A$ have a length $p$ (pumping length). Any string $s$ in the language longer than this length can be broken into an $s = xyz$ that fulfills the following 3 properties:
    1. $xy^iz \in A$ for any $i \geq 0$ (middle section can be pumped)
    2. $|y| > 0$ (non trivial pumping)
    3. $|xy| \leq p$ (useful trait for later)