# integral calculus

## primitives (antiderivatives)
- intuition: integrating reverses differentiation.
- formal:
$$
F'=f \quad \Longleftrightarrow \quad \int f(x)\,dx=F(x)+C
$$
- common primitives:
$$
\int x^p\,dx=\frac{x^{p+1}}{p+1}+C\ (p\neq -1),\quad \int \frac1x\,dx=\ln x + C
$$
$$
\int e^x\,dx=e^x+C,\quad \int \cos x\,dx=\sin x + C,\quad \int \sin x\,dx=-\cos x + C
$$

## definite integrals
- intuition: signed area under the curve on $[a,b]$.
- fundamental theorem:
$$
\int_a^b f(x)\,dx=F(b)-F(a)=[F(x)]_a^b
$$
- key properties: linearity, additivity on intervals, sign change when swapping bounds
$$
\int_a^b f = -\int_b^a f,\qquad \int_a^c f = \int_a^b f + \int_b^c f
$$

## integration methods
- integration by parts:
$$
\int_a^b f'(x)g(x)\,dx=[f(x)g(x)]_a^b-\int_a^b f(x)g'(x)\,dx
$$
- substitution ($u=g(x)$):
$$
\int_a^b f'(g(x))g'(x)\,dx=\int_{u(a)}^{u(b)} f'(u)\,du
$$
- always change bounds when you change variable

## numerical integration
- intuition: approximate area by simple shapes.
- Riemann sum:
$$
\lim_{n\to\infty}\sum_{k=0}^{n-1}\frac{b-a}{n}\,f\!\left(a+k\frac{b-a}{n}\right)=\int_a^b f(x)\,dx
$$
- trapezium rule is usually more accurate than rectangles

## improper integrals and p-tests
- define by limits, e.g.
$$
\int_a^{+\infty}f(x)\,dx=\lim_{t\to+\infty}\int_a^t f(x)\,dx
$$
- near $\infty$:
$$
\int_a^{+\infty}\frac1{x^p}\,dx \text{ converges } \iff p>1
$$
- near $0$:
$$
\int_0^a\frac1{x^p}\,dx \text{ converges } \iff p<1
$$

## link with series
- integral test compares $\sum a_n$ with $\int f(x)\,dx$ when $a_n=f(n)$ and $f$ is positive/decreasing
- classic comparison:
$$
\int_{n-1}^{n}\frac1x\,dx \ge \frac1n \ge \int_n^{n+1}\frac1x\,dx
$$
- used to show harmonic series and $\int_1^\infty \frac1x\,dx$ both diverge

## worked exam questions

### primitives
- question: compute $\int (3x^2-4e^x)\,dx$.
- formula used: linearity of the integral + basic primitives.
- working:
$$
\int (3x^2-4e^x)\,dx=\int 3x^2\,dx-4\int e^x\,dx=x^3-4e^x+C
$$

### definite integral
- question: compute $\int_0^2 (x^2+1)\,dx$.
- formula used:
$$
\int_a^b f(x)\,dx=F(b)-F(a)
$$
- working:
$$
F(x)=\frac{x^3}{3}+x,\quad \int_0^2 (x^2+1)\,dx=\left[\frac{x^3}{3}+x\right]_0^2=\frac{8}{3}+2=\frac{14}{3}
$$

### integration by parts
- question: compute $\int_0^1 xe^x\,dx$.
- formula used:
$$
\int u\,dv=uv-\int v\,du
$$
- working: choose $u=x$, $dv=e^x dx$, so $du=dx$, $v=e^x$:
$$
\int_0^1 xe^x\,dx=\left[xe^x\right]_0^1-\int_0^1 e^x\,dx
=e-(e-1)=1
$$

### substitution
- question: compute $\int_0^1 2x\cos(x^2)\,dx$.
- formula used: $u=x^2$, $du=2x\,dx$.
- working:
$$
\int_0^1 2x\cos(x^2)\,dx=\int_0^1 \cos(u)\,du=[\sin u]_0^1=\sin(1)
$$

### improper integral / p-test
- question: decide convergence of $\int_1^{\infty}\frac1{x^2}\,dx$.
- formula used:
$$
\int_a^\infty \frac1{x^p}\,dx \text{ converges } \iff p>1
$$
- working: $p=2>1$, so convergent.
$$
\int_1^\infty \frac1{x^2}\,dx=\lim_{t\to\infty}\left[-\frac1x\right]_1^t=1
$$