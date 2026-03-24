# Complete Induction & Infinite Descent — COMP0003 Formal Logic

*Lecture-style notes covering Logic Lecture 12. **Complete (strong) induction** generalises ordinary induction by letting the inductive hypothesis assume $P(k')$ for **all** $k' < k$, eliminating the need for a separate base case. **Infinite descent** (Fermat) is logically equivalent: if every counterexample implies a smaller counterexample, the property holds universally over $\mathbb{N}$. Both techniques shine where ordinary induction's "assume $P(k)$, show $P(k+1)$" structure is awkward — for instance, the Fundamental Theorem of Arithmetic and the irrationality of $\sqrt{2}$.*

---

## 1. COMPLETE TOPIC SUMMARY

### Ordinary induction — quick recap

Ordinary (weak) induction over $\mathbb{N}$ requires two steps:

1. **Base case.** Show $P(0)$.
2. **Inductive step.** Assume $P(k)$, show $P(k+1)$.

**Conclusion:** $\forall n \in \mathbb{N}.\; P(n)$.

This works perfectly when $P(k+1)$ depends only on $P(k)$, but becomes cumbersome when the argument needs $P(j)$ for arbitrary $j < k+1$.

---

### Complete (strong) induction

Complete induction collapses the base case into the inductive step by strengthening the hypothesis.

**Principle.** To prove $\forall n \in \mathbb{N}.\; P(n)$, it suffices to prove a single step:

$$\forall k \in \mathbb{N}.\;\Big(\forall k'.\; (k' < k \to P(k'))\Big) \to P(k)$$

That is: for **every** $k$, if $P$ holds for **all** predecessors of $k$, then $P(k)$ follows.

**Inference rule (formal):**

$$\frac{\forall k \in \mathbb{N}.\;\big(\forall k' < k.\; P(k')\big) \to P(k)}{\forall n \in \mathbb{N}.\; P(n)}$$

**Why no explicit base case?** When $k = 0$, the set $\{k' \mid k' < 0\}$ is **empty**, so the premise $\forall k' < 0.\; P(k')$ is **vacuously true**. Thus the step for $k = 0$ reduces to showing $P(0)$ outright — the base case is **embedded**.

---

### Example — every integer n ≥ 2 is a product of primes

**Claim.** For all $n \geq 2$, $n$ can be written as a product of one or more primes (the Fundamental Theorem of Arithmetic, existence half).

**Proof by complete induction on $n$.**

Let $k \geq 2$. Assume (complete IH): for all $k'$ with $2 \leq k' < k$, $k'$ is a product of primes.

- **Case 1:** $k$ is prime. Then $k$ is itself a product of primes (a single-factor product).
- **Case 2:** $k$ is composite. Then $k = a \cdot b$ with $2 \leq a, b < k$. By the complete IH, both $a$ and $b$ are products of primes, so $k = a \cdot b$ is a product of primes.

In both cases, $P(k)$ holds. By complete induction, $\forall n \geq 2.\; P(n)$. $\blacksquare$

**Why ordinary induction struggles here:** In Case 2, the factors $a$ and $b$ satisfy $a < k$ and $b < k$, but neither needs to equal $k - 1$. Ordinary induction only gives $P(k-1)$, which is insufficient.

---

### The Ackermann function

The **Ackermann function** $A : \mathbb{N} \times \mathbb{N} \to \mathbb{N}$ is defined recursively:

$$A(0, y) = s(y)$$

$$A(s(x), 0) = A(x, s(0))$$

$$A(s(x), s(y)) = A(x, A(s(x), y))$$

where $s(n) = n + 1$ is the successor function.

**Key property:** $A$ grows extraordinarily fast — faster than any primitive recursive function. The challenge is proving that $A$ is **total** (terminates on all inputs).

#### Proving the Ackermann function is total via complete induction with lexicographic ordering

The recursive calls do not simply decrease a single argument, so ordinary induction on one variable is insufficient. Instead, use **complete induction** on pairs $(x, y)$ ordered **lexicographically**:

$$(x_1, y_1) <_{\text{lex}} (x_2, y_2) \iff x_1 < x_2,\;\text{or}\;(x_1 = x_2 \text{ and } y_1 < y_2)$$

**Claim:** $A(x, y)$ is defined for all $(x, y) \in \mathbb{N}^2$.

**Proof sketch (complete induction on $<_{\text{lex}}$).** Assume $A(x', y')$ is defined for all $(x', y') <_{\text{lex}} (x, y)$.

- **Case** $x = 0$: $A(0, y) = s(y)$, which is defined. No recursive call needed.
- **Case** $x = s(x'), y = 0$: $A(s(x'), 0) = A(x', s(0))$. Since $(x', s(0)) <_{\text{lex}} (s(x'), 0)$ (the first component decreased), the IH gives that $A(x', s(0))$ is defined.
- **Case** $x = s(x'), y = s(y')$: $A(s(x'), s(y')) = A(x', A(s(x'), y'))$.
    - First, $(s(x'), y') <_{\text{lex}} (s(x'), s(y'))$ (same first component, second decreased), so by the IH, $A(s(x'), y')$ is defined — call its value $v$.
    - Then $(x', v) <_{\text{lex}} (s(x'), s(y'))$ (first component decreased), so by the IH, $A(x', v)$ is defined.

In all cases, $A(x, y)$ is defined. By complete induction on $<_{\text{lex}}$, $A$ is total. $\blacksquare$

---

### Equivalence of complete induction and ordinary induction

Complete induction and ordinary induction are **logically equivalent** — each can derive the other.

#### Ordinary implies complete

To derive the complete induction principle from ordinary induction, define an auxiliary property:

$$Q(n) \;\equiv\; \forall k \leq n.\; P(k)$$

Prove $\forall n.\; Q(n)$ by ordinary induction:

- **Base:** $Q(0)$: $P(0)$ holds because the complete induction step with $k = 0$ (vacuous hypothesis) gives $P(0)$.
- **Step:** Assume $Q(n)$ (i.e. $\forall k \leq n.\; P(k)$). For $k = n + 1$, we have $\forall k' < n + 1.\; P(k')$ (which is exactly $Q(n)$), so by the complete induction step, $P(n+1)$. Combined with $Q(n)$, this gives $Q(n+1)$.

Therefore $\forall n.\; Q(n)$, which implies $\forall n.\; P(n)$.

#### Complete implies ordinary

Conversely, if we have ordinary induction (base $P(0)$ and step $P(k) \to P(k+1)$), we can derive the complete induction principle. The complete induction step $(\forall k' < k.\; P(k')) \to P(k)$ is **stronger** than the ordinary step $P(k-1) \to P(k)$ — if we can show $P(k)$ given only $P(k-1)$, we can certainly show $P(k)$ given $P(k')$ for all $k' < k$. So the ordinary induction step is a special case of the complete induction step, and the derivation goes through by applying ordinary induction to build up $\forall k' < k.\; P(k')$ incrementally.

---

### Infinite descent (Fermat's method)

**Infinite descent** is a proof technique attributed to Fermat. It proves $\forall n \in \mathbb{N}.\; P(n)$ by contradiction: assume a counterexample exists and show it implies a **smaller** counterexample, giving an infinite descending chain in $\mathbb{N}$ — which is impossible.

**Formal principle:**

$$\frac{\forall k \in \mathbb{N}.\;\neg P(k) \to \exists k'.\;(k' < k \;\wedge\; \neg P(k'))}{\forall n \in \mathbb{N}.\; P(n)}$$

**Reasoning:** Suppose $\exists n.\; \neg P(n)$. Let $n_0$ be such a counterexample. The premise gives $n_1 < n_0$ with $\neg P(n_1)$. Repeating gives $n_2 < n_1$ with $\neg P(n_2)$, and so on:

$$n_0 > n_1 > n_2 > \cdots$$

This is an **infinite strictly descending sequence** of natural numbers, which cannot exist (the natural numbers are **well-ordered** — every nonempty subset has a least element). Contradiction. Therefore $\forall n.\; P(n)$. $\blacksquare$

**No infinite descending chains in $\mathbb{N}$:** This is equivalent to the well-ordering principle. Every nonempty subset of $\mathbb{N}$ has a minimum, so any descending chain must terminate.

---

### Example — every natural number is even or odd (by descent)

**Claim.** $\forall n \in \mathbb{N}.\;$ $n$ is even or $n$ is odd.

**Proof by infinite descent.** Suppose for contradiction that some $n_0$ is neither even nor odd.

- $n_0 \neq 0$ (since $0$ is even).
- So $n_0 = n_1 + 1$ for some $n_1 < n_0$.
- If $n_1$ were even, say $n_1 = 2m$, then $n_0 = 2m + 1$ would be odd — contradiction.
- If $n_1$ were odd, say $n_1 = 2m + 1$, then $n_0 = 2m + 2 = 2(m+1)$ would be even — contradiction.
- So $n_1$ is also neither even nor odd.

We have produced a smaller counterexample $n_1 < n_0$. Iterating gives an infinite descending chain in $\mathbb{N}$, which is impossible. Therefore every natural number is even or odd. $\blacksquare$

---

### Example — square root of 2 is irrational (by descent)

**Claim.** $\sqrt{2}$ is irrational.

**Proof by infinite descent (on $y$).** Suppose for contradiction that $\sqrt{2}$ is rational, so $\sqrt{2} = x_0 / y_0$ for some positive integers $x_0, y_0$. Then $2 y_0^2 = x_0^2$.

From $x_0^2 = 2 y_0^2$, we get that $x_0^2$ is even, hence $x_0$ is even (since the square of an odd number is odd). Write $x_0 = 2k$. Then $2 y_0^2 = 4k^2$, so $y_0^2 = 2k^2$. By the same argument, $y_0$ is even; write $y_0 = 2m$.

Now set $x_1 = k$ and $y_1 = m$. We have $\sqrt{2} = x_1 / y_1$ with $y_1 = y_0 / 2 < y_0$.

This gives a new representation with a **strictly smaller** denominator. Repeating produces an infinite descending chain of positive integers:

$$y_0 > y_1 > y_2 > \cdots$$

This is impossible in $\mathbb{N}$. Contradiction. Therefore $\sqrt{2}$ is irrational. $\blacksquare$

**Connection to the standard proof:** The "lowest terms" proof asserts $\gcd(x, y) = 1$ then derives $2 \mid x$ and $2 \mid y$, contradicting coprimality. Infinite descent replaces "assume lowest terms" with "produce a smaller fraction" — logically the same, but framed as descent rather than a direct contradiction with coprimality.

---

### Equivalence of infinite descent and complete induction

The premise of infinite descent is:

$$\forall k.\; \neg P(k) \to \exists k' < k.\; \neg P(k')$$

Taking the **contrapositive** of the inner implication:

$$\forall k.\; \big(\forall k' < k.\; P(k')\big) \to P(k)$$

This is exactly the premise of **complete induction**. The two principles are **logically equivalent** — they are contrapositives of each other. Any proof by one can be mechanically rewritten as a proof by the other.

**Summary of equivalences:**

$$\text{Ordinary induction} \iff \text{Complete induction} \iff \text{Infinite descent} \iff \text{Well-ordering of } \mathbb{N}$$

---

## 2. EXAM-STYLE QUESTIONS (WITH MODEL ANSWERS)

### Q1 — State and compare the two induction principles

**Question.** State the principles of (a) ordinary induction and (b) complete (strong) induction over $\mathbb{N}$. Why does complete induction not require a separate base case?

**Model answer.**

(a) **Ordinary induction:** If $P(0)$ holds, and $\forall k.\; P(k) \to P(k+1)$, then $\forall n \in \mathbb{N}.\; P(n)$.

(b) **Complete induction:** If $\forall k \in \mathbb{N}.\; (\forall k' < k.\; P(k')) \to P(k)$, then $\forall n \in \mathbb{N}.\; P(n)$.

