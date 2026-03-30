# Overview & History of Logic — COMP0003 Formal Logic

*Lecture-style notes. Logic underpins every formal discipline in computer science — from hardware verification to AI. This opening lecture traces the subject from **Aristotle's syllogisms** through **Frege**, **Russell**, **Gödel**, and **Turing** to modern **program verification**, motivating **why** we study formal logic and what its fundamental limits are.*

---

## 1. COMPLETE TOPIC SUMMARIES

### What is logic?

Logic is the study of **valid reasoning**. It asks: given some assumptions, what conclusions **necessarily** follow? To answer this rigorously, logic provides three layers:

1. **Syntax** — the formal language of well-formed formulas (what strings are grammatically legal).
2. **Semantics** — the meaning assigned to formulas (when a formula is **true** or **false** under an interpretation).
3. **Inference rules** — mechanical steps that derive new formulas from existing ones purely by form (e.g. from \(A\) and \(A \to B\), conclude \(B\)).

A **logical system** combines all three: a language, a way to interpret it, and proof rules that (ideally) produce exactly the valid conclusions.

---

### Aristotle and syllogisms

**Aristotle** (384–322 BCE) gave the first systematic account of deductive reasoning via **syllogisms** — structured arguments with two premises and a conclusion, each involving quantified categorical statements.

**Canonical example (Barbara):**

$$\text{All men are mortal.} \quad \text{Socrates is a man.} \quad \therefore\ \text{Socrates is mortal.}$$

Aristotle catalogued valid syllogistic forms and identified fallacious ones. His framework dominated logic for roughly two millennia but was limited: it could not express relations between individuals (e.g. "\(x\) is taller than \(y\)") or nested quantification.

---

### Classical principles

Two laws sit at the foundation of **classical** logic:

| Principle | Formula | Meaning |
|-----------|---------|---------|
| **Law of non-contradiction** | \(\lnot(A \land \lnot A)\) | A proposition cannot be **both** true and false simultaneously |
| **Law of excluded middle** | \(A \lor \lnot A\) | Every proposition is **either** true or false — there is no third option |

Together they enforce a **bivalent** view of truth. Rejecting excluded middle leads to **intuitionistic** logic; rejecting non-contradiction leads to **paraconsistent** logic — both are active research areas, but COMP0003 works within the classical setting.

---

### Inconsistency

A set of formulas is **inconsistent** if it can derive a **contradiction** — i.e. both \(A\) and \(\lnot A\) for some \(A\). In classical logic, from a contradiction **anything** follows (the principle of **explosion**, *ex falso quodlibet*):

$$A,\ \lnot A\ \vdash\ B \quad \text{for any } B$$

This is why consistency is a non-negotiable requirement for any logical foundation: an inconsistent system is **trivial** (it proves every statement).

---

### Frege and predicate logic

**Gottlob Frege** (1848–1925) revolutionised logic in his 1879 *Begriffsschrift*:

- Introduced **predicate logic** (first-order logic) with **quantifiers** \(\forall\) and \(\exists\), **variables**, **predicates**, and **functions** — far more expressive than syllogisms.
- Proposed **formal proofs** as sequences of formulas, each justified by an explicit **inference rule** or taken as an **axiom**.
- His system could express statements like \(\forall x\, (P(x) \to Q(x))\) — "for all \(x\), if \(P(x)\) then \(Q(x)\)" — capturing the logical core of mathematical reasoning.

Frege's work laid the groundwork for all modern logic and is the direct ancestor of the formal systems studied in this course.

---

### Naive set theory and Russell's paradox

Frege (and Cantor) used **naive set theory**, where any definable property determines a set:

- **Sets and membership:** \(x \in S\) means \(x\) belongs to set \(S\).
- **Subsets:** \(A \subseteq B\) iff every member of \(A\) is a member of \(B\).
- **Comprehension principle:** for any property \(\varphi(x)\), there exists a set \(\{x \mid \varphi(x)\}\).

**Russell's paradox** (1901) shows this is inconsistent. Define

$$R = \{X \mid X \notin X\}$$

and ask: is \(R \in R\)?

