# Arrays — COMP0004

*Lecture-style notes aligned with Slides 4. Arrays are the bridge between **imperative loops** and **collections/APIs** you will use everywhere in Java.*

---

## 1. COMPLETE TOPIC SUMMARIES

### Java arrays vs **C arrays**

In **C**, an array name often decays to a **pointer** to the first element; you can do **pointer arithmetic** (e.g. `p + i`) and there is **no guaranteed runtime bounds check** — out-of-range access is **undefined behaviour**.

In **Java**, an array is a **proper object** on the **heap** (created with **`new`**). The language gives you **`[]` syntax**, but under the hood you still have an **object** with a **runtime length** and **bounds checking**:

- **No pointer arithmetic** on arrays: you cannot “move” a Java array reference by adding an offset like in C.
- **Bounds checking:** every indexed read/write **`arr[i]`** is checked; invalid **`i`** throws **`ArrayIndexOutOfBoundsException`**.
- **Length:** use **`arr.length`** (a **`public final` field** on array objects — not a method).

> **Mental model:** A Java array variable holds a **reference** to an array **object**; the object knows its **length** and stores **elements** in a contiguous layout (for each dimension).

---

### **Declaration** and **creation** (two conceptual steps)

You often write a **single line**, but conceptually there are **two ideas**:

1. **Declare** a variable whose type is “array of **`int`**”: **`int[] arr;`**
2. **Create** an array object and assign it: **`arr = new int[6];`**

Combined:

```java
int[] arr = new int[6]; // indexes 0 .. 5 inclusive
```

- **`new int[6]`** allocates an **`int`** array of **length 6**; all slots start at **default** values (see below).
- The **`[]`** can be written after the type (**`int[] arr`**, preferred style in Java) or after the name (**`int arr[]`** — C-style, legal but less idiomatic).

---

### **Default values** for array elements

When you allocate with **`new`**, every cell is initialised automatically:

| Element type | Default value |
|--------------|----------------|
| **`byte`**, **`short`**, **`int`**, **`long`** | **`0`** |
| **`float`**, **`double`** | **`0.0`** |
| **`boolean`** | **`false`** |
| **Reference types** (`String`, your own classes, etc.) | **`null`** |

So **`new int[100]`** gives one hundred **`0`**s; **`new String[10]`** gives ten **`null`** references (not empty strings).

---

### **Array initialisation** literals

If you already know the elements at compile time, use **brace initialisation**:

```java
int[] a = {1, 2, 3}; // cannot use this form after a blank declaration line in older patterns;
```

The **`new`-with-anonymous-array** form is handy when you need an expression (e.g. as an argument):

```java
int[] b = new int[] {1, 2, 3};
foo(new int[] {4, 5, 6});
```

Both create a **new array object** with the given length and values.

---

### **Indexing** and **`ArrayIndexOutOfBoundsException`**

- **Zero-based:** valid indices are **`0`** through **`length - 1`**.
- **`arr.length`** is **`6`** ⇒ legal indices **`0..5`** only.
- **`arr[6]`** or **`arr[-1]`** throws **`ArrayIndexOutOfBoundsException`** at **runtime**.

> **Exam trap:** **`length`** is not a method — no parentheses: **`a.length`**, not **`a.length()`**.

---

### **Iteration** patterns

**Traditional `for` loop** — use when you need the **index** or to **write** into specific positions:

```java
for (int i = 0; i < arr.length; i++) {
    System.out.println(i + ": " + arr[i]);
}
```

**Enhanced `for` (“for-each”)** — use when you only need **each value** (read-mostly over the whole array):

```java
for (int value : arr) {
    System.out.println(value);
}
```

You **cannot** resize the array in the loop; for-each also **hides** the index (use indexed `for` if you need it).

**Streams** — good for **pipelines** of transforms/filters/aggregations:

```java
import java.util.Arrays;

int[] nums = {1, 2, 3, 4};
int sum = Arrays.stream(nums).sum();
```