Complete induction has **no separate base case** because when $k = 0$, the set $\{k' \mid k' < 0\}$ is empty, making the hypothesis $\forall k' < 0.\; P(k')$ **vacuously true**. The inductive step at $k = 0$ therefore requires proving $P(0)$ from a trivially true assumption — effectively embedding the base case. In ordinary induction, the hypothesis at the base ($P(k)$ for $k = 0$) is not yet available, so $P(0)$ must be shown separately.

---

### Q2 — Product of primes by complete induction

**Question.** Prove by complete induction that every integer $n \geq 2$ can be expressed as a product of primes.

**Model answer.** Let $P(n)$ be "$n$ is a product of one or more primes."

**Complete induction step:** Let $k \geq 2$ and assume $P(k')$ for all $2 \leq k' < k$.

- If $k$ is **prime**, then $k$ is trivially a product of primes (just $k$ itself).
- If $k$ is **composite**, then $k = a \cdot b$ where $2 \leq a < k$ and $2 \leq b < k$. By the inductive hypothesis, $a = p_1 \cdots p_r$ and $b = q_1 \cdots q_s$ for primes $p_i, q_j$. Therefore $k = p_1 \cdots p_r \cdot q_1 \cdots q_s$, a product of primes.

By complete induction, $P(n)$ holds for all $n \geq 2$. $\blacksquare$

**Why ordinary induction is awkward here:** Knowing $P(k-1)$ is insufficient — the factors $a, b$ can be any values less than $k$, not just $k - 1$.

---

### Q3 — Ackermann function recursive calls

**Question.** The Ackermann function is defined by $A(0, y) = s(y)$, $A(s(x), 0) = A(x, s(0))$, $A(s(x), s(y)) = A(x, A(s(x), y))$. Explain why the recursive call $A(s(x), s(y)) = A(x, A(s(x), y))$ terminates, using lexicographic ordering on pairs.

**Model answer.** We use complete induction on pairs $(x, y)$ under the lexicographic order $<_{\text{lex}}$.

To evaluate $A(s(x), s(y))$, two recursive calls are made:

1. **Inner call** $A(s(x), y)$: the pair $(s(x), y)$ satisfies $(s(x), y) <_{\text{lex}} (s(x), s(y))$ because the first components are equal and $y < s(y)$. By the IH, this call terminates and returns some value $v$.

2. **Outer call** $A(x, v)$: the pair $(x, v)$ satisfies $(x, v) <_{\text{lex}} (s(x), s(y))$ because $x < s(x)$ (the first component strictly decreased). By the IH, this call terminates.

Since every recursive call is on a lexicographically smaller pair, and there are no infinite descending chains in $\mathbb{N} \times \mathbb{N}$ under $<_{\text{lex}}$, the computation terminates.

---

### Q4 — Infinite descent: square root of 2 is irrational

**Question.** Prove that $\sqrt{2}$ is irrational using infinite descent.

**Model answer.** Suppose for contradiction that $\sqrt{2} = x / y$ for positive integers $x, y$. Then $x^2 = 2y^2$.

Since $x^2$ is even, $x$ is even; write $x = 2k$. Substituting: $4k^2 = 2y^2$, so $y^2 = 2k^2$. Thus $y$ is also even; write $y = 2m$.

Now $\sqrt{2} = 2k / 2m = k / m$ with $m = y/2 < y$. We have constructed a new representation of $\sqrt{2}$ as a ratio of positive integers with a **strictly smaller denominator**.

Repeating this argument produces an infinite strictly descending sequence of positive integer denominators $y > m > \cdots$, which is impossible in $\mathbb{N}$.

Contradiction. Therefore $\sqrt{2}$ is irrational. $\blacksquare$

---

### Q5 — Prove descent and complete induction are equivalent

**Question.** Show that the principle of infinite descent is logically equivalent to complete induction, by rewriting the premise of one into the other.

**Model answer.** The premise of **infinite descent** is:

$$\forall k.\; \neg P(k) \to \exists k' < k.\; \neg P(k') \tag{D}$$

