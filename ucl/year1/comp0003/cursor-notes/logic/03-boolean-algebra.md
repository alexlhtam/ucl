# Boolean Algebra — COMP0003 Formal Logic

*Lecture-style notes. **Boolean algebra** provides the **algebraic** foundation for propositional logic: the same truth-functional reasoning expressed through **axioms**, **equational proofs**, and **circuit design** rather than truth tables. Understanding the correspondence \(+ \leftrightarrow \lor\), \(\cdot \leftrightarrow \land\), \(\overline{\ } \leftrightarrow \lnot\) and the **duality** theorem ties together logic, algebra, and hardware.*

---

## 1. COMPLETE TOPIC SUMMARIES

### Definition of a Boolean algebra

A **Boolean algebra** is a tuple \((B,\; 0,\; 1,\; +,\; \overline{\ })\) where

- \(B\) is a **non-empty set**,
- \(0, 1 \in B\) are distinguished **constants** (zero and one),
- \(+ : B \times B \to B\) is a **binary operation** (read "plus" or "join"),
- \(\overline{\ } : B \to B\) is a **unary operation** (read "complement" or "bar"),

satisfying the following **axioms** for all \(a, b, c \in B\):

| Axiom | Statement |
|-------|-----------|
| **Associativity** of \(+\) | \((a + b) + c = a + (b + c)\) |
| **Commutativity** of \(+\) | \(a + b = b + a\) |
| **Idempotency** of \(+\) | \(a + a = a\) |
| **Unit law** for \(+\) | \(a + 0 = a\) |
| **Double negation** | \(\overline{\overline{a}} = a\) |
| **Complement** | \(a + \overline{a} = 1\) |
| **0/1 law** for complement | \(\overline{0} = 1\) (equivalently \(\overline{1} = 0\)) |
| **Distribution** of \(+\) over \(\cdot\) | \(a + (b \cdot c) = (a + b) \cdot (a + c)\) |

Here the **product** (meet) is a **derived** operation defined by:

$$a \cdot b \;=\; \overline{\,\overline{a} + \overline{b}\,}$$

This mirrors the De Morgan definition: \(a \land b \equiv \lnot(\lnot a \lor \lnot b)\).

---

### Notation and correspondence with logic

| Boolean algebra | Propositional logic | Circuit |
|:-:|:-:|:-:|
| \(\overline{a}\) | \(\lnot A\) | NOT gate |
| \(a + b\) | \(A \lor B\) | OR gate |
| \(a \cdot b\) | \(A \land B\) | AND gate |
| \(0\) | \(\bot\) (false) | Low signal |
| \(1\) | \(\top\) (true) | High signal |

This correspondence means every propositional equivalence has a Boolean-algebraic counterpart and vice versa. Proving an identity in Boolean algebra is the same as proving a propositional equivalence.

---

### Example 1 — the two-element Boolean algebra

$$(\{0, 1\},\; 0,\; 1,\; +,\; \overline{\ })$$

where \(+\) is defined by \(\max\) (equivalently: \(0+0=0\), \(0+1=1+0=1+1=1\)) and \(\overline{0} = 1\), \(\overline{1} = 0\). Product becomes \(\min\): \(a \cdot b = \overline{\,\overline{a}+\overline{b}\,}\).

This is the **simplest** Boolean algebra — it is exactly the truth-value structure of classical propositional logic. Every axiom is verified by checking the (finitely many) cases.

---

### Example 2 — the powerset Boolean algebra

Let \(X\) be any set. Define

$$(\mathcal{P}(X),\; \emptyset,\; X,\; \cup,\; X \setminus (\cdot))$$

where

- \(B = \mathcal{P}(X)\) (the power set — all subsets of \(X\)),
- \(0 = \emptyset\) and \(1 = X\),
- \(+ = \cup\) (set union),
- \(\overline{A} = X \setminus A\) (set complement relative to \(X\)).

Then the derived product is \(A \cdot B = \overline{\,\overline{A} \cup \overline{B}\,} = A \cap B\) (set intersection). All axioms hold by standard set identities. This example shows Boolean algebras arise naturally outside pure logic.

---

### Stone's theorem

**Stone's Representation Theorem** (1936) states: every Boolean algebra is **isomorphic** to a **field of sets** (a subalgebra of some powerset Boolean algebra). In other words, the powerset example is not just one example — it is, up to isomorphism, the **universal** model. For finite Boolean algebras, this means every finite Boolean algebra is isomorphic to \(\mathcal{P}(X)\) for some finite set \(X\), and so has \(2^n\) elements for some \(n\).

