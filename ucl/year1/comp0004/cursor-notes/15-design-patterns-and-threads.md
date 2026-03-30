# Design Patterns & Threads — COMP0004 Object-Oriented Programming (UCL)

*Lecture-style notes aligned with Slides 6 & 10: **design patterns** (**GoF**, categories), **key patterns** (**Factory**, **Visitor**, **Composite**, **Strategy**, **Observer**, **Decorator**, **Builder**, **Façade**), **architectural patterns** (**MVC**, **Pipe and Filter**), **threads** in Java (**`Thread`**, **`Runnable`**), **concurrency issues**, and **synchronisation** basics.*

---

## 1. COMPLETE TOPIC SUMMARIES

### **What are design patterns?**

**Design patterns** are **reusable**, **named solutions** to **recurring design problems** in object-oriented systems. They are not finished code you paste — they are **templates** for structure and collaboration between classes.

---

### **Origin: Gang of Four (GoF)**

The **“Gang of Four”** book (*Design Patterns: Elements of Reusable Object-Oriented Software*, 1994) catalogued patterns seen in **Smalltalk** and **C++** systems. Many names (**Observer**, **Factory**, …) come from that tradition and are still standard vocabulary in Java and beyond.

---

### **Why patterns matter**

- **Standardise practice** — experienced developers recognise the same **structure** quickly.
- **Communication** — “use an **Observer** here” conveys **intent** faster than a long description.
- **Reusability / maintainability / scalability** — good patterns **localise change** (e.g. swap algorithms with **Strategy**) and **reduce coupling** when applied appropriately.

Patterns are **tools**, not goals: **over-engineering** with patterns hurts clarity.

---

### **Pattern categories (GoF)**

| Category | Focus | Examples |
|----------|--------|----------|
| **Creational** | How objects are **instantiated** | **Factory**, **Builder**, **Singleton** (know pros/cons) |
| **Structural** | How classes/objects **compose** | **Decorator**, **Composite**, **Façade**, **Adapter** |
| **Behavioral** | How objects **collaborate** and **distribute responsibility** | **Strategy**, **Observer**, **Visitor**, **Iterator** |

---

### **Key patterns to know (concise)**

- **Factory** — centralise **object creation** so clients depend on **interfaces**, not concrete constructors (`new Concrete()` scattered everywhere). **Factory method** / **Abstract factory** variants exist.
- **Visitor** — separate **operations** from **element types**: a **`Visitor`** object is **accepted** by each node in a structure; **double dispatch** dispatches to the right **`visit`** overload.
- **Composite** — treat **individual objects** and **compositions** uniformly via a **common interface** (e.g. **GUI** trees, **file system**).
- **Strategy** — define a **family of algorithms**, encapsulate each in a class, **interchange** at runtime (e.g. **sorting** policies, **pricing** rules).
- **Observer** — **one-to-many** dependency: when a **subject** changes state, **observers** are **notified** (event-driven UIs, **MVC** variants).
- **Decorator** — attach **new behaviour** **wrapping** an object, **transparently** (I/O streams in Java are the classic lesson).
- **Builder** — construct a **complex object** **step by step** (fluent API, immutable products).
- **Façade** — a **single simple interface** hiding a **complex subsystem** (reduce coupling for clients).

---

### **Architectural patterns**

- **MVC** (**Model–View–Controller**) — see web notes: separates **data/logic**, **presentation**, **request handling**.
- **Pipe and Filter** — data flows through a **sequence of filters** (each **transforms** input to output); good for **streams**, **compilers**, **Unix pipelines** mentally mapped to objects.

---

### **Threads: what is a thread?**

A **thread** is a **sequence of method calls** — an independent **path of execution** within the same program. One **process** can have **many threads** sharing **heap memory** but each with its **own call stack**.

---

### **Single-threaded vs multi-threaded**

| | **Single-threaded** | **Multi-threaded** |
|---|---------------------|-------------------|
| **Execution** | One statement stream at a time in the program logic | **Multiple** concurrent (or time-sliced) streams |
| **Simplicity** | Easier reasoning — no **races** | **Harder** — needs **synchronisation** |
| **Use** | Simple tools, some embedded UIs | **Servers**, **responsive GUIs**, **parallel work** |

---

### **Java: `Thread` and `Runnable`**

- **`Runnable`** — functional task: **`void run()`** (use **lambda** or class).
- **`Thread`** — actual thread of execution; **`start()`** begins **concurrent** `run()` (never call **`run()`** directly if you want a new thread).

```java
// Lambda Runnable
Thread t1 = new Thread(() -> {
    System.out.println("Hello from " + Thread.currentThread().getName());
});
t1.start();

// Named Runnable class
class DownloadTask implements Runnable {
    @Override
    public void run() {
        // work...
    }
}
new Thread(new DownloadTask()).start();
```

**`start()`** schedules the thread; **`join()`** waits for it to finish.

---

### **Thread safety: shared data and race conditions**

When **multiple threads** access **mutable shared state** without coordination, **race conditions** occur: outcomes depend on **timing** (lost updates, inconsistent reads).

```java
// Unsafe if count is shared between threads without sync
public void increment() {
    count++; // read-modify-write — not atomic
}
```

---

### **Basic synchronisation concepts**

- **`synchronized` method or block** — **mutual exclusion** (**lock**) on an object’s **monitor**; only one thread at a time executes the guarded code for that lock.
- **`volatile`** (awareness) — visibility of field updates across threads; does **not** replace locking for compound actions.
- Higher-level tools (**`java.util.concurrent`**) exist in production; exams often expect **`synchronized`** intuition.

