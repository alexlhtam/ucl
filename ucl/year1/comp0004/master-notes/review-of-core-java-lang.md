# Core Java Language

## 1) Types and variables
- Java is **statically** and **strongly** typed: types are checked at compile time, with some runtime checks (exceptions).
- Two type categories:
  - **Primitive**: `byte`, `short`, `int`, `long`, `float`, `double`, `char`, `boolean`
  - **Reference/Class**: `String`, `ArrayList`, your own classes, etc.
- Local variables must be assigned before use (no default local value).
- `var` only works when an initializer is present and the type is inferable.

## 2) Objects, references, assignment
- Objects live on the heap and are accessed via references.
- Assignment copies:
  - primitive value bits, or
  - reference value (not the underlying object).
- Java has no pointer arithmetic (`*`, `&` are not Java operators).

```java
MyClass a = new MyClass();
MyClass b = a;   // copies reference
```

## 3) Equality and comparison
- `==` compares:
  - primitive values for primitives,
  - references for objects.
- For object value comparison, use `equals` (and `compareTo` when ordering is needed).

## 4) Control flow essentials
- `if/else` for binary decisions.
- `switch` for multi-way branching (`int`, `char`, `String`, enums, wrappers).
- Modern `switch` expression returns a value with `->`.
- `while`: 0 or more iterations; `do-while`: 1 or more.

```java
int days = switch (month) {
  case "apr", "jun", "sep", "nov" -> 30;
  case "feb" -> 28;
  default -> 31;
};
```

### Switch expressions quick notes
- `switch` **expression** returns a value; `switch` **statement** performs actions.
- Arrow cases (`->`) do not fall through, so `break` is usually unnecessary.
- For multi-line case logic, use a block and `yield` the value.
- Expressions should be exhaustive (include `default` unless all possibilities are covered, e.g. complete enum handling).

```java
int score = switch (grade) {
  case "A", "B" -> 1;
  case "C" -> {
    int adjusted = 2;
    yield adjusted; // return value for this case block
  }
  default -> 0;
};
```

- Pattern matching in `switch` (modern Java) lets you branch by runtime type in a cleaner way than long `if (x instanceof ...)` chains.

## 5) Scope and methods
- Scope defines where a name is usable (local, method, class).
- Lifetime is how long a variable/object exists.
- Methods must declare parameter types and return type (`void` for no return value).

## 6) Arrays and collections
- Arrays are objects with fixed length (`a.length`), index-based access, and bounds checks.
- Collections (`ArrayList`, `HashMap`, `HashSet`, etc.) are library types, used via methods.
- Prefer **generics** for type safety (`ArrayList<String>` not raw `ArrayList`).

```java
ArrayList<String> words = new ArrayList<>();
words.add("hello");
String w = words.get(0);
```

## 7) Boxing and wrappers
- Collections store object references, so primitives are boxed into wrappers (`int` <-> `Integer`).
- Java can auto-box/unbox in many contexts.

## 8) Program entry point
```java
public static void main(String[] args) {
}
```
- `public`: callable externally
- `static`: callable without an instance
- `void`: no return value

## Important Summary
- Use `equals` for object values; avoid `==` except for primitives (or intentional reference checks).
- Remember: assignment/calls copy values; for objects that means copying references.
- Prefer generic collections over raw types and over arrays for most app code.
- Keep scope tight, initialize locals early, and rely on compile-time type checks.