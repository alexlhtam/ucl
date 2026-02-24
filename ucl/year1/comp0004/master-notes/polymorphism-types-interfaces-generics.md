# being object oriented
- exploiting the combination of:
  - objects
  - classes
  - encapsulation
  - inheritance
  - dynamic binding
  - polymorphism
  - pluggability
  - substitutability 

# polymorphism
- has multiple forms
  - a single function that can be applied to multiple types
  - generic methods/classes
  - ability of objects of different types to respond to same method calls
- allows one section of code to work with multiple values and objects
  - share rather than duplicate

# forms of polymorphism
- parametric polymorphism
  - generic classes
- sub-typing or inheritance polymorphism
  - overriding
  - dynamic binding
- ad-hoc polymorphism
  - overloading
  - coercion
  - duck typing

# polymorphism and types
- a supertype defines a common set of public method signatures
  - classes, interfaces, records, enums, define types
- subtypes inherit and may specialise method signatures
- a subtype object can be used where a supertype has been specified

# pluggability/substitutability 
- client code only uses common methods declared by superclass or interface (supertype)
- backend code can be updated without clients noticing a change

# objects and types
- an object has state
  - the value of its instance variables
- the overall value of an object is determined by its state
- an object also has a type, or it can conform to multiple types
  - an object's class determines the types it can conform to 
  - a class is a user defined type
- an object reference has a type to determine what types of objects it can refer to 

# types
- a type defines a set of values
  - objects represent the values
- a type defines a set of operations on the values of the type
  - classes define implementations of the operations as methods
- type checking ensures that only the operations defined by a type can be applied to values of that type
  - a class can inherit methods and implement interfaces

# type conformance
- all classes are subclasses of `Object` (except `Object`);
- a class can have indirect superclasses (the inheritance chain);
- classes can implement (and inherit) interfaces;
- an object can have multiple types
  - more precisely, an object can `conform` to multiple types
  - type conformance: any method declared by a type can be called on an object that conforms to the type

# type and class
- there is a close relationship between types and classes
  - a class defines a type in Java
- types are a more abstract representation
  - provide a link to maths/theory
  - types can be represented as sets
  - types can be defined in other ways, not just by declaring classes
    - interfaces
    - records, enums
    - primitives (non-class types)

# type hierarchies
- types also have supertype and subtype relationships (like superclass/subclass)
- class hierarchy defines part of the type hierarchy
- gets more interesting

# comparable interface
- any class that implements the `Comparable` interface must provide a `compareTo` method (unless abstract)
  - objects of the class can be compared
  - implements relationship is inherited by subclasses

# comparable sort
```java
public static <T extends Comparable<T>> void sort(List<T> list) {
    int n = list.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - j; j++) {
            if (list.get(j).compareTo(list.get(j+1)) > 0) {
                T temp = list.get(j);
                list.set(j, list.get(j+1));
                list.set(j+1, temp);
            }
        }
    }
}
```
- `sort` is a generic static method. `T` is declared by the declaration in red before the method signature
- type variable `T` is declared after the `static` keyword and constrained to be a subtype of `Comparable<T>`; a reference of type `T` can reference an object of any class that implements `Comparable<T>`, like `List<T>` or `String`
- `List<T> list`: any list of type `T`
- `list.get(j).compareTo(list.get(j+1)) > 0`: `get` returns a value of type `T`, it is safe to call `compareTo` as `T` must be a subtype of `Comparable<T>`
- when this method is compiled, `T` is unbound and erased to `Object`

# calling sort
```java
List <String> strings
    = new ArrayList<>(List.of("orange", "apple", "banana", "grape"));
sort(strings);
```
- `List<T>` is a generic type with type variable `T` unbound but constrained to be a subtype of `Comparable<T>`
- `List<String>` is a concrete parameterised type, which is an instantiation of `List<T>` with `T` bound to `String` for type checking
  - and `String` implements `Comparable<String>`
