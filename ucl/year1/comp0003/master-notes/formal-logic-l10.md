# structural induction
## ordinary induction on $\N$
natural numbers defined inductively by:
$$ n ::= 0 | s(n)$$
thus, to prove a universal property $P$ of natural numbers:
1. show that $P(0)$ holds (base case)
2. assume that $P(k)$ holds for some $k \in \N$ (inductive hypothesis)
3. show that $P(s(k))$ holds (step case)
$$ \frac{P(0) \qquad P(k) \implies P(s(k))}{\forall n \in \N . P(n)} \text{(k arbitrary)}$$

## inductive definition of lists
lists defined inductively by 
$$ \mathcal{l} ::= [ \text{ }] | x :: \mathcal{l} $$
(where $x$ ranges over some datatype, e.g. natural numbers)
that is,
- $[\text{ }]$ ("empty list") is a list; (base case)
- if $\mathcal{l}$ is a list then so is $x :: l$, for any $x$; (step case)
- nothing else is a list

## induction principle for lists
to prove a universal property $P$ of lists:
1. show that $P([ \text{ }])$ holds (base case)
2. assume $P(xs)$ for some arbitrary list $xs$ (inductive hypothesis)
3. show that $P(x::xs)$ holds for any $x$ (step case)

As an inference rule:
$$\frac{P([\text{ }]) \qquad \forall x. P(xs) \implies P(x::xs)}{\forall l \in \text{List}. P(l)} \text{(xs arbitrary)} $$

## recursive functions on lists
functions designed by recursion on lists:

$$
\begin{align}
\text{len}[ \space] &= 0 \\
\text{len}(x::xs) &= 1 + \text{len}(xs) \\
\nonumber \\
[ \space] \space @ \space ys &= ys \\
(x::xs) \space @ \space ys &= x :: (xs \space @ \space ys) \\
\nonumber \\
\text{rev}[ \space ] &= [\space] \\
\text{rev}(x::xs) &= (\text{rev}(xs)) \space @ \space (x::[\space])
\end{align}
$$

## list induction example (1)
### lemma
$\forall xs, ys \in \text{List}. \text{len}(xs \space @ \space ys) = \text{len}(xs) + \text{len}(ys)$
### proof
by structural induction on $xs$. Here,
$P(l) = \forall ys. \text{len}(l \space @ \space ys) = \text{len}(l) + \text{len}(ys)$

base case: we have to show that $\text{len}([\space] \space @ \space ys) = \text{len}([\space])+ \text{len}(ys)$, easy using $(1)$ and $(3)$

inductive hypothesis: $\forall ys. \text{len}(zs \space @ \space ys) = \text{len}(zs) + \text{len}(ys)$

step case: let $ys$ be a list. we have to show $\text{len}((z:zs) \space @ \space ys) = \text{len}(z::zs) + \text{len}(ys)$
(sub in $(z:zs)$ for $l$)

to show: $\text{len}((z::zs) \space @ \space ys) = \text{len}(z::zs) + \text{len}(ys)$

$$
\begin{align*} 
  \text{len}((z :: zs) \mathbin{@} ys) 
    &= \text{len}(z :: (zs \mathbin{@} ys)) && \text{by (4)} \\
    &= 1 + \text{len}(zs \mathbin{@} ys) && \text{by (2)} \\
    &= 1 + \text{len}(zs) + \text{len}(ys) && \text{by (IH)} \\
    &= \text{len}(z :: zs) + \text{len}(ys) && \text{by (2)}
\end{align*}$$
this completes the step case, and the proof $\square$

## list induction example (2)

### lemma
$\forall xs \in \text{List}. \text{len}(rev(xs)) = \text{len}(xs)$

### proof
by structural induction on $xs$
base case: we have to show $\text{len}(\text{rev}([\space])) = \text{len}([\space])$
inductive hypothesis: $\text{len}(\text{rev}(ys)) = \text{len}(ys)$
step case: we have to show $\text{len}(\text{rev}(y::ys)) = \text{len}(y:ys)$

$$
\begin{align*}
  \text{len}(\text{rev}(y :: ys)) 
    &= \text{len}((\text{rev}(ys)) \mathbin{@} (y :: [])) && \text{by (6)} \\
    &= \text{len}(\text{rev}(ys)) + \text{len}(y :: []) && \text{by last lemma} \\
    &= \text{len}(\text{rev}(ys)) + 1 && \text{by (1) and (2)} \\
    &= \text{len}(ys) + 1 && \text{by (IH)} \\
    &= \text{len}(y :: ys) && \text{by (2)}
\end{align*}
$$

## inductive definition of trees
binary trees defined inductively by
$$ t::= Lf \space | \space \text{Br}(x, t, t)$$
(where $x$ ranges over some datatype). That is,
- $Lf$ ("leaf") is a tree; (base case)
- if $t_1$ and $t_2$ are trees, then so is $\text{Br}(x, t_1, t_2)$ ("branch"), for any $x$; (step case)
- nothing else is a tree

## induction principle for trees
to prove a universal property $P$ of trees:
1. show that $P(Lf)$ holds (base case)
2. assume $P(t_1)$ and $P(t_2)$ for arbitrary trees $t_1$ and $t_2$ (induction hypothesis)
3. show that $P(\text{Br}(x, t_1, t_2))$ holds for any $x$ (step case)
As an inference rule:
$$\frac{P(Lf) \quad P(t_1) \land P(t_2) \implies P(\text{Br}(x, t_1, t_2))}{\forall t \in \text{Tree}. P(t)}(x, t_1, t_2 \text{  arbitrary})$$

## recursive functions on trees
functions defined by recursion on trees:
$$
\begin{align}
  \text{size}(\text{Lf}) &= 0 \\
  \text{size}(\text{Br}(x, t_1, t_2)) &= 1 + \text{size}(t_1) + \text{size}(t_2) \\[3ex]
  \text{refl}(\text{Lf}) &= \text{Lf} \\
  \text{refl}(\text{Br}(x, t_1, t_2)) &= \text{Br}(x, \text{refl}(t_2), \text{refl}(t_1))
\end{align}
$$

## tree induction example (1)
### lemma
$\forall t \in \text{Tree}. \space \text{refl}(\text{refl}(t)) = t$

### proof
by structural induction on trees $t$
base case: require to prove $\text{refl}(\text{refl}(Lf)) = Lf$. Done by $(9)$ (twice)

inductive hypothesis: $\text{refl}(\text{refl}(t_1)) = t_1$ and $\text{refl}(\text{refl}(t_2)) = t_2$

step case: let $x$ be given. We have to show $\text{refl}(\text{refl}(\text{Br}(x, t_1, t_2))) = \text{Br}(x, t_1, t_2)$

$$
\begin{align*}
  \text{refl}(\text{refl}(\text{Br}(x, t_1, t_2))) 
  &= \text{refl}(\text{Br}(x, \text{refl}(t_2), \text{refl}(t_1))) && \text{by (10)} \\
  &= \text{Br}(x, \text{refl}(\text{refl}(t_1)), \text{refl}(\text{refl}(t_2))) && \text{by (10)} \\
  &= \text{Br}(x, t_1, t_2) && \text{by (IH)}
\end{align*}
$$