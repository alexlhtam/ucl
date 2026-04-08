# DIAGRAM_PACK — COMP0147 Discrete Mathematics

> This file is read by **Agent 2** to generate images.
> Each entry specifies one figure: its prompt, filename, save path, and where to embed it.

---

## 1 — number-sets-venn

- **ID**: `number-sets-venn`
- **Image prompt**: A clean, modern Venn-style diagram showing the nested containment of number sets. Concentric rounded rectangles (not circles) centred on the page. Innermost: **N** (natural numbers) in light green. Next layer: **Z** (integers) in light blue. Then **Q** (rationals) in light yellow. Then **R** (reals) in light orange. Mark the region R \ Q as **I** (irrationals) with a hatch pattern or distinct tint. Each region is labelled with the set symbol in bold sans-serif. Include a few representative elements in each region: 0, 1, 2 in N; −3 in Z; 1/2 in Q; √2, π in I. White background. No copyrighted material. Flat vector style with thin dark borders.
- **Filename**: `number-sets-venn.png`
- **Save path**: `ucl/year1/comp0147/resources/number-sets-venn.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/01-numbers.md`
  - Section heading: `## Number Sets`
  - Markdown: `![Nested number sets: N ⊂ Z ⊂ Q ⊂ R, with irrationals I = R \ Q](../resources/number-sets-venn.png)`
- **Relative path from .md**: `../resources/number-sets-venn.png`
- **Alt text**: Nested number sets: N ⊂ Z ⊂ Q ⊂ R, with irrationals I = R \ Q
- **Priority**: High

---

## 2 — decimal-to-binary

- **ID**: `decimal-to-binary`
- **Image prompt**: A step-by-step diagram showing the conversion of the decimal number 77 to binary using repeated division by 2. Left column shows the divisions: 77÷2=38 R1, 38÷2=19 R0, 19÷2=9 R1, 9÷2=4 R1, 4÷2=2 R0, 2÷2=1 R0, 1÷2=0 R1. Right side shows an arrow labelled "read remainders bottom-to-top" pointing to the result 1001101₂. Clean flat vector style, white background, dark text, remainders highlighted in blue circles, result in a green box.
- **Filename**: `decimal-to-binary.png`
- **Save path**: `ucl/year1/comp0147/resources/decimal-to-binary.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/01-numbers.md`
  - Section heading: `## Binary Representation`
  - Markdown: `![Converting 77 to binary via repeated division by 2](../resources/decimal-to-binary.png)`
- **Relative path from .md**: `../resources/decimal-to-binary.png`
- **Alt text**: Converting 77 to binary via repeated division by 2
- **Priority**: Medium

---

## 3 — logic-connectives-truth-tables

- **ID**: `logic-connectives-truth-tables`
- **Image prompt**: A single reference card showing truth tables for all five main propositional logic connectives side by side: NOT (¬p), AND (p∧q), OR (p∨q), XOR (p⊕q), IMPLIES (p→q), IFF (p↔q). Each connective has a small clearly labelled truth table with T/F values. Use a grid layout: 2 rows × 3 columns of small tables. Monospace font for T/F entries. Light pastel column headers. Clean flat vector style, white background, thin borders.
- **Filename**: `logic-connectives-truth-tables.png`
- **Save path**: `ucl/year1/comp0147/resources/logic-connectives-truth-tables.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/02-propositional-logic.md`
  - Section heading: `## Connectives at a Glance`
  - Markdown: `![Truth tables for all main propositional logic connectives](../resources/logic-connectives-truth-tables.png)`
- **Relative path from .md**: `../resources/logic-connectives-truth-tables.png`
- **Alt text**: Truth tables for all main propositional logic connectives
- **Priority**: High

---

## 4 — implication-truth-table-visual

- **ID**: `implication-truth-table-visual`
- **Image prompt**: A 2×2 grid visualisation of the implication p→q truth table. Top-left cell (P true, Q true): green check "TRUE". Top-right cell (P true, Q false): red cross "FALSE — only case where implication fails". Bottom-left cell (P false, Q true): green check "TRUE". Bottom-right cell (P false, Q false): green check "TRUE". Row header "P" on left, column header "Q" on top. Annotation: "Implication is only false when P is true but Q is false." Clean, minimal, pastel colours, no copyrighted material.
- **Filename**: `implication-truth-table-visual.png`
- **Save path**: `ucl/year1/comp0147/resources/implication-truth-table-visual.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/02-propositional-logic.md`
  - Section heading: `## Implication`
  - Markdown: `![Visual truth table for implication: only false when P true and Q false](../resources/implication-truth-table-visual.png)`
