# File Handling Basics (Concise Revision)

## 1) Stream abstraction
- Java I/O is stream-based: data flows from source to destination.
- Main pairs:
  - `InputStream` / `OutputStream` for bytes (binary data),
  - `Reader` / `Writer` for characters (text data).

## 2) Text encodings (UTF-8 vs UTF-16)
- UTF-8: variable width (1-4 bytes), web standard, ASCII-compatible.
- UTF-16: usually 2 bytes, sometimes 4 via surrogate pairs.
- Encoding matters whenever text crosses file/network boundaries.

## 3) Internal vs external representation
- Java `String`/char processing is internal character representation.
- Files/network require encoded byte sequences (UTF-8, UTF-16, etc.).
- Always be explicit about encoding when reading/writing text.

## 4) `File` class idea
- `File` (or modern `Path`) represents a pathname, not file contents.
- Use it to locate files/directories and perform filesystem operations.

## Important Summary
- Pick byte streams for raw binary, character streams for text.
- Encoding mismatches cause subtle bugs; default to explicit UTF-8 unless required otherwise.
- Treat path handling and data reading/writing as separate concerns.

