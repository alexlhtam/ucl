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

## worked exam questions

### euclidean division
- question: divide $A(X)=2X^3+3X^2-X+5$ by $B(X)=X-1$.
- formula used:
$$
A=QB+R,\qquad \deg(R)<1 \Rightarrow R \text{ is constant}
$$
- working (synthetic division at $1$): coefficients $2,3,-1,5$
  - bring down $2$
  - $2\cdot 1=2$, add to $3$ gives $5$
  - $5\cdot 1=5$, add to $-1$ gives $4$
  - $4\cdot 1=4$, add to $5$ gives $9$
- result:
$$
Q(X)=2X^2+5X+4,\qquad R=9
$$

### roots and factors
- question: factor $P(X)=X^3-6X^2+11X-6$ over $\mathbb R$.
- formula used:
$$
a \text{ root } \iff (X-a)\text{ factor}
$$
- working:
$$
P(1)=1-6+11-6=0 \Rightarrow (X-1)\text{ factor}
$$
divide by $(X-1)$:
$$
P(X)=(X-1)(X^2-5X+6)
$$
then
$$
X^2-5X+6=(X-2)(X-3)
$$
- result:
$$
P(X)=(X-1)(X-2)(X-3)
$$

### quadratics and discriminant
- question: solve $2X^2-5X-3=0$.
- formula used:
$$
\Delta=b^2-4ac,\qquad x=\frac{-b\pm\sqrt\Delta}{2a}
$$
- working:
$$
a=2,\ b=-5,\ c=-3,\quad \Delta=25+24=49
$$
$$
x=\frac{5\pm 7}{4}\Rightarrow x_1=3,\ x_2=-\frac12
$$
- factorisation:
$$
2X^2-5X-3=2(X-3)\left(X+\frac12\right)=(2X+1)(X-3)
$$

### degree n picture / FTA
- question: state number of complex roots of $P(X)=X^5-1$.
- formula used (FTA):
$$
\deg(P)=n \Rightarrow \text{exactly } n \text{ complex roots counting multiplicity}
$$
- working: $\deg(P)=5$.
- result: $P$ has exactly $5$ complex roots (here all simple).
