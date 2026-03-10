# introduction
- intuition: complex numbers extend $\mathbb R$ so equations like $x^2+1=0$ have solutions.
- formal unit:
$$
i^2=-1
$$
- standard form:
$$
z=x+iy,\qquad x,y\in\mathbb R
$$
- $x=\Re(z)$, $y=\Im(z)$, and the set is $\mathbb C$

# basic complex arithmetic
- add/subtract parts separately
- multiply then use $i^2=-1$

## conjugate of a complex number
$$
\overline{x+iy}=x-iy
$$
- key identity:
$$
z\overline z=x^2+y^2=|z|^2
$$

- division: multiply top and bottom by conjugate of denominator

# geometric representation
- intuition: $z$ is a point/vector in the plane.
- polar form:
$$
z=R(\cos\theta+i\sin\theta)=Re^{i\theta}
$$
$$
R=|z|=\sqrt{x^2+y^2},\qquad \theta=\arg(z)
$$


## exponential form
- intuition: exponential form makes multiplication/division easy.
$$
z=Re^{i\theta},\qquad R\ge 0,\ \theta\in\mathbb R
$$
- arguments are modulo $2\pi$
- rules:
$$
R_1e^{i\theta_1}\cdot R_2e^{i\theta_2}=(R_1R_2)e^{i(\theta_1+\theta_2)}
$$
$$
\frac{R_1e^{i\theta_1}}{R_2e^{i\theta_2}}=\frac{R_1}{R_2}e^{i(\theta_1-\theta_2)}
$$

- triangle inequality:
$$
|z_1+z_2|\le |z_1|+|z_2|
$$
- geometric view of multiplication: scale by moduli, rotate by sum of arguments

# roots of unity
- problem: solve $z^n=1$ for $n\in\mathbb N$
- write $z=Re^{i\theta}$:
$$
z^n=R^ne^{in\theta}=1
$$
- so $R=1$ and $n\theta=2k\pi$, hence
$$
z_k=e^{i\frac{2k\pi}{n}},\qquad k=0,1,\dots,n-1
$$
- exactly $n$ distinct roots (equally spaced on unit circle)

## worked exam questions

### basic arithmetic
- question: compute $(2+3i)(1-4i)$.
- formula used:
$$
i^2=-1
$$
- working:
$$
(2+3i)(1-4i)=2-8i+3i-12i^2=2-5i+12=14-5i
$$

### conjugate and division
- question: simplify $\frac{3+2i}{1-i}$.
- formula used:
$$
\frac{z}{w}=\frac{z\overline w}{w\overline w}
$$
- working:
$$
\frac{3+2i}{1-i}\cdot\frac{1+i}{1+i}
=\frac{(3+2i)(1+i)}{1+1}
=\frac{1+5i}{2}
=\frac12+\frac52 i
$$

### modulus/argument form
- question: write $z=-1+i\sqrt3$ in polar/exponential form.
- formula used:
$$
z=Re^{i\theta},\quad R=|z|,\ \theta=\arg(z)
$$
- working:
$$
R=\sqrt{(-1)^2+(\sqrt3)^2}=2,\quad \theta=\frac{2\pi}{3}
$$
- result:
$$
z=2\!\left(\cos\frac{2\pi}{3}+i\sin\frac{2\pi}{3}\right)=2e^{i\frac{2\pi}{3}}
$$

### roots of unity
- question: find all roots of $z^4=1$.
- formula used:
$$
z_k=e^{i\frac{2k\pi}{n}},\ k=0,\dots,n-1
$$
- working with $n=4$:
$$
z_0=1,\ z_1=i,\ z_2=-1,\ z_3=-i
$$