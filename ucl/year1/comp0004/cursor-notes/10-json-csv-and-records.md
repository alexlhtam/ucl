# JSON, CSV, and Java Records — COMP0004 Object-Oriented Programming (UCL)

*Lecture-style notes aligned with Slide decks **15** and **10(1)**: **JSON** as a data interchange format, **parsing/generation in Java**, **CSV** tabular files, and **Java Records** as **immutable data carriers** — including **DTO** usage and **shallow immutability**.*

---

## 1. COMPLETE TOPIC SUMMARIES

### **JSON — JavaScript Object Notation**

**JSON** (**JavaScript Object Notation**) is a **lightweight**, **text-based** format for structured data. It is **language-independent** (despite the name): many languages, including **Java**, read and write JSON for **config files**, **REST APIs**, and **data exchange** between systems.

**Why JSON is popular:**

- **Human-readable** (unlike many binary formats).
- **Maps cleanly** to common data structures: **objects** (maps of names to values), **arrays** (ordered lists), **strings**, **numbers**, **booleans**, and **`null`**.

```json
{
  "colour": "blue",
  "active": true,
  "scores": [10, 20, 30],
  "meta": { "version": 1 }
}
```

---

### **JSON structure — objects, arrays, nesting**

- **Name–value pairs** — written as **`"name": value`**. Names are **strings in double quotes**.
- **Objects** — surround zero or more pairs with **`{ }`**, comma-separated.
- **Arrays** — ordered values in **`[ ]`**, comma-separated.
- **Nesting** — values may be **objects** or **arrays**, so JSON naturally represents **hierarchical** data (unlike flat **CSV**).

> **Beginner trap:** JSON requires **double quotes** for strings; **single quotes** are **not** standard JSON.

---

### **JSON in Java — parsing and generating**

Java’s standard library did not always include a single “official” high-level JSON API for all use cases; in practice, courses and industry use **libraries**:

| Library | Typical role |
|---------|----------------|
| **Jackson** | Very common in enterprise / Spring; **`ObjectMapper`** maps JSON ↔ Java objects. |
| **Gson** | Google’s library; simple **`fromJson` / `toJson`** ergonomics. |
| **`org.json`** | Lightweight; **`JSONObject` / `JSONArray`** for manual tree-style access. |

**Exam-level idea:** **deserialisation** = JSON text → Java objects; **serialisation** = Java objects → JSON text. You should be able to **name** a library and describe **why** manual string concatenation is fragile (escaping quotes, nesting, commas).

```java
// Illustrative Gson-style idea (exact API depends on library version / imports)
// String json = "{ \"x\": 1, \"y\": 2 }";
// Gson gson = new Gson();
// Point p = gson.fromJson(json, Point.class);
```

---

### **Reading and writing JSON files in Java programs**

Conceptually:

1. **Read** the file into a **`String`** (e.g. **`Files.readString(path, UTF_8)`**) or stream it for large inputs.
2. **Parse** with a **library** into **`JSONObject`** / **`JsonNode`** / your **DTO** type.
3. **Write** by **serialising** your objects to a **`String`** and **`Files.writeString`** (or library methods that write to streams).

Always use **UTF-8** for JSON files on disk unless an external spec forces otherwise.

---

### **CSV — Comma-Separated Values**

**CSV** (**Comma-Separated Values**) is a **simple tabular** format: each **row** is usually one line; **columns** are separated by **commas** (sometimes **`;`** or **tab** — “TSV”).

```text
name,email,score
Alex,alex@ucl.ac.uk,92
Sam,sam@ucl.ac.uk,88
```

**Headers** — the first row may name columns; your parser can **skip** it or use it to index fields.

**Escaping** — fields containing delimiters or newlines are often wrapped in **double quotes**; quotes inside fields may be **doubled**. This is why **`split(",")`** alone is not a full CSV solution.

**When CSV vs JSON:** **CSV** is compact for **flat tables**; **JSON** handles **nesting** and **variable structure** more naturally.

---

### **Java Records (Java 16+) — data-centric classes**

A **record** is a **specialised** kind of class for **immutable data objects** (“**data carriers**”). The compiler generates a lot of boilerplate for you.

```java
public record Point(int x, int y) { }
```

**What you get automatically (conceptual checklist):**

