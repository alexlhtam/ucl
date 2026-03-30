# Intro to Java & the Java Platform — COMP0004

*Lecture-style notes aligned with introductory slides (OOP mindset, Java history, platform architecture, classes/objects, first programs, tooling).*

---

## 1. COMPLETE TOPIC SUMMARIES

### **Object-oriented programming (OOP) as a paradigm**

OOP is not only a **syntax style**; it is a way to organise software around **objects** that combine **state** (data) and **behaviour** (methods). In professional practice, OOP sits inside a broader lifecycle:

- **Design** — choose **abstractions** (classes, interfaces), relationships (**inheritance**, **composition**), and responsibilities so the system stays understandable as it grows.
- **Coding** — implement those abstractions in a language like **Java**, using **encapsulation** (hiding internals), **polymorphism** (many shapes, one interface), and **reuse** (libraries, APIs).
- **Testing** — verify behaviour with **unit tests**, **integration tests**, and manual checks; OOP often makes testing easier when objects have clear contracts.

> **Beginner intuition:** A **class** is the idea “what kind of thing is this?”; an **object** is “this specific thing right now.” COMP0004 builds from that picture toward full OOP design.

---

### **Java history (high-signal timeline)**

- **1991 — Project Oak** at Sun Microsystems, led by **James Gosling** and others. Early goals included embedded / consumer devices.
- **1995 — Renamed Java** and public launch with the **applet** story and a focus on networked programs.
- **“Write Once, Run Anywhere” (WORA)** — Java programs target a **portable bytecode** executed by a **JVM** on each platform, rather than one CPU-specific binary per OS.
- **Platform families (historical branding)** — **J2SE** (Standard Edition, desktop / general), **J2EE** (Enterprise Edition, large server apps; later **Jakarta EE** lineage), **J2ME** (Micro Edition, constrained devices). Modern naming uses **Java SE**, **Java EE/Jakarta EE**, **Java ME** less prominently for many curricula.
- **Oracle** acquired Sun (**2010**); Java stewardship continues via **OpenJDK** (open-source reference implementation) and the **Java Community Process (JCP)** for language evolution.
- **Current releases** — Java uses a **six-month** cadence (e.g. **Java 25** in the **September 2025** release train in real-world calendars). For coursework, always check the **JDK version** your department standardises on.

---

### **Java ecosystem: JDK, JRE, JVM, class libraries**

| Piece | Role |
|--------|------|
| **JVM (Java Virtual Machine)** | Runtime that **loads**, **verifies**, and **executes** **bytecode**; manages memory and **garbage collection**; may use a **JIT** (below). |
| **JRE (Java Runtime Environment)** | **JVM + libraries** needed to **run** Java programs. (Modern practice often ships a **jlink**-style runtime or uses a full **JDK** for development.) |
| **JDK (Java Development Kit)** | **JRE + development tools**: **`javac`** (compiler), **`java`** (launcher), **`jar`**, **`javadoc`**, debuggers, etc. **You need a JDK to compile.** |
| **Class libraries** | Huge standard API: **`java.lang`**, **`java.util`**, I/O, networking, concurrency, etc. This is a major reason Java is productive compared to “bare metal” C for many tasks. |

---

### **Java vs C (typical contrasts taught early)**

| Aspect | C (typical first course) | Java |
|--------|---------------------------|------|
| **Paradigm emphasis** | Procedural; structs + functions | **Object-oriented** first class: **classes**, **methods**, **interfaces** |
| **Libraries** | Small standard library; often OS-specific | Rich **cross-platform** standard library |
| **Memory** | **Manual** `malloc`/`free` (or similar patterns) | **Automatic garbage collection**; no free() for ordinary objects |
| **Pointers** | **Explicit** pointer arithmetic possible | **No C-style pointers**; only **references** to objects, with safety checks |
| **Type system** | Static but **weaker** in places (casts, `void*`, etc.) | **Strong static typing** with stricter checks at compile time |
| **Execution** | Compile mostly to **native machine code** | Compile to **bytecode**; **JVM** executes (often **JIT**-compiled) |

> **Exam phrasing:** Java trades **low-level control** for **safety**, **portability**, and **large-scale library support**.

---

### **The Java compiler (`javac`) — bytecode, not machine code**

- **`javac`** translates **`.java` source** into **`.class` files** containing **bytecode** (a stack-oriented instruction set for the JVM).
- Bytecode is **not** the same as **native machine code** for your CPU; it is **platform-neutral** until the JVM runs it.
- Traditional **linking** (as in C build pipelines) is **not** the same story: the JVM **loads classes dynamically** and resolves references at **runtime** (with verification rules). For beginners: “compile” means **source → `.class`**, then **`java`** runs the program entry point.

