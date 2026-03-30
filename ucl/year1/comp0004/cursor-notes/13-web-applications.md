# Web Applications — COMP0004 Object-Oriented Programming (UCL)

*Lecture-style notes aligned with Slides 14: **three-tier architecture**, **HTTP**, **HTML**, **Java web stacks** (**Servlets**, **JSP**, **Spring Boot**), **REST** and **JSON**, **MVC**, **static vs dynamic** content, **deployment**, and **security** basics.*

---

## 1. COMPLETE TOPIC SUMMARIES

### **Three-tier / three-layer web architecture**

Most **web applications** are described as **three tiers** (or three logical layers):

1. **Presentation tier (client)** — usually a **web browser** (or mobile app) that sends **HTTP requests** and renders **HTML**, **JSON** consumers, etc.
2. **Application tier (server)** — a **web server** runs your **application code** (e.g. **Servlets**, **Spring Boot** controllers). This layer implements **business logic**, talks to storage, and builds responses.
3. **Data tier** — **databases**, file systems, or other services where information is **persisted** and **queried**.

> **Beginner intuition:** The **browser** asks a question; the **server** thinks and fetches data; the **database** remembers things long-term. Each tier can scale or change technology somewhat independently.

---

### **HTTP protocol basics**

**HTTP** (**Hypertext Transfer Protocol**) is how clients and servers communicate on the web.

- A **request** from the client includes: a **method** (verb), a **URL** (path + optional query string), **headers**, and sometimes a **body**.
- A **response** from the server includes: a **status code** (e.g. **200 OK**, **404 Not Found**), **headers**, and a **body** (HTML, JSON, image bytes, …).

**Common methods:**

| Method | Typical use |
|--------|-------------|
| **GET** | **Retrieve** a resource; should be **safe** and **idempotent** in good design (no lasting side effects). Data often in **query string** (`?name=value`). |
| **POST** | **Submit** data (forms, file uploads); often creates resources or triggers actions. Data usually in **request body**. |

Other methods you should recognise: **PUT** (replace/update), **PATCH** (partial update), **DELETE** (remove) — central to **RESTful APIs**.

---

### **HTML basics for web UI**

**HTML** (**HyperText Markup Language**) structures the **content** of web pages: headings, paragraphs, lists, links, forms, buttons.

- Browsers **parse** HTML and **render** a page; **CSS** styles it; **JavaScript** adds interactivity.
- **Forms** (`<form>`, `<input>`, `<button>`) are how users **submit** data; the **`action`** URL and **`method`** (often **GET** or **POST**) determine how the **server** receives input.

---

### **Java web frameworks: Servlets, JSP, Spring Boot**

- **Servlets** — low-level Java **request handlers** (often subclass **`HttpServlet`**). The **servlet container** (e.g. **Tomcat**) maps URLs to servlet classes and calls **`doGet`**, **`doPost`**, etc. Still the conceptual core of many Java web stacks.
- **JSP** (**JavaServer Pages**) — **historical** view technology: HTML mixed with Java snippets, **compiled to servlets**. Helped avoid printing HTML from Java by hand; modern apps often prefer **template engines** or **SPA** front ends.
- **Spring Boot** — **modern** framework: **convention over configuration**, embedded server, **annotations** (`@RestController`, `@GetMapping`), **dependency injection**, and strong **ecosystem** for **REST**, **security**, and **data access**.

---

### **RESTful APIs**

**REST** (**Representational State Transfer**) is an **architectural style** (not a single library) for networked systems.

**REST principles** (exam-friendly summary):

- **Resources** are identified by **URLs** (e.g. `/api/books/42`).
- **Representations** (often **JSON**) are exchanged; the server sends **state** of a resource, not hidden “RPC endpoints” named after verbs only.
- **Stateless** requests: each request carries what the server needs (tokens, IDs); the server does not rely on hidden **server-side session** for every API call (though cookies/sessions exist for browser apps).
- Use **HTTP methods** meaningfully (**GET** read, **POST** create, **PUT/PATCH** update, **DELETE** delete).

**HTTP methods mapped to CRUD** (typical mapping):