We rewrite using standard logical equivalences. The contrapositive of $\neg P(k) \to \exists k' < k.\; \neg P(k')$ is:

$$\neg(\exists k' < k.\; \neg P(k')) \to \neg\neg P(k)$$

Applying $\neg \exists = \forall \neg$ and double negation elimination:

$$(\forall k' < k.\; P(k')) \to P(k)$$

Universally quantifying over $k$:

$$\forall k.\; (\forall k' < k.\; P(k')) \to P(k) \tag{CI}$$

This is exactly the premise of **complete induction**. Since (D) and (CI) are contrapositives of each other (after distributing the outer $\forall k$), they are logically equivalent. Therefore infinite descent and complete induction are the same principle. $\blacksquare$

---

## 3. MUST-KNOW KEY POINTS

- **Complete induction** assumes $P(k')$ for **all** $k' < k$ (not just $k - 1$), then derives $P(k)$. The base case is handled **vacuously** at $k = 0$.
- **Formal rule:** $\big(\forall k.\; (\forall k' < k.\; P(k')) \to P(k)\big) \vdash \forall n \in \mathbb{N}.\; P(n)$.
- **Use complete induction** when the inductive step needs $P(j)$ for arbitrary $j < k$ (e.g. factors of a composite number).
- **Ackermann function** requires complete induction on **lexicographically ordered pairs** $(x, y)$ because recursive calls decrease different components.
- **Infinite descent** (Fermat): if $\neg P(k) \to \exists k' < k.\; \neg P(k')$, then $\forall n.\; P(n)$. Every counterexample producing a smaller counterexample yields an impossible infinite descending chain in $\mathbb{N}$.
- **Complete induction $\iff$ infinite descent:** they are contrapositives — rewrite $\neg P(k) \to \exists k' < k.\; \neg P(k')$ as $(\forall k' < k.\; P(k')) \to P(k)$.
- **All four equivalent:** ordinary induction $\iff$ complete induction $\iff$ infinite descent $\iff$ well-ordering of $\mathbb{N}$.

