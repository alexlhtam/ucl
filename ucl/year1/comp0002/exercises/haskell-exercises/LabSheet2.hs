import Data.Char
import Data.List


inRange :: Int -> Int -> [Int] -> [Int]
inRange _ _ [] = []
inRange minVal maxVal (x:xs)
  | x >= minVal && x <= maxVal = x : inRange minVal maxVal xs
  | otherwise = inRange minVal maxVal xs


countPositives :: [Int] -> Int
countPositives [] = 0
countPositives (x:xs)
  | x > 0 = 1 + countPositives xs
  | otherwise = countPositives xs

-- with tail recursion
countPositivesTail :: [Int] -> Int
countPositivesTail [] = 0
countPositivesTail xs = go xs 0
  where 
    go [] count = count
    go (y:ys) count 
      | y > 0 = go ys (count + 1)
      | otherwise = go ys count


capitalised :: String -> String
capitalised [] = []
capitalised (x:xs) = toUpper x : go xs
  where
    go [] = []
    go (y:ys) = toLower y : go ys

capitalisedTail :: String -> String
capitalisedTail [] = []
capitalisedTail xs = go xs []
  where 
    go [] acc = reverse acc
    go (y:ys) acc
      | null acc = go ys (toUpper y : acc)
      | otherwise = go ys (toLower y : acc)


titleTail :: [String] -> [String]
titleTail [] = []
titleTail xs = go xs []
  where
    go [] acc = reverse acc
    go (y:ys) acc 
      | null acc || length y >= 4 = go ys (capitalisedTail y : acc)
      | otherwise = go ys (y : acc)


isort :: Ord a => [a] -> [a]
isort [] = []
isort (x:xs) = insert' x (isort xs)
  where insert' x [] = [x]
        insert' x (y:ys) = if x <= y then x : (y:ys) else y : insert' x ys

merge :: Ord a => [a] -> [a] -> [a]
merge [] [] = []
merge [] xs = xs
merge xs [] = xs
merge (x:xs) (y:ys)
  | x <= y = x: merge xs (y:ys)
  | otherwise = y:merge (x:xs) ys