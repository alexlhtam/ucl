# Arrays

## 1) Key properties
- Arrays are fixed-length, same-type sequences.
- Random access is `O(1)` via index; full traversal is `O(n)`.
- Arrays in Java are objects (with bounds checks), unlike C-style raw memory arrays.

## 2) Creation and indexing
```java
int[] a = new int[6]; // indexes 0..5
int x = a[2];
a[3] = 10;
```
- Invalid index access throws `ArrayIndexOutOfBoundsException`.
- Zero-length arrays are valid and often better than returning `null`.

## 3) Initialization
```java
int[] nums1 = {1, 2, 3, 4, 5};
int[] nums2 = new int[] {1, 2, 3, 4, 5};
```
- Default element values: numeric `0/0.0`, `false`, or `null` for references.

## 4) Iteration styles
- Index loop (need position):
```java
for (int i = 0; i < a.length; i++) { ... }
```
- Enhanced for loop (need values only):
```java
for (int n : a) { ... }
```
- Streams (declarative transformations):
```java
int sum = Arrays.stream(a).sum();
```

## 5) Streams on arrays (a bit more)
- Typical pipeline: **source -> intermediate ops -> terminal op**.
- Intermediate ops (`map`, `filter`, `sorted`) are lazy; terminal ops (`sum`, `count`, `toArray`) trigger execution.
- Prefer primitive streams (`IntStream`, `DoubleStream`) for numeric arrays to avoid boxing overhead.

```java
int[] a = {1, 2, 3, 4, 5, 6};

int evenSum = Arrays.stream(a)
    .filter(n -> n % 2 == 0)
    .map(n -> n * 10)
    .sum();                 // terminal op

long count = Arrays.stream(a)
    .filter(n -> n > 3)
    .count();               // terminal op
```

- If you need indexes, use `IntStream.range`:

```java
int[] a = {10, 20, 30};
int weighted = IntStream.range(0, a.length)
    .map(i -> i * a[i])     // uses index + value
    .sum();
```

- For object arrays:
```java
String[] names = {"alex", "sam", "mia"};
String[] upper = Arrays.stream(names)
    .map(String::toUpperCase)
    .toArray(String[]::new);
```

- Rule of thumb:
  - Use loops when logic is very stateful/branch-heavy.
  - Use streams when expressing clear transformations/aggregations.

## 6) 2D arrays and ragged arrays
- `int[][]` is an array of `int[]`.
- Rows can have different lengths (ragged arrays).
- Stream flattening:
```java
int sum = Arrays.stream(twoD)
    .flatMapToInt(Arrays::stream)
    .sum();
```

## 7) Arrays vs collections
- Use arrays for fixed-size, performance-critical, low-level data layouts.
- Prefer `ArrayList`/collections for most app code (resizable, richer API, generics-friendly).

## Important Summary
- Arrays are simple and fast, but fixed size and less expressive.
- Most practical Java code prefers collections, but array fundamentals are still essential.
- Avoid index bugs: use enhanced for/streams when index is not needed.