- **Relative path from .md**: `../resources/implication-truth-table-visual.png`
- **Alt text**: Visual truth table for implication: only false when P true and Q false
- **Priority**: Medium

---

## 5 — quantifier-negation-rules

- **ID**: `quantifier-negation-rules`
- **Image prompt**: A compact reference card showing De Morgan's laws for quantifiers. Two rows. Row 1: ¬(∀x P(x)) ≡ ∃x ¬P(x), with a left arrow labelled "flip ∀→∃, negate inside". Row 2: ¬(∃x P(x)) ≡ ∀x ¬P(x), with a left arrow labelled "flip ∃→∀, negate inside". Also show the consequence forms: ∀x P(x) ≡ ¬∃x ¬P(x) and ∃x P(x) ≡ ¬∀x ¬P(x). Use large clear mathematical notation, blue accent arrows, white background, flat vector style.
- **Filename**: `quantifier-negation-rules.png`
- **Save path**: `ucl/year1/comp0147/resources/quantifier-negation-rules.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/03-first-order-logic.md`
  - Section heading: `## Negating Quantifiers`
  - Markdown: `![De Morgan's laws for quantifiers: negation flips ∀↔∃](../resources/quantifier-negation-rules.png)`
- **Relative path from .md**: `../resources/quantifier-negation-rules.png`
- **Alt text**: De Morgan's laws for quantifiers: negation flips ∀↔∃
- **Priority**: High

---

## 6 — euclidean-algorithm-example

- **ID**: `euclidean-algorithm-example`
- **Image prompt**: A step-by-step diagram of the Euclidean algorithm computing gcd(1234, 54). Show each division step as a row: 1234 = 54×22 + 46, then 54 = 46×1 + 8, then 46 = 8×5 + 6, then 8 = 6×1 + 2, then 6 = 2×3 + 0. Highlight the final nonzero remainder (2) in a green box with label "gcd(1234,54) = 2". Use arrows connecting each remainder to the next step's divisor. Clean flat vector style, white background.
- **Filename**: `euclidean-algorithm-example.png`
- **Save path**: `ucl/year1/comp0147/resources/euclidean-algorithm-example.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/04-modular-arithmetic-and-primes.md`
  - Section heading: `## Euclidean Algorithm`
  - Markdown: `![Euclidean algorithm computing gcd(1234, 54) = 2](../resources/euclidean-algorithm-example.png)`
- **Relative path from .md**: `../resources/euclidean-algorithm-example.png`
- **Alt text**: Euclidean algorithm computing gcd(1234, 54) = 2
- **Priority**: Medium

---

## 7 — proof-techniques-flowchart

- **ID**: `proof-techniques-flowchart`
- **Image prompt**: A decision flowchart for choosing proof techniques. Start node: "What are you proving?". Branch 1: "∀x P(x)→Q(x)" leads to choices: "Direct proof (assume P, show Q)", "Contraposition (assume ¬Q, show ¬P)", "Contradiction (assume P∧¬Q, derive absurdity)". Branch 2: "∃x P(x)" leads to "Constructive (find witness)" or "Non-constructive (indirect)". Branch 3: "Disprove ∀x P(x)" leads to "Find counterexample". Branch 4: "P₁∨P₂∨...→Q" leads to "Case analysis". Each leaf node is in a coloured rounded box. Clean flowchart style, no copyrighted material, flat vector, white background.
- **Filename**: `proof-techniques-flowchart.png`
- **Save path**: `ucl/year1/comp0147/resources/proof-techniques-flowchart.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/05-proofs.md`
  - Section heading: `## Choosing a Proof Technique`
  - Markdown: `![Flowchart for choosing the right proof technique](../resources/proof-techniques-flowchart.png)`
- **Relative path from .md**: `../resources/proof-techniques-flowchart.png`
- **Alt text**: Flowchart for choosing the right proof technique
- **Priority**: High

---

## 8 — induction-ladder