- `List<String>` is not a subtype of `List<T>`

# calling sort (2)
- `Integer` and `Double` are subtypes of `Number`
```java
List<Integer> ints
    = new ArrayList<>(List.of(5, 3, 8, 1, 2));
sort(ints); // valid T == Integer
```

# invariance
- `Integer` is a subtype of `Number`
- BUT `List<Integer>` is not a subtype of `List<Number>`
  - this is needed to maintain type safety
```java
List<Integer> ints = new ArrayList<>(); //valid
// 
List<Number> numbers = ints // invalid
numbers.add(2.34); // not type safe
```
- if this was allowed, a `Double` would be added to a list of `Integer`
- invariant - no type variation allowed
- a parameterised type is neither a subtype nor a supertype of the same type with a different parameter type
  - regardless of the inheritance relationship between those parameter types
- enforces strict compile-time checking, preventing potential runtime errors that could occur when manipulating collections with mixed types
- Java implements invariance by default in its generic type system
  - deliberate design choice to maintain type safety in a language that allows both immutable and mutable collection operations

# covariance
- a subtype can be used in place of its supertype, preserving assignment compatibility
- subtype substitution: if $B$ is a subtype of $A$, then $B$ can be used wherever $A$ is expected
- read only safety: covariant type allow values to be read safely but updates are disallowed or unsafe
  - applies to return types, not parameter types
- compile time type checking v runtime type checking

# programming to an interface
- use interfaces to declare types needed
- write code using interface types
- use objects of any classes that implement interfaces
- implementing classes can be added, edited, removed independently of code using the interface types
- commonly used and important design/implementation strategy
- decouples concrete representations from abstract specifications

# what is a clone?
- a method declared as 
```java
protected Object clone();
```
- in class `Object`, hence inherited by all classes
- by default, it does a shallow copy (just copies the values of instance variables, may be optimised to a bitwise copy)
- subclasses can override and specialise
  - do a 'proper' copy
  - declare as public, but can be left protected

# why `Cloneable`?
- a marker interface marks a class as implementing a `public` version of clone
  - doesn't need to declare clone as this is already done in `Object`
  - doesn't require the implementing class to actually override `clone`
- better to use a copy constructor
  - given an object of the same class to copy
  - does a full initialisation of a new object, no tjust copying instance variable values

# generic methods
- another form of polymorphism (parametric!!)
- a generic method can use/return values of different types
- an alternative to overloading
- another way of avoiding duplication of code

# two type parameters
```java
public static <T, V extends T> boolean isIn2(T x, List <V> y) {
    for (V item : y) {
        if (x.equals(item)) return true;
    }

    return false;
}
```
- `equals` method is declared in class `Object`, so can be called on all objects regardless of what type $V$ is instantiated to 
- $V$ is constrained to type $T$ or a subtype of $T$
- `List<V>` is a list of $V$ but not a subtype
- two type parameter makes type inference more complicated
- given `isIn2(2.2, numbers)`
  - the argument types are `Double`, `List<Number>`
  - type of first argument cannot be used to determine what $T$ will be bound to
- both $T$, $V$ need to be inferred
- infer both $V$ and $T$, while maintaining $V$ extends $T$
1. try `T == Double`, using the type of the first arg
   - then $V$ must extend `Double`, but $V$ is `Number`
        - `Number` is not a subtype of `Double`
        - fails.
2. broaden $T$ to `Number` (move to supertype) and try again
    - `Number` extends `Number` is now valid
    - `T == Number` gives `isIn(Number, List<Number>)`
    - type checking succeeds, type safety is maintained
- comparing `Integers` and `Doubles` using equals also has its issues: `7 != 7.0`
- two objects have to be instances of the same class to be equals

# generics for this module:
- have:
  - ability to write straightforward generic classes and methods
  - an understanding of what generic and parameterised types are
  - an awareness of type inference, `super`, `extends`
