# scope & lifetime

## scope of a name
- a name must be declared before it can be used
  - variable names need a type
  - function names need a signature
  - a definition is a declaration plus more information

- the scope of a name determines where in the source code it is valid
  - from the point of declaration/definition to the end of the scope

- use of a name not "in scope" potentially results in an error
  - the C compiler will make assumptions in some cases
  - invent a function signature that may be wrong

## different kinds of variables
- file scope
  - declared outside a function, within a source file
  - valid from the point of declaration
  - can be used by any function in the file following declaration
  - sort of a "global" scope (with an asterisk!!)
  ```c
  // n yet not declared, not in scope
  int n; // n now in file scope

  int f() {
    n = 10; // in scope
  }
  // n still in scope
  ```

- local scope
  - within a compound statement including function bodies
  - valid from the point of declaration
  - also called block scope
```c
{
  // x not delcared yet, not in scope
  int x; // local, in scope
  // ...
}

// x no longer in scope
```

## parameter variables
```c
void square(int size) {
  // size in scope within body only
}
// size not in scope outside of function definition
```
- the paramter variable can only be used inside the function body (a compound statement)
- only accessible while function is being evaluated
- a paramater variable is a kind of local variable with specific initialisation rules

## local variable lifetime
- lifetime of a local/param variable is determined by its scope and when memory is allocated
- memory is allocated when a local scope is entered at runtime
- memory is deallocated when the scope is exited
  - uses the stack
- with C it is possible to access deallocated memory by mistake, be careful

## file scope variable lifetime
- the lifetime is the entire runtime of the program
- memory allocated once when program starts
- remains allocated until program ends
- variable can only be used when the name is scope

## nested scopes
```c
if (...) {
  int n = 2; // local var in scope
  for (...) {
    int n = 3 // new variable local to nested scope, outer n hidden
  }
  int n = 4; // error, n already declared above in same scope
}
```
- in Java, the innermost n definition would cause an error
- in C, names can be reused if declared in disjoint (different) scopes

## global scope
- scope of entire program
  - across multiple soruce files (.c files or translation units)
- C does effectively have global scope
  - functions can be called from any source file
    - must be declared in files they are not defined in
  - file scope variables can be made "global" using extern
    - can be poor design practice

## localisation
- best practice is to limit the scope of a name to the minimum region
- limit access to functions to code that actually needs them
- reduce risk of variables being misused
  - the larger the scope, greater risk of accidental use
- particularly important for object oriented programming with Java