- If \(R \in R\), then by definition \(R \notin R\) — contradiction.
- If \(R \notin R\), then by definition \(R \in R\) — contradiction.

Either way we reach a contradiction, so the naive comprehension principle is **inconsistent**. This forced a retreat to **axiomatic** set theories (e.g. ZFC) with restricted comprehension, and it demonstrated the critical importance of **rigorous foundations**.

---

### Hilbert's programme

**David Hilbert** (1862–1943) proposed an ambitious programme: find a single formal system that is

1. **Consistent** — it never derives a contradiction, and
2. **Complete** — every true mathematical statement is provable within the system.

If successful, all of mathematics would rest on a secure, mechanically checkable foundation. This programme also demanded **decidability** — an effective procedure to determine, for any statement, whether it is provable.

---

### Gödel's Incompleteness Theorems

**Kurt Gödel** (1906–1978) proved in 1931 that Hilbert's programme is **impossible** in its full generality:

- **First Incompleteness Theorem:** Any consistent formal system \(F\) that can express basic arithmetic contains statements that are **true** (in the standard model of natural numbers) but **not provable** in \(F\). Such a system is necessarily **incomplete**.
- **Second Incompleteness Theorem:** Moreover, \(F\) cannot prove its **own consistency** (assuming it is in fact consistent).

**Key technique:** Gödel constructed a self-referential sentence \(G\) that effectively says "I am not provable in \(F\)." If \(F\) is consistent, \(G\) is true but unprovable; if \(F\) proves \(G\), then \(F\) is inconsistent.

**Consequence:** No single formal system can be both **consistent** and **complete** for all of mathematics. There will always be truths beyond the reach of any given axiom system.

---

### Turing, computability, and the halting problem

**Alan Turing** (1912–1954) formalised the notion of **effective computation** via **Turing machines** (1936) — abstract devices with a tape, a head, and a finite set of states that read, write, and move.

Turing proved that the **halting problem** is **undecidable**: there is no algorithm that, given a description of a Turing machine \(M\) and an input \(w\), always correctly determines whether \(M\) halts on \(w\).

**Proof sketch (diagonalisation):** Suppose a decider \(H(M, w)\) exists. Construct a machine \(D\) that, on input \(M\), runs \(H(M, M)\) and does the **opposite** (loops if \(H\) says "halts", halts if \(H\) says "loops"). Then \(D(D)\) leads to a contradiction — \(H\) cannot exist.

**Connection to Gödel:** Both results use **self-reference** and **diagonalisation**. Gödel shows limits of **provability**; Turing shows limits of **computability**. Together they bound what formal systems and algorithms can achieve.

---

### Hoare logic and program verification

**Tony Hoare** (1934–) introduced **Hoare triples** for reasoning about the correctness of imperative programs:

$$\{A\}\ C\ \{B\}$$

This reads: "If the **precondition** \(A\) holds before executing command \(C\), and \(C\) terminates, then the **postcondition** \(B\) holds afterward."

**Example:**

$$\{x = 5\}\ \texttt{x := x + 1}\ \{x = 6\}$$

Hoare logic provides **inference rules** for assignments, sequencing, conditionals, and loops, enabling **formal proofs** that programs meet their specifications. This bridges logic and software engineering: the correctness of code becomes a **theorem** to be proved.

---

### Computer science applications of logic

Logic is not a historical curiosity — it is embedded throughout modern CS:

| Area | How logic applies |
|------|-------------------|
| **Databases** | SQL queries rest on **relational algebra** and **first-order logic** |
| **Hardware verification** | Circuit correctness checked via **propositional satisfiability** (SAT solvers) |
| **Programming language design** | **Type systems** are logical systems; the **Curry–Howard correspondence** equates types with propositions and programs with proofs |
| **Machine learning / AI** | Knowledge representation, expert systems, and probabilistic reasoning all build on logical formalisms |
| **Software verification** | Tools like model checkers and proof assistants use **temporal logic** and **Hoare logic** to verify code |

---

## 2. EXAM-STYLE QUESTIONS (WITH MODEL ANSWERS)

### Q1 — Classical principles

**Question.** State the **law of non-contradiction** and the **law of excluded middle** in symbolic form. What does it mean for a logical system to be **bivalent**, and how do these two laws enforce bivalence?