Here **`Arrays.stream(int[])`** gives an **`IntStream`**, avoiding **boxing** to **`Integer`**.

---

### **`IntStream.range`**, **`map`**, and **lambdas**

When you need **both index and value**, **`IntStream.range(0, arr.length)`** is a clean idiom:

```java
import java.util.stream.IntStream;

int[] a = {10, 20, 30};

int weighted = IntStream.range(0, a.length)
    .map(i -> i * a[i]) // lambda: i is the index
    .sum();
```

- **`range(start, endExclusive)`** emits **`start .. endExclusive-1`**.
- **`.map(...)`** transforms each stream element (here: index **`i`** → **`i * a[i]`**).
- **`.sum()`** is a **terminal operation** that runs the pipeline.

> **Beginner note:** **Lambdas** are shorthand for **functional interfaces**; for **`map`**, you supply a function **`int → int`**.

---

### **2D arrays** are **arrays of arrays**

```java
int[][] twoD = new int[3][7];
```

- **`twoD`** references an array of **length 3**.
- Each **`twoD[r]`** is itself an **`int[]`** of **length 7**.
- **Row *r*, column *c*:** **`twoD[r][c]`**.

**Nested traditional loops:**

```java
for (int r = 0; r < twoD.length; r++) {
    for (int c = 0; c < twoD[r].length; c++) {
        // use twoD[r][c]
    }
}
```

Notice **`twoD[r].length`**: rows could differ in **ragged** arrays (next section).

**Nested enhanced for:**

```java
for (int[] row : twoD) {
    for (int value : row) {
        // use value
    }
}
```

**Streams:** treat each row as an **`int[]`**, flatten to one **`IntStream`**, aggregate:

```java
int total = Arrays.stream(twoD)
    .flatMapToInt(Arrays::stream)
    .sum();
```

---

### **Ragged arrays** (jagged rows)

Because each row is its own **`int[]`**, row lengths may differ:

```java
int[][] rag = new int[3][];
rag[0] = new int[] {1, 2};
rag[1] = new int[] {3, 4, 5, 6};
rag[2] = new int[] {7};
```

This models **triangular tables**, **sparse structures**, or irregular data without wasting a full rectangle.

---

### **N-dimensional arrays**

The idea generalises: **`double[][][]`** is an array of **`double[][]`**, each of which is an array of **`double[]`**, etc. You can allocate partially:

```java
double[][][] cube = new double[4][5][6];
```

Or build ragged structures at deeper levels — each dimension is “just another array object.”

---

### **Zero-length arrays**

**`new int[0]`** is **legal** and often **preferable to `null`** when representing “no results”:

```java
int[] empty = new int[0];
for (int x : empty) { } // runs zero times — safe
```

Returning **`null`** forces every caller to **null-check**; returning **`new T[0]`** lets callers use uniform loops without branching.

---

### **`java.util.Arrays` utility class**

**`Arrays`** provides **static** helpers — sorting, searching, comparison, parallel operations, and **streaming**:

```java
import java.util.Arrays;

int[] a = {3, 1, 4};
Arrays.sort(a);                    // mutates a
int idx = Arrays.binarySearch(a, 3); // array must be sorted for correct binary search semantics

int[] b = {3, 1, 4};
boolean same = Arrays.equals(a, b);

int sum = Arrays.stream(a).sum();
```

Common methods to recognise: **`sort`**, **`binarySearch`**, **`equals`**, **`fill`**, **`copyOf`**, **`toString`**, **`stream`**.

---

### **`Array` type** — special language status

Every Java array type is a **subtype of `Object`** and implements **`Cloneable`** and **`Serializable`**. You use **`[]`** at the language level, but arrays are still **objects** with **identity**, **`equals`** behaviour (reference equality by default unless you compare contents via **`Arrays.equals`**), and **`length`**.

---

### **Arrays vs `ArrayList`**

