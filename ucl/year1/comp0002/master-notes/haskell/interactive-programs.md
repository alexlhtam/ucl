# purity vs side effects
haskell is a pure functional language, meaning functions cannot change global state or have side effects (like printing/reading files) directly
- the problem: I/O is inherently "impure" because it changes the state of the world
- the solution: `IO` monad
  - haskell separates pure code form impure actions
  - an object of type `IO a` is not the result itself; it is a description of an action that will produce a value of type `a`

> think of `IO a` as a "recipe" or "blueprint" to get a value of type `a`, involving interaction with the outside world

# basic I/O actions
these are the standard building blocks found in the `prelude`

## output
- `putStr :: String -> IO ()` prints a string to stdout (no newline)
- `putStrLn :: String -> IO ()` prints a string with a newline
- `print :: Show a => a -> IO ()` converts a value to a string (using `show`) and prints it

## input
- `getLine :: IO String` reads a line from stdin
- `getChar :: IO Char` reads a single character

# the `do` notation
to chain multiple I/O actions together, we use `do` blocks
this allows us to write code that looks imperative but is syntactic sugar for chaining monadic operations
```hs
main :: IO ()
main = do
    putStrLn "What is your name?"
    name <- getLine
    putStrLn ("Hello, " ++ name ++ "!")
```
key rules of `do` blocks:
1. alignment: all lines in the `do` block must be aligned vertically
2. `<-` (binding): extracts the value from an IO action
   - `x <- action` performs action, take the result, and binds it to `x`
   - example: `name <- getLine` (name is now a `String`)
3. `let`  (pure binding): use `let` (without `in`) to bind pure values inside a `do` block
4. last statement: the last action in a `do` block cannot be a bind (`<-`). it must be an expression that determines the return value of the block

# the `return` function 
in haskell, `return` is not like "return" in C/Java/Python. It does not exit a function
- type: `return :: a -> IO a`
- purpose: it takes a pure value and wraps it into an IO action
- usage: often used as the last line of a `do` block to pass a pure value back as the result of the IO action
```hs
-- this reads a line, converts it to uppercase and returns it
getUpperLine :: IO String
getUpperLine = do 
    line <- getLine
    return (map toUpper line)
```

# control structures in IO
you can use standard haskell control inside IO actions

## if-then-else
you must have an `else` branch and both branches must return the same IO type
```hs
main :: IO ()
main = do
    line <- getLine 
    if line == ""
        then return()        -- do nothing
        else do
        put StrLn line
        main                 -- recursive call to loop
```

## recursion
since there are no while loops, use recursion to repeat actions
```hs
askForNumber :: IO ()
askForNumber = do 
    input <- getLine
    if input == "exit"
        then putStrLin "Goodbye!"
        else do
            putStrLn ("You said: " ++ input)
            askForNumber -- Loop
```

# useful IO functions (`Control.monad`)
`when` and `unless
execute an action
```hs
import Control.Monad (when)

main = do 
    input <- getLine
    when (input == "save") $ do
        putStrLn "Saving..."
```
`sequence`
takes a list of IO actions and performs them one after another, returning a list of results
- `sequence :: [IO a] -> IO [a]

`mapM` and `mapM_`
maps a function return an IO action over a list
- `mapM` : returns the list of results (`IO [b]`)
- `mapM_` : discard the results (useful for iteration where you only care about side effects, like printing)

```hs
-- prints numbers 1 to 3, each on a new line
mapM_ print [1, 2, 3]
```

`forM`
similar to `mapM`, but with arguments flipped. often looks like a "for loop"
```hs

import Control.Monad (forM)

main = do
    colours <- forM [1,2, 3] $ \i -> do
        putStrLn $ "Enter colour for number " ++ show i ++ ":"
        getLine
    print colours
```
