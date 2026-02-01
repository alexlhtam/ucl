# elementary sorts


## selection sort

### key idea
- scan array `a` from left to right
- on iteration `i`, find the index `min` of the smallest remaining entry in the array
- swap `a[i]` and `a[min]`
<br>

- outer loop invariants
  - entries to the left of `i` are fixed and sorted
  - no entry to the right of `i` (including `i`)  is smaller than any entry to the left of `i`
- to maintain invariants:
  - scan left to right
    - `i++`
  - identify index of min entry to the right
    ```java
    min i = 1;
    for (j = i + 1; j < N; j++)
        if (a[j] < a[min]) min = j
    ```
  - exchange into position
    ```java
    swap(a[i], a[min])
    ```

### complexity analysis
- number of compares: $(N-1) + (N-2) + \dots + 1 + 0 = \frac{N^2}{2}$
- number of exchanges: $N$
- $\Omega(N^2) = \Theta(N^2) = O(N^2)$

## insertion sort

### key idea
- scan array `a` from left to right
- in iteration `i`, swap `a[i]` with each larger entry to its left
<br>

- outer loop invariants
  - entry to the left of `i` are in ascending order
  - entries to the right of `i` are yet to be seen
- to maintain invariants:
  - scan left to right
    - `i++`
  - moving from right ot left, exchange `a[i]` with each larger entry to its left
  ```java
  for (j = i; j > 0; j--) 
    if (a[j] < a[j-1]) 
        swap(a[j], a[j-1])
  ```
  - inner loop invariant:
    - every item from `a[0]` to `a[i]` is in ascending order, except for possibly `a[j]`
    - every item from `a[j+1]` is greater than `a[j]`
  - useful optimisation: break out of loop in else branch when `a[j] >= a[j-1]`

### complexity analysis
- number of comparisons (on average): $\sim \frac{1}{4}N^2$
- number of exchanges (on average): $\sim \frac{1}{4}N^2$
<br>
- best case (already sorted array): $N-1$ compares, $0$ exchanges
- worst case (array in reverse order): $\sim\frac{1}{2} N^2$ comparisons, $\sim\frac{1}{2} N^2$ exchanges
<br>
- $\Omega(N)$
- $\Theta(N^2)$
- $O(N^2)$

# merge sort

## key idea: divide and conquer
- divide an array into two halves (split the problem)
- sort each half separately (solve smaller instances of the problem)
- merge the two halves (recombine the solutions of the smaller problem into the solution of the larger problem)

## example: merge step
- given two sorted sub-arrays `a[lo]` to `a[mid]` and `a[mid+1]` to `a[hi]`, compute sorted sub-array `a[lo]` to `a[hi]`

## pseudocode: merge step
- pre-condition: `a[lo, mid]` is sorted
- pre-condition: `a[mid+1, hi]` is sorted
```java
merge(a[], aux[], lo, mid, hi):
    for (k = lo; k <= hi; k++) aux[k] = a[k];

    i = lo;
    j = mid + 1;

    for (k = lo; k <= hi; k++)
        if (i > mid)               a[k] = aux[j]; j++;
        else if (j > hi)           a[k] = aux[i]; i++;
        else if (aux[j] < aux[i)   a[k] = aux[j]; j++;
```
- postcondition: `a[lo, hi]` is sorted

## pseudocode: divide and sort steps
```java
sort(a[], aux[], lo, hi):
    if (hi <= lo) return;

    mid = lo + (hi - lo) / 2;

    sort(a, aux, lo, mid);
    sort (a, aux, mid+1, hi);
    merge(a, aux, lo, mid, hi);
```

## additional notes
- stop if already sorted:
```java
sort(a[], aux[], lo, hi):
    if (hi <= lo) return;

    mid = lo + (hi - lo) / 2;

    sort(a, aux, lo, mid);
    sort (a, aux, mid+1, hi);
    if (a[mid] <= a[mid+1]) return; // add this line!
    merge(a, aux, lo, mid, hi);
```
- avoid copying to the auxiliary array

## analysis
- merge sort is an optimal algorithm in terms of number of operations, since its cost ($\sim N\log N$) is a proven limit (lower bound) for all comparison-based sorting algorithms
- memory: merge sort uses extra space proportional to $N$
- a sorting algorithm is in-place if it uses $\leq c \log N$ extra memory
  - selection, insertion sort are in-place sorting algorithms
- a sorting algorithm is said to be stable if two items with equal keys appear in the same order in the sorted output as they appear in the input array
  - stable sorts: insertion and merge
  - non-stable sorts: selection