- **Arrays:** **fixed size** after allocation; very **lean**; great for **known-size** buffers and **performance-sensitive** numeric code.
- **`ArrayList<E>`:** **resizable**; rich **collection** API; **generics** give **type safety**; usually **prefer `ArrayList`** for application logic where size grows/shrinks.

> **Rule of thumb:** default to **`ArrayList`** (or other collections) unless you have a concrete reason for a fixed array.

---

## 2. EXAM-STYLE QUESTIONS (3–5 with model answers)

### Q1 — Java vs C arrays

**Question:** Explain two **concrete** differences between **Java arrays** and **C-style arrays** (as typically used with pointers), focusing on **memory model** and **safety**.

**Model answer:** (1) A Java array is a **heap object** created with **`new`**; a variable of type **`T[]`** holds a **reference** to that object, not a raw memory address you may arithmetic-advance. (2) Java performs **runtime bounds checking** on each **`arr[i]`** access, throwing **`ArrayIndexOutOfBoundsException`** on illegal indices, whereas out-of-range access through pointers in C is **undefined behaviour** with no mandatory check. (Optional third point: Java exposes **`length`** on the array object; no pointer decay model.)

---

### Q2 — Defaults and initialisation

**Question:** What values appear in each element after **`String[] s = new String[5];`** and **`double[] x = new double[5];`**? Why?

**Model answer:** For **`String[]`**, each slot is **`null`** because **reference** types default to **`null`**. For **`double[]`**, each slot is **`0.0`** because **numeric floating-point** primitives default to **zero**. The **`new`-allocated** array initialises every element to the type’s **default** before any explicit assignment.

---

### Q3 — 2D arrays and ragged rows

**Question:** Explain why **`int[][] m = new int[3][];`** is valid. How does **`m[1].length`** differ from **`m[2].length`** in a ragged configuration?

**Model answer:** **`m`** is an array of **three** references to **`int[]`**. The second dimension is not allocated by **`new int[3][]`** — each **`m[i]`** starts as **`null`** until assigned. In a **ragged** array, **`m[1]`** and **`m[2]`** refer to **different** row arrays, so **`.length`** can differ (e.g. row 1 has 4 ints, row 2 has 1). You must **allocate or assign** each row before indexing **`m[i][j]`**, otherwise you risk **`NullPointerException`**.

---

### Q4 — Pass-by-value with references (arrays as objects)

**Question:** Java is **call-by-value**. Consider:

```java
static void bumpFirst(int[] a) {
    a[0] += 1;
}

public static void main(String[] args) {
    int[] x = {10, 20};
    bumpFirst(x);
    System.out.println(x[0]);
}
```

What is printed, and why does this not contradict call-by-value?

**Model answer:** Prints **`11`**. The parameter **`a`** receives a **copy of the reference value** pointing to the **same array object** as **`x`**. Mutating **`a[0]`** mutates **shared object state**. Call-by-value means the **reference itself** is copied, not the **array contents**; Java never passes objects “by object copy” implicitly.

---

### Q5 — Streams vs loops

**Question:** Write a **stream-based** expression that sums **even** numbers in **`int[] nums`**. Mention one **advantage** and one **caution** of streams for beginners.

**Model answer:** Example:

```java
int evenSum = Arrays.stream(nums)
    .filter(n -> n % 2 == 0)
    .sum();
```

**Advantage:** clear **dataflow** (filter → aggregate) for simple pipelines. **Caution:** easy to accidentally **box** primitives if you use **`Stream<Integer>`** instead of **`IntStream`**; also debugging can feel harder than a plain **`for`** loop when logic branches heavily.

---

## 3. MUST-KNOW KEY POINTS

