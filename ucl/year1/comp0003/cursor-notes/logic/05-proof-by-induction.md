# Proof by Induction — COMP0003 Formal Logic

*Lecture-style notes covering Lectures 9–11. **Induction** is the canonical method for proving that a property holds for **every** element of an inductively defined set — natural numbers, lists, trees, or formulas. The pattern is always the same: prove the **base case(s)**, assume the **induction hypothesis (IH)** for smaller structures, and prove the **step case**.*

---

## 1. COMPLETE TOPIC SUMMARIES

### Overview: why induction?

Many mathematical and computational objects are defined **inductively** (recursively): natural numbers, lists, trees, formulas. To prove that **every** such object has a property $P$, we need a proof method that mirrors the inductive definition. **Induction** does exactly this:

- Show $P$ holds for the **base elements**.
- Show that if $P$ holds for **smaller** structures, it holds for the structure **built from** them.

Because every element is produced by finitely many applications of the constructors, these two steps suffice to cover all elements.

---

### Inductive definition of the natural numbers

$$0 \in \mathbb{N} \qquad\qquad \text{if } n \in \mathbb{N} \text{ then } s(n) \in \mathbb{N}$$

Nothing else is in $\mathbb{N}$. Here $s$ is the **successor** function; $s(n)$ represents $n + 1$.

---

### Ordinary (mathematical) induction on ℕ

To prove $\forall n \in \mathbb{N}.\; P(n)$:

1. **Base case:** Prove $P(0)$.
2. **Induction step:** Let $k \in \mathbb{N}$ be arbitrary. Assume $P(k)$ (**induction hypothesis**, IH). Prove $P(s(k))$.

**Inference rule notation:**

$$\frac{P(0) \qquad \forall k.\; P(k) \to P(s(k))}{\forall n.\; P(n)}$$

---

#### Example 1: every natural number is even or odd

**Claim.** $\forall n \in \mathbb{N}$, $n$ is even or $n$ is odd.

Define: $n$ is **even** iff $n = 2m$ for some $m$; $n$ is **odd** iff $n = 2m + 1$ for some $m$.

**Base case ($n = 0$):** $0 = 2 \cdot 0$, so $0$ is even. ✓

**Induction step:** Assume $k$ is even or odd (IH).

- **Case 1:** $k$ is even, so $k = 2m$. Then $s(k) = 2m + 1$, which is odd. ✓
- **Case 2:** $k$ is odd, so $k = 2m + 1$. Then $s(k) = 2m + 2 = 2(m+1)$, which is even. ✓

In both cases $s(k)$ is even or odd. $\square$

---

#### Example 2: y + 0 = y

Working in Peano-style arithmetic where addition is defined:

$$y + 0 = y \qquad\qquad y + s(x) = s(y + x)$$

Wait — $y + 0 = y$ is actually the **first defining equation**, so it holds by definition. The point is that the **other direction** or properties like **commutativity** require induction.

---

#### Example 3: commutativity of addition (x + y = y + x)

**Claim.** $\forall x, y \in \mathbb{N}.\; x + y = y + x$.

We induct on $x$.

**Auxiliary lemma (needed):** $s(y) + k = y + s(k)$ for all $y, k$.

*Proof of lemma by induction on $k$:*

**Base ($k = 0$):** $s(y) + 0 = s(y)$ (by definition) and $y + s(0) = s(y + 0) = s(y)$. ✓

**Step:** Assume $s(y) + k = y + s(k)$ (IH). Then:

$$s(y) + s(k) = s(s(y) + k) = s(y + s(k)) \quad\text{(by IH)}$$

$$y + s(s(k)) = s(y + s(k))$$

Both sides equal $s(y + s(k))$. ✓ $\square$

*Now prove commutativity by induction on $x$:*

**Base ($x = 0$):** $0 + y = y$ (requires its own small induction or is taken as known) and $y + 0 = y$ by definition. ✓

**Step:** Assume $x + y = y + x$ for all $y$ (IH). Then:

$$s(x) + y = s(x + y) \quad\text{(by definition of } +\text{)}$$

$$y + s(x) = s(y + x) \quad\text{(by definition of } +\text{)}$$

