# matrices and linear algebra

## matrices as linear maps
- intuition: matrices are coordinate representations of linear maps.
- matrix-vector product in $\mathbb R^2$:
$$
\begin{bmatrix}a&b\\c&d\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix}
=\begin{bmatrix}ax+by\\cx+dy\end{bmatrix}
$$
- examples:
  - symmetry $(x,y)\mapsto(-x,y)$ has matrix $\begin{bmatrix}-1&0\\0&1\end{bmatrix}$
  - projection $(x,y)\mapsto(0,y)$ has matrix $\begin{bmatrix}0&0\\0&1\end{bmatrix}$

## building a matrix of a map
- for linear $f:W\to V$ with $\dim(W)=n$, $\dim(V)=m$, matrix is $m\times n$
- each column = image of a basis vector of $W$, written in basis of $V$
- kernel/image are preserved: $\ker(M)=\ker(f)$ and $\text{Im}(M)=\text{Im}(f)$

## matrix operations
- transpose: $(M^T)_{ij}=m_{ji}$
- addition and scalar multiplication are componentwise
- matrix product condition: if $M$ is $m\times n$ and $Q$ is $n\times p$, then $MQ$ exists
- entry formula:
$$
(MQ)_{ij}=\sum_{r=1}^n m_{ir}q_{rj}
$$
- properties: associative, generally non-commutative, identity matrix $I$

## inverse and invertibility
- for square $M$, inverse satisfies
$$
M^{-1}M=MM^{-1}=I
$$
- equivalent conditions:
  - columns linearly independent
  - rows linearly independent
  - $\ker(M)=\{0\}$
  - $\det(M)\neq 0$

## linear systems and elimination
- system form:
$$
A\mathbf x=\mathbf b
$$
- if $A$ invertible, unique solution:
$$
\mathbf x=A^{-1}\mathbf b
$$
- Gaussian elimination uses row operations:
  - swap rows
  - multiply row by non-zero scalar
  - add multiple of one row to another
- then solve by back-substitution

## determinants
- intuition: determinant tells scaling/orientation and invertibility.
- for $2\times2$:
$$
\det\!\begin{bmatrix}a&b\\c&d\end{bmatrix}=ad-bc
$$
- triangular matrix: determinant = product of diagonal terms
- key properties:
$$
\det(MN)=\det(M)\det(N),\quad \det(M^T)=\det(M),\quad \det(M^{-1})=\frac1{\det(M)}
$$
- geometric meaning: $|\det|$ gives area/volume scaling factor

## worked exam questions

### matrix multiplication
- question: compute
$$
\begin{bmatrix}1&2\\3&4\end{bmatrix}
\begin{bmatrix}2&0\\1&-1\end{bmatrix}
$$
- formula used:
$$
(MQ)_{ij}=\sum_r m_{ir}q_{rj}
$$
- working:
$$
\begin{bmatrix}
1\cdot2+2\cdot1 & 1\cdot0+2\cdot(-1)\\
3\cdot2+4\cdot1 & 3\cdot0+4\cdot(-1)
\end{bmatrix}
=
\begin{bmatrix}
4&-2\\
10&-4
\end{bmatrix}
$$

### inverse of a 2x2 matrix
- question: find inverse of $A=\begin{bmatrix}2&1\\5&3\end{bmatrix}$.
- formula used:
$$
A^{-1}=\frac1{ad-bc}\begin{bmatrix}d&-b\\-c&a\end{bmatrix}
$$
- working:
$$
\det(A)=2\cdot3-1\cdot5=1\neq0
$$
so
$$
A^{-1}=\begin{bmatrix}3&-1\\-5&2\end{bmatrix}
$$

### linear system
- question: solve
$$
\begin{cases}
x+y=3\\
2x-y=0
\end{cases}
$$
- formula used: Gaussian elimination/back-substitution.
- working: add equations:
$$
3x=3\Rightarrow x=1,\quad y=2
$$
- result: $(x,y)=(1,2)$.

### determinant and invertibility
- question: decide if $B=\begin{bmatrix}1&2\\2&4\end{bmatrix}$ is invertible.
- formula used:
$$
\det(B)\neq 0 \iff B \text{ invertible}
$$
- working:
$$
\det(B)=1\cdot4-2\cdot2=0
$$
- result: $B$ is not invertible.