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