By IH, $x + y = y + x$, so $s(x + y) = s(y + x)$. Hence $s(x) + y = y + s(x)$. ✓ $\square$

---

### Structural induction on lists

#### Inductive definition of lists

$$\ell ::= [\;] \;\mid\; x :: \ell$$

A list is either **empty** ($[\;]$) or a **cons** of a head element $x$ and a tail list $\ell$.

#### Induction principle for lists

To prove $\forall \ell.\; P(\ell)$:

1. **Base case:** Prove $P([\;])$.
2. **Induction step:** For arbitrary $x$ and $xs$, assume $P(xs)$ (IH). Prove $P(x :: xs)$.

$$\frac{P([\;]) \qquad \forall x.\;\forall xs.\; P(xs) \to P(x :: xs)}{\forall \ell.\; P(\ell)}$$

#### Standard recursive functions on lists

**Length:**

$$len([\;]) = 0 \qquad\qquad len(x :: xs) = 1 + len(xs)$$

**Append:**

$$([\;])\; @\; ys = ys \qquad\qquad (x :: xs)\; @\; ys = x :: (xs\; @\; ys)$$

**Reverse:**

$$rev([\;]) = [\;] \qquad\qquad rev(x :: xs) = rev(xs)\; @\; [x]$$

---

#### Example 1: length of append (len(xs @ ys) = len(xs) + len(ys))

**Proof** by structural induction on $xs$.

**Base case ($xs = [\;]$):**

$$len([\;]\;@\;ys) = len(ys) \qquad\text{and}\qquad len([\;]) + len(ys) = 0 + len(ys) = len(ys) \quad\checkmark$$

**Induction step ($xs = a :: as$).** Assume $len(as\;@\;ys) = len(as) + len(ys)$ (IH).

$$len((a :: as)\;@\;ys) = len(a :: (as\;@\;ys)) = 1 + len(as\;@\;ys)$$

$$= 1 + len(as) + len(ys) \quad\text{(by IH)} = len(a :: as) + len(ys) \quad\checkmark$$

$\square$

---

#### Example 2: length of reverse (len(rev(xs)) = len(xs))

**Proof** by structural induction on $xs$, using the result above as a lemma.

**Base case ($xs = [\;]$):**

$$len(rev([\;])) = len([\;]) = 0 \quad\checkmark$$

**Induction step ($xs = a :: as$).** Assume $len(rev(as)) = len(as)$ (IH).

$$len(rev(a :: as)) = len(rev(as)\;@\;[a]) = len(rev(as)) + len([a])$$

$$= len(as) + 1 \quad\text{(by IH)} = 1 + len(as) = len(a :: as) \quad\checkmark$$

$\square$

---

### Structural induction on binary trees

#### Inductive definition

$$t ::= Lf \;\mid\; Br(x, t_1, t_2)$$

A tree is either a **leaf** ($Lf$) or a **branch** node with a value $x$ and two subtrees $t_1$, $t_2$.

#### Induction principle for binary trees

To prove $\forall t.\; P(t)$:

1. **Base case:** Prove $P(Lf)$.
2. **Induction step:** For arbitrary $x$, $t_1$, $t_2$, assume $P(t_1)$ and $P(t_2)$ (IH). Prove $P(Br(x, t_1, t_2))$.

$$\frac{P(Lf) \qquad \forall x, t_1, t_2.\; P(t_1) \land P(t_2) \to P(Br(x, t_1, t_2))}{\forall t.\; P(t)}$$

#### Standard recursive functions on trees

**Size** (number of branch nodes):

$$size(Lf) = 0 \qquad\qquad size(Br(x, t_1, t_2)) = 1 + size(t_1) + size(t_2)$$

**Reflect** (mirror image):

$$refl(Lf) = Lf \qquad\qquad refl(Br(x, t_1, t_2)) = Br(x, refl(t_2), refl(t_1))$$

---

#### Example 1: double reflection is the identity (refl(refl(t)) = t)

**Proof** by structural induction on $t$.

**Base case ($t = Lf$):**

$$refl(refl(Lf)) = refl(Lf) = Lf \quad\checkmark$$

