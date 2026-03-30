# Core Java Language — COMP0004

*Lecture-style notes aligned with core language slides: types, variables, control flow, methods, collections, generics basics, and program entry.*

---

## 1. COMPLETE TOPIC SUMMARIES

### **Java’s type system: strong + static**

- **Static typing** — every variable has a **compile-time-known type**; many errors are caught **before** runtime.
- **Strong typing** — conversions are **controlled**; unsafe mixes (e.g. treating arbitrary bits as unrelated types) are largely rejected. In introductory comparisons, Java is often **stricter than C** in everyday code (e.g. **`boolean`** is not interchangeable with **`int`**).

> **Beginner pitfall:** “**Static**” refers to **compile-time checking**, not the Java keyword **`static`**.

---

### **Primitive types — values live in the variable**

Primitives are **built-in**, **non-object** value types (for the eight listed below). Variables of primitive type **store the value directly** (in the JVM’s implementation terms: typically in **stack frames** or **registers**, not as heap objects).

| Type | Typical notes |
|------|----------------|
| **`byte`** | 8-bit signed integer |
| **`short`** | 16-bit signed integer |
| **`int`** | 32-bit signed integer; default integer choice |
| **`long`** | 64-bit signed; literals often need **`L` suffix** (e.g. `10L`) |
| **`float`** | 32-bit IEEE float; literals may use **`f` suffix** (e.g. `1.5f`) |
| **`double`** | 64-bit IEEE float; default floating choice |
| **`char`** | single 16-bit **Unicode code unit** (UTF-16 unit); literals use **single quotes** `'A'` |
| **`boolean`** | **`true` / `false` only** — not numeric in Java |

```java
int count = 42;
double x = 0.1 + 0.2;   // floating-point caveats still exist
boolean ok = true;
char c = 'Z';
```

---

### **Class (reference) types — variables hold references**

Types like **`String`**, **`ArrayList<E>`**, **`HashMap<K,V>`**, and user-defined classes are **reference types**. A variable stores a **reference** (think “address-like handle”) to an **object** typically allocated on the **heap**.

```java
String s = "hello";              // s refers to a String object
ArrayList<Integer> xs = new ArrayList<>();  // xs refers to list object
```

Two variables can **refer to the same object**:

```java
ArrayList<Integer> a = new ArrayList<>();
ArrayList<Integer> b = a;   // alias: same object
```

---

### **Variables: local, instance, parameter**

- **Local variables** — declared inside a **block**/**method**; must be **definitely assigned** before use; lifetime ends when the block/method frame ends.
- **Parameters** — special locals initialised by the caller; also require definite assignment rules from the caller’s arguments.
- **Instance fields (instance variables)** — per-object state; lifetime tied to the **object** (until GC-eligible).

```java
public class Counter {
    private int value;            // instance field (per object)

    public void bump(int delta) { // delta is a parameter
        int tmp = value + delta;  // tmp is local
        value = tmp;
    }
}
```

---

### **Type inference with `var` (Java 10+)**

**`var`** asks the compiler to infer the **static type** from the **right-hand side** — it is **not** dynamic typing.

```java
var name = "Ada";        // inferred as String
var xs = new ArrayList<String>(); // inferred as ArrayList<String>
```

Rules of thumb:

- Still **statically typed** — you cannot reassign incompatible types later.
- Use when it **improves readability**; avoid when the RHS type is **unclear**.

---

### **Operators — C-like, but mind Java’s types**

Java reuses many C operators: **arithmetic** `+ - * / %`, **comparison** `< > <= >=`, **equality** `== !=`, **logical** `&& || !`, **bitwise** (for integers), etc. **Precedence** is broadly similar to C; when unsure, **parentheses**.

**Integer division:**

```java
int q = 7 / 3;   // 2, not 2.333...
```

For floating results, promote to **`double`**:

```java
double q = 7.0 / 3.0;
```

---

### **`==` vs `.equals()` — the classic Java trap**

- For **primitives**, **`==`** compares **values**.
- For **references**, **`==`** compares **reference equality** (same object?), **not** usually “same contents”.

```java
String a = new String("hi");
String b = new String("hi");
boolean sameRef = (a == b);        // false (distinct objects)
boolean sameText = a.equals("hi"); // true (value/content comparison)
```

**Strings:** prefer **`equals`** for text equality; **`compareTo`** for **lexicographic ordering** (dictionary order):

```java
int cmp = s1.compareTo(s2); // <0 if s1 < s2, 0 if equal, >0 if s1 > s2
```

---

### **Control flow — `if`, `switch` statement, `switch` expression**

**`if / else`** — standard branching.

**`switch` statement** — chooses among discrete cases (traditionally **`int`/enum/String`**-friendly patterns; newer features expand expressiveness).

**`switch` expression (Java 14+)** — `switch` can **produce a value**, often with **arrow syntax** and compile-time exhaustiveness checks for **`enum`**/`sealed` patterns in advanced use.

