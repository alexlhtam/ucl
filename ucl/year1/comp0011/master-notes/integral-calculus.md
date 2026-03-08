# COMP0011: Integral Calculus Notes

## I. Introduction & Primitives
The integral represents a **continuous sum**, geometrically interpreted as the **area under a curve**.

### 1.1 Definition of a Primitive (Antiderivative)
If $f(x)$ is the derivative of $F(x)$, then $F(x)$ is called a **primitive** or **antiderivative** of $f(x)$.
*   **The Constant of Integration:** Since the derivative of a constant is zero, if $F$ is a primitive, then $F + c$ is also a primitive. 
*   **General form:** $\int f(x) dx = F(x) + c$.

### 1.2 Classic Primitives Table
| Function $f(x)$ | Primitive $F(x)$ |
| :--- | :--- |
| $a$ (constant) | $ax + c$ |
| $x$ | $\frac{1}{2}x^2 + c$ |
| $x^p$ ($p \neq -1$) | $\frac{1}{p+1}x^{p+1} + c$ |
| $1/x$ | $\ln(x) + c$ |
| $e^x$ | $e^x + c$ |
| $\cos(x)$ | $\sin(x) + c$ |
| $\sin(x)$ | $-\cos(x) + c$ |

---

## II. The Definite Integral
For a continuous function $f$ on $[a, b]$, the area under the graph is calculated as:
$$\int_{a}^{b} f(x) dx = F(b) - F(a) = [F(x)]_a^b$$

### 2.1 Fundamental Properties
1.  **Linearity:** $\int (f+g) = \int f + \int g$ and $\int (a \cdot f) = a \int f$.
2.  **Chasles' Relation:** $\int_a^b f(x)dx + \int_b^c f(x)dx = \int_a^c f(x)dx$.
3.  **Bound Symmetry:** $\int_a^b f(x)dx = -\int_b^a f(x)dx$.
4.  **Positivity:** If $f(x) \geq 0$ on $[a, b]$, then $\int_a^b f(x)dx \geq 0$.
5.  **Negative Area:** If the graph is below the $x$-axis, the integral yields a negative value.

---

## III. Advanced Integration Methods

### 3.1 Integration by Parts (IBP)
Derived from the product rule $(fg)' = f'g + fg'$.
$$\int_{a}^{b} f'(x)g(x)dx = [f(x)g(x)]_a^b - \int_{a}^{b} f(x)g'(x)dx$$
*   **Strategy:** Choose $g(x)$ to be a function that simplifies when derived (e.g., $x$ or $\ln(x)$) and $f'(x)$ to be a function you can easily integrate.

### 3.2 Integration by Substitution
Derived from the chain rule. It involves a "change of variable" $u = g(x)$.
$$\int_{a}^{b} f'(g(x)) \cdot g'(x)dx = \int_{u(a)}^{u(b)} f'(u)du = [f(u)]_{u(a)}^{u(b)}$$
*   **Crucial Step:** When changing the variable to $u$, you **must** update the bounds of the integral from $x$-values to $u$-values.

---

## IV. Numerical Methods
Used when the expression of a function is unknown or too complex to integrate analytically.

### 4.1 Rectangle & Trapezium Rules
*   **Rectangles (Riemann Sum):** Approximates area by summing $n$ rectangles. As $n \to \infty$, the sum converges to the exact integral.
    $$\lim_{n \to +\infty} \sum_{k=0}^{n-1} \frac{b-a}{n} f\left(a + k\frac{b-a}{n}\right) = \int_a^b f(x)dx$$
*   **Trapeziums:** Generally more precise as they follow the slope of the curve.

---

## V. Improper Integrals
Integrals with infinite bounds or functions that are not continuous on a closed interval.

### 5.1 Convergence near Infinity
Defined as a limit: $\int_a^{+\infty} f(x)dx = \lim_{t \to +\infty} \int_a^t f(x)dx$.
*   **Theorem (p-test near $\infty$):** $\int_a^{+\infty} \frac{1}{x^p}dx$ is **defined** if $p > 1$ and **undefined** (divergent) if $p \leq 1$.
    *   *Intuition:* Higher exponents flatten out fast enough to have a finite area.

### 5.2 Convergence near Zero
If $f$ is continuous on $(0, a]$ but not at $0$:
*   **Theorem (p-test near $0$):** $\int_0^a \frac{1}{x^p}dx$ is **defined** if $p < 1$ and **undefined** if $p \geq 1$.
    *   *Note:* $1/x$ is never integrable near $0$ or near $\infty$.

---

## VI. Series and Integrals
We can compare the divergence/convergence of a series to its integral counterpart.

### 6.1 The Integral Test
For a decreasing function $1/x$, the terms of the **Harmonic Series** $\sum \frac{1}{n}$ can be bounded by integrals:
$$\int_{n-1}^{n} \frac{1}{x} dx \geq \frac{1}{n} \geq \int_{n}^{n+1} \frac{1}{x} dx$$
Summing these leads to the conclusion that because the partial sums of the harmonic series tend to $\infty$, the integral $\int_1^\infty \frac{1}{x}dx$ must also diverge. **The behavior of series and integrals near $\infty$ is connected.**