**Induction step ($t = Br(x, t_1, t_2)$).** Assume $refl(refl(t_1)) = t_1$ and $refl(refl(t_2)) = t_2$ (IH).

$$refl(refl(Br(x, t_1, t_2))) = refl(Br(x, refl(t_2), refl(t_1)))$$

$$= Br(x, refl(refl(t_1)), refl(refl(t_2))) = Br(x, t_1, t_2) \quad\text{(by IH)} \quad\checkmark$$

$\square$

---

#### Example 2: size unchanged by reflection (size(refl(t)) = size(t))

**Proof** by structural induction on $t$.

**Base case ($t = Lf$):**

$$size(refl(Lf)) = size(Lf) = 0 \quad\checkmark$$

**Induction step ($t = Br(x, t_1, t_2)$).** Assume $size(refl(t_1)) = size(t_1)$ and $size(refl(t_2)) = size(t_2)$ (IH).

$$size(refl(Br(x, t_1, t_2))) = size(Br(x, refl(t_2), refl(t_1)))$$

$$= 1 + size(refl(t_2)) + size(refl(t_1)) = 1 + size(t_2) + size(t_1) \quad\text{(by IH)}$$

$$= 1 + size(t_1) + size(t_2) = size(Br(x, t_1, t_2)) \quad\checkmark$$

$\square$

---

### Structural induction on formulas

Formulas themselves are inductively defined, so we can induct on them.

#### Formulas built only from ∨ and ¬

$$F ::= Q \;\mid\; \lnot F \;\mid\; F_1 \lor F_2$$

where $Q$ ranges over propositional variables.

#### Example: propositional letters exceed ∨ occurrences by one

**Claim.** For every $(\lor, \lnot)$-formula $F$: $\text{letters}(F) = \text{ors}(F) + 1$.

Define:

$$\text{letters}(Q) = 1 \qquad \text{letters}(\lnot F) = \text{letters}(F) \qquad \text{letters}(F_1 \lor F_2) = \text{letters}(F_1) + \text{letters}(F_2)$$

$$\text{ors}(Q) = 0 \qquad \text{ors}(\lnot F) = \text{ors}(F) \qquad \text{ors}(F_1 \lor F_2) = 1 + \text{ors}(F_1) + \text{ors}(F_2)$$

**Proof** by structural induction on $F$.

**Base case ($F = Q$):** $\text{letters}(Q) = 1 = 0 + 1 = \text{ors}(Q) + 1$. ✓

**Case $F = \lnot G$.** Assume $\text{letters}(G) = \text{ors}(G) + 1$ (IH).

$$\text{letters}(\lnot G) = \text{letters}(G) = \text{ors}(G) + 1 = \text{ors}(\lnot G) + 1 \quad\checkmark$$

**Case $F = F_1 \lor F_2$.** Assume $\text{letters}(F_i) = \text{ors}(F_i) + 1$ for $i = 1, 2$ (IH).

$$\text{letters}(F_1 \lor F_2) = \text{letters}(F_1) + \text{letters}(F_2) = (\text{ors}(F_1) + 1) + (\text{ors}(F_2) + 1)$$

$$= \text{ors}(F_1) + \text{ors}(F_2) + 2 = (1 + \text{ors}(F_1) + \text{ors}(F_2)) + 1 = \text{ors}(F_1 \lor F_2) + 1 \quad\checkmark$$

$\square$

---

### Two-step (strong) induction

Sometimes the induction step for $P(s(k))$ needs not just $P(k)$ but also $P(k-1)$ (or, more generally, $P$ for all smaller values).

**Two-step induction** has:

1. **Two base cases:** Prove $P(0)$ and $P(1)$.
2. **Induction step:** Assume $P(k)$ and $P(s(k))$ (IH). Prove $P(s(s(k)))$.

**Inference rule:**

$$\frac{P(0) \qquad P(1) \qquad \forall k.\; P(k) \land P(s(k)) \to P(s(s(k)))}{\forall n.\; P(n)}$$

---

#### Example: sum of two evens is even

Define $even$ inductively: $even(0)$ holds; if $even(n)$ then $even(s(s(n)))$.