**Pattern matching for `switch` (modern Java)** — allows **`case` patterns** (types, guarded conditions) depending on language level; exams may focus on the **concept**: **safer, more expressive dispatch** than long `if-else` chains.

```java
String label = switch (day) {
    case 1, 2, 3, 4, 5 -> "weekday";
    case 6, 7          -> "weekend";
    default            -> "unknown";
};
```

---

### **Loops — `while`, `do-while`, `for`, enhanced `for`**

```java
while (condition) { }

do { } while (condition);   // body runs at least once

for (int i = 0; i < n; i++) { }

int[] arr = {1, 2, 3};
for (int x : arr) {        // enhanced for / for-each
    System.out.println(x);
}
```

**Enhanced `for`** also iterates **`Iterable`** types like **`ArrayList`**.

---

### **`break` and `continue`**

- **`break`** exits the **nearest** loop or **`switch`**.
- **`continue`** skips to the **next iteration** of the nearest loop.

---

### **Scope and lifetime (introductory view)**

- **Block scope** — locals exist from declaration to **closing brace**.
- **Method scope** — parameters/locals live for the **method activation**.
- **Class scope** — **static members** belong to the class; **instance fields** belong to each **object** for the object’s lifetime (until eligible for GC).

---

### **Methods — instance vs static (intro level)**

- **Instance methods** operate on a specific object’s state (have **`this`** implicitly).
- **Return types** — `void` returns nothing; otherwise **`return`** must provide a value matching the declared type.
- **Parameter types** are checked **statically** at compile time.

```java
public int add(int a, int b) {
    return a + b;
}
```

---

### **Data structures overview**

**Arrays** — fixed length; **`[]` syntax**; elements can be primitives or references.

```java
int[] nums = new int[10];
String[] words = {"a", "b"};
```

**`ArrayList<T>`** — growable **indexed** list (reference type); use **`add`**, **`get`**, **`size`**.

**`HashMap<K,V>`** — **key → value** map with fast expected lookup by key.

Both are **generic** in modern Java: **`T`**, **`K`**, **`V`** are **type parameters** enforced by the compiler.

---

### **Generics basics**

**Generics** let you write **type-safe** collections/APIs: **`ArrayList<String>`** rejects accidental insertion of non-**`String`** (at compile time, for typical non-legacy APIs).

```java
ArrayList<String> names = new ArrayList<>();
names.add("Ada");
// names.add(123); // compile error
```

**Raw types** (e.g. plain **`ArrayList`**) exist for legacy interop — avoid in new code you write in COMP0004.

---

### **Autoboxing and unboxing**

Wrapper types (**`Integer`**, **`Double`**, …) correspond to primitives. Java **autoboxes** primitives to wrappers and **unboxes** back when contexts demand it — convenient but not free at runtime.

```java
Integer a = 5;    // boxing
int b = a;        // unboxing
```

**Pitfall:** **`==`** between **`Integer`** objects can surprise you; prefer **`equals`** for wrapper **value** comparisons, or use **`int`** where possible.

---

### **`main` and command-line arguments**

```java
public static void main(String[] args) {
    for (String arg : args) {
        System.out.println(arg);
    }
}
```

**`args[0]`** is the **first** user-provided argument (after the class name on the CLI), not the program name.

---

## 2. EXAM-STYLE QUESTIONS (3–5 with model answers)

### Q1 — Primitives vs references

**Question:** Explain the difference between a variable of type **`int`** and a variable of type **`String`** in terms of **what the variable stores** and **where the data typically lives**.

**Model answer:** An **`int`** variable stores the **integer value directly** as a primitive. A **`String`** variable stores a **reference** to a **`String` object**; the object’s characters and internal data live on the **heap**, managed by the **GC**. Multiple **`String`** variables can reference the **same** object; **`==`** on references tests **alias**, not text equality.

---

### Q2 — `==` vs `equals`

**Question:** For **`int`**, **`Integer`**, and **`String`**, explain when to use **`==`** versus **`.equals()`**. Give one example where **`==`** on **`String`** is misleading.

**Model answer:** For **`int`**, use **`==`** (value comparison). For **`Integer`**, prefer **`int`** primitives for numeric logic; if you have **`Integer` objects**, use **`.equals`** for **value equality** (or unbox safely). For **`String`**, use **`.equals`** for **text equality**; **`==`** only checks **reference equality**. Example: `new String("a") == new String("a")` is **`false`** even though the text matches, because they are distinct objects.

---

### Q3 — Definite assignment

**Question:** Why does Java reject reading a **local variable** before it is assigned, even if you “know” a path sets it? Give a minimal code sketch illustrating **compile-time error**.

**Model answer:** The compiler enforces **definite assignment** to prevent **undefined reads**. It analyses **all paths** conservatively. Example:

```java
int x;
if (Math.random() > 0.5) {
    x = 1;
}
System.out.println(x); // compile error: x might not have been assigned
```

---

### Q4 — Enhanced `for` and `ArrayList`