- **ID**: `induction-ladder`
- **Image prompt**: A diagram of an infinite ladder extending upward. The bottom rung is labelled "Base case P(1) ✓". The second rung has an arrow from the first rung labelled "P(1)→P(2)". The third rung has an arrow from the second labelled "P(2)→P(3)", and so on with "..." continuing upward. A bracket on the right side says "Inductive step: P(k)→P(k+1) for all k". The conclusion at the top says "∴ P(n) for all n ≥ 1". Light blue ladder, gold rungs, green checks on reached rungs. Clean flat vector, white background.
- **Filename**: `induction-ladder.png`
- **Save path**: `ucl/year1/comp0147/resources/induction-ladder.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/06-induction.md`
  - Section heading: `## The Principle`
  - Markdown: `![Induction as climbing an infinite ladder: base case + inductive step](../resources/induction-ladder.png)`
- **Relative path from .md**: `../resources/induction-ladder.png`
- **Alt text**: Induction as climbing an infinite ladder: base case + inductive step
- **Priority**: High

---

## 9 — l-tiling-induction

- **ID**: `l-tiling-induction`
- **Image prompt**: A 6-panel diagram showing the inductive step for L-shaped tiling of a 2^(k+1) × 2^(k+1) board. Panel (a): the full board with one square removed. Panel (b): board divided into four 2^k × 2^k quadrants. Panel (c): the quadrant containing the removed square is tiled by I.H. Panel (d): one square temporarily removed from each of the other three quadrants (at the shared centre corner). Panel (e): each of those three quadrants tiled by I.H. Panel (f): the three removed centre squares filled with one L-shaped piece. Use distinct pastel colours for different quadrants; show the L-piece in red. Grid lines visible. Clean flat vector, white background, no copyrighted material.
- **Filename**: `l-tiling-induction.png`
- **Save path**: `ucl/year1/comp0147/resources/l-tiling-induction.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/06-induction.md`
  - Section heading: `### L-Shaped Tiling`
  - Markdown: `![Inductive step for L-shaped tiling: divide, apply I.H., fill centre with one L-piece](../resources/l-tiling-induction.png)`
- **Relative path from .md**: `../resources/l-tiling-induction.png`
- **Alt text**: Inductive step for L-shaped tiling: divide, apply I.H., fill centre with one L-piece
- **Priority**: Medium

---

## 10 — tower-of-hanoi

- **ID**: `tower-of-hanoi`
- **Image prompt**: A diagram of the Tower of Hanoi with 3 pegs labelled A, B, C and 4 disks of decreasing size stacked on peg A. Show the three-step strategy as annotated arrows: (1) "Move top k disks A→B (2^k − 1 moves)", (2) "Move largest disk A→C (1 move)", (3) "Move k disks B→C (2^k − 1 moves)". Total label: "M(k+1) = 2·M(k) + 1 = 2^(k+1) − 1". Wooden-style pegs, coloured disks (blue, green, yellow, red from top to bottom). Clean flat vector, white background.
- **Filename**: `tower-of-hanoi.png`
- **Save path**: `ucl/year1/comp0147/resources/tower-of-hanoi.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/06-induction.md`
  - Section heading: `### Tower of Hanoi`
  - Markdown: `![Tower of Hanoi: recursive strategy for n disks requires 2^n − 1 moves](../resources/tower-of-hanoi.png)`
- **Relative path from .md**: `../resources/tower-of-hanoi.png`
- **Alt text**: Tower of Hanoi: recursive strategy for n disks requires 2^n − 1 moves
- **Priority**: Medium

---

## 11 — strong-vs-weak-induction

- **ID**: `strong-vs-weak-induction`
- **Image prompt**: A side-by-side comparison diagram. Left side: "Weak Induction" — a chain of dominoes where each domino topples only the next one. Arrow from P(k) to P(k+1). Right side: "Strong Induction" — a chain where ALL previous dominoes are used: arrows from P(1), P(2), ..., P(k) all pointing to P(k+1). Caption below weak: "I.H.: P(k) is true". Caption below strong: "I.H.: P(1)∧P(2)∧...∧P(k) are all true". Clean flat vector, pastel colours, white background.
- **Filename**: `strong-vs-weak-induction.png`
- **Save path**: `ucl/year1/comp0147/resources/strong-vs-weak-induction.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/07-strong-induction.md`
  - Section heading: `## Weak vs Strong Induction`
  - Markdown: `![Weak induction uses P(k); strong induction uses P(1)∧...∧P(k)](../resources/strong-vs-weak-induction.png)`