**Claim.** $\forall x.\; even(x) \to \forall y.\;(even(y) \to even(x + y))$.

**Proof** by two-step induction on $x$ (for fixed $y$, or alternatively induction on the derivation of $even(x)$).

**Base case $x = 0$:** $even(0 + y) = even(y)$, which holds by assumption. ✓

**Base case $x = 1$:** $even(1)$ is false, so the implication $even(1) \to \ldots$ is vacuously true. ✓

**Induction step.** Assume:

- $even(k) \to even(k + y)$ (IH$_1$)
- $even(s(k)) \to even(s(k) + y)$ (IH$_2$)

We must show $even(s(s(k))) \to even(s(s(k)) + y)$.

Assume $even(s(s(k)))$. By the definition of $even$, this means $even(k)$. By IH$_1$, $even(k + y)$. Then $even(s(s(k + y)))$ by the $even$ constructor. Since $s(s(k)) + y = s(s(k + y))$ (by the definition of addition), we have $even(s(s(k)) + y)$. ✓ $\square$

---

#### Equivalence of two-step and ordinary induction

**Two-step implies ordinary:** Ordinary induction is the special case where the second base case and the "look back two steps" are not needed (trivially satisfied or absorbed).

**Ordinary implies two-step:** Given a two-step induction proof of $P$, define $Q(n) = P(n) \land P(s(n))$. Then:

- **Base:** $Q(0) = P(0) \land P(1)$ — both given.
- **Step:** Assume $Q(k) = P(k) \land P(s(k))$. The two-step rule gives $P(s(s(k)))$. Combined with $P(s(k))$ (from $Q(k)$), we get $Q(s(k)) = P(s(k)) \land P(s(s(k)))$.

By ordinary induction, $\forall n.\; Q(n)$, hence $\forall n.\; P(n)$ (since $P(n)$ is a conjunct of $Q(n)$). $\square$

This shows the two principles are **inter-derivable** — two-step induction adds no extra logical strength.

---

## 2. EXAM-STYLE QUESTIONS (WITH MODEL ANSWERS)

### Q1 — Ordinary induction on ℕ

**Question.** Prove by induction: $\forall n \geq 0.\; \displaystyle\sum_{i=0}^{n} (2i + 1) = (n+1)^2$.

**Model answer.**

**Base case ($n = 0$):** $\displaystyle\sum_{i=0}^{0}(2i+1) = 1 = (0+1)^2 = 1$. ✓

**Induction step.** Assume $\displaystyle\sum_{i=0}^{k}(2i+1) = (k+1)^2$ (IH). Then:

$$\sum_{i=0}^{k+1}(2i+1) = \left(\sum_{i=0}^{k}(2i+1)\right) + (2(k+1) + 1)$$

$$= (k+1)^2 + 2k + 3 \quad\text{(by IH)}$$

$$= k^2 + 2k + 1 + 2k + 3 = k^2 + 4k + 4 = (k+2)^2 = ((k+1)+1)^2 \quad\checkmark$$

$\square$

---

### Q2 — Structural induction on lists

**Question.** Given $rev$ and $@$ as defined above, prove: $rev(xs\;@\;ys) = rev(ys)\;@\;rev(xs)$.

You may assume as lemmas: (i) $xs\;@\;[\;] = xs$, (ii) $(xs\;@\;ys)\;@\;zs = xs\;@\;(ys\;@\;zs)$.

**Model answer.** Induction on $xs$.

**Base case ($xs = [\;]$):**

$$rev([\;]\;@\;ys) = rev(ys)$$

$$rev(ys)\;@\;rev([\;]) = rev(ys)\;@\;[\;] = rev(ys) \quad\text{(by lemma (i))} \quad\checkmark$$

**Induction step ($xs = a :: as$).** Assume $rev(as\;@\;ys) = rev(ys)\;@\;rev(as)$ (IH).

$$rev((a :: as)\;@\;ys) = rev(a :: (as\;@\;ys)) = rev(as\;@\;ys)\;@\;[a]$$

$$= (rev(ys)\;@\;rev(as))\;@\;[a] \quad\text{(by IH)}$$

$$= rev(ys)\;@\;(rev(as)\;@\;[a]) \quad\text{(by lemma (ii))}$$

