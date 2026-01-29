# runtime errors
- unexpected errors that can terminate a program
  - undesired
- not detectable by compiler
- caused by:
  - errors in the program logic
  - unanticipated user behaviour
    - user performs actions or enters invalid data that the program cannot deal with
  - unexpected failure of services
    - running out of memory space
    - file server goes down/runs out of space
    - network unavailable

# exceptions
- an error results in an `exception` being `thrown`
- if the program does not `catch` the `exception` it will be terminated
  - it crashes from the user pov
- current data in memory will be lost
- open file, database and network connections may also cause loss of data
- data cannot be recovered, program cannot be restarted from the point where the exception was thrown

# check vs unchecked exceptions
- Java supports two categories of exception:
  - checked exceptions, which must be managed
    - otherwise, code won't compile
    - programmer must design how to handle the error
  - unchecked exceptions, which can be left unmanaged
    - the program will terminate if they occur and not handled
- checked vs unchecked is controversial
  - checked exceptions have overheads and clutter designs
  - do not want program to crash
  - generally agreed that checked exceptions in Java can be onerous to manage
    - many consider Java implementation too strict
    - tradeoff with reliability

# exception v optional
- which is 'best'?
  - exceptions work better when there is no value a method can return (not even null), and/or the method cannot complete
  - exceptions allow an entire sequence of active method calls to be abandoned safely
    - non-local recovery
  - optional works better when a method can return a value or null, and the calling method can deal with it
    - local recovery
  - both require the calling code (local or non-local) to handle the problem

# try and catch
```java
try {
    a.doSomething();
} catch (Exception e) {
    //handle the exception
}
```
- try block tries to evaluate a block of code
- catch block catches the exceptions thrown from the try block, if the exception type matches

# throw
```java
throw new MyException("method failed");
```
- `throw` statement throws an exception
- it needs a reference to an exception object
- in the chain of active method calls there must be a method with a catch block to catch the exception

# catch
```java 
catch (Exception e) { ... }
```
- catches an object of library class `Exception` or any of its subclasses
- `e` is initialised to the exception object reference
- typically, exceptions are subclasses of the class `Exception`
- the exception class can be more specific

# finally
```java
try {
    if (f()) g();
    h();
} catch (MyException e) {
    // do something
} finally {
    // guaranteed to evaluate
}
```
- `finally` block are always evaluated regardless before the enclosing method terminates
- `try-finally` with no `catch` is also allowed

# standard exception classes 
- `Throwable`
  - superclass of all exception classes
- `Error` (extends `Throwable`)
  - serious error that is not usually recoverable
- `Exception` (extends `Throwable`)
  - error that must be caught and recovered from
  - checked exceptions
- `RuntimeException` (extends `Exception`)
  - error that may be caught, not `try/catch` required
  - unchecked exceptions

# class `Throwable`
- `Throwable` provides:
  - a `String` to store a message about an exception
  - a method `String getMessage()` to return the mssage string
  - a method `printStackTrace()`
  - a few more methods
- subclasses extend `Throwable` and can add further variables and methods
- the majority of but not all `Exception` classes represent exceptions that must be caught
- the compiler will check -- checked exceptions
- but a number of `Exception` classes represent exceptions that are not required to be caught (unchecked exceptions) 

# `Throws` keyword
- a method can throw or re-throw an exception without catching it
  - the exception must be declared by a throws declaration, for class `Exception` and subclasses (excluding `RuntimeException`)
- if not, the compiler will fail the code
  - guarantees the exception will be caught