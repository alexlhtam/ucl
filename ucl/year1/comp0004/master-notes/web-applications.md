# Java Web Applications

## 1) Basic architecture
- Browser (client) sends HTTP requests.
- Java server app handles request logic.
- Data layer stores/retrieves information (files or database).
- Common mental model: 3-tier architecture.

## 2) MVC pattern
- **Model**: domain data + business logic.
- **View**: presentation (HTML/JSP/templates).
- **Controller**: receives request, coordinates model, picks response/view.

## 3) Web server + servlet model
- Server maps URL paths to handlers (files/servlets).
- Servlet classes usually extend `HttpServlet`.
- Typical lifecycle methods:
  - `init()` once at startup,
  - `doGet()` / `doPost()` per request,
  - `destroy()` on shutdown.

### Minimal servlet example
- This is the smallest useful servlet-style endpoint.
- URL example: `/hello?name=Alex`
- It reads a query parameter and returns plain text.

```java
import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet("/hello")
public class HelloServlet extends HttpServlet {
  @Override
  protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
    String name = req.getParameter("name");
    if (name == null || name.isBlank()) name = "world";

    resp.setContentType("text/plain; charset=UTF-8");
    resp.setStatus(HttpServletResponse.SC_OK);

    PrintWriter out = resp.getWriter();
    out.println("Hello, " + name + "!");
  }
}
```

- How to think about it:
  - `@WebServlet("/hello")` maps URL path to this servlet.
  - `doGet(...)` handles HTTP GET requests.
  - `req` is request input; `resp` is response output.
  - The container (e.g. Tomcat) is the actual web server runtime.

## 4) Request/response objects
- `HttpServletRequest`: input data (params, headers, cookies, session).
- `HttpServletResponse`: output data (status, headers, body).

### Simple `doPost` shape
```java
@Override
protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
  String email = req.getParameter("email");
  // validate + call model/service layer
  resp.sendRedirect("/thanks");
}
```

## 5) Threading note
- A servlet instance is reused across requests.
- Multiple request threads may execute concurrently.
- Shared mutable state in servlets must be handled carefully.

## 6) Deployment
- Java web apps are often packaged as `.war` files (Web ARchive).
- Server deploys/unpacks and serves under an application context path.

## 7) JSP in legacy Java web stacks
- JSP is view technology compiled into servlets.
- Historically used to reduce raw HTML generation in servlet code.
- Modern stacks often favor template engines/framework views (e.g. Thymeleaf).

## Important Summary
- Think request lifecycle: **URL -> controller/servlet -> model -> view -> response**.
- Keep business logic out of view templates.
- Understand servlet lifecycle + threading; they explain many web bugs.
