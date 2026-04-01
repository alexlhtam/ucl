mult :: Num a => [a] -> a
-- mult xs = foldr (*) 1 xs
mult = foldr (*) 1

posList :: [Int] -> [Int]
posList = filter (\x -> x > 0)

trueList :: [Bool] -> Bool
-- trueList xs = length xs == length (filter id xs)
trueList = foldr (&&) True

evenList :: [Int] -> Bool
evenList xs = foldr (&&) True (map even xs)
-- evenList = foldr ((&&) . even) True

maxList :: (Ord a) => [a] -> a
maxList = foldr1 max
-- maxList xs = foldr max (head xs) xs

inRange :: Int -> Int -> [Int] -> [Int]
inRange low high lst = filter (\x -> x >= low && x <= high) lst
-- lst can also be removed from both sides

countPositives :: [Int] -> Int
countPositives = foldr (\x acc -> if x > 0 then acc + 1 else acc) 0

myLength :: [a] -> Int
myLength xs = foldr (+) 0 (map (\x -> 1) xs)

myMap :: (a -> b) -> [a] -> [b]
myMap f  = foldr (\x acc -> f x : acc) [] 
-- f x transforms current item from type a to type b
-- f x conses new b item onto the list acc
-- we start with an empty list []

-- myMap f = foldr((:).f) []

myLength' :: [a] -> Int
myLength' xs = foldr (\x acc -> acc + 1) 0 xs