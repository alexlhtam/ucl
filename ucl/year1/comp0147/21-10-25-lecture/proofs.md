## evidence vs proof
consider $p(n) = n^2 + n + 41$
- conjecture: $\forall n \in \N : p(n) $ is prime
- the values $n=0, 1, ..., 39$ is true until $n=40$
- evidence is not the same as proof

## how to write a proof
- clearly state the statement you want to prove
  - it is command to precede the statement with the word Theorem or Lemma
- clearly delimit the scope of the proof
  - indicate the start of the proof with the word proof
  - indicate the end of the proof with a marker
  - one can use a little square $\square$ 
  - or the abbreviation QED
- write a proof in such a way that it is self contained
  - use natural language clearly
  - employ complete and well-structured sentences
  - mathematical formulae, equations, etc. can be used when necessary

## direct proof
1. express the statement to be proved in the form: $$ \forall x \in D: (P(x) \rightarrow Q(x)) $$
    this step is sometimes done mentally
2. start the proof by assuming that $x$ is a specific element of domain $D$, but chosen arbitrarily, for which the hypothesis $P(x)$ is true
3. show that the conclusion $Q(x)$ is true using definitions, previous results, and the rules of logical inference
- since $x \in D$ is chosen arbitrarily:
  - it does not depend on any special assumption about $x$
  - can be generalised to all elements of $D$

## proof by contraposition
1. express the statement to be proved in the form: $$ \forall x \in D : (P(x) \rightarrow Q(x)) $$
2. find the contrapositive of the statement: $$\forall x \in D : (\neg Q(x) \rightarrow \neg P(x))$$
3. start the proof by assuming that $x$ is a specific element of the domain $D$, but chosen arbitrarily, for which the conclusion $Q(x)$ is false
4. show that the hypothesis $P(x)$ is false using definitions, previous results, and rules of logical inference
- since $x \in D$ is chosen arbitrarily:
  - it does not depend on any special assumption about $x$
  - can be generalised to all elements of $D$

## proof by contradiction
- based on the fact that if starting from a premise $p$ and applying inference rules correctly, we arrive at a false conclusion, so the premise $p$ itself must necessarily be false
- equivalently, if assuming the negation $\neg p$ of a statement elads to an absurdity (contradiction) then the premise $p$ must necessarily be false
- to prove that the statement $p$ is true, assume that the negation $\neg p$ is true
- show that $\neg p$ leads to a contradiction