- **Relative path from .md**: `../resources/strong-vs-weak-induction.png`
- **Alt text**: Weak induction uses P(k); strong induction uses P(1)∧...∧P(k)
- **Priority**: High

---

## 12 — recursive-fibonacci-tree

- **ID**: `recursive-fibonacci-tree`
- **Image prompt**: A call tree diagram for computing Fibonacci f(5). Root node "f(5)" branches to "f(4)" and "f(3)". "f(4)" branches to "f(3)" and "f(2)". Each "f(3)" branches to "f(2)" and "f(1)". Each "f(2)" branches to "f(1)" and "f(0)". Leaf nodes f(1)=1 and f(0)=1 are shown in green. Repeated subtrees (like f(3) appearing twice) highlighted with a dashed border and note "computed twice". Clean tree layout, flat vector style, white background.
- **Filename**: `recursive-fibonacci-tree.png`
- **Save path**: `ucl/year1/comp0147/resources/recursive-fibonacci-tree.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/08-recursion-and-structural-induction.md`
  - Section heading: `## Recursive Functions`
  - Markdown: `![Recursive call tree for Fibonacci f(5), showing repeated subproblems](../resources/recursive-fibonacci-tree.png)`
- **Relative path from .md**: `../resources/recursive-fibonacci-tree.png`
- **Alt text**: Recursive call tree for Fibonacci f(5), showing repeated subproblems
- **Priority**: Medium

---

## 13 — set-operations-venn

- **ID**: `set-operations-venn`
- **Image prompt**: A 2×3 grid of Venn diagrams showing the six main set operations. Each diagram has two overlapping circles A and B inside a rectangle U (universal set). Shaded regions: (1) A∪B — both circles shaded. (2) A∩B — overlap shaded. (3) A−B — A minus overlap shaded. (4) A^c — everything outside A shaded. (5) A△B (symmetric difference) — both circles minus overlap shaded. (6) A×B conceptual — not a Venn, instead show a grid of pairs. Labels under each. Consistent pastel blue/pink colouring for A and B. Clean flat vector, white background.
- **Filename**: `set-operations-venn.png`
- **Save path**: `ucl/year1/comp0147/resources/set-operations-venn.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/09-sets.md`
  - Section heading: `## Set Operations`
  - Markdown: `![Venn diagrams for union, intersection, difference, complement, and symmetric difference](../resources/set-operations-venn.png)`
- **Relative path from .md**: `../resources/set-operations-venn.png`
- **Alt text**: Venn diagrams for union, intersection, difference, complement, and symmetric difference
- **Priority**: High

---

## 14 — function-types

- **ID**: `function-types`
- **Image prompt**: Three side-by-side arrow diagrams showing injective, surjective, and bijective functions. Each shows a set A on the left (3-4 dots labelled a₁,a₂,...) and set B on the right (3-4 dots labelled b₁,b₂,...) with arrows mapping A to B. (1) Injective: each element of A maps to a different element of B; one element of B has no arrow. Label: "Injective (one-to-one)". (2) Surjective: every element of B has at least one arrow; two elements of A map to the same b. Label: "Surjective (onto)". (3) Bijective: perfect pairing, each a maps to exactly one unique b. Label: "Bijective". Clean flat vector, pastel colours, white background.
- **Filename**: `function-types.png`
- **Save path**: `ucl/year1/comp0147/resources/function-types.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/10-functions-and-sequences.md`
  - Section heading: `## Injective, Surjective, Bijective`
  - Markdown: `![Arrow diagrams: injective, surjective, and bijective functions](../resources/function-types.png)`
- **Relative path from .md**: `../resources/function-types.png`
- **Alt text**: Arrow diagrams: injective, surjective, and bijective functions
- **Priority**: High

---

## 15 — pigeonhole-principle

- **ID**: `pigeonhole-principle`
- **Image prompt**: A cartoon-style diagram illustrating the pigeonhole principle. Show 5 colourful pigeons trying to fit into 4 pigeonholes (small house-shaped boxes). One box clearly has 2 pigeons squeezed in together. Text label: "k+1 objects into k boxes → at least one box has ≥ 2 objects". For the generalised version below: "N objects into k boxes → at least one box has ≥ ⌈N/k⌉ objects". Friendly, clean flat illustration style, white background, no copyrighted material.
- **Filename**: `pigeonhole-principle.png`
- **Save path**: `ucl/year1/comp0147/resources/pigeonhole-principle.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/11-counting.md`
  - Section heading: `## Pigeonhole Principle`
  - Markdown: `![Pigeonhole principle: k+1 pigeons in k holes means at least one hole has two](../resources/pigeonhole-principle.png)`
