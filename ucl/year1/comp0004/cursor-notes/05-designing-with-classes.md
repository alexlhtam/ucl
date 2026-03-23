# Designing with Classes — COMP0004 Object-Oriented Programming (UCL)

*Lecture-style notes aligned with **Slide deck 7**: moving from “writing a class” to **object-oriented design (OOD)** — requirements, analysis, **UML**, multi-class structure, and core Java mechanics (**constructors**, **`static`**, **`null`**, copying, **getters** / **immutability**).*

---

## 1. COMPLETE TOPIC SUMMARIES

### **Object-oriented design (OOD)** — what it is

**Object-oriented design (OOD)** is the disciplined activity of deciding **which classes** you need, **what each one is responsible for**, and **how they connect**, so that your program stays understandable and changeable as requirements evolve. It sits between **analysis** (“what problem are we solving?”) and **implementation** (“how do we code it in Java?”).

A useful mental model:

- **Analysis** produces a **conceptual model** of the domain (nouns/verbs, relationships).
- **Design** turns that model into **software abstractions** (classes, interfaces, packages) with clear **contracts**.
- **Implementation** expresses those abstractions in **Java** using **encapsulation**, **constructors**, **collections**, and so on.

---

### **The software development cycle** (high level)

A common teaching progression (and industry simplification) is:

1. **Requirements** — capture **what** the system must do (and constraints).
2. **Analysis** — understand the domain; identify **candidate classes** and **relationships**.
3. **Design** — refine abstractions, assign **responsibilities**, sketch **UML**, plan APIs.
4. **Implementation** — write Java (classes, methods, tests).
5. **Testing** — verify behaviour (**unit**, **integration**, acceptance).

> **Beginner intuition:** Requirements are the “menu of features”; design is the “floor plan”; code is the “building.” Changing the floor plan after construction is expensive — good early design reduces rework.

---

### **Requirements: functional vs non-functional**

- **Functional requirements** describe **observable behaviour**: inputs, outputs, workflows, business rules.  
  *Example:* “A customer can place an order containing multiple line items.”

- **Non-functional requirements** describe **qualities** and constraints: performance, security, usability, maintainability, portability, legal compliance.  
  *Example:* “Order totals must compute in under 50 ms for typical basket sizes on lab machines.”

Exams often want you to **classify** a sentence as functional vs non-functional and justify it in one line.

---

### **MoSCoW prioritisation**

**MoSCoW** is a lightweight way to prioritise scope when time is limited:

| Priority | Meaning |
|----------|---------|
| **Must have** | Non-negotiable for the release / milestone. |
| **Should have** | Important; include unless strong pressure. |
| **Could have** | Nice-to-have if time permits. |
| **Won’t have (this time)** | Explicitly out of scope (prevents scope creep). |

> **Exam tip:** MoSCoW is about **delivery planning**, not Java syntax — but it explains why your coursework might implement only a subset of “dream features.”

---

### **Use cases and user stories**

A **use case** describes an interaction between an **actor** (human or external system) and the system to achieve a goal. Typical elements:

- **Actor** — who initiates or participates.
- **Preconditions** — what must be true before the use case starts.
- **Postconditions** — what must be true after success (and sometimes failure).
- **Main success scenario** — numbered **sequence of steps**.
- **Extensions / alternatives** — variations (e.g. invalid input, item out of stock).
- **Errors / exceptions** — how failures are surfaced or recovered.

A **user story** is a short goal statement, often:  
“As a **\<role\>**, I want **\<capability\>** so that **\<benefit\>**.”

Stories are good for **backlog** communication; use cases are good for **detailed flows** and test scenarios.

---

### **Analysis: finding classes and relationships**

In early OOP courses, a practical technique is:

- Read requirements and highlight **nouns** → candidate **classes** or **attributes**.
- Highlight **verbs** → candidate **methods** or **use-case steps**.
- Ask: **who owns** this data? **who collaborates** with whom?

The output is a **conceptual model**: not necessarily identical to your final Java packages, but a map of **entities** and **associations** you will refine during design.

---

### **UML class diagrams** (what COMP0004 usually expects)

**UML (Unified Modeling Language)** class diagrams show **types** (classes/interfaces) as boxes and **relationships** as lines.

**Associations** — a structural link between types (often navigable in code as a field reference).

**Multiplicity** — how many instances participate (examples):

- **`1`** exactly one  
- **`0..1`** zero or one  
- **`*` or `0..*`** zero or many  
- **`1..*`** one or many  

