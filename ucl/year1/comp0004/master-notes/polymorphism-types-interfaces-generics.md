# Polymorphism, Types, Generics

## 1) Polymorphism in practice
- One interface/supertype, many concrete implementations.
- Write client code once; plug in different object types.
- Main forms:
  - subtype polymorphism (inheritance/interfaces + overriding),
  - parametric polymorphism (generics),
  - ad-hoc polymorphism (overloading).

## 2) Types and conformance
- A type defines valid operations.
- Objects conform to their class type and implemented interface types.
- Subtype objects can be used where supertype references are expected.

## 3) Program to interfaces
- Depend on interface/supertype in method signatures and fields.
- Improves replaceability, testing, and long-term maintainability.

## 4) Generic constraints example
```java
public static <T extends Comparable<T>> void sort(List<T> list) {
  // can safely call compareTo on T
}
```
- Constraint `T extends Comparable<T>` guarantees ordering operations are available.

## 5) Invariance (important exam point)
- Even if `Integer` is a subtype of `Number`, `List<Integer>` is **not** a subtype of `List<Number>`.
- This protects type safety for mutable collections.

```java
List<Integer> ints = new ArrayList<>();
// List<Number> nums = ints; // invalid
```

## 6) Wildcards mental model
- `? extends T`: producer/read-oriented.
- `? super T`: consumer/write-oriented.
- Helps write flexible but safe APIs.

### Invariance cheat box (quick recall)
- Default Java generics are invariant: `Box<A>` and `Box<B>` are unrelated unless `A == B`.
- Why: prevents inserting wrong subtype values into mutable collections.
- PECS rule:
  - **Producer Extends**: `List<? extends Number>` (safe to read as `Number`).
  - **Consumer Super**: `List<? super Integer>` (safe to add `Integer`).

```java
List<Integer> ints = new ArrayList<>();
List<? extends Number> src = ints; // read-only view (for Number values)
Number n = src.get(0);             // OK
// src.add(1);                      // Not allowed

List<? super Integer> dst = new ArrayList<Number>();
dst.add(42);                       // OK to add Integer
Object x = dst.get(0);             // Read type is Object
```

## 7) `clone` note
- `Object.clone()` is shallow by default and often awkward.
- Copy constructors/factory methods are usually clearer and safer.

## Important Summary
- Polymorphism reduces duplication and coupling.
- Master generic bounds and invariance: they are central to Java type safety.
- Default design rule: code to interfaces + use generic constraints intentionally.
