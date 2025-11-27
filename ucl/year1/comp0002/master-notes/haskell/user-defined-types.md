# type declarations
- in haskell, a new name for an existing type can be defined using a type declaration
```hs
type String = [Char]
```
- type declarations can be used to make other types easier to read
```hs
type Pos = (Int, Int)
-- define var
origin :: Pos
origin = (0, 0)

left :: Pos -> Pos
left (x, y) = (x - 1, y)
```
- similar to function definitions, type declarations can also have `parameters`
```hs
type Pair a = (a, a)

mult :: Pair Int -> Int
mult (m, n) = m * n

copy :: a -> Pair a
copy x = (x, x)
```

# data declarations
- a completely new type can be defined by specifying its values by using data declaration
```hs
data Bool = False | True
-- bool is a new type, with two new values False and True
```
- the values `False` and `True` are called the `constructor` for the type `Bool`
- type and constructor names must always begin with an `upper case letter`
- data declaration are similar to content free grammar
  - the former specifies the value of a type, the latter the sentences of a language
- values of new types can be used in the same way as those of the built types
```hs
data Answer = Yes | No | Unknown

answers :: [Answer]
flip :: Answer -> Answer
flip Yes = No
flip No = Yes
flip Unknown = Unknown
```
- the constructor in data declaration can also have parameters
```hs
data Shape = Circle Float | Rect Float Float

square :: Float -> Shape
square n = Rect n n 

area :: Shape -> Float
area (Circle r) = pi * r * r
area (Rect x y) = x * y
```
- shapes has the values of the form:
  - `Circle r` where `r` is a float
  - `Rect x y` where `x` and `y` are floats
- `Circle` and `Rect` can be viewed as functions that construct values of type `Shape`
```hs
Circle :: Float -> Shape
Rect :: Float -> Float -> Shape
```
- data declarations themselves can also hbave parameters
- `data Maybe a = Nothing | Just a`

# recursive types
- new types can be declared in terms of themselves
```hs
data Nat = Zero | Succ Nat
```
  - `Nat` is a new type with constructors `Zero :: Nat` and `Succ :: Nat -> Nat`