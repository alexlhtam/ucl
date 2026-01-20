# intro to functions
- definition: a function is a mapping of elements from on set (domain) to elements of another set (codomain)
- type: most functions map real numbers to real numbers, denoted as $\R \rightarrow \R$
- notation: a function is often written as $f: \R \rightarrow \R$ where $x \rightarrowtail x^2$
- graphical representation: the graph of a function is the set of points $(x, y)$ such that $y = f(x)$

# trig functions
## definitions via unit circle
- consider a unit circle with radius 1;
- angle $(\theta)$: the angle between the horizontal axis and the radius segment $OA$
- coordinates: for a point $A$ on the circle defined by angle $\theta$
  - the x-coordinate is $\cos(\theta)$
  - the y-coordinate is $\sin(\theta)$

## radians and classic values
- radians $\theta$ is measured as the length of the arc on the unit circle
- key values:
  -  $\cos(\frac{\pi}{3})=\frac{1}{2}$, $\sin(\frac{\pi}{3})=\frac{\sqrt{3}}{2}$
  - $\cos(\frac{\pi}{2})=0$, $\sin(\frac{\pi}{2})=1$
  - $\cos(\pi)=-1$, $\sin(\pi)=0$
  - $\cos(2\pi)=1$, $\sin(2\pi)=0$.

# exponential and logarithm

## exponential function $(e^x)$
- definition: the function $\exp(x)$ verifies $\exp(x+y) = \exp(x) \times \exp(y)$ and $\exp(0) = 1$
- derivative property: it is the only function $f(x) = a^x$ equal to its own derivative
- the constant $e$: a specific real number where $e \approx 2.71828 \dots$
- properties:
  - $e^x > 0$ for all $x$ (never equals $0$)
  - exhibits very fast growth

## logarithm function $(ln(x))$
- definition: the natural logarithm $\ln$ is the inverse of the exponential function
- inverse property: it verifies $\ln(e^x) = x$
- domain: defined only for $x > 0$
- algebraic properties:
  - $\ln(a \times b) = \ln(a) + \ln(b)$
  - $\ln(\frac{a}{b}) = ln(a) - ln(b)$
  - $\ln(1) = 0 \text{ and } \ln(e) = 1 $
- change of bases:
  - any exponent can be written using exponentials $a^x = e^{x \times \ln(a)}$

# limits and continuity
## limits
- intuitively as $x$, approaches a value, $f(x)$ approaches a value $l$ (possibly infinite); notation: $lim_{x \rightarrow a} f(x) = l$

## formal definitions:
1. infinite limit at infinity $(x \rightarrow \infty, f(x) \rightarrow \infty)$:
   - "for every number $d$, there exists a number $C$ such that $f(x) > d$ if $x > C$"
   - $\forall d > 0, \exists c > 0, x > c \implies  f(x) \rightarrow d$
2. infinite limit at a point $(x \rightarrow a, f(x) \rightarrow \infty)$:
   - "for any value $d$, $f(x)$ can be greater than $d$, as long as that $x$ is close enough to $a$"
   - $\forall d > 0 , \exists \eta > 0, 0 < |x - a| < \eta \implies f(x) > d$

3. finite limit at a point $(x \rightarrow a, f(x) \rightarrow b)$:
   - $\forall \epsilon > 0, \exists \eta > 0, 0 < |x - a| < \eta \implies |f(x) - b| < \epsilon$

## rules and indeterminate
- combination: limits respect addition, multiplication and division (if denominator limit $\neq$ 0)
- infinites: $ a \times \infty = \infty$ and $a /\infty = 0$
- indeterminate forms: cases where the limit is not immediately obvious

## asymptotic notation
- little o $(o): f = o(g)$ near $b$ means $f$ is negligible compared to $g$
  - definition $\lim_{x\rightarrow b}(\frac{f(x)}{g(x)}) = 0$
  - example $x = o(x^2)$ near $\infty$ because $1/x \rightarrow 0$
- big O $(0): f = O(g)$ near $b$ means $f$ and $g$ have similar growth/magnitude
  - definition: the ration $|\frac{f(x)}{g(x)}|$ is bounded near $b (\exists M \in \R, |\frac{f(x)}{g(x)}| < M)$.
  - example $3x = O(x+1)$ near $\infty$
- polynomials: for a polynomial of degree $n, P(x) = O(x^n)$ near $\plusmn \infty$

# continuity
- definition: a function is continuous at $a \text{ if } \lim_{x \rightarrow b} f(x) = f(a)$
- visual: the graph is a single unbroken curve
- continuous functions: $\exp(x)$ and $\ln(x)$ are continuous on their domains
- algebra of continuity: if $f$ and $g$ are continuous, then $f + g , f - g, f \times g, f/g$ (where $g \neq 0$) and $f \circ g$ (composition) are continuous

# intermediate value theorem (IVT)
- theorem statement: assume $f$ is continuous on $[a, b]$ with $f(a) \neq f(b)$. for any value $t$ strictly between $f(a)$ and $f(b)$, there exists an $x$ such that $a < x < b$ and $f(x) = t$
  - this applies whether $f(a) < f(b) \text{ or } f(a) > f(b)$
- application example: used to prove roots exist
  - to prove $x^3 + x + 1 = 0$ has a solution: definite $f(x) = x^3 + x + 1$. limits at $\plusmn \infty$ show the functions spans from $-\infty$ to $+\infty$. by IVT, it must cross 0