- Java arrays are **objects** with **`length`** and **runtime bounds checks** — **no pointer arithmetic**.
- **Declaration** vs **creation**: **`T[] ref;`** then **`ref = new T[n];`** — often written in one line.
- **Default values:** **`0` / `0.0` / `false` / `null`** depending on element type.
- Initialisation: **`{...}`** and **`new T[] { ... }`**.
- Indexing is **0 .. length-1**; mistakes throw **`ArrayIndexOutOfBoundsException`**.
- Iterate with **indexed `for`**, **for-each**, or **`Arrays.stream`** / **`IntStream.range`** when indices matter.
- **`int[][]`** means **array of row arrays**; rows may be **ragged**.
- Flatten 2D numeric arrays with **`flatMapToInt(Arrays::stream)`**.
- **Zero-length arrays** are valid; often better than **`null`** for “empty results.”
- Know **`Arrays`**: **`sort`**, **`binarySearch`**, **`equals`**, **`stream`**.
- Prefer **`ArrayList`** for typical **resizable** sequences; arrays for **fixed** layouts and tight loops.

---

## 4. HIGH-PRIORITY TOPICS

| Priority | Topic | Why it matters |
|----------|--------|----------------|
| 🔴 **Must know** | **Java array = object + `length` + bounds checks** | Core language semantics; contrasts with C thinking. |
| 🔴 **Must know** | **Default initialisation** after **`new`** | Predicts contents before you assign explicitly. |
| 🔴 **Must know** | **Valid index range** and **`ArrayIndexOutOfBoundsException`** | Universal bug/edge-case theme. |
| 🔴 **Must know** | **Indexed `for` vs for-each** — when each is appropriate | Shows control vs simplicity trade-off. |
| 🟡 **Important** | **`Arrays.stream` / `IntStream` / `IntStream.range`** | Modern Java style + exam “rewrite as stream” tasks. |
| 🟡 **Important** | **2D = arrays of arrays; ragged rows** | Appears in matrix/grid questions and **`NullPointerException`** traps. |
| 🟡 **Important** | **`Arrays` utilities** (`sort`, `binarySearch`, `equals`, `stream`) | Practical API literacy. |
| 🟢 **Useful** | **N-dimensional generalisation** | Rare detail questions; builds confidence. |
| 🟢 **Useful** | **Zero-length arrays vs `null`** | Good design hygiene in written answers. |
| 🟢 **Useful** | **Arrays vs `ArrayList` trade-offs** | Shows you can choose structures deliberately. |

---

## 5. TOPIC INTERCONNECTIONS & BIGGER PICTURE

- **References & objects:** Arrays are the first place many courses make **heap objects** tangible — same **reference copying** rules apply as for any **object** type.
- **Loops & complexity:** Traversing **`n`** elements is **Θ(n)** time; 2D **`R×C`** grids are typically **Θ(R·C)** unless structure is ragged (then sum of row lengths).
- **Collections:** **`ArrayList`** internally uses arrays; understanding **fixed vs resizable** clarifies **why** lists grow via **reallocation** strategies (amortised cost) later.
- **Functional style:** Streams connect to **lambdas** and **method references**, previewing **functional interfaces** and **API design** in later OOP topics.
- **Defensive programming:** Bounds checks and **empty arrays** foreshadow **exceptions**, **`Optional`**, and API contracts (“never return **`null`** arrays”).

---

## 6. EXAM STRATEGY TIPS

- **Define before you derive:** one sentence — “**`arr` references an array object of length **`n`**, indices **`0..n-1`**.”
- **Trace memory diagrams:** for reference questions, draw **one array object** and **two arrows** (variables) when explaining aliasing.
- **Streams:** if asked for a stream solution, prefer **`IntStream`** for **`int[]`** to avoid **boxing**.
- **2D loops:** always tie inner bound to **`matrix[r].length`** when ragged is possible.
- **Binary search caveat:** mention **`Arrays.binarySearch` requires sorted data** (or explain the returned insertion-point convention if you’ve been taught it).
- **Pick structure deliberately:** end written answers with **when you’d pick array vs `ArrayList`** for maintainability.

---

*End of notes — Arrays (COMP0004, Slides 4).*
