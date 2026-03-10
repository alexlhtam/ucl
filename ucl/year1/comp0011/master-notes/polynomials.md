# polynomials

## definitions and notation
- intuition: a polynomial is a finite sum of powers of $X$ with coefficients.
- formal:
$$
P(X)=a_0+a_1X+\cdots+a_nX^n,\quad a_i\in\mathbb K
$$
- intuition: degree = highest power that actually appears.
- formal:
$$
\deg(P)=n \text{ if } a_n\neq 0
$$
- constants have degree $0$; degree $1$ polynomials are linear
- notation: $\mathbb K[X]$ = all polynomials, $\mathbb K_n[X]$ = degree $\le n$

## arithmetic
- intuition: same algebra rules as usual expressions.
- formal degree rules:
$$
\deg(P+Q)\le \max(\deg(P),\deg(Q)),\qquad \deg(PQ)=\deg(P)+\deg(Q)
$$
- in $P+Q$, strict inequality can happen if leading terms cancel
- $P=AB$: $A,B$ are factors of $P$
- irreducible: no non-constant factorisation

## euclidean division
- intuition: same pattern as integer division (quotient + remainder).
- formal: for $A,B\in\mathbb K[X]$, $B\neq 0$, unique $Q,R$ exist with
$$
A=QB+R,\qquad \deg(R)<\deg(B)
$$
- $Q$: quotient, $R$: remainder
- dividing by $(X-a)$ gives remainder $P(a)$ (remainder theorem)

## roots and factors
- intuition: roots and linear factors are the same information.
- formal:
$$
a \text{ root of } P \iff (X-a)\text{ divides }P
$$
- so if $\deg(P)=m>0$ and $a$ is a root:
$$
P(X)=(X-a)Q(X),\qquad \deg(Q)=m-1
$$
- finding roots $\Leftrightarrow$ factoring
- if $\deg(P)=m$, then at most $m$ roots in $\mathbb K$

## degree 2 (quadratics)
- intuition: the discriminant tells how many real roots you get.
- formal form: $P(X)=aX^2+bX+c,\ a\neq 0$
- discriminant:
$$
\Delta=b^2-4ac
$$
- quadratic formula:
$$
x=\frac{-b\pm \sqrt{\Delta}}{2a}
$$
- over $\mathbb R$:
  - $\Delta>0$: 2 distinct real roots
  - $\Delta=0$: 1 repeated real root
  - $\Delta<0$: no real root (irreducible over $\mathbb R$)
- over $\mathbb C$: always 2 roots (counting multiplicity)

## degree n picture
- intuition: degree controls how many roots/factors are possible.
- over $\mathbb R$: factorisation into linear and irreducible quadratic factors
- over $\mathbb C$ (fundamental theorem of algebra):
$$
P(X)=a\prod_{j=1}^n (X-\lambda_j),\qquad \lambda_j\in\mathbb C
$$
- meaning of FTA: every non-constant polynomial has a complex root, so it splits into linear factors in $\mathbb C$
- if $\deg(P)=n$, there are exactly $n$ complex roots counting multiplicity
- over $\mathbb R$, the number of real roots is between $0$ and $n$
- multiplicity: if
$$
P(X)=(X-\lambda)^kQ(X),\quad Q(\lambda)\neq 0
$$
  then $k$ is the multiplicity of $\lambda$

## quick identities
$$
(X-\alpha)(X-\beta)=X^2-(\alpha+\beta)X+\alpha\beta
$$
for $aX^2+bX+c$ with roots $r_1,r_2$:
$$
r_1+r_2=-\frac{b}{a},\qquad r_1r_2=\frac{c}{a}
$$
- if constant term is $0$, then $0$ is a root (so $X$ is a factor)
