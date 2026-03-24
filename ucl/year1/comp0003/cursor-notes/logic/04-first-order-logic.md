# First-Order Logic — COMP0003 Formal Logic

*Lecture-style notes covering Lectures 5–8b. **First-order logic (FOL)** extends propositional logic by letting us talk about **objects**, their **properties**, and **relationships**, and by **quantifying** over them. The leap from "propositions as atoms" to "structured formulas with variables and quantifiers" unlocks the expressiveness needed for mathematics, databases, and verification.*

---

## 1. COMPLETE TOPIC SUMMARIES

### Motivation: why propositional logic is not enough

Propositional logic treats each proposition as an **opaque atom**. It cannot:

- **Access internal structure.** "Alice is tall" and "Bob is tall" are unrelated atoms $P$ and $Q$ — we cannot express that both share the **predicate** "is tall."
- **Quantify.** "Everyone is tall" or "someone is tall" have no propositional representation without listing every individual.

First-order logic solves both problems by introducing **terms** (naming objects), **predicates** (expressing properties/relations), and **quantifiers** ($\forall$, $\exists$).

---

### First-order language (signature Σ = (F, P))

A **first-order language** (or **signature**) specifies the non-logical vocabulary:

| Component | Notation | Description |
|-----------|----------|-------------|
| **Function symbols** | $F$ | Each $f \in F$ has an **arity** $k \geq 0$. Arity-0 functions are **constants**. |
| **Predicate symbols** | $P$ | Each $R \in P$ has an **arity** $k \geq 0$. Arity-0 predicates are **propositions**. |

**Example — Peano arithmetic:**

$$\Sigma_{PA} = (\{0, s, +, \times\},\;\{=, <\})$$

- $0$ is a constant (arity 0), $s$ is unary (arity 1), $+$ and $\times$ are binary (arity 2).
- $=$ and $<$ are binary predicates.

**Example — Family relations:**

$$\Sigma_{Fam} = (\{alice, bob\},\;\{Parent, Sibling\})$$

- $alice$, $bob$ are constants; $Parent$ and $Sibling$ are binary predicates.

---

### Terms

**Terms** name objects. They are built recursively:

1. Every **variable** $x, y, z, \ldots$ is a term.
2. If $f$ is a function symbol of arity $k$ and $t_1, \ldots, t_k$ are terms, then $f(t_1, \ldots, t_k)$ is a term.

**Examples** (over $\Sigma_{PA}$): $\;x$, $\;0$, $\;s(0)$, $\;s(s(x))$, $\;+(x, s(0))$ (usually written $x + s(0)$).

---

### Formulas

**Formulas** are built from **atomic formulas** using connectives and quantifiers:

1. **Atomic formula:** If $R$ is a predicate of arity $k$ and $t_1, \ldots, t_k$ are terms, then $R(t_1, \ldots, t_k)$ is a formula.
2. **Boolean connectives:** If $A$, $B$ are formulas, so are $\lnot A$, $A \land B$, $A \lor B$, $A \to B$, $A \leftrightarrow B$.
3. **Quantifiers:** If $A$ is a formula and $x$ a variable, then $\forall x\, A$ and $\exists x\, A$ are formulas.

**Examples:**

- $\forall x\,(P(x) \to Q(x))$ — "for all $x$, if $P(x)$ then $Q(x)$."
- $\exists x\,(P(x) \land R(x, y))$ — "there exists an $x$ such that $P(x)$ and $R(x, y)$."

---

### Free and bound variables; sentences

An occurrence of a variable $x$ in a formula is **bound** if it falls within the scope of a quantifier $\forall x$ or $\exists x$; otherwise it is **free**.

- In $\forall x\,(P(x) \to Q(x, y))$: $x$ is **bound**, $y$ is **free**.
- In $P(x) \land \exists x\, Q(x)$: the first $x$ in $P(x)$ is **free**; the $x$ in $Q(x)$ is **bound** by $\exists x$.

