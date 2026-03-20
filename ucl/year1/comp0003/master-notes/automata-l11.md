# pumping lemma examples and introduction to Turing machines

## review: pumping lemma for CFLs
For any CFL $A$, there exists pumping length $p$ such that any $s \in A$ with $|s| \geq p$ can be split into $s = uvxyz$ with:
1. $uv^ixy^iz \in A$ for all $i \geq 0$
2. $|vy| > 0$
3. $|vxy| \leq p$

Pumping length $p = b^{n+1}$ where $b$ = branching factor, $n$ = number of variables.

### concrete example
For the algebraic expression grammar:
- $E \to E \; Op \; E \mid (E) \mid Var$
- $Op \to + \mid - \mid * \mid \div$
- $Var \to x \mid y \mid z$

Here $b = 3$, $n = 3$, so $p = 3^4 = 81$. Any string of 81+ terminals is guaranteed to be pumpable.

---

## example 1: $L = \{a^i b^j c^k \mid 0 \leq i \leq j \leq k\}$ is not context-free

Given arbitrary $p$, choose $s = a^p b^p c^p$ (clearly $s \in L$ and $|s| \geq p$).

Since $|vxy| \leq p$, the window $vxy$ can touch at most 2 of the 3 segments.

**Case 1**: $v$ or $y$ contains two character types.
- pumping up creates interleaved characters (e.g. `abab`), breaking the $a^*b^*c^*$ pattern

**Case 2**: $v$ and $y$ contain only a's or b's (no c's).
- pump **up**: more a's or b's than c's, so $i \leq j \leq k$ breaks

**Case 3**: $v$ and $y$ contain only b's or c's (no a's).
- pump **down**: fewer b's or c's than a's, so $i \leq j \leq k$ breaks

**Case 4**: $v$ and $y$ contain only a's or only c's.
- pump up: more a's than b's. Pump down: more b's than c's. Either way, broken.

All cases fail, so $L$ is not a CFL.

---

## example 2: $L = \{ww \mid w \in \{0,1\}^*\}$ is not context-free

The string $0^p 1 0^p 1$ works for the RL pumping lemma but **not** here (it can be pumped in the CFL sense).

Instead, use $s = 0^p 1^p 0^p 1^p$.

The midpoint of $s$ falls between the first block of 1's and the second block of 0's.

**Case 1**: $vxy$ falls entirely in the first half (or entirely in the second half).
- pumping up adds at most $p$ characters, shifting the midpoint so the two halves start with different characters (one starts with 0, the other with 1). Not in $L$.

**Case 2**: $vxy$ straddles the midpoint.
- since $|vxy| \leq p$, the first-half portion can only contain 1's and the second-half portion can only contain 0's
- pump **down**: fewer 1's in the first half than the second, and fewer 0's in the second half than the first. Even accounting for the shifted midpoint, the two halves can't be equal. Not in $L$.

All cases fail, so $L$ is not a CFL.

---

## CFLs vs non-CFLs summary

| CFL | Not a CFL |
| --- | --- |
| $\{ww^R \mid w \in \Sigma^*\}$ (palindromes) | $\{ww \mid w \in \Sigma^*\}$ (repeated string) |
| $\{a^n b^n \mid n \geq 0\}$ | $\{a^n b^n c^n \mid n \geq 0\}$ |
| $\{a^i b^j \mid 0 \leq i \leq j\}$ | $\{a^i b^j c^k \mid 0 \leq i \leq j \leq k\}$ |

Intuitively: a PDA's stack can match **one** pair of things (e.g. count a's then match b's), but not **two independent constraints** simultaneously.

---

## language hierarchy so far
![](resources/al11-hierarchy.png)

- regular languages $\subset$ context-free languages $\subset$ ???
- RLs: DFAs = NFAs = regex
- CFLs: PDAs = CFGs
- some languages are not context-free — need something more powerful

---

## power of automata
- **DFAs/NFAs**: memory = current state only. Would need infinite states to store arbitrary data.
- **PDAs**: infinite storage via a stack, but only one point of access (the top).
- **next step**: infinite storage with **free access** anywhere → Turing machines.

---

## Turing machines (TMs)

### intuition
Like a DFA, but with:
1. an **infinite tape** (replaces the input stream — input is written on the tape initially)
2. a **read/write head** that can move left or right

At each step: read the character under the head, optionally replace it, move head left or right.

![](resources/al11-tm-example.png)

### acceptance and rejection
- TMs have a single **accept state** and a single **reject state** — both halt immediately
- unlike DFAs/PDAs, a TM can also **loop forever** (neither accept nor reject)

![](resources/al11-tm-accept-reject.png)

---

## formal definition
A Turing machine $M$ is a 7-tuple $(Q, \Sigma, \Gamma, \delta, q_0, q_{\text{accept}}, q_{\text{reject}})$:

- $Q$: finite set of states
- $\Sigma$: input alphabet (does not contain the blank symbol $\sqcup$)
- $\Gamma$: tape alphabet ($\Sigma \subseteq \Gamma$, and $\sqcup \in \Gamma$)
- $\delta: Q \times \Gamma \to Q \times \Gamma \times \{L, R\}$: transition function
- $q_0 \in Q$: start state
- $q_{\text{accept}} \in Q$: accept state (halts immediately)
- $q_{\text{reject}} \in Q$: reject state (halts immediately)

### transition notation
$\delta(q_i, a) = (q_j, b, R)$ means: in state $q_i$, reading $a$, write $b$, move right, go to $q_j$.

![](resources/al11-tm-transition.png)

---

## configurations
A **configuration** captures the full state of a TM at any point: current state, tape contents, and head position.

Written as: $C = w_1 \; q_i \; w_2$
- $w_1$: tape contents to the left of the head
- $q_i$: current state (placed at the head position)
- $w_2$: tape contents under and to the right of the head

Starting configuration: $C_1 = q_0 w$ (head at leftmost character of input).

---

## computation (formal acceptance)
TM $M$ accepts input $w$ if there exists a sequence of configurations $C_1, \dots, C_k$ such that:

1. $C_1 = q_0 w$ (start in starting configuration)
2. $C_i \Rightarrow C_{i+1}$ for all $i = 1, \dots, k-1$ (each step follows from $\delta$):
   - if $\delta(q_i, b) = (q_j, c, L)$: $ua \; q_i \; bv \Rightarrow u \; q_j \; acv$
   - if $\delta(q_i, b) = (q_j, c, R)$: $ua \; q_i \; bv \Rightarrow uac \; q_j \; v$
3. $C_k$ contains $q_{\text{accept}}$ (end in accepting configuration)

---

## notes on finiteness
- input strings: finite length (same as DFAs/PDAs)
- accepted language: can be infinite (same as DFAs/PDAs)
- alphabets and states: finite (same as DFAs/PDAs)
- tape storage: arbitrarily large / infinite (like PDA stack, but with random access)

---

## summary
- pumping lemma for CFLs is used the same way as for RLs: construct an evil string, show all breakdowns fail
- key non-CFL examples: $\{ww\}$, $\{a^n b^n c^n\}$, $\{a^i b^j c^k \mid i \leq j \leq k\}$
- Turing machines extend DFAs with an infinite read/write tape and a movable head
- TMs can accept, reject, or loop forever
- next: examples showing what TMs can do
