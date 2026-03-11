# differential calculus

## derivative
- intuition: derivative = local slope / infinitesimal variation.
- formal:
$$
f'(a)=\lim_{h\to 0}\frac{f(a+h)-f(a)}{h}
$$
- if this limit exists, $f$ is differentiable at $a$
- notation: $f'$, $\frac{df}{dx}$ (not a fraction), and $f''=\frac{d^2f}{dx^2}$
- if $F'=f$, then $F$ is a primitive (antiderivative) of $f$

## continuity and monotonicity
- differentiable at $c$ $\Rightarrow$ continuous at $c$
- if $f'>0$ on interval $I$, then $f$ is increasing on $I$
- if $f'<0$ on interval $I$, then $f$ is decreasing on $I$
- stationary points satisfy $f'(x)=0$ (possible min/max/inflection)

## key theorems
- L'Hopital rule (for $0/0$ or $\infty/\infty$ forms, under standard hypotheses):
$$
\lim_{x\to c}\frac{f(x)}{g(x)}=\lim_{x\to c}\frac{f'(x)}{g'(x)}
$$
- mean value theorem: if $f$ continuous on $[a,b]$ and differentiable on $(a,b)$, then
$$
\exists c\in(a,b),\quad f'(c)=\frac{f(b)-f(a)}{b-a}
$$

## first-order differential equations
- example:
$$
f'(x)=-3f(x)\quad \Rightarrow\quad f(x)=Ce^{-3x}
$$
- homogeneous linear equation:
$$
f'(x)=a(x)f(x)
$$
- if $A'(x)=a(x)$, general solution is
$$
f(x)=Ce^{A(x)},\qquad C\in\mathbb R
$$
- initial condition gives the constant $C$

## worked exam questions

### derivative
- question: compute $f'(x)$ for $f(x)=x^3-4x+1$ and find stationary points.
- formula used:
$$
\frac{d}{dx}(x^n)=nx^{n-1}
$$
- working:
$$
f'(x)=3x^2-4
$$
stationary points satisfy $3x^2-4=0$:
$$
x=\pm \frac{2}{\sqrt3}
$$

### monotonicity
- question: determine where $f(x)=x^3-3x$ is increasing/decreasing.
- formula used:
$$
f'(x)>0 \Rightarrow f \text{ increasing},\quad f'(x)<0 \Rightarrow f \text{ decreasing}
$$
- working:
$$
f'(x)=3x^2-3=3(x-1)(x+1)
$$
so $f'>0$ on $(-\infty,-1)\cup(1,\infty)$ and $f'<0$ on $(-1,1)$.

### L'Hopital
- question: compute $\lim_{x\to 0}\frac{e^x-1}{x}$.
- formula used: L'Hopital for $0/0$.
- working:
$$
\lim_{x\to 0}\frac{e^x-1}{x}
=\lim_{x\to 0}\frac{e^x}{1}=1
$$

### first-order ODE
- question: solve $y'=2y$ with $y(0)=5$.
- formula used:
$$
y'=a y \Rightarrow y=Ce^{ax}
$$
- working:
$$
y=Ce^{2x},\quad y(0)=C=5
$$
- result:
$$
y(x)=5e^{2x}
$$