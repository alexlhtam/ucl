# Java types
- Java is both a strongly typed and statically typed language
  - more strict than C
- type of everything must be declared/known
  - compiler does rigorous static type checking
  - it can do some type inference
  - some dynamic checking needed at runtime
    - runtime type safety is guaranteed
    - code either works or throws an `Exception`

# Primitive v Class types
- there are two categories of types:
  - Primitive types `byte`, `int`, `short`, `long`, `float`, `double`, `char`, `boolean`
    - similar to C, but there is a proper boolean type
    - values (bit representation) stored directly in variables
  - Class types: `String`, `ArrayList`, `Graphics`, etc.
    - values stored in variables are references to objects on the heap
    - class type of a variable determines what types of objects it can reference
    - class type of an object determines what class it is an instance of 
      - objects can conform to multiple types

# declaration v definition
- same concept as C applies to Java
- Java interfaces hold method declarations

# variables
- local instance and parameter variables
  - must always be declared before use
  - and have an explicit type - Java is strongly typed
- e.g.
  - `int size = 10;`
  - `String name = "UCL";`
  - `double weight = 1.23;`

# definite assignment before use
- a local variable must be definitely initialised or assigned to before its value is used
- no default values
- compiler checks before runtime

# local variable type inference
- local variable types can be inferred if enough information is available
`var size = 10; // must have an initialiser`
- the var keyword declares a variable where the compiler infers the type
- `10` is a literal of type `int`, hence `var` must be a variable of type `int`
- still static type checking
  - inference is also used in other contexts

# primitive types and values
- Java has primitive values represented directly in binary formats, not as objects
  - `boolean`: true or false
  - `int`: 32-bit 2's complement integer
  - `long`: 64-bit 2's complement integer
  - `char`: 16-bit unsigned Unicode character code
  - `float`: 32-bit floating point (IEEE 754 format)
  - `double`: 54-bit floating point (IEEE 754 format)

# object and references
- all objects are accessed via object references
- objects exist in heap memory only
  - like C dynamic memory allocation, but managed entirely by the JVM
  - JVM garbage collection automatically frees memory
```java
MyClass myVariable = new MyClass();
```
- create and initialise a MyClass object and obtain a reference to it
- `myVariable` must be declared as type `MyClass`
<br>
- references are similar to opaque handles, the language spec deliberately does not define their representation
- a reference locates an object
- a reference is not a C-style pointer accessible to the programmer, there are no pointer types

# assignment
- `a = value;`
- for primitive types the value (binary bits) is copied into the variable
- for class types, the object reference is copied into the variable
  - the reference is copied, but not the object itself!

# operators
- Java operators use the same symbols as C
- much the same precedence rules
- strict type checking is applied to expressions
- types of arguments determine which version of operator to use

# `==`
- in C `==` is used to compare two values
- in Java:
  - for primitive types `==` compares values
  - for class types `==` compares the object references
  - `"abc == "def"` compares the references to the String objects, not the string values themselves
  - instead, use the `compareTo` or `equals` methods to compare String object values

# comparing objects
- methods like `equals`, `compareTo` are used to compare object values
- the programmer can provide their own implementations and other methods to do the comparison
- an object's value (state) is the collection of instance variable values
- how a comparison is made depends on which values are compared and how

# `if` statement
```java
if (x == y) {
  foo();
} else {
  doSomething();
  // else is optional
}
```
- braces denote compound statements

# `switch` statement
- select one from many
```java
char c;
switch (value) {
  case 1:
    c = '1';
    break;
  case 2:
    c = '2';
    break;
  default:
    c = '?';
    break;
};
```
- value can be:
  - `byte` and `Byte`
  - `short` and `Short`
  - `int` and `Integer`
  - `char` and `Character`
  - `enum`
  - `String` or use pattern matching

# `switch` expression
```java
var result = switch (name) {
  case "april", "june", "sept", "nov" -> 30;
  case "jan", "mar", "may",
       "july", "aug", "oct", "dec" -> 31;
  case "feb" -> 28;
  default -> 0;
};
```
- an expression has a value, which is generated when the expression is evaluated

# `switch` pattern matching
- a variable of type `Object` can reference any object
- match case based on the actual type of the object referenced by `obj`
- and declare a variable of the type initialised to obj reference