$$= rev(ys)\;@\;rev(a :: as) \quad\checkmark$$

$\square$

---

### Q3 — Structural induction on trees

**Question.** Let $leaves(Lf) = 1$ and $leaves(Br(x, t_1, t_2)) = leaves(t_1) + leaves(t_2)$. Prove: $leaves(t) = size(t) + 1$.

**Model answer.** Induction on $t$.

**Base case ($t = Lf$):** $leaves(Lf) = 1 = 0 + 1 = size(Lf) + 1$. ✓

**Induction step ($t = Br(x, t_1, t_2)$).** Assume $leaves(t_i) = size(t_i) + 1$ for $i = 1, 2$ (IH).

$$leaves(Br(x, t_1, t_2)) = leaves(t_1) + leaves(t_2)$$

$$= (size(t_1) + 1) + (size(t_2) + 1) \quad\text{(by IH)}$$

$$= size(t_1) + size(t_2) + 2 = (1 + size(t_1) + size(t_2)) + 1$$

$$= size(Br(x, t_1, t_2)) + 1 \quad\checkmark$$

$\square$

---

### Q4 — Induction on formulas

**Question.** For $(\lor, \lnot)$-formulas $F$, let $depth(Q) = 0$, $depth(\lnot F) = 1 + depth(F)$, $depth(F_1 \lor F_2) = 1 + \max(depth(F_1), depth(F_2))$. Prove: $\text{letters}(F) \leq 2^{depth(F)}$.

**Model answer.** Induction on $F$.

**Base ($F = Q$):** $\text{letters}(Q) = 1 \leq 1 = 2^0 = 2^{depth(Q)}$. ✓

**Case $F = \lnot G$.** Assume $\text{letters}(G) \leq 2^{depth(G)}$ (IH).

$$\text{letters}(\lnot G) = \text{letters}(G) \leq 2^{depth(G)} \leq 2^{1 + depth(G)} = 2^{depth(\lnot G)} \quad\checkmark$$

**Case $F = F_1 \lor F_2$.** Assume $\text{letters}(F_i) \leq 2^{depth(F_i)}$ for $i = 1, 2$ (IH). Let $d = \max(depth(F_1), depth(F_2))$.

$$\text{letters}(F_1 \lor F_2) = \text{letters}(F_1) + \text{letters}(F_2) \leq 2^{depth(F_1)} + 2^{depth(F_2)}$$

$$\leq 2^d + 2^d = 2 \cdot 2^d = 2^{d+1} = 2^{depth(F_1 \lor F_2)} \quad\checkmark$$

$\square$

---

### Q5 — Two-step induction

**Question.** Define the Fibonacci sequence: $F_0 = 0$, $F_1 = 1$, $F_{n+2} = F_{n+1} + F_n$. Prove by two-step induction: $\forall n \geq 0.\; F_n \leq 2^n$.

**Model answer.**

**Base $n = 0$:** $F_0 = 0 \leq 1 = 2^0$. ✓

**Base $n = 1$:** $F_1 = 1 \leq 2 = 2^1$. ✓

**Induction step.** Assume $F_k \leq 2^k$ and $F_{k+1} \leq 2^{k+1}$ (IH). Then:

$$F_{k+2} = F_{k+1} + F_k \leq 2^{k+1} + 2^k \quad\text{(by IH)}$$

$$\leq 2^{k+1} + 2^{k+1} = 2 \cdot 2^{k+1} = 2^{k+2} \quad\checkmark$$

$\square$

---

## 3. MUST-KNOW KEY POINTS

- **Ordinary induction on $\mathbb{N}$:** base $P(0)$, step $P(k) \to P(s(k))$. Always state the IH explicitly.
- **Structural induction** generalises to any inductively defined structure: prove $P$ for each **constructor**, assuming $P$ for the constructor's recursive arguments.
- **Lists:** base $P([\;])$, step $P(xs) \to P(x :: xs)$. Key functions: $len$, $@$, $rev$.
- **Binary trees:** base $P(Lf)$, step $P(t_1) \land P(t_2) \to P(Br(x, t_1, t_2))$. Key functions: $size$, $refl$.
- **Formulas:** induction follows the grammar. Each case in the grammar gives one case in the proof.
- **Two-step induction:** two base cases ($P(0)$, $P(1)$), step assumes $P(k) \land P(s(k))$ to prove $P(s(s(k)))$. Equivalent in strength to ordinary induction.
- **Auxiliary lemmas** are often needed (e.g. associativity of $@$, $xs\;@\;[\;] = xs$). State and prove them separately before the main proof.
- **Every step must cite a definition or the IH** — no unjustified leaps.

