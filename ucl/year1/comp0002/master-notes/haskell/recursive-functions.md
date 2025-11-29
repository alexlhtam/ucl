# intro
- many functions can naturally be defined in terms of other functions
```hs
factorial :: Int -> Int
factorial n = product[1..n]
```
- expressions are evaluated by a stepwise process of applying functions to their arguments

# recursive functions
- functions can also be defined in terms of themselves
```hs
factorial 0 = 1
factorial n = n * factorial (n - 1)
```
- recursion is not restricted to numbers, but can also be used to define functions on lists
```hs
product :: [Int] -> Int
product [] = 1
product(x:xs) = x * product xs
```

# quicksort
- quicksort for sorting a list of integers can be specified by the following rules:
  - empty list is already sorted
  - non-empty lists can be sorted by sorting the tail values $\leq$ the head, soriting the tail values $\geq$ the head, and then appending resulting lists on either side of the head value
- using recursion, this can be directly translated into an implementation
```hs
qsort :: [Int] -> [Int]
qsort [] = []
qsort (x:xs) = qsort[a | a <- xs, a <= x]
              ++ [x] ++
              qsort[b | b <- xs, b > x]
```

# exercise
```hs
-- define a recursive function 
insert :: Int -> [Int] -> [Int]
--that inserts an integer to the correct position of a sorted list of Integers
insert x [] = [x]
insert x (y: ys)
    | x <= x : y : ys
    | otherwise = y : insert x ys
```