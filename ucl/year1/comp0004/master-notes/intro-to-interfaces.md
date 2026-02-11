# interfaces
- a way of defining a type separately from classes
- a collection of method signatures (return type, name, params)
- an object conforms to an interface if it has all the methods in the interface
- allow different objects to be used with the same code
  - object classes don't need to be related by inheritance
  - all objects will inherit from `Object`

# enter the interface
- types can also be declared using an `interface`:
```java
public interface ShapeIF {
    void draw(Graphics g);

    void move(int x, int y);
}
```
- no method bodies
- no instance variables

# implements
- a class can implement an interface
```java
class MyShape implements ShapeIF {
    // MyShape must override `draw` and `move` methods
    // or be abstract
}
```

# interface declarations
- an interface declares a collection of public methods
  - methods are abstract (no method bodies)
    - default methods are allowed
  - no instance variables
  - a class `implements` an interface and must override all the methods (or be an abstract class)
    - a bit like an abstract class only declaring abstract methods
- an interface specifies a type, that objects can conform to
  - any method in the interface can be called on a conforming object

# default methods
- Java 8 added ability to include default instance methods
```java
public interface Nameable {
    String getFirstName();
    String getSecondName();

    default String getFullName() {
        return getFirstName() + ", " + getSecondName();
    }
}
```
- inherited by any class implementing the interface
  - hidden if a class overrides the method
- cannot access instance variables

## why default methods?
- add methods independently from classes
  - allow APIs/libraries to evolve
- backward compatibility
  - existing classes can use a new version of an interface without modification
- multiple inheritance (sort of)
  - a class can inherit methods from multiple interfaces
  - if two or more interfaces have default methods with the same signature, a class must override the method
    - however, it can call the overridden methods

# `Iterators`
- a data structure can provide an `iterator` object to iterate through its elements
- an `iterator` decouples elements access from the data structure implementation