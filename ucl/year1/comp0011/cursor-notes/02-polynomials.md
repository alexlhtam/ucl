# Polynomials

## I. Introduction

A **polynomial** \(P\) over a field \(\mathbb{K}\) (typically \(\mathbb{R}\) or \(\mathbb{C}\)) is an algebraic expression:

\[
P(X) = a_n X^n + a_{n-1}X^{n-1} + \cdots + a_1 X + a_0
\]

- **Coefficients**: \(a_i \in \mathbb{K}\)
- **Degree**: \(\deg(P) = n\) (highest power with nonzero coefficient)
- \(\mathbb{K}_n[X]\) denotes polynomials of degree \(\leq n\) with coefficients in \(\mathbb{K}\)

Polynomials are **algebraic objects**, not functions -- though we can evaluate them by substitution.

## II. Arithmetic

### Addition & Scalar Multiplication

Add corresponding coefficients. Scalar multiplication multiplies each coefficient. Hence \(\mathbb{K}[X]\) is a vector space.

**Degree rules**:

- \(\deg(P + Q) \leq \max(\deg P, \deg Q)\) (may be strict if leading terms cancel)
- \(\deg(P \cdot Q) = \deg P + \deg Q\)

### Euclidean Division

**Theorem**: For polynomials \(A, B\) with \(B \neq 0\), there exist unique \(Q, R\) such that:

\[
A = Q \cdot B + R, \quad \deg(R) < \deg(B)
\]

### Irreducible Polynomials

A polynomial is **irreducible** if it has no non-constant factors (analogous to prime numbers).

## III. Roots of Polynomials

A value \(a \in \mathbb{K}\) is a **root** of \(P\) if \(P(a) = 0\).

**Factor Theorem**: \(a\) is a root of \(P\) iff \((X - a)\) is a factor of \(P\):

\[
P = (X - a) \cdot Q, \quad \deg Q = \deg P - 1
\]

*Proof sketch*: Use Euclidean division by \((X-a)\); the remainder is a constant equal to \(P(a)\).

**Corollary**: A polynomial of degree \(m\) has **at most** \(m\) roots in \(\mathbb{K}\).

## IV. Degree 2 Polynomials

For \(P = aX^2 + bX + c\), the **discriminant** is:

\[
\Delta = b^2 - 4ac
\]

| Discriminant | Roots in \(\mathbb{R}\) | Factorisation |
|---|---|---|
| \(\Delta > 0\) | 2 distinct: \(\frac{-b \pm \sqrt{\Delta}}{2a}\) | \(a(X - r_1)(X - r_2)\) |
| \(\Delta = 0\) | 1 repeated: \(\frac{-b}{2a}\) | \(a(X - r)^2\) |
| \(\Delta < 0\) | 0 real roots (irreducible over \(\mathbb{R}\)) | Does not split over \(\mathbb{R}\) |

### Over \(\mathbb{C}\)

When \(\Delta < 0\), use \(\sqrt{\Delta} = i\sqrt{|\Delta|}\). Every degree 2 polynomial has 2 roots in \(\mathbb{C}\) (possibly equal), and they are **conjugate pairs**.

**Key identities**:

- \((X - r_1)(X - r_2) = X^2 - (r_1 + r_2)X + r_1 r_2\)
- Sum of roots: \(r_1 + r_2 = -b/a\)
- Product of roots: \(r_1 r_2 = c/a\)

## V. Polynomials of Degree \(n\)

### Factorisation over \(\mathbb{R}\)

Every polynomial of degree \(n > 0\) factors uniquely as:

\[
P = a \cdot (X - r_1) \cdots (X - r_m) \cdot Q_1 \cdots Q_k
\]

where each \(Q_j\) is irreducible of degree 2. So \(m + 2k = n\) and there are between 0 and \(n\) real roots.

### Factorisation over \(\mathbb{C}\)

Every polynomial of degree \(n > 0\) splits completely:

\[
P = a(X - \lambda_1)^{k_1}(X - \lambda_2)^{k_2} \cdots
\]

with exactly \(n\) roots (counted with **multiplicity** \(k_i\)).

### Key Remarks

- Over \(\mathbb{R}\), the only irreducible polynomials have degree 2
- Real polynomials of **odd degree** always have at least one real root
- \(X^4 + 1\) has no real roots but factors into two irreducible quadratics over \(\mathbb{R}\)

## Quick Tips

- If there's no constant term, then \(0\) is a root and \(X\) is a factor
- Easy expansion: \((a+b)^2 = a^2 + 2ab + b^2\), \((a-b)^2 = a^2 - 2ab + b^2\)
- Factoring \(\Leftrightarrow\) finding roots

## Exam Checklist

- [ ] Apply the discriminant formula for degree 2
- [ ] Use the Factor Theorem to factorise after finding a root
- [ ] Perform Euclidean division of polynomials
- [ ] Factorise over \(\mathbb{R}\) and \(\mathbb{C}\)
- [ ] Identify irreducible polynomials
- [ ] Work with multiplicity of roots
