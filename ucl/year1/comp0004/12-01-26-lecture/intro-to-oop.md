# Java v C
- the core syntax is deliberately similar
- Java is `object-oriented` (not orientated)
  - classes, objects, inheritance, dynamic binding
  - C has no (direct) support for OO programming
    - but the C++, C#, Python, Swift, JS languages do
- Java has extensive class libraries supporting many features
  - GUIs, networking, databases, graphics, etc.
  - cannot be separated from the language
- Java programs run on the Java Virtual Machine, the JVM
  - no direct access to memory or hardware
  - no C-style pointers (memory addresses)
  - JVM is not a VM that virtualises hardware

# in the terminal:
# Java terminal:
- Java compiler is called `javac`
  - to compile use:
    - `javac` <filename>.java
    - this will create a file called `TemperatureConverter.class`

# running a Java program
- to run a program Java program use `java`
  - `java` <filename>
  - no file extension!

# behind the scenes
- the program creates an `object`
- the method is called on the object

# classes and objects
- program actually consisted of a single class declaration
  - simple program are one-class programs
  - normal Java programs have many classes

## class
- a `class` describes an object is and does
  - a class is described by writing its definition in source code
    - defines the object's variables and methods
  - the class acts as a template or factory for creating objects
  - gives organisation and structure to the code
  - partitions and modularises the design
  - a class represents an abstractino

## objects
- exist at runtime only
- has responsibilities:
  - behaviour
    - implemented as `methods`
  - attributes
    - implemented as `instance variables`
    - also known as `properties`
- objects collaborate to perform more complex tasks
- when running, an OO program is a collection of communicating objects

# `println` and `print`
- `System.out` is a `PrintStream` object always available when a program is run
- a Java string always appears in double quotes

# Java compiler
- translates source code directly into bytecode
  - parsing, analysis, type checking
  - bytecode is generated but it is not machine code
    - bytecode is an intermediate abstract representation
  - equivalent representation of source code
    - no bytecode analysis/optimisation
- compiler independently compiles each source file to generate a `.class` file
- there is no linking done, just a collection of `.class` files

# Java virtual machine
- not an OS style VM
- an interpreter that runs bytecode, but does not emulate a processor
  - interpreter provides a complex structured environment, based on stacks
  - manages memory allocation
  - garbage collector to deallocate memory

# just in time compiler
- for high performance bytecode is translated at runtime into machine code
  - done incrementally when sections of code are used frequently enough, space for optimisation
- JIT is a compiler from bytecode to machine code
  - so Java has two compilers!
  - does all machine code optimisation very efficiently
  - continually modifying and rewriting code
  - dynamic compilation and optimisation
- C code is static once compiled, does not change
- Java code is constantly analysed and modified at runtime

# linking
- all linking is done at runtime but not like C
- no single executable program, the compiler outputs `.class` files each representing one class
- `.class` files are loaded and linked by the JVM as needed
  - extensive verification to ensure all language rules are enforced
  - no security violations
- gives very dynamic behaviour with full type safety
  - however, Java is not a dynamic language like Python
  - mostly statically typed