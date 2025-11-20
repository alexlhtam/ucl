'# Imperative Programming
## Imperative...
- expressing command, commanding, peremptory, urgent, obligatory
- an imperative program carries out a sequence of instruction/commands
    - referred to as statements
- mutable (updateable) memory stores information

## Basic control constructs
- sequence
  - one statement after another
- selection (branching, if statements)
- iteration (loop statement)

## Decomposition
- break down a large complex problem into a series of smaller problems

## Abstraction
- "a representation or model that includes the important, essential or distinguishing aspects of something while suppressing or ignoring less important, immaterial or diversionary details"
- programming relies heavily on using and creating abstractions

## Defining Variables
- a definition introduces a name, type and allocates memory
``` c
int a = 1;
double pi = 3.141;
long largeNumber = 9874587698769;
char c = 'a';
```
- a variable must be named before it can be used
- in contranst, a declaration just gives a name and type and does NOT allocate memory

## Allocation & Deallocation
- a variable is allocated memory for a fixed length of time
  - depending ont he kind of variable, local, file, scope (kind != type)
- when the variable goes out of scope, the memory is deallocated
  - memory is not destroyed/removed
  - can be reallocated to other variables as the program continues