# `while` loops
```java
while (x == y) {
    foo();
}
```
- loop body will be executed `0 or more` times
```java
int counter = 0;
while (counter++ <10) {
    System.out.println("Hello " + counter);
}
```

# `do` loops
```java
do {
    foo();
} while (x == y);
```
- loop body will be executed `1 or more` times


# scope and lifetime
- scope is a region of a program where a variable is valid
  - where a variable is declared and used
  - scopes are local, method, class
  - scope applies to anything that is named: variables/methods/classes
- lifetime is how long a variable exists
  - local variables have local scope and exist only while the scope is active
  - parameter variables are the same
  - instances variables exist while the object holding them exist

# comments
```java
// one line comment

/*
multi
line
comment
*/

/**
 * Documentation comments 
 * /
```

# methods
- a method is the object oriented name for function
- an instance method is declared in a class:
```java
public void f() {System.out.println("hello");}
```
- and called `obj.f();`
- void is a type - the empty type
- the return type must always be declared

# parameters
- parameters are type checked by compiler

# return type
- return statement allows a method to return a value, the type must be declared
- we can have multiple returns, but they all must be of the declared type

# data structures
- Java supports arrays as part of the language syntax, using the `[]` notation for indexing
- Java class libraries provide various `list` and `map` classes
  - `[]` notation cannot be used
  - all operations are done via method calls

# arrays
```java
int[] myArray = new int[6];
```
- because `Arrays` are objects, they know their own size:
- `myArray.length` returns an int length of the array

# C Array v Java Array
- a C array is a directly accessible sequence of memory locations
  - access is done via pointers (memory address)
  - square brackets are syntactic sugar
  - no bounds checking
- a Java array is a managed data structure wrapped in an object
  - access is via index operator (square brackets) only
  - strict bounds checking
  - no memory address pointers, no access to actual memory

# container classes
- the java collections framework provides many container classes:
  - list implementations:
    - `ArrayList`
    - `LinkedList`
  - map implementations
    - `HashMap`
    - `TreeMap`
  - set implementations
    - `TreeSet`
    - `HashSet`
  - and more

# generics and container classes
- for type safety the type of the values stored in a container needs to be defined
  - e.g. `String[]` can only store values of `String` type
  - values added, removed, etc. must be of the right type
- classes can be parameterised over types
  - `ArrayList<String>`, `ArrayList<Integer>`
  - same class, but type checking will guarantee correct usage
  - the class declaration uses a type variable
    - a variable that is bound to a type during type checking
    - `ArrayList<T>`
    - by convention, single capital letters are used

# ArrayList (generic class)
```java
import java.util.ArrayList; // requires importing

ArrayList<String> a = new ArrayList<>();
String s1 = "Hello";
a.add(s1);
a.add("world");
String s = a.get(1);
```
- diamond "operator": an example of type inference
- must explicitly create the ArrayList using new
- accessed via method calls, no `[]` operator
- can grow and shrink

# non-generic ArrayList
- avoid using this
- can also use ArrayList in this way:
```java
import java.util.ArrayList;

ArrayList a = new ArrayList();
String s1 = "hello";
a.add(s1);
a.add("world");
String s = (String) a.get(1);
```
- cast expression specifies the type of object returned

# containers, objects and primitives
- a container class can store object references only
  - and NOT primitive types
- nonetheless, we can still add and get primitive values from container classes

# auto-boxing/unboxing
- for each primitive type, there is a matching class
  - `Integer`, `Long`, `Double`, `Float`, `Boolean`, etc. are often referred to as 'wrapper' classes as they wrap the primitive values
- where possible, the compiler will automatically add code to convert representations
  - `int -> Integer` (boxing)
  - `Integer -> int` (unboxing)
- this allows primitive type values to be stored

# map (dictionary)
```java
HashMap<String, Integer> map = new HashMap<>();

map.put("One", 1);
int n = map.get("One");
int m  = map.get("Two"); // error, no key "Two"
```
- another generic class with two type variables
- maps keys of type `String` to values of type `Integer`
- type checking makes sure that keys/values used are of the correct type

# main function
```java
public static void main(String[] args) {
}
```
- `main` called to run program
- takes a `String` array as an argument
  - command line parameters
- `void` is the return type
- `static` declares the method does not need to be called for an object
- `public` indicates the method is accessible from outside the class