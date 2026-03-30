# Packages & Modules — COMP0004 Object-Oriented Programming (UCL)

*Lecture-style notes aligned with Slides 12: **packages** as named scopes, **directory layout**, **`import`**, **classpath**, **JAR** / **WAR** / **EAR**, **package and protected access**, and **Java modules** (Java 9+, **Project Jigsaw**) with **`module-info.java`**.*

---

## 1. COMPLETE TOPIC SUMMARIES

### **Packages — related types in one named scope**

A **package** is a **collection of related classes and interfaces** that share a **package name**. That name gives a **named scope**: types in the same package cooperate easily; types elsewhere refer to them with **imports** or **fully qualified names**.

> **Beginner intuition:** Think of a package as a **folder of teamwork** — not a single class, but a **namespace** so **`Student`** in **`uk.ac.ucl.model`** does not clash with **`Student`** in another package.

---

### **Scope hierarchy: module → package → class → local**

Java visibility and name resolution sit in a **hierarchy**:

| Level | What it scopes |
|--------|----------------|
| **Module** (Java 9+) | Which packages are **visible outside** the module; **dependencies** (`requires`). |
| **Package** | Groups types; affects **default (package-private)** access. |
| **Class / interface** | **Fields**, **methods**, **nested types**. |
| **Local** | **Method parameters**, **local variables**, **loop variables** — narrowest. |

So **module** is the **outer** organisational layer for large apps; **package** is the everyday grouping inside (or across) modules.

---

### **Package declaration — first statement in the file**

The **package declaration** must be the **first statement** in a compilation unit (only **comments** may appear above it — in coursework, keep **`package`** immediately after any file header comment):

```java
package uk.ac.ucl.cs.example;

public class Demo {
    // ...
}
```

If you omit **`package`**, the type lives in the **unnamed default package** — fine for tiny exercises, **avoid** for real projects and libraries.

---

### **Package naming conventions**

- Use **lowercase** segments separated by **`.`**.
- Often **hierarchical** names that read like a path: **`datastructures.matrix.array`**.
- Common **reverse-DNS** style: **`uk.ac.ucl.cs.mycourse`** so names are **globally unlikely to collide** when libraries combine.

The dots are **not** “nested packages” in the language sense — see next subsection.

---

### **Hierarchical names ≠ nested packages**

A name like **`a.b.c`** suggests nesting, but **Java does not treat `b` as “inside” `a` as a language construct**. There is **no** outer/inner package relationship — only **separate packages** whose names share a **prefix**. **Access modifiers** and **imports** work **per full package name**, not “inheritance between packages.”

---

### **Packages and directories — source and class files must align**

The **package name** must match the **directory path** (from a **source root** or **output root**):

- Source: **`src/uk/ac/ucl/cs/example/Demo.java`** for **`package uk.ac.ucl.cs.example;`**
- Compiled: **`.../uk/ac/ucl/cs/example/Demo.class`** in the same relative layout

If **`Demo.java`** declares **`package uk.ac.ucl.cs.example`** but the file sits in the wrong folder, **`javac`** typically errors with **“wrong package”** / **“should be declared in a named package”** style messages.

---

### **`src/` and `build/` (or `out/`) — parallel trees**

A common IDE / build layout:

- **`src/`** — **`.java`** files in package directories.
- **`build/`**, **`out/`**, or **`target/classes/`** — **`.class`** files mirroring the same package tree.

**Same logical package**, **two physical roots**: one for **source**, one for **compiled output**. Build tools (**Gradle**, **Maven**, **IDE**) keep them in sync.

---

### **`import` — shorthand for type names**

**`import`** brings a **simple name** into scope so you can write **`ArrayList`** instead of **`java.util.ArrayList`**.

```java
import java.util.ArrayList;
import java.util.List;

public class ImportsDemo {
    public static void main(String[] args) {
        List<String> xs = new ArrayList<>();
    }
}
```

- **Single-type import:** **`import java.util.ArrayList;`**
- **On-demand (wildcard) import:** **`import java.util.*;`** — imports **types** in that package, **not** subpackages (`java.util.regex` is **not** covered by **`java.util.*`**).
- **`java.lang`** is **auto-imported** (**`String`**, **`System`**, **`Integer`**, etc.).

You can always use the **fully qualified class name** (**FQCN**) with **no** **`import`**.

---

### **Classpath — where the compiler and JVM look for `.class` files**

The **classpath** is a list of **directories**, **JAR files**, and **modules** (module path — advanced) that **`javac`** and **`java`** search to **load compiled types**.

- **CLI flag:** **`-classpath`** (or **`-cp`**) with **`:`**-separated entries on macOS/Linux (**`;`** on Windows).

**Rule of thumb:** **classpath entry + package path = file location**. If **`uk.ac.ucl.cs.example.Demo`** is on the classpath root **`classes/`**, the JVM expects **`classes/uk/ac/ucl/cs/example/Demo.class`**.

---

### **JAR files — zip of `.class` files + metadata**

