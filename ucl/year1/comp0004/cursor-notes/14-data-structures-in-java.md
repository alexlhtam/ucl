# Data Structures in Java — COMP0004 Object-Oriented Programming (UCL)

*Lecture-style notes aligned with Slides 20–21: **classes as data structures**, **singly/doubly linked lists**, **`Iterator<T>`**, **inner classes**, **binary trees** and **BSTs**, **traversals**, **hash tables** (**hashing**, **collisions**, **separate chaining**), **`java.util`** (**`LinkedList`**, **`TreeMap`**, **`HashMap`**), and **Big-O** comparisons.*

---

## 1. COMPLETE TOPIC SUMMARIES

### **Classes as data structures**

In **OOP**, you implement **abstract data types** with **classes**: **fields** hold **state**, **methods** implement **operations**. A **linked list** or **tree** is not magic — it is **objects** linked by **references**.

---

### **Linked list: `Node` with `data` + `next`**

A **singly linked list** is a chain of **nodes**:

```java
public class Node<E> {
    E data;
    Node<E> next;

    Node(E data, Node<E> next) {
        this.data = data;
        this.next = next;
    }
}
```

The **list** object typically holds a **`head`** reference (and sometimes **`tail`** / **`size`** for efficiency).

**Core operations (conceptual):**

| Operation | Idea |
|-----------|------|
| **Prepend** | New node’s **`next = head`**, then **`head = newNode`** — **O(1)** if you have `head`. |
| **Append** | Walk to last node (**O(n)**) or keep **`tail`** for **O(1)** append. |
| **Insert** | After locating position, relink **`prev.next`** and **`newNode.next`**. |
| **Delete** | Relink **`prev.next = node.next`** (handle **`head`** specially). |
| **Traverse** | `for (Node<E> n = head; n != null; n = n.next) { ... }` |

---

### **Implementing `Iterator<T>`**

**`Iterator<E>`** provides **`hasNext()`**, **`next()`**, and optionally **`remove()`**. For a linked list, the iterator keeps a **cursor** (`Node<E> current`) and advances along **`next`**.

```java
import java.util.Iterator;
import java.util.NoSuchElementException;

public class SinglyLinkedList<E> implements Iterable<E> {
    private Node<E> head;
    // ... list methods ...

    @Override
    public Iterator<E> iterator() {
        return new ListIterator();
    }

    private class ListIterator implements Iterator<E> {
        private Node<E> cursor = head;

        @Override
        public boolean hasNext() {
            return cursor != null;
        }

        @Override
        public E next() {
            if (!hasNext()) throw new NoSuchElementException();
            E value = cursor.data;
            cursor = cursor.next;
            return value;
        }
    }
}
```

**`Iterable<T>`** + **`iterator()`** enables the **enhanced for-loop**: `for (E x : list)`.

---

### **Inner classes for `Node` and `Iterator`**

**Non-static nested classes** (**inner classes**) can access the **outer instance**’s fields (e.g. **`head`**). Hiding **`Node`** as **`private static`** or **private inner** keeps the **implementation** from leaking to clients — **encapsulation**.

- **`private static class Node<E>`** — no reference to outer `this`; common when nodes don’t need the list instance.
- **Inner iterator** — often non-static if it needs outer state; still **private** so only your list exposes **`Iterable`**.

---

### **Doubly linked list basics**

Each **node** has **`prev`** and **`next`**:

- **Delete** and **insert** at a known node are **O(1)** if you already have references (no need to find predecessor).
- Cost: **extra memory** per node, slightly more **invariant** work when relinking.

```java
static final class DNode<E> {
    E data;
    DNode<E> prev;
    DNode<E> next;
}
```

---

### **Binary trees**

A **binary tree** **node** has **`left`** and **`right`** children (possibly **`null`**). Structure is **recursive**: a tree is empty, or a **root** whose **subtrees** are binary trees.