---

### Boolean terms as circuits

A **Boolean term** (expression built from variables, constants \(0, 1\), and operations \(+, \cdot, \overline{\ }\)) directly translates to a **logic circuit**:

| Operation | Gate | Symbol |
|-----------|------|--------|
| \(\overline{a}\) | **NOT** | Triangle with bubble |
| \(a + b\) | **OR** | Curved-input gate |
| \(a \cdot b\) | **AND** | Flat-input gate |

Variables are **inputs** (wires); the final expression is the **output**. Simplifying a Boolean expression algebraically corresponds to **minimising** the number of gates in the circuit.

---

### De Morgan's laws — with proof

**Theorem.** For all elements \(a, b\) of a Boolean algebra:

$$\overline{a + b} = \overline{a} \cdot \overline{b} \qquad \text{and} \qquad \overline{a \cdot b} = \overline{a} + \overline{b}$$

**Proof of \(\overline{a \cdot b} = \overline{a} + \overline{b}\):**

By definition, \(a \cdot b = \overline{\,\overline{a} + \overline{b}\,}\). Therefore:

$$\overline{a \cdot b} = \overline{\,\overline{\,\overline{a} + \overline{b}\,}\,} = \overline{a} + \overline{b}$$

using **double negation** (\(\overline{\overline{x}} = x\)) with \(x = \overline{a} + \overline{b}\).

**Proof of \(\overline{a + b} = \overline{a} \cdot \overline{b}\):**

By the definition of \(\cdot\), we need \(\overline{a} \cdot \overline{b} = \overline{\,\overline{\,\overline{a}\,} + \overline{\,\overline{b}\,}\,} = \overline{\,a + b\,}\), where the last step uses double negation on both \(\overline{a}\) and \(\overline{b}\).

---

### Consequences of the axioms

Several useful identities follow from the axioms and De Morgan:

| Identity | Proof sketch |
|----------|-------------|
| \(a \cdot \overline{a} = 0\) | \(a \cdot \overline{a} = \overline{\,\overline{a} + \overline{\,\overline{a}\,}\,} = \overline{\,\overline{a} + a\,} = \overline{1} = 0\) (using complement, double negation, and 0/1 law) |
| \(a \cdot 1 = a\) | \(a \cdot 1 = \overline{\,\overline{a} + \overline{1}\,} = \overline{\,\overline{a} + 0\,} = \overline{\,\overline{a}\,} = a\) |
| \(a \cdot 0 = 0\) | \(a \cdot 0 = \overline{\,\overline{a} + \overline{0}\,} = \overline{\,\overline{a} + 1\,} = \overline{1} = 0\) (since \(x + 1 = 1\) by complement and idempotency: \(x + 1 = x + (x + \overline{x}) = (x+x) + \overline{x} = x + \overline{x} = 1\)) |
| \(a + 1 = 1\) | From complement: \(a + \overline{a} = 1\). Since \(1 = a + \overline{a} \leq a + 1\) and \(a + 1 \leq 1 + 1 = 1\), we get \(a + 1 = 1\). Alternatively: \(a + 1 = a + (a + \overline{a}) = (a + a) + \overline{a} = a + \overline{a} = 1\). |

---

### The duality theorem

**Duality principle.** If an equation \(E\) holds in every Boolean algebra, then the **dual** equation \(E^d\) (obtained by simultaneously swapping \(+ \leftrightarrow \cdot\) and \(0 \leftrightarrow 1\) throughout) also holds in every Boolean algebra.

**Why it works:** The axioms are self-dual as a set — every axiom for \(+\) has a corresponding derived property for \(\cdot\) (and vice versa, once the derived identities like \(a \cdot 1 = a\) are established). So any chain of equational reasoning from the axioms can be "dualised" step by step.

**Example:**

- **Original:** \(a + 0 = a\) (unit law for \(+\)).
- **Dual:** \(a \cdot 1 = a\) (unit law for \(\cdot\)).

- **Original:** \(a + 1 = 1\).
- **Dual:** \(a \cdot 0 = 0\).

---

### Dual distribution law — with proof

The axiom gives distribution of \(+\) over \(\cdot\):

$$a + (b \cdot c) = (a + b) \cdot (a + c)$$

By **duality**, the dual distribution law also holds:

$$a \cdot (b + c) = (a \cdot b) + (a \cdot c)$$

**Direct proof** (without invoking duality):

$$a \cdot (b + c) = \overline{\,\overline{a} + \overline{b + c}\,} \quad \text{(definition of } \cdot \text{)}$$