---

## 4. HIGH-PRIORITY TOPICS

### 🔴 Must Know

- **Complete induction principle:** inference rule with the $\forall k' < k$ hypothesis; why the base case is vacuous.
- **When to use complete induction** over ordinary: argument needs $P(j)$ for $j < k$ other than $k - 1$.
- **"Product of primes" proof** as the canonical example of complete induction.
- **Infinite descent principle:** formal statement; "counterexample begets smaller counterexample" reasoning.
- **$\sqrt{2}$ irrationality proof** by descent on the denominator.
- **Equivalence:** descent $\iff$ complete induction via contrapositive.

### 🟡 Important

- **Ackermann function definition** and the three clauses; why single-variable induction fails.
- **Lexicographic ordering** on pairs: $(x_1, y_1) <_{\text{lex}} (x_2, y_2)$ and why it is well-founded on $\mathbb{N} \times \mathbb{N}$.
- **Proof that $A$ is total** — identifying which component decreases in each recursive case.
- **Ordinary $\iff$ complete induction** proof sketch using the auxiliary $Q(n) = \forall k \leq n.\; P(k)$.
- **"Even or odd" example** by descent.

### 🟢 Useful but Lower Priority

- Full formal details of well-ordering $\iff$ induction $\iff$ descent equivalence circle.
- Growth rate of the Ackermann function (faster than any primitive recursive function).
- Descent proofs in number theory beyond $\sqrt{2}$ (e.g. Fermat's original applications).

---

## 5. TOPIC INTERCONNECTIONS & BIGGER PICTURE

- **Ordinary induction (Lecture 11)** is the special case where the hypothesis is $P(k)$ only. Complete induction subsumes it; recognising when the stronger hypothesis is needed is a core exam skill.
- **Structural induction** (on trees, formulas, etc.) parallels complete induction: the inductive hypothesis applies to **all** substructures, not just an immediate predecessor. Both generalise the same well-foundedness principle.
- **Propositional and first-order logic (Lectures 1–10)** supply the formal language in which induction principles are stated. The quantifier manipulations $\neg \exists \leftrightarrow \forall \neg$ used to show descent $\iff$ complete induction are direct applications of FOL equivalences.
- **Well-ordering** of $\mathbb{N}$ underpins all forms of induction over $\mathbb{N}$. In set theory, the well-ordering principle, Zorn's lemma, and the axiom of choice are equivalent — a deeper connection encountered in later courses.
- **Modal logic (Lectures 13–15)** uses Kripke frames with accessibility relations; proving properties of frames (e.g. reflexivity, transitivity) sometimes involves inductive arguments on paths, connecting back to the induction toolkit.

---

## 6. EXAM STRATEGY TIPS

- **State the principle before using it.** Write the complete induction rule or the descent principle explicitly at the start of your proof. This earns method marks even if the subsequent argument has a slip.
- **Vacuous truth for the base case:** If asked "where is the base case?", explain that when $k = 0$ the hypothesis $\forall k' < 0.\; P(k')$ is vacuously true, so $P(0)$ must be shown from nothing — the base case is embedded, not missing.
- **Descent proofs need the chain argument.** Don't just say "we get a smaller counterexample." Explicitly state that repeating this process gives an infinite descending chain in $\mathbb{N}$, which contradicts well-ordering.
- **Ackermann questions:** Identify which argument decreases lexicographically for each clause. Draw a table of the three cases and annotate which component drops. Don't claim "both decrease" — in the third clause, the inner call only decreases $y$, while the outer call decreases $x$.
- **Contrapositive rewrite:** For "show descent $\iff$ complete induction," write the descent premise, take the contrapositive of the inner implication, apply $\neg \exists = \forall \neg$ and double negation elimination. Examiners want to see each logical step.
- **Link to ordinary induction:** If asked "are these equivalent?", sketch the auxiliary-property proof ($Q(n) = \forall k \leq n.\; P(k)$) in both directions. A one-line "they're both induction" is insufficient.

---

*These notes cover Logic Lecture 12 (Complete Induction & Infinite Descent) for COMP0003 Formal Logic; follow your lecturer's notation if it differs.*