```java
class TreeNode<E> {
    E data;
    TreeNode<E> left;
    TreeNode<E> right;
}
```

---

### **Binary search tree (BST)**

A **BST** stores **comparable** keys with the **ordering property**:

- Every key in the **left subtree** is **less** than the **root** key.
- Every key in the **right subtree** is **greater** (or `>=` depending on convention for duplicates).

**Search:** compare target to root; go **left** or **right** — **O(h)** where **h** is **height**.

**Insert:** search until **`null`** child; attach new node — **O(h)**.

**In-order traversal** visits nodes in **sorted order** for a valid BST.

---

### **Tree traversals**

Assume **visit** prints or processes **`node.data`**:

| Traversal | Order (mnemonic) |
|-----------|------------------|
| **In-order** | **left**, **root**, **right** |
| **Pre-order** | **root**, **left**, **right** |
| **Post-order** | **left**, **right**, **root** |

```java
void inOrder(TreeNode<E> n, Comparator<E> cmp) {
    if (n == null) return;
    inOrder(n.left, cmp);
    visit(n.data);
    inOrder(n.right, cmp);
}
```

---

### **Hash tables: hashing and collisions**

A **hash table** maps **keys** to **values** using a **hash function** **`h(key)`** that returns an **array index** (often `hashCode()` reduced modulo bucket count).

**Collision:** two distinct keys map to the **same bucket**. Common strategies:

- **Separate chaining** — each bucket is a **collection** (often **linked list**) of entries.
- **Open addressing** — store colliding entries in other slots (linear probing, etc.) — more advanced for this course level.

---

### **Separate chaining**

Maintain an **array** of **buckets**; each bucket is a **list** of **key–value** pairs.