**Model answer.** **Law of non-contradiction:** \(\lnot(A \land \lnot A)\) — a proposition cannot be both true and false. **Law of excluded middle:** \(A \lor \lnot A\) — every proposition is either true or false. A system is **bivalent** if every proposition receives exactly one of two truth values (true or false). Non-contradiction rules out "both true and false"; excluded middle rules out "neither true nor false." Together they ensure every proposition is assigned **exactly one** truth value.

---

### Q2 — Russell's paradox

**Question.** Define the set \(R = \{X \mid X \notin X\}\). Show that assuming \(R\) exists leads to a contradiction. What principle of naive set theory does this refute?

**Model answer.** Ask whether \(R \in R\). **Case 1:** Suppose \(R \in R\). By definition of \(R\), members satisfy \(X \notin X\), so \(R \notin R\) — contradiction. **Case 2:** Suppose \(R \notin R\). Then \(R\) satisfies the defining property \(X \notin X\), so \(R \in R\) — contradiction. Both cases lead to contradictions, so the assumption that \(R\) exists is untenable. This refutes the **unrestricted comprehension principle** of naive set theory, which asserts that any property defines a set.

---

### Q3 — Gödel's First Incompleteness Theorem

**Question.** State Gödel's First Incompleteness Theorem. Explain briefly the role of **self-reference** in the proof.

**Model answer.** **Theorem:** Any consistent formal system \(F\) capable of expressing basic arithmetic contains a sentence \(G\) that is true (in the standard model of \(\mathbb{N}\)) but not provable in \(F\). \(F\) is therefore **incomplete**. **Self-reference:** Gödel constructed \(G\) to encode "this sentence is not provable in \(F\)." If \(F\) proves \(G\), then \(G\) is false (since it says it is not provable), making \(F\) inconsistent. If \(F\) is consistent, then \(G\) is not provable, hence \(G\) is true — an unprovable truth.

---

### Q4 — Turing and the halting problem

**Question.** What is the **halting problem**? Sketch why it is undecidable using a diagonalisation argument.

**Model answer.** The halting problem asks: given a Turing machine \(M\) and input \(w\), does \(M\) halt on \(w\)? **Proof of undecidability:** Assume a total decider \(H(M, w)\) exists that outputs "yes" if \(M\) halts on \(w\) and "no" otherwise. Construct machine \(D\): on input \(M\), \(D\) runs \(H(M, M)\); if \(H\) says "halts," \(D\) loops forever; if \(H\) says "loops," \(D\) halts. Now consider \(D(D)\): if \(D\) halts on \(D\), then \(H(D,D)\) says "halts," so \(D\) loops — contradiction. If \(D\) loops on \(D\), then \(H(D,D)\) says "loops," so \(D\) halts — contradiction. Therefore \(H\) cannot exist.

---

### Q5 — Hoare triples

**Question.** Explain the meaning of the Hoare triple \(\{A\}\ C\ \{B\}\). Give a concrete example involving an assignment statement.

**Model answer.** \(\{A\}\ C\ \{B\}\) asserts **partial correctness**: if the precondition \(A\) is true before \(C\) executes, and \(C\) terminates, then the postcondition \(B\) is true afterward. It does **not** guarantee termination (that would be **total correctness**). **Example:** \(\{x \ge 0\}\ \texttt{x := x + 1}\ \{x \ge 1\}\). If \(x \ge 0\) before the assignment, then after incrementing, \(x \ge 1\).

---

## 3. MUST-KNOW KEY POINTS