- A **canonical constructor** with all **components** in order.
- **Accessor methods** named like the components: **`x()`**, **`y()`** — **not** `getX()` unless you add it yourself.
- **`equals`**, **`hashCode`**, **`toString`** derived from the **state** (the components).

Records are **`final`** — you **cannot** extend a record (subclassing is forbidden). A record **can implement interfaces**.

---

### **Shallow immutability**

Record **fields** corresponding to components behave like **`final`** state: you **cannot reassign** `x` after construction.

**Shallow** means: if a component has **reference type** (e.g. **`List<String>`**), the **reference** cannot change to point to another list, but the **contents of that list** might still be **mutable** unless you enforce otherwise (defensive copies, **unmodifiable** collections).

```java
public record Bag(List<String> items) {
    public Bag {
        items = List.copyOf(items); // defensive copy → safer immutability story
    }
}
```

Exam answers should use the phrase **shallow immutability** and give a **mutated list** counterexample if the record only stores the reference.

---

### **Compact constructors — validation without repeating assignments**

Records allow a **compact canonical constructor** (no parameter list) to **normalise** or **validate** components before the implicit field assignment completes.

```java
public record Grade(String module, int mark) {
    public Grade {
        if (mark < 0 || mark > 100) {
            throw new IllegalArgumentException("mark out of range");
        }
        module = module.trim();
    }
}
```

Use this for **invariants** (ranges, non-blank strings) without manually listing **`this.x = x`** for every field.

---

### **Records vs regular classes — when to use each**

| Use **records** when… | Prefer a **regular class** when… |
|------------------------|-----------------------------------|
| The type is mostly **data** with stable fields | You need **mutable** state or rich lifecycle |
| **`equals`/`hashCode`/`toString`** should track **all** components | **Identity** matters more than value equality |
| You want **minimal boilerplate** | You need **inheritance** from a **class** (records cannot `extend` classes) |
| You are modelling **DTOs**, **events**, **coordinates** | You are building **frameworks** with complex hierarchies |

---

### **Records with extra methods — still “just data plus behaviour”**

Records can declare **instance methods**, **`static`** methods, and **nested types** (subject to Java rules). Example: derived values.

```java
public record Point(int x, int y) {
    public double distanceFromOrigin() {
        return Math.hypot(x, y);
    }
}
```

---

### **Records with JSON / CSV — DTOs**

A **DTO** (**Data Transfer Object**) carries data across boundaries (file, network, modules). Records are excellent **DTOs** because **serialisation libraries** can map JSON fields ↔ record components with little code, and **`equals`/`hashCode`** make testing and collections pleasant.

For **CSV**, you might parse a line into **`new Person(name, email, score)`** once fields are validated — the record documents the **shape** of a row.

---

## 2. EXAM-STYLE QUESTIONS (3–5 with model answers)

### **Q1. Define JSON and explain two reasons it is widely used for data interchange.**

**Model answer:** **JSON** is a **text-based**, **lightweight** data format built from **objects**, **arrays**, **strings**, **numbers**, **booleans**, and **`null`**. It is widely used because it is **human-readable** and **easy to parse/generate** in many programming languages, and it maps naturally to **nested structures** (unlike flat **CSV**), making it ideal for **web APIs** and **configuration**.

---

### **Q2. Why should JSON typically be read/written using a library rather than manual string concatenation?**

**Model answer:** JSON requires **correct syntax** — quotes, commas, brackets, and **escaping** special characters inside strings. Manual concatenation is **error-prone** and hard to maintain when data is **nested** or **optional**. Libraries apply consistent **serialisation rules**, reduce **security/format** bugs, and usually support mapping to **Java objects** automatically.

---

### **Q3. What does `public record Point(int x, int y) { }` cause the compiler to generate?**

**Model answer:** A **canonical constructor** **`Point(int x, int y)`**, **accessor methods** **`x()`** and **`y()`**, and **`equals`**, **`hashCode`**, and **`toString`** implementations based on the **components**. The record class is **`final`** and its **component state** is **immutable** in the sense that those fields are not reassigned after construction.

---

### **Q4. Explain shallow immutability for records using a `List` field example.**

**Model answer:** A record is **shallowly immutable** if a component is a **reference** to a **mutable object** like **`List`**. The record cannot replace the **reference** after construction, but code holding another reference to the **same list** could **`add`** elements unless the record **defensively copies** on construction (e.g. **`List.copyOf`**) and avoids leaking internal **mutators**. True **deep immutability** requires **immutable** field types or copying.

