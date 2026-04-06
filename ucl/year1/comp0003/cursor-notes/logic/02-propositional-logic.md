# Propositional Logic — COMP0003 Formal Logic

*Lecture-style notes. **Propositional logic** is the simplest formal logic: it studies how the truth of **compound** statements depends on the truth of their **atomic** parts via connectives like $\lnot, \land, \lor, \to, \leftrightarrow$. Mastery of **syntax**, **semantics**, **truth tables**, **equivalences**, and **normal forms** (DNF/CNF) is essential for everything that follows in this module.*

---

## 1. COMPLETE TOPIC SUMMARIES

### What is propositional logic?

Propositional logic deals with **propositions** — statements that are either **true** or **false** — and the **logical connectives** that combine them. It does **not** look inside propositions (no variables, quantifiers, or predicates — that is **first-order logic**). Its strength is that validity and satisfiability are **decidable** (checkable by truth tables or algorithms), and it provides the algebraic backbone for Boolean circuits, SAT solvers, and more.

---

### Syntax

#### Alphabet

| Symbol type | Examples |
|-------------|----------|
| **Proposition letters** (atoms) | $P, Q, R, S, \ldots$ (sometimes $p, q, r, \ldots$) |
| **Connectives** | $\lnot$ (not), $\land$ (and), $\lor$ (or), $\to$ (implies), $\leftrightarrow$ (iff) |
| **Parentheses** | $($, $)$ |

#### Grammar (recursive definition of well-formed formulas)

Let $\mathcal{L} = \{P, Q, R, \ldots\}$ be a set of proposition letters. The set of **formulas** over $\mathcal{L}$ is the smallest set such that:

1. Every proposition letter $P \in \mathcal{L}$ is a formula.
2. If $\varphi$ is a formula, then $\lnot \varphi$ is a formula.
3. If $\varphi$ and $\psi$ are formulas, then $(\varphi \land \psi)$, $(\varphi \lor \psi)$, $(\varphi \to \psi)$, and $(\varphi \leftrightarrow \psi)$ are formulas.

**Syntax trees** mirror the recursive structure: leaves are proposition letters; internal nodes are connectives. The **main connective** (root of the tree) determines the formula's outermost logical structure.

#### Precedence (binding strength, tightest first)

$$\lnot \quad > \quad \land \quad > \quad \lor \quad > \quad \to \quad > \quad \leftrightarrow$$

So $\lnot P \land Q \to R$ parses as $((\lnot P) \land Q) \to R$. Implication $\to$ is **right-associative**: $P \to Q \to R$ means $P \to (Q \to R)$.

---

### Translating English to propositional logic

**Strategy:** Identify atomic propositions, assign letters, then express the logical structure using connectives.

| English | Translation |
|---------|-------------|
| "It is raining **and** cold" | $R \land C$ |
| "If it rains, the ground is wet" | $R \to W$ |
| "It is **not** the case that $P$" | $\lnot P$ |
| "Either $P$ or $Q$ (or both)" | $P \lor Q$ |
| "$P$ if and only if $Q$" | $P \leftrightarrow Q$ |
| "If it rains then I take an umbrella, **unless** it is warm" | $(R \land \lnot W) \to U$ (interpretation-dependent) |

**Pitfall:** Natural language "or" is often **exclusive** ("one or the other, not both"), but logical $\lor$ is **inclusive**. Exclusive or can be expressed as $(P \lor Q) \land \lnot(P \land Q)$, or equivalently $\lnot(P \leftrightarrow Q)$.

---

### Semantics — valuations

A **valuation** (or **truth assignment**) is a function

$$v : \mathcal{L} \to \{0, 1\}$$

mapping each proposition letter to a truth value ($0$ = false, $1$ = true). A valuation **extends uniquely** to all formulas via the truth tables of the connectives.

#### Truth tables for all connectives

| $A$ | $B$ | $\lnot A$ | $A \land B$ | $A \lor B$ | $A \to B$ | $A \leftrightarrow B$ |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | 1 | 0 | 0 | 1 | 1 |
| 0 | 1 | 1 | 0 | 1 | 1 | 0 |
| 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| 1 | 1 | 0 | 1 | 1 | 1 | 1 |

