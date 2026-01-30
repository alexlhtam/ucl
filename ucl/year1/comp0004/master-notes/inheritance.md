# inheritance intro
- models the "kind-of" or "specialisation-of" or "extension-of" relationship between classes
- allows one class ot extend another class

# subclass and superclass
- a subclass inherits from a superclass
- the subclass gains all the properties of the superclass, can specialise, and it can add more features

# multiple subclasses
- more than one subclass can inherit from the same superclass
- Java supports single inheritance, one superclass only
  - some languages support multiple inheritance, 2 or more superclasses (like C++)

# generalisation and specialisation
- a superclass is a generalisation
- a subclass is a specialisation

# abstract vs concrete
- abstract classes provide a partial or abstract description
  - not enough to create instance objects
  - define a set of public method signatures that all subclass objects must have - common methods
  - define a common set of variable definitions and method implementations that are shared by inheritance
    - do not need to be duplicated in subclasses
- concrete classes provide a complete description
  - inherited + new attribute/methods
  - inherit common shared set of public methods signatures
  - can be used to create instance objects

# private and inheritance
- private variables are inherited and are part of subclass objects
- BUT they can be accessed by superclass methods only
  - scope and encapsulation are respected
- subclass methods have no access

# protected
```java
public class Shape {
    protected int x, y;
}
```
- a `protected` variable can also be accessed from subclasses
- allows the selective weakening of strict encapsulation
- increases the coupling between super and sub classes
- could use getter, setter methods in superclass instead (or accessor methods)

# super
- `super` gives a way of referring to the superclass
- when used in a constructor, it results in a call to the superclass constructor with the matching parameter list
  - known as 'explicit constructor invocation'
- `super` must go first:
  - super statement is typically the first statement in the constructor body

# abstract classes
- declaring an abstract method forces the class to be declared abstract
```java
public abstract class Shape {

}
```