**Minimal compile/run mental model:**

```bash
javac Hello.java    # produces Hello.class (bytecode)
java Hello          # JVM loads Hello and runs main
```

---

### **The JVM — what it is (and what it is not)**

- The **JVM** is a **software machine specification** + implementation: it executes bytecode with rules for the **class file format**, **class loading**, **bytecode verification**, and **execution semantics**.
- It **manages memory** for objects (typically **heap**-allocated) and runs **garbage collection** to reclaim unreachable objects.
- It is **not** a “hardware VM” like VirtualBox; think **process virtual machine** specialised for Java bytecode (and other JVM languages).

---

### **JIT compilation — speed without losing portability**

- A **JIT (Just-In-Time) compiler** inside the JVM **translates hot bytecode into native machine code at runtime**.
- Benefits: **adaptive optimisation** (the JVM learns which methods are hot), **inlining**, and other optimisations that a static ahead-of-time compiler might miss or over-commit to.
- Consequence for learners: **micro-benchmark intuition** is tricky — **warm-up** matters; first runs can be slower.

---

### **Classes and objects — vocabulary that must be automatic**

- **Class** — a **template / blueprint** describing **fields** (state) and **methods** (behaviour) for a kind of thing.
- **Object (instance)** — a **concrete realization** of a class in memory at runtime, with its **own field values**.
- The class defines **structure + behaviour**; each object **stores its own state** (for non-static fields).

---

### **Hello World — `public class`, `main`, output**

A classic entry program:

```java
public class Hello {
    public static void main(String[] args) {
        System.out.println("Hello, world!");
        System.out.printf("Args: %d%n", args.length);
    }
}
```

- **`public class Hello`** — file is usually **`Hello.java`**; **`public`** top-level class name must match filename.
- **`public static void main(String[] args)`** — **entry point** the **`java`** launcher calls.
- **`System.out.println`** — print line; **`printf`** — formatted printing (C-like format strings).

---

### **`jshell` — a Java REPL**

**`jshell`** (Java 9+) is an interactive **Read–Eval–Print Loop**: type snippets, see results, experiment with APIs without a full `main` class cycle. Excellent for **syntax drills** and API exploration.

---

### **Unnamed classes and instance `main` (modern Java)**

Recent Java versions streamline **tiny programs**: you may see **unnamed classes** / compact launch patterns so beginners can write a **`main`** with less boilerplate than a full `public class` file (exact features depend on **language version** and preview/final status — always match your **JDK**). Pedagogical point: the **runtime still runs on the JVM**; convenience features do not change the bytecode/JVM big picture.

---

### **IDE recommendation — IntelliJ IDEA**

For COMP0004-scale work, **IntelliJ IDEA** (Community Edition is sufficient for many modules) is a strong default: **navigation**, **refactoring**, **debugger**, **test runners**, and **Gradle/Maven** integration. You can use any editor, but an IDE accelerates **OOP refactoring** (rename class, extract method, find usages).

---

## 2. EXAM-STYLE QUESTIONS (3–5 with model answers)

### Q1 — OOP lifecycle

**Question:** In one paragraph, explain how **design**, **coding**, and **testing** relate in an object-oriented project. Give one example of a design choice that makes testing easier.

**Model answer:** **Design** fixes **abstractions** and boundaries (classes, responsibilities); **coding** implements those abstractions with methods and data; **testing** checks that behaviour matches requirements and that changes do not break contracts. OOP helps when objects expose a **small, clear API** (e.g. a `BankAccount` class with `deposit`/`withdraw` methods) so **unit tests** can call those methods directly without simulating an entire application. Good design reduces **coupling**, so tests can substitute **test doubles** where needed.

---

### Q2 — JDK vs JVM

**Question:** Define **JDK**, **JVM**, and **bytecode**. Explain what `javac` produces and what executes it.

**Model answer:** The **JDK** is the **development kit** including the compiler and tools. The **JVM** is the **runtime** that executes Java programs. **Bytecode** is the **platform-independent** instruction format stored in **`.class`** files. **`javac`** compiles **`.java` → bytecode** (`.class`). The **`java`** command starts a **JVM process** that **loads** classes and runs **`main`**.

---

### Q3 — Java vs C memory model

**Question:** Contrast **manual memory management** in typical C with **garbage collection** in Java. Why does Java disallow C-style pointer arithmetic?