---

### Material implication

The connective $\to$ is defined by:

$$A \to B \equiv \lnot A \lor B$$

The only case where $A \to B$ is **false** is when $A$ is true and $B$ is false. In particular, a **false antecedent** makes the implication **vacuously true**.

#### Paradoxes of material implication

These are valid formulas that feel counterintuitive:

- $\lnot A \to (A \to B)$ — "if $A$ is false, then $A$ implies anything."
- $B \to (A \to B)$ — "if $B$ is true, then anything implies $B$."
- $(A \to B) \lor (B \to A)$ — "of any two propositions, at least one implies the other."

These are semantically valid in classical logic (check by truth table) but clash with everyday intuitions about implication as a **causal** or **relevant** connection. This mismatch motivates **relevance logic** and **conditional logic** but is not pursued in COMP0003.

---

### Satisfiability and validity

| Concept | Definition |
|---------|-----------|
| **Satisfiable** | A formula $\varphi$ is satisfiable if **there exists** a valuation $v$ such that $v(\varphi) = 1$ |
| **Valid** (tautology) | A formula $\varphi$ is valid if **for every** valuation $v$, $v(\varphi) = 1$ |
| **Unsatisfiable** (contradiction) | A formula $\varphi$ is unsatisfiable if **no** valuation makes it true |
| **Contingent** | A formula is satisfiable but not valid (true under some valuations, false under others) |

**Key relationship:**

$$\varphi \text{ is valid} \iff \lnot\varphi \text{ is unsatisfiable}$$

To show a formula is valid, you can show its negation is unsatisfiable (and vice versa). This duality is exploited in **resolution** and **SAT-based** validity checking.

---

### The semantic entailment relation

We write

$$\varphi_1, \varphi_2, \ldots, \varphi_n \models \psi$$

to mean: **every** valuation that makes **all** of $\varphi_1, \ldots, \varphi_n$ true also makes $\psi$ true. When the premise set is empty, $\models \psi$ means $\psi$ is valid.

**Equivalently:** the set $\{\varphi_1, \ldots, \varphi_n, \lnot\psi\}$ is **unsatisfiable**.

---

### Minimal sets of connectives

Not all five connectives are independent. Any one of these sets is **functionally complete** — it can express every truth function:

- $\{\lnot, \land\}$ — since $A \lor B \equiv \lnot(\lnot A \land \lnot B)$ and $A \to B \equiv \lnot(A \land \lnot B)$.
- $\{\lnot, \lor\}$ — since $A \land B \equiv \lnot(\lnot A \lor \lnot B)$ and $A \to B \equiv \lnot A \lor B$.
- $\{\lnot, \to\}$ — since $A \lor B \equiv \lnot A \to B$ and $A \land B \equiv \lnot(A \to \lnot B)$.

Even a **single** connective suffices: the **Sheffer stroke** (NAND) $A \mid B \equiv \lnot(A \land B)$ or **Peirce's arrow** (NOR) $A \downarrow B \equiv \lnot(A \lor B)$.

---

### Key equivalences

These equivalences hold for all valuations and are fundamental tools for rewriting formulas:

| Name | Equivalence |
|------|-------------|
| **Double negation** | $\lnot\lnot A \equiv A$ |
| **Idempotency** | $A \land A \equiv A$; $A \lor A \equiv A$ |
| **Commutativity** | $A \land B \equiv B \land A$; $A \lor B \equiv B \lor A$ |
| **Associativity** | $(A \land B) \land C \equiv A \land (B \land C)$; likewise for $\lor$ |
| **De Morgan's laws** | $\lnot(A \land B) \equiv \lnot A \lor \lnot B$; $\lnot(A \lor B) \equiv \lnot A \land \lnot B$ |
| **Distribution** | $A \land (B \lor C) \equiv (A \land B) \lor (A \land C)$; $A \lor (B \land C) \equiv (A \lor B) \land (A \lor C)$ |
| **Contrapositive** | $A \to B \equiv \lnot B \to \lnot A$ |
| **Material implication** | $A \to B \equiv \lnot A \lor B$ |
| **Biconditional** | $A \leftrightarrow B \equiv (A \to B) \land (B \to A)$ |
| **Absorption** | $A \land (A \lor B) \equiv A$; $A \lor (A \land B) \equiv A$ |

