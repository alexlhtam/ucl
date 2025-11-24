# haskell types
- a type is a collection of related values
- all functions that map a logical value to a logical value
  
## types in haskell
- use the notation `e::T`
  - expression `e`
  - will produce a value of type `T`
- every expression must have a valid type
  - calculated prior to expression evalutaion using `type inference`
- haskell programs are `type safe`, as type errors can never occur during evaluation

## function types
- a mapping from values of one type ot values of another type
```hs
not :: Bool -> Bool

isDigit :: Char -> Bool
```
- the argument and result types are unrestricted
- functions with multiple arguments or results are possible using lists or tuples

# curried functions
- functions with multiple arguments are also possible by returning functions as results:
```hs
add' :: Int -> (Int -> Int)
add' x y = x + y
```
- `add'` takes an integer `x` and returns a function
  - in turn, this function takes an integer `y` and returns the result `x + y`

```hs
add :: (Int, Int) -> Int 

add' :: Int -> (Int -> Int)
```
- `add` and `add'` produce the same final result
  - `add` takes two arguments at the same time
  - `add'` takes them one at the time
    - functions that take their arguments one at a time are called `curried functions`


## curry conventions

- functions with more than two arguments can be curried by returning nested functions:
```hs
mult :: Int -> (Int -> (Int -> Int))
mult x y z = x * y * z
```

- to avoid excess parentheses when using curried functions, two simple conventions are adopted:
  - arrow `->` associates to the `right`
  - as a consequence, it is natural for function application to associate to the left
  ```hs
    mult x y z = ((mult x ) y ) z
  ```
- unless tupling is explicitly required, all functions in Haskell are normally defined in curried form

# polymorphic types
- function `length` calculates the length of any list, regardless of type
  - this idea is made precise in the type for length by the inclusion of a type variable
```hs
length :: [a] -> Int
-- take a list of type a and return an integer
```
- a type with variables is called `polymorphic`

# overloaded types
- arithmetic operator `+` calculates the sum of any two numbers of the same generic type
- idea is made precis in the type for `+` by the inclusion of a class constraint
```hs
(+) :: Num a => a -> a -> a
```
- a type with constraints is called overloaded

# classes 
- a collection of types that support certain operations, called the `methods` of the class
## haskell basic classes

### Eq
- equality types
### Ord
- ordered types
- 