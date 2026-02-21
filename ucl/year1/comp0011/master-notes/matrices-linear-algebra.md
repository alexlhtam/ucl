# COMP0011: Matrices & Linear Algebra Notes

## I. Introduction to Matrices
A matrix is a mathematical tool used to represent **linear maps** (transformations) between vector spaces.

### 1.1 Matrix-Vector Multiplication
For a $2 \times 2$ matrix multiplying a vector in $\mathbb{R}^2$:
$$\begin{bmatrix} a & b \\ c & d \end{bmatrix} \times \begin{bmatrix} x \\ y \end{bmatrix} = \begin{bmatrix} ax + by \\ cx + dy \end{bmatrix}$$

*   **Example (Vertical Symmetry):** $f\begin{pmatrix} x \\ y \end{pmatrix} = \begin{pmatrix} -x \\ y \end{pmatrix}$ is represented by $M = \begin{bmatrix} -1 & 0 \\ 0 & 1 \end{bmatrix}$.
*   **Example (Projection on $y$-axis):** $p_2\begin{pmatrix} x \\ y \end{pmatrix} = \begin{pmatrix} 0 \\ y \end{pmatrix}$ is represented by $M = \begin{bmatrix} 0 & 0 \\ 0 & 1 \end{bmatrix}$.

---

## II. Matrices and Linear Maps
Every linear map $f: W \to V$ corresponds to a matrix $M$. 

### 2.1 The Construction Rule
If $W$ has dimension $n$ and $V$ has dimension $m$, the matrix $M$ will have **$m$ rows and $n$ columns**.
*   **Rule:** Each column of the matrix is the **image of a basis vector** of $W$, expressed in the basis of $V$.
*   **Kernel and Image:** $\text{Ker}(M) = \text{Ker}(f)$ and $\text{Im}(M) = \text{Im}(f)$.

---

## III. Matrix Arithmetic
The set of matrices with $m$ rows and $n$ columns is denoted $\mathcal{M}_{m,n}(\mathbb{R})$.

### 3.1 Basic Operations
*   **Transpose ($M^T$):** The columns of $M$ become the rows of $M^T$. $(m_{ij})^T = m_{ji}$.
*   **Addition ($M + Q$):** Performed component-wise. Matrices must be the same size.
*   **Scalar Multiplication ($a * M$):** Every element is multiplied by the scalar $a$.

### 3.2 Matrix Multiplication
Two matrices $M$ and $Q$ can be multiplied if the **number of columns in $M$ equals the number of rows in $Q$**.
*   **Composition:** If $M$ represents $f$ and $Q$ represents $g$, then $M \times Q$ represents the composition $f \circ g$.
*   **Formula:** $l_{i,j} = \sum_{r=1}^n m_{i,r} * q_{r,j}$
*   **Properties:**
    *   **Associative:** $(A \times B) \times C = A \times (B \times C)$
    *   **NOT Commutative:** Generally, $M \times Q \neq Q \times M$.
    *   **Identity Matrix ($I$):** A square matrix with 1s on the diagonal and 0s elsewhere. $M \times I = M$.

---

## IV. Matrix Inversion
Only **square matrices** can be inverted. An inverse $M^{-1}$ satisfies: $M^{-1} \times M = M \times M^{-1} = I$.

### 4.1 Equivalent Properties for Invertibility
A square matrix $M$ is invertible if and only if:
1.  The columns of $M$ are linearly independent.
2.  The rows of $M$ are linearly independent.
3.  $\text{Ker}(M) = \{0\}$.
4.  $\det(M) \neq 0$.

---

## V. Linear Systems & Gaussian Elimination
A system of linear equations can be written as $A\mathbf{x} = \mathbf{b}$. If $A$ is invertible, then $\mathbf{x} = A^{-1}\mathbf{b}$.

### 5.1 Gaussian Elimination Algorithm
We use 3 basic row manipulations to transform a system into a **triangular shape**:
1.  Swapping two rows.
2.  Multiplying a row by a non-zero scalar.
3.  Adding a row to another row.

**Step 2 (Substitution):** Once the system is triangular, solve for the bottom variable and substitute upwards to find the others.

---

## VI. Determinants
The determinant $\det(A)$ is a scalar value that tells us if a matrix is invertible.

### 6.1 Calculation Rules
*   **Dimension 2:** $\det\begin{bmatrix} a & b \\ c & d \end{bmatrix} = ad - bc$
*   **Triangular Matrix:** The determinant is the product of the diagonal coefficients.
*   **Expansion by Cofactors:** Used for $n \times n$ matrices. Choose a row/column with many zeros to simplify.
    *   $C_{ij} = (-1)^{i+j} M_{ij}$ (where $M_{ij}$ is the minor determinant).

### 6.2 Properties of Determinants
*   $\det(M \times N) = \det(M) \times \det(N)$
*   $\det(M^T) = \det(M)$
*   $\det(M^{-1}) = \frac{1}{\det(M)}$
*   **Geometric Interpretation:** The absolute value $|\det(r_1, r_2, r_3)|$ represents the **volume** of the parallelepiped formed by the column vectors.