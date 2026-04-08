# COMP0011 Diagram Pack

> This file specifies every figure that Agent 2 should generate for the COMP0011 cursor-notes.
> Do **not** edit cursor-notes or master-notes. Generate each image and place it at the given save path.
> After generating, embed using the Markdown snippet under "Embed in".

---

## 1. argand-diagram

- **ID**: `argand-diagram`
- **Image prompt**: A clean mathematical diagram of the Argand plane (complex plane). Show the horizontal axis labelled "Re" and vertical axis labelled "Im". Plot a single point z = x + iy as a blue dot. Draw a dashed horizontal line from the origin to x on the real axis, and a dashed vertical line from x up to the point z. Draw a solid arrow from the origin to z. Label the horizontal distance "x", the vertical distance "y", the arrow length "r = |z|", and the angle from the positive real axis "θ = arg(z)". Use a small arc to indicate the angle. White background, thin black axes, blue point and arrow, grey dashed construction lines. No copyrighted material. Mathematical/textbook style.
- **Filename**: `argand-diagram.png`
- **Save path**: `ucl/year1/comp0011/resources/argand-diagram.png`
- **Embed in**: `ucl/year1/comp0011/cursor-notes/01-complex-numbers.md`, section "## III. Geometric Representation"
- **Markdown snippet**: `![Argand diagram showing cartesian and polar representations](../resources/argand-diagram.png)`
- **Alt text**: Argand diagram showing cartesian and polar representations of a complex number
- **Priority**: High

---

## 2. roots-of-unity

- **ID**: `roots-of-unity`
- **Image prompt**: A diagram of the unit circle in the complex plane for n=5. Draw a circle of radius 1 centred at the origin with axes labelled "Re" and "Im". Mark 5 equally spaced points on the circle at angles 0, 2π/5, 4π/5, 6π/5, 8π/5. Label them ω₀=1, ω₁, ω₂, ω₃, ω₄ in blue. Connect consecutive points with thin grey lines to form a regular pentagon inscribed in the circle. Draw dashed radial lines from the origin to each point. White background, clean mathematical style. No copyrighted material.
- **Filename**: `roots-of-unity.png`
- **Save path**: `ucl/year1/comp0011/resources/roots-of-unity.png`
- **Embed in**: `ucl/year1/comp0011/cursor-notes/01-complex-numbers.md`, section "## V. Roots of Unity"
- **Markdown snippet**: `![Roots of unity on the unit circle for n=5](../resources/roots-of-unity.png)`
- **Alt text**: The five 5th roots of unity equally spaced on the unit circle forming a regular pentagon
- **Priority**: High

---

## 3. vector-addition-r2

- **ID**: `vector-addition-r2`
- **Image prompt**: A 2D coordinate plane showing vector addition and scalar multiplication in R². Draw two vectors u (red arrow) and v (blue arrow) originating from the origin. Show u+v as a green arrow using the parallelogram rule — draw dashed copies of u and v to complete the parallelogram. Separately, show v and 2v (a longer blue arrow in the same direction) to illustrate scalar multiplication. Label all vectors clearly: u, v, u+v, 2v. Use a light grid background. Clean mathematical style, no copyrighted material. White background.
- **Filename**: `vector-addition-r2.png`
- **Save path**: `ucl/year1/comp0011/resources/vector-addition-r2.png`
- **Embed in**: `ucl/year1/comp0011/cursor-notes/03-vector-spaces.md`, section "## III. Vectors of Real Numbers"
- **Markdown snippet**: `![Vectors in R2 showing addition and scalar multiplication](../resources/vector-addition-r2.png)`
- **Alt text**: Vectors in R2 showing addition via parallelogram rule and scalar multiplication
- **Priority**: Medium

---

## 4. gaussian-elimination