A formula with **no free variables** is called a **sentence**. Sentences have a definite truth value in any structure (no valuation needed for free variables).

---

### Translating English to FOL

**Strategy:** identify the **domain**, choose **predicate/function symbols**, then translate quantifier phrases.

| English | FOL (domain: people) |
|---------|----------------------|
| "Every student studies" | $\forall x\,(Student(x) \to Studies(x))$ |
| "Some student is happy" | $\exists x\,(Student(x) \land Happy(x))$ |
| "No student is lazy" | $\lnot \exists x\,(Student(x) \land Lazy(x))$, equivalently $\forall x\,(Student(x) \to \lnot Lazy(x))$ |
| "Every number has a successor" | $\forall x\, \exists y\,(y = s(x))$ |
| "There is a smallest element" | $\exists x\, \forall y\,(x \leq y)$ |

**Common pitfall:** "Every $A$ is $B$" uses $\to$ (not $\land$): $\forall x\,(A(x) \to B(x))$. "Some $A$ is $B$" uses $\land$ (not $\to$): $\exists x\,(A(x) \land B(x))$.

---

### Semantics: first-order structures

A **first-order structure** (or **model**) for signature $\Sigma = (F, P)$ is a triple:

$$M = (D,\; F^M,\; P^M)$$

| Component | Meaning |
|-----------|---------|
| $D$ | The **domain** (a non-empty set of objects) |
| $F^M$ | For each $f \in F$ of arity $k$: a function $f^M : D^k \to D$ |
| $P^M$ | For each $R \in P$ of arity $k$: a relation $R^M \subseteq D^k$ |

**Example.** Let $\Sigma = (\{0, s\}, \{<\})$ and define $M$ with:

- $D = \{0, 1, 2, 3\}$
- $0^M = 0$, $\;s^M(n) = \min(n+1, 3)$
- $<^M = \{(a,b) \in D^2 \mid a < b\}$

---

### Valuations and interpreting terms

A **valuation** is a function $\rho : \text{Vars} \to D$ assigning each variable a domain element.

**Extending $\rho$ to terms** (written $\llbracket t \rrbracket^M_\rho$ or simply $t^{M,\rho}$):

- $\llbracket x \rrbracket^M_\rho = \rho(x)$
- $\llbracket f(t_1, \ldots, t_k) \rrbracket^M_\rho = f^M(\llbracket t_1 \rrbracket^M_\rho, \ldots, \llbracket t_k \rrbracket^M_\rho)$

---

### The satisfaction relation (M ⊧_ρ A)

The **satisfaction relation** is defined recursively:

| Formula $A$ | $M \models_\rho A$ iff |
|-------------|------------------------|
| $R(t_1, \ldots, t_k)$ | $(\llbracket t_1 \rrbracket^M_\rho, \ldots, \llbracket t_k \rrbracket^M_\rho) \in R^M$ |
| $\lnot A$ | $M \not\models_\rho A$ |
| $A \land B$ | $M \models_\rho A$ and $M \models_\rho B$ |
| $A \lor B$ | $M \models_\rho A$ or $M \models_\rho B$ |
| $A \to B$ | $M \not\models_\rho A$ or $M \models_\rho B$ |
| $A \leftrightarrow B$ | $M \models_\rho A$ iff $M \models_\rho B$ |
| $\forall x\, A$ | for **every** $d \in D$: $M \models_{\rho[x \mapsto d]} A$ |
| $\exists x\, A$ | for **some** $d \in D$: $M \models_{\rho[x \mapsto d]} A$ |

Here $\rho[x \mapsto d]$ denotes the **updated valuation** that maps $x$ to $d$ and agrees with $\rho$ on all other variables.

**Worked example.** Let $M$ have $D = \{1, 2, 3\}$, $<^M$ the usual ordering. Is $M \models \forall x\, \exists y\,(x < y)$?

- For $x = 1$: choose $y = 2$, $1 < 2$ ✓
- For $x = 2$: choose $y = 3$, $2 < 3$ ✓
- For $x = 3$: need $y$ with $3 < y$, but max is 3 ✗

