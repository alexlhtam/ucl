# haskell lists

## why haskell?
- generally, functional languages are good for web servers
- has features not all languages have:
  - static type system with type inference
  - type classes and type polymorphism
  - automated, random, property based testing
  - support for domain specific languages

### intro
- haskell lists are homogenous data structures
  - i.e. all elements must be the same type
- use `let` as a keyword to define a name in GHCi
  - writing `let a = 1` in GHCi is the same as writing a script containing `a = 1` and then running `:l`
```hs
GHCi> let lostNums = [4, 78, 5, 900]
GHCi> lostNums
[4, 78, 5, 900]
```

### concatenation
```hs
GHCi> [1, 2, 3, 4] ++ [7, 8, 9]
[1, 2, 3, 4, 7, 8, 9]

GHCi> "Hello" ++ "World!"
"Hello World!"
```

### cons `:`
- adds an element to the head of the list
```hs
GHCi> 'A' : " BIG MESS"
"A BIG MESS"

GHCi> 54 : [45, 69, 27]
[54, 45, 69, 27]
```
- `++` takes A PAIR OF LISTS of the same type
- `:` takes AN ELEMENT AND A LIST

### accessing list elements
- use the `!!` operator to get a list member by index number
- indicies start from 0
```hs
GHCi> "Claude Shannon" !! 10
"n" -- should be 'n'

GHCi> [3.4, 7.89, 9.4, 12.0] !! 3
12.0
```
- error message for out of range access

### lists inside lists
```hs
GHCi> let z = [[1, 2, 3, 4], [5, 3, 3, 3], [1, 2, 2, 2, 3, 4], [1, 2, 3]]
GHCi> z
[[1, 2, 3, 4], [5, 3, 3, 3], [1, 2, 2, 2, 3, 4], [1, 2, 3]]

GHCi> z ++ [[99]] -- needs to be same LIST TYPE, so nested list
[[1, 2, 3, 4], [5, 3, 3, 3], [1, 2, 2, 2, 3, 4], [1, 2, 3], [99]]

GHCi> [6, 6] : z -- needs to be the same ELEMENT TYPE
[[6, 6], [1, 2, 3, 4], [5, 3, 3, 3], [1, 2, 2, 2, 3, 4], [1, 2, 3], [99]]

GHCi> z !! 3
[1, 2, 3]
```

### list comparison
- lists can be compared if the elements within can be compared
- compared in lexicographical order using `<`, `>`, `<=`, `>=`
- nonempty lists considered GREATER than an empty one

### ranges with lists
```hs
GHCi> [1..10]
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

GHCi> ["m".."q"] -- should be `m`
"mnopq"

GHCi> ["A".."J"] -- should be `A`
"ABCDEFGHIJ"
```

### steps and ranges
```hs
GHCi> [2,4..10]
[2, 4, 6, 8, 10]

GHCi> [3,6..30]
[3, 6, 9, 12, 15, 18, 21, 24, 27, 30]

GHCi> [20..1]
[]

GHCi> [20,19..1] -- needs step to indicate going down
[20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
```

### laziness and infinite lists
```hs
GHCi> take 11 [13,26..] -- take 11 elements from the infinte list of [13, 26..]
[13, 26, 39, 52, 65, 78, 91, 104, 117, 130, 143]
-- cycle
GHCi> take 5 (cycle[4, 3, 2])
[4, 3, 2, 4, 3]
-- repeat
GHCi> take 6 (repeat 7)
[7, 7, 7, 7, 7, 7]
-- replicate
GHCi> replicate 5 'a'
"aaaaa"

-- floating point numbers have FINITE PRECISION
GHCi> [0.1, 0.3..1]
[0.1, 0.3, 0.5, 0.7, 0.89999999999, 1.0999999999]
```

### list comprehension
- similar to set comprehension in maths, e.g. {$ 2 \cdot x \text{ | } x > 0 \text{ and } x \in \Z$}
```hs
GHCi> [x * 2 | x <-[1..10]]
[2, 4, 6, 8, 10, 12, 14, 16, 18, 20]

GHCi> [x * 2 | x <= [1..10], x * 2 >= 12]
[12, 14, 16, 18, 20]

GHCi> [x | x <- [50..100], x mod 7 == 5]
[54, 61, 68, 75, 82, 89, 96]
```

```hs
-- add to file, :l
length' xs = sum[1 | _ <- xs]
GHCi> length' "David"
5

-- add to file, :l
keepLowerCase st = [c | c <- st, c elem ["a".."z"]] -- should be 'a','z'
GHCi> keepLowerCase "David"
"avid"

GHCi> keepLowerCase "David + 12345"
"avid"
```

### nested list comprehension
```hs
-- ad to file, :l
xxs = [[1, 3, 5, 7, 8, 7, 6, 2], [2, 3, 4, 5, 6, 1], [12, 6, 7, 8, 9, 4, 6, 77]]
GHCi> [ [x | x <- xs, even x] | xs <- xxs]
[[8, 6, 2], [2, 4, 6], [12, 6, 8, 4, 6]]
```

# haskell tuples
- lists only have homogenous elements
- tuples can have heterogenous elements
- lists have flexible size, they can grow and shrink
- tuples have a fixed size
```hs
GHCi> (1, 10)
(1, 10)

GHCi> ("Hi", "a", 72, 1.01) -- should be 'a'
("Hi", "a", 72, 1.01)
```
- use of tuples enforces a type discipline, which extends to within the tuples

## zip
```hs
GHCi> zip [1,3,5,7,9] [‘a’,’b’,’c’,’j’,’k’]
[(1,'a’),(3,’b’),(5,’c’),(7,’j’),(9,’k’)]

GHCi> zip [5,3,4,2,6,7,8,9,0,1,2,3] [5,6,7]
[(5,5),(3,6),(4,7)]

GHCi>  zip [10..] [5,6,7]
[(10,5),(11,6),(12,7)]
```