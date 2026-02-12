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

# `Iterator` object abstraction
```java
ArrayList<String> a = new ArrayList<String>();
...
for (Iterator <String> iter = a.iterator(); iter.hasNext();) {
  doSomething(iter.next());
}
```
- or you can use:
  `a.forEach(Main::doSomething)`
  - `forEach` uses an iterator object to access each element, calling the `doSomething` method passing the element ref as the arg value.
  - the iterator object itself cannot be accessed

# `Iterator` interface
- type `Iterator` is declared as an interface

# `Iterator` implementation class
```java
class MyIterator<E> implements Iterator<E> {
  // must override non-default methods declared
  // in the interface
}
```
- an `iterator` object needs to access to the data structure being iterated
- `Iterator<String> iterator = new MyIterator<String>();`

# generic method using `Iterator`
```java
public <E> void print(Iterator<E> iterator) {
  while (iterator.hasNext()) {
    System.out.println(iterator.next());
  }
}
```
- the method (not class) has a type parameter `<E>`
- prints the content of any data structure that can provide an `Iterator`
- actual class of the iterator object does not need to be known here
- class of the data structure being iterated also does not need to be known

# enhanced for loop and iterator
```java
for (int i : someArray) { sum += i; }
```
- enhanced for loop actually uses `Iterator` objects
  - loop syntax mapped to creating/using `Iterator`
  - works properly with nested loops
- any data structure class can implement the `Iterable` interface to work with enhanced for
- an iterable - something that can be iterated with an `Iterator`
- an iterator - something that implements iteration

# `Consumer<T>`
- consumer is a generic functional interface
```java
@FunctionalInterface
public interface Consumer<T> {
  void accept(T t);
}
```
  - represents a function to 'consume' a value
  - no value returned
- an implementing class provides an accept method, taking a `T` as argument
  - this does the 'consuming'
  - includes anonymous classes and lambdas

- example:
- create a consumer of strings, use it with `forEach`:
  ```java
    List<String> names = Arrays.asList("One", "Two", "Three");
    Consumer<String> printConsumer = name -> System.out.println(name);
    names.forEach(printConsumer);
  ```
  - conceptually, lambda is mapped to:
    ```java
    Consumer<String> printConsumer = new Consumer<String>() {
      @Override
      public void accept(String name) {
        System.out.println(name);
      }
    }
    ```
    - new anonymous class implementing `Consumer<T>T`
    - `new` instantiates a consumer instance object of the class

# what is `<? super T>`
- a lower bounded wildcard type
- matches a type that is `T` or a supertype of `T`
```java
default void forEach(Consumer<? super T> action) {
  Objects.requireNonNull(action); // exception if null
  for (T t : this) {
    action.accept(t);
  }
}
```
- when compiling `Consumer`, the type of `<? Super T>` is erased to `Object`