So $M \not\models \forall x\, \exists y\,(x < y)$.

---

### Satisfiability and validity

| Concept | Definition |
|---------|------------|
| **Satisfiable in $M$** | There exists a valuation $\rho$ such that $M \models_\rho A$ |
| **Valid in $M$** (written $M \models A$) | For **every** valuation $\rho$: $M \models_\rho A$ |
| **Satisfiable** (generally) | There exists **some** structure $M$ and valuation $\rho$ with $M \models_\rho A$ |
| **Valid** (logically valid, written $\models A$) | For **every** structure $M$ and **every** valuation $\rho$: $M \models_\rho A$ |

A formula is **valid** iff its negation is **unsatisfiable**. For sentences (no free variables), satisfiability/validity in $M$ does not depend on $\rho$.

---

### Substitution and variable capture

**Substitution** $A[t/x]$ replaces every **free** occurrence of $x$ in $A$ with the term $t$.

**Variable capture warning.** If $t$ contains a variable $y$ and a free occurrence of $x$ in $A$ lies within the scope of $\forall y$ or $\exists y$, then the substitution **captures** $y$, changing the meaning.

**Example of capture:** Let $A = \exists y\,(x < y)$ and $t = y + 1$.

$$A[t/x] = \exists y\,(y + 1 < y)$$

The free $y$ in $t$ has been captured by $\exists y$ — the meaning changes from "something is bigger than $y+1$" to the (always false) "$y + 1 < y$." To avoid this, **rename the bound variable** first: $\exists z\,(x < z)$, then substitute: $\exists z\,(y + 1 < z)$ ✓.

---

### Key equivalences for quantifiers

**Quantifier reordering:**

$$\forall x\, \forall y\, A \equiv \forall y\, \forall x\, A \qquad\qquad \exists x\, \exists y\, A \equiv \exists y\, \exists x\, A$$

**Quantifier duality (De Morgan for quantifiers):**

$$\lnot \forall x\, A \equiv \exists x\, \lnot A \qquad\qquad \lnot \exists x\, A \equiv \forall x\, \lnot A$$

**Distribution:**

$$\forall x\,(A \land B) \equiv \forall x\, A \;\land\; \forall x\, B$$

$$\exists x\,(A \lor B) \equiv \exists x\, A \;\lor\; \exists x\, B$$

**Important non-equivalences:**

$$\forall x\, \exists y\, A \;\not\equiv\; \exists y\, \forall x\, A$$

$$\exists x\,(A \land B) \;\not\equiv\; \exists x\, A \;\land\; \exists x\, B$$

$$\forall x\,(A \lor B) \;\not\equiv\; \forall x\, A \;\lor\; \forall x\, B$$

**Intuition for $\forall x\, \exists y$ vs $\exists y\, \forall x$:** In $\forall x\, \exists y\, R(x,y)$ the choice of $y$ can **depend** on $x$; in $\exists y\, \forall x\, R(x,y)$ a **single** $y$ must work for all $x$.

---

### Prenex normal form

A formula is in **prenex normal form (PNF)** if it has the shape:

$$Q_1 x_1\, Q_2 x_2 \cdots Q_n x_n\;\; \varphi$$

where each $Q_i \in \{\forall, \exists\}$ (the **prefix**) and $\varphi$ is **quantifier-free** (the **matrix**).

**4-step conversion procedure:**

1. **Eliminate $\to$ and $\leftrightarrow$:**
    - $A \to B \;\leadsto\; \lnot A \lor B$
    - $A \leftrightarrow B \;\leadsto\; (\lnot A \lor B) \land (A \lor \lnot B)$

2. **Push $\lnot$ inward** using De Morgan laws and quantifier duality:
    - $\lnot(A \land B) \;\leadsto\; \lnot A \lor \lnot B$
    - $\lnot(A \lor B) \;\leadsto\; \lnot A \land \lnot B$
    - $\lnot \forall x\, A \;\leadsto\; \exists x\, \lnot A$
    - $\lnot \exists x\, A \;\leadsto\; \forall x\, \lnot A$
    - $\lnot \lnot A \;\leadsto\; A$

