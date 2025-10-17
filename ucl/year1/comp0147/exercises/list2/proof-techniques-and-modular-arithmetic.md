## q1 [M]
if $m+n$ is even, rewrite $m+n=2a$, and $n+p=2b$

then rearrange $m+n=2a$ for $m$, giving us $$m = 2a - n$$ and similarly for $p$: $$p =2b - n$$

therefore $ m + p = (2a-n) + (2b-n) = 2(a+b-n)$

since $a$, $b$ and $n$ are all integers, $a+b-n$ must also be an integer. 

therefore, $m+p$ must be even by direct proof

## q2 [M]
let $x$ and $y$ be the two odd numbers respectively

since $x$ and $y$ are both odd, there exist some numbers $k$ and $j$ such that $$x = 2k + 1 \newline y=2j+1$$

therefore, $$\begin{align}
x \cdot y &= (2k+1)(2j+1) \\
&= 2kj + 2k + 2j + 1 \\
&=2(kj + k + j) + 1
\end{align}$$

since $k$ and $j$ are both integers, $kj + k + j$ must also be an integer. 
we therefore have by direct proof that multiples of two odd numbers must also be odd

## q4 [M]

by contradiction:
assume that $n$ and $n+2$ are perfect squares
then, there exist $a, b \in \N$ such that $n = a^2$ and $n+2=b^2$
we then have $ n+2-n = b^2 - a^2$, or $(a+b)(b-a) = 2$
since $a$ and $b$ must be integers, $(a+b)$ and $(a-b)$ must be factors of $2$
the only solution would therefore be $(a+b) = 2$ and $(a-b)=1$ which gives $ a = \frac{3}{2}$ and $b = \frac{1}{2}$
then, $n=a^2$ and $n+2=b^2$ would not be perfect squares, which contradicts the original statement