A **JAR** (**Java Archive**) is a **`.zip`** archive of **`.class`** files (and resources) with **directory structure preserved** so **package paths** still match.

- **Distribution:** ship one **`.jar`** instead of thousands of loose **`.class`** files.
- **Classpath:** you can put **`mylib.jar`** directly on the **classpath**; the JVM reads classes **inside** it.

---

### **Executable JAR — `Main-Class` in the manifest**

An **executable JAR** includes a **manifest** (often **`META-INF/MANIFEST.MF`**) specifying **`Main-Class: fully.qualified.Name`** so you can run:

```bash
java -jar myapp.jar
```

Build tools generate manifests; for exams, know **manifest + main class** is what **`java -jar`** uses.

---

### **`.war` and `.ear` — web and enterprise packaging**

- **`.war`** (**Web Application Archive**): web apps for **servlet containers** — **HTML**, **JSP**, **`WEB-INF`**, libraries, etc.
- **`.ear`** (**Enterprise Archive**): bundles **multiple modules** (EJB + web + resources) for **Java EE**-style servers.

You mainly need the **idea**: **JAR** = general Java library/app; **WAR/EAR** = **deployment** formats for **servers**.

---

### **Package-level access and `protected`**

- **`public` class** — visible **everywhere** the module graph allows.
- **Package-private class** (no modifier) — visible **only inside the same package** — even if subclasses exist elsewhere, they **cannot** access that class if it is not **`public`** (they cannot **name** it from another package).

For **members**:

- **`public`** — everywhere.
- **`protected`** — **subclasses** + **same package** (broader than “subclass only”).
- **package-private** (default) — **same package only**.
- **`private`** — **enclosing class only**.

Exam trap: **`protected`** includes **same-package non-subclasses**.

---

### **Java modules (Java 9+) — Project Jigsaw**

A **module** is a **named unit** grouping **packages** with an explicit **module descriptor** **`module-info.java`**. Goals: **strong encapsulation** (hide internal packages), **reliable configuration** (explicit dependencies), and **smaller runtime** (custom **jlink** images — beyond intro exams sometimes).

---

### **Module flavours (exam vocabulary)**

| Kind | Idea |
|------|------|
| **System modules** | **`java.base`**, **`java.sql`**, etc. — the **JDK** modularised platform. |
| **Application modules** | Your code with **`module-info.java`**. |
| **Automatic modules** | A plain **JAR** on the **module path** gets an **automatic name** (from **`Automatic-Module-Name`** or derived from **JAR** filename) — migration bridge. |
| **Unnamed module** | Code **without** **`module-info`** on the **module path** reads all observable modules; classic **classpath** code lands here in hybrid setups. |

---

### **`module-info.java` — `requires`, `exports`, `services`**

```java
module uk.ac.ucl.example {
    requires java.base;       // implicit, often omitted in tiny examples
    requires java.logging;

    exports uk.ac.ucl.example.api;          // API package visible to other modules
    opens uk.ac.ucl.example.internal;      // reflection access for frameworks (e.g. DI)

    uses com.example.spi.PaymentProcessor;  // service interface
    provides com.example.spi.PaymentProcessor
        with com.example.impl.StripeProcessor;
}
```

- **`requires`** — this module **depends on** another **named module**.
- **`exports`** — makes a **package** available to **other modules** at compile/run (depending on readability).
- **`opens`** — **runtime-only** openness (often **reflection** / **frameworks**).
- **`uses` / `provides … with`** — **service loader** pattern (SPI).

---

## 2. EXAM-STYLE QUESTIONS (WITH MODEL ANSWERS)

### **Q1.** Explain why the package name **`a.b.c`** does **not** mean package **`c`** is **nested inside** package **`b`**. What **does** the dot notation represent?

**Model answer:** In Java, **each package is independent**; there is **no hierarchical nesting** of package objects or scopes. The dots are **naming convention** only: **`a.b`** and **`a.b.c`** are **different packages** whose names share a prefix. **Imports**, **access**, and **visibility** apply to the **full name** **`a.b.c`**, not to “inheritance” from **`a.b`**. Practically, the dots mirror **folder structure** on disk.

---

### **Q2.** A class is declared **`package com.example.app;`**. Where must **`Main.java`** live relative to a source root, and where will **`Main.class`** appear after compilation?

**Model answer:** Under the **source root**, the file path must be **`com/example/app/Main.java`**. After **`javac`**, **`Main.class`** appears under the **output root** as **`com/example/app/Main.class`**, **mirroring** the package. Mismatches between **`package`** line and path cause **compile errors**.

---

### **Q3.** What is the **classpath**, and how does **`classpath + package`** determine where **`java.util.ArrayList`** is loaded from?

**Model answer:** The **classpath** lists **roots** (directories or **JAR**s) where **`javac`/`java`** search for **compiled types**. The **fully qualified name** **`java.util.ArrayList`** maps to path **`java/util/ArrayList.class`** **relative to a classpath root**. For example, if **`classes/`** is on the classpath and contains **`java/util/ArrayList.class`**, loading succeeds; the JVM does **not** flatten package dots into a single directory name.