- **ID**: `gaussian-elimination`
- **Image prompt**: A step-by-step diagram showing Gaussian elimination on a 3×3 augmented matrix. Show three stages left-to-right with arrows between them: (1) the original augmented matrix [A|b], (2) the matrix after forward elimination producing upper triangular form with the eliminated entries shown as 0, (3) the solved form after back substitution showing the identity on the left. Use coloured highlights: red for the pivot elements, blue for the entries being eliminated. Label each arrow with the row operation performed (e.g. "L3 ← L3 - 5L1"). Clean mathematical style, white background, no copyrighted material.
- **Filename**: `gaussian-elimination.png`
- **Save path**: `ucl/year1/comp0011/resources/gaussian-elimination.png`
- **Embed in**: `ucl/year1/comp0011/cursor-notes/04-matrices.md`, section "### Gaussian Elimination"
- **Markdown snippet**: `![Gaussian elimination reducing to triangular form](../resources/gaussian-elimination.png)`
- **Alt text**: Step-by-step Gaussian elimination reducing an augmented matrix to upper triangular form
- **Priority**: High

---

## 5. exp-ln-graphs

- **ID**: `exp-ln-graphs`
- **Image prompt**: A plot showing the graphs of y = eˣ (red curve) and y = ln(x) (blue curve) on the same axes, along with the dashed line y = x (grey). The two curves should be visible as reflections of each other across y = x. Mark the points (0,1) on eˣ and (1,0) on ln(x). Label axes "x" and "y". Show that eˣ is always positive and grows steeply to the right, while ln(x) is only defined for x > 0 and grows slowly. White background, clean mathematical/textbook style. No copyrighted material.
- **Filename**: `exp-ln-graphs.png`
- **Save path**: `ucl/year1/comp0011/resources/exp-ln-graphs.png`
- **Embed in**: `ucl/year1/comp0011/cursor-notes/05-continuous-functions.md`, section "### Exponential & Logarithm"
- **Markdown snippet**: `![Graphs of exp and ln as mirror images across y=x](../resources/exp-ln-graphs.png)`
- **Alt text**: Graphs of the exponential and natural logarithm functions as reflections across y=x
- **Priority**: Medium

---

## 6. ivt-diagram

- **ID**: `ivt-diagram`
- **Image prompt**: A diagram illustrating the Intermediate Value Theorem. Draw a continuous curve y = f(x) from point (a, f(a)) to point (b, f(b)) where f(a) < f(b). Draw a horizontal dashed line at height y = t where f(a) < t < f(b). Mark the intersection point x where f(x) = t with a red dot. Label the points a, b on the x-axis and f(a), t, f(b) on the y-axis. The curve should be wavy (not monotone) to emphasise that the theorem doesn't require monotonicity, but must cross the line y = t. White background, clean mathematical style. No copyrighted material.
- **Filename**: `ivt-diagram.png`
- **Save path**: `ucl/year1/comp0011/resources/ivt-diagram.png`
- **Embed in**: `ucl/year1/comp0011/cursor-notes/05-continuous-functions.md`, section "## V. Intermediate Value Theorem (IVT)"
- **Markdown snippet**: `![IVT showing a horizontal line at y=t crossing the curve](../resources/ivt-diagram.png)`
- **Alt text**: Intermediate Value Theorem diagram showing a continuous function crossing a horizontal line y=t
- **Priority**: High

---

## 7. sequence-convergence

- **ID**: `sequence-convergence`
- **Image prompt**: A plot showing a converging sequence. The horizontal axis is labelled "n" (with integer ticks 1 through 10), vertical axis is unlabelled. Plot discrete points (dots) for a sequence like u_n = 1/n + (-1)^n/(2n) that oscillates while converging to 0. Draw two horizontal dashed lines at y = l + ε and y = l − ε (where l = 0), shaded lightly between them to form an "epsilon tube". Mark the limit l with a solid horizontal line. Show that after some rank N (marked on the x-axis with a vertical dashed line), all points lie within the tube. Label ε, l, and N. White background, clean mathematical style. No copyrighted material.
- **Filename**: `sequence-convergence.png`
- **Save path**: `ucl/year1/comp0011/resources/sequence-convergence.png`
- **Embed in**: `ucl/year1/comp0011/cursor-notes/06-sequences-and-series.md`, section "## II. Convergence"
- **Markdown snippet**: `![Sequence converging to limit l within epsilon tube](../resources/sequence-convergence.png)`
- **Alt text**: A converging sequence with points eventually contained within an epsilon tube around the limit
- **Priority**: High

---

## 8. stationary-points

