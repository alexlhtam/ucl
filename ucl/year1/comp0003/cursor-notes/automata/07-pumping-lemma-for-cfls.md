# Pumping Lemma for Context-Free Languages — COMP0003 Automata

*Lecture-style notes. The **pumping lemma for CFLs** mirrors the regular-language version but splits a long string into **five** pieces $s = uvxyz$ and pumps the **second and fourth** parts simultaneously. Mastery of the **parse-tree proof**, the **three conditions**, and the **contrapositive argument** for showing languages are not context-free is essential.*

---

## 1. COMPLETE TOPIC SUMMARIES

### Parse trees — visual foundation for the lemma

A **parse tree** for a CFG derivation has:

- **Root** = start variable $S$.
- **Interior nodes** = variables; **leaves** = terminals (read left-to-right to recover the derived string).
- **Children** of a node labelled $A$ are the symbols on the right-hand side of whichever rule $A \to w$ was applied.

The **branching factor** $b$ of a grammar is the maximum number of symbols on the right-hand side of any rule. A tree with branching factor $b$ and $h$ levels has at most $b^h$ leaves.

---

### Ambiguity (brief context)

A grammar is **ambiguous** if some string has **more than one parse tree**. For the pumping lemma we always work with a **most compact** (fewest interior nodes) parse tree — this assumption is critical for the $|vy| > 0$ argument.

---

### Statement of the pumping lemma for CFLs

For any context-free language $A$, there exists a **pumping length** $p$ such that every string $s \in A$ with $|s| \geq p$ can be split into five pieces

$$s = u\,v\,x\,y\,z$$

satisfying **all three** conditions:

1. $uv^i x y^i z \in A$ for every $i \geq 0$ (pump $v$ and $y$ **simultaneously**).
2. $|vy| > 0$ (at least one of $v$, $y$ is non-empty).
3. $|vxy| \leq p$ (the pumpable "window" is bounded).

Compare with the **RL pumping lemma** where the split is $s = xyz$ and only the middle piece $y$ is pumped.

---

### Proof of the pumping lemma — parse-tree argument

#### Setup

Let the grammar for $A$ have:

- $b$ = branching factor (max RHS length of any rule).
- $n = |V|$ = number of variables.
- **Pumping length:** $p = b^{\,n+1}$.

#### Why a long string forces a repeated variable

A tree with branching factor $b$ and at most $n$ interior-node levels (i.e. $\leq n+1$ total levels including leaves) can have at most $b^n$ leaves. So if $|s| \geq b^{\,n+1} > b^n$, the parse tree must have a root-to-leaf path with **at least $n + 1$ interior nodes** (variables). Since there are only $n$ distinct variables, by the **pigeonhole principle** some variable $R$ must **appear twice** on that path.

#### Identifying the pieces

Pick the **longest** root-to-leaf path in the **most compact** parse tree. Label the two copies of the repeated variable:

- **Upper $R$** — the occurrence closer to the root.
- **Lower $R$** — the occurrence closer to the leaf.

Then:

- Lower $R$'s subtree generates some substring $x$.
- Upper $R$'s subtree generates a wider substring $vxy$ (lower $R$'s part is nested inside).
- The rest of the string gives $u$ (before $vxy$) and $z$ (after $vxy$).

#### Pumping up — duplicating upper R's subtree

At the position of lower $R$, **replace** its subtree with a copy of upper $R$'s entire subtree. This inserts an extra copy of $v$ before $x$ and an extra copy of $y$ after $x$, producing $uv^2xy^2z$. Repeating gives $uv^i xy^i z$ for any $i \geq 2$.

#### Pumping down — replacing upper R with lower R's decisions

At upper $R$, apply the same derivation rules that lower $R$ used. This **skips** $v$ and $y$ entirely, producing $uxz = uv^0 x y^0 z$.

#### Why |vy| > 0

If both $v = \epsilon$ and $y = \epsilon$, then upper $R$'s subtree generates the same substring $x$ as lower $R$'s subtree but with **more interior nodes**. Replacing upper $R$'s subtree with lower $R$'s would produce a **smaller** parse tree for the same string — contradicting our choice of the **most compact** tree.

#### Why |vxy| ≤ p

The repeated variable was found in the **bottom $n + 1$** interior nodes of the longest path. Upper $R$'s subtree therefore has at most $n + 1$ levels of interior nodes, so at most $b^{\,n+1} = p$ leaves. Hence $|vxy| \leq p$.

---

### Using the contrapositive to prove non-CFL

The lemma says: **CFL $\Rightarrow$ pumping property holds**.

**Contrapositive:** pumping property fails $\Rightarrow$ **not a CFL**.

