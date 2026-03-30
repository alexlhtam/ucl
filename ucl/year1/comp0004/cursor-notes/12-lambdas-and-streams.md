# Lambdas & Streams — COMP0004 Object-Oriented Programming (UCL)

*Lecture-style notes aligned with Slides 19: **functional interfaces**, **lambda expressions**, **method references**, the **Stream API**, **lazy pipelines**, **intermediate vs terminal operations**, and **parallel streams**.*

---

## 1. COMPLETE TOPIC SUMMARIES

### **Functional interfaces — exactly one abstract method**

A **functional interface** is an **interface** with **exactly one abstract method** (SAM — **single abstract method**). Java uses this shape as the **target type** for **lambda expressions** and **method references**.

Common library examples:

| Interface | Abstract method idea | Typical use |
|-----------|----------------------|-------------|
| **`Consumer<T>`** | **`void accept(T t)`** | Do something with each element — **side effect**. |
| **`Function<T, R>`** | **`R apply(T t)`** | Transform **`T`** → **`R`**. |
| **`Predicate<T>`** | **`boolean test(T t)`** | **Yes/no** filter. |
| **`Supplier<T>`** | **`T get()`** | Provide a value (deferred creation). |
| **`UnaryOperator<T>`** | extends **`Function<T,T>`** | **`T` → `T`**. |

> **Beginner intuition:** The interface is a **slot** for “one piece of behaviour.” A **lambda** **fills the slot** without writing **`new AnonymousClass()`**.

---

### **`@FunctionalInterface` — documentation + compiler check**

Annotating with **`@FunctionalInterface`** is **optional** but useful:

- **Documents intent** — “this is designed for lambdas.”
- **Compiler enforcement** — the interface must remain a **valid** functional interface (exactly one abstract method, aside from **`Object`** method overrides and **`default`/`static`** methods).

```java
@FunctionalInterface
public interface IntPredicate {
    boolean test(int value);
}
```

---

### **Lambda syntax**

**Lambda expression** forms:

- **Single expression body:** **`(params) -> expression`**
- **Block body:** **`(params) -> { statements; }`**

```java
// Predicate<String> — keep non-empty strings
Predicate<String> nonEmpty = s -> !s.isEmpty();

// Function<String, Integer> — length
Function<String, Integer> len = String::length;

// Consumer<String> — print
Consumer<String> print = s -> System.out.println(s);
```

**Parameter types** can often be **inferred** from the **target type** (the functional interface expected by the method).

---

### **Lambda as an implementation of a functional interface**

When you pass a lambda to a method, the compiler **expects** a **functional interface** and **synthesises** an object that implements it:

```java
List<String> names = List.of("ada", "alan");
names.forEach(s -> System.out.println(s)); // Consumer<? super String>
```

So **lambdas are not “magic syntax”** — they are **compact implementations** of **SAM interfaces**.

---

### **Method references — reuse an existing method**

**Method reference** shorthand **`::`** when a lambda **only** forwards to a method:

| Form | Example | Meaning |
|------|---------|---------|
| **Static** | **`Integer::parseInt`** | **`s -> Integer.parseInt(s)`** |
| **Instance (bound)** | **`System.out::println`** | **`x -> System.out.println(x)`** |
| **Instance (unbound)** | **`String::length`** | **`s -> s.length()`** |
| **Constructor** | **`ArrayList::new`** | **`() -> new ArrayList<>()`** |

---

### **Streams — values flowing through stages**

A **stream** is a **sequence of values** (often from a **collection** or **generator**) processed through a **pipeline** of **operations**. Streams favour **declarative** code: **what** to compute, not **how** to index loops (though loops remain fine when simpler).

---

### **Stream pipeline: source → intermediate → terminal**

1. **Source** — e.g. **`collection.stream()`**, **`Stream.of(...)`**, **`IntStream.range`**, **`Files.lines`**.
2. **Intermediate operations** — **lazy** transforms: **`filter`**, **`map`**, **`sorted`**, … Return a **new stream** (conceptually chained).
3. **Terminal operation** — **triggers** computation: **`forEach`**, **`collect`**, **`reduce`**, **`count`**, … Produces a **result** or **side effect** and **ends** the pipeline.

```java
List<String> result = names.stream()
    .filter(s -> s.startsWith("a"))
    .map(String::toUpperCase)
    .toList(); // terminal (Java 16+)
```

---

### **Creating streams**

```java
// From array
int[] nums = {1, 2, 3};
IntStream s1 = Arrays.stream(nums);

// From collection
List<String> xs = List.of("a", "b");
Stream<String> s2 = xs.stream();

// Numeric range (exclusive end)
IntStream s3 = IntStream.range(0, 10);      // 0..9
IntStream s4 = IntStream.rangeClosed(0, 10); // 0..10
```

---

### **Intermediate operations (lazy)**