$$= \overline{\,\overline{a} + (\overline{b} \cdot \overline{c})\,} \quad \text{(De Morgan: } \overline{b+c} = \overline{b} \cdot \overline{c} \text{)}$$

$$= \overline{\,(\overline{a} + \overline{b}) \cdot (\overline{a} + \overline{c})\,} \quad \text{(distribution axiom)}$$

$$= \overline{\,\overline{a} + \overline{b}\,} + \overline{\,\overline{a} + \overline{c}\,} \quad \text{(De Morgan on the outer complement)}$$

$$= (a \cdot b) + (a \cdot c) \quad \text{(definition of } \cdot \text{)}$$

---

### Sums of products (cf. DNF)

A **sum of products** is a Boolean expression of the form

$$(x_1 \cdot x_2 \cdot \overline{x_3}) + (\overline{x_1} \cdot x_3) + \cdots$$

where each **product term** is a conjunction of literals (variables or their complements), and the overall expression is a disjunction (\(+\)) of such terms.

This is exactly the Boolean-algebraic counterpart of **DNF**:

| Logic | Algebra |
|-------|---------|
| Literal | Variable or \(\overline{\text{variable}}\) |
| Conjunctive clause | Product term |
| DNF formula | Sum of products |

#### Reading sums of products from a truth table

Identical to the DNF procedure:

1. For each row with output \(1\), form a product term: include \(x_i\) if the variable is \(1\) in that row, \(\overline{x_i}\) if it is \(0\).
2. Sum (\(+\)) all product terms.

#### Deriving via equivalences

Alternatively, simplify the expression using the axioms (distribution, complement, idempotency, etc.) to reach a sum-of-products form. This may yield a **simpler** expression than the truth-table method (fewer terms, fewer literals).

**Products of sums** (the dual) correspond to **CNF** — conjunction of disjunctive clauses.

---

### Limitations of propositional logic

Propositional logic (and equivalently, Boolean algebra) cannot express:

- **Quantification** over individuals: "for all \(x\), \(P(x)\)" or "there exists \(x\) such that \(Q(x)\)."
- **Relations** between objects: "\(x\) is greater than \(y\)."
- **Functions** and terms: "\(f(x) = y\)."

These limitations motivate the move to **first-order logic (FOL)**, where the language includes variables, quantifiers \(\forall\) and \(\exists\), predicates, and function symbols — while retaining all propositional connectives as a sublanguage.

---

## 2. EXAM-STYLE QUESTIONS (WITH MODEL ANSWERS)

### Q1 — Verify axioms for the two-element Boolean algebra

**Question.** For the Boolean algebra \((\{0,1\}, 0, 1, +, \overline{\ })\) with \(+\) defined as \(\max\) and \(\overline{0}=1\), \(\overline{1}=0\), verify the **complement** axiom and the **distribution** axiom.

**Model answer.** **Complement (\(a + \overline{a} = 1\)):** If \(a = 0\): \(0 + \overline{0} = 0 + 1 = 1\). If \(a = 1\): \(1 + \overline{1} = 1 + 0 = 1\). Both cases give \(1\). **Distribution (\(a + (b \cdot c) = (a+b) \cdot (a+c)\)):** The product is \(\min\). Check all \(2^3 = 8\) combinations of \(a, b, c \in \{0,1\}\):

| \(a\) | \(b\) | \(c\) | \(b \cdot c\) | \(a + (b \cdot c)\) | \(a+b\) | \(a+c\) | \((a+b)\cdot(a+c)\) |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 | 0 | 1 | 0 |
| 0 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |
| 1 | 0 | 1 | 0 | 1 | 1 | 1 | 1 |
| 1 | 1 | 0 | 0 | 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |

Columns 5 and 8 agree in all rows. Both axioms hold.

---

### Q2 — Prove a consequence of the axioms

**Question.** Prove that \(a \cdot \overline{a} = 0\) from the axioms of Boolean algebra.

**Model answer.**

$$a \cdot \overline{a} = \overline{\,\overline{a} + \overline{\,\overline{a}\,}\,} \quad \text{(definition of } \cdot \text{)}$$
$$= \overline{\,\overline{a} + a\,} \quad \text{(double negation: } \overline{\overline{a}} = a \text{)}$$
$$= \overline{1} \quad \text{(complement: } \overline{a} + a = a + \overline{a} = 1 \text{, using commutativity)}$$
$$= 0 \quad \text{(0/1 law: } \overline{1} = 0 \text{)}$$

---

### Q3 — Duality

