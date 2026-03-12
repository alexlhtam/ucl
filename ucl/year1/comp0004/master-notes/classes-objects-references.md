# Classes, Objects, References (Concise Revision)

## 1) Core idea
- A **class** defines structure + behavior.
- An **object** is a runtime instance of a class.
- Good OO design models real concepts via useful abstractions.

```java
class SimpleBook {
  private String title;
  private String author;

  public SimpleBook(String title, String author) {
    this.title = title;
    this.author = author;
  }
}
```

## 2) Encapsulation and visibility
- `private`: accessible only inside the class.
- `public`: accessible from outside via object references.
- Encapsulation reduces coupling: clients rely on the public interface, not internals.

## 3) References and object identity
- Class-type variables store **references**, not object values.
- Multiple variables can reference the same object.
- Reassigning a reference does not copy/move the object.

## 4) Method calls and `null`
- You can call methods only through a non-null reference.
- Calling a method on `null` throws `NullPointerException`.

```java
Person p = new Person("Alex", "Tam");
String name = p.getName();
```

## 5) Argument passing in Java
- Java is always **call-by-value**.
- For primitives: the primitive value is copied.
- For objects: the reference value is copied.
- So methods can mutate the shared object, but cannot change the caller's variable binding.

```java
void update(Person p) {    // p is a copy of caller's reference
  p.setName("New Name");   // mutates shared object
}
```

## 6) Object lifetime
- A reference variable can go out of scope while the object still exists.
- Objects remain alive while reachable by at least one reference.

## Important Summary
- Think in terms of: **class = blueprint, object = instance, reference = handle**.
- Most confusion comes from references: object values are not copied unless you explicitly copy.
- Keep state `private` and expose behavior through methods to preserve invariants.