| Operation | Role |
|-----------|------|
| **`filter(Predicate<T>)`** | Keep elements where **predicate** is true. |
| **`map(Function<T,R>)`** | **One output** per input — **1:1** transform. |
| **`flatMap(Function<T, Stream<R>>)`** | **Flatten** nested streams (**1:many** then merge). |
| **`sorted()`** / **`sorted(Comparator)`** | Sort stream (may buffer — **stateful**). |
| **`distinct()`** | Drop duplicates (**`equals`**-based for object streams). |

These **do nothing** until a **terminal** operation runs.

---

### **Terminal operations**

| Operation | Role |
|-----------|------|
| **`forEach(Consumer<T>)`** | Act on each element (often **side effects** — use carefully). |
| **`reduce`** | **Fold** stream to one value (e.g. **sum** pattern with **`Optional`**). |
| **`collect(Collector)`** | **Mutable reduction** into **`List`**, **`Set`**, **`String`**, etc. |
| **`sum()` / `average()` / `summaryStatistics()`** | On **primitive streams** (**`IntStream`**, etc.). |
| **`count()`** | Number of elements. |
| **`toList()`** | Java 16+ **immutable list** (convenient terminal). |

---

### **`filter` — `Predicate<T>`**

**`filter`** keeps elements for which **`test`** returns **`true`**:

```java
List<Integer> evens = numbers.stream()
    .filter(n -> n % 2 == 0)
    .toList();
```

---

### **`map` — `Function<T, R>`**

**`map`** applies **one transformation** per element:

```java
List<Integer> lengths = words.stream()
    .map(String::length)
    .toList();
```

---

### **`reduce` — combine into one result**

**`reduce`** combines stream elements with a **binary operator**:

```java
int sum = IntStream.of(1, 2, 3).reduce(0, Integer::sum); // identity + combiner
OptionalInt maybe = IntStream.of(1, 2, 3).reduce(Integer::sum); // empty stream → empty OptionalInt
```

**Empty streams** → **`Optional`** empty (without identity); **identity** form returns **`identity`** when empty.

---

### **Laziness — values pulled by the terminal op**

**Streams are lazy:** intermediate steps **record** operations; **nothing runs** until a **terminal** operation **pulls** values. That enables **short-circuit** ops (e.g. **`findFirst`**) to avoid **unnecessary** work.

> **Beginner intuition:** Intermediate ops build a **recipe**; **terminal** op **cooks** it.

---

### **Streams vs classic loops**

| Aspect | **Streams** | **Traditional loops** |
|--------|-------------|------------------------|
| Style | Often **declarative** | **Imperative** step-by-step |
| State | Prefer **stateless** lambdas for **parallel** safety | **Mutable locals** common |
| **Parallelism** | **`parallelStream()`** possible | Manual **fork/join** harder |

Use streams when they **clarify** intent; use loops when **performance**, **debugging**, or **complex control flow** is clearer.

---

### **Parallel streams — `parallelStream()`**

**`collection.parallelStream()`** (or **`stream().parallel()`**) splits work for **multi-core** — **only** safe if:

- Operations are **side-effect-free** (or properly synchronised — usually avoid),
- **No** unsafe mutation of **shared** data,
- **Splittable** source behaves well.

**Wrong parallelisation** can cause **wrong answers** and **subtle races**. Exams often test **knowing the risks**, not writing heavy parallel code.

---

### **Common patterns**

- **Filter–map–reduce:** **`filter`** → **`map`** → **`reduce`** (or **`collect`**).
- **Collect to list:** **`.collect(Collectors.toList())`** or **`.toList()`** (Java 16+).
- **Sum / count / average:** primitive streams (**`mapToInt`**, **`IntStream`**, etc.).

```java
double avgLen = sentences.stream()
    .filter(Predicate.not(String::isBlank))
    .mapToInt(String::length)
    .average()
    .orElse(0.0);
```

---

## 2. EXAM-STYLE QUESTIONS (WITH MODEL ANSWERS)

### **Q1.** What is a **functional interface**? Why can a **lambda** be assigned to a variable of type **`Predicate<String>`**?

**Model answer:** A **functional interface** has **exactly one abstract method**. **`Predicate<String>`**’s SAM is **`boolean test(String t)`**. A lambda **`s -> s.length() > 0`** matches that **signature** and **semantics**, so the compiler treats it as an **instance** of **`Predicate<String>`** (via **invokedynamic** / generated calls — implementation detail not usually required). **`@FunctionalInterface`** documents and validates the SAM property.

---

### **Q2.** Explain **`map`** vs **`flatMap`** on a **`Stream<String>`** where each string holds **comma-separated tokens**.

**Model answer:** **`map`** would turn **each string** into **one object** (e.g. **`String[]`** or **`List<String>`**) — result is **`Stream<List<String>>`** or **`Stream<String[]>`**. **`flatMap`** takes each element to a **stream** and **concatenates** those streams into **one flat `Stream<String>`** of all tokens. So **`flatMap`** is for **one-to-many** then **flatten**; **`map`** is **one-to-one**.

---

### **Q3.** Why are **streams lazy**? Give one **benefit** of laziness.

