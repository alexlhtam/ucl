# introduction
- why complex numbers?
  - algebraic argument: some equations must have solutions but have no solutions among real numbers
  - practical argument: complex numbers make our lives easier in many areas, such as trigonometry, physics, engineering, etc.
- foundation of complex numbers:
$$ i = \sqrt{-1}$$
- a complex number can be written as:
$$ z = x + iy \qquad x, y \in \R$$
- $x$ is the real part, $y$ is the imaginary part, both $x$, $y$ are both real numbers
- the set of all complex numbers is denoted by $C$
- real numbers are included in complex numbers

# basic complex arithmetic
- add up the real parts and imaginary parts separately
- multiply the real parts and imaginary parts separately

## conjugate of a complex number
$$ \overline{x+iy} = x - iy$$
- remark: $z \times \overline z = (x + iy) \times (x-iy) = x^2 + y^2$

- division: use the conjugate of the denominator and simplify

# geometric representation
- a complex number is represented by a point in the 2D plane
- cartesian coordinates or polar coordinates
- $R$ is called absolute value/modulus, $\theta$ is the argument
$$ \begin{align*}
z = x &+ iy: \\
x &= R \times \cos{(\theta)} \\
y &= R\times \sin{(\theta)} \\
|z| &= R = \sqrt{x^2 + y^2} \\
\theta &= \arg(z)
\end{align*}
$$ 


## exponential form
- a new notation:
$$ z = R \times e^{i\theta} \\
R, \theta \in \R; R \geq 0$$
- two complex numbers whose arguments differ by $2 \pi$ are considered equal
- multiplication of complex numbers is easier in exponential form

$$\begin{align*}
(1 \times e^{i \frac{\pi}{6}}) \times (2 \times e^{-i\frac{\pi}{4}}) &= 2 \times e^{i\frac{\pi}{6} + (-i\frac{\pi}{4})} \\ &= 2 \times e^{i(\frac{\pi}{6}-\frac{\pi}{4})}
\end{align*}
$$
- multiply the moduli and add up the arguments
- divide the moduli and subtract the arguments
<br>
- the absolute value (or modulus) verifies the following:
$$
\text{triangular equality} \\
|z_1 + z_2| \leq |z_1|+|z_2|
$$
<br>
- visualising complex operations geometrically
- multiplication:
- $z_1 \times z_2 = (R_1 \times R_2)e^{i(\theta_1 + \theta_2)}$ 
  - "rotation" by adding the arguments, multiplication of moduli

# roots of unity
- let $n \in \N$: how to find all complex numbers $z$ such that $z^n = 1$?
- simple case: $n = 2$
  -  there are 2 complex numbers $z$ such that $z^2 = 1$: $1, -1$
- simple case: $n = 3$
  - $z^3 = 1: 1, e^{i\frac{2\pi}{3}}, e^{i\frac{4\pi}{3}}$
  - $(e^{i\frac{2\pi}{3}})^3 = (e^{i\times2\pi}) = 1$
- in general: assume that $z$ is a solution, we write it as $z = R \times e^{i\theta}$
$$ z^n = (R\times e^{i\theta})^n = R^n \times e ^{i \times n \times \theta} = 1$$
  - this complex inequality implies equalities for:
    - the absolute value of $z$
$$ |z^n| = |1| \implies R^n = 1 \implies R = 1$$
    - the argument of $z$
$$ \arg(z^n) = \arg(1) = 0[2\pi] \implies n\theta = 0 + 2k\pi, k \in \N \implies \theta = \frac{2k\pi}{n}$$
  - need to consider the argument up to increments of $2\pi$
- to summarise:
$$ z^n = 1 \implies z = e^{ik\frac{2\pi}{n}}, k \in \N \\ e^{i\frac{2k\pi}{n}} = e^{i\frac{2k\pi}{n}+2\pi} = e^{i\frac{2(k+n)\pi}{n}}$$
  - we can consider only the first $n$ values of $k$, there are exactly $n$ distinct solutions, which we denote by $\omega_1, \dots, \omega_n$, with $\omega_n$ always $=1$