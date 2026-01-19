# booelan algebra
- essentially propositional logic viewed in algebraic terms
- a boolean algebra is a tuple $(B, 0, 1, +, -)$;
  - where $B$ is a nonempty set, and 
    - $0, 1 \in B;$
    - $+: B \times B \rightarrowtail \text{ is a binary function on } B$
    - $-: B \rightarrowtail B \text{ is a unary function on } B$
  - we write abbreviations:
$$ \overline a \text{ for } -a \text{ and } a \cdot b \text{ for } -(\overline a + \overline b)$$

# axioms for boolean algebra
## axioms for $+$
$$\begin{align*} 
a + (b + c) &= (a + b) + c &\text{(associativity)} \\
a + b &= b + a  &\text{(commutativity)} \\
a + a &= a &\text{(idempotency)} \\
0 + a &= a &\text{(unit law)}
\end{align*}$$

## axioms for $-$
$$\begin{align*} 
--a &= a &(--) \\
a + \overline a &= 1 &\text{(complement)} \\
-1 &= 0 &\text{(0/1 law)} 
\end{align*}$$

## distribution law
$$
a \cdot (b + c) = a \cdot b + a \cdot c
$$

# example (1st) of boolean algebra
- easy correspondence with propositional logic
- $=$ corresponds to disjunction $(\lor)$
- $-$ corresponds to negation $(\neg)$
- $\cdot$ corresponds to conjunction $(\land)$

# example (2nd) of boolean algebra
if $X$ is a non-empty set, then define its powerset:
$$ \text{Pow}(X) =_{def} \set{Y | Y \subseteq X} $$
then 
$$ (\text{Pow}(X), \emptyset, X, \cup, \setminus) $$
is a boolean algebra (called a Boolean set algebra)
- the $0$ and $1$ of the algebra are $\emptyset$ and $X$
- the $+$ of the algebra is $\cup$ (set union)
- the $-$ of the algebra is $X \setminus$ (set complement)

theorem: every boolean algebra is isomorphic (the same) to a Boolean set algebra

# De Morgan Laws
$$
\begin{align*}
-(a+b) &= - (\overline {\overline a} + \overline {\overline b}) \\
&= \overline a \cdot \overline b \\
-(a \cdot b) &= - - (\overline a + \overline b) \\
&= \overline a + \overline b
\end{align*}
$$

# consequences of the axioms
1. $a \cdot \overline a = 0$
$$ \begin{align*}
 \overline a + \overline {\overline a} &= 1 \qquad &\text{(complement)} \\
 -(\overline a + \overline{\overline a}) &= -1 = 0 &\text{(0/1 law)} \\
a \cdot \overline a &= 0 &\text{(defn of } \cdot)
\end{align*} $$

2. $a \cdot 1 = a$ 

$$\begin{align*}
a \cdot 1 &= a \cdot (\overline a + a) &\text{(complement)} \\
&= a \cdot \overline a + a \cdot a &\text{(distribution law)} \\
&= 0 + - (\overline a + \overline a ) &\text{(item 1 above and defn of }\cdot) \\ 
&= 0 + - (\overline a) &\text{(idempotency)} \\
&= 0 + a &\text{(--)} \\
&= a &\text{(unit law)}
\end{align*}$$

# duality
theorem:
if $A = B$ is a true Boolean equation then $A* = B*$ is also true, where $A*$ is obtained from $A$ by swapping $+$ and $\cdot$ throughout, and swapping $0$ and $1$ throughout,


$$ a + b \cdot c = (a + b ) \cdot (a + c) $$

$$ 
(a + b) \cdot (a + c) \\
\text{}\\
\begin{align*} 
&= (a + b) \cdot a + (a + b) \cdot c &\text{(distribution)} \\
&= a \cdot a + b \cdot a + a \cdot c + b \cdot c &\text{(distribution)} \\
&= a \cdot 1 + b \cdot a + a \cdot c + b \cdot c &(a \cdot a = a = a \cdot 1) \\
&= a \cdot (1 + b + c) + b \cdot c &\text{(distribution} \times 2) \\
&= a \cdot 1 + b \cdot c &(1 + b + c = 1) \\
&= a + b \cdot c &(a \cdot 1 = a)
\end{align*}
$$ 

# sums of products
- every boolean term is equal to a sum of products (cf. DNF)
- we can read off a sum of products from the truth table of the term, as for DNFs
- alternatively we can use equational laws. Replace
$$
\begin{align*}
-(a + b) &\text{ by } \overline a \cdot \overline b \\
-(a \cdot b) &\text{ by } \overline a + \overline b \\
--a &\text{ by } a \\
a \cdot (b + c) &\text{ by } a \cdot b + a \cdot c
\end{align*}
$$

# limitations of propositional logic 
- propositional logic/boolean algebra is fine as far as it goes
  - not very expressive: we have no access to the internal structure of propositions, and no way of quantifying anything

- in particular we cannot explain why Aristotelian-type arguments are valid
- for this, need to ues first-order logic