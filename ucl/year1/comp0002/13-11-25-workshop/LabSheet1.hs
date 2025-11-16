import Data.Char

square :: Int -> Int
square x = x * x

pyth :: Int -> Int -> Int
pyth a b = square a + square b

isTriple :: Int -> Int -> Int -> Bool
isTriple a b c = pyth a b == square c

isTripleAny :: Int -> Int -> Int -> Bool
isTripleAny a b c = (isTriple a b c) ||
                    (isTriple c a b) ||
                    (isTriple b c a )

halfEvens ::  [Int] -> [Int]
halfEvens xs = [if x `mod` 2 == 0 then x `div` 2 else x | x <- xs]

inRange :: Int -> Int -> [Int] -> [Int]
inRange lower upper xs = [x | x <- xs, x >= lower, x <= upper]

countPositives :: [Int] -> Int
countPositives xs = length [ x | x <- xs, x > 0]


capitalised :: String -> String
capitalised "" = ""
capitalised (x:xs) = newHead : newTail
    where
        newHead = toUpper x
        newTail = [ toLower c | c <- xs ]

-- title :: [String] -> [String]