3. **Rename bound variables** so that every quantifier binds a **distinct** variable (and no bound variable coincides with any free variable). This prevents capture when moving quantifiers.

4. **Move quantifiers out** to the front. If $x$ is not free in $B$:
    - $(\forall x\, A) \land B \;\leadsto\; \forall x\,(A \land B)$
    - $(\exists x\, A) \lor B \;\leadsto\; \exists x\,(A \lor B)$
    - and symmetric variants.

**Worked example.** Convert $\forall x\, P(x) \to \exists x\, Q(x)$ to PNF:

1. Eliminate $\to$: $\;\lnot \forall x\, P(x) \lor \exists x\, Q(x)$
2. Push $\lnot$: $\;\exists x\, \lnot P(x) \lor \exists x\, Q(x)$
3. Rename: $\;\exists x\, \lnot P(x) \lor \exists y\, Q(y)$
4. Move quantifiers: $\;\exists x\, \exists y\,(\lnot P(x) \lor Q(y))$

**Another worked example.** Convert $\lnot(\forall x\,(P(x) \to \exists y\, Q(x,y)))$:

1. Eliminate $\to$: $\;\lnot(\forall x\,(\lnot P(x) \lor \exists y\, Q(x,y)))$
2. Push $\lnot$: $\;\exists x\, \lnot(\lnot P(x) \lor \exists y\, Q(x,y))$ then $\;\exists x\,(P(x) \land \lnot \exists y\, Q(x,y))$ then $\;\exists x\,(P(x) \land \forall y\, \lnot Q(x,y))$
3. No renaming needed (distinct bound variables).
4. Quantifiers out: $\;\exists x\, \forall y\,(P(x) \land \lnot Q(x,y))$

---

## 2. EXAM-STYLE QUESTIONS (WITH MODEL ANSWERS)

### Q1 — Translating English to FOL

**Question.** Using a domain of people and predicates $Student(x)$, $Takes(x, y)$ (person $x$ takes course $y$), and constant $logic$, translate into FOL:

(a) "Every student takes logic."
(b) "Some student does not take logic."
(c) "No one who takes logic is not a student."

**Model answer.**

(a) $\forall x\,(Student(x) \to Takes(x, logic))$

(b) $\exists x\,(Student(x) \land \lnot Takes(x, logic))$

(c) $\lnot \exists x\,(Takes(x, logic) \land \lnot Student(x))$, equivalently $\forall x\,(Takes(x, logic) \to Student(x))$

Key patterns: "every $A$ is $B$" → $\forall x\,(A(x) \to B(x))$; "some $A$ is $B$" → $\exists x\,(A(x) \land B(x))$; "no $A$ is $B$" → $\forall x\,(A(x) \to \lnot B(x))$ or $\lnot \exists x\,(A(x) \land B(x))$.

---

### Q2 — Evaluating satisfaction

**Question.** Let $M = (D, <^M)$ where $D = \{1, 2, 3\}$ and $<^M$ is the usual strict ordering on integers. Determine whether:

(a) $M \models \forall x\, \exists y\,(x < y)$
(b) $M \models \exists x\, \forall y\,(x < y \lor x = y)$

**Model answer.**

(a) Check each $d \in D$:

- $x = 1$: $y = 2$ works ($1 < 2$) ✓
- $x = 2$: $y = 3$ works ($2 < 3$) ✓
- $x = 3$: no $y \in \{1,2,3\}$ satisfies $3 < y$ ✗

So $M \not\models \forall x\, \exists y\,(x < y)$.

(b) Try $x = 1$: for all $y \in \{1,2,3\}$, is $1 < y$ or $1 = y$? $y=1$: $1=1$ ✓; $y=2$: $1<2$ ✓; $y=3$: $1<3$ ✓. Yes.

