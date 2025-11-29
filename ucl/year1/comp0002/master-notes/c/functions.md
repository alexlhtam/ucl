# functions
## use functions
- a named statement sequence gives us a function (also called a procedure or method)
- use the name to call the function

## parameterisation
- varying behaviour of a function depending on which argument value it is called with
- better abstraction

## argument v parameter
- argument: a value passed to the function in a function call
  - a literal the value of a variable, the value of an expression (e.g., a + 3)
- parameter: a variable defined in the function definition, initialised by an argument value
  
## multiple parameters
- a function can have zero or more parameter variables
  - two or mroe give a parameter list 
  - `void f(int a, double b)`
- good practice is no more than 5 or 6 unless good reason
- function call must provide an argument value of a compatible type for each parameter

## implicit conversions
- type promotion
  - no information lost
  - short to int, int to long, float to double, char to int
- type conversion
  - info can be lost
  - int to double, safe sort of, there are edge cases
  - float, double to int - will cause compiler warning
    - changes value from 2.123 to 2
  - double to float (no warning but can lose info)
- pointer to int, int to pointer
  - gives a warning and allowed, not useful, most likely programmer error
  - pointers can be thought of as an unsigned int

## functions as mathematical functions
- functions can be written to look like mathematical functions
  - sqrt, pow, sin, cos, log, etc.
- always return the same value when applied to the same arguments
  - referential transparency
- C functinos can be written to return different values when called with the same arguments
- C functions can also have side-effects (e.g. doing input or output, updating data structure)

## recursion
- a recursive function calls itself
- too many recursive calls without returning will cause program to crash
  - uses up all available stack memory
  - can result in unallocated memory being overwritten
  - program cannot recover
- will see an unhelpful error message

## function signature
- name, parameter(s) and return type:
  - `int f(char c)`
  - `double g(int a[], int b)`
- every function should have unique signature within a single program

## function declaration v definition
- a declaration is a function signature + semi-colon
  - `int f(char c);`
- the definition inside the function body:
  - `int f(char c) {...}`
- these denote the same function

## use of function declarations
- a function must at least be declared before it is called in a function call expression
  - header files (.h) files contain function declarations
    - for functions in other source files or libraries
  - you want to call a function before it is defined in your own source code file
  - or the function is in another of your source code files

## definition order
- to a change the order of definitions in source file you can change functinos before the definitions

# summary
- functions - named statement sequences
- function calls, parameters, return
- recursion
- function signatures
- declaration v definition