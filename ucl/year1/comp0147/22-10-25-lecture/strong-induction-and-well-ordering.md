# strong induction

## the curious case of prime divisors
- show that every natural number $n \geq 2$ has a prime divisor
  - base step: 2 is prime, so the result follows trivially
  - inductive step: suppose that the result follows for all $ k < n$, that is, "$\forall k \in \N \cdot k < n \rightarrow \exists p \cdot (\text{prime} \space p) \land (p \vert k) $"
  - hence either $n$ is prime, and the result follows trivially, or $ n = a \cdot b $ with $ 1 < a $, $ b < n$
  - by the induction hypothesis, there exists $p$ prime such that $ p \vert a$ hence $p \vert n$

## introduction
- the (normal) induction principle we have seen so far is sometimes called the weak principle of mathematical induction
$$
[P(1) \land \forall k : (P(k) \rightarrow P(k+1))] \rightarrow \forall n: P(n)
$$

- it is called weak induction because the inductive hypothesis, $P(k)$, is only true for some $k$ 
- sometimes it is complicated to use weak induction to prove a theorem, so we can resort to the strong principle of mathematical induction
  - the induction hypothesis is that $P(j)$ is true for every $ 1 \leq j \leq k$.

## principle of strong mathematical induction
- to show that a property $P(n)$ holds for all positive integers $n$, a proof using the strong principle of mathematical induction has two parts:
  - base step: prove $P(1)$
  - inductive step: prove that for any positive integer $k$, if $P(j)$ is true for all $ 1 \leq j \leq k$, then $P(k+1)$ is true
  - the inductive hypothesis of strong induction is that $P(1) \land P(2) \land ... \land P(k)$ are all true
  - the strong principle of mathematical induction can be expressed as: $$
  [P(1) \land \forall k : ([P(1) \land P(2) \land ... \land P(k)] \rightarrow P(k+1))] \rightarrow \forall n : P(n)
$$
    - with the base step being $P(1)$,
    - the inductive step being $(P(1) \land P(2) \land ... \land P(k))\rightarrow P(k+1)$

## intuition
- imagine you are in front of an infinite staircase, and ask "Can I reach any step on this staircase?"
- we know that:
  1. we can reach the first step and also the second step, and
  2. if we can reach any step, we can also reach two steps above it (climb to steps at a time)
- we can use weak induction to verify that we can reach any step of this staircase

## postage example
- every postage of 12 cents or more can be made using only 4-cent and 5-cent stamps
  proof:
    - let $P(n)$ be the proposition any postage of $n$ cents can be made using only 4-cent and 5-cent stamps
    - base step: we need four base cases.
      1) $P(12)$ is true because we can use three 4-cent stamps;
      2) $P(13)$ is true because we can use two 4-cent stamps and one 5-cent stamp;
      3) $P(14)$ is true because we can use one 4-cent stamp and two 5-cent stamps;
      4) $P(15)$ is true because we can use three 5-cent stamps.
      5) this completes the base step.
     - inductive step:
       - the inductive hypothesis is that $P(j)$ is true for $ 12 \leq j \leq k$, where $k$ is an integer where $k \geq 15$; that is all postage values between $12$ and $k$ cents can be made using only 4-cent and 5-cent stamps
       - to complete the inductive step, we will show that, under the IH, $P(k+1)$ is true, that is, that postage of $k+1$ cents can be made using only 4- and 5- cent stamps.
       - by the inductive hypothesis, $P(k-3)$ is true because $k-3 \geq 12$ and for all $ 12 \leq j \leq k$ we have $P(j)$ true
       - therefore, there is a way to make $k-3$ cents of postage using only 4- and 5-cent stamps. to make $k + 1$ cents, just add one 4-cent stamp to the postage for $k-3$ cents.
       - this completes the inductive step and the proof

## well-ordering principle
- the weak and strong principles of mathematical induction are equivalent: 
  1. any proof that can be done using weak induction can also be done using strong induction
  2. any proof that can be done using strong induction can also be done using weak induction
- moreover, the weak and strong principles of mathematical induction are are equivalent to the following axiom of the natural numbers:

- well-ordering principle: let $S$ be a non-empty subset of $\N$, then $S$ has a smallest element