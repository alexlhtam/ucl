-- Give definitions of functions to take a list of integers, ns, and
    -- return the list consisting of all the squares of the integers in ns
    squares :: [Int] -> [Int]
    squares = map (\ x -> x * x)

    -- return the sum of the squares of items in ns
    sumSquares :: [Int] -> Int
    sumSquares = sum.squares

    -- check whether all items in the list are greater than zero
    checkPositives :: [Int] -> Bool
    checkPositives = foldr ((&&) . (>0)) True

-- Using functions already defined wherever possible write definitions of functions to
    -- give the minimum value of a function f on inputs 0 to n
    minValue :: (Int -> Int) -> Int -> Int
    minValue f n = minimum (map f [0..n])

    --test whether the values of f on inputs 0 to n are all equal
    allEqual :: (Int -> Int) -> Int -> Bool
    allEqual f n = all ((== f 0) . f) [0..n]
    -- allEqual f n = all (== f 0) (map f [0..n])
    
    -- test if the values of f on inputs 0 to n are greater than zero
    allGreaterZero :: (Int -> Int) -> Int -> Bool
    allGreaterZero f n = all ((> 0) . f) [0..n]

    -- check whether the values f 0, f 1 to f n are in increasing order
    increasingOrder :: (Int -> Int) -> Int -> Bool
    increasingOrder f n = all (\x -> f x < f (x+1)) [0..(n-1)]

-- Recall the higher order function twice where twice f x = f(f(x)) = (f . f) x
    -- Give the type of twice.
    -- twice :: (a -> a) -> a -> a

-- Give the type and the definition of a function iter so that
    -- iter n f x = f (f (f ... (f x) ...))
    -- where f occurs n times in the right hand side of the equation
    --  For instance
    -- iter 3 f x = f (f (f x))
    -- and iter 0 f x should return x
    iter :: Int -> (a -> a) -> a -> a
    iter 0 f x = x
    iter n f x = f (iter (n - 1) f x)

-- using iter and double define a function that on input n returns 2^n where n is a
-- whole number and double is the integer doubling function from the introductory lecture
-- on Haskell functions
    double :: Int -> Int
    double x = 2 * x

    expTwo :: Int -> Int
    expTwo x = iter x double 1

-- Model the patient’s blood type. ABO Blood Type refers to A, B, AB, O 
-- and the positive and negative part refers to Rhesus (Rh) group.
    -- define the type RHType
    data RHType = Positive | Negative

    -- defining the type ABOType
    data ABOType = A | B | AB | O

    -- combine ABOType and RHType to create BloodType
    data BloodType = BloodType ABOType RHType

    -- create BloodType data for 5 patients
    patient1 :: BloodType
    patient1 = BloodType A Positive

    patient2 :: BloodType
    patient2 = BloodType A Negative

    patient3 :: BloodType
    patient3 = BloodType B Negative

    patient4 :: BloodType
    patient4 = BloodType AB Positive

    patient5 :: BloodType
    patient5 = BloodType O Negative
    
    -- Display your types: showRh, showABO, showBloodType
    showRh :: RHType -> String
    showRh Positive = "+"
    showRh Negative = "-"
    
    showABO :: ABOType -> String
    showABO A = "A"
    showABO B = "B"
    showABO AB = "AB"
    showABO O = "O"

    showBloodType :: BloodType -> String
    showBloodType (BloodType abo rh) = showABO abo ++ showRh rh

    -- Define the canDonateTo function
    -- A can donate to A and AB. B can donate to B and AB. AB can donate
    -- only to AB. O can donate to anybody.
    canDonateTo :: BloodType -> BloodType -> Bool
    canDonateTo (BloodType dABO _) (BloodType rABO _ ) = 
        case dABO of
            O -> True
            A -> case rABO of 
                A -> True
                AB -> True
                _ -> False
            B -> case rABO of
                AB -> True
                B -> True
                _ -> False
            AB -> case rABO of
                AB -> True
                _ -> False