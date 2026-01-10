# testing properties

## some properties of reverse

```hs
reverse :: [a] -> [a]
reverse [] = []
reverse (x:xs) = (reverse xs) ++ [x]

-- begin maths
reverse [x] = [x]
reverse (xs ++ ys) = reverse ys ++ reverse xs
reverse (reverse xs) = xs
-- end maths
```

## haskell predicates
```hs
prop_RevUnit x =
    reverse [x] == [x]
proper_RevApp xs ys =
    reverse (xs ++ ys) == (reverse ys) ++ (reverse xs)
prop_RevRev xs =
    reverse (reverse xs) == xs
```

## QuickCheck properties
```hs
import Test.QuickCheck

square :: Integer -> INteger
square x = x * x

pyth :: Integer -> Integer -> Integer
pyth a b = square a + square b

prop_square :: Integer -> Bool
prop_square x = 
    square x >= 0

prop_squares :: Integer > Integer -> Bool
prop_squares x y =
    square (x+y) == square x + square y + 2*x*y

prop_pyth :: Integer -> Integer -> Bool
prop_pyth x y =
    square (x+y) == pyth x y + 2*x*y
```

# proving properties

## correctness
- pre condition: logical statement that holds on the data to which the function is applied
- post condition: logical that holds on the data after the function has been applied
- given that the pre condition holds we show that the function established the post condition
<br>
<br>
- for recursive functions we can use induction on the definition of the function to prove that the function has a property
  - if the data used by the function is recursive, the induction on the structure of the data to show that function has the property

### examples
```hs
-- pre condition x, y >= 0
-- post condition mult x y = x * y

mult :: Int -> Int -> Int
mult x 0 = 0
mult x y | y % 2 == 0 = 2 * mult x (y `div` 2)
         | otherwise = x + 2 mult x (y `div` 2)
```

```hs
-- pre condition n > 0 
-- post condition sumTo n = sum (1 to n)
sumTo :: Int -> Int
sumTo 1 = 1
sumTo n = n + sumTo n - 1
```
### correctness for recursive functions
- recursive functions are shown correct by demonstrating two things:
    1. a recursive variant exists
    2. a proof by induction that the function establishes the post condition
    the recursive variant is a non negative expression: 
        using the input parameters which gets "smaller" each time the function is called the function is called

## termination
the meaning of "smaller" will usually depend on the context

example of variants:
- for sumTo the variant is just x 
- for mult the variant is just y 

the idea is that the variant gets smaller until the base case is reached and the call terminates

## using induction
there are two equivalent forms of mathematical induction:

> simple induction
> to show a property $P$ holds on all natural numbers:
> show the base case: $P(0)$
> then show the inductive step: if we have proof for $P(n-1)$, we can prove $P(n)$


> course of values induction:
> to show a property $P$ holds on a set of natural numbers
> show that if we know $P(m)$ for every $m < n$, we can show $P(n)$

## simple induction correctness example: `sumTo`
simple induction: show `sumTo` n = sum (1 up to n)
<u>basis</u> $n = 1$: `sumTo(1)` = 1 = `sum`(1 up to 1)
<u>induction</u> assume `sumTo(n-1)` = `sum`(1 to n-1) [IH]

$$
\begin{align*}
\text{sumTo}(n) &= n + \text{sumTo}(n-1) && [\text{defn. of sumTo}] \\
                &= n + \text{sum}(1 \dots n-1) && [\text{I.H.}] \\
                &= \text{sum}(1 \dots n) && [\text{def. of sum}(1 \dots n)]
\end{align*}
$$
- we can conclude the function works correctly for every integer bigger or equal to 1

## course of values induction example: `mult`
```hs
-- pre condition x, y >= 0
-- post condition mult x y = x * y

mult :: Int -> Int -> Int
mult x 0 = 0
mult x y | (y `mod` 2 == 0) = 2 * mult x (y `div` 2)
         | otherwise    = x + 2 * mult x (y `div` 2)
```
$$
\begin{align*}
\text{[IH] Assume } \text{mult}(x, m) = x \times m \quad \forall m < N, N \geq 0 \\[1em]
\textbf{Case 1: } N \text{ is even } (N \% 2 = 0) \\
\text{mult}(x, N) &= 2 \times \text{mult}(x, N/2) \\
                  &= 2 \times (x \times N/2) && [\text{by IH}] \\
                  &= x \times N && \checkmark \\[1em]
\textbf{Case 2: } N \text{ is odd } (N \% 2 = 1) \\
\text{mult}(x, N) &= x + 2 \times \text{mult}(x, N \text{ div } 2) \\
                  &= x + 2 \times \text{mult}(x, (N-1)/2) \\
                  &= x + 2 \times (x \times \frac{N-1}{2}) && [\text{by IH}] \\
                  &= x + x(N-1) \\
                  &= x + xN - x \\
                  &= x \times N && \checkmark
\end{align*}
$$

# tail & non-tail recursion
recursive functions can be distinguished either as:
- tail recursive
- non-tail recursive

a tail recursive function has an inductive step that calls the function directly on a "smaller" value (the tail)
non tail recursive functions do some computation with the recursive call
  - `remainder`: tail recursive
  - `mult`: non tail recursive
  - `sumTo`: non tail recursive

tail recursion has a computational advantage:
  - do the same computation, but with different arguments
  - it is useful to be able to transform a non tail recursive procedure into a tail recursive one

## accumulators
- an accumulator is a parameter of a recursive function that accumulates the answer as the function recurses towards the base case
- in general, the accumulator gets bigger as the variant gets smaller
```hs
-- pre: x >= 1, acc >.= 0
-- post: tailSumTo x acc = sum (1 to x) + acc

tailSumTo: Int -> Int -> Int
tailSumTo 1 acc = 1 + acc
tailSumTo x acc = tailSumTo(x - 1) (x + acc) 
```


$$
\begin{align*}
\textbf{Base case: } \text{tailSumTo } 1 \ n &= 1 + n && [\text{defn. tailSumTo}] \\
&= \text{sum}(1 \text{ to } 1) + n && [\text{defn. sum}(1 \text{ to } x)] \\[1em]

\textbf{IH: } \text{tailSumTo } (k-1) \ \text{acc} &= \text{sum}(1 \text{ to } k-1) + \text{acc} \\[1em]

\color{red}{\text{Show tailSumTo } k \ \text{acc} = \text{sum}(1 \text{ to } k) + \text{acc}} \\[1em]

\text{tailSumTo } k \ \text{acc} &= \text{tailSumTo } (k-1) \ (k + \text{acc}) && [\text{defn. tailSumTo}] \\
&= \text{sum}(1 \text{ to } k-1) + (k + \text{acc}) && [\text{I.H.}] \\
&= \text{sum}(1 \text{ to } k) + \text{acc} && [\text{defn. sum}(1 \text{ to } x)]
\end{align*}
$$