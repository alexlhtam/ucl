# intro to functions
- intuition: a function assigns one output to each input.
- formal type: $f:\mathbb R\to\mathbb R$ (in many examples)
- notation example: $f(x)=x^2$
- graph: set of points $(x,f(x))$

# trig functions
## definitions via unit circle
- angle $\theta$: between horizontal axis and radius
- for point $A$ on unit circle:
  - the x-coordinate is $\cos(\theta)$
  - the y-coordinate is $\sin(\theta)$

## radians and classic values
- radians: angle measured by arc length on unit circle
- key values:
  -  $\cos(\frac{\pi}{3})=\frac{1}{2}$, $\sin(\frac{\pi}{3})=\frac{\sqrt{3}}{2}$
  - $\cos(\frac{\pi}{2})=0$, $\sin(\frac{\pi}{2})=1$
  - $\cos(\pi)=-1$, $\sin(\pi)=0$
  - $\cos(2\pi)=1$, $\sin(2\pi)=0$.

# exponential and logarithm

## exponential function $(e^x)$
- definition: $\exp(x+y)=\exp(x)\exp(y)$ and $\exp(0)=1$
- derivative property: it is the only function $f(x) = a^x$ equal to its own derivative
- $e\approx 2.71828$
- properties:
  - $e^x > 0$ for all $x$ (never equals $0$)
  - exhibits very fast growth

## logarithm function $(ln(x))$
- definition: the natural logarithm $\ln$ is the inverse of the exponential function
- inverse property: it verifies $\ln(e^x) = x$
- domain: defined only for $x > 0$
- algebraic properties:
  - $\ln(a \times b) = \ln(a) + \ln(b)$
  - $\ln(\frac{a}{b}) = \ln(a) - \ln(b)$
  - $\ln(1) = 0 \text{ and } \ln(e) = 1 $
- change of bases:
  - $a^x = e^{x\ln(a)}$

# limits and continuity
## limits
- intuition: as $x\to a$, $f(x)$ approaches $L$ (possibly infinite)
- notation: $\lim_{x\to a}f(x)=L$

## formal definitions:
1. infinite limit at infinity $(x \rightarrow \infty, f(x) \rightarrow \infty)$:
   - "for every number $d$, there exists a number $C$ such that $f(x) > d$ if $x > C$"
   - $\forall d > 0,\ \exists c > 0,\ x > c \Rightarrow f(x) > d$
2. infinite limit at a point $(x \rightarrow a, f(x) \rightarrow \infty)$:
   - "for any value $d$, $f(x)$ can be greater than $d$, as long as that $x$ is close enough to $a$"
   - $\forall d > 0,\ \exists \eta > 0,\ 0 < |x-a| < \eta \Rightarrow f(x) > d$

3. finite limit at a point $(x \rightarrow a, f(x) \rightarrow b)$:
   - $\forall \epsilon > 0,\ \exists \eta > 0,\ 0 < |x-a| < \eta \Rightarrow |f(x)-b| < \epsilon$

## rules and indeterminate
- combination: limits respect addition, multiplication and division (if denominator limit $\neq$ 0)
- useful rules: $a\times\infty=\infty$ and $a/\infty=0$ (for fixed $a$)
- indeterminate forms: cases where the limit is not immediately obvious

## asymptotic notation
- little o $(o): f = o(g)$ near $b$ means $f$ is negligible compared to $g$
  - definition $\lim_{x\rightarrow b}(\frac{f(x)}{g(x)}) = 0$
  - example $x = o(x^2)$ near $\infty$ because $1/x \rightarrow 0$
- big O $(O): f = O(g)$ near $b$ means $f$ is bounded by a multiple of $g$
  - definition: $|\frac{f(x)}{g(x)}|$ bounded near $b$ $(\exists M,\ |\frac{f(x)}{g(x)}|<M)$
  - example $3x = O(x+1)$ near $\infty$
- polynomials: if $\deg(P)=n$, then $P(x)=O(x^n)$ near $\pm\infty$

# continuity
- definition: $f$ continuous at $a$ if $\lim_{x\to a}f(x)=f(a)$
- visual: the graph is a single unbroken curve
- continuous functions: $\exp(x)$ and $\ln(x)$ are continuous on their domains
- algebra of continuity: if $f$ and $g$ are continuous, then $f + g , f - g, f \times g, f/g$ (where $g \neq 0$) and $f \circ g$ (composition) are continuous

# intermediate value theorem (IVT)
- theorem statement: assume $f$ is continuous on $[a, b]$ with $f(a) \neq f(b)$. for any value $t$ strictly between $f(a)$ and $f(b)$, there exists an $x$ such that $a < x < b$ and $f(x) = t$
  - this applies whether $f(a) < f(b) \text{ or } f(a) > f(b)$
- application example: used to prove roots exist
  - for $f(x)=x^3+x+1$, continuity plus sign change implies a root by IVT

## worked exam questions

### trig functions
- question: compute $\sin\!\left(\frac{\pi}{6}\right)$ and $\cos\!\left(\frac{\pi}{6}\right)$.
- formula used (unit circle values).
- result:
$$
\sin\!\left(\frac{\pi}{6}\right)=\frac12,\qquad \cos\!\left(\frac{\pi}{6}\right)=\frac{\sqrt3}{2}
$$

### exponential and logarithm
- question: solve $e^{2x+1}=7$.
- formula used:
$$
\ln(e^u)=u
$$
- working:
$$
2x+1=\ln 7 \Rightarrow x=\frac{\ln 7-1}{2}
$$

### limits
- question: compute $\lim_{x\to\infty}\frac{3x^2+1}{x^2-4}$.
- formula used: divide numerator and denominator by highest power $x^2$.
- working:
$$
\frac{3x^2+1}{x^2-4}
=\frac{3+\frac1{x^2}}{1-\frac4{x^2}}
\xrightarrow[x\to\infty]{}\frac{3+0}{1-0}=3
$$

### continuity
- question: is $f(x)=\frac{x^2-1}{x-1}$ continuous at $x=1$?
- formula used: continuity at $a$ requires $f(a)$ defined and $\lim_{x\to a}f(x)=f(a)$.
- working:
$$
f(x)=\frac{(x-1)(x+1)}{x-1}=x+1\quad (x\neq 1)
$$
but $f(1)$ is undefined, so not continuous at $1$ (removable hole).

### IVT
- question: prove $x^3+x+1=0$ has a real root.
- formula used (IVT): continuous + sign change on $[a,b]$ implies a root in $(a,b)$.
- working:
$$
f(x)=x^3+x+1,\quad f(-1)=-1,\quad f(0)=1
$$
$f$ is continuous, and $0$ lies between $-1$ and $1$, so $\exists c\in(-1,0)$ with $f(c)=0$.