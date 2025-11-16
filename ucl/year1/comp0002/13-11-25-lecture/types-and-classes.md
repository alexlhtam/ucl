# types and classes
## what is a type?
- a collection of related values
## types in haskell
- `e :: T` expression `e` will produce a value of type `T`
- every expression must have a valid type
  - calculated prior to evaluation using type inference
- haskell is type safe, type errors can never occur during compilation

## list type
- sequence of values of the same type
- type of a list says nothing about its length

## tuple type
- a sequence of values of possibly different types
- `(T1, T2, ..., TN)` means a `N-tuple`

## function types
- a mapping from values of one type to values of another type
- `not :: Bool -> Bool`
- `isDigit :: Char -> Bool`
- `T1 -> T2` is the type of functions htat map arguments of type `T1` to results of type `T2`
 
## curried functions
- functions with multiple arguments are possible by returning functions as results
- `add :; (Int, Int) -> Int` vs `add' :: Int -> (Int -> Int)`

## polymorphic types
- function `length` calculates the length of any list, irrespective of the type of its element

## overloaded types
- can be used with multiple types (but not any)