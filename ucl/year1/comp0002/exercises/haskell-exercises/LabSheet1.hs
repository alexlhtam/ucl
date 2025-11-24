import Data.Char

square :: Int -> Int
square x = x * x

pyth :: Int -> Int -> Int
pyth x y = square x + square y

isTriple :: Int -> Int -> Int -> Bool
isTriple x y z = pyth x y == square z

isTripleAny :: Int -> Int -> Int -> Bool
isTripleAny x y z = isTriple x y z ||
                    isTriple y z x || 
                    isTriple z x y

halfEvens :: [Int] -> [Int]
halfEvens xs = [if x `mod` 2 == 1 then x else x `div` 2 | x <- xs ]

countPositives :: [Int] -> Int
countPositives xs = length [x | x <- xs, x > 0]

capitalised :: String -> String
capitalised [] = []
capitalised (x:xs) = toUpper x : [toLower c | c <- xs]

lowercase :: String -> String
lowercase xs = [toLower x | x <- xs]

title :: [String] -> [String]
title [] = []
title (x:xs) = capitalised x : [processWord w | w <- xs]
  where 
    processWord w
      | length w >= 4 = capitalised w
      | otherwise     = lowercase w