**Question:** Write a Java snippet that creates an **`ArrayList<Integer>`**, adds three integers, and prints each using an **enhanced for-loop**. Explain one difference versus iterating with an **index `for`**.

**Model answer:**

```java
ArrayList<Integer> xs = new ArrayList<>();
xs.add(2);
xs.add(3);
xs.add(5);
for (int v : xs) {
    System.out.println(v);
}
```

An **enhanced for** iterates **elements** directly (clean for read-only traversal). An **index loop** exposes **`i`** so you can **modify by index**, **inspect neighbours**, or parallel arrays; it is also the typical pattern when you need the **index** itself.

---

### Q5 — Generics + autoboxing

**Question:** Explain why **`ArrayList<int>`** is invalid in Java and what you write instead. What happens when you call **`add(3)`** on an **`ArrayList<Integer>`**?

**Model answer:** **Generic type parameters** must be **reference types**; **`int`** is a **primitive**, so **`ArrayList<int>`** is illegal. Use **`ArrayList<Integer>`**. Calling **`add(3)`** applies **autoboxing**: the **`int` literal** is converted to an **`Integer`** instance (cached for small values in typical implementations) and stored in the list.

---

## 3. MUST-KNOW KEY POINTS

- Java is **statically + strongly typed**; many mistakes are **compile-time errors**.
- **Eight primitives** — know names + that **`boolean` is not numeric**.
- **Reference variables** store **references** to heap objects; **`==`** compares references for objects.
- Use **`.equals`** / **`compareTo`** appropriately for **object value / ordering** semantics (especially **`String`**).
- **Locals/params** need **definite assignment**; fields get default values.
- **`var`** infers **static** types; it does not create dynamic typing.
- **Integer division** truncates; **operator precedence** matches C-like habits — parenthesise when unsure.
- Control: **`if`**, **`switch`**, loops; **`break`/`continue`** meanings.
- **Arrays** fixed; **`ArrayList`** growable; **`HashMap`** maps keys to values.
- **Generics** enforce **`ArrayList<String>`**-style safety; avoid **raw types** in new code.
- **Autoboxing** connects **`int` ↔ `Integer`**; beware **`==`** on wrappers.
- **`main(String[] args)`** reads **CLI arguments**.

---

## 4. HIGH-PRIORITY TOPICS

| Priority | Topic | Why it matters |
|----------|--------|----------------|
| 🔴 **Must know** | **Primitives vs references + `==` vs `equals`** | Highest-frequency Java exam trap. |
| 🔴 **Must know** | **Definite assignment for locals** | Classic compiler-error reasoning question. |
| 🔴 **Must know** | **`String` comparison (`equals`, `compareTo`)** | Everyday correctness + exam favourite. |
| 🔴 **Must know** | **Arrays vs `ArrayList` vs `HashMap` (when to use)** | Shapes how you model data in OOP labs. |
| 🟡 **Important** | **Loops + `break`/`continue`** | Control-flow tracing questions. |
| 🟡 **Important** | **`switch` statement vs expression + modern patterns** | Increasingly common in modern Java curricula. |
| 🟡 **Important** | **Generics syntax + why `ArrayList<int>` fails** | Shows understanding of type parameters. |
| 🟡 **Important** | **Autoboxing/unboxing + wrapper pitfalls** | Links collections + primitives. |
| 🟢 **Useful** | **`var` inference style rules** | Mostly readability + “still static” clarification. |
| 🟢 **Useful** | **Operator precedence / mixed numeric promotions** | Smaller MCQs; know **`int` division** cold. |

---

## 5. TOPIC INTERCONNECTIONS & BIGGER PICTURE

- **Types + references** underpin **OOP state**: fields hold either **primitives** or **references** to other objects (**composition** graphs).
- **Collections + generics** foreshadow **interfaces** (`List`, `Map`), **iterators**, and **API design** (returning `List<T>` rather than concrete types).
- **Control flow + definite assignment** connect to **compiler theory** (reachable paths) and later **exception** paths (when `finally`/`try` affect assignment).
- **`equals` semantics** leads to **`hashCode` contracts** when you use **`HashMap` with custom keys** (often a later lecture).
- **`main` + `args`** is the bridge to **CLI tools**, **testing harnesses**, and **build systems** (Gradle/Maven) running your classes.

---

## 6. EXAM STRATEGY TIPS

- **State the rule in one line, then example:** e.g. “**`==` on references is alias**; therefore **`String` text uses **`equals`**.”
- **Trace loops on paper** with a small table: **index**, **variable values**, **condition**.
- **Watch types in mixed expressions:** **`int` division** vs **`double` division** is a classic gotcha.
- **Generics:** if asked “why compile error?”, mention **type parameter must be reference type** / **incompatible generic assignment**.
- **Boxing:** if a question involves **`ArrayList<Integer>`** and **`==`**, explicitly mention **reference vs value** and prefer **`equals`** or unbox to **`int`**.
- **Command-line args:** remember **`args[0]`** is first user argument; **`args.length`** is count.

---

*End of notes — Core Java Language (COMP0004).*
