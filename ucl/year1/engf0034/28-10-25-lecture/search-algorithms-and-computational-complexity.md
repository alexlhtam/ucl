# single-agent search: mazes and heuristics

goal: find a path from start (S) to end (E) location

challenge: develop an algorithm that guarantees findinga. solution if one eists, and ideally does so efficiently 

## common heuristic: right hand rule
1. place right hand on a wall at the entrance
2. continuously follow the wall, maintaining contact with your right hand

guaranteed to work if and only if the maze is simply connected
-   all walls connected to the outer boundary, no detached chunks or islands

### failure point 
right-hand cycles that isolates the destination

## the need for a guaranteed algorithm
1. termination: algorithm must not get stuck in infinite loops (must handle cycles)
2. completeness: algorithm must expore all reachable paths to guarantee finding the solution if it exists

## mechanism: the call stack
1. when a function is called a new stack frame is pushed onto the call stack, storing local variables and the return address
2. the recursion winds as frames are pushed until the base case is reached
3. the recursion unwinds as the base case returns, and frames are popped off the stack sequentially

## applying recursion to maze solving
- approach naturally implements DFS
- recursive insight:
  -  a path exists from the current location L to the End E if and only if a path eists from one of L's adjacent, reachable neighbours to E
- addressing cycle problem
  - to prevent infinite loops, the algorithm must track its history. 
  - state space needs to be augmented

## DFS maze algorithm
1. base case 1 (success): if location is end, return true
2. base case 2 (failure): if locaiton is wall or visited, return False
3. state update: mark location as visited
4. recursive step: for each step:
   1. if solve(neighbour) returns true, return true
5. exhaustion (dead end): if all neighbours fail, return false

## the mechanism of backtracking:
- completness guaranteed
  - ensures every reachable path is eventually explored
- path reconstruction
  - need to umark the cell when 
  - backtracking from a dead end

# adversial search and game trees 
- in maze solving (DFS), we seek an optimal path in a passive environment. we control the decisions
- in adversarial search (games), the environment is hostile

new challenge:
- we face rational opponents actively working against our goals
- need a strategy that accounts for the opponent's moves, assuming the opponent also plays optimally
  
focus: two-player zero-sum games
- two player and zero sum
- deterministic and perfect information

## modelling games: the game tree
- fundamental structure for analysing these games is the Game Tree, which is analogous to the search space of the maze
  - nodes: game states
  - edges: represent moves
  - root: the initial state
  - leaves (terminal nodes): states where the game ends (W/L/D)

## game complexity and state space
- the feasability of solving a game depends on the szie of its game tree
  - b: branching factor (average number of legal moves per turn)
  - depth (maximum length of game in turns/player)
  - game tree size (time complexity of search: $O(b^d)$)

## goal: optimal play against a rational opponent
- we want an algorithm that chooses the best possible move, assuming the opponent also plays optimally to defeat us
- defining utility and players
  - MAX tries to maximise final utility score
  - MIN tries to minimise final utility score
  - DRAW utility of 0 