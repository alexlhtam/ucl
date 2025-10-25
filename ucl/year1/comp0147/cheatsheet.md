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