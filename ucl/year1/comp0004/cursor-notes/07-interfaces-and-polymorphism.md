# Interfaces & Polymorphism — COMP0004 Object-Oriented Programming (UCL)

*Lecture-style notes aligned with Slides 11 & 13: **interfaces**, **default methods**, **iterators**, **functional interfaces & lambdas**, **polymorphism** (parametric, subtyping, ad-hoc), **programming to an interface**, **generics**, **wildcards**, **type erasure**, and the **ArrayList** type hierarchy.*

---

## 1. COMPLETE TOPIC SUMMARIES

### **Interfaces — types separate from classes**

An **interface** in Java is a **type** that specifies a **contract**: a named set of **method signatures** (and sometimes **constants**) that implementing classes must honour. It lets you define **what** clients may call without fixing **how** each concrete class implements it.

- You declare an interface with the **`interface`** keyword.
- A class **implements** one or more interfaces with **`implements`** (comma-separated if several).

```java
public interface Drawable {
    void draw();           // public abstract by default
}

public class Circle implements Drawable {
    @Override
    public void draw() {
        // concrete implementation
    }
}
```

> **Beginner intuition:** A **class** is “a thing with data + code.” An **interface** is “a role or capability” — *something this object can do* — that many unrelated classes can share.

---

### **`interface` vs `implements`**

| Keyword | Role |
|--------|------|
| **`interface`** | Declares a new interface type (method signatures, `default`/`static` methods since Java 8, etc.). |
| **`implements`** | States that a **class** (or **enum**) provides bodies for that interface’s abstract methods. |

A class can **`extends` one superclass** but **`implements` many interfaces** — this is a major difference from single inheritance of implementation.

---

### **Interface vs abstract class**

| Aspect | **Interface** | **Abstract class** |
|--------|----------------|-------------------|
| **Instance fields** | Traditionally **none** (only **`public static final`** constants by default). No per-object state in the interface itself. | Can have **instance variables** and constructors. |
| **Inheritance** | A class **implements** multiple interfaces. | A class **extends** at most **one** abstract (or concrete) superclass. |
| **Method bodies** | Before Java 8: only abstract methods (+ static constants). Java 8+: **`default`** and **`static`** methods allowed in interfaces. | Can mix **abstract** and **concrete** methods freely. |
| **Typical use** | Cross-cutting **capabilities** shared by unrelated classes (`Comparable`, `Iterable`, `List`). | Shared **implementation** and **state** in a family of types (`AbstractList`). |

**Combining interface + abstract class + concrete class** is a common pattern: an **abstract class** shares code and fields; **interfaces** carve out narrow contracts; a **concrete class** fills in the last details.

```java
public interface Queue<E> {
    void enqueue(E item);
    E dequeue();
}

public abstract class AbstractArrayQueue<E> implements Queue<E> {
    protected int size;   // shared state — belongs in abstract class, not interface
    // partial implementations + abstract hooks possible
}
```

---

### **Default methods (Java 8+)**

A **`default`** method in an interface provides a **default implementation**. Implementing classes **inherit** it but may **`@Override`** to specialise.

- **Backward compatibility:** New methods can be added to widely used interfaces (e.g. **`Collection`**) without breaking every existing implementation at compile time — old classes get the default until they override.
- **Multiple interfaces:** If two interfaces supply conflicting defaults, the class must **resolve** the conflict explicitly (override and choose/super-call rules apply — worth knowing for exams).

```java
public interface Logger {
    default void log(String msg) {
        System.out.println(msg);
    }
}
```

---

### **`Iterator<E>` — walking a collection**

The **`Iterator<E>`** interface supports **sequential access** with optional removal:

- **`boolean hasNext()`** — whether another element exists.
- **`E next()`** — returns the next element; throws **`NoSuchElementException`** if none.
- **`void remove()`** — removes the **last element returned by `next()`** from the underlying collection; optional behaviour; misuse throws **`IllegalStateException`**.

