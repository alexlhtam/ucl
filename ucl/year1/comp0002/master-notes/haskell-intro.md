# intro to haskell

## intro
- not a state-based language
- uses functions to perform calculations
  - write a function
  - apply it to some data (input)
  - get some result (output)
  - no state update, no state, no variables, no loops, just functions

```haskell
swap: (Int, Int) -> (Int, Int)
swap(x, y) = swap(y, x)
```
## glasgwow haskell compiler (ghc)
- has both an interpreter and a compiler
- write simple things at the command line
- compile larger programs
- mix these up!

## unique haskell features
- static type system with type inference
- type classes and type polymorphism
- automated, random, property based testing
- support for domain specific languages

## lists
- homogenous data structures
  - all elements must be same type
- use let as keyword to define a name in GHCi
```haskell
let a = 1
```
- same as writing a script containing `let a = 1` and loading it using `.l`
- strings are lists of characters and we can use list functions on strings

### : cons op
- element on the left must be a single element
```haskell
54 : [45, 69, 27] 
-- gives
[54, 45, 69, 27]
```

### ++ append op
```haskell
[45, 69, 27] ++ 54
-- gives
[45, 69, 27, 54]
```

### accessing list elements
- use the `!!` operator

### list comparisons
- `<`, `>`, `<=`, `>=` for lexicogrphical comparisons
- nonempty lists considered GREATER than empty ones

## using ranges with lists
```haskell
[1..5]
-- gives
[1, 2, 3, 4, 5]

[2, 4..10]
-- gives
[2, 4, 6, 8, 10]

-- infinite lists + laziness
take 11 [13, 26..]
-- give size of the HEAD, (first 11)
-- then give it the infinite list
```
### list comprehension
```haskell
[x * 2 | x <- [1..10]]
-- gives
[2, 4, 6, 8, 10, 12, 14, 16, 18, 20]

[x * 2 | x <- [1..10], x * 2 >= 12]
-- gives
[12, 14, 16, 18, 20]

-- RHS of the '|' can be thought as a list of filters that apply
```

## tuples
- lists only have homogeneous elements
- tuples can have heterogeneous elements
- lists have a flexible size
- tuples have a fixed size