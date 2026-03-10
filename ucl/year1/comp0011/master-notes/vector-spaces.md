# vector spaces

## core idea
- intuition: vectors can be added and scaled; linear algebra studies sets stable under these operations.
- formal: for a field $\mathbb K$, a non-empty set $V$ is a $\mathbb K$-vector space if
$$
\forall u,v\in V,\ \forall a\in\mathbb K:\quad u+v\in V,\ au\in V
$$
- example: $\mathbb R^n$ with componentwise operations
- zero vector is $0_V$ (a vector, not a scalar)

## combinations, span, subspaces
- linear combination:
$$
a_1u_1+\cdots+a_nu_n
$$
- span of $S=(u_1,\dots,u_n)$:
$$
\text{span}(S)=\{a_1u_1+\cdots+a_nu_n\}
$$
- colinear vectors: $u=\lambda v$
- subspace: subset stable under addition and scalar multiplication

## linear independence and basis
- intuition: independent vectors contain no redundancy.
- formal:
$$
a_1u_1+\cdots+a_nu_n=0 \Rightarrow a_1=\cdots=a_n=0
$$
- basis of $V$: family that is independent and spans $V$
- if basis is finite, its size is $\dim(V)$
- canonical basis of $\mathbb R^n$: $e_1,\dots,e_n$
- in $\mathbb R^2$, every vector writes uniquely as $xe_1+ye_2$

## linear maps
- intuition: linear maps preserve vector operations.
- formal: $f:V\to W$ is linear if
$$
f(u+av)=f(u)+af(v)
$$
- examples in $\mathbb R^2$: rotations, symmetries, scalings, projections
- if domain = codomain, map is an endomorphism
- composition of linear maps is linear

## kernel and image
$$
\ker(f)=\{v\in V:f(v)=0\},\qquad \text{Im}(f)=\{f(v):v\in V\}
$$
- $\ker(f)$ and $\text{Im}(f)$ are subspaces
- always $0\in\ker(f)$

## example
for
$$
g\!\left(\begin{bmatrix}x\\y\end{bmatrix}\right)=\begin{bmatrix}x+y\\x+y\end{bmatrix}
$$
- kernel:
$$
x+y=0 \Rightarrow \ker(g)=\text{span}\!\left(\begin{bmatrix}1\\-1\end{bmatrix}\right)
$$
- image:
$$
\text{Im}(g)=\left\{\begin{bmatrix}z\\z\end{bmatrix}:z\in\mathbb R\right\}
=\text{span}\!\left(\begin{bmatrix}1\\1\end{bmatrix}\right)
$$

## worked exam questions

### linear independence
- question: are $u_1=(1,2)$ and $u_2=(2,4)$ linearly independent in $\mathbb R^2$?
- formula used:
$$
a_1u_1+a_2u_2=0 \Rightarrow a_1=a_2=0 \text{ (for independence)}
$$
- working: $u_2=2u_1$, so take $a_1=2,\ a_2=-1$:
$$
2u_1-u_2=0
$$
non-trivial relation exists, so dependent.

### basis and coordinates
- question: show $S=\{(1,0),(0,1)\}$ is a basis of $\mathbb R^2$, and write $v=(-3,5)$ in this basis.
- formula used: basis = independent + spanning.
- working:
  - independent: $a(1,0)+b(0,1)=(0,0)\Rightarrow a=b=0$
  - spanning: any $(x,y)=x(1,0)+y(0,1)$
- result:
$$
(-3,5)=-3(1,0)+5(0,1)
$$

### kernel and image
- question: for $f(x,y)=(x-y,\ x-y)$, find $\ker(f)$ and $\text{Im}(f)$.
- formula used:
$$
\ker(f)=\{v:f(v)=0\},\qquad \text{Im}(f)=\{f(v)\}
$$
- working:
$$
f(x,y)=(0,0)\Rightarrow x-y=0 \Rightarrow x=y
$$
so
$$
\ker(f)=\text{span}\!\left(\begin{bmatrix}1\\1\end{bmatrix}\right)
$$
and outputs are $(t,t)$, so
$$
\text{Im}(f)=\text{span}\!\left(\begin{bmatrix}1\\1\end{bmatrix}\right)
$$
