import Data.Char
import Data.List
import System.Win32.Automation.Input (xBUTTON2)


inRange :: Int -> Int -> [Int] -> [Int]
inRange _ _ [] = []
inRange minVal maxVal (x:xs)
  | x >= minVal && x <= maxVal =x : inRange minVal maxVal xs
  | otherwise = inRange minVal maxVal xs


countPositives :: [Int] -> Int
countPositives [] = 0
countPositives (x:xs)
  | x > 0 = 1 + countPositives xs
  | otherwise = countPositives xs


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
  | x <= y = x:(merge xs (y:ys))
  | otherwise = y:(merge (x:xs) ys)