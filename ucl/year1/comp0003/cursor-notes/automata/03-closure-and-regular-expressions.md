# Closure Properties & Regular Expressions — COMP0003 Automata

*Lecture-style notes. **Closure properties** show that the class of regular languages is **robust** — combining regular languages via **union**, **concatenation**, or **Kleene star** always yields another regular language. **Regular expressions** are a compact notation that captures exactly the same class. The equivalence **regex ↔ NFA/DFA** is proved via **structural induction** (regex → NFA) and **GNFA state elimination** (DFA → regex).*

---

## 1. COMPLETE TOPIC SUMMARIES

### The "big three" closure properties

If **\(L_1\)** and **\(L_2\)** are regular languages (recognised by some NFAs **\(M_1\)** and **\(M_2\)**), then each of the following is also regular:

| Operation | Notation | Meaning |
|-----------|----------|---------|
| **Union** | **\(L_1 \cup L_2\)** | Strings in **\(L_1\)** **or** **\(L_2\)** (or both) |
| **Concatenation** | **\(L_1 \circ L_2\)** | Every string **\(s_1 s_2\)** where **\(s_1 \in L_1\)** and **\(s_2 \in L_2\)** |
| **Kleene star** | **\(L^*\)** | Zero or more strings from **\(L\)** concatenated together |

All three proofs work by **constructing an NFA** from the given machines and then invoking the result that every NFA has an equivalent DFA.

---

### Union closure — NFA construction

**Goal.** Given NFAs **\(M_1 = (Q_1, \Sigma, \delta_1, q_{01}, F_1)\)** and **\(M_2 = (Q_2, \Sigma, \delta_2, q_{02}, F_2)\)**, build an NFA **\(N\)** with **\(L(N) = L(M_1) \cup L(M_2)\)**.

**Construction.**

- **\(Q = \{q_0\} \cup Q_1 \cup Q_2\)** — a fresh start state **\(q_0\)** plus all states from both machines.
- **\(\Sigma\)** unchanged (assume alphabets agree, or take the union).
- **\(q_0\)** = new start state.
- **\(F = F_1 \cup F_2\)** — accept if **either** machine would accept.
- **\(\delta\):**
  - **\(\delta(q_0, \varepsilon) = \{q_{01}, q_{02}\}\)** — ε-transitions from the new start into both original start states.
  - **\(\delta(q, a) = \delta_1(q, a)\)** for **\(q \in Q_1\)**, **\(a \in \Sigma_\varepsilon\)**.
  - **\(\delta(q, a) = \delta_2(q, a)\)** for **\(q \in Q_2\)**, **\(a \in \Sigma_\varepsilon\)**.
  - **\(\delta(q_0, a) = \varnothing\)** for every **\(a \in \Sigma\)** (the new start state only has ε-transitions out).

**Why it works.** On any input **\(w\)**, the NFA non-deterministically follows **\(M_1\)** or **\(M_2\)**. If **\(w \in L(M_1)\)** then the branch through **\(M_1\)** reaches an accept state in **\(F_1 \subseteq F\)**; symmetrically for **\(M_2\)**. Conversely, if **\(N\)** accepts **\(w\)**, the accepting computation must have gone entirely through one of the two original machines, so **\(w\)** belongs to at least one language.

---

### Concatenation closure — NFA construction

**Goal.** Build NFA **\(N\)** with **\(L(N) = L(M_1) \circ L(M_2)\)**: the set of all strings **\(s_1 s_2\)** where **\(s_1 \in L(M_1)\)** and **\(s_2 \in L(M_2)\)**.

**Construction.**

