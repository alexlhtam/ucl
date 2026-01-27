# intro
- notion of linearity:
  - picture vectors as arrows
  - they can be added together
  - they can be multiplied by a number
  - strictly speaking vectors cannot multiplied together

# linearity
- definition:
  - for $K$ a field (typically $\R$ or $\mathbb{C}$), $V$ is a $K$-vector space if $V$ is non-empty and:
$$ \forall u, v \in V, a \in K$$
- $u + v \in V$: vector addition
- $a \times u \in V$: scalar multiplication
<br>
- examples: consider the set of pairs of real numbers, written vertically
$$ \begin{bmatrix} 2 \\ 5 \end{bmatrix} \qquad \begin{bmatrix} -1 \\ 8 \end{bmatrix}$$
- they can be added together: $$ \begin{bmatrix} 2 \\ 5 \end{bmatrix} + \begin{bmatrix} -1 \\ 8 \end{bmatrix} = \begin{bmatrix} 1 \\ 13 \end{bmatrix}$$
- they can be multiplied by a real number: $$ 3 \times \begin{bmatrix} 2 \\ 5 \end{bmatrix} = \begin{bmatrix} 6 \\ 15 \end{bmatrix}$$
- it is easy to show that all the rules are verified: this is a vector space
- remark: the zero vector is $$\begin{bmatrix} 0 \\ 0 \end{bmatrix}$$
  - we sometimes write it as ${0}$, but it is still a vector. It is not the same as a scalar $0$.

<br>

- if $u = a \times v$, $u$ and $v$ are said to be colinear
- for $u, v$ vectors and $a, b$ scalars, $a \times u + b \times v$ is called a linear combination
- for a family of vectors $S = (u_1, u_2, \dots, u_n)$, the span of $S$, is the set of all linear combinations of $u_1, u_2, \dots, u_n$
- if $V$ is a vector space and $U$ is a subset of $V$, then $U$ is a subspace if it is stable under linearity (same operators as $V$). 
  - in this case, $U$ is a vector space

# vectors of real numbers
- we've seen before that pairs of real numbers form a vector space
- more generally, $\R^n$ is a vector space for any $n \in \N$
- a vector of $\R^n$ is written as:
$$ u = \begin{bmatrix} u_1 \\ u_2 \\ \vdots \\ u_n \end{bmatrix} $$
- also an $n$-tuple of real numbers

<br>

- special case: $\R^2$
- seen before as a set of pairs
- geometric interpretation: set of vectors in the 2D plane

<br>

- special case: $\R^3$
- vectors in the 3D space
- consider 2 non-colinear vectors $u$, $w$ in the horizontal plance
- intuitively we can see that all linear combinations of them remain int his plane. The span of $(u, w)$ is the horizontal plane
- there is no combination of them that can be equal to $v$

# linear independence
- let $u_1, u_2, \dots, u_n$ be vectors:
  - they are linearly independent if there exist no scalars $a_1, \dots, a_n$ (not all equal to 0) such that: 
$$ a_1 \times u_1 + \dots + a_n \times u_n = 0 $$
- equivalent definition: there is no vector in $u_1, \dots, u_n$ which can be expressed as a linear combination of the others
<br>
## basis
- let $A$ be a vector space. $S = (u_1, u_2, \dots)$ is called a basis of $A$ if:
  - $\text{span}(S) = A$
  - $u_1, u_2, \dots$ are linearly independent
  - if $S$ is finite, its size is called the dimension of $A$
  - in $\R^n$ a basis is:
- $$\begin{bmatrix}1 \\ 0 \\ 0 \\ \vdots \\ 0 \end{bmatrix}, 
    \begin{bmatrix}0 \\ 1 \\ 0 \\ \vdots \\ 0 \end{bmatrix},
    \begin{bmatrix}0 \\ 0 \\ 1 \\ \vdots \\ 0 \end{bmatrix}, 
    \dots,
    \begin{bmatrix}0 \\ 0 \\ 0 \\ \vdots \\ 1 \end{bmatrix}
$$
- it is called the canonical basis

## examples:
- a basis of $\R^2$ is $$ (
    \begin{bmatrix}1 \\ 0 \end{bmatrix},
    \begin{bmatrix}0 \\ 1 \end{bmatrix}
) $$
- they are linearly independent, and any vector can be expressed using these 2.
- for instance;
$$ 
v = 
\begin{bmatrix} -5 \\ 3 \end{bmatrix} = 
{-5} \times \begin{bmatrix} 1 \\ 0 \end{bmatrix}
{+ 3} \times \begin{bmatrix} 0 \\ 1 \end{bmatrix}
$$

# linear mappings
- transformations which preserve the structure of vector spaces:
  - linear mapping:
    - for $K$-vector spaces $V, W$ a mapping $f: V \rightarrow W$ is a linear mapping if:
$$ \forall u, v \in V, \forall a \in K, f(u + a \times v) = f(u) + a \times f(v)$$
- examples of linear mappings in $\R^2$:
  - symmetry
  - rotations
  - scaling
  - projections
- a linear map $f: V \rightarrow V$ is called an endomorphism
<br>
- let $U, V, W$ be vector spaces, $f: U \rightarrow V$ and $g: V \rightarrow W$ be linear mappings
  - $f$ and $g$ can be composed into a linear mapping $g \circ f : U \rightarrow W$
<br>
- let $V, W$ be vector spaces, $f: V \rightarrow W$ a linear mapping. We define:
  - the kernel of $f$, denoted by $\text{Ker}(f)$, is the set of $v \in V, f(v) = 0$
  - the image of $f$, denoted by $\text{Im}(f)$, is the set of $f(v), v \in V$
  - $\text{Ker}(f)$ and $\text{Im}(f)$ are both vector spaces. Note that 
  - $\text{Ker}(f)$ always contains $0$ (because we always have $f(0) = 0$)

## example
let us calculate the $\text{Ker}$ and $\text{Im}$ of the following linear map:
$$ g(\begin{bmatrix} x \\ y \end{bmatrix}) = \begin{bmatrix} x + y \\ x + y \end{bmatrix}$$
- to find $\text{Ker}(g)$ we solve $g(u) = 0$:
$$ \begin{bmatrix} x + y \\ x + y \end{bmatrix} = \begin{bmatrix} 0 \\ 0 \end{bmatrix} \implies x = -y, \quad \text{Ker}(g) = \set{\begin{bmatrix}x \\ -x\end{bmatrix}, x \in \R} = \text{span}(\begin{bmatrix}1 \\ -1\end{bmatrix})$$
- to find $\text{Im}(g)$ we find which vectors are in the image of $g$, or. in other words: which vectors $v$ verify $g(u) = v$ for a certain $u$
$$ v = g(u) \iff \exists x, y, \quad v = \begin{bmatrix} x + y \\ x + y\end{bmatrix} \implies \exists z, \quad v = \begin{bmatrix} z \\ z\end{bmatrix}, \qquad \text{Im}(g) = \text{span}(\begin{bmatrix}1 \\ 1\end{bmatrix})$$