Iterators are how many structures expose **internal traversal** without revealing representation.

---

### **`Iterable<T>` and the enhanced `for` loop**

**`Iterable<T>`** requires:

```java
Iterator<T> iterator();
```

If a class implements **`Iterable<T>`**, you can use the **enhanced for-loop** (`for (T x : obj)`), which compiles to iterator usage under the hood.

```java
public class Bag<T> implements Iterable<T> {
    private final List<T> items = new ArrayList<>();
    public void add(T t) { items.add(t); }
    @Override
    public Iterator<T> iterator() {
        return items.iterator();
    }
}
```

---

### **`Consumer<T>` and `forEach`**

**`Consumer<T>`** is a **functional interface** from **`java.util.function`**: a single abstract method **`void accept(T t)`**. It represents “do something with a **T**.”

**`Iterable.forEach`** (default method) takes a **`Consumer<? super T>`**, so you can pass a **lambda** or **method reference**.

```java
List<String> names = List.of("Ada", "Alan");
names.forEach(s -> System.out.println(s));
```

---

### **Lambdas and functional interfaces**

A **lambda expression** is **syntactic sugar** for an instance of an **anonymous class** that implements a **functional interface** (an interface with **exactly one abstract method** — SAM).

```java
// These ideas are equivalent in spirit (lambda is shorter):
names.forEach(new Consumer<String>() {
    @Override
    public void accept(String s) {
        System.out.println(s);
    }
});
names.forEach(s -> System.out.println(s));
```

The compiler **maps** the lambda to the functional interface’s single method.

---

### **Polymorphism — one piece of code, many types**

**Polymorphism** means “many shapes”: the same **client code** can operate on **values of different types** through a **common abstraction**.

1. **Parametric polymorphism (generics)** — A method or class is written **once** with a **type parameter** **`T`**, and works for many **`T`** (e.g. **`ArrayList<T>`**).
2. **Subtyping / inheritance polymorphism** — A **supertype reference** (class or interface) can point at a **subtype object**; **dynamic dispatch** calls the **overridden** method at **runtime**.
3. **Ad-hoc polymorphism** — **Overloading**: same method name, different parameter lists (resolved at **compile time**). **Coercion**: implicit widening conversions (e.g. **`int`** to **`long`**).

```java
void printArea(Shape s) {   // subtyping: any Shape subtype works
    System.out.println(s.area());
}

static <T> void printAll(List<T> list) {  // parametric
    for (T t : list) System.out.println(t);
}

void f(int x) { }
void f(double x) { }  // ad-hoc (overloading)
```

---

### **Pluggability, substitutability, and “programming to an interface”**

**Substitutability (Liskov-style idea):** Wherever a **supertype** is expected, a **subtype** instance should be usable without breaking the client’s expectations.

**Programming to an interface** means:

- Method parameters, return types, and fields use **interface** or **abstract supertype** types where possible.
- Concrete classes can be **swapped** (different algorithms, testing fakes) without rewriting client code.

The **Factory pattern** returns **interface** types from creation methods so callers depend on **`Product`** or **`Parser`**, not **`ConcreteProductA`**.

```java
public interface Parser {
    Document parse(String text);
}

public class ParserFactory {
    public static Parser create() {
        return new FastParser();  // could return SlowParser tomorrow
    }
}
```

---

### **Type conformance and multiple types**

An object **conforms** to:

- Its **runtime class** type and every **superclass** up to **`Object`**.
- Every **interface** its class **implements** (and superinterfaces transitively).

So one object can be referred to as **`Serializable`**, **`Comparable<String>`**, and **`String`** depending on context — **one value, many static types** it is compatible with.

---

### **Type hierarchy vs class hierarchy**

- **Class hierarchy** — **`extends`**: single inheritance chain (**`Object`** at the top).
- **Type hierarchy** in Java is richer: **interfaces** form their own **DAG** of **`extends`** between interfaces; a class’s **full set of types** = its class chain **plus** all implemented interface types.