---

### **Q4.** Compare **`import java.util.*;`** and **`import java.util.ArrayList;`**. Does the wildcard import **subpackages**?

**Model answer:** **Single-type import** brings **one** class into scope. **Wildcard** **`import java.util.*;`** imports **all public top-level types** in **`java.util`** **only** — **not** types in **`java.util.regex`**, **`java.util.concurrent`**, etc., because those are **different packages**. **Name clashes** are still possible if two wildcarded packages export the same simple name — then use **FQCN** or **explicit imports**.

---

### **Q5.** Who can access a **`protected`** instance field? How does that differ from **package-private**?

**Model answer:** A **`protected`** member is visible in **the declaring class**, **other classes in the same package**, and **subclasses** (even in **other packages**, via inheritance rules for accessing **`super`** fields/methods as per language access checks). **Package-private** (no modifier) allows **only** the **same package** — **subclasses in other packages** do **not** get access. This is a favourite **MCQ / short answer** distinction.

---

## 3. MUST-KNOW KEY POINTS

- **Package** = **named scope** for related **classes/interfaces**.
- **Scope order:** **module** → **package** → **class** → **local**.
- **`package name;`** must be the **first statement** in a **`.java`** file (for named packages).
- **Naming:** **lowercase**, **hierarchical**, often **reverse domain** (**`uk.ac.ucl.cs…`**).
- **Dots ≠ nesting** — **`a.b`** and **`a.b.c`** are separate packages; **no** subpackage language feature.
- **Directory structure** must **match** **package** for **`.java`** and **`.class`**.
- **`src/`** vs **`build/`/`out/`** — **parallel** trees.
- **`import`** = convenience; **`java.lang`** **auto-imported**; **`java.util.*`** does **not** import **subpackages**.
- **FQCN** works **without** **`import`**.
- **Classpath** = where **`.class`** / **JAR** entries are found; **path = package layout**.
- **JAR** = **zip** of **`.class`** + resources; **executable JAR** needs **manifest** **`Main-Class`**.
- **`.war` / `.ear`** = **web/enterprise** deployment archives.
- **`public` type** vs **package-private type** — who can **name** the class from another package.
- **`protected`** = **subclass + same package**; **default** = **same package only**.
- **Modules (9+):** **`module-info.java`**, **`requires`**, **`exports`**, **`opens`**, **`uses`/`provides`**.

---

## 4. HIGH-PRIORITY TOPICS

### 🔴 **Must Know**
- **Package declaration** + **matching folder** structure
- **`import`** vs **FQCN**; **`java.lang`** automatic; **wildcard does not include subpackages**
- **Classpath** concept and **package-to-path** mapping
- **JAR** as **structured archive** of **`.class`** files
- **Access modifiers** at **member** level: **`private` / package / `protected` / `public`**
- **`protected` includes same package** (not just subclasses)

### 🟡 **Important**
- **`src/`** vs **output** directory convention
- **Executable JAR** + **manifest** **`Main-Class`**
- **Default (unnamed) package** — why real code avoids it
- **Module** motivation: **encapsulation** + explicit **dependencies**
- **`module-info.java`**: **`requires`**, **`exports`** (and awareness of **`opens`**)

### 🟢 **Useful**
- **`.war` / `.ear`** roles in **deployment**
- **Automatic** vs **unnamed** modules — **migration** / **classpath interop**
- **`provides` / `uses`** — **SPI** / **service loader** big picture

---

## 5. TOPIC INTERCONNECTIONS & BIGGER PICTURE

- **Packages** organise **OOP** codebases so **teams** and **libraries** compose without **name collisions**; they pair with **visibility** to enforce **API surfaces**.
- **Classpath + JAR** connect **compilation** to **runtime loading** — same logical layout (**package = path**).
- **Access modifiers** link **encapsulation** (class design) to **deployment structure** (who can see **`public`** APIs across packages).
- **Modules** scale **packages** up: **JDK** itself is modular; applications can **hide** internal packages and declare **`requires`** for **maintainable** large systems.
- **Build tools** (**Maven/Gradle/IDE**) automate **classpath**, **JAR** creation, and **manifests** — lectures give **concepts** exams test even if you rarely hand-write manifests.

---

## 6. EXAM STRATEGY TIPS

- Draw **one line**: **`package a.b.c;` → folders `a/b/c/` → `Class.class` in same relative path**.
- For **access** questions, make a **2×2**: same vs other package × subclass vs non-subclass; mark **`protected`** and **package** cells carefully.
- If asked **classpath**, write **`root + / + dotted name with slashes + .class`**.
- Contrast **“nested names”** (packages) with **nested **classes**** — students often confuse them.
- For **modules**, memorise **three keywords:** **`requires`**, **`exports`**, and **`module-info.java`** location at **source root** of the module.
- When **wildcard import** appears in MCQs, ask: **“Is this type in exactly that package?”** — not a **subpackage**.

---

*End of notes — Packages & Modules (Slides 12).*