- **Logic = syntax + semantics + inference rules** — the three layers of any formal system.
- **Aristotle's syllogisms** were the first systematic logic but could not handle relations or nested quantification.
- **Classical logic** rests on **non-contradiction** \(\lnot(A \land \lnot A)\) and **excluded middle** \(A \lor \lnot A\) — bivalent truth.
- **Inconsistency** is fatal: from a contradiction, everything follows (*ex falso quodlibet*).
- **Frege** invented **predicate logic** with quantifiers (\(\forall, \exists\)) and **formal proofs** — the foundation of modern logic.
- **Russell's paradox** \(R = \{X \mid X \notin X\}\) refutes **unrestricted comprehension** in naive set theory.
- **Hilbert's programme** sought a consistent + complete system for all mathematics — **Gödel** proved this is impossible.
- **Gödel's First Incompleteness Theorem:** any consistent system for arithmetic is incomplete (true unprovable sentences exist).
- **Turing:** formalised computation via Turing machines; proved the **halting problem** is undecidable.
- **Hoare triples** \(\{A\}\ C\ \{B\}\) enable **formal verification** of programs.
- Logic pervades CS: databases, hardware, PLs, AI, verification.

---

## 4. HIGH-PRIORITY TOPICS

### 🔴 Must Know

- **Three layers** of a logical system: syntax, semantics, inference rules.
- **Law of non-contradiction** and **law of excluded middle** — symbolic forms and intuitive meaning.
- **Russell's paradox:** construction of \(R\), the contradiction, and what it refutes.
- **Gödel's First Incompleteness Theorem:** statement and the self-referential idea behind the proof.
- **Halting problem:** statement and diagonalisation proof sketch.
- **Hoare triples:** notation \(\{A\}\ C\ \{B\}\), meaning of partial correctness, a simple example.

### 🟡 Important

- **Frege's contributions:** predicate logic, quantifiers, formal proofs — and why they superseded syllogisms.
- **Hilbert's programme:** the goals (consistency + completeness + decidability) and why Gödel/Turing defeated them.
- **Gödel's Second Incompleteness Theorem:** a consistent system cannot prove its own consistency.
- **Inconsistency and explosion:** why a contradiction makes a system trivial.

### 🟢 Useful but Lower Priority

- Aristotle's specific syllogistic forms (Barbara, etc.).
- Detailed comparison of intuitionistic vs classical logic.
- Specific CS application areas (databases, hardware, etc.) — awareness is sufficient; deep detail is not expected.
- Historical timeline and biographical details beyond the key contributions.

---

## 5. TOPIC INTERCONNECTIONS & BIGGER PICTURE

- **Propositional and predicate logic** (Lectures 2–7) build directly on the **syntax / semantics / inference** framework introduced here — every subsequent topic instantiates this three-layer pattern.
- **Russell's paradox** motivates **careful axiomatisation** — the same caution reappears in **type theory** and **programming language** foundations (preventing "type-level contradictions").
- **Gödel's incompleteness** connects to **computability theory**: the unprovable Gödel sentence is closely related to the halting problem via the **arithmetisation of syntax** and **diagonalisation**. Both establish absolute limits.
- **Hoare logic** connects formal logic to **software engineering** — it reappears in courses on formal methods, compilers, and concurrency.
- **Boolean algebra** (Lecture 4) provides the algebraic counterpart to propositional logic — the correspondence between logical connectives and algebraic operations threads through the entire module.

---

## 6. EXAM STRATEGY TIPS

- **Lead with definitions.** When asked "what is logic?" or "what is a formal system?", structure your answer around the **three layers** (syntax, semantics, inference) — this shows you understand the framework, not just examples.
- **Russell's paradox:** Write out the definition of \(R\), then explicitly do **both cases** (\(R \in R\) and \(R \notin R\)). State the conclusion: unrestricted comprehension is inconsistent.
- **Gödel questions:** State the theorem precisely first, then give the **one-paragraph** self-reference intuition. Don't attempt a full proof — examiners want the statement and the key idea.
- **Halting problem:** The diagonalisation argument has three steps: (1) assume \(H\) exists, (2) build \(D\) that does the opposite, (3) apply \(D\) to itself for contradiction. Practise writing this in under 10 lines.
- **Hoare triples:** Always specify that \(\{A\}\ C\ \{B\}\) gives **partial** correctness (termination not guaranteed) unless the question specifies total correctness.
- **Link results together.** If asked about the "limits of formal systems," mention **both** Gödel (limits of provability) and Turing (limits of computability) and note the shared **diagonalisation** technique.

---

*These notes cover Logic Lecture 1 of COMP0003 Formal Logic — the historical and conceptual foundations upon which propositional logic, predicate logic, and formal proof systems are built.*