Exam point: **`instanceof`** and assignment compatibility follow this **full** set of named types, not only the class chain.

---

### **`Comparable<T>` and sorting**

**`Comparable<T>`** declares **`int compareTo(T o)`** — a **natural ordering**. Negative / zero / positive means *this* is less than / equal / greater than *o*.

Sorting APIs (e.g. **`Collections.sort`**, **`List.sort`**) use **`Comparable`** or an explicit **`Comparator`**.

```java
public class Student implements Comparable<Student> {
    private final String name;
    @Override
    public int compareTo(Student other) {
        return this.name.compareTo(other.name);
    }
}
```

---

### **Generic methods and bounded type parameters**

A **generic method** declares its own type parameters before the return type:

```java
public static <T> void print(ArrayList<T> list) {
    for (T t : list) System.out.println(t);
}
```

**Bounded types** restrict **`T`** to types that support certain operations:

```java
public static <T extends Comparable<T>> T max(T a, T b) {
    return a.compareTo(b) >= 0 ? a : b;
}
```

**`T extends SomeType`** means **`T` must be a subtype of `SomeType`** (class or interface bound).

---

### **Wildcard types: `?`, `? extends T`, `? super T`**

- **`?`** — unknown type (e.g. **`List<?>`** — “list of something”).
- **`? extends T`** (**upper bound**) — “some subtype of **`T`**” — good for **reading** **`T`** (producer).
- **`? super T`** (**lower bound**) — “some supertype of **`T`**” — good for **writing** **`T`** (consumer).

**PECS:** **Producer `extends`**, **Consumer `super`.**

```java
public static double sum(List<? extends Number> nums) {
    double s = 0;
    for (Number n : nums) s += n.doubleValue();
    return s;
}

public static void addInts(List<? super Integer> dst) {
    dst.add(42);
}
```

---

### **Invariance: `List<Integer>` is not a `List<Number>`**

Even though **`Integer` extends `Number`**, **`List<Integer>`** is **not** a subtype of **`List<Number>`**. Java **generic** collections are **invariant** in **`T`** for **type safety** (especially with **mutation**).

If the assignment were allowed, you could **add a `Double`** through a **`List<Number>`** reference pointing at an **`ArrayList<Integer>`** — corrupting the list. Java forbids this at compile time.

---

### **Array covariance vs generic invariance**

**Arrays** are **covariant**: **`String[]`** is a subtype of **`Object[]`**. That allows **`ArrayStoreException`** at **runtime** if you misuse a **`Object[]`** reference holding a **`String[]`**.

**Generics** avoid this class of hole for mutable collections by using **invariance** (and **erasure** — see below).

```java
Object[] oa = new String[10];
// oa[0] = 42;  // ArrayStoreException at runtime
```

---

### **Type erasure**

At **compile time**, generics are checked strictly. At **runtime**, **most** generic type parameters are **erased** and replaced by their **bounds** (or **`Object`** if unbounded). The compiler **inserts casts** where needed.

Consequences:

- You **cannot** `new T()` or do **`instanceof List<String>`** (use **`List<?>`** or raw types in legacy code — avoid raw types in new code).
- **Overloads** cannot differ only by generic parameters after erasure.

---

### **Marker interfaces**

**Marker interfaces** have **no methods** (or no abstract methods): they **tag** types for **APIs / JVM / libraries** to query at runtime via **`instanceof`** or reflection.

Examples: **`Cloneable`**, **`Serializable`**, **`RandomAccess`** ( **`ArrayList`** implements it to advertise fast random access).

---

### **`ArrayList` type hierarchy (typical)**

Implementation detail useful for “bigger picture” questions:

- **Class side:** **`Object`** ← **`AbstractCollection<E>`** ← **`AbstractList<E>`** ← **`ArrayList<E>`**
- **Interfaces (among others):** **`List<E>`**, **`RandomAccess`**, **`Cloneable`**, **`Serializable`**, **`Iterable<E>`** (via **`Collection`**), etc.

