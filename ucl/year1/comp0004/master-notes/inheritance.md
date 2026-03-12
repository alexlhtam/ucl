# Inheritance (Concise Revision)

## 1) Core idea
- Inheritance models an **is-a** relationship.
- A subclass extends a superclass, reuses shared state/behavior, and can specialize.
- Java supports **single inheritance** for classes (one direct superclass).

## 2) Generalization and specialization
- Superclass: more general abstraction.
- Subclass: more specific abstraction.
- Use inheritance to remove duplication of shared code.

## 3) Abstract vs concrete classes
- **Abstract class**: cannot be instantiated; may contain abstract methods and shared implementation.
- **Concrete class**: complete implementation; can be instantiated.

```java
public abstract class Shape {
  public abstract double area();
}
```

## 4) Access control with inheritance
- `private`: not accessible from subclass methods.
- `protected`: accessible in subclasses (use carefully; increases coupling).
- Prefer `private` + accessor methods unless `protected` is justified.

## 5) `super` keyword
- `super(...)` calls superclass constructor and is usually first line of subclass constructor.
- `super.method()` can call an overridden superclass method.

## 6) Dynamic binding (polymorphism basis)
- Instance methods are dynamically dispatched at runtime based on actual object type.
- Static methods are statically bound (compile-time resolution).

```java
Shape s = new Circle();
s.area(); // Circle implementation runs
```

## Important Summary
- Inheritance is for true is-a reuse, not just code sharing convenience.
- Favor encapsulation (`private`) and keep hierarchies shallow/clear.
- Dynamic dispatch enables polymorphism: one supertype reference, many subtype behaviors.