---

### **Why threads matter**

- **Responsive UIs** — long work off the **event thread** (JavaFX/Swing concepts).
- **Concurrent processing** — overlap **I/O** and **computation**.
- **Server applications** — **one request per thread** (simplified model) or **pools** handling many clients.

---

## 2. EXAM-STYLE QUESTIONS (with model answers)

### Q1 — Pattern categories

**Question:** Name the **three GoF pattern categories** and place **Decorator**, **Factory**, and **Observer** into the correct category.

**Model answer:** **Creational** — **Factory**. **Structural** — **Decorator**. **Behavioral** — **Observer**. The three categories are **creational**, **structural**, **behavioral**.

---

### Q2 — Strategy vs inheritance

**Question:** Explain how **Strategy** avoids a large **`switch` on type** or deep **subclass hierarchy** for interchangeable algorithms.

**Model answer:** **Strategy** encapsulates each algorithm in a class implementing a **common interface**. The **context** holds a **reference** to a **strategy** and **delegates**; at runtime you **swap** the strategy object. New algorithms add **new classes** without modifying existing **context** control flow (**Open/Closed** idea).

---

### Q3 — Observer one-liner

**Question:** In the **Observer** pattern, what are the roles of **subject** and **observer**?

**Model answer:** The **subject** maintains state and **registers** observers; when state changes, it **notifies** them. **Observers** **subscribe** and **react** to updates — **one-to-many** propagation.

---

### Q4 — `start()` vs `run()`

**Question:** Why call **`thread.start()`** instead of **`thread.run()`** in Java?

**Model answer:** **`start()`** asks the **JVM** to create a **new thread** of execution that will invoke **`run()`** **asynchronously**. Calling **`run()`** directly executes **`run()`** on the **current** thread only — **no concurrency**.

---

### Q5 — Race condition

**Question:** What is a **race condition**? Give a minimal example involving a **shared `int` counter**.

**Model answer:** A **race** is when correctness depends on **uncontrolled interleaving** of threads. Example: two threads both **`read`** `count`, **`add 1`**, **`write`** — both may write the **same** value so **one increment is lost** (`count++` is not atomic).

---

## 3. MUST-KNOW KEY POINTS

- **Patterns** = **named**, **reusable** **OO** design solutions; **GoF** book origin.
- **Categories:** **creational**, **structural**, **behavioral**.
- **Factory** — hide **construction**; **Strategy** — **pluggable algorithms**; **Observer** — **notify** dependents.
- **Decorator** — **wrap** for extra behaviour; **Composite** — **tree** as whole/part; **Visitor** — **operations** on structure.
- **Builder** — **stepwise** construction; **Façade** — **simple face** on complex subsystem.
- **MVC** and **Pipe and Filter** as **architectural** patterns.
- **Thread** = execution path; **`Runnable.run()`**, **`Thread.start()`**.
- **Shared mutable state** → **race conditions**; **`synchronized`** for **mutual exclusion** basics.

---

## 4. HIGH-PRIORITY TOPICS (🔴 / 🟡 / 🟢)

| Priority | Topic | Why it matters |
|----------|--------|----------------|
| 🔴 | **GoF categories** + classify a pattern | Fast marks if you memorise the table. |
| 🔴 | **`start()` vs `run()`** | Very common trap question. |
| 🔴 | **Race conditions** + **shared mutable state** | Short definition + example. |
| 🟡 | **Strategy** vs **Subclassing** | Delegation and **swapping** behaviour. |
| 🟡 | **Observer** roles | **One-to-many** update. |
| 🟡 | **Decorator** vs **inheritance** | **Composition** wrapping. |
| 🟢 | **Visitor** / **Composite** | Often “what problem does it solve?” |
| 🟢 | **Pipe and Filter** | Dataflow **architecture** vocabulary. |
| 🟢 | **`synchronized`** basics | **Lock** + **mutual exclusion** one-liner. |

---

## 5. TOPIC INTERCONNECTIONS

- **Observer** often backs **MVC** (**model** notifies **views**).
- **Strategy** appears inside **controllers** or services to **plug policies** without **if/else** explosion.
- **Factory** pairs with **interfaces** — construction behind **abstract types** (**programming to an interface**).
- **Threads** matter for **web servers** (concurrent requests) and link back to **Servlets** (container uses a **thread pool**).
- **Synchronisation** is the price of **sharing objects** between **threads** — same **encapsulation** discipline as elsewhere, plus **locks**.

```text
Client code  --->  Factory  --->  concrete Product
Context      --->  Strategy interface  --->  ConcreteStrategyA/B

Subject state change  --->  notify()  --->  Observer1, Observer2, ...
```

---

## 6. EXAM STRATEGY TIPS

- For **“name that pattern”**, list **intent** first (**what changes often?**), then **structure** (**who calls whom**).
- Memorise **one sentence** each for **Strategy**, **Observer**, **Decorator**, **Factory** — they cover many exam prompts.
- On **threads**, always mention **shared mutable state** when discussing bugs; mention **atomicity** for **`count++`**.
- If asked **creational vs structural**, ask yourself: “Is this mainly about **making objects** or **wiring parts together**?”
- **MVC** as **architectural** vs **Strategy** as **OO micro-pattern** — match the **scale** the question implies.
