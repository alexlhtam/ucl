# intro
- study of infinitesimal variation

# differentiation of univariate functions
- consider a continuous function $f$ and $2$ values, $a, h$ such that $a$ and $a+h$ are in the domain of $f$
- we can study the variations of $f$ between $a$ and $a + h$
- the ratio below informs us about the variation / slope of the tangent
$$
\frac{f(a+h)-f(a)}{(a+h)-a} = \frac{f(a+h) - f(a)}{h}
$$
- to study the variations close to $a$, we make $h$ tend to 0
- if the quotient $\frac{f(a+h) - f(a)}{h}$ has a limit when $h$ tends to 0, this limit is called the derivative of $f$ in $a$ and denoted $f'(a)$
- $f$ is said to be differentiable in $a$
- we do not require $f$ to be continuous, only that this limit exists
- $f'(a)$ is the slope of the tangent to the graph of $f$ in $a$
- for a differentiable function, we denote $f'$ by $\frac{df}{dx}$, or sometimes by $f^{(1)}$
    - this is not a quotient!
- if $F' = f$, $F$ is called the primitive, or antiderivative of $f$
- if we derivate twice, we obtain the second order derivative
- it is denoted by $\frac{d^2f}{dx^2}$ or $f^{(2)}$


> one important result: if $f$ is differentiable in $c$, then $f$ is continuous in $c$
- differentiability is stronger than continuity
- angular points indicate non-differentiability
- differentiable functions are smoother

- if $f' > 0$ on an interval $I$ then $f$ is increasing on this interval
- if $f' < 0$ on an interval $I$ then $f$ is decreasing on this interval

> theorem: L'Hopital Rule
Consider functions $f, g$ differentiable on an interval containing $c$ (not necessarily differentiable at $c$ itself)
if we have $g(x) \neq 0$ near $c$
and $\lim_{x \to c} f(x) = \lim_{x \to c} g(x) = 0$ or 
$\lim_{x \to c} f(x) = \lim_{x \to c} g(x) = \infty$
then: $$\lim_{x \to c} \frac{f(x)}{g(x)} = \lim_{x \to c} \frac{f'(x)}{g'(x)}$$


> theorem: mean value theorem
Consider a continuous function $f$ defined on an interval $[a, b]$, differentiable on $[a, b]$
then there exists $c \in [a,b]$ such that $f'(c) = \frac{f(a)-f(b)}{a-b}$

# stationary points
- $f'(x) = 0$ means a flat tangent, which can mean:
    - local minimum
    - local maximum
    - inflection point

# diff equations
- example: $f'(x) = -3f(x)$
    - solutions: all functions $f(x) = C \times e^{-3x}, \quad C \in \R$

- slightly harder: first order homogeneous linear diff eqs
$$ f'(x) = a(x) \times f(x)$$
    - recall that: $$ \frac{d}{dx}(c \times e^{g(x)}) = g'(x) \times c \times e^{g(x)}$$
    - the solutions are all functions $f(x) = C \times e ^ {A(x)}$, for $C \in \R$ and $A$ a primitive of $a$.

- these solutions are called general solutions of the considered differential equation
- they contain multiplicative constants, which we keep general
we will sometimes have to find the value of these constants for particular initial conditions