**Proof template:**

1. Let $p$ be an **arbitrary** pumping length (the adversary chooses $p$).
2. **Construct** an "evil string" $s \in L$ with $|s| \geq p$.
3. For **every** valid split $s = uvxyz$ with $|vy| > 0$ and $|vxy| \leq p$, show that some pumped string $uv^i xy^i z \notin L$.
4. Conclude $L$ is **not** a CFL.

---

### Example 1 — a^n b^n c^n (n ≥ 0) is not CFL

**Evil string:** $s = a^p b^p c^p$, so $|s| = 3p \geq p$ and $s \in L$.

**Window argument (using condition 3).** Since $|vxy| \leq p$ and each of the three blocks $a^p$, $b^p$, $c^p$ has length $p$, the window $vxy$ can **overlap at most two** of the three blocks. So $v$ and $y$ collectively touch at most **two** character types.

- **Case A — $v$ and $y$ each contain a single character type.** Pumping up ($i = 2$) increases at most two of the three counts while the third stays at $p$. The counts become unequal, so $uv^2 xy^2 z \notin L$.
- **Case B — $v$ or $y$ contains two character types (e.g. $ab$).** Pumping up produces interleaved characters (e.g. $abab$), breaking the $a^*b^*c^*$ pattern.

All cases fail. $\square$

---

### Example 2 — ww over {0,1} is not CFL

**Evil string:** $s = 0^p 1^p 0^p 1^p$. Here $s = ww$ with $w = 0^p 1^p$, so $s \in L$ and $|s| = 4p \geq p$.

The **midpoint** of $s$ falls between the first $1^p$ block and the second $0^p$ block.

- **Case 1 — $vxy$ falls entirely in the first half (or entirely in the second half).** Pumping up adds at most $p$ characters to that half, shifting the midpoint. The two resulting halves begin with different symbols (one starts with $0$, the other with $1$), so the string is not of the form $ww$.
- **Case 2 — $vxy$ straddles the midpoint.** Since $|vxy| \leq p$, the first-half portion of the window touches only $1$'s and the second-half portion touches only $0$'s. Pumping down ($i = 0$) removes some $1$'s from the first half and some $0$'s from the second half, making the two halves unequal.

All cases fail. $\square$

---

### Example 3 — a^i b^j c^k with i ≤ j ≤ k is not CFL

**Evil string:** $s = a^p b^p c^p$ (satisfies $i = j = k = p$).

By condition 3, $|vxy| \leq p$, so the window touches at most two of the three blocks.