- **Relative path from .md**: `../resources/pigeonhole-principle.png`
- **Alt text**: Pigeonhole principle: k+1 pigeons in k holes means at least one hole has two
- **Priority**: High

---

## 16 — counting-summary-table

- **ID**: `counting-summary-table`
- **Image prompt**: A clean 2×2 summary table for counting formulas. Rows: "Without repetition" and "With repetition". Columns: "Order matters (Permutations)" and "Order doesn't matter (Combinations)". Cell contents: (1) P(n,r)=n!/(n−r)!, (2) C(n,r)=n!/(r!(n−r)!), (3) nʳ, (4) C(n+r−1,r). Each cell has the formula in large text and a short label. Use distinct pastel colours for each cell. Clean flat vector, white background.
- **Filename**: `counting-summary-table.png`
- **Save path**: `ucl/year1/comp0147/resources/counting-summary-table.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/11-counting.md`
  - Section heading: `## Summary`
  - Markdown: `![Counting formulas: permutations and combinations with/without repetition](../resources/counting-summary-table.png)`
- **Relative path from .md**: `../resources/counting-summary-table.png`
- **Alt text**: Counting formulas: permutations and combinations with/without repetition
- **Priority**: High

---

## 17 — pascals-triangle

- **ID**: `pascals-triangle`
- **Image prompt**: Pascal's Triangle showing the first 7 rows (row 0 through row 6). Each entry is the binomial coefficient C(n,k). Entries arranged in a triangular pattern centred horizontally. Row 0: 1. Row 1: 1 1. Row 2: 1 2 1. Row 3: 1 3 3 1. Row 4: 1 4 6 4 1. Row 5: 1 5 10 10 5 1. Row 6: 1 6 15 20 15 6 1. Light connecting lines showing that each number is the sum of the two above it. Label the rows n=0,1,...,6 on the left. Clean flat vector, numbers in dark text on white circles, white background.
- **Filename**: `pascals-triangle.png`
- **Save path**: `ucl/year1/comp0147/resources/pascals-triangle.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/11-counting.md`
  - Section heading: `## Pascal's Triangle`
  - Markdown: `![Pascal's Triangle rows 0–6, each entry is C(n,k)](../resources/pascals-triangle.png)`
- **Relative path from .md**: `../resources/pascals-triangle.png`
- **Alt text**: Pascal's Triangle rows 0–6, each entry is C(n,k)
- **Priority**: Medium

---

## 18 — cantor-diagonal

- **ID**: `cantor-diagonal`
- **Image prompt**: A diagram illustrating Cantor's diagonal argument. Show a table with rows r₁, r₂, r₃, r₄, ... and columns representing decimal/binary digits. Each row is a real number in [0,1) written as a sequence of digits. The diagonal entries (r₁₁, r₂₂, r₃₃, r₄₄, ...) are highlighted in red. Below the table, construct the number s by flipping each diagonal digit (e.g. 0→1, 1→0). Annotation: "s differs from rₙ in the n-th digit → s is not in the list → contradiction". Clean flat vector style, white background, red highlighting on diagonal.
- **Filename**: `cantor-diagonal.png`
- **Save path**: `ucl/year1/comp0147/resources/cantor-diagonal.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/12-cardinality.md`
  - Section heading: `## R Is Uncountable`
  - Markdown: `![Cantor's diagonal argument: constructing a real not in any enumeration](../resources/cantor-diagonal.png)`
- **Relative path from .md**: `../resources/cantor-diagonal.png`
- **Alt text**: Cantor's diagonal argument: constructing a real not in any enumeration
- **Priority**: High

---

## 19 — rationals-countable-zigzag

- **ID**: `rationals-countable-zigzag`
- **Image prompt**: A table/grid with rows labelled by numerators (0, 1, −1, 2, −2, ...) and columns labelled by denominators (1, 2, 3, 4, 5, ...). Each cell shows the fraction numerator/denominator. A zig-zag path (Cantor pairing) winds through the grid, enumerating rationals in order: 0/1, 1/1, −1/1, 1/2, −1/2, 2/1, −2/1, ... Cells with non-simplified fractions (like 2/2, 3/3) are crossed out. The zig-zag path is drawn in blue with numbered steps. Clean flat vector, white background.
- **Filename**: `rationals-countable-zigzag.png`
- **Save path**: `ucl/year1/comp0147/resources/rationals-countable-zigzag.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/12-cardinality.md`
  - Section heading: `## Q Is Countable`
  - Markdown: `![Zig-zag enumeration showing the rationals are countable](../resources/rationals-countable-zigzag.png)`
