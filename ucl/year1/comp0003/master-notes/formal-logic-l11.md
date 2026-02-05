# induction principle for formulas
$(\lor, \neg)$-formulas: $ F ::= Q \space | \space \neg F \space | \space F \lor F$
- "an or/not formula $F$ is either a proposition letter $Q$ or is a negation of something that is a formula, or a disjunction of two things that are already formulas"

to prove a universal property $P$ of $(\neg, \lor)$-formulas:
1. show that $P(Q)$ holds for any $Q$ (base case):
2. assuming $P(A)$ $\text{(IH)}$, show that $P(\neg A)$ (step case 1)
3. assuming $P(A)$ and $P(B)$ $\text{(IH)}$, show $P(A \lor B)$ (step case 2)
$$
  \frac{
    P(Q) \quad P(A) \Rightarrow P(\neg A) \quad P(A) \ \& \ P(B) \Rightarrow P(A \lor B)
  }{
    \forall F \in \text{Formula}. \ P(F)
  }
  \quad (A, B \text{ arbitrary})
$$

# formula induction example
## lemma
every $(\lor, \neg)$-formula has one more occurrence of proposition letters than occurrences of $\lor$
## proof
by structural induction on $(\lor, \neg)$-formula $A$

base case: proposition $Q$: 1 proposition letter, 0 disjunctions, trivially true

induction hypothesis: $A$ and $B$ both have one more occurrence of proposition letters than of $v$

step case for $\neg$: $\neg A$ has as many prop. letters and $\lor$s as $A$ does, so done by $\text{(IH)}$

step case for $\lor$: suppose $A$ and $B$ have $m, n$ respectively of propositional letters. By the $\text{(IH)}$ they have $m-1$, $n-1$ $\lor$s. Therefore $A \lor B$ has $m + n$ propositional letters and $m + n - 1$ $\lor$s (as we added one between $A, B$) $\square$

# alternative induction schemes
## two-step induction on $\N$
alternative way to prove a universal property $P$ of $\N$
1. show that $P(0)$ holds (base case)
2. show that $P(s(0))$ holds (base case)
3. assume that $P(k)$ and $P(s(k))$ hold for some $k \in \N$ (inductive hypothesis)
4. show that $P(s(s(k))$ holds (step case)
$$ \frac{
    P(0) \quad P(s(0)) \quad P(k) \wedge P(s(k)) \to P(s(s(k)))
  }{
    \forall n \in \mathbb{N}.\ P(n)
  }
  \quad (k \text{ arbitrary})$$

## two-step induction example
define predicate even $(-)$ inductively on $\N$:
$$
\text{even}(0) \\
\text{even}(x) \rightarrow \text{even}(s(s(x)))
$$
even numbers are $0, ss0, ssss0, ssssss0, \dots$
### lemma
$\forall x, y \in \N. \space \text{even}(x) \land \text{even}(y) \rightarrow \text{even}(x + y)$
### proof 
by "two-step induction" on $x$

base case 1: require to prove $\text{even}(0)\land \text{even}(y) \rightarrow \text{even}(0 + y)$: easy
base case 2: require to prove $\text{even}(s(0)) \land \text{even}(y) \rightarrow \text{even}(s(0) + y)$: holds by contradiction, because $\neg \text{even}(s(0))$

inductive hypothesis: $\forall y \in \N. \space \text{even}(k) \land \text{even}(y) \rightarrow \text{even}(k+y)$ (and same for $s(k)$, but we won't need it)

step case: let $y \in \N$ be given. require to prove

$$ 
\text{even}(s(s(k))) \land \text{even}(y) \rightarrow \text{even}(s(s(k)) + y)
$$

so suppose $\text{even}(s(s(k)))$ and $\text{even}(y)$. Hence, by $\text{(IH)}$, $\text{even}(k+y)$ then we have: 
$$
\begin{align*}
\text{even}(k + y) &\rightarrow \text{even}(s(s(k+y))) && \text{(even)} \\
&\rightarrow \text{even}(s(s(k)+y)) && (+) \\
&\rightarrow \text{even}(s(s(k)) + y) && (+)
\end{align*}
$$

# two step induction implies ordinary induction
we can use two step induction to derive ordinary induction: 
$$
\frac{
    P(0) \quad P(k) \to P(s(k))
  }{
    \forall n \in \mathbb{N}.\ P(n)
  }
  \quad (k \text{ arbitrary})
$$

proof: suppose $P(0)$ and $P(k) \rightarrow P(s(k))$ for any $k$. we show $\forall n \in \N$. $P(n)$ by two step induction on $n$

base case 1: require to prove $P(0)$. immediate by assumption

base case 2: require to prove $P(s(0))$. follows from $P(0)$ and $P(k) \to P(s(k))$, taking $k = 0$

inductive hypothesis: $P(x)$ and $P(s(x))$

step case: RTP $P(s(s(x)))$. follows from $P(s(x))$ and $P(k) \to P(s(k))$, taking $k = s(x)$

$$
\frac{
    P(0) \quad P(s(0)) \quad P(k) \wedge P(s(k)) \to P(s(s(k)))
  }{
    \forall n \in \mathbb{N}.\ P(n)
  }
  \quad (k \text{ arbitrary})
$$
proof: 
assume premises of the rule: we show $\forall n \in \N$. $P(n)$, by showing $\forall n \in N$ . $P(n) \land P(s(n))$ by ordinary induction on $n$

base case: require to prove $P(0) \land P(s(0))$. immediate by assumption

inductive hypothesis: $P(x) \land P(s(x))$

step case: require to prove $P(s(x)) \land P(s(s(x)))$. Follows from $\text(IH)$ and $P(k) \land P(s(k)) \to P(s(s(k)))$, taking $k = x$ $\square$