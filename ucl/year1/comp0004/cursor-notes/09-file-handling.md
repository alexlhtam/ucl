# File Handling — COMP0004 Object-Oriented Programming (UCL)

*Lecture-style notes aligned with Slide decks **16** and **18**: **Java I/O generations**, **character streams**, **buffering**, **`PrintWriter`**, **`try-with-resources`**, **structured text files**, **CSV**, **tokenising**, **`File` / `Path` / `Files`**, **directories**, **encoding**, and **I/O exceptions**.*

---

## 1. COMPLETE TOPIC SUMMARIES

### **Java file handling in four “generations” (mental model)**

Java’s approach to files and I/O grew over time. You do **not** need every historical detail for exams, but you **should** recognise the layers:

1. **`java.io` (classic / “original” I/O)** — **`InputStream` / `OutputStream`** for **bytes**, **`Reader` / `Writer`** for **characters**. High-level helpers like **`FileReader`**, **`FileWriter`**, **`BufferedReader`**, **`BufferedWriter`**, **`PrintWriter`**, and the **`File`** class. This is still common in teaching and small programs.
2. **NIO (`java.nio`, buffers, channels)** — added **buffers** and **channels** for more scalable / lower-level control (often used in server and performance-sensitive code). First-year OOP courses often mention it as “the middle layer” rather than requiring deep channel APIs.
3. **NIO.2 (`java.nio.file`)** — modern **path-based** file system API: **`Path`**, **`Paths`**, **`Files`**, **`DirectoryStream`**, better support for **copy/move**, **attributes**, and **walking** trees. This is the **preferred** way to work with paths and many file operations today.
4. **Modern practice** — combine **NIO.2** for paths and filesystem tasks with **appropriate streams** for reading/writing contents; always prefer **`try-with-resources`** for **closing**; be explicit about **character encoding** (usually **UTF-8**).

> **Beginner intuition:** **`Path` / `Files`** answer “where is it and what exists on disk?” **Readers / Writers / streams** answer “how do I move the actual bytes/characters in and out?”

---

### **Reading and writing text: `FileReader`, `FileWriter`, buffering**

- **`FileReader`** — a **`Reader`** that reads **characters** from a file using a **default encoding** (platform-dependent unless you use constructors that specify **`Charset`**; in real code, **UTF-8** is usually what you want).
- **`FileWriter`** — a **`Writer`** that writes **characters** to a file (same encoding caveat).
- **`BufferedReader`** — wraps another **`Reader`** and reads **large chunks** into an internal buffer. Adds **`readLine()`**, which is convenient for **line-based** text.
- **`BufferedWriter`** — wraps a **`Writer`** and reduces many small writes into **fewer physical writes** (much faster for loops).

```java
// Line-by-line read (classic pattern)
try (BufferedReader in = new BufferedReader(new FileReader("notes.txt"))) {
    String line;
    while ((line = in.readLine()) != null) {
        System.out.println(line);
    }
}
```

**Why buffer?** Disk and OS calls are relatively expensive; buffering **amortises** cost across many small read/write operations.

---

### **`PrintWriter` — formatted, line-oriented output**

**`PrintWriter`** is a **`Writer`** that behaves a bit like **`System.out`**: **`print`**, **`println`**, **`printf`**. It is handy for **human-readable** text files (logs, reports, simple exports).

```java
try (PrintWriter out = new PrintWriter(new FileWriter("report.txt"))) {
    out.printf("Score: %d%n", 42);
    out.println("Done.");
}
```

You can wrap **`BufferedWriter`** inside if you want both **buffering** and **`printf`** ergonomics; many small teaching examples skip that for brevity.

---

### **`try-with-resources` — automatic closing**

Any class that implements **`AutoCloseable`** can appear in **`try ( ... ) { }`**. When the block ends (normally or because of an exception), **`close()`** is called **automatically**. For file I/O this prevents **resource leaks** (open file handles).

```java
try (BufferedReader br = new BufferedReader(new FileReader("data.txt"))) {
    // use br
} // br.close() called here
```