- **ID**: `stationary-points`
- **Image prompt**: Three small side-by-side plots showing the three types of stationary points. Left plot: a smooth U-shaped curve with a red dot at the bottom labelled "Local minimum" and a flat tangent line. Middle plot: an inverted U-shaped curve with a red dot at the top labelled "Local maximum" and a flat tangent line. Right plot: an S-shaped curve (cubic-like) with a red dot at the inflection point labelled "Inflection point" and a flat tangent line. Each plot should show the tangent line as a dashed grey horizontal line. Use consistent axis scales. White background, clean mathematical style. No copyrighted material.
- **Filename**: `stationary-points.png`
- **Save path**: `ucl/year1/comp0011/resources/stationary-points.png`
- **Embed in**: `ucl/year1/comp0011/cursor-notes/07-differential-calculus.md`, section "### Second Derivative Test"
- **Markdown snippet**: `![Three types of stationary points: min, max, inflection](../resources/stationary-points.png)`
- **Alt text**: Three types of stationary points: local minimum, local maximum, and inflection point
- **Priority**: High

---

## 9. numerical-integration

- **ID**: `numerical-integration`
- **Image prompt**: Two side-by-side plots comparing numerical integration methods. Left plot: "Rectangle method" — show a smooth curve y = f(x) over [a,b] with 5 rectangles underneath (using left endpoints), coloured light blue with dark blue outlines. Right plot: "Trapezoid method" — same curve with 5 trapezoids underneath, coloured light green with dark green outlines. Both plots should show the curve in red. Label the x-axis with a and b. Title each subplot. White background, clean mathematical style. No copyrighted material.
- **Filename**: `numerical-integration.png`
- **Save path**: `ucl/year1/comp0011/resources/numerical-integration.png`
- **Embed in**: `ucl/year1/comp0011/cursor-notes/08-integral-calculus.md`, section "## VI. Numerical Methods"
- **Markdown snippet**: `![Rectangles vs trapezoids for numerical integration](../resources/numerical-integration.png)`
- **Alt text**: Comparison of rectangle and trapezoid methods for numerical integration
- **Priority**: Medium

---

## 10. binomial-distribution

- **ID**: `binomial-distribution`
- **Image prompt**: A bar chart showing the Binomial(10, 0.6) probability distribution. The x-axis shows values 0 through 10, the y-axis shows probability (as percentage, 0% to 30%). Each bar should be coloured blue with the probability value printed above it. The tallest bar should be at k=6 (~25.08%). Use a clean sans-serif font. White background, no grid lines, mathematical/statistical style. No copyrighted material.
- **Filename**: `binomial-distribution.png`
- **Save path**: `ucl/year1/comp0011/resources/binomial-distribution.png`
- **Embed in**: `ucl/year1/comp0011/cursor-notes/09-probabilities.md`, section "### Binomial(\(n, p\))"
- **Markdown snippet**: `![Binomial distribution bar chart for n=10, p=0.6](../resources/binomial-distribution.png)`
- **Alt text**: Bar chart of the Binomial distribution with n=10 and p=0.6
- **Priority**: Medium

---

## 11. normal-distribution

- **ID**: `normal-distribution`
- **Image prompt**: A diagram of the standard normal distribution (bell curve) with mean μ and standard deviation σ. Draw the smooth bell-shaped curve centred at μ. Mark and label μ on the x-axis. Show the distances σ, 2σ, 3σ on both sides of μ with small tick marks. Shade the region within ±1σ in dark blue (labelled "68%"), the region within ±2σ in medium blue (labelled "95%"), and the region within ±3σ in light blue (labelled "99.7%"). Label the y-axis "density". White background, clean statistical/mathematical style. No copyrighted material.
- **Filename**: `normal-distribution.png`
- **Save path**: `ucl/year1/comp0011/resources/normal-distribution.png`
- **Embed in**: `ucl/year1/comp0011/cursor-notes/09-probabilities.md`, section "## VI. The Normal Distribution"
- **Markdown snippet**: `![Normal distribution bell curve with mean and standard deviation marked](../resources/normal-distribution.png)`
- **Alt text**: Normal distribution bell curve showing 68-95-99.7 rule with mean and standard deviation
- **Priority**: High