- **Relative path from .md**: `../resources/rationals-countable-zigzag.png`
- **Alt text**: Zig-zag enumeration showing the rationals are countable
- **Priority**: Medium

---

## 20 — relation-properties

- **ID**: `relation-properties`
- **Image prompt**: A 2×2 grid of small directed graphs (digraphs) on 3 nodes {1,2,3}, each illustrating one relation property. (1) Reflexive: loops on all 3 vertices, plus some other edges. Label "Reflexive: loop on every vertex". (2) Symmetric: for every edge u→v, there is also v→u (double-headed arrows). Label "Symmetric: all edges bidirectional". (3) Antisymmetric: no pair of distinct vertices has edges in both directions. Label "Antisymmetric: no two-way edges between distinct vertices". (4) Transitive: if 1→2 and 2→3 then 1→3 exists. Label "Transitive: indirect path implies direct edge". Clean flat vector, distinct pastel background for each, white overall background.
- **Filename**: `relation-properties.png`
- **Save path**: `ucl/year1/comp0147/resources/relation-properties.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/13-relations.md`
  - Section heading: `## Properties of Relations`
  - Markdown: `![Four key relation properties illustrated as digraphs: reflexive, symmetric, antisymmetric, transitive](../resources/relation-properties.png)`
- **Relative path from .md**: `../resources/relation-properties.png`
- **Alt text**: Four key relation properties illustrated as digraphs: reflexive, symmetric, antisymmetric, transitive
- **Priority**: High

---

## 21 — equivalence-classes-partition

- **ID**: `equivalence-classes-partition`
- **Image prompt**: A diagram showing a set A = {2, 3, 4, 6, 7, 9} partitioned into three equivalence classes by congruence modulo 3. Three distinct coloured regions (blobs): green blob contains {3, 6, 9} labelled "[0] — remainder 0"; blue blob contains {4, 7} labelled "[1] — remainder 1"; pink blob contains {2} labelled "[2] — remainder 2". Within each blob, elements are connected by edges showing they are related. Outside the blobs, the universal set boundary is drawn. Caption: "Equivalence classes partition the set into disjoint subsets". Clean flat vector, white background.
- **Filename**: `equivalence-classes-partition.png`
- **Save path**: `ucl/year1/comp0147/resources/equivalence-classes-partition.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/13-relations.md`
  - Section heading: `## Equivalence Classes and Partitions`
  - Markdown: `![Equivalence classes of mod 3 partitioning {2,3,4,6,7,9}](../resources/equivalence-classes-partition.png)`
- **Relative path from .md**: `../resources/equivalence-classes-partition.png`
- **Alt text**: Equivalence classes of mod 3 partitioning {2,3,4,6,7,9}
- **Priority**: Medium

---

## 22 — hasse-diagram-example

- **ID**: `hasse-diagram-example`
- **Image prompt**: Two diagrams side by side for the poset ({1,2,3,9,18}, divides). Left: the full directed graph with all divisibility edges (1→2, 1→3, 1→9, 1→18, 2→18, 3→9, 3→18, 9→18) plus loops. Right: the simplified Hasse diagram — same set arranged vertically with 1 at bottom, 18 at top; edges only between 1-2, 1-3, 2-18, 3-9, 9-18; no loops, no transitive edges, no arrows (upward implicit). Clearly labelled "Directed graph" and "Hasse diagram". Clean flat vector, white background.
- **Filename**: `hasse-diagram-example.png`
- **Save path**: `ucl/year1/comp0147/resources/hasse-diagram-example.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/13-relations.md`
  - Section heading: `## Hasse Diagrams`
  - Markdown: `![Divisibility poset on {1,2,3,9,18}: full digraph vs simplified Hasse diagram](../resources/hasse-diagram-example.png)`
- **Relative path from .md**: `../resources/hasse-diagram-example.png`
- **Alt text**: Divisibility poset on {1,2,3,9,18}: full digraph vs simplified Hasse diagram
- **Priority**: Medium

---

