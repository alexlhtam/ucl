# Exceptions (Concise Revision)

## 1) What exceptions do
- Exceptions signal abnormal situations at runtime.
- If uncaught, they terminate the current thread/program flow.
- Proper handling protects data integrity and user experience.

## 2) Checked vs unchecked
- **Checked exceptions**: must be handled or declared with `throws`.
- **Unchecked exceptions** (`RuntimeException` and subclasses): optional to catch, often programming errors.

## 3) Core syntax
```java
try {
  riskyOperation();
} catch (IOException e) {
  // recover or report
} finally {
  // cleanup (always runs)
}
```

```java
throw new MyException("method failed");
```

## 4) `throws` usage
- Use `throws` to propagate checked exceptions to caller.
- Caller must then handle or propagate further.

```java
public void readFile() throws IOException { ... }
```

## 5) Exception hierarchy (minimal view)
- `Throwable`
  - `Error` (serious JVM/system issues; usually not recovered in app code)
  - `Exception`
    - `RuntimeException` (unchecked)

## 6) Exceptions vs optional return values
- Use exceptions when operation cannot reasonably continue.
- Use optional/nullable-like return patterns for expected absence/failure paths.

## Important Summary
- Catch only exceptions you can meaningfully handle.
- Prefer specific exception types over broad `Exception`.
- Always release resources (`finally` or try-with-resources pattern).