So $M \models \exists x\, \forall y\,(x < y \lor x = y)$. (The witness is the minimum element.)

---

### Q3 — Prenex normal form conversion

**Question.** Convert $\exists x\, P(x) \to \forall x\, Q(x)$ to prenex normal form.

**Model answer.**

1. **Eliminate $\to$:** $\;\lnot \exists x\, P(x) \lor \forall x\, Q(x)$
2. **Push $\lnot$ in:** $\;\forall x\, \lnot P(x) \lor \forall x\, Q(x)$
3. **Rename variables:** $\;\forall x\, \lnot P(x) \lor \forall y\, Q(y)$
4. **Move quantifiers out:** $\;\forall x\, \forall y\,(\lnot P(x) \lor Q(y))$

---

### Q4 — Non-equivalence of quantifier orders

**Question.** Give a structure $M$ and formula $A(x,y)$ such that $M \models \forall x\, \exists y\, A(x,y)$ but $M \not\models \exists y\, \forall x\, A(x,y)$.

**Model answer.** Let $D = \{1, 2\}$ and $A(x,y)$ be $x = y$.

- $\forall x\, \exists y\,(x = y)$: for $x=1$ pick $y=1$; for $x=2$ pick $y=2$. True ✓
- $\exists y\, \forall x\,(x = y)$: $y=1$ fails for $x=2$; $y=2$ fails for $x=1$. False ✗

The $y$ in $\forall x\, \exists y$ can depend on $x$; in $\exists y\, \forall x$ one fixed $y$ must serve all $x$.

---

### Q5 — Substitution and variable capture

**Question.** Let $A = \forall y\,(x < y \to P(y))$. Compute $A[y+1/x]$ naively and explain why this is problematic. Give the correct procedure.

**Model answer.**

**Naive substitution:** Replace free $x$ with $y + 1$:

$$\forall y\,((y+1) < y \to P(y))$$

The free $y$ in $t = y + 1$ is **captured** by $\forall y$, changing the meaning. The original says "for all $y$, if $x < y$ then $P(y)$"; the result says "for all $y$, if $y+1 < y$ then $P(y)$" — always vacuously true since $y + 1 < y$ is false.

**Correct procedure:** First **rename** the bound variable: $A' = \forall z\,(x < z \to P(z))$. Now substitute:

$$A'[y+1/x] = \forall z\,((y+1) < z \to P(z))$$

No capture. This correctly says "for all $z$ greater than $y+1$, $P(z)$ holds."

---

## 3. MUST-KNOW KEY POINTS

- **Signature** $\Sigma = (F, P)$: function symbols with arities, predicate symbols with arities; constants are arity-0 functions, propositions are arity-0 predicates.
- **Terms** name objects: variables and $f(t_1, \ldots, t_k)$. **Formulas** assert facts: $R(t_1, \ldots, t_k)$, connectives, quantifiers.
- **Free vs bound:** $\forall x$ and $\exists x$ **bind** $x$ within their scope. A **sentence** has no free variables.
- **Translation patterns:** "Every $A$ is $B$" → $\forall x\,(A(x) \to B(x))$; "Some $A$ is $B$" → $\exists x\,(A(x) \land B(x))$.
- **Structure** $M = (D, F^M, P^M)$: domain, function interpretations, relation interpretations.
- **Satisfaction** $M \models_\rho A$: defined recursively; $\forall$ checks **all** $d \in D$, $\exists$ checks **some** $d \in D$, via valuation update $\rho[x \mapsto d]$.
- **Quantifier dualities:** $\lnot \forall x\, A \equiv \exists x\, \lnot A$ and $\lnot \exists x\, A \equiv \forall x\, \lnot A$.
- **Key non-equivalence:** $\forall x\, \exists y\, A \not\equiv \exists y\, \forall x\, A$ — order of mixed quantifiers matters.
- **Substitution:** replace free occurrences only; **rename bound variables** to avoid capture before substituting.
- **Prenex normal form:** eliminate $\to$/$\leftrightarrow$, push $\lnot$ in, rename variables, pull quantifiers to the front.

