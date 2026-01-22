# classes & objects
- we want to design programs in terms of classes and objects
- write the classes using programming language
  - define structure and behaviour
- objects are created and used when the program runs

## example class
```java
class SimpleBook {
    private String title;
    private String author;

    public SimpleBook(String title, string author) {
        this.title = title;
        this.author = author;
    }

    public String toString() {
        return title + " by " + author;
    }
}
```

## example object
```java
SimpleBook aBook = new SimpleBook("A Title", "An Author");
```
  - "+" means public, visible and accessible from the outside
  - "-" means private, not visible or accessible from the outside

# abstraction
- a representation or model that includes the important, essential or distinguishing aspects of something while suppressing or ignoring less important, immaterial or diversionary details
- removing distinctions to emphasise commonality
- leaving out of consideration one or more properties of a complex object so as to attend to others
- the process of formulating general concepts by abstracting common properties or instances

# abstraction and classes
- classes represent abstractions
- abstraction is used to separate the essential from the full detail
- they provide a selective and simplified view of the concepts being represented as objects
- good OO programming is all about identifying and using the right abstractions

# class roles
- representation
  - entities and things 
  - strategies and behaviours, controllers
  - data structures
- relationships
  - associations between entities
  - the mid-level structure of a program
- partitioning
  - divide application into manageable chunks, good abstractions
  - enforce encapsulation and information hiding
  - components and architecture

# notation
- classes can be represented by:
  - bytecode
    - produced by compiler (.class files)
    - not easily human readable
  - source code
    - programming language used to write programs with
  - a modelling language
    - formal: UML
    - informal: notes, diagrams, doodles
- different levels of abstraction
  - source code embodies all the details
  - modelling language gives a more abstract view

# unified modelling language/UML
- de-facto standard for OO design
- UML provides a complete language for describing object-oriented models 
- also provides a visual notation for displaying models
- maintained and developed as a standard by the Object Management Group

# who uses UML?
- designers, architects for larger applications
  - formal syntax and diagram style
  - modelling tools

- informally used as the notational style by many developers

# mermaid markdown
- widely used for creating all kinds of diagrams, including UML diagrams

# private
- a class defines a scope
- declaring a method or variable private means that it can be accessed only within the scope of the class
  - this means within a method body or an instance variable initialisation expression
- at runtime objects implement the scope rules
  - class + compiler + type checking + JVM ensures behaviour must conform
- internal state of an object should be private and changed by the object's methods only
  - the state is represented by the values of the instance variables

# public 
- at compile time methods and variables declared public can be used by any code where the class is in scope
  - imported into the source file
- at runtime methods and variables declared public can be accessed by anything that has a reference to an object of the class
  - variables belong to an object
  - methods are called on an object
- methods form the public interface of objects of the class
  - the services the object can perform
- it is the `.class` file that holds all relevant info

# encapsulation
- technique for minimising interdependencies among separately written modules by defining strict interfaces
- external interface acts as a contract between a module and its clients
- if clients only depend on the interface, modules can be re-implemented without affecting the client

# references
- a variable of a class type holds a reference to an object
  - a reference denotes a location but is not a memory address
- the variable does not hold the object itself
- the variable can go out of scope but the object can remain valid (providing it is referenced by some other variable(s))
- multiple variables or data structures can reference the same object
  - all store the same reference value

# calling methods
- given an object reference, a method can be called:
```java
Person person = new Person("Alex", "Tam");
String name = person.getName();
```
- only methods provided by class `Person` can be called
  - those methods declared by `Person`
  - and inherited methods

# Null reference
- `null` is a keyword
- the value of `null` is a "non-reference"
- no object is referenced, so no methods can be called
- default value if variable not initialised

# NullPointerException
- caused by calling method on a null reference 
- no object, so no method can be called

# object reference argument
- can pass an object reference as an argument to a method:
```java
void someMethod(Person aPerson) {
    // -- use aPerson in method body
}
```
- a parameter variable is declared as normal and initialised to a copy of the argument value
- object is not copied, cannot simply pass an object value to a method
- if the object reference is passed to a method:
  - changing the object inside the method changes the object outside the method
- do not forget that arrays are objects
  - changing elements in an array passed to a method changes the array outside the method

# primitive type arguments
- when a value of a primitive value type is passed as an argument, it is always copied
- the parameter variable is initialised to a copy of the argument value
- the argument value is computed in the method call
- e.g. `obj.f(1)`, `obj.f(n)`, `obj.f(a + b)`, `obj.f(g.h())`

# call-by-value
- parameter passing mechanism used by Java is called the "call-by-value"
- value of an argument is always copied and a parameter variable initialised with the copy
- objects not passed as arguments, only references to objects
  - reference is copied

# "variable is passed"
- value held in variable is passed as an argument
- variable itself is not passed
- value of the variable is not changed by the method called
  - object referenced by variable of class type can change

# return-by-value
- returning a value from a method works in a similar way to argument passing
- value returned is a copy of the value computed in the return statement

# object lifetime
- an object exists as long as it is accessible
  - i.e. reference to the object is available
- lifetime of reference variable different from lifetime of object