# C Strings
## characters in C
- any character on the keyboard, plus newline, tab, space, etc.
- `char c = 'a';` encoded as ASCII numbers
- by default type char is a SIGNED 1 byte value
  - -128 to +127
    - can be unsigned in some implementations
    - 0 to 255
  - ASCII encoded (7-bit) to represent max of 128 characters
- UTF-8 encoding widely used to represent many more characters
  - 1-4 byte encoding, e.g. Unicode
  - added to C via library code, built-in on more modern languages

## how long is a string in an array
- over time an array could hold a number of different words or sentences
- size:
  - `char sentence[???];`
- two options:
  - choose a maxiumu size
    - but must make sure no overflow
    - wasted space for anything that doesn't reach that cap
  - determine the length before creating the array, then create array with correct length
    - still need to make sure no overflow

## C strings
- null character '\0' ised to mark the end of the string in a char array
- `"Hello\n"` = 5 characters + newline + null `("Hello\n\0")`
- string literals always end with a null
- array must be big enough to hold the string characters AND the null
- array elements after the null are left unused if the array is longer than the string + null
- ARRAY INDEXING can be used to access the string characters
```c
char s[] = "Monday"; // array includes the null (7 bytes)
for (int n = 0; s[n] != '\0'; n++) {
    printf("%c", s[n]);
}
```
- the loop runs until null is reached

## null - '\0'
- the null character is represented by zero
  - one byte, all bits zero. The value zero
- represented as \0, the escape character
- can simplify the loop boolean expression
```c
for (int n = 0; s[n]; n++) {
    printf("%c", s[n]);
}
```

## lines of text
```c
char lines[][80] = {
    "Some text.",
    "The next line.",
    "And so it goes on and on."
};
```
- `lines[1]` gives `The next line.`
- `lines[1][2]` gives `'e'`

## C string functions
- c strings are so widely used that the standard C library provides lots of standard functions.
- `#include <string.h>`
- all rely on \0 used to mark the end of a string
  - `size_t strlen(string) - length` (number of characters excluding \0)
- a char * pointer points to a character
  - C strings are typically manipulated using pointers
  - square bracket array syntax can be used as well
```c
char *strcpy(string1, string2); 
//copy string2 into string1
// string1 array must be large enough
char *strcat(string1, string2);
// append a copy of string2 to string1
// string1 array must be large enough
char *strchr(string, character);
// returns a pointer to the first occurence
// of the character in the string
// or the value null (zero)
```

## strcmp(s1, s2): string comparisons
- `s1 > s2` returns positive int
  - e.g. "abc" > "ABC"
- `s1 == s2` returns zero
- `s1 < s2` return negative int
  - e.g. "ABC" < "abc"
- characters are compared using their integer values
  - A-Z: 65-90
  - a-z: 97-122
  - 0-9: 48-57
- strings compared character by character

## inputting a C string
```c
char name[50];
scanf("%49s", name);
```
- must specify the maximum numbers of characters that will be accepted into the array
  - allowing for the \0
- otherwise, there is a risk of overflow
  - memory not allocated to the array gets overwritten
  - serious potential security problem
- `scanf %s` reads one word at a time and stops at the first space (tab, newline)
  - not one line of text

## fgets
- an alternative to scanf:
```c
char name[30];
fgets(name, sizeof(name), stdin);
```
- `sizeof` is a C operator that returns the size of a variable in bytes
  - actually returns a value of type `size_t`
  - unsigned integer    
- reads all characters up to the end of line or until array is full
  - correctly takes into account \0
  - does read an entire line of text
- there is a function called `gets`, NEVER USE IT!!

# summary
- character arrays can hold words, strings
- C strings are terminated null (\0)
- the standard C library provides a collection of functions for working with strings
- it's all pointers underneath
- character representations get complicated