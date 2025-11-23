# proof methods
### direct proof of $P \rightarrow Q$
1. assume that $P$ is true
2. [ logical deductions to derive $Q$ from $P$ ]
3. therefore, $Q$ is true.

### proof by contrapositive (of $P \rightarrow Q$)
1. state that we are using proof by contrapositive and what the contrapositive of the implication is 
$$ (\neg Q \rightarrow \neg P \equiv P \rightarrow Q)$$
2. use a proof technique to show that $ \neg Q \rightarrow \neg P $
3. therefore, the original implication is proved

### proof by contradiction (of proposition $P$)
1. assume that $P$ is false (i.e. $\neg P$ is true)
2. [ logical deductions to come up with a contradiction ]
3. conclude that the assumption that $P$ is false cannot hold
4. therefore, $P$ is true

$$\begin{align}
    \neg (Q \rightarrow R) &\equiv \neg(\neg Q \lor R) \\
    & \equiv \neg \neg Q \land \neg R \\
    & Q \land \neg R
\end{align}$$

### proof by contradiction (of $P \rightarrow Q$)
1. assume that $P \rightarrow Q$ is false (i.e. $P$ is true and $Q$ is false)
2. [ logical deductions to come up with a contradiction ]
3. conclude that the assumption that $P \rightarrow Q$ is false and cannot hold
4. therefore, $P \rightarrow Q$ is true

## induction
### when to use mathematical induction
- the principle of induction can be used to prove properties of the integers (if they are true)
- cannot be used to discover properties of the integers
- properties are discovered using other methods, and once a property is conjectured, induction can be used to prove it

### template for a proof by mathematical induction
1. express the statement to be proved in the form "for all integers $n \geq b, \space P(n)$, where $b$ is a fixed integer
2. write "Base step", and show that $P(b)$ is true, making sure that the correct value of $b$ is used. this completes the base step
3. "inductive step" and state the inductive hypothesis in the form "assume that $P(k)$ is true for an arbitrary fixed integer $k \geq b$
4. write what $P(k+1)$ 
5. prove the statement $P(k+1)$ using the fact that $P(k)$ is true, making sure proof is valid for any $k \geq b$
6. identify conclusions of inductive step
7. once both are completed, write: "by mathematical induction, $P(n)$ is true for all integers $n \geq b$

## strong induction
### weak (normal) induction
$$
[P(1) \land \forall k: (P(k) \longrightarrow P(k+1))] \longrightarrow \forall n : P(n)
$$
- where $P(k)$ is the inductive hypothesis
  - it is known as weak induction because the inductive hypothesis is only that $P(k)$ is true for some $k$
- in contrast, the inductive hypothesis is that $P(j)$ is true for every $1 \leq j \leq k$


### principle of strong mathematical induction
- to show that a property $P(n)$ holds for all positive integers $n$, proof using strong induction has two parts:

### base step
- prove $P(1)$

### inductive step
- prove that for any positive integer $k$, if $P(j)$ is true for all $1 \leq j \leq k$, then $P(k+1)$ is true
  - the inductive hypothesis is that $P(1) \land P(2) \land ... \land P(k)$ are all true
- the strong principle of mathematical induction can be expressed as:
$$ 
[ P(1) \land \forall k: ([P(1) \land P(2) \land ... \land P(k)] \longrightarrow P(k+1))] \longrightarrow \forall n : P(n)
$$
  - where:
    - $P(1)$ is the base step
    - $\forall k: ([P(1) \land P(2) \land ... \land P(k)] \longrightarrow P(k+1))]$ the inductive step
    - $\forall n : P(n)$ the conclusion