---

### **Q5. Compare JSON and CSV for representing student marks for five modules per student.**

**Model answer:** **CSV** fits a **flat table** (`studentId, M1, M2, ...`) and is compact in spreadsheets. **JSON** fits if each student has **variable** numbers of modules, **nested** metadata (exam board, resits), or **hierarchical** structures — at the cost of **more syntax characters**. CSV is weaker when fields contain **commas** or **multiline** text unless **proper escaping** is implemented.

---

## 3. MUST-KNOW KEY POINTS

- **JSON** = hierarchical **text** interchange; **objects `{}`**, **arrays `[]`**, **quoted names/strings**.
- **Parse/serialise JSON** with a **library** (**Jackson**, **Gson**, **`org.json`**) — not ad-hoc concatenation for real programs.
- **CSV** = **rows/lines**, **delimiter-separated** columns; watch **headers**, **quotes**, and **escaped delimiters**.
- **`record`** declares a **final**, **data-centric** type; accessors are **`name()`**, not JavaBean **`getName()`** by default.
- Compiler supplies **constructor**, **`equals`**, **`hashCode`**, **`toString`** from **components**.
- **Shallow immutability** — **mutable referenced objects** can still change unless you **copy** / use **immutable** types.
- **Compact constructor** = validate/normalise **without** repeating field assignments.
- **Records** shine as **DTOs** for **JSON/CSV**-backed data; use **classes** when **inheritance** or **mutable** state dominates.

---

## 4. HIGH-PRIORITY TOPICS (🔴 / 🟡 / 🟢)

| Priority | Topic | Why it matters |
|----------|--------|----------------|
| 🔴 | **JSON structure (objects/arrays/nesting)** | Diagram / “valid JSON?” questions. |
| 🔴 | **Record syntax + generated members** | Short code completion and “what prints?” |
| 🔴 | **Shallow immutability + `List` pitfall** | Classic conceptual trap. |
| 🟡 | **Library-based JSON (why not string hacks)** | Explain / justify in prose. |
| 🟡 | **CSV headers + escaping + `split` limits** | Compare robust vs naïve parsing. |
| 🟡 | **Compact constructor validation** | Small method completion tasks. |
| 🟢 | **DTO pattern with records** | Design justification questions. |
| 🟢 | **Records vs classes decision** | Trade-off tables in exams. |
| 🟢 | **UTF-8 for JSON on disk** | One-line “best practice” marks. |

---

## 5. TOPIC INTERCONNECTIONS

- **File handling (Note 09):** JSON/CSV files are **text**; use **`Files.readString`**, **`BufferedReader`**, and **UTF-8** — same **encoding** and **try-with-resources** story.
- **Exceptions:** parsing can throw **`IOException`** (file) and runtime parse errors (bad JSON) depending on library — links to **checked vs unchecked** reasoning.
- **Collections:** JSON arrays often become **`List`**; CSV rows become **`List<RecordType>`** or **`Map`** keyed by id.
- **OOP design:** records encourage **value-oriented** modelling; **classes** remain for **behaviour-heavy** or **mutable** domains — compare to **inheritance/polymorphism** topics when a type hierarchy is required.
- **Generics (where taught):** libraries map JSON to **`TypeToken`** / **`ParameterizedType`** patterns — usually “awareness” level in year one.

---

## 6. EXAM STRATEGY TIPS

- **JSON questions:** start by classifying values as **string/number/object/array/bool/null** before parsing questions; watch **commas** and **matching braces/brackets**.
- **Record questions:** list **four** compiler-generated items (**constructor, accessors, equals, hashCode, toString** — grouping equals/hashCode/toString is fine) for full marks.
- **Immutability questions:** always mention **references vs object contents**; offer **`List.copyOf`** as a standard fix.
- **CSV questions:** if you use **`split`**, **state assumptions** explicitly; otherwise explain **quoted fields**.
- **Comparison questions (JSON vs CSV):** use **flat vs nested** and **schema flexibility** as your central axis — one tight paragraph beats a bullet dump.
- **Code style:** show **`public record Name(...)`** exactly; use **`()` accessors** in examples to prove you know record conventions.

---

*These notes summarise typical COMP0004 delivery; always follow your term’s official slides and lab specifications for required libraries (e.g. Gson vs Jackson) and record exercises.*
