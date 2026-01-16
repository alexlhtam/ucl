# union-find
- given a set of objects (nodes), how do we:
  - connect them
  - check if they are connected

## problem model:
- we have $N$ objects, (integers $0 \to N - 1$)
- `union` command: connect the two objects
- `find` command: check if there is a path connecting the two objects
- connections are reflexive, symmetric and transitive (equivalence relations)

## alg 1: quick-find/eager approach
- data structure: an integer array `id[]` where `id[i]` is the component ID of the object `i`
- logic: two objects are connected if they have the same ID
- cost: 
  - `find` is very fast ($O(1)$) because we can check if `id[p] ==id[q]`
  - `union` is too slow ($O(N)$) because we need to iterate through the entire array to change all matching IDs every time a pair is connected - not scalable for huge datasets

## alg 2: quick-union/lazy approach
- data structure: the array `id[]` now represents a set of "trees": `id[i]` is the parent of `i`
- logic: to find the `root` of an item, we need to follow the parents up until the index matches the value (`i == id[i]`)
- cost:
  - `union` involves just changing one parent pointer
  - trees can get too call (worst-case $N$ height), making `find` operation slow ($O(N)$) in the worst case

## alg 3: weighted quick-union/(optimised
- improvement: to avoid tall trees, we keep track of the size of each tree
- logic: when linking two trees, always link the root of the smaller tree to the root of the larger tree
- result: guarantees the tree remain flat, the depth of any node is at most $\log N$

# analysis of algorithms
- explains how to scientifically predict the performance of code and compare different algorithms

## mathematical models
- the total running time is the sum of (cost $\times$ frequency) for all operations
- tilde notation ($\sim$): a simplification technique where you ignore lower-order terms to focus on the dominant factor (e.g. $\frac{1}{2}N^2 + N \rightarrow \sim \frac{1}{2}N^2$)
- asymptotic notation:
  - big oh ($O$): upper bound, worse case guarantee
  - big omega ($\Omega$): lower bound, best case scenario
  - big theta ($\Theta$): tight bound, use to classify algorithm precisely