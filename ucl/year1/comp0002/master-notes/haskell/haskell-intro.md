# intro to haskell

## intro
- not a state-based language
- uses functions to perform calculations
  - write a function
  - apply it to some data (input)
  - function transforms data (output)
  - no state update, no state, no variables, no loops, just functions

```haskell
swap: (Int, Int) -> (Int, Int)
swap(x, y) = swap(y, x)
```

## glasgwow haskell compiler (GHCi)
- has both an interpreter and a compiler
- write simple things at the command line
- compile larger programs
- mix these up!

## using the interpreter
- open a terminal window and type `ghci`
- prompt appears and you can begin

- simple things can be done at the command line:
  - arithmetic at prompt
  - boolean algebra
  - equality tests
  - functions

## functions and files
- use `:l` to load (compile and make available)