**Aggregation** — “whole/part” where the part **can exist independently”; drawn with a **hollow (open) diamond** on the “whole” side. (Interpretations vary in industry; in teaching, treat it as **weaker ownership** than composition.)

**Composition** — stronger “whole/part”: the part’s lifetime is tied to the whole; drawn with a **filled diamond** on the whole side.

> **Beginner pitfall:** Do not confuse UML diamonds with Java keywords — they are **design notation**. The Java code might still be plain fields and collections.

---

### **Design principles** (the acronym soup, explained)

These are **guidelines**, not laws — but examiners love them because they test whether you can **justify** structure.

#### **SOLID**

- **S — Single Responsibility Principle (SRP):** a class should have **one reason to change** (one cohesive responsibility). If a class mixes unrelated concerns (e.g. UI + database + business rules), changes become risky.
- **O — Open/Closed Principle (OCP):** design modules **open for extension** but **closed for modification** — often via **interfaces**, **polymorphism**, or **composition**, so new behaviour does not require editing fragile core code constantly.
- **L — Liskov Substitution Principle (LSP):** subtypes must be **substitutable** for their base types **without breaking correctness** of programs that use the base type. (Deeply tied to **inheritance**; see the inheritance notes.)
- **I — Interface Segregation Principle (ISP):** prefer **small, focused interfaces** over one “fat” interface forcing implementors to provide irrelevant methods.
- **D — Dependency Inversion Principle (DIP):** depend on **abstractions** (interfaces) rather than concrete implementations where practical, so high-level policy is not glued to low-level details.

#### **DRY, KISS, YAGNI**

- **DRY (Don’t Repeat Yourself):** avoid duplicating knowledge/logic; duplication means duplicated bug fixes. (Balance: don’t “abstract” too early.)
- **KISS (Keep It Simple, Stupid):** choose the **simplest design** that meets requirements.
- **YAGNI (You Aren’t Gonna Need It):** don’t build features “just in case” without evidence.

#### **High cohesion, low coupling**

- **Cohesion** — how strongly the parts inside a module belong together. **High cohesion** is good: methods/fields support one clear purpose.
- **Coupling** — how much modules depend on each other’s internals. **Low coupling** is good: changes ripple less.

---

### **Designing a multi-class program: `SimpleOrderSystem`**

A classic teaching pattern is a small **domain model** for orders:

- **`Customer`** — identity/contact details; owns a collection of **`Order`** objects.
- **`Order`** — a basket-like object containing **`LineItem`** entries.
- **`LineItem`** — pairs a **`Product`** with a **quantity** and can compute a **subtotal**.
- **`Product`** — something sellable (in your repo’s exercise code, **`Product` is declared `abstract`** — a forward link to **inheritance** topics).

**Collaboration sketch (conceptual):**

```text
SimpleOrderSystem
   ├─ manages lists of Customer / Product (application layer)
Customer
   ├─ List<Order> orders
Order
   ├─ List<LineItem> lineItems
LineItem
   ├─ Product product
   ├─ int quantity
```

This is a clean example of **separation of concerns**: domain objects (`Customer`, `Order`, …) are not responsible for reading console menus; an app class coordinates use cases.

---

### **Constructors in Java** (rules that must be automatic)

- A **constructor** has the **same name as the class**.
- It has **no return type** (not even `void`).
- It runs when you **`new`** a class: `Customer c = new Customer(...);`
- Its job is to put the object into a **valid initial state** (initialise fields, create empty collections, enforce invariants).

---

### **Overloaded constructors**

**Constructor overloading** means multiple constructors with **different parameter lists** (different arity/types). Common patterns:

- a “full” constructor setting all fields, and
- a convenience constructor delegating with **`this(...)`**.

```java
public class Point {
    private final int x;
    private final int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Point() {
        this(0, 0); // delegates to Point(int,int)
    }
}
```

---

### **Default constructor**

If you declare **no constructors at all**, Java provides a **public no-argument default constructor** automatically.

If you declare **any** constructor explicitly, the compiler **does not** add the default unless you write it yourself.

---

### **`this` for fields vs parameters**

The idiom **`this.name = name`** disambiguates a **field** from a **parameter** with the same identifier:

```java
public Person(String name) {
    this.name = name;
}
```

You can also use **`this(...)`** to call another constructor in the same class (**must be the first statement** in that constructor).

---

### **Initializer blocks**

**Instance initializer blocks** run when an object is constructed (before the constructor body), in a defined order with field initialisers. **Static initializer blocks** run once when the class is initialised.