---

### Disjunctive Normal Form (DNF)

**Definitions:**

- A **literal** is an atom or its negation: $P$ or $\lnot P$.
- A **conjunctive clause** (minterm) is a conjunction of literals: $P \land \lnot Q \land R$.
- A formula is in **DNF** if it is a disjunction of conjunctive clauses:

$$(\ell_{1,1} \land \cdots \land \ell_{1,k_1}) \lor (\ell_{2,1} \land \cdots \land \ell_{2,k_2}) \lor \cdots$$

#### Extracting DNF from a truth table

1. For each row where the formula evaluates to **1**, form a conjunctive clause: use $P$ if $v(P)=1$, use $\lnot P$ if $v(P)=0$.
2. Take the **disjunction** of all such clauses.

**Example:** For $A \to B$:

| $A$ | $B$ | $A \to B$ |
|:---:|:---:|:---:|
| 0 | 0 | 1 |
| 0 | 1 | 1 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

Rows 1, 2, 4 give value 1. DNF: $(\lnot A \land \lnot B) \lor (\lnot A \land B) \lor (A \land B)$.

#### Constructing DNF using equivalences

1. Eliminate $\to$ and $\leftrightarrow$ using their definitions.
2. Push $\lnot$ inward using **De Morgan's laws** and **double negation**.
3. Distribute $\land$ over $\lor$ until the formula is a disjunction of conjunctions.

---

### Conjunctive Normal Form (CNF)

**Definitions:**

- A **disjunctive clause** is a disjunction of literals: $P \lor \lnot Q \lor R$.
- A formula is in **CNF** if it is a conjunction of disjunctive clauses:

$$(\ell_{1,1} \lor \cdots \lor \ell_{1,k_1}) \land (\ell_{2,1} \lor \cdots \lor \ell_{2,k_2}) \land \cdots$$

**Relation to DNF:** A formula $\varphi$ is in CNF iff $\lnot\varphi$ can be put in DNF (by De Morgan). Alternatively: negate the formula, find DNF of the negation, negate back and apply De Morgan.

**Why CNF matters:** A CNF formula is **valid** iff **every** clause is valid (contains some literal and its complement). This makes validity checking easy for CNF. CNF is also the input format for **SAT solvers** and **resolution** proof systems.

#### Extracting CNF from a truth table

1. For each row where the formula evaluates to **0**, form a disjunctive clause: use $\lnot P$ if $v(P) = 1$, use $P$ if $v(P) = 0$ (i.e. **negate** the assignment).
2. Take the **conjunction** of all such clauses.

#### Constructing CNF using equivalences

1. Eliminate $\to$ and $\leftrightarrow$.
2. Push $\lnot$ inward (De Morgan + double negation).
3. Distribute $\lor$ over $\land$ until the formula is a conjunction of disjunctions.

---

## 2. EXAM-STYLE QUESTIONS (WITH MODEL ANSWERS)

### Q1 — Truth table and classification

**Question.** Construct the truth table for $(P \to Q) \to P$. Is this formula valid, satisfiable but not valid, or unsatisfiable?

**Model answer.**

| $P$ | $Q$ | $P \to Q$ | $(P \to Q) \to P$ |
|:---:|:---:|:---:|:---:|
| 0 | 0 | 1 | 0 |
| 0 | 1 | 1 | 0 |
| 1 | 0 | 0 | 1 |
| 1 | 1 | 1 | 1 |

The formula is true in rows 3–4 and false in rows 1–2. It is **satisfiable but not valid** (contingent). This is **Peirce's law** — it is valid in classical logic only when taken as an axiom schema or proved via excluded middle, but the specific propositional instance here is not a tautology as the truth table shows.

*Correction — re-evaluation:* Actually, $(P \to Q) \to P$ is indeed **not** a tautology. Peirce's law $((P \to Q) \to P) \to P$ (with the extra $\to P$) **is** a tautology. The formula as given is **contingent**.

