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
- created automatically when a program is run
- default config, can be easily overridden

## printing
- printf is a function defined in the standard C library
- writes to stdout
- `printf(format_string, values) // formatted output`
  - format_string determines what to print and where to insert values
  - values are zero or more values to include
```c
printf("Some ouptut: %i %o %x %u\n", i, j, k, l);
```
- % denotes a conversion or formatting character

## conversion characters
```c
i/d: integer
u: unsigned integer
o: octal integer
x: hexadecimal integer, using a-f
X: hexadecimal integer, using A-F
f or F: floating point number, six d.p. by default
e or E: floating point number in exponential format
g: floating point number in f or e format
G: floating point number in F or E format
a or A: flatoing point number in hexadecimal format 0xd.dddp+-d
c: single character
s: null-terminated character string
p: pointer
```
## escape characters
```c
\a: audible alert
\b: backspace
\f: form feed
\n: newline
\r: carriage return (enter)
\t: horizontal tab
\v: vertical tab
\\: backslash
\": double quotation mark
\': single quotation mark
\?: question mark
\nnn: octal character value nnn
\unnnn: universal character name
\Unnnnnnnn: universal character name
\xnn: hexadecimal character value nn
```

## input
- formatted input:
```c
double number = 0.0;
char word[25];
printf("Enter number: ");
scanf("%lf", &number); // read from stdin by default
printf("The number is %g\n", number);
printf("Enter word: ");
scanf("%s", word);
printf("The word is %s\n", word);
```

## input buffering
- input is buffered
- program is puasing waiting for user to type input, followed by `<return>`
- program continues and takes input from the buffer
- it won't be paused again until the buffer is empty
  - can read multiple numbers from the ipnut buffer without waiting for the user to type anything
  - program does not read directly from the keyboard, unless terminal i/o is set to raw mode

## clearing the input up to newline
```c
int c;
while ((c = getchar()) != EOF && c != '\n');
```
- `char` is integer type of size 8 bits
- `getchar` is a lib function that returns the next character from the stdin stream input buffer as an int
  - or `EOF` (-1, int) if the input stream has closed
  - `-1` is not a valid character code, hence can be used to denote no more input without confusion
- value of `c = getchar()` is the value assigned to `c`
  - if character assigned to a char converted to 8 bits
- loop boolean does all the work - see the semicolon, it is an empty statement
- `&&` evaluates the left-hand sub-expression first
  - if false, then the right is not evaluated
  - short circuit evaluation
- hence, `ch != '\n'` is only evaluated when the input is not EOF

## type char
- 8 bits/1 byte
- usually signed (can represent -1, 127 ASCII codes)
- may be unsigned in some implementations
```c
#include <stdio.h>
int main() {
  char c = 255; // implicit conversion from 'int' to 'char' changes value from 255 to -1 [-Wconstant-conversion]
  if (c > 0) {
    printf("char is unsigned.\n");
  } else {
    printf("char is signed.\n");
  }
  return 0;
}
```

## i/o redirection
- stdin, stdout and stderror can be re-directed and connected to different files
- a.out < inputFile
  - read stdin from a file
- a.out > outputFile
  - write output to a file, overwrite any existing content
- a.out >> outputFile
  - append output to a file
- a.out | more
  - send stdout through a pipe to the stdin of more
- a.out 2> outputFIle
  - redirect stderr to a file
- a.out 2>> outputFIle
  - redirect stderr to append to a file
- a.out &> outputFile
  - redirect both stdout and stderr to a file
- a.out &>> outputFile
  - append both stdout and stderr to append to a file
- a.out > file1 2> file2
  - redirect stdout, stderr to separate files