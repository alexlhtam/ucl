## intro
a function is called higher-order if it takes a function as an argument or returns a function as a result.
```hs
twice :: (a -> a) -> a -> a
twice f x = f(f x)
```
- twice is higher-order because it takes a function as its first argument
- `common programming idioms` such as applying a function twice can be encapsulated as general purpose higher-order functions
- `special purpose languages` can be defined using higher-order functions, such as for list processing, interaction or parsing
- `algebraic properties` of higher-order functions can be used to reason about programs

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

<br>
a number of functions on lists can be defined using the simple pattern of recursion:

```hs
f [] = v
f (x:xs) = x + f xs
```
- f maps the empty list to a value $v$
- any non-empty list to a function $+$ applied to its head and $f$ of its tail

## `foldr`
- higher-order library function `foldr` ("fold right") encapsulates this pattern of recursion
- with function $+$ and value $v$ as args
`foldr` defined using recursion:

```hs
foldr (+) v [] = v
foldr (+) v (x:xs) = x + foldr(+) v xs
```
### example 1
```hs
sum [1, 2, 3]
= foldr (+) 0 [1, 2, 3]
= foldr (+) 0 (1:(2:(3:[])))
= 1 + (2 + (3 + 0))
= 6
-- replace each cons by + and [] by 0
```

### example 2: sum using foldr 
```hs
sum[1,2]
= foldr (+) 0 [1, 2]
= foldr (+) 0 (1 : (2 : []))
= 1 + (foldr (+) 0 (2 : []))
= 1 + (2 + (foldr (+) 0 []))
= 1 + (2 + 0)
= 3
```

## type of `foldr`
```hs
foldr :: (a -> b -> b) -> b -> [a] -> b
```

## combining
### sum of squares of positive integers in a list
```hs
-- using list comprehension
f :: [Int] -> Int
f xs = sum [x*x | x <-xs, x > 0]

-- using recursion
f :: [Int] -> Int
f[] = 0
f(x:xs) | x>0 = (x*x) + f xs
        | otherwise = f xs

-- higher order functions
f :: [Int] -> Int
f xs = foldr (+) 0 (map sqr (filter pos xs))
  where
    sqr x = x * x
    pos x = x > 0 
```