**Model answer:** **Intermediate operations** build a **pipeline** without processing data immediately. **Computation** begins when a **terminal operation** executes. **Benefits:** (1) **Short-circuiting** operations can **stop early** (`findFirst`, `anyMatch`). (2) **Fusion** — the runtime can **optimise** the pipeline without storing **all** intermediate collections. (3) **Readability** — separate **what** stages exist from **when** they run.

---

### **Q4.** What is the difference between **`forEach`** and **`map`**?

**Model answer:** **`map`** is an **intermediate** operation returning a **new stream** of **transformed** elements (**`Function`**) — it **produces values** for downstream steps. **`forEach`** is **terminal** and takes a **`Consumer`** — it **consumes** each element for an **action** (often **side effects**) and returns **`void`**. You **cannot** chain after **`forEach`**.

---

### **Q5.** When **parallel streams** can produce **wrong results**, what programming mistakes should you mention?

**Model answer:** **Mutating shared** variables from **lambda bodies** (e.g. **`total++`** captured from outside) causes **data races**. **Non-associative** or **non-deterministic** **combiners** in **`reduce`** can break parallel correctness. **Order-dependent** side effects (printing order assumed) may **differ** in parallel. **IO** or **synchronised** heavy work can **destroy speedup**. Correct style: **pure** functions, **immutable** accumulation, **`collect`** with **thread-safe** collectors, or avoid **parallel** unless safe.

---

## 3. MUST-KNOW KEY POINTS

- **Functional interface** = **one abstract method** (SAM); target for **lambdas**.
- **`@FunctionalInterface`** — intent + **compiler** validation.
- **Lambda:** **`(x) -> expr`** or **`(x) -> { ... }`**.
- **Method references:** **`Class::static`**, **`inst::meth`**, **`Type::instanceMethod`**, **`Type::new`**.
- **Stream pipeline:** **source** → **intermediate** (lazy) → **terminal** (eager execution trigger).
- **Common creators:** **`collection.stream()`**, **`Arrays.stream`**, **`IntStream.range`**.
- **Intermediate:** **`filter` (Predicate)**, **`map` (Function)**, **`flatMap`**, **`sorted`**, **`distinct`**.
- **Terminal:** **`forEach`**, **`reduce`**, **`collect`**, **`count`**, **`sum`/`average`**, **`toList()`** (16+).
- **Lazy streams** — work runs at **terminal**; enables **short-circuit**.
- **Declarative** style vs **imperative** loops; **stateless** ops preferred for **parallel**.
- **`parallelStream()`** — **multi-core** but **correctness** requires **care**.

---

## 4. HIGH-PRIORITY TOPICS

### 🔴 **Must Know**
- **Functional interface** definition + examples (**`Predicate`**, **`Function`**, **`Consumer`**)
- **Lambda** syntax and **target typing**
- **Stream** pipeline: **intermediate vs terminal**
- **`filter` / `map` / `reduce`** meanings
- **Laziness** and **when** computation runs
- **`map` vs `flatMap`**

### 🟡 **Important**
- **Method references** (four forms)
- **`@FunctionalInterface`**
- **Primitive streams** (**`IntStream`**) for **`sum`/`average`**
- **`collect` vs `reduce`** — **mutable reduction** vs **fold**
- **Streams vs loops** — trade-offs (clarity, **mutation**, **debugging**)

### 🟢 **Useful**
- **`distinct`**, **`sorted`** (**stateful** implications)
- **`toList()`** vs **`Collectors.toList()`** (mutability / API level differences — exam “awareness”)
- **Parallel stream** pitfalls (**shared mutation**)

---

## 5. TOPIC INTERCONNECTIONS & BIGGER PICTURE

- **Functional interfaces** connect **lambdas** to the **Collections** API (**`forEach`**, **`removeIf`**, **`replaceAll`**, …).
- **Streams** build on **iterators** and **internal iteration** — complementary to **enhanced for-loops** you learned earlier.
- **`Optional`** often appears with **`reduce`** and **terminal** ops that may **empty** — same “explicit absence” story as elsewhere in Java APIs.
- **Generics** make **`Stream<T>`**, **`Function<T,R>`**, etc. **type-safe** — lambdas inherit those constraints.
- **Parallel streams** tie to **concurrency** courses later; OOP module expects **risk awareness**, not expert **fork/join** tuning.

---

## 6. EXAM STRATEGY TIPS

- For “**what does this pipeline print?**” trace **order**: remember **lazy** until **terminal**; **short-circuit** ops **stop early**.
- Label each method: **`filter` → Predicate**, **`map` → Function** — examiners reward **correct interface vocabulary**.
- If asked **parallel**, mention **shared mutable state** and **non-associative reduce** as **classic wrong answers**.
- Contrast **`map` (1:1)** vs **`flatMap` (1:many flattened)`** with a **tiny** example (e.g. **lines → words**).
- When writing **collect**, if unsure, **`toList()`** is the **simple** Java 16+ answer; older style: **`Collectors.toList()`**.
- **Method reference** questions: check **arity** — **`System.out::println`** matches **`Consumer<String>`** for **`String`** stream.

---

*End of notes — Lambdas & Streams (Slides 19).*