- **put** — compute bucket; if key exists, replace value; else **prepend**/**append** entry.
- **get** — compute bucket; **scan** list for matching key (**`equals`** after **`hashCode`** agreement).
- **contains** — same as **get** but boolean.

---

### **`java.util` implementations: how they relate**

| Class | Underlying idea | Ordered? | Typical cost |
|-------|-----------------|----------|--------------|
| **`LinkedList<E>`** | **Doubly linked** nodes | **Insertion order** when iterating | Index access **O(n)**; add at ends **O(1)** with references |
| **`TreeMap<K,V>`** | **Red–black tree** (BST variant) | **Sorted** by key | **O(log n)** put/get |
| **`HashMap<K,V>`** | **Hash table** + buckets | **Unpredictable** iteration order | **O(1)** average put/get; **O(n)** worst case if many collisions |

---

### **Performance summary (exam classic)**

| Structure | Lookup / search | Notes |
|-----------|-----------------|--------|
| **Hash table** | **O(1)** average | Depends on **good hash** and **load factor** |
| **BST** (balanced-ish) | **O(log n)** | Unbalanced BST can degrade to **O(n)** |
| **Linked list** (unsorted) | **O(n)** | Must **scan** |
| **Linked list** by index | **O(n)** | No random access |

---

## 2. EXAM-STYLE QUESTIONS (with model answers)

### Q1 — BST property

**Question:** State the **ordering property** of a **binary search tree** and what **in-order traversal** yields.

**Model answer:** For every node, **all keys in the left subtree** are **less** than the node’s key and **all keys in the right subtree** are **greater** (for a simple no-duplicates tree). **In-order traversal** (left, root, right) visits keys in **sorted ascending order**.

---

### Q2 — Iterator purpose

**Question:** Why implement **`Iterator<E>`** for your own linked list instead of exposing **`Node`** references?

**Model answer:** **`Iterator`** hides **internal structure** so clients can traverse **safely** without depending on **`Node`**. It supports **uniform** traversal with **`hasNext`/`next`** and enables **`for-each`** via **`Iterable`**, preserving **encapsulation**.

---

### Q3 — Hash collisions

**Question:** What is a **collision** in a **hash table**? Name one resolution strategy and describe **separate chaining** in one sentence.

**Model answer:** A **collision** occurs when two different keys **hash to the same bucket index**. **Separate chaining** stores an **array of buckets**, each bucket a **linked list** (or similar) of all entries that mapped to that index.

---

### Q4 — Complexity comparison

**Question:** Compare **average** lookup time in a **`HashMap`**, a **balanced BST**, and an **unsorted singly linked list** containing **n** elements.

**Model answer:** **`HashMap`**: **O(1)** average (constant-time bucket + short chain). **BST** (balanced): **O(log n)**. **Unsorted linked list**: **O(n)** linear scan. Mention **worst case** **O(n)** for hash table if **all keys collide**.

---

### Q5 — Prepend vs append on singly linked list

**Question:** Why is **prepend** **O(1)** at **`head`** while **append** may be **O(n)** without a **`tail`** pointer?

**Model answer:** **Prepend** only updates **`head`** to the new node — no walk. **Append** must find the **last node** whose **`next` is null**, which requires traversing all **n** nodes unless a **`tail`** reference is maintained.

---

## 3. MUST-KNOW KEY POINTS

- **Linked list:** **`Node`**, **`next`**, **prepend/append/delete/traverse** complexities.
- **`Iterator` / `Iterable`:** **`hasNext`**, **`next`**, **encapsulation** of traversal.
- **Inner / nested classes** to hide **representation**.
- **BST:** **ordering property**, **insert/search** = **tree height**, **in-order** = **sorted**.
- **Traversals:** **in-, pre-, post-order** recursive patterns.
- **Hash table:** **`hashCode` + equals**, **collisions**, **separate chaining**.
- **`HashMap` vs `TreeMap` vs `LinkedList`:** **hash vs tree vs linked**; **Big-O** expectations.

---

## 4. HIGH-PRIORITY TOPICS (🔴 / 🟡 / 🟢)

| Priority | Topic | Why it matters |
|----------|--------|----------------|
| 🔴 | **BST ordering** + **in-order** sorted output | Definition + traversal questions appear constantly. |
| 🔴 | **Hash table** + **collisions** + **chaining** | Classic “how does `HashMap` work?” |
| 🔴 | **O(1) vs O(log n) vs O(n)** for map/list lookup | Short comparison tables score well. |
| 🟡 | **Singly linked list** operations | Relinking **`next`** references on paper. |
| 🟡 | **`Iterator`** implementation sketch | Shows OOP + ADT together. |
| 🟡 | **`TreeMap` vs `HashMap`** | Sorted keys vs average-time hash. |
| 🟢 | **Doubly linked list** advantage | **O(1)** delete with **known node**. |
| 🟢 | **Inner vs static nested** `Node` | Encapsulation vocabulary. |

---

## 5. TOPIC INTERCONNECTIONS

- **`Iterable`/`Iterator`** connect **linked lists** to **for-each** and the same **pattern** used by **`java.util`** collections.
- **BST** is the conceptual model behind **`TreeMap`** / **`TreeSet`** (with **self-balancing** in the library).
- **Hash tables** use **`hashCode`** and **`equals`** — the same **contract** you learned for **`HashMap`** keys.
- **Lists vs maps:** **position-based** (**`LinkedList`**) vs **key-based** (**`HashMap`**); choose by access pattern.
- **Worst cases:** **skewed BST** → **linked-list shape**; **bad hash** → long **chains**.

---

## 6. EXAM STRATEGY TIPS

- For **BST**, redraw a **small tree** and trace **insert** or **search** with comparisons at each level.
- When asked for **traversal**, write **three lines** of recursion: **base case** `null`, then **left/root/right** order swapped per type.
- For **hash tables**, always mention **`equals`** after **bucket index** — two objects can have **same bucket** but still be **unequal**.
- If you sketch **`Iterator`**, show **`cursor`** moving along **`next`** and **`NoSuchElementException`** when exhausted.
- **Big-O** answers: qualify **average vs worst** for **hashing**; say **height** for **trees**.