**Question.** State the **duality principle** for Boolean algebras. Given the identity \(a + (a \cdot b) = a\) (absorption), write its dual and verify the dual for the two-element Boolean algebra.

**Model answer.** **Duality principle:** swap \(+ \leftrightarrow \cdot\) and \(0 \leftrightarrow 1\) throughout any valid identity to obtain another valid identity. **Dual of absorption:** \(a \cdot (a + b) = a\). **Verification in \(\{0,1\}\):** check all four cases:

| \(a\) | \(b\) | \(a + b\) | \(a \cdot (a+b)\) |
|:---:|:---:|:---:|:---:|
| 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 0 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 1 | 1 |

In every row, \(a \cdot (a + b) = a\). The dual identity holds.

---

### Q4 — Sum of products from truth table

**Question.** A Boolean function \(f(a, b, c)\) has output \(1\) exactly when an odd number of its inputs are \(1\). Write \(f\) as a sum of products.

**Model answer.** The rows with an odd number of 1s among \((a, b, c)\) are: \((0,0,1)\), \((0,1,0)\), \((1,0,0)\), \((1,1,1)\). The product terms are:

- \((0,0,1) \to \overline{a} \cdot \overline{b} \cdot c\)
- \((0,1,0) \to \overline{a} \cdot b \cdot \overline{c}\)
- \((1,0,0) \to a \cdot \overline{b} \cdot \overline{c}\)
- \((1,1,1) \to a \cdot b \cdot c\)

Sum of products:

$$f(a,b,c) = (\overline{a} \cdot \overline{b} \cdot c) + (\overline{a} \cdot b \cdot \overline{c}) + (a \cdot \overline{b} \cdot \overline{c}) + (a \cdot b \cdot c)$$

This is the **3-variable XOR** (parity function).

---

### Q5 — Powerset Boolean algebra

**Question.** Let \(X = \{1, 2, 3\}\). In the powerset Boolean algebra \((\mathcal{P}(X), \emptyset, X, \cup, X\setminus)\), compute: (a) \(\{1,2\} + \{2,3\}\), (b) \(\overline{\{1\}}\), (c) \(\{1,2\} \cdot \{2,3\}\), (d) verify that \(\{1,2\} + \overline{\{1,2\}} = X\).

**Model answer.** (a) \(\{1,2\} + \{2,3\} = \{1,2\} \cup \{2,3\} = \{1,2,3\} = X\). (b) \(\overline{\{1\}} = X \setminus \{1\} = \{2,3\}\). (c) \(\{1,2\} \cdot \{2,3\} = \{1,2\} \cap \{2,3\} = \{2\}\). (d) \(\{1,2\} + \overline{\{1,2\}} = \{1,2\} \cup (\{1,2,3\} \setminus \{1,2\}) = \{1,2\} \cup \{3\} = \{1,2,3\} = X\). The complement axiom is satisfied.

---

## 3. MUST-KNOW KEY POINTS

- A **Boolean algebra** is \((B, 0, 1, +, \overline{\ })\) satisfying axioms: associativity, commutativity, idempotency, unit law for \(+\); double negation, complement, 0/1 law; distribution.
- **Product** is derived: \(a \cdot b = \overline{\,\overline{a} + \overline{b}\,}\) (De Morgan definition of \(\land\) from \(\lor\) and \(\lnot\)).
- **Correspondence:** \(+ \leftrightarrow \lor\), \(\cdot \leftrightarrow \land\), \(\overline{\ } \leftrightarrow \lnot\), \(0 \leftrightarrow \bot\), \(1 \leftrightarrow \top\).
- **Two-element algebra** \(\{0,1\}\) is the truth-value structure of propositional logic.
- **Powerset algebra** \((\mathcal{P}(X), \emptyset, X, \cup, X\setminus)\) is the canonical set-theoretic example.
- **Stone's theorem:** every Boolean algebra embeds into a powerset algebra.
- **De Morgan laws** in algebraic form: \(\overline{a + b} = \overline{a} \cdot \overline{b}\) and \(\overline{a \cdot b} = \overline{a} + \overline{b}\).
- **Key derived identities:** \(a \cdot \overline{a} = 0\), \(a \cdot 1 = a\), \(a \cdot 0 = 0\), \(a + 1 = 1\).
- **Duality:** swap \(+/\cdot\) and \(0/1\) in any valid identity to get another valid identity.
- **Sums of products** = DNF; **products of sums** = CNF.
- **Propositional logic is limited** — cannot express quantification, relations, or functions → first-order logic needed.

---

## 4. HIGH-PRIORITY TOPICS

