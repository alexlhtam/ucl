# Java arrays
- Java supports arrays with some similarities to C, but also some important differences
- most of the time ew use class=based structures such as ArrayList instead of arrays 

# array data structure (reminder)
- an array is a data structure
- array properties:
  - array is a sequence of values
    - a sequence data structure
  - can be accessed in sequential order
    - start at first value and work through each value, giving $O(n)$ performance
  - or, randomly access any element as needed 
    - random access with $O(1)$ performance
    - what makes arrays most useful

# Java v C
- Java uses square bracket syntax for arrays
- arrays are still fixed length, holds values of one type
- no pointers in Java
- arrays are accessed only using square bracket syntax
  - no pointer arithmetic
  - no dereference(`*`) or address-of (`&`) operators

# reminder - creating an array
```java
int[] myArray = new int[6];
// type array of int
// create an array of 6 ints
```
- declare the variable
- create the array
- note where the square brackets are positioned

# using indexing
- we can fetch the value of an array element
```java
int n = myArray[2];
```
- or we can assign to an array element
```java
myArray[3] = 10;
```

# length v index
```java
int[] myArray = new int[6];
```
- this gives 6 elements indexed from 0 to 5
- attempting to access an element with index >5 or <0 results in an ArrayBoundsException

# length 0
- you can create an array of length 0 
```java
int[] emptyIntArray = new int[0];
```
- an empty array object is created
- why?
  - an empty array is still an array and can be iterated over (empty iteration)
  - a method computing/finding values can return an empty array if no values are computed/found
  - avoid returning null
  - the `varargs` mechanism - passing a variable number of arguments to a method
  - in C, zero length arrays are not allowed

# initialisation
```java
int[] anArray = new int[10];
```
- the variable `anArray` is initialised
- initialised to default values, (0, 0.0, `null` for references)
- a null reference is one that does not reference an object
  - refers to nowhere, cannot be used to call methods

# initialising array elements
- either write a loop and assign to each element, 
- or use an array initialisation expression:
```java
int[] array = {1, 2, 3, 4, 5};
// OR
int[] array = new int[]{1, 2,3, 4, 5};
```

# iterating an array
- the `old` for loop:
```java
int[] a = new int[100];
int sum = 0;
for (int n = 0; n < a.length; n++) {
    sum += a[n];
}
```

- enhanced for loop:
```java
for (int n : a) {
    sum += n;
}
```
- no counter or index needed
- iterator abstraction

# iterating an array using a Stream
```java
int sum = Arrays.stream(a).sum();
```
- arrays is a utility class providing methods to manipulate arrays
  - check the Javadocs
  - do not need to write all methods ourselves
- a stream is a sequence of valeus that 'flows' through one or more transformation stages
  - values are pulled through from the end, not pushed through from the start
  - Streams are lazy
- `stream(a)` creates an `IntStream` using array content
  - see Javadocs for `IntStream`
- `sum()` reduces the stream to a single value
  - a terminal operation ending the stream (consumer)
  - pulls the value through the stream
- using `IntStream.range`:
```java
var sum = IntStream.range(0, a.length)
map(i -> a[i]).sum();
```
- `range` creates a `IntStream` for the range of array index values (in this case the entire array)
  - the index values (0, 1, 2) not the array elements
- `map` applies an operation to each value in the stream - mapping from index value to element
  - and passes each value on in the stream
- `i -> a[i]` is a lambda, anonymous function `(int -> Int)`
  - Java supports lambda expressions (automatically represented using anonymous classes and objects internally)
- does use indexing, but in a more managed way

```java
int sum = Arrays.stream(a).mapToInt(Integer :: intValue).sum()
```
- not using indexing, does use `Integer` objects
- `Integer :: intValue` is a method reference
- the stream `int` values are mapped to `Integer` objects using the `intValue` method
- `mapToInt` returns an `IntStream` over the `Integer` values
- `sum()` then sums the `Integer` object values and returns an `int`

# iterating an array (2)
- use recursion
```java
public static int sumArray(int[] a, int length) {
    if (length <= 0) return 0; // base case
    return sumArray(a, length - 1) + a[length - 1]; // recursive case
}
```
- a length parameter is needed, as the array is not sliced
  - Java does not support array slicing like Python
  - the array indexing expression takes into account that indexing starts from zero

# stream for a 2D array
```java
int sum = Arrays.stream(twoD)
            .flatMapToInt(Arrays :: stream)
            .sum();
```
- `Arrays.stream(twoD)` is a `Stream<int[]>` (a stream of rows)
- for each row (an `int[]`), `Arrays.stream(row)` is an `IntStream` (a stream of the `int`s in that row)
- `flatMapToInt(Arrays :: stream)` takes all the per-row `IntStreams` and joins them into a single `IntStream` of every `int`, in row order
- then `.sum()` adds them
- equivalent to:
```java
Stream<int[]> rows = Arrays.stream(twoD);
IntStream allNumbers = row.flatMapToInt(row -> Arrays.stream(row));
int sum = allNumbers.sum();
```
- flatten rows into one stream of `int`s

# iteration v `Stream`
- Streams are the `functional` style, now widely used in Java
- style: imperative v declarative
- control vs intent: how to iterate vs what transformation/aggregation to apply
- state and side effects: mutable variables and side effects v stateless operations and minimal side effects
- errors & safety: off-by-one/index mistakes v no indexing or bounds issues
- performance and parallelism: more predictable and often faster, sequential v more overheads, more easily parallelisable

# ragged array
- different length rows, to avoid wasting space
- column array has type `int[][]`
- row has type `int[]`

# 2D iteration (4) streams
```java
int sum = Arrays.stream(twoD)
            .flatMapToInt(Arrays::stream)
            .sum();
```
- `flatMapToInt` 'flattens' an array of arrays to a `stream` of `int`
  - each element goes into the stream
- works with rectangular and ragged arrays

# arrays summary
- arrays allow collections of values to be stored and accessed via a single variable
- square bracket syntax is used
- loops are used to work with arrays
- arrays are really objects
- a 2D array is an array of arrays
- use Java container classes in preference to arrays whenever possible