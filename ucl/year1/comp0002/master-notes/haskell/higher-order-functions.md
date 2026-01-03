a function is called higher-order if it takes a function as an argument or returns a function as a result.
```hs
twice :: (a -> a) -> a -> a
twice f x = f(f x)
```
- twice is higher-order because it takes a function as its first argument
- `common programming idioms` such as applying a function twice can be encapsulated as general purpose higher-order functions
- `special purpose languages` can be defined using higher-order functions, such as for list processing, interaction or parsing
- `algebraic properties` of higher=order functions can be used to reason about programs

## `map`
the higher-order function called `map` applies a function to every element of a list
```hs
map :: (a -> b) -> [a] -> [b]
```
the map function can be defined using list comprehension:
```hs
map f xs = [fx | x <- xs]
```
or using recursion:
```hs
map f [] = []
map f (x:xs) = f x : map f xs
```

## `filter`
the higher-order library `filter` selects every element from a list that satisfies a predicate
```hs
filter :: (a -> Bool) -> [a] -> [a]
```
can be defined using list comprehension:
```hs
filter p xs = [x | x <- xs, p x]
```
or using recursion:
```hs
filter p [] = []
filter p (x:xs)
  | p x = x : filter p xs
```