| CRUD | HTTP | Example |
|------|------|---------|
| **Create** | **POST** | `POST /api/books` with JSON body |
| **Read** | **GET** | `GET /api/books/42` |
| **Update** | **PUT** or **PATCH** | `PUT /api/books/42` |
| **Delete** | **DELETE** | `DELETE /api/books/42` |

An **endpoint** is a specific **URL + method** combination your server exposes.

---

### **JSON for web APIs**

**JSON** (**JavaScript Object Notation**) is a **lightweight text format**: objects `{ "key": value }`, arrays `[ ... ]`, strings, numbers, booleans, `null`.

- **Human-readable** and **language-neutral** — easy for browsers, mobile apps, and servers to exchange data.
- In Java, libraries like **Jackson** or **Gson** **serialize** objects → JSON and **deserialize** JSON → objects.

```java
// Conceptual: a record or POJO maps cleanly to JSON fields
public record Book(String title, String author, int year) { }

// Server sends: {"title":"...","author":"...","year":2024}
```

---

### **MVC: Model–View–Controller**

**MVC** separates concerns:

- **Model** — **domain data** and **business rules** (e.g. `Book`, `Order`, services that validate and persist).
- **View** — **presentation** (HTML page, JSP, Thymeleaf template, or JSON is “view” in API terms).
- **Controller** — **handles HTTP request**, calls the **model**, chooses **which view** or **response** to return.

This improves **testability** and **maintainability**: UI changes don’t force rewriting core logic, and logic isn’t buried in templates.

---

### **Client–server communication**

1. **Client** sends **request** (browser navigation, form submit, `fetch`/XHR).
2. **Server** **routing** picks a **handler** (servlet, controller).
3. Handler **parses** input (parameters, JSON body), calls **model** layer.
4. Handler **generates response** — set **status**, **headers**, write **body** (HTML or JSON).

---

### **Static vs dynamic web content**

| | **Static** | **Dynamic** |
|---|------------|-------------|
| **What** | Fixed files (**HTML**, CSS, images) served as-is | Content **generated per request** (database lookup, user session, template fill) |
| **Who builds it** | Uploaded to server once | **Application code** runs on each request |
| **Example** | Course syllabus `.html` | “My account” page with your name and orders |

Many real sites mix both: **static assets** from a CDN, **dynamic** data from APIs.

---

### **Deployment basics: web servers and application servers**

- **Web server** — serves HTTP, often **static files**, and may **reverse proxy** to an app (e.g. **nginx** in front of Java).
- **Application server / servlet container** — runs **Java web applications** (**.war** deployable), manages **servlets**, **threads**, **sessions** (e.g. **Tomcat**, **Jetty**).
- **Spring Boot** often bundles an **embedded** server — one **JAR** runs the whole app for development and many production setups.

---

### **Security considerations**

- **Input validation** — never trust **query parameters**, **form fields**, or **JSON** from clients. Validate **types**, **ranges**, and **allowed values** before using data in **SQL**, **file paths**, or **HTML output**.
- **Authentication** — verify **who** the user is (login, **tokens**, **sessions**). **Authorisation** decides **what** they may do.
- Related exam topics: **SQL injection** (use **parameterised queries**), **XSS** (escape output when injecting user text into HTML), **HTTPS** for transport encryption.

---

## 2. EXAM-STYLE QUESTIONS (with model answers)

### Q1 — Three-tier architecture

**Question:** Name the **three tiers** in a typical web application and state **one responsibility** of each.

**Model answer:** **(1) Client/presentation** — browser or app sends requests and displays responses. **(2) Application** — web server runs business logic, orchestrates processing. **(3) Data** — persistent storage (database/files) for reading and writing domain data.

---

### Q2 — GET vs POST

**Question:** Explain when you would use **HTTP GET** vs **HTTP POST** for a form that searches a product catalogue vs one that places an order.

**Model answer:** **Search** is a **read** operation with no lasting server-side change → **GET** is appropriate (bookmarkable URL, cacheable; parameters in query string). **Placing an order** **creates** state and must not be accidentally repeated by refresh → **POST** (body carries order details; browsers warn on resubmit). Design **POST** for **non-idempotent** actions.

---

### Q3 — REST and CRUD

**Question:** Map **CRUD** operations to **HTTP methods** and give an example URL pattern for a `Student` resource with id `7`.