```java
public class Demo {
    private final int x;

    { // instance initializer
        System.out.println("instance init");
    }

    static { // static initializer
        System.out.println("static init (once)");
    }

    public Demo(int x) {
        this.x = x;
    }
}
```

> **Course reality:** know they exist; most coursework prefers explicit constructors for clarity.

---

### **`static`: class variables and constants**

- **Instance variables** — one per object (`each customer has its own name`).
- **Class variables** — declared **`static`**: shared by **all instances** of the class (`static` “belongs to the type”).

**`public static final`** is the usual Java pattern for **named constants**:

```java
public class Keys {
    public static final int MAX_RETRIES = 3;
}
```

---

### **`null` handling and `Optional<T>`**

**`null`** means “no object reference.” Calling a method on `null` causes a **`NullPointerException`**.

Defensive checks:

```java
public void printUpper(String s) {
    if (s == null) {
        System.out.println("(null)");
        return;
    }
    System.out.println(s.toUpperCase());
}
```

**`Optional<T>`** (in `java.util`) models “maybe absent” **explicitly** at the API level:

```java
public Optional<String> findNickname(String id) {
    // ...
    return Optional.empty();
}
```

Use **`Optional`** for **return types** more than for **every field**; overusing it can obscure simple code.

---

### **Shallow copy vs deep copy**

- **Shallow copy** — duplicate the **container/reference structure**, but **inner objects may still be shared**.
- **Deep copy** — recursively duplicate nested objects so copies are fully independent (more work; not always desired).

For **`ArrayList`**, **`new ArrayList<>(list)`** copies the **list structure** (new list object) but **elements are the same references** → typically a **shallow** copy of the collection.

Your `Customer` exercise uses a defensive pattern:

```java
public ArrayList<Order> getOrders() {
    return new ArrayList<Order>(orders);
}
```

This prevents callers from **adding/removing** orders through the returned list **without** your methods — but it does **not** clone the **`Order`** objects themselves (still shallow at element level).

---

### **Getter methods, immutable classes (POJO), “withers”**

- **Getters** expose read access to fields, often as `getX()` / `isX()` for `boolean`.
- A **POJO (Plain Old Java Object)** often means a simple data-focused class with fields + getters/setters (and maybe `equals`/`hashCode`).

An **immutable** object cannot be changed after construction: **`final` fields**, no setters, defensive copying of mutable components if needed.

A **wither** (like a setter but immutable) returns a **new instance** with one field changed:

```java
public record Point(int x, int y) {
    public Point withX(int nx) {
        return new Point(nx, y);
    }
}
```

(Java **`record`** types are a compact way to model immutable data carriers — useful if your course has introduced them.)

---

## 2. EXAM-STYLE QUESTIONS (3–5 with model answers)

### **Q1.** Distinguish **functional** vs **non-functional** requirements. Give one example of each for an online shop.

**Model answer:** **Functional** requirements specify **behaviour** (what the system does): e.g. “Users can add products to a basket and checkout.” **Non-functional** requirements specify **qualities/constraints**: e.g. “Checkout must complete within 2 seconds under normal load” (performance) or “Passwords must be stored hashed” (security).

---

### **Q2.** Explain **aggregation** vs **composition** in UML and what the diamonds mean.

**Model answer:** Both model **whole/part** relationships. **Aggregation** uses an **open (hollow) diamond** and suggests the part **can exist independently** of the whole. **Composition** uses a **filled diamond** and suggests **stronger ownership/lifetime dependence** (the part is conceptually owned by the whole). Multiplicity annotations (e.g. `1..*`) clarify how many parts may attach.

---

### **Q3.** State the **Single Responsibility Principle** and apply it to a class that both reads user input from the console and calculates order totals.

**Model answer:** **SRP** says a class should have **one reason to change**—one cohesive responsibility. A class that both parses console input and computes totals mixes **I/O** with **domain logic**; input formatting changes and pricing rule changes both force edits. Better: separate **`InputReader`/`Ui`** concerns from **`Order`/`PricingService`** domain code, connected by clear method calls.

---

### **Q4.** What is wrong with this constructor header, and what is the correct Java form?

```java
public void Person(String name) { ... }
```

**Model answer:** Constructors **must not** have a return type (not even `void`). `void Person(...)` is treated as a **method named `Person`**, not a constructor, so **`new Person(...)`** will not use it as a constructor. Correct: `public Person(String name) { ... }`.

---

