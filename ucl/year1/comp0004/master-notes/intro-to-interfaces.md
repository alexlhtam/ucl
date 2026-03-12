# Interfaces and Iteration

## 1) What an interface is
- An interface defines a type by method signatures.
- Classes `implement` interfaces to guarantee those methods exist.
- Different, unrelated classes can be used through one interface type.

```java
public interface ShapeIF {
  void draw(Graphics g);
  void move(int x, int y);
}
```

## 2) Why interfaces matter
- Support programming to abstractions, not concrete classes.
- Improve decoupling and replaceability.
- Enable polymorphism across unrelated classes.

## 3) Default methods
- Interfaces can include `default` instance methods (Java 8+).
- Useful for API evolution and backward compatibility.
- If two interfaces provide conflicting defaults, implementing class must override.

## 4) `Iterator` and `Iterable`
- `Iterator<T>` abstracts traversal (`hasNext`, `next`).
- `Iterable<T>` means "can provide an iterator."
- Enhanced for-loop uses iterator semantics internally.

```java
for (Iterator<String> it = list.iterator(); it.hasNext();) {
  System.out.println(it.next());
}
```
- Manual iterator version:
  - `list.iterator()` creates the iterator.
  - `hasNext()` checks if another element exists.
  - `next()` returns that element and moves forward.
  - Useful when you need explicit control (e.g., safe removal during iteration).

## 5) `forEach` and `Consumer<T>`
- `Consumer<T>` represents an operation taking `T` and returning nothing.
- Common with lambdas:

```java
list.forEach(x -> System.out.println(x));
```

## 6) Wildcard note: `<? super T>`
- Lower-bounded wildcard: accepts `T` or supertypes of `T`.
- Common in consumers because consuming is type-safe "from below."

## Important Summary
- Interface = contract; class = implementation.
- Prefer interface-typed variables/parameters to keep code flexible.
- Understand iterator/consumer basics because they power enhanced for-loops and stream-style APIs.