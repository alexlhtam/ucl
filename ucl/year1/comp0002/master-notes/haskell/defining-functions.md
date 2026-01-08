# intro
as in most programming languages, functions can be defined using conditional expressions
- conditional expressions can be nested
- functions can also be defined using guarded equations as an alternative to conditionals
  - guarded equations can be used to make definitions involving multiple conditions easier to read
  - catch all condition `otherwise` defined in the prelude by `otherwise = True`

# pattern matching
- many functions have a particularly clear definition using `pattern matching` on their arguments
```hs
not :: Bool -> Bool
not False = True
not True = False
```
- functions can often be defined in many different ways using pattern matching
```hs
(&&) :: Bool -> Bool -> Bool
True && True = True
True && False = False
False && True = False
False && False = False

-- can also be defined more compactly by:
True && True = True
_ && _ = False
```

# list patterns
- in haskell, every non-empty list is constructed by repeated use of the `:` "cons" operator that addes to the start of list
```hs
[1, 2, 3] = 1:(2:(3:[]))
```
- the `cons` operator can also be used in patterns, in which case it `destructs` a non-empty list
```hs
head :: [a] -> a
head (x:_) = x

tail :: [a] -> [a]
tail (_:xs) = xs
-- head and tail map any non-empty list to its first and remaining elements
```

# lambda expressions
- a function can be constructed without giving it a name by using a `lambda expression`
$ \lambda x \longrightarrow x + 1$ is the same as `\x -> x + 1`
  - the nameless function that takes a number $x$ and returns the value $x + 1$

## why are lambda's useful?
- can be used to give a meaning to functions defined using currying
```hs
add x y = x + y
```
- means $\text{add } = \lambda x \rightarrow (\lambda y \rightarrow x + y)$
- also useful when defining functions that return `functions as results`

## example 
- consider a function `safeTail` that behaves the same way as `tail`
  - however, it maps the empty list to the empty list, where `tail` gives an error


```hs
safeTail :: [a] -> [a]

-- using a conditional expression
safeTail xs = if null xs then [] else tail xs

-- using guard equations
safeTail xs | null xs = []
            | otherwise = tail xs

-- using pattern matching
safeTail [] = []
safeTail (x:xs) = xs
```