## 23 — graph-types-taxonomy

- **ID**: `graph-types-taxonomy`
- **Image prompt**: A visual taxonomy of graph types as a grid. Six small example graphs, each clearly labelled. (1) Simple graph: 3 vertices, simple edges, no loops, no multi-edges. (2) Multigraph: 3 vertices with double edges between a pair. (3) Pseudograph: 2 vertices with a loop and multi-edges. (4) Simple directed graph: 3 vertices with one-way arrows. (5) Directed multigraph: directed with multiple same-direction edges and a loop. (6) Mixed graph: has both directed and undirected edges. Below: a summary table row showing Type / Edges / Multi-Edges? / Loops?. Clean flat vector, white background, each graph in its own box.
- **Filename**: `graph-types-taxonomy.png`
- **Save path**: `ucl/year1/comp0147/resources/graph-types-taxonomy.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/14-graphs.md`
  - Section heading: `## Types of Graphs`
  - Markdown: `![Taxonomy of graph types: simple, multi, pseudo, directed, mixed](../resources/graph-types-taxonomy.png)`
- **Relative path from .md**: `../resources/graph-types-taxonomy.png`
- **Alt text**: Taxonomy of graph types: simple, multi, pseudo, directed, mixed
- **Priority**: High

---

## 24 — special-graphs

- **ID**: `special-graphs`
- **Image prompt**: A row of four small labelled graphs showing special graph families. (1) K₅ — complete graph on 5 vertices, all edges drawn. (2) C₆ — cycle on 6 vertices. (3) W₅ — wheel graph (C₄ + hub). (4) K₂,₃ — complete bipartite graph with 2 vertices top and 3 vertices bottom, all cross-edges. Each graph clearly labelled with its name. Vertices as filled circles, edges as thin lines. Clean flat vector, white background.
- **Filename**: `special-graphs.png`
- **Save path**: `ucl/year1/comp0147/resources/special-graphs.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/14-graphs.md`
  - Section heading: `## Special Graphs`
  - Markdown: `![Special graphs: K₅, C₆, W₅, K₂,₃](../resources/special-graphs.png)`
- **Relative path from .md**: `../resources/special-graphs.png`
- **Alt text**: Special graphs: K₅, C₆, W₅, K₂,₃
- **Priority**: Medium

---

## 25 — graph-representations

- **ID**: `graph-representations`
- **Image prompt**: Three representations of the same simple graph G with 5 vertices {a,b,c,d,e} and edges {ab, ac, bd, be, cd, de}. Left panel: the graph drawn visually as a node-link diagram. Centre panel: adjacency list (table with vertex → list of neighbours). Right panel: 5×5 adjacency matrix with 0s and 1s. All three clearly labelled "Graph", "Adjacency List", "Adjacency Matrix". Clean flat vector, white background, thin borders.
- **Filename**: `graph-representations.png`
- **Save path**: `ucl/year1/comp0147/resources/graph-representations.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/14-graphs.md`
  - Section heading: `## Representations`
  - Markdown: `![Three representations of a graph: visual, adjacency list, adjacency matrix](../resources/graph-representations.png)`
- **Relative path from .md**: `../resources/graph-representations.png`
- **Alt text**: Three representations of a graph: visual, adjacency list, adjacency matrix
- **Priority**: Medium

---

## 26 — connectivity-cut-vertex-bridge

- **ID**: `connectivity-cut-vertex-bridge`
- **Image prompt**: A connected graph with about 8 vertices. Two vertices are circled in red and labelled "Cut vertex" (their removal disconnects the graph). One edge is highlighted in red and labelled "Bridge" (its removal disconnects the graph). Show the graph intact on the left and the graph with a cut vertex removed on the right (now disconnected into two components). Clean flat vector, white background.
- **Filename**: `connectivity-cut-vertex-bridge.png`
- **Save path**: `ucl/year1/comp0147/resources/connectivity-cut-vertex-bridge.png`
- **Embed in**:
  - File: `ucl/year1/comp0147/cursor-notes/14-graphs.md`
  - Section heading: `## Connectivity`
  - Markdown: `![Cut vertices and bridges: removing them disconnects the graph](../resources/connectivity-cut-vertex-bridge.png)`
- **Relative path from .md**: `../resources/connectivity-cut-vertex-bridge.png`
- **Alt text**: Cut vertices and bridges: removing them disconnects the graph
- **Priority**: Medium