### **Q5.** Explain why returning the internal `ArrayList` directly is risky, and what `new ArrayList<>(orders)` improves.

**Model answer:** Returning the **internal list reference** lets callers **mutate your object’s encapsulated state** (add/remove/clear) bypassing your invariants. Returning **`new ArrayList<>(orders)`** provides a **shallow copy of the list structure**, so callers cannot directly modify **which elements** your field references via list operations—though the **`Order`** objects inside may still be mutable unless you design otherwise.

---

## 3. MUST-KNOW KEY POINTS

- **OOD** bridges **domain understanding** and **Java implementation** via **abstractions** and **relationships**.
- Requirements split into **functional** (behaviour) vs **non-functional** (qualities/constraints); **MoSCoW** prioritises delivery scope.
- **Use cases** structure **actors**, **pre/postconditions**, **main flow**, **alternatives**, and **errors**.
- **UML** communicates **associations**, **multiplicity**, **aggregation (open diamond)**, **composition (filled diamond)**.
- **SOLID / DRY / KISS / YAGNI** + **high cohesion / low coupling** are standard justification vocabulary.
- **Constructors**: same name as class, **no return type**, invoked by **`new`**, can be **overloaded**; default constructor exists **only if** you declare none.
- **`this.field = param`** disambiguates fields; **`this(...)`** chains constructors (first line).
- **`static`** fields/methods belong to the **class**; **`public static final`** for constants.
- **`null`** requires careful checks; **`Optional<T>`** can document “absent” results in APIs.
- Returning **`new ArrayList<>(internal)`** is a common **defensive copy** pattern (**shallow** at element level).
- **Getters/setters** vs **immutability** vs **withers** expresses how you manage change safely.

---

## 4. HIGH-PRIORITY TOPICS (🔴 Must Know / 🟡 Important / 🟢 Useful)

### 🔴 **Must Know**

- **Development cycle:** Requirements → Analysis → Design → Implementation → Testing  
- **Functional vs non-functional** requirements  
- **UML:** associations + **multiplicity** + **aggregation vs composition** (diamonds)  
- **Constructor rules**, **overloading**, **default constructor** behaviour  
- **`this` field initialisation idiom**  
- **`static` vs instance** fields; **`public static final` constants**  
- **`null` safety** basics + why **defensive copies** of collections matter  

### 🟡 **Important**

- **Use cases / user stories** structure (actor, pre/post, steps, alternatives)  
- **MoSCoW** prioritisation  
- **SRP** + **high cohesion / low coupling** (frequent short-answer prompts)  
- **OCP, LSP, ISP, DIP** at “define + small example” level  
- **DRY, KISS, YAGNI** as trade-off heuristics  
- **Initializer blocks** (recognise/explain execution order at a high level)  
- **`Optional<T>`** as an API style for absent values  

### 🟢 **Useful**

- Multi-class design narratives like **`SimpleOrderSystem`** as an exam story problem  
- **Immutable objects**, **POJO** terminology, **wither** methods / **`record`** as modern immutability  

---

## 5. TOPIC INTERCONNECTIONS & BIGGER PICTURE

- **Requirements → use cases → analysis classes** is the same pipeline you later validate with **tests** (behaviour described early becomes **test scenarios**).
- **UML relationships** often become **fields** (`Customer` has `List<Order>`), and multiplicity warns you about **`null`**, empty collections, and **encapsulation** choices.
- **Defensive copying** is part of **encapsulation**: it connects to **immutability** and to **security/correctness** in larger systems.
- **SRP/cohesion** decisions anticipate **inheritance and interfaces** later: clean classes are easier to extend without breaking **LSP**.
- **Static constants** often appear in “menu-driven” coursework apps (`SimpleOrderSystem`)—they tie **readability** to **maintainability**.

---

## 6. EXAM STRATEGY TIPS

- For “**principle**” questions, use a **two-step template**: (1) **define** in one sentence, (2) **apply** to a tiny example (2–3 sentences).
- When asked for **UML**, label **multiplicities** even if the drawing is rough—examiners mark the **intent**.
- If a question mentions **`void ClassName(...)`**, immediately discuss **constructor vs method** confusion—this is a classic trap.
- For **copying**, explicitly say **shallow vs deep** and what is shared after `new ArrayList<>(...)`.
- Link **non-functional** requirements to measurable words: **latency**, **throughput**, **security**, **maintainability**, **usability**.

---

*These notes are for revision; always follow your module’s exact definitions, diagram conventions, and coding standards in assessed work.*
