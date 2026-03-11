# sequences and series

## formula checklist
- $\epsilon$-$N$ convergence:
$$
|a_n-L|<\epsilon
$$
- monotone convergence theorem:
$$
\text{monotone}+\text{bounded}\Rightarrow\text{convergent}
$$
- little-o:
$$
f(n)=o(g(n)) \iff \lim_{n\to\infty}\frac{f(n)}{g(n)}=0
$$
- arithmetic sequence:
$$
u_n=u_1+(n-1)d,\qquad
S_n=\frac n2(u_1+u_n)=\frac n2\big(2u_1+(n-1)d\big)
$$
- geometric sequence:
$$
u_n=u_1r^{n-1},\qquad
\sum_{k=0}^{n-1}ar^k=a\frac{1-r^n}{1-r}\ (r\neq1)
$$
- geometric infinite series:
$$
\sum_{n=0}^\infty ar^n \text{ converges } \iff |r|<1,\qquad
S_\infty=\frac{a}{1-r}
$$
- divergence test:
$$
\lim_{n\to\infty}a_n\neq0 \Rightarrow \sum a_n \text{ diverges}
$$
- telescoping:
$$
\sum_{k=1}^{n}\big(f(k+1)-f(k)\big)=f(n+1)-f(1)
$$

## sequence limits
- intuition: $a_n \to L$ means terms get arbitrarily close to $L$ for large $n$.
- formal ($\epsilon$-$N$):
$$
\forall \epsilon>0,\ \exists N\in\mathbb N,\ n>N \Rightarrow |a_n-L|<\epsilon
$$
- proof pattern: start from $|a_n-L|<\epsilon$, isolate $n$, choose $N$.

### worked exam question
- question: prove with $\epsilon$-$N$ that $a_n=\frac{3n+1}{n+2}\to 3$.
- working:
$$
\left|\frac{3n+1}{n+2}-3\right|=\left|\frac{-5}{n+2}\right|=\frac{5}{n+2}
$$
want $\frac{5}{n+2}<\epsilon \iff n>\frac{5}{\epsilon}-2$.
choose
$$
N=\left\lceil \frac{5}{\epsilon}-2\right\rceil
$$
then $n>N \Rightarrow |a_n-3|<\epsilon$, so $a_n\to 3$.

## monotonicity and boundedness
- increasing: $a_{n+1}\ge a_n$; decreasing: $a_{n+1}\le a_n$
- bounded above: $\exists M,\ a_n\le M$; bounded below: $\exists m,\ a_n\ge m$
- monotone convergence theorem: monotone + bounded $\Rightarrow$ convergent

### worked exam question
- question: show $u_n=1-\frac1n$ converges, and find the limit.
- working:
$$
u_{n+1}-u_n=\left(1-\frac1{n+1}\right)-\left(1-\frac1n\right)=\frac1n-\frac1{n+1}>0
$$
so $(u_n)$ is increasing.
also $u_n<1$ for all $n$, so it is bounded above.
by MCT, $(u_n)$ converges; since $\frac1n\to0$, limit is $1$.

## little-o notation
- intuition: $f=o(g)$ means $f$ is negligible compared to $g$.
- formal:
$$
f(n)=o(g(n)) \iff \lim_{n\to\infty}\frac{f(n)}{g(n)}=0
$$

### worked exam question
- question: prove $n=o(n^2)$ as $n\to\infty$.
- working:
$$
\frac{n}{n^2}=\frac1n\to0
$$
hence $n=o(n^2)$.

## arithmetic and geometric sequences
- arithmetic sequence (difference $d$):
$$
u_n=u_1+(n-1)d,\qquad S_n=\frac n2(u_1+u_n)=\frac n2\left(2u_1+(n-1)d\right)
$$
- geometric sequence (ratio $r$):
$$
u_n=u_1r^{n-1},\qquad \sum_{k=0}^{n-1}ar^k=a\frac{1-r^n}{1-r}\ (r\neq 1)
$$

### worked exam questions
- question 1 (arithmetic): $u_1=4,\ d=3$. Find $u_{10}$ and $\sum_{n=1}^{10}u_n$.
- working:
$$
u_{10}=4+9\cdot3=31,\qquad S_{10}=\frac{10}{2}(4+31)=175
$$
- question 2 (geometric): $u_1=2,\ r=\frac12$. Find $u_6$ and $\sum_{n=1}^{6}u_n$.
- working:
$$
u_6=2\left(\frac12\right)^5=\frac1{16}
$$
$$
S_6=2\cdot\frac{1-(1/2)^6}{1-1/2}=\frac{63}{16}
$$

## infinite series
- intuition: $\sum a_n$ converges if partial sums $S_N=\sum_{n=1}^N a_n$ converge.
- divergence test: if $\lim a_n\neq 0$, then $\sum a_n$ diverges.
- geometric series:
$$
\sum_{n=0}^\infty ar^n \text{ converges } \iff |r|<1,\qquad S_\infty=\frac{a}{1-r}
$$

### worked exam questions
- question 1: does $\sum_{n=1}^\infty \frac{n+1}{n}$ converge?
- working:
$$
\frac{n+1}{n}=1+\frac1n \to 1\neq 0
$$
terms do not go to $0$, so series diverges.
- question 2: compute $\sum_{n=0}^\infty 3\left(\frac14\right)^n$.
- working: geometric with $a=3$, $r=\frac14$, $|r|<1$:
$$
S_\infty=\frac{3}{1-\frac14}=4
$$

## useful inequalities and tools
- logarithm inequality ($x\ge 0$):
$$
x\ge \ln(1+x)
$$
- telescoping:
$$
\sum_{k=1}^n\big(f(k+1)-f(k)\big)=f(n+1)-f(1)
$$
- classic example:
$$
\sum_{k=1}^n\ln\!\left(\frac{k+1}{k}\right)=\sum_{k=1}^n\big(\ln(k+1)-\ln(k)\big)
$$
- growth hierarchy:
$$
\ln n \ll n^k \ll a^n \ll n! \ll n^n
$$

### worked exam questions
- question 1 (telescoping): compute
$$
\sum_{k=1}^n \ln\!\left(\frac{k+1}{k}\right)
$$
- working:
$$
\sum_{k=1}^n(\ln(k+1)-\ln k)=\ln(n+1)-\ln 1=\ln(n+1)
$$
- question 2 (growth): evaluate $\lim_{n\to\infty}\frac{2^n}{n!}$.
- working: from $a^n\ll n!$, ratio tends to $0$:
$$
\lim_{n\to\infty}\frac{2^n}{n!}=0
$$