- **Window covers $a$'s and $b$'s (no $c$'s):** pump **up** ($i = 2$) — more $a$'s or $b$'s than $c$'s, breaking $j \leq k$.
- **Window covers $b$'s and $c$'s (no $a$'s):** pump **down** ($i = 0$) — fewer $b$'s or $c$'s, so either $i > j$ or $j > k$ fails. Actually: fewer $b$'s can break $i \leq j$ (since $a$'s stay at $p$), and fewer $c$'s can break $j \leq k$.
- **Window covers only $a$'s:** pump up — more $a$'s than $b$'s, breaking $i \leq j$.
- **Window covers only $b$'s:** pump up — $j > k$; pump down — $i > j$. Either way, broken.
- **Window covers only $c$'s:** pump down — $j > k$, broken.
- **Mixed characters in $v$ or $y$:** pumping produces interleaved characters, breaking the $a^*b^*c^*$ pattern.

All cases fail. $\square$

---

### CFL vs non-CFL comparison table

| CFL (PDA/CFG can handle) | Not a CFL (pumping lemma proves) |
|---|---|
| $\{ww^R \mid w \in \Sigma^*\}$ (palindromes) | $\{ww \mid w \in \Sigma^*\}$ (exact copy) |
| $\{a^n b^n \mid n \geq 0\}$ | $\{a^n b^n c^n \mid n \geq 0\}$ |
| $\{a^i b^j \mid 0 \leq i \leq j\}$ | $\{a^i b^j c^k \mid 0 \leq i \leq j \leq k\}$ |

**Intuition:** a PDA's single stack can match **one pair** of constraints (e.g. count $a$'s, then match with $b$'s). It **cannot** enforce **two independent equalities or orderings** simultaneously. The pumping lemma formalises this limitation.

---

### Language class hierarchy

$$\text{Regular Languages} \;\subset\; \text{Context-Free Languages} \;\subset\; \cdots$$

- **Regular languages:** recognised by DFAs = NFAs = regular expressions.
- **Context-free languages:** recognised by PDAs = generated by CFGs.
- Some languages (like $\{a^n b^n c^n\}$) are **beyond** CFLs — recognising them requires more powerful models (Turing machines).

---

## 2. EXAM-STYLE QUESTIONS (WITH MODEL ANSWERS)

### Q1 — State the pumping lemma for CFLs

**Question.** State the pumping lemma for context-free languages, clearly listing all three conditions.

**Model answer.** For any CFL $A$, there exists a pumping length $p$ such that every $s \in A$ with $|s| \geq p$ can be written as $s = uvxyz$ satisfying: (1) $uv^i xy^i z \in A$ for all $i \geq 0$; (2) $|vy| > 0$; (3) $|vxy| \leq p$.

---

### Q2 — Why does |vy| > 0 hold?

**Question.** In the proof of the CFL pumping lemma, explain why condition 2 ($|vy| > 0$) must hold.

**Model answer.** We choose the **most compact** parse tree (fewest interior nodes). If $v = \epsilon$ and $y = \epsilon$, then upper $R$'s subtree generates exactly the same substring $x$ as lower $R$'s subtree but with strictly more nodes. Replacing upper $R$'s subtree with lower $R$'s would yield a valid, **smaller** parse tree for the same string — contradicting compactness. Therefore at least one of $v$, $y$ must be non-empty.

---

### Q3 — Prove a^n b^n c^n (n ≥ 0) is not CFL

**Question.** Using the pumping lemma, prove that $L = \{a^n b^n c^n \mid n \geq 0\}$ is not a context-free language.

**Model answer.** Assume for contradiction that $L$ is a CFL with pumping length $p$. Choose $s = a^p b^p c^p \in L$ with $|s| = 3p \geq p$. For any split $s = uvxyz$ with $|vxy| \leq p$: since each block has length $p$, the window $vxy$ spans at most two of the three blocks. If $v$ and $y$ each contain one character type, pumping up ($i = 2$) increases at most two counts while the third remains $p$ — counts become unequal. If either contains two types, pumping produces interleaved characters breaking the $a^*b^*c^*$ pattern. In both cases $uv^2 xy^2 z \notin L$. Contradiction. $\square$

---

### Q4 — Prove ww over {0,1} is not CFL

**Question.** Prove that $L = \{ww \mid w \in \{0,1\}^*\}$ is not context-free.

**Model answer.** Let $p$ be the pumping length. Choose $s = 0^p 1^p 0^p 1^p \in L$. The midpoint falls between the first $1^p$ and the second $0^p$. For any split with $|vxy| \leq p$: **Case 1** — window is entirely in one half: pumping changes that half's length, shifting the midpoint so the two halves start with different symbols. **Case 2** — window straddles the midpoint: the first-half portion is all $1$'s and the second-half portion is all $0$'s; pumping down removes some of each, making the halves unequal. All cases give $uv^i xy^i z \notin L$. $\square$

---

### Q5 — CFL vs non-CFL and the role of the stack

**Question.** Explain intuitively why $\{a^n b^n\}$ is a CFL but $\{a^n b^n c^n\}$ is not. What limitation of PDAs does this illustrate?

**Model answer.** For $\{a^n b^n\}$, a PDA pushes one symbol per $a$ and pops one per $b$; accepting with an empty stack ensures equal counts. For $\{a^n b^n c^n\}$, after matching $a$'s with $b$'s the stack is empty and there is no mechanism to verify the $c$-count also equals $n$. A PDA's **single stack** can track **one** counter relationship at a time but not **two independent** equalities simultaneously. The pumping lemma formalises this: the "window" $vxy$ of length $\leq p$ cannot span all three blocks, so pumping always breaks at least one equality.

---

## 3. MUST-KNOW KEY POINTS

- **CFL pumping lemma splits** into **five** parts $s = uvxyz$; the **RL** version splits into **three** parts $s = xyz$.
- **Three conditions:** (1) $uv^i xy^i z \in A$ for all $i \geq 0$; (2) $|vy| > 0$; (3) $|vxy| \leq p$.
- **Pumping length:** $p = b^{\,n+1}$ where $b$ = branching factor, $n$ = number of variables.
- **Proof mechanism:** pigeonhole on a long root-to-leaf path forces a **repeated variable** $R$; pumping up = duplicate upper $R$'s subtree at lower $R$; pumping down = replace upper $R$ with lower $R$'s subtree.
- **$|vy| > 0$** from compactness of the chosen parse tree; **$|vxy| \leq p$** because upper $R$'s subtree has $\leq n+1$ levels.
- **Contrapositive** is the tool for proofs: given arbitrary $p$, pick an evil string, show all splits fail.
- **Evil string recipe:** typically set all parameters to $p$ (e.g. $a^p b^p c^p$) so the window covers at most two blocks.
- **Non-CFL examples:** $\{a^n b^n c^n\}$, $\{ww\}$, $\{a^i b^j c^k \mid i \leq j \leq k\}$.
- **CFL examples:** $\{a^n b^n\}$, $\{ww^R\}$, $\{a^i b^j \mid i \leq j\}$ — stack matches **one** pair.
- **Hierarchy:** Regular $\subset$ Context-Free $\subset$ (needs Turing machines and beyond).

---

## 4. HIGH-PRIORITY TOPICS

### 🔴 Must Know

- **Full statement** of the CFL pumping lemma with all three conditions.
- **Contrapositive proof structure:** arbitrary $p$, evil string, exhaust all splits.
- **Proof that $\{a^n b^n c^n\}$ is not CFL** — the canonical example (window argument).
- **Proof that $\{ww\}$ is not CFL** — choosing $0^p 1^p 0^p 1^p$ and the midpoint/straddling argument.
- **CFL vs non-CFL table** — know which languages are CFL and which are not, with brief justification.
- **Difference from RL pumping lemma:** five-piece split $uvxyz$ vs three-piece $xyz$; two pieces pumped simultaneously.

### 🟡 Important

- **Parse-tree proof sketch:** branching factor $b$, pumping length $p = b^{\,n+1}$, pigeonhole on repeated variable.
- **Why $|vy| > 0$** (compactness argument) and **why $|vxy| \leq p$** (bounded subtree depth).
- **Pumping up vs pumping down** — when each is useful in a proof.
- **$\{a^i b^j c^k \mid i \leq j \leq k\}$ proof** — handling directional inequalities.

### 🟢 Useful but Lower Priority

- **Ambiguity** of grammars (multiple parse trees) as context for "most compact tree" assumption.
- **Exact computation** of $p = b^{\,n+1}$ for a given grammar (e.g. the algebraic expression grammar where $b = 3$, $n = 3$, $p = 81$).
- **Language hierarchy positioning:** where CFLs sit relative to regular languages below and Turing-recognisable languages above.

---

## 5. TOPIC INTERCONNECTIONS & BIGGER PICTURE

- **RL pumping lemma** (Lectures 4–5) is the **direct precursor**. The CFL version generalises the pigeonhole argument from states on a path (DFA) to variables on a root-to-leaf path (parse tree).
- **CFG ↔ PDA equivalence** (Lecture 9) establishes what CFLs can do; the pumping lemma establishes what they **cannot** do. Together they **fully characterise** the boundary of context-free power.
- **Parse trees** connect to **ambiguity** and **Chomsky Normal Form** — both restructure derivations for analysis. CNF ensures binary branching ($b = 2$), simplifying the pumping length calculation.
- The non-CFL examples ($\{a^n b^n c^n\}$, $\{ww\}$) motivate **Turing machines** — a strictly more powerful model that can recognise these languages by using an infinite read/write tape instead of a stack.
- **Closure properties** interact with the pumping lemma: CFLs are closed under union, concatenation, and Kleene star, but **not** under intersection or complement. Knowing closure failures can sometimes replace pumping arguments.

---

## 6. EXAM STRATEGY TIPS

- **Memorise the three conditions** — exams often ask you to state the lemma before applying it; missing condition 3 ($|vxy| \leq p$) is a common error.
- **Always use the window argument** ($|vxy| \leq p$) to restrict where $v$ and $y$ can fall. This eliminates many cases immediately (e.g. $vxy$ cannot span all three blocks of $a^p b^p c^p$).
- **State your evil string explicitly** with $|s| \geq p$ justified. A good default: set every parameter to $p$.
- **Organise cases cleanly:** "single character type in $v,y$" vs "mixed characters in $v$ or $y$." Cover both and explain the contradiction for each.
- For **$\{ww\}$** proofs, the evil string $0^p 1^p 0^p 1^p$ is standard; do **not** use $0^p 0^p$ (that can be pumped within the CFL $\{0^n 0^n\} = \{0^{2n}\}$).
- **Pumping down** ($i = 0$) is often simpler to argue than pumping up — remember it as "delete $v$ and $y$."
- **Do not confuse** the RL pumping lemma ($s = xyz$, pump $y$) with the CFL version ($s = uvxyz$, pump $v$ and $y$ together). If the exam asks for the CFL version, writing the RL version scores zero.
- When comparing CFL vs non-CFL, reference the **stack limitation**: one stack matches one pair of constraints; two independent constraints require more power.

---

*These notes cover the CFL pumping lemma as presented in COMP0003 Automata Lectures 10–11 (first half). Always follow your lecturer's notation for the split and conditions if it differs from the conventions here.*