**`close()` can throw** — in **`try-with-resources`**, if both **`try`** body and **`close()`** throw, exceptions are **suppressed** and attached to the primary exception (useful for debugging).

---

### **Structured data in plain text files**

Beyond “dump a string,” applications often store **records** — e.g. an **address book** where each **contact** has **name**, **phone**, **email**. Common patterns:

- **One record per line** with a **delimiter** (comma, tab, `|`) → easy to parse with **`readLine()`** + **`split(...)`**.
- **Key–value lines** (`email=...`) → parse with **`split("=", 2)`** or **`Scanner`**.
- **Section headers** or **fixed-width** fields (less common in OOP teaching, but appears in legacy data).

The **object-oriented** idea: read strings from the file → **parse** into fields → construct **`Contact`** (or similar) objects in memory.

---

### **CSV (Comma-Separated Values)**

**CSV** is a **tabular** text format: **rows** are lines; **columns** are separated by **commas** (sometimes **semicolons** in locales that use comma as decimal separator).

**Beginner pitfalls:**

- **Headers** — first line may be column names; skip or use to build maps.
- **Commas inside fields** — real CSV often wraps fields in **quotes** and escapes quotes by **doubling** them. Naïve **`split(",")`** breaks on commas **inside** quoted text.
- For **serious** CSV, use a **library**; for **exam-style** questions, you may be asked to implement **simple** CSV (no embedded commas) or to explain why **`split` is fragile**.

```java
// Toy CSV reader: assumes NO commas inside fields
try (BufferedReader br = new BufferedReader(new FileReader("people.csv"))) {
    String header = br.readLine(); // e.g. "name,age"
    String line;
    while ((line = br.readLine()) != null) {
        String[] parts = line.split(",");
        String name = parts[0].trim();
        int age = Integer.parseInt(parts[1].trim());
        // build object...
    }
}
```

---

### **Parsing structured text: `Scanner`, `split()`, tokenising**

- **`String.split(regex)`** — splits a line into **tokens** using a **regular expression**. Simple for **fixed delimiters**; tricky if data contains the delimiter as **data**.
- **`java.util.Scanner`** — can read **tokens** from a **`String`**, **`InputStream`**, or **`Readable`** (including **`Path`** via **`Files.newBufferedReader`**). Methods like **`next()`**, **`nextInt()`**, **`nextLine()`** are convenient but require care when **mixing** token and line reads (newline handling trips beginners up).
- **Tokenising** means breaking **continuous text** into **meaningful chunks** (words, numbers, fields).

```java
Scanner s = new Scanner("10 20 30");
while (s.hasNextInt()) {
    System.out.println(s.nextInt());
}
s.close();
```

---

### **`File`, `Path`, and `Files`**

- **`java.io.File`** — older **pathname + metadata** abstraction (`exists()`, `isDirectory()`, `listFiles()`, `mkdirs()`). Still appears in legacy code and teaching examples.
- **`java.nio.file.Path`** — **modern** path representation; **immutable**, richer operations when combined with **`Files`**.
- **`java.nio.file.Files`** — static helpers: **`readAllLines`**, **`readString`**, **`writeString`**, **`createDirectories`**, **`walk`**, **`copy`**, **`deleteIfExists`**, etc.

```java
Path p = Paths.get("data", "book.txt");
List<String> lines = Files.readAllLines(p, StandardCharsets.UTF_8);
```

Prefer **`Path` + `Files`** for **filesystem** operations; use **streams/readers** when you need **fine-grained** control (streaming huge files line-by-line).

---

### **Directory operations**

Typical tasks: **list** entries, **create** folders, **test** whether a path is a file or directory.

- With **`File`**: **`listFiles()`**, **`mkdir()`**, **`mkdirs()`**.
- With **`Files`**: **`newDirectoryStream`**, **`list`**, **`walk`**, **`createDirectories`**.

```java
Path dir = Paths.get("exports");
Files.createDirectories(dir);
try (DirectoryStream<Path> stream = Files.newDirectoryStream(dir)) {
    for (Path entry : stream) {
        System.out.println(entry.getFileName());
    }
}
```

