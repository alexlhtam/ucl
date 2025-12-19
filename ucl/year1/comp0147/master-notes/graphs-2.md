# Euler & Hamilton paths

## walks, trails and paths
- path: a sequence of edges leading from one vertex to another
- circuit: a path that begins and ends at the same vertex
- simple path/circuit: does not repeat any edges
- our focus: paths and circuits that use either all edges (Euler) or all vertices (Hamilton)

## definitions: Euler paths and circuits

### Euler path
- an Euler path is a simple path in a graph $G$ that traverses every edge of $G$ exactly once
  
### Euler circuit
- an Euler circuit is a simple circuit in a graph $G$ that traverses every edge of $G$ exactly once

## conditions for Euler circuits
Theorem (Euler circuit condition)
a connected multigraph has an Euler circuit if and only if every vertex in the graph has an even degree
- Intuition: for any intermediate vertex, every time you enter that vertex (using one edge), you must leave it (using a different edge)
- this paired entry/exit requires an even number of edges connected to that vertex

## the rule of two
- for any vertex $v$ that is simply passed through by the circuit, two things happen:
  - the circuit enters $v$ via one edge
  - the circuit leaves $v$ via a different edge
- this single passage contributes exactly two $(+2)$ to the vertex's degree

### case 1: vertices not the start/end point
- let $v$ be any vertex that is NOT the starting/ending vertex
- since the circuit does not start or end at $v$, every time an edge connected to $v$ is used, the circuit must pass through $v$
- each pass contributes $+2$ to $\text{deg}(v)$
- if the circuit passes through $m$ times:
$$ \text{deg}(v) = 2m $$
- the degree of $v$ must be even

### case 2: the starting/ending vertex $(a)$
- let $a$ be the vertex where the circuit starts and ends
1. start: the circuit leaves $a$ $(+1)$
2. passes: if the circuit returns and leaves again $k$ times $(+2k)$
3. end: the circuit enters $a$ for the final time $(+1)$
- total degree of $a$ is the sum of these contributions:
$$ \text{deg}(a) = 1 + 2k + 1 = 2k + 2 = 2(k + 1) $$

### the sufficient condition: guaranteeing an Euler circuit
> the power of Euler's theorem
> if a connected multigraph has every vertex with an even degree, then an Euler circuit must exist
this is proven using a construction method, often attributed to Hierholzer's Algorithm 
1. start at any vertex $v_1$ and build a closed circuit $C_1$ until you can't proceed (you will always return to $v_1$ because degrees are even)
2. remove all edges in $C_1$. all remaining vertices still have even degrees
4. splice $C_2$ into $C_1$ to create a larger circuit 
5. repeat until all edges are used 

### why the circuit will always close
> the crucial property
> in any graph where all vertex degrees are even, if you start walking along a path, you are guaranteed to return to your starting point
- every time you enter an intermediate vertex $v$, you use one of its edges. since $\text{deg}(v)$ is even, there is always at least one unused edge left to leave by.
- when you reach a vertex $v$ for the last time, you used the final entry edge. if $v$ is not the starting vertex, its degree must have been a multiple of 2, meaning you could not have just one edge left.
- you cannot get stuck at an intermediate vertex

### conditions for Euler paths
> corollary (Euler path condition)
- a connected multigraph has an Euler path but not an Euler circuit if and only if it has exactly two vertices of odd degree
- all other vertices must have an even degree to allow for transit (enter/exit pairs)

# Hamilton paths and circuits

## Hamilton path
- a Hamilton path is a path that visits every vertex in the graph exactly once

## Hamilton circuit
- a Hamilton circuit is a Hamilton path that is also a circuit (returns to start) 

## contrast: Euler v Hamilton
| property | Euler | Hamilton |
| :---: | :---: | :---: |
| focus | use every edge once | visit every vertex once | 
| key check | vertex degrees | graph structure | 
| difficulty | easy $(O(E))$ | generally hard ($NP$-complete) |
- unlike Euler, there is no simple degree condition for Hamilton paths/circuits
- we rely on necessary conditions (to rule out) and sufficient conditions (to guarantee)

## sufficient conditions (guarantees)
- Dirac's Theorem 

  If $G$ is a simple graph with $n$ vertices, where $n \geq 3$, such that the degree of every vertex in $G$ is at least $\frac{n}{2}$, then $G$ has a Hamiltonian circuit
<br>
- Ore's Theorem
  If G is a simple graph with $n$ vertices, where $n \leq 3$, such that $$\text{deg}(u) + \text{deg}(v) \leq n$$ for every pair of nonadjacent vertices $u$ and $v$ in $G$, then $G$ has a Hamiltonian circuit

# Planar Graphs
> a graph $G$ is planar if it can be drawn in the plane such that no two edges cross
- such a drawing is called a planar embedding or planar representation
- a graph might be planar even if its initial drawing shows edges crossing. we only need to find one drawing without crossings

## regions in planar graphs
- a planar representation divides the plane into connected cell areas called regions or faces $(r)$
- there is always exactly one unbounded region (the exterior)

## Euler's formula
let $G$ be a connected planar simple graph with:
  - $v$ vertices
  - $e$ edges
  - $r$ regions
- then the following relationship holds: $$r = e - v + 2$$

## corollaries for Non-Planarity
> Theorem (maximum edges)
> if $G$ is a connected planar simple graph with $v \leq 3$ vertices, then $$ e \leq 3v - 6$$

> Theorem (triangle-free graphs)
 
  - and no $K3, 3$ sub graph

# graph colouring

## graph colouring: definitions
- graph colouring: a colouring of a simple graph $G$ is an assignment of a colour to each vertex such that no two adjacent vertices have the same colour
- chromatic number $(\chi(G))$
  - $\chi(G)$ is the least number of colours needed for a colouring of $G$
  - a graph $G$ is $k$-colourable if $\chi(G) \leq k$

## map colouring
- map colouring: assign a colour to each region of a map such that adjacent regions (sharing a common border) have different colours
- dual graph: any map can be represented by a graph where:
  - vertices represent map regions
  - edges connect vertices if the corresponding regions share a border\
 
## four colour theorem
> theorem
the chromatic number of a planar graph is no greater than $4$

## how to solve problems using graph theory
secret santa example: assign receivers randomly, so everybody gets a gift from someone

backtracking search or depth-first search: 
1. start with $A$ and pick the next node at random. we get the node $C$
2. the node $C$ is connected to $E$, $D$, $B$ and $A$. we exclude $A$ because the node has been used already, and pick $E$ at random
3. then, we pick $D$
4. the only node left to go from $D$ is $B$. all other nodes have already been visited
5. our path contains all nodes, but we have to return to $A$ to complete the cycle. however, there is no connection between $B$ and $A$, so we take a step back and return to $D$.
6. we can only go to $B$ from $D$ at step 3, and this path doesn't lead to a solution. so, we take another step back and return to $E$
7. this time we go from $E$ to $B$
8. now, the only possible move is from $B$ to $D$
9. we now complete the cycle going from $D$ to $A$

- if we always find a dead end after multiple back-trackings (and failing to find a Hamiltonian cycle) then there is no solution for the graph 