---

## 4. HIGH-PRIORITY TOPICS

### 🔴 Must Know

- **Ordinary induction principle** on $\mathbb{N}$: statement, base case, IH, step case.
- **Structural induction on lists:** principle, examples with $len$, $@$, $rev$.
- **Structural induction on binary trees:** principle, examples with $size$, $refl$.
- **How to write a clean induction proof:** state claim, state what you induct on, label base/step/IH, conclude.
- **Recursive function definitions** for lists ($len$, $@$, $rev$) and trees ($size$, $refl$) — you must be able to unfold these by hand.

### 🟡 Important

- **Two-step induction:** when it's needed (two base cases), how the IH differs, equivalence with ordinary induction.
- **Structural induction on formulas:** the grammar defines the cases.
- **Auxiliary lemma pattern:** recognising when a subgoal needs a separate lemma (e.g. associativity of $@$).
- **The "letters vs ors" counting argument** as a template for formula induction.

### 🟢 Useful but Lower Priority

- **Strong induction** (assume $P(j)$ for all $j < k$) — strictly more convenient but equivalent to ordinary induction.
- **Well-founded induction** as the general principle unifying all variants.
- Detailed proof that two-step and ordinary induction are inter-derivable (the $Q(n) = P(n) \land P(n+1)$ trick).

---

## 5. TOPIC INTERCONNECTIONS & BIGGER PICTURE

- **FOL and induction:** FOL formulas are inductively defined structures, so **metatheorems** about FOL (e.g. every formula has a prenex form, substitution lemma, soundness) are proved by structural induction on formulas.
- **Data structures in algorithms:** Lists and trees appear throughout algorithms courses. Correctness proofs for recursive algorithms on these structures use exactly the structural induction principles here.
- **Recursion = induction, computationally:** A recursive function over an inductive type mirrors an induction proof. The base case handles constructors with no recursive arguments; the recursive call uses the "induction hypothesis" on substructures.
- **Program verification:** Proving loop invariants often uses ordinary induction on iteration count. Proving properties of recursive programs uses structural induction.
- **Type theory and functional programming:** Languages like Haskell, OCaml, and Coq have inductive types with built-in structural recursion/induction principles — the same ideas formalised in a programming language.

---

## 6. EXAM STRATEGY TIPS

- **Always state:** (1) what property $P$ you are proving, (2) what you are inducting on, (3) the base case(s), (4) the IH (written out explicitly), (5) the step case. Missing any of these loses marks.
- **Unfold definitions mechanically.** Each equality step should cite either a definition (e.g. "by def. of $rev$") or the IH. Examiners look for this discipline.
- **Auxiliary lemmas:** If your step case gets stuck, it almost certainly needs a lemma. Common ones: $xs\;@\;[\;] = xs$, associativity of $@$, $0 + y = y$. State them, prove them (by induction), then use them.
- **Two-step induction cue:** if the recursive definition refers to $n - 2$ or the function is defined by $F(n) = \ldots F(n-1) \ldots F(n-2) \ldots$, two-step induction is the natural choice.
- **Tree proofs have two IHs.** Don't forget: in the branch case, you assume $P(t_1)$ **and** $P(t_2)$.
- **Formula induction:** one case per grammar rule. $\lnot$ case has one IH, binary connective case has two.
- **Sanity check:** after the proof, verify the base case with a tiny example (e.g. $n=0$ or $xs = [\;]$). If it doesn't typecheck, something went wrong.
- **Presentation:** use clear formatting with labelled cases. A proof that is correct but unreadable will lose marks.

---

*These notes synthesise Lectures 9–11 on proof by induction for COMP0003 Formal Logic.*
