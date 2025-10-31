# terminal-based i/o

## input and output (i/o)
- basic i/o is defined in terms of sequences of characters
  - read characters from the input stream
    - e.g. keyboard, file, network socket
  - write characters to ouput stream
    - e.g. terminal screen, file, network socket
- use the file abstraction:
  - open
  - read/write
  - close
- a file handle connects a file with an actual device or file in the filing system
  - "everything is a file"
    - this includes the screen and keyboard

## default files
- stdin
  - connected to the default input (keyboard)
- stdout
  - connected to the default output (terminal view)
- stderr
  - connected to the default error output (terminal view)