---

### **Character encoding: UTF-8 and stream types**

- **Byte streams** — **`InputStream` / `OutputStream`**: raw **bytes**. Use for **binary** files (images, compressed archives) or when you manage encoding **manually**.
- **Character streams** — **`Reader` / `Writer`**: **Unicode characters** (internally Java uses **UTF-16** for **`char`**, but that is separate from **file encoding**).
- **UTF-8** — the usual **interop** encoding for text files, web, and JSON. **Mismatched encoding** → **mojibake** (garbled text) or **`MalformedInputException`** when decoding strictly.

**Best practice:** specify **`StandardCharsets.UTF_8`** (or **`Charset.forName("UTF-8")`**) when constructors allow it — do not rely on the **platform default**.

---

### **Error handling: `IOException` and `FileNotFoundException`**

- **`IOException`** — broad **checked** exception for I/O failures (disk, permissions, unexpected EOF in some APIs, etc.).
- **`FileNotFoundException`** — subclass of **`IOException`**; thrown when opening a **non-existent** file for **reading** (and related cases).

Because these are **checked**, calling methods must **`catch`** or declare **`throws`**. In exam answers, show **`try-with-resources`** plus **either** recovery (message to user) **or** deliberate propagation with **`throws IOException`**.

```java
public List<String> loadLines(Path path) throws IOException {
    return Files.readAllLines(path, StandardCharsets.UTF_8);
}
```

---

## 2. EXAM-STYLE QUESTIONS (3–5 with model answers)

### **Q1. Explain the difference between a byte stream and a character stream in Java. When would you pick each?**

**Model answer:** **Byte streams** (`InputStream` / `OutputStream`) read and write **raw bytes** — suitable for **binary** data where encoding is irrelevant or handled manually. **Character streams** (`Reader` / `Writer`) read and write **Unicode text**, applying a **character encoding** when talking to bytes on disk. Pick **byte streams** for images, compressed files, or network protocols framed as bytes; pick **character streams** for **text** files where human-readable strings are the logical unit — and specify **UTF-8** explicitly when possible.

---

### **Q2. Why wrap a `FileReader` in a `BufferedReader`?**

**Model answer:** **`FileReader`** reads characters but may incur frequent **low-level read** operations. **`BufferedReader`** reads ahead into an **internal buffer**, reducing overhead and improving performance for many small reads. It also provides convenient methods like **`readLine()`** for **line-based** text processing.

---

### **Q3. What is `try-with-resources` and why is it important for file handling?**

**Model answer:** **`try-with-resources`** declares one or more **`AutoCloseable`** resources in parentheses after **`try`**. The JVM guarantees each resource’s **`close()`** runs when the block exits, including on **exceptions**. For files, failing to **close** leaks **file handles** and can cause data loss (buffered data not flushed). **`try-with-resources`** makes cleanup **automatic** and pairs naturally with **`BufferedReader`**, **`PrintWriter`**, and **`Files`** APIs that return streams.

---

### **Q4. Compare `java.io.File` with `java.nio.file.Path` and `Files`.**

**Model answer:** **`File`** is the older representation of a **pathname** plus some **filesystem queries** and directory listing. **`Path`** is the modern **immutable** path abstraction; **`Files`** supplies **static utility methods** for reading, writing, copying, walking directories, and creating directories. New code should prefer **`Path` + `Files`** for filesystem operations because the API is clearer, more consistent, and better integrated with **exceptions** and **optional** advanced features — while still using **`Reader`/`Writer`** when streaming file **contents** is appropriate.

---

### **Q5. Why can naïve `line.split(",")` be wrong for CSV? Give an example failure mode.**

**Model answer:** CSV often allows **commas inside fields** if the field is **quoted**, and may escape quotes by **doubling** them. **`split(",")` treats every comma as a delimiter, regardless of quoting**, so a value like **`"Smith, Alex"`** would be split incorrectly into two fields. Real CSV needs a **parser** (or at least a state machine) that respects **quotes** and **escaping**; exam answers should name **embedded delimiters** and **quoted fields** as the core issue.