So **`ArrayList`** is both a **concrete list** and an **`Iterable`** — linking **inheritance**, **interfaces**, and **enhanced for-loops**.

---

## 2. EXAM-STYLE QUESTIONS (WITH MODEL ANSWERS)

### **Q1.** Explain why Java allows a class to **implement multiple interfaces** but only **extend one class**. Relate your answer to **state** and **diamond problem** issues.

**Model answer:** **Single inheritance of classes** avoids ambiguity when two superclasses could provide **conflicting instance fields** or **overridden method** resolution for **one** object layout. **Interfaces** historically carried **no per-object state** (only constants and abstract methods), so a class can **compose several contracts** without conflicting **instance variable** layouts. Java 8+ **default methods** reintroduce some “diamond” resolution rules; the language requires explicit resolution when defaults clash. **Multiple interfaces** therefore support **flexible typing** and **mixins-like** behaviour without multiplying superclass state.

---

### **Q2.** What is the difference between **`Iterator`**, **`Iterable`**, and **`for-each`**? Write a minimal sketch showing how they connect.

**Model answer:** **`Iterable<T>`** promises **`iterator()`**. **`Iterator<E>`** supports **`hasNext`**, **`next`**, (optional) **`remove`**. The **enhanced for-loop** **`for (T x : collection)`** requires **`collection`** to be **`Iterable`** (or an array); the compiler uses **`iterator()`** and **`next`/`hasNext`** under the hood. Sketch: class implements **`Iterable<String>`** → method returns **`Iterator<String>`** → client uses **`for (String s : myObject)`**.

---

### **Q3.** Define **parametric**, **subtype**, and **ad-hoc** polymorphism. Give one **Java example** of each.

**Model answer:** **Parametric:** code parameterised by a type, e.g. **`static <T> void swap(T[] a, int i, int j)`** or **`List<T>`**. **Subtype:** a **`Drawable d = new Circle()`**; **`d.draw()`** uses **dynamic binding** to **`Circle.draw`**. **Ad-hoc:** **method overloading** **`void m(int x)`** vs **`void m(String x)`** — the compiler picks by **static types** of arguments; or **numeric widening** as coercion.

---

### **Q4.** Why is **`List<Integer>`** not a subtype of **`List<Number>`**? How does this differ from **arrays** of reference types?

**Model answer:** **Generic** **`List`** is **invariant** in **`E`** to prevent **heap pollution**: if the assignment were allowed, code holding **`List<Number>`** could **`add(1.5)`** into what is really **`ArrayList<Integer>`**. **Arrays** are **covariant** (`String[]` subtype of `Object[]`), so the compiler cannot prevent all bad stores; **`ArrayStoreException`** may occur at **runtime**. Generics trade **runtime array-style failures** for **stricter compile-time** rules.

---

### **Q5.** What is **type erasure**? Give two **consequences** for Java programmers.

**Model answer:** **Type erasure** removes (most) generic type information at **runtime**, using **raw** **`Object`** or **bounds** instead, with **compiler-inserted casts**. **Consequences:** (1) **`instanceof List<String>`** is illegal / meaningless at runtime — use **`List<?>`** or inspect elements. (2) You **cannot instantiate** **`new T()`** or create **`new T[]`** without workarounds, because **`T` is not reified**. (3) **Bridge methods** may be generated for overriding with generics — occasionally visible in stack traces.

---

## 3. MUST-KNOW KEY POINTS