**Model answer:** **Create** → **POST** `/students`; **Read** → **GET** `/students/7`; **Update** → **PUT** or **PATCH** `/students/7`; **Delete** → **DELETE** `/students/7`. (Plural resource collections with **id** in the path is standard REST style.)

---

### Q4 — MVC roles

**Question:** In **MVC**, which component should contain validation rules for “a user must not borrow more than five books”? Justify briefly.

**Model answer:** The **model** (domain/service layer). Validation is **business logic**, not presentation. The **controller** should **invoke** the model and map results to HTTP; the **view** should only **display** outcomes/errors, not encode the rule.

---

### Q5 — Static vs dynamic

**Question:** Distinguish **static** and **dynamic** web content with one example of each.

**Model answer:** **Static** content is **pre-written** and served unchanged (e.g. a `logo.png` or `about.html`). **Dynamic** content is **generated per request** using application logic and often data stores (e.g. “Welcome, Alex” on a dashboard after database lookup).

---

## 3. MUST-KNOW KEY POINTS

- **Three tiers:** **client**, **application server**, **data** storage.
- **HTTP request/response:** **method**, **URL**, **headers**, **body**; **status codes**.
- **GET** for **safe reads**; **POST** for **submissions** / creates; **PUT/PATCH/DELETE** in **REST**.
- **JSON** as the dominant **API payload** format; **serialisation** in Java.
- **REST:** **resources** as **URLs**, **stateless** style, meaningful **HTTP verbs**.
- **MVC:** **Model** (logic/data), **View** (UI/representation), **Controller** (request coordination).
- **Static** vs **dynamic** pages; **Servlets** vs **Spring Boot** as **historical vs modern** Java web style.
- **Security:** **validate input**, **authenticate** users, mind **injection** and **XSS**.

---

## 4. HIGH-PRIORITY TOPICS (🔴 / 🟡 / 🟢)

| Priority | Topic | Why it matters |
|----------|--------|----------------|
| 🔴 | **HTTP** methods (**GET/POST**) + **request/response** | Foundation for everything web-related on exams. |
| 🔴 | **Three-tier architecture** | Standard high-level diagram question. |
| 🔴 | **REST** + **CRUD ↔ HTTP** mapping | Very common short-answer / design question. |
| 🟡 | **MVC** responsibilities | Links OOP course to how real apps are structured. |
| 🟡 | **JSON** + **APIs** | Explain data exchange without HTML. |
| 🟡 | **Static vs dynamic** | Quick definitional plus example. |
| 🟢 | **Servlets / JSP / Spring Boot** | “What is X?” and **historical vs modern** comparison. |
| 🟢 | **Deployment** (**.war**, **Tomcat**, embedded server) | Vocabulary and one-sentence roles. |
| 🟢 | **Security** (validation, auth) | Often a bullet list in “what could go wrong?” questions. |

---

## 5. TOPIC INTERCONNECTIONS

```text
Browser (HTML/JS)  --HTTP-->  Web server + Java app (Servlets / Spring)
                                    |
                                    | JDBC / repositories
                                    v
                              Database / files
```

- **MVC** structures the **application tier** so **HTTP handlers** stay thin.
- **REST + JSON** often means the **view** is not HTML but **serialised objects** consumed by **JavaScript** clients.
- **Three-tier** explains **where** **authentication** happens (usually **application tier** + **data** for user records).
- **GET/POST** choices affect **caching**, **bookmarks**, and **security** (e.g. not putting secrets in **GET** URLs).

---

## 6. EXAM STRATEGY TIPS

- Draw **three boxes** (client, server, data) and label **one arrow** each way with **HTTP** and **SQL** (or “persistence”) when asked for architecture.
- For **REST**, write a **mini table**: **Create → POST**, **Read → GET**, etc., with a **plural noun** URL like `/items/{id}`.
- When comparing **GET** and **POST**, mention **idempotency**, **side effects**, and **where data lives** (query string vs body).
- For **MVC**, use a **one-line job description** per letter — avoid repeating “handles requests” for both **C** and **M**.
- If a question mentions **security**, pair **input validation** with a **concrete risk** (e.g. **SQL injection**, **XSS**) for full marks.
