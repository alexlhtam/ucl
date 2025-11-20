# haskell lists

## why haskell?
- generally, functional languages are good for web servers
- has features not all languages have:
  - static type system with type inference
  - type classes and type polymorphism
  - automated, random, property based testing
  - support for domain specific languages

## lists 

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