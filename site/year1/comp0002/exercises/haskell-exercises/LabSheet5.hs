-- consider the factorial function fac:
-- pre : n >= 0
-- post fac n = n!
-- write a definition for fac. 
-- find the variant and use simple induction to show that the function definition is correct.
    fac :: Int -> Int
    fac 0 = 1
    fac n = n * fac (n - 1)
    -- variant: n

-- Consider the Fibonacci function fib:
-- pre: n >= 0
-- post fib n = fibonacci(n)
-- where fibonacci(n) is the nth fibonacci number
-- Write a definition for fib. Find the variant and use course of values 
-- induction to show that the function definition is correct.
    fib :: Int -> Int
    fib 0 = 0
    fib 1 = 1
    fib n = fib(n-2) + fib (n-1)
    -- variant: n 

    -- goal: prove fib n = F_n for all n >= 0
    -- base cases:
        -- n = 0: fib 0 = 0, which matches F_0
        -- n = 1: fib 1 = 1, which matches F_1
    -- inductive step: let n >= 2
        -- IH: assume fib j = F_j for all 0 <= j < n
    -- proof:
        -- fib n = fib (n - 2) + fib(n - 1) (code definition)
        --       = F_(n-2) + F_(n-1)        (by IH since n - 2 < n and n -1 < n)
        --       = F_n                      (mathematical definition)
    -- conclusion:
        -- since the base cases hold and the inductive step holds, 
        -- the function is correct for all n

-- Consider the list function reverse
-- Write a definition for reverse and prove that your definition is correct
-- pre: True
-- post: reverse xs = reversed xs (i.e. list xs is successfully reversed)
    myReverse :: [a] -> [a]
    myReverse [] = []
    myReverse (x:xs) =  myReverse xs ++ [x]

    -- base case:
        -- myReverse [] = reversed [] (reversing an empty list returns an empty list)
    -- inductive step:
        -- [IH]: myReverse (xs) = reversed (xs); assume list is correctly reversed []
    -- proof:
        -- reverse(x:xs) = reverse xs ++ [x]
        -- applying [IH], we get reverse(x:xs) = reversed xs ++ [x]
        -- mathematically, reversing a list is defined as taking the tail reversed (reversed xs) and applying the head at the end