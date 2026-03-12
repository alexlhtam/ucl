# JSON and CSV

## JSON
- Lightweight text format for structured data exchange.
- Built from key-value pairs and arrays.
- Core value types: `string`, `number`, `object`, `array`, `boolean`, `null`.
- Common in APIs and web backends.

Example:
```json
{
  "colour": "blue",
  "pages": 200,
  "tags": ["java", "notes"]
}
```

## CSV
- Plain-text tabular format (rows + delimited fields).
- Usually comma-separated, sometimes other delimiters (e.g. semicolon).
- Common for spreadsheets, exports, and simple data pipelines.

Example:
```text
name,score
Alex,90
Sam,84
```

## When to use which
- Use JSON for nested/structured objects.
- Use CSV for flat table-like data.

## Important Summary
- JSON is hierarchical and schema-flexible.
- CSV is simple and compact for tables, but weak for nested data.
- Parsing/serialization should be done via libraries, not manual string manipulation.