- **`interface`** defines a **contract** (**method signatures**); **`implements`** connects a **class** to one or more interfaces.
- **Multiple interfaces**, **single superclass** — core Java OOP rule.
- **Default methods** add **implementations** in interfaces for **evolution** and **backward compatibility**.
- **`Iterator`** / **`Iterable`** power **standard traversal** and **for-each**.
- **Lambdas** target **functional interfaces** (e.g. **`Consumer<T>`**).
- **Polymorphism** = **parametric** + **subtype** + **ad-hoc** (know which is which).
- **Program to an interface** + **factories** → **low coupling**, easy **substitution**.
- **`Comparable<T>`** → **`compareTo`** → **natural order**.
- **Generics:** **generic methods**, **`extends` bounds**, **wildcards** (`? extends`, `? super`), **PECS**.
- **`List<Integer>`** is **not** **`List<Number>`** — **invariance**.
- **Arrays covariant**, **generics invariant** — exam favourite contrast.
- **Type erasure** → generics mostly **compile-time** discipline.
- **Marker interfaces** signal **capabilities** to APIs/JVM.

---

## 4. HIGH-PRIORITY TOPICS

### 🔴 **Must Know**
- **`interface` / `implements`** and **multiple interface** implementation
- **Subtype polymorphism** + **dynamic binding** (`@Override`)
- **`Iterator` vs `Iterable`** and **for-each**
- **Functional interface** + **lambda** correspondence
- **Invariance** of **`List<E>`**; why **`List<Integer>`** is not a subtype of **`List<Number>`**
- **Wildcard** meaning: **`? extends`** vs **`? super`** (PECS)
- **Type erasure** — what disappears at runtime and why casts appear

### 🟡 **Important**
- **Interface vs abstract class** (state, multiple inheritance, defaults)
- **Default methods** and **interface evolution**
- **Programming to an interface** + **Factory** sketch
- **Comparable** / **`compareTo`** contract (sign conventions)
- **Generic methods** and **`<T extends Comparable<T>>`**-style bounds
- **Array covariance** vs **generic** safety story
- **`ArrayList`** implements **`List`**, **`Iterable`**, **`RandomAccess`**, etc.

### 🟢 **Useful**
- **Ad-hoc polymorphism** (overloading vs overriding distinction)
- **Type vs class hierarchy** wording in long-form questions
- **Bridge methods** and advanced **erasure** edge cases
- **`Consumer` / `forEach`** as API reading fluency

---

## 5. TOPIC INTERCONNECTIONS & BIGGER PICTURE

- **Interfaces** are the main Java tool for **flexible architecture**: clients depend on **stable contracts** (`List`, `Comparable`, `Iterable`) while implementations change (`ArrayList`, `LinkedList`).
- **Polymorphism** ties **inheritance**, **abstract classes**, and **interfaces** together: **shared behaviour** vs **shared type**.
- **Generics** generalise **collections** and **algorithms** without **`Object` + cast** soup; **wildcards** refine **read vs write** APIs safely.
- **Lambdas** modernise **iterator-style** APIs into **declarative** **`forEach`**, **`stream()`**-ready thinking (later courses build on this).
- **Erasure** explains why Java generics feel powerful at compile time yet **`ClassCastException`** defence still matters at boundaries (raw types, legacy libraries).
- The **`ArrayList` hierarchy** shows **reuse**: **`AbstractList`** shares list logic; **`List`** promises behaviour; **concrete class** optimises storage.

---

## 6. EXAM STRATEGY TIPS

- When a question says **“polymorphism”**, **identify which kind** before writing — examiners reward precise vocabulary (**subtype** vs **parametric** vs **ad-hoc**).
- Draw **small UML-style arrows**: class **`extends`** one parent, **`implements`** interfaces; label **“is-a”** vs **“has-capability”**.
- For **wildcards**, write **one line of PECS** (“read **`Number`** from **`? extends Number`**; write **`Integer`** into **`? super Integer`**”).
- Contrast **compile-time** (**overload**, generics checking) vs **runtime** (**override** dispatch, **`ArrayStoreException`**).
- If asked **interface vs abstract class**, mention **instance state**, **constructor**, and **how many** you can combine.
- Memorise **`compareTo`** sign table and **`equals`/`hashCode`** awareness when sorting is discussed (common follow-up).

---

*End of notes — Interfaces & Polymorphism (Slides 11 & 13).*