---

## 3. MUST-KNOW KEY POINTS

- **Streams vs paths:** **`Reader`/`Writer`/`Stream`** move **data**; **`Path`/`File`** locate **resources** on disk.
- **Buffering** improves performance; **`BufferedReader.readLine()`** is the standard **line** loop pattern.
- **`PrintWriter`** is the usual choice for **`printf`/`println`**-style **text output** to files.
- **`try-with-resources`** ensures **`close()`** runs — essential for correctness and exam code style.
- **UTF-8** should be your **default mental model** for text file encoding; avoid **platform default** surprises.
- **Checked exceptions:** **`IOException`** (and **`FileNotFoundException`**) force explicit **handling** or **`throws`** in signatures.
- **CSV** is **tabular** and **simple** only in the toy case; **quoted fields** break naïve splitting.
- **`Files.readAllLines` / `readString`** are convenient for **small** files; **streaming** (`BufferedReader`) suits **large** files.

---

## 4. HIGH-PRIORITY TOPICS (🔴 / 🟡 / 🟢)

| Priority | Topic | Why it matters |
|----------|--------|----------------|
| 🔴 | **`try-with-resources` + closing** | Every file question expects safe resource management. |
| 🔴 | **Byte vs character streams + encoding (UTF-8)** | Classic “explain the bug” and “correct constructor” questions. |
| 🔴 | **`IOException` / `FileNotFoundException` (checked)** | Signature and `catch` ordering questions. |
| 🟡 | **`BufferedReader` line loop + parsing to objects** | Lab-style “load address book” tasks. |
| 🟡 | **`Path`, `Files`, directory listing / `createDirectories`** | Modern API recognition and small code completion. |
| 🟡 | **CSV limitations + headers** | Compare robust parsing vs `split`. |
| 🟢 | **Four generations of Java I/O (story)** | High-level multiple-choice / short paragraph. |
| 🟢 | **`PrintWriter` formatting** | Often one short snippet question. |
| 🟢 | **`Scanner` vs `split` trade-offs** | Conceptual “when to use which” questions. |

---

## 5. TOPIC INTERCONNECTIONS

- **Exceptions (Slide 8):** file APIs surface **checked** **`IOException`** — connects to **`throws`**, **`catch`**, and why **`try-with-resources`** is preferred over manual **`finally`** for **`close()`**.
- **Strings and parsing:** file bytes → **decoded characters** → **`String`** operations → **`split` / `Scanner`** → **objects** (e.g. **`Contact`**). This is the pipeline from **persistence** to **OO model**.
- **Collections:** loaded records usually become **`List`**, **`Map`**, or **`Set`** structures in memory — file I/O is often “**serialization’s humble cousin**” before you meet **JSON** (next note).
- **NIO.2 + streams:** use **`Path`/`Files`** to **open** or **read whole files**, then optionally process line-by-line with **`BufferedReader`** for **memory-efficient** designs.

---

## 6. EXAM STRATEGY TIPS

- **Always show closing:** if you open a **`Reader`/`Writer`/`Stream`**, use **`try-with-resources`** unless the question forbids it.
- **Mention encoding** whenever text files appear: “**use UTF-8 explicitly**” is a high-value phrase.
- **Distinguish APIs:** one sentence — “**`Files` for filesystem operations; `BufferedReader` for streaming lines**” — earns structure marks.
- **For CSV questions:** state the **assumption** (“no commas in fields”) **or** explain why **`split` fails** with quoted commas.
- **Exception answers:** **`FileNotFoundException`** is a **`IOException`** subtype — catch **specific** before **general** if both appear.
- **Tracing:** a typical trace follows **open → read line → split/parse → construct object → add to list → close**; write those steps in order even in prose answers.

---

*These notes summarise typical COMP0004 delivery; always follow your term’s official slides and lab specifications for required APIs and coding style.*