---

### Q2 — Semantic entailment

**Question.** Does $P \to Q,\; Q \to R \models P \to R$? Prove your answer.

**Model answer.** Yes. Let $v$ be any valuation with $v(P \to Q) = 1$ and $v(Q \to R) = 1$. We need $v(P \to R) = 1$. If $v(P) = 0$, then $v(P \to R) = 1$ immediately. If $v(P) = 1$, then from $v(P \to Q) = 1$ we get $v(Q) = 1$; from $v(Q \to R) = 1$ we get $v(R) = 1$; so $v(P \to R) = 1$. In all cases the conclusion holds, so $P \to Q,\; Q \to R \models P \to R$.

---

### Q3 — De Morgan and equivalence

**Question.** Using equivalences, show that $\lnot(P \to Q)$ is equivalent to $P \land \lnot Q$. State each equivalence used.

**Model answer.**

$$\lnot(P \to Q) \equiv \lnot(\lnot P \lor Q) \quad \text{(material implication)}$$
$$\equiv \lnot\lnot P \land \lnot Q \quad \text{(De Morgan)}$$
$$\equiv P \land \lnot Q \quad \text{(double negation)}$$

---

### Q4 — DNF from truth table

**Question.** Find the DNF of $\lnot(P \leftrightarrow Q)$ by constructing its truth table.

**Model answer.**

| $P$ | $Q$ | $P \leftrightarrow Q$ | $\lnot(P \leftrightarrow Q)$ |
|:---:|:---:|:---:|:---:|
| 0 | 0 | 1 | 0 |
| 0 | 1 | 0 | 1 |
| 1 | 0 | 0 | 1 |
| 1 | 1 | 1 | 0 |

Rows with output 1: row 2 ($P=0, Q=1$) and row 3 ($P=1, Q=0$). DNF:

$$(\lnot P \land Q) \lor (P \land \lnot Q)$$

This is the **exclusive or** of $P$ and $Q$.

---

### Q5 — Minimal connective sets

**Question.** Prove that $\{\lnot, \to\}$ is functionally complete by expressing $\land$ and $\lor$ using only $\lnot$ and $\to$.

**Model answer.** **Disjunction:** $A \lor B \equiv \lnot A \to B$. Check: $\lnot A \to B \equiv \lnot\lnot A \lor B \equiv A \lor B$. **Conjunction:** $A \land B \equiv \lnot(A \to \lnot B)$. Check: $A \to \lnot B \equiv \lnot A \lor \lnot B \equiv \lnot(A \land B)$ by De Morgan, so $\lnot(A \to \lnot B) \equiv A \land B$. Since $\lor$ and $\land$ can be expressed, and together $\{\lnot, \land, \lor\}$ is known to be functionally complete, so is $\{\lnot, \to\}$.

---

## 3. MUST-KNOW KEY POINTS

- **Syntax:** formulas built from atoms $P, Q, R, \ldots$ and connectives $\lnot, \land, \lor, \to, \leftrightarrow$ via a recursive grammar.
- **Precedence:** $\lnot > \land > \lor > \to > \leftrightarrow$; $\to$ is right-associative.
- **Semantics:** a valuation $v : \mathcal{L} \to \{0,1\}$ determines the truth value of every formula.
- **Material implication:** $A \to B \equiv \lnot A \lor B$; false **only** when $A$ is true and $B$ is false.
- **Satisfiable** = some $v$ makes it true; **valid** = every $v$ makes it true; **$\varphi$ valid $\iff$ $\lnot\varphi$ unsatisfiable**.
- **$\models$**: $\Gamma \models \psi$ means every valuation satisfying all of $\Gamma$ also satisfies $\psi$.
- **Minimal connective sets:** $\{\lnot, \land\}$, $\{\lnot, \lor\}$, or $\{\lnot, \to\}$ are each functionally complete.
- **Key equivalences:** De Morgan, double negation, distribution, contrapositive, material implication, biconditional expansion.
- **DNF:** disjunction of conjunctive clauses; extract from truth-table rows with output 1, or derive via equivalences.
- **CNF:** conjunction of disjunctive clauses; extract from truth-table rows with output 0 (negate the assignment); a CNF is valid iff every clause is a tautology.

