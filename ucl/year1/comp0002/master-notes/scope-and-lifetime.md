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