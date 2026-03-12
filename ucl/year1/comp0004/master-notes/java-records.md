# Java Records (Concise Revision)

## 1) What a record is
- A record is a compact class for immutable-like data carriers.
- Ideal for "just data" objects with little custom behavior.
- Introduced in modern Java (standardized after preview stages).

```java
public record Book(String title, String author, int pages) {}
```

## 2) What Java generates automatically
- Constructor with all components.
- Accessor methods with component names (`title()`, `pages()`, etc.).
- `equals`, `hashCode`, and `toString` based on components.

## 3) Key constraints
- Record class is implicitly `final` (cannot be subclassed).
- Components are final-like: no setters; state is fixed after construction.
- Record can implement interfaces, but cannot extend another class.

## 4) Adding behavior
- You can still add methods.

```java
public record Book(String title, String author, int pages) {
  public boolean isLongBook() {
    return pages > 250;
  }
}
```

## 5) Equality and hashing
- Record equality is value-based on declared components.
- Generated `hashCode` aligns with `equals`, so records work well in hash collections.

## Important Summary
- Use records when the class is mainly immutable data.
- Records remove boilerplate while preserving type safety and clarity.
- If you need mutable state or complex inheritance, use a normal class instead.