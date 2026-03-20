# COMP0005 — Algorithms: Lecture Notes Index

*Comprehensive revision notes covering all 9 lectures of the COMP0005 Algorithms module.*

---

## Notes Files

| # | File | Topic | Lectures | Summary |
|---|------|-------|----------|---------|
| 01 | [Union-Find](01-union-find.md) | Union-Find | L1 | Quick-Find, Quick-Union, Weighted Quick-Union; modelling connected components; the algorithm development cycle |
| 02 | [Analysis of Algorithms](02-analysis-of-algorithms.md) | Analysis of Algorithms | L2 | Empirical observations, mathematical models, frequency analysis, tilde notation, order of growth, binary search, Big-O / Big-Ω / Big-Θ |
| 03 | [Elementary Sorts](03-elementary-sorts.md) | Selection Sort & Insertion Sort | L3 | Two quadratic-time sorting algorithms with different invariants, best/worst/average cases, and stability properties |
| 04 | [MergeSort](04-mergesort.md) | MergeSort | L3 | Divide-and-conquer sorting; the merge step; $N \log N$ optimality; stability; extra space trade-off |
| 05 | [QuickSort](05-quicksort.md) | QuickSort | L4 | Partitioning, randomised shuffling, average vs worst case, 3-way partitioning for duplicates, in-place but not stable |
| 06 | [Abstract Data Types](06-abstract-data-types.md) | ADTs & Implementations | L4–L5 | ADT vs data structure; arrays, lists, stacks, queues, sets, maps, priority queues; array and linked-list implementations; amortised analysis of resizing |
| 07 | [Heaps & HeapSort](07-heaps-and-heapsort.md) | Binary Heaps & HeapSort | L5 | Complete binary trees, max-heap property, swim/sink operations, priority queue implementation, HeapSort (in-place, $N \log N$ worst case) |
| 08 | [Symbol Tables & BST](08-symbol-tables-and-bst.md) | Symbol Tables & Binary Search Trees | L6 | Key-value pair ADT, sequential search, binary search on arrays, BST operations (get, put, delete), ordered operations, Hibbard deletion |
| 09 | [Balanced Trees & Hash Tables](09-balanced-trees-and-hash-tables.md) | 2-3 Trees, Red-Black BSTs, Hash Tables | L7 | Guaranteed $\log N$ search via balanced trees; LLRB BST rotations and color flips; hashing with separate chaining and linear probing |
| 10 | [Undirected Graphs](10-undirected-graphs.md) | Undirected Graph Algorithms | L8 | Graph API, adjacency list/matrix, DFS (connectivity, paths), BFS (shortest paths), connected components |
| 11 | [Directed Graphs](11-directed-graphs.md) | Directed Graph Algorithms | L8 | Digraph API, directed DFS/BFS, topological sort, directed cycle detection, strongly connected components (Kosaraju-Sharir) |
| 12 | [Minimum Spanning Trees](12-minimum-spanning-trees.md) | MST Algorithms | L9 | Cut property, greedy algorithm, Kruskal's (Union-Find), Prim's (priority queue); $O(E \log E)$ performance |
| 13 | [Shortest Paths](13-shortest-paths.md) | Shortest Path Algorithms | L9 | Edge relaxation, Dijkstra (non-negative weights), DAG shortest paths (topological order), Bellman-Ford (negative weights, no negative cycles) |

---

## Suggested Revision Order

A logical progression through the material:

1. **Foundations** — Start with [02 Analysis](02-analysis-of-algorithms.md) to understand how we measure algorithm performance
2. **Union-Find** — [01 Union-Find](01-union-find.md) as a gentle introduction to algorithm design methodology
3. **ADTs** — [06 Abstract Data Types](06-abstract-data-types.md) for the vocabulary used throughout the course
4. **Sorting** — Work through [03 Elementary Sorts](03-elementary-sorts.md) → [04 MergeSort](04-mergesort.md) → [05 QuickSort](05-quicksort.md) → [07 Heaps & HeapSort](07-heaps-and-heapsort.md)
5. **Search** — [08 Symbol Tables & BST](08-symbol-tables-and-bst.md) → [09 Balanced Trees & Hash Tables](09-balanced-trees-and-hash-tables.md)
6. **Graphs** — [10 Undirected Graphs](10-undirected-graphs.md) → [11 Directed Graphs](11-directed-graphs.md) → [12 MST](12-minimum-spanning-trees.md) → [13 Shortest Paths](13-shortest-paths.md)

---

## Key Themes Across the Course

- **Algorithm design cycle**: model → design → analyse → iterate (introduced in Union-Find, applied everywhere)
- **Complexity analysis**: Big-O, Big-Ω, Big-Θ; worst/average/best case; amortised analysis
- **Data structure choice matters**: the same ADT can have vastly different performance depending on implementation
- **Trade-offs**: time vs space, simplicity vs performance, worst-case guarantees vs average-case speed
- **Divide and conquer**: MergeSort, QuickSort, binary search
- **Greedy algorithms**: Kruskal's, Prim's, Dijkstra's
- **Graph traversal**: DFS and BFS are foundational tools with many applications

---

## Quick Reference: Algorithm Complexities

### Sorting

| Algorithm | Best | Average | Worst | In-Place | Stable |
|-----------|------|---------|-------|----------|--------|
| Selection Sort | $\sim N^2/2$ | $\sim N^2/2$ | $\sim N^2/2$ | Yes | No |
| Insertion Sort | $\sim N$ | $\sim N^2/4$ | $\sim N^2/2$ | Yes | Yes |
| MergeSort | $\sim N \lg N$ | $\sim N \lg N$ | $\sim N \lg N$ | No | Yes |
| QuickSort | $\sim N \lg N$ | $\sim N \lg N$ | $\sim N^2/2$ | Yes | No |
| HeapSort | $\sim N \lg N$ | $\sim N \lg N$ | $\sim N \lg N$ | Yes | No |

### Symbol Table Implementations

| Implementation | Search (worst) | Insert (worst) | Search (avg) | Insert (avg) |
|----------------|---------------|----------------|-------------|-------------|
| Sequential search | $N$ | $N$ | $N/2$ | $N$ |
| Binary search (array) | $\lg N$ | $N$ | $\lg N$ | $N/2$ |
| BST | $N$ | $N$ | $c \lg N$ | $c \lg N$ |
| 2-3 Tree | $c \lg N$ | $c \lg N$ | $c \lg N$ | $c \lg N$ |
| LLRB BST | $2 \lg N$ | $2 \lg N$ | $1 \lg N$ | $1 \lg N$ |
| Hash (separate chaining) | $\lg N$ | $\lg N$ | $3$–$5$ | $3$–$5$ |
| Hash (linear probing) | $N$ | $N$ | $3$–$5$ | $3$–$5$ |

### Shortest Path Algorithms

| Algorithm | Restriction | Typical | Worst | Space |
|-----------|------------|---------|-------|-------|
| DAG (topological) | No cycles | $E + V$ | $E + V$ | $V$ |
| Dijkstra (binary heap) | No negative weights | $E \log V$ | $E \log V$ | $V$ |
| Bellman-Ford | No negative cycles | $EV$ | $EV$ | $V$ |