---

## 4. HIGH-PRIORITY TOPICS

### 🔴 Must Know

- **Truth tables** for all five connectives — be able to write them from memory.
- **Material implication** $A \to B \equiv \lnot A \lor B$ and the "only false when $A$ true, $B$ false" rule.
- **Satisfiability vs validity** definitions and the **duality**: valid $\iff$ negation unsatisfiable.
- **Semantic entailment** $\models$ — definition and how to verify (check all valuations).
- **De Morgan's laws** and **double negation** — used in almost every equivalence derivation.
- **DNF from truth table** — the mechanical procedure (rows with 1, form minterms, disjoin).
- **CNF from truth table** — the dual procedure (rows with 0, negate assignments, conjoin).
- **Constructing DNF/CNF via equivalences** — eliminate $\to, \leftrightarrow$, push $\lnot$ inward, distribute.

### 🟡 Important

- **Precedence and parsing** — correctly parenthesising formulas from their textual form.
- **Syntax trees** — drawing the parse tree, identifying the main connective.
- **Translating English to logic** — knowing when to use $\to$, $\land$, $\lor$, $\leftrightarrow$.
- **Paradoxes of material implication** — recognising vacuous truth and why it is valid classically.
- **Functional completeness** — showing a connective set suffices by expressing the others.

### 🟢 Useful but Lower Priority

- **Sheffer stroke** (NAND) and **Peirce's arrow** (NOR) as single-connective complete sets.
- **Absorption** laws.
- Historical context of material implication debates.
- Efficiency considerations for DNF vs CNF (exponential blowup in the worst case).

---

## 5. TOPIC INTERCONNECTIONS & BIGGER PICTURE

- **Boolean algebra** (Lecture 4) gives the **algebraic** view of propositional logic: $\lor \leftrightarrow +$, $\land \leftrightarrow \cdot$, $\lnot \leftrightarrow \overline{\ }$. DNF corresponds to **sums of products**; CNF to **products of sums**.
- **Natural deduction** (Lectures 5–6) provides **syntactic proof rules** for propositional logic — the inference-rule layer that complements the semantic (truth-table) layer studied here.
- **First-order logic** (Lectures 7+) extends propositional logic with **quantifiers** and **predicates** — every propositional equivalence carries over, but new phenomena (quantifier scope, free/bound variables) arise.
- **SAT solvers** use CNF as input; the ability to convert arbitrary formulas to CNF is a prerequisite for understanding resolution and DPLL algorithms.
- **Digital circuits** implement propositional formulas in hardware — DNF corresponds to **two-level AND-OR** circuits; CNF to **two-level OR-AND** circuits.

---

## 6. EXAM STRATEGY TIPS

- **Truth tables are mechanical** — for $n$ atoms, you have $2^n$ rows. Don't skip rows; list all combinations systematically (binary counting order).
- **Label columns** for subformulas (e.g. compute $P \to Q$ before $(P \to Q) \to R$). This avoids errors and earns method marks.
- For **equivalence proofs**, write one equivalence per line and cite the rule (De Morgan, double negation, etc.) — examiners look for justification at each step.
- When constructing **DNF from a truth table**, double-check: the DNF should have exactly as many clauses as there are 1-rows.
- For **CNF**, remember the "flip" compared to DNF: use the 0-rows, and negate the literal sense.
- **Validity checking via CNF:** convert to CNF, then check each clause for a complementary pair $P, \lnot P$. If every clause has one, the formula is valid.
- If asked whether a set of connectives is functionally complete, express $\lnot$ and one binary connective ($\land$ or $\lor$) using only the given set — that suffices.
- **Entailment questions:** either do the truth table (small cases) or argue semantically case-by-case on the possible values of the atoms.

---

*These notes cover Logic Lectures 2–3 of COMP0003 Formal Logic — propositional syntax, semantics, truth tables, equivalences, and normal forms.*