### 🔴 Must Know

- **Boolean algebra definition:** the tuple, the axioms, and the derived product \(a \cdot b = \overline{\,\overline{a} + \overline{b}\,}\).
- **Correspondence** between \(+, \cdot, \overline{\ }\) and \(\lor, \land, \lnot\) — be able to translate freely.
- **Two-element Boolean algebra** — verifying axioms by case analysis.
- **De Morgan laws** in algebraic form, with proof from definition of \(\cdot\) and double negation.
- **Key consequences:** \(a \cdot \overline{a} = 0\), \(a \cdot 1 = a\), \(a \cdot 0 = 0\), \(a + 1 = 1\) — be able to derive each from axioms.
- **Sums of products:** reading them from truth tables (identical to DNF extraction).

### 🟡 Important

- **Duality theorem:** statement, how to form the dual of an identity, and why it works.
- **Dual distribution:** \(a \cdot (b + c) = (a \cdot b) + (a \cdot c)\) — proof via definition and axioms.
- **Powerset Boolean algebra** — definition and verifying the operations.
- **Boolean terms as circuits:** NOT, OR, AND gates and how expressions map to gate diagrams.

### 🟢 Useful but Lower Priority

- **Stone's theorem** — statement and significance (isomorphism to powerset algebras); proof not expected.
- **Absorption laws** (\(a + a \cdot b = a\), \(a \cdot (a+b) = a\)) — derivable but less frequently examined directly.
- **Minimisation** of Boolean expressions (Karnaugh maps, Quine–McCluskey) — beyond this lecture's scope but good awareness.
- **Limitations of propositional logic** — motivational awareness for FOL transition.

---

## 5. TOPIC INTERCONNECTIONS & BIGGER PICTURE

- **Propositional logic** (Lectures 2–3) provides the **semantic** (truth-table) approach; Boolean algebra provides the **equational** (axiomatic) approach. They are two views of the same subject — **soundness** and **completeness** of the equational theory ensures they agree.
- **DNF/CNF** from Lecture 3 are exactly **sums of products** / **products of sums** in algebraic language. The truth-table extraction procedure is the same; algebraic simplification offers an alternative derivation path.
- **Digital hardware** implements Boolean functions as circuits — the algebra of \(+, \cdot, \overline{\ }\) is literally the algebra of **OR, AND, NOT gates**. Circuit optimisation is Boolean expression minimisation.
- **Stone's theorem** connects Boolean algebra to **topology** and **set theory** — it is a deep structural result that explains why the powerset example is "universal."
- **First-order logic** (upcoming lectures) extends the language with quantifiers and predicates, overcoming the limitations of propositional logic/Boolean algebra. Every propositional identity remains valid in FOL; FOL adds new expressive power on top.
- **Natural deduction** (Lectures 5–6) gives **proof rules** that correspond to the algebraic axioms — the **soundness** theorem says: if you can prove it, the algebra validates it; **completeness** says: if the algebra validates it, you can prove it.

---

## 6. EXAM STRATEGY TIPS

- **Algebraic proofs:** Always start from the definition \(a \cdot b = \overline{\,\overline{a} + \overline{b}\,}\) when proving identities involving \(\cdot\). Cite each axiom used (double negation, complement, distribution, etc.) — examiners award marks per step.
- **Duality shortcut:** If you have already proved an identity, state its dual immediately by citing the duality theorem — you do not need to re-prove the dual from scratch.
- **Verifying axioms for specific algebras:** For the two-element algebra, a simple case check (\(0\) and \(1\)) suffices. For the powerset algebra, appeal to standard set identities.
- **Truth table to sum of products:** This is mechanical — list the 1-rows, write the product terms, sum them. State the correspondence to DNF if asked to connect the two topics.
- **Common errors:** Don't confuse the axiom for distribution (which distributes \(+\) over \(\cdot\): \(a + b \cdot c = (a+b)(a+c)\)) with the dual distribution (\(a \cdot (b+c) = ab + ac\)). In ordinary arithmetic, only the latter holds — both hold in Boolean algebra.
- **Connecting to logic:** If a question asks you to prove a propositional equivalence algebraically, translate connectives to \(+, \cdot, \overline{\ }\), prove the algebraic identity, then translate back.
- **Circuit questions:** Draw the expression as a tree (leaves = inputs, nodes = gates), then simplify the expression first to reduce gate count.

---

*These notes cover Logic Lecture 4 of COMP0003 Formal Logic — Boolean algebra as the algebraic foundation of propositional reasoning and digital circuit design.*