- **\(Q = Q_1 \cup Q_2\)**.
- Start state = **\(q_{01}\)** (start of **\(M_1\)**).
- Accept states = **\(F_2\)** only (must finish in **\(M_2\)**).
- **\(\delta\):**
  - Keep all original transitions of **\(M_1\)** and **\(M_2\)**.
  - For every **former** accept state **\(q_f \in F_1\)**, add **\(\delta(q_f, \varepsilon) \ni q_{02}\)** — an ε-transition from each old accept state of **\(M_1\)** into the start state of **\(M_2\)**.
  - The states in **\(F_1\)** are **no longer** accept states.

**Why it works.** The NFA processes the first portion of the input through **\(M_1\)**. At any point where **\(M_1\)** would have accepted (i.e. the prefix is in **\(L_1\)**), the NFA non-deterministically jumps via ε to **\(M_2\)**, which then processes the remaining suffix. Acceptance requires the suffix to land in **\(F_2\)**, i.e. the suffix is in **\(L_2\)**.

---

### Kleene star closure — NFA construction

**Goal.** Given NFA **\(M = (Q, \Sigma, \delta, q_0, F)\)**, build NFA **\(N\)** with **\(L(N) = L(M)^*\)**: zero or more concatenations of strings from **\(L(M)\)**.

**Construction.**