---

## 4. HIGH-PRIORITY TOPICS

### 🔴 Must Know

- **Syntax:** signature, terms, formulas, free/bound variables, sentences.
- **Satisfaction relation** $M \models_\rho A$: full recursive definition, especially the $\forall$/$\exists$ clauses with $\rho[x \mapsto d]$.
- **English-to-FOL translation** with the $\to$-vs-$\land$ pattern for $\forall$ vs $\exists$.
- **Quantifier dualities** $\lnot \forall \equiv \exists \lnot$ and $\lnot \exists \equiv \forall \lnot$.
- **Prenex normal form** 4-step procedure.
- **Substitution** $A[t/x]$ and the variable capture problem.

### 🟡 Important

- **Structure examples:** constructing specific $M$ and evaluating truth of sentences in $M$.
- **Quantifier distribution:** $\forall$ distributes over $\land$; $\exists$ distributes over $\lor$; but **not** the other combinations.
- **Non-equivalence** $\forall x \exists y \not\equiv \exists y \forall x$ — must be able to construct counterexamples.
- **Validity vs satisfiability** (general and in a structure).

### 🟢 Useful but Lower Priority

- **Peano arithmetic** signature as a running example.
- **Equivalent reformulations** of English sentences (e.g. "no A is B" two ways).
- **Deeper semantic notions:** logical consequence $\Gamma \models A$ in FOL (may appear in later lectures).

---

## 5. TOPIC INTERCONNECTIONS & BIGGER PICTURE

- **Propositional logic $\to$ FOL:** FOL strictly extends propositional logic; every propositional tautology is a valid FOL schema (replace atoms with formulas). PL is the special case with no quantifiers and no internal term structure.
- **Natural deduction / sequent calculus:** FOL natural deduction adds $\forall$-intro, $\forall$-elim, $\exists$-intro, $\exists$-elim rules to the propositional rules — syntactic counterpart of the semantic $\forall$/$\exists$ clauses.
- **Proof by induction:** FOL formulas are **inductively defined**, so metatheorems about FOL (e.g. "every formula has a prenex form") are proved by **structural induction** on formulas.
- **Decidability:** Propositional satisfiability is decidable (truth tables, NP-complete); FOL validity is **undecidable** in general (Church–Turing theorem) — a dramatic jump in expressiveness.
- **Applications:** FOL underpins **databases** (SQL WHERE clauses are essentially FOL), **program verification** (Hoare logic preconditions/postconditions), and **mathematical foundations** (ZFC set theory is a first-order theory).

---

## 6. EXAM STRATEGY TIPS

- **Translation questions** are the most common FOL exam task. Always state your domain and signature explicitly, then apply the $\forall$-uses-$\to$ / $\exists$-uses-$\land$ rule mechanically.
- **Evaluation questions:** write out the domain elements and check $\forall$ exhaustively (every $d$) and $\exists$ by exhibiting a witness. Show every step — partial credit depends on visible working.
- **Prenex conversion:** follow the 4 steps **in order** and **rename before moving quantifiers**. Skipping the rename step is the most common error.
- **Capture:** if a substitution question appears, always check whether the substitution term's variables collide with bound variables. If so, rename first and state why.
- **Non-equivalences:** for $\forall x \exists y \not\equiv \exists y \forall x$, have a concrete counterexample memorised (e.g. $x = y$ over $\{1, 2\}$).
- **De Morgan for quantifiers** is high-yield: $\lnot \forall \leftrightarrow \exists \lnot$ and $\lnot \exists \leftrightarrow \forall \lnot$ appear in prenex conversion, translation, and equivalence proofs.
- For **"is this formula valid?"** questions, try to find a falsifying structure first (small domain, 2–3 elements). If you cannot, argue validity.

---

*These notes synthesise Lectures 5–8b on first-order logic for COMP0003 Formal Logic.*