**Model answer:** In typical C, the programmer explicitly allocates/frees memory; errors cause **leaks**, **double free**, or **use-after-free**. Java allocates objects on the **heap** and a **garbage collector** reclaims objects that are **unreachable**, reducing those classes of bugs. Java avoids **pointer arithmetic** so references cannot be **offset into arbitrary memory**, improving **safety** and supporting **bounds checks** and **verification** in the JVM.

---

### Q4 — JIT vs interpreter (conceptual)

**Question:** What does a **JIT compiler** do in the JVM? Why might a program become faster after it has been running for a while?

**Model answer:** A **JIT** translates **bytecode** (or runs an interpreter initially) into **native machine code** for hot methods **at runtime**, applying **optimisations** based on observed behaviour (**profiling**). After warm-up, frequently executed code paths may be **optimised and cached**, so later iterations run faster than the first.

---

### Q5 — Class vs object

**Question:** Explain the difference between a **class** and an **object**. Illustrate with a Java example naming one class and two distinct objects.

**Model answer:** A **class** is a **blueprint**; an **object** is an **instance** created from that blueprint with its own state. Example: `class Student { String name; }` is a class; `Student a = new Student(); a.name = "Ada";` and `Student b = new Student(); b.name = "Alan";` are two **objects** of the same class with **different field values**.

---

## 3. MUST-KNOW KEY POINTS

- **OOP** bundles **state + behaviour**; professional work spans **design → code → test**.
- Java’s headline property is **portable bytecode + JVM**, historically marketed as **WORA**.
- **JDK** = dev tools + runtime pieces; **JVM** executes **bytecode**; libraries are huge and cross-platform.
- **`javac`** outputs **`.class`** (**not** native machine code for arbitrary CPUs by itself).
- **GC + no raw pointers** → safer memory story than typical C pointer arithmetic.
- **Class** = template; **object** = instance; **`main`** is the standard entry point.
- **`jshell`** supports interactive learning; **IntelliJ** is the usual recommended IDE.

---

## 4. HIGH-PRIORITY TOPICS

| Priority | Topic | Why it matters |
|----------|--------|----------------|
| 🔴 **Must know** | **Class vs object** | Foundational vocabulary for all OOP topics. |
| 🔴 **Must know** | **JDK / JVM / bytecode / `javac`** | Explains *what you are running* and *why it is portable*. |
| 🔴 **Must know** | **`public static void main(String[] args)`** | Entry point; appears in every runnable program discussion. |
| 🔴 **Must know** | **Java vs C: GC, references, stronger typing** | Standard comparative question in intro modules. |
| 🟡 **Important** | **JIT compilation + warm-up intuition** | Explains performance behaviour at a high level. |
| 🟡 **Important** | **JRE vs JDK distinction** | Common setup/debugging exam MCQ. |
| 🟡 **Important** | **History + WORA + ecosystem branding (SE/EE/ME)** | Context questions; shows you understand Java’s niche. |
| 🟢 **Useful** | **Oracle/OpenJDK/release cadence** | Useful for “current Java version” literacy (check your lab JDK). |
| 🟢 **Useful** | **`jshell`, unnamed/compact launch features** | Productivity; may be bonus / practical lab questions. |

---

## 5. TOPIC INTERCONNECTIONS & BIGGER PICTURE

- **Bytecode + JVM** is the bridge to later topics: **class loading**, **packages**, **modules** (in advanced courses), and **JVM diagnostics**.
- **Strong static typing + references** foreshadows **interfaces**, **generics**, and **polymorphism** — the compiler enforces contracts early.
- **OOP design** connects to **testing**: small, cohesive classes simplify **unit tests**; bad coupling makes tests fragile.
- **JIT/GC** connects to **performance engineering** later (allocation rates, object lifetimes), even if COMP0004 only needs awareness.
- **IDE refactoring** reinforces **rename-safe** OOP structure — the same discipline scales to **team repositories**.

---

## 6. EXAM STRATEGY TIPS

- **Define terms before mechanisms:** e.g. “**bytecode** is …; the **JVM** is …; therefore **`javac`/`java` roles** are …”.
- **Contrast tables** score well for **Java vs C** questions: pick **3–4** crisp rows (memory, pointers, compilation output, libraries).
- **Avoid folklore:** say **“bytecode + JVM”** rather than vague “Java is interpreted only” — mention **JIT** when discussing speed.
- **Match file/class rules** if asked about `public class` and filenames.
- **One-sentence lifecycle:** **design abstractions → implement classes → test behaviour** ties OOP to software engineering marks.

---

*End of notes — Intro to Java & the Java Platform (COMP0004).*