- **\(Q' = \{q_s\} \cup Q\)** — a **fresh** start state **\(q_s\)**.
- **\(q_s\)** is **accepting** (so that **\(\varepsilon \in L(N)\)**, accounting for zero repetitions).
- **\(\delta(q_s, \varepsilon) = \{q_0\}\)** — ε-transition from new start to old start.
- For every **\(q_f \in F\)**, add **\(\delta(q_f, \varepsilon) \ni q_0\)** — ε-transitions from old accept states back to the old start, allowing repetition.
- Accept states = **\(\{q_s\} \cup F\)**.

**Pitfall of the naive approach.** A tempting shortcut: just make the **original** start state **\(q_0\)** accepting and add ε-transitions from accept states back to **\(q_0\)**. This **fails** because making **\(q_0\)** accepting can introduce **new paths** that were not in the original language — incoming edges to **\(q_0\)** (which may exist in the original NFA or from the back-loop) now reach an accept state that was previously non-accepting, potentially accepting strings outside **\(L(M)^*\)**. The fix is the fresh start state **\(q_s\)** with no incoming edges other than being the start.

---

### Regular expressions — recursive definition

A **regular expression** (**regex**) over alphabet **\(\Sigma\)** and the language it represents **\(L(R)\)** are defined **recursively**:

| Regex **\(R\)** | Language **\(L(R)\)** | Description |
|---|---|---|
| **\(a\)** for **\(a \in \Sigma\)** | **\(\{a\}\)** | Single character |
| **\(\varepsilon\)** | **\(\{\varepsilon\}\)** | The empty string only |
| **\(\varnothing\)** | **\(\varnothing\)** | No strings at all (empty language) |
| **\(R_1 \cup R_2\)** | **\(L(R_1) \cup L(R_2)\)** | Union |
| **\(R_1 \circ R_2\)** | **\(L(R_1) \circ L(R_2)\)** | Concatenation |
| **\(R_1^*\)** | **\(L(R_1)^*\)** | Kleene star |

Nothing else is a regular expression. Every regex is built from the three **atomic** cases (**\(a\)**, **\(\varepsilon\)**, **\(\varnothing\)**) and three **compound** operations (**\(\cup\)**, **\(\circ\)**, **\({}^*\)**).

---

### Convenience features and shorthand

| Shorthand | Meaning |
|-----------|---------|
| **\(\Sigma\)** | **\(a_1 \cup a_2 \cup \cdots \cup a_k\)** — any single character in the alphabet |
| **\(\Sigma^*\)** | All strings over **\(\Sigma\)** (apply Kleene star to the above) |
| **\(R_1 \mid R_2\)** | Alternative notation for **\(R_1 \cup R_2\)** (common in programming) |
| **\(R^+\)** | **\(R \circ R^*\)** — one or more repetitions (excludes **\(\varepsilon\)** unless **\(\varepsilon \in L(R)\)**) |

---

### Order of operations (precedence)

From **highest** to **lowest** binding:

1. **Parentheses** **\((\cdots)\)** — override everything.
2. **Kleene star** **\({}^*\)** — binds tightest of the operators.
3. **Concatenation** **\(\circ\)** — often written by juxtaposition (no explicit symbol).
4. **Union** **\(\cup\)** — binds loosest.

**Example.** **\(ab^* \cup c\)** parses as **\((a(b^*)) \cup c\)**: first star **\(b\)**, then concatenate **\(a\)** with **\(b^*\)**, then union with **\(c\)**.

---

### Regex examples

| Regex | Language (over **\(\Sigma = \{0, 1\}\)** unless stated) |
|-------|-------|
| **\(0^* 1 0^*\)** | Strings with **exactly one** **\(1\)** |
| **\(\Sigma^* 1 \Sigma^*\)** | Strings containing **at least one** **\(1\)** |
| **\((\Sigma\Sigma)^*\)** | All strings of **even length** |
| **\(0 \cup 1\)** | **\(\{0, 1\}\)** — either a single **\(0\)** or a single **\(1\)** |
| **\(01 \cup 10\)** | **\(\{01, 10\}\)** |
| **\(0\Sigma^* \cup \varepsilon\)** | Strings that **start with 0**, plus the empty string |
| **\((0 \cup 1)^* 00 (0 \cup 1)^*\)** | Strings containing **\(00\)** as a substring |
| **\(1^*(01^+)^*\)** | Strings where every **\(0\)** is followed by at least one **\(1\)** |
| **\(\varnothing^*\)** | **\(\{\varepsilon\}\)** — Kleene star of the empty language contains only the empty string |
| **\(\varepsilon \circ R\)** | **\(L(R)\)** — concatenating with **\(\varepsilon\)** changes nothing |

---

### Regex ↔ DFA/NFA equivalence

**Theorem.** A language is **regular** if and only if some **regular expression** describes it.

The proof has **two directions:**

---

#### Direction 1: Regex → NFA (structural induction)

**Claim.** For every regex **\(R\)**, there exists an NFA **\(N\)** with **\(L(N) = L(R)\)**.

**Proof by structural induction on the definition of regex:**

**Base cases** (construct small NFAs directly):

1. **\(R = a\)** (**\(a \in \Sigma\)**): Two states; single transition **\(q_0 \xrightarrow{a} q_f\)** where **\(q_f\)** is the only accept state.
2. **\(R = \varepsilon\)**: Single state that is both start and accept. No transitions.
3. **\(R = \varnothing\)**: Single state that is start but **not** accept. No transitions. Accepts nothing.

**Inductive cases** (assume NFAs for **\(R_1\)** and **\(R_2\)** exist):

1. **\(R = R_1 \cup R_2\)**: Apply the **union closure construction** (new start, ε-transitions to both).
2. **\(R = R_1 \circ R_2\)**: Apply the **concatenation closure construction** (ε from **\(M_1\)** accept states to **\(M_2\)** start).
3. **\(R = R_1^*\)**: Apply the **Kleene star closure construction** (new accepting start, ε loop-back).

Since every NFA can be converted to a DFA (subset construction), every regex describes a **regular** language.

---

#### Direction 2: DFA → Regex (via GNFAs and state elimination)

**Goal.** Given any DFA **\(M\)**, produce a regex **\(R\)** with **\(L(R) = L(M)\)**.

**Tool: Generalised NFA (GNFA).** A GNFA is like an NFA except the **labels on transitions are regular expressions** (not single characters). A transition labelled **\(R\)** between states **\(q_i\)** and **\(q_j\)** means: the machine can move from **\(q_i\)** to **\(q_j\)** by consuming any string in **\(L(R)\)**.

**GNFA requirements (canonical form):**

1. **Start state** has **no incoming** arrows (only outgoing).
2. Exactly **one accept state**, which has **no outgoing** arrows.
3. The start state ≠ accept state.
4. Every pair of states (except for arrows into start / out of accept) has exactly **one** transition arrow between them (use **\(\varnothing\)** for "no connection").

**Converting a DFA to a GNFA:**

1. Add a **new start state** **\(q_s\)** with a single ε-transition to the DFA's original start state (ensures no incoming arrows to the start).
2. Add a **new single accept state** **\(q_a\)** with ε-transitions from every original accept state to **\(q_a\)** (ensures one accept state with no outgoing arrows).
3. Replace multiple transitions between the same pair with their **union**.
4. Add **\(\varnothing\)**-labelled transitions for any missing pair.

**State elimination procedure (GNFA → 2-state GNFA → regex):**

Repeat until only **\(q_s\)** and **\(q_a\)** remain:

1. **Pick** any state **\(q_r\)** that is neither **\(q_s\)** nor **\(q_a\)**.
2. **Remove** **\(q_r\)** from the machine.
3. **For every pair** of remaining states **\((q_i, q_j)\)** (including **\(i = j\)**, i.e. self-loops), update the transition label:

\[
R'_{i \to j} = R_{i \to j} \cup R_{i \to r} \circ R_{r \to r}^* \circ R_{r \to j}
\]

**Intuition.** "I can go from **\(q_i\)** to **\(q_j\)** either **directly** (the old **\(R_{i \to j}\)**), or by going to **\(q_r\)** (**\(R_{i \to r}\)**), looping at **\(q_r\)** zero or more times (**\(R_{r \to r}^*\)**), then leaving to **\(q_j\)** (**\(R_{r \to j}\)**)."

After eliminating all intermediate states, only **\(q_s\)** and **\(q_a\)** remain, connected by a **single** transition whose label is the desired regex **\(R\)**.

---

### Worked example: even-1s DFA → regex

**DFA.** Two states: **\(q_E\)** (even number of 1s, **start** and **accept**) and **\(q_O\)** (odd). Alphabet **\(\Sigma = \{0, 1\}\)**.

| | 0 | 1 |
|---|---|---|
| **\(q_E\)** (start, accept) | **\(q_E\)** | **\(q_O\)** |
| **\(q_O\)** | **\(q_O\)** | **\(q_E\)** |

**Step 1 — Convert to GNFA.** Add fresh start **\(q_s\)** with **\(q_s \xrightarrow{\varepsilon} q_E\)**, and fresh accept **\(q_a\)** with **\(q_E \xrightarrow{\varepsilon} q_a\)**. Label self-loops and transitions as regex: **\(q_E \xrightarrow{0} q_E\)** (self-loop), **\(q_E \xrightarrow{1} q_O\)**, **\(q_O \xrightarrow{0} q_O\)** (self-loop), **\(q_O \xrightarrow{1} q_E\)**. Fill missing pairs with **\(\varnothing\)**.

The GNFA now has 4 states: **\(q_s, q_E, q_O, q_a\)**.

**Step 2 — Eliminate** **\(q_O\)** (it is neither start nor accept).

For every remaining pair **\((q_i, q_j)\)** where **\(q_i, q_j \in \{q_s, q_E, q_a\}\)**, apply the update formula with **\(q_r = q_O\)**:

- **\(q_E \to q_E\):** **\(R'_{E \to E} = 0 \cup 1 \circ 0^* \circ 1\)** (go directly via self-loop **\(0\)**, or go to **\(q_O\)** via **\(1\)**, loop on **\(0^*\)**, return via **\(1\)**).
- **\(q_E \to q_a\):** **\(R'_{E \to a} = \varepsilon \cup 1 \circ 0^* \circ \varnothing = \varepsilon\)** (since **\(q_O\)** has no edge to **\(q_a\)**, the second term vanishes).
- **\(q_s \to q_E\):** **\(R'_{s \to E} = \varepsilon \cup \varnothing \circ 0^* \circ 1 = \varepsilon\)** (since **\(q_s\)** has no edge to **\(q_O\)**, the second term vanishes).
- **\(q_s \to q_a\):** remains **\(\varnothing\)** (both paths through **\(q_O\)** are blocked).

GNFA now has 3 states: **\(q_s, q_E, q_a\)** with **\(q_s \xrightarrow{\varepsilon} q_E\)**, **\(q_E\)** self-loop **\(0 \cup 10^*1\)**, **\(q_E \xrightarrow{\varepsilon} q_a\)**.

**Step 3 — Eliminate** **\(q_E\)**.

- **\(q_s \to q_a\):** **\(R'_{s \to a} = \varnothing \cup \varepsilon \circ (0 \cup 10^*1)^* \circ \varepsilon = (0 \cup 10^*1)^*\)**.

**Result.** The regex is:

\[
(0 \cup 10^*1)^*
\]

This describes all binary strings with an **even number of 1s** — matching the original DFA.

---

## 2. EXAM-STYLE QUESTIONS (WITH MODEL ANSWERS)

### Q1 — Union NFA construction

**Question.** Given NFA **\(M_1\)** recognising **\(L_1\)** and NFA **\(M_2\)** recognising **\(L_2\)**, describe precisely how to construct an NFA **\(N\)** with **\(L(N) = L_1 \cup L_2\)**. State **\(Q\)**, **\(q_0\)**, **\(F\)**, and the key transitions.

**Model answer.** Introduce a **fresh** start state **\(q_0\)** with **\(\delta(q_0, \varepsilon) = \{q_{01}, q_{02}\}\)** (ε-transitions to both original starts). Set **\(Q = \{q_0\} \cup Q_1 \cup Q_2\)**, keep all original transitions, and set **\(F = F_1 \cup F_2\)**. On input **\(w\)**, the NFA non-deterministically follows **\(M_1\)** or **\(M_2\)**; it accepts iff at least one branch reaches an accept state, so **\(L(N) = L_1 \cup L_2\)**. The new start has **no incoming** edges and transitions **only** on **\(\varepsilon\)** — it never "re-enters" the choice point.

---

### Q2 — Kleene star pitfall

**Question.** Explain why the following "shortcut" for **\(L(M)^*\)** is **incorrect**: "make the original start state **\(q_0\)** accepting and add ε-transitions from every accept state back to **\(q_0\)**." Give a concrete example where the shortcut accepts a string **not** in **\(L(M)^*\)**.

**Model answer.** Making **\(q_0\)** accepting can create **new accepting paths** that skip parts of the original machine. Consider **\(M\)** with **\(L(M) = \{01\}\)**: states **\(q_0 \xrightarrow{0} q_1 \xrightarrow{1} q_2\)** where **\(q_2\)** is the only accept state. With the shortcut, **\(q_0\)** becomes accepting. Now add **\(q_2 \xrightarrow{\varepsilon} q_0\)**. The string **\(0\)** is now accepted: read **\(0\)** to reach **\(q_1\)**, but we can also trace: start at **\(q_0\)** (now accepting) — actually the problem is subtler. If there were **incoming** edges to **\(q_0\)** (e.g. from the ε-loop **\(q_2 \to q_0\)**), strings that reach **\(q_0\)** mid-computation now accept prematurely. Concretely, **\(010\)** would be accepted: read **\(01\)** to **\(q_2\)**, ε to **\(q_0\)**, read **\(0\)** to **\(q_1\)** — but **\(q_0\)** was visited and is now accepting, so the substring **\(01\)** accepted, then a stray **\(0\)** remains. Actually the accepting run uses the ε-back then recognises at **\(q_0\)** as accepting after the ε — meaning the NFA accepts **\(01\)** (which is in **\(L^*\)**) then **\(0\)** remains unconsumed — wait, NFAs must consume the whole string. The correct problematic example: if the original NFA had **any** transitions into **\(q_0\)**, those paths now lead to an accept state that was not previously accepting, potentially accepting new strings. A standard example: suppose **\(M\)** recognises strings starting with **\(a\)** and ending with **\(b\)** (**\(q_0 \xrightarrow{a} q_1 \xrightarrow{b} q_2\)** with **\(q_2\)** accepting). The shortcut makes **\(q_0\)** accepting (**\(\varepsilon\)** is fine — zero repetitions). But with the ε-back, after reading **\(ab\)** we ε-jump to **\(q_0\)**, then reading **\(b\)** takes us — only if there is a **\(b\)**-transition from **\(q_0\)** (there isn't). The cleanest example: if **\(q_0\)** already has a self-loop or incoming transition on some symbol, making **\(q_0\)** accepting creates a new accepting computation. The **safe** construction avoids this entirely by using a **fresh** start state **\(q_s\)** with **no incoming edges**.

---

### Q3 — Converting a regex to an NFA

**Question.** Using the closure constructions, draw or describe the NFA for the regex **\((0 \cup 1) \circ 0^*\)** over **\(\Sigma = \{0, 1\}\)**. Explain which construction applies at each step.

**Model answer.** Build bottom-up:

1. **Base NFAs:** NFA for **\(0\)**: **\(q_a \xrightarrow{0} q_b\)** (accept at **\(q_b\)**). NFA for **\(1\)**: **\(q_c \xrightarrow{1} q_d\)** (accept at **\(q_d\)**).
2. **Union** **\(0 \cup 1\)**: Fresh start **\(q_u\)** with **\(\varepsilon\)**-transitions to **\(q_a\)** and **\(q_c\)**. Accept states **\(\{q_b, q_d\}\)**.
3. **Base NFA for second \(0\):** **\(q_e \xrightarrow{0} q_f\)** (accept at **\(q_f\)**).
4. **Kleene star** **\(0^*\)**: Fresh accepting start **\(q_s\)** with **\(\varepsilon\)** to **\(q_e\)**. Add **\(q_f \xrightarrow{\varepsilon} q_e\)** for repetition. Accept states **\(\{q_s, q_f\}\)**.
5. **Concatenation** **\((0 \cup 1) \circ 0^*\)**: From accept states of the union NFA (**\(q_b, q_d\)**), add **\(\varepsilon\)**-transitions to the start of the star NFA (**\(q_s\)**). Strip **\(q_b, q_d\)** of accept status. Final accept states: **\(\{q_s, q_f\}\)** (from the star sub-NFA).

The resulting NFA accepts any string that starts with **\(0\)** or **\(1\)** followed by zero or more **\(0\)**s.

---

### Q4 — GNFA state elimination

**Question.** State the **GNFA state-removal formula**. Given a 3-state GNFA with states **\(\{q_s, q_1, q_a\}\)** where **\(q_s \xrightarrow{a} q_1\)**, **\(q_1\)** self-loop **\(b\)**, **\(q_1 \xrightarrow{a} q_a\)**, and **\(q_s \xrightarrow{\varnothing} q_a\)**, eliminate **\(q_1\)** to find the resulting regex.

**Model answer.** The state-removal formula for eliminating **\(q_r\)** is:

\[
R'_{i \to j} = R_{i \to j} \cup R_{i \to r} \circ R_{r \to r}^* \circ R_{r \to j}
\]

Applying with **\(q_r = q_1\)**, **\(q_i = q_s\)**, **\(q_j = q_a\)**:

\[
R'_{s \to a} = \varnothing \cup a \circ b^* \circ a = ab^*a
\]

The resulting regex is **\(ab^*a\)**: strings of the form **\(a\)**, followed by zero or more **\(b\)**s, followed by **\(a\)**.

---

### Q5 — Regex equivalence

**Question.** Outline **both directions** of the proof that a language is regular if and only if it is described by a regular expression. For each direction, name the proof technique and the key idea.

**Model answer.**

**(Regex → Regular):** By **structural induction** on the recursive definition of regular expressions. **Base cases:** NFAs for single-character **\(a\)**, **\(\varepsilon\)**, and **\(\varnothing\)** are trivially constructible. **Inductive cases:** given NFAs for **\(R_1\)** and **\(R_2\)**, use the NFA closure constructions for **union**, **concatenation**, and **Kleene star** to build an NFA for each compound expression. Since every NFA has an equivalent DFA, the language is regular.

**(Regular → Regex):** Start with a DFA. Convert it to a **GNFA** in canonical form (fresh start with no incoming arrows, single accept state with no outgoing arrows, regex-labelled transitions). **Eliminate states** one at a time using the formula **\(R'_{i \to j} = R_{i \to j} \cup R_{i \to r} \circ R_{r \to r}^* \circ R_{r \to j}\)** until only the start and accept remain. The single transition label from start to accept is the desired regex. Each elimination **preserves** the language because all paths through the removed state are folded into the updated labels.

---

## 3. MUST-KNOW KEY POINTS

- **Closure under union:** new start state with ε-transitions to both original starts; accept states = **\(F_1 \cup F_2\)**.
- **Closure under concatenation:** ε-transitions from **\(M_1\)**'s accept states to **\(M_2\)**'s start; only **\(M_2\)**'s accept states remain accepting.
- **Closure under Kleene star:** **fresh** accepting start **\(q_s\)** with ε to old start; ε from old accept states back to old start. **Must** use a new start state to avoid the naive-alteration pitfall.
- **Regular expression** = recursive definition with six cases: **\(a\)**, **\(\varepsilon\)**, **\(\varnothing\)**, **\(R_1 \cup R_2\)**, **\(R_1 \circ R_2\)**, **\(R_1^*\)**.
- **Precedence:** **\({}^*\)** > **\(\circ\)** > **\(\cup\)** (parentheses override).
- **Regex → NFA:** structural induction; base cases for atoms, inductive cases use closure constructions.
- **DFA → Regex:** convert DFA to GNFA (canonical form), then **eliminate states** one by one with the formula **\(R'_{i \to j} = R_{i \to j} \cup R_{i \to r} \circ R_{r \to r}^* \circ R_{r \to j}\)**, ending with a 2-state GNFA whose sole transition label is the regex.
- **GNFA canonical form:** start state has no incoming arrows; single accept state has no outgoing arrows; every pair of states has exactly one (possibly **\(\varnothing\)**-labelled) transition.
- **Equivalence theorem:** regex ⇔ NFA ⇔ DFA — all describe exactly the class of **regular languages**.

---

## 4. HIGH-PRIORITY TOPICS

### 🔴 Must Know

- **NFA constructions** for all three closures (union, concatenation, Kleene star): be able to state **\(Q\)**, **\(q_0\)**, **\(F\)**, and the ε-transitions precisely.
- **Kleene star pitfall:** why you **must** add a fresh start state rather than modifying the original.
- **Recursive definition of regex:** all six cases, and the distinction between **\(\varepsilon\)** (language **\(\{\varepsilon\}\)**) and **\(\varnothing\)** (empty language).
- **Order of operations:** **\({}^*\)** > **\(\circ\)** > **\(\cup\)**.
- **Regex → NFA proof sketch:** structural induction using the three closure constructions.
- **GNFA state-elimination formula:** **\(R'_{i \to j} = R_{i \to j} \cup R_{i \to r} \circ R_{r \to r}^* \circ R_{r \to j}\)**.
- **GNFA canonical form** requirements (no incoming to start, single accept with no outgoing).
- **Equivalence** of regex, NFA, DFA, and regular languages.

### 🟡 Important

- **Complement closure** proof for DFAs (flip accept/non-accept states) — easy but sometimes examined alongside the big three.
- **DFA → GNFA conversion steps** (add fresh start/accept, consolidate transitions, fill **\(\varnothing\)**).
- **Worked example** of state elimination (e.g. even-1s DFA → regex **\((0 \cup 10^*1)^*\)**).
- Applying **regex** to describe specific languages (practice parsing and constructing regex).
- **Convenience notation:** **\(\Sigma\)**, **\(\Sigma^*\)**, **\(R^+\)**, **\(R \mid R\)**.

### 🟢 Useful but Lower Priority

- Formal proof that each state-elimination step preserves the language.
- **Uniqueness** — the same language can have many different regexes; there is no single canonical regex.
- DFA union construction via **Cartesian product** (from lecture 2) vs the NFA ε-transition construction — both work but the NFA version is simpler and generalises to all three closures.
- Extended regex features in real programming (backreferences, lookahead) go **beyond** regular languages.

---

## 5. TOPIC INTERCONNECTIONS & BIGGER PICTURE

- **NFAs and closure** are the bridge between **DFA** theory (lectures 1–3) and **regular expressions** — the closure constructions are the mechanical core that makes the regex ↔ NFA equivalence work.
- **Structural induction** on regex mirrors the **recursive definition** — the proof technique and the data structure align perfectly. This pattern recurs in formal logic and programming language theory.
- **GNFAs** are a "convenience tool" much like NFAs themselves: they do not add power but make the DFA → regex direction tractable. The same theme — **syntactic sugar** without extra computational power — appears across automata theory.
- The **equivalence** regex ⇔ NFA ⇔ DFA establishes that **regular languages** have three completely interchangeable characterisations. Later topics (**pumping lemma**, **context-free grammars**) use this equivalence: any result about DFAs automatically applies to regex and vice versa.
- **Concatenation** closure foreshadows **pushdown automata** and **context-free grammars**, where concatenation of language fragments drives derivation rules.
- In **practice**, regex engines in programming languages (Python, Java, grep) implement these NFA constructions at their core, though they add non-regular extensions (backreferences) that exceed the power of finite automata.

---

## 6. EXAM STRATEGY TIPS

- **Draw the NFA constructions:** a quick sketch of the union/concatenation/star NFA with labelled ε-transitions is often worth more than a paragraph of text. Label the fresh start state clearly.
- **Kleene star:** always mention the **fresh start state** and **why** the naive approach fails — this is a classic exam pitfall question.
- **Regex parsing:** when given a regex, apply precedence rules explicitly. Write out the parse tree if unsure: **star first**, then **concatenation**, then **union**.
- **GNFA elimination:** write the formula **\(R'_{i \to j} = R_{i \to j} \cup R_{i \to r} \circ R_{r \to r}^* \circ R_{r \to j}\)** at the top of your working and fill in systematically for each pair. Don't skip pairs — missing one transition leads to an incorrect regex.
- **Don't confuse \(\varepsilon\) and \(\varnothing\):** **\(\varepsilon\)** in a regex means "the empty string is in the language"; **\(\varnothing\)** means "nothing is in the language." **\(\varnothing \circ R = \varnothing\)** but **\(\varepsilon \circ R = R\)**.
- **Check your regex** by testing a few strings mentally: does the empty string match? Does a single character match? Does a "boundary" string match?
- When converting DFA → regex, **choose wisely** which state to eliminate first — states with fewer connections produce simpler intermediate expressions. But the final result is equivalent regardless of elimination order.
- **Two-direction proofs:** if asked to show regex ⇔ regular, clearly separate the two directions and name the technique for each (structural induction vs GNFA state elimination).

---

*These notes cover Automata Lectures 4–5 of COMP0003. Follow your lecturer's conventions for GNFA notation, state-elimination order, and whether union is written as **\(\cup\)** or **\(\mid\)** in formal definitions.*
