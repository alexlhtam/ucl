# Arrays
- a normal variable holds one value
- an array variable holds a sequence of values in a single, contiguous block of memory
- indexing starts at 0 
## why arrays?
- allow a sequence of values of the same type to be stored using one variable
- no need to name many variables
- array can be as big as we want, within limits (but arrays are still fixed sizes)
- array contents can be iterated through using loops
- arrays are the most basic kind of data structure
## defining an array variable
```c
int m[6] = {10, 22, 6, 43, 19, 27};
double d[2] = {1.2, 3.4};
short k[3] = {12, 30, 40};
```
## variable length arrays (VLAs)
- the length of a local array defined in a function body can be given by a local variable or expression
- the sizes of VLA should be kept relatively small due to the way memory is allocated 

## array length
- C arrays do not store their lengths
- need to manually track length of array

# bounds checking
```C
int n[] = {0, 1, 2, 3, 4, 5}; // length 6
printf("%d", n[6]);
```
- this code will compile without error and runs without crashing, but will return whatever value is in the next "block" of memory
- we can also overwrite the next byte by doing `n[6] = 10`, which can be disastrous if the memory contains essential data

## array pointer
- C has pointer types
- `int *p`: variable holding a pointer (memory address)
  - adding the * changes the type to pointer from int
- arrays are accessed mostly via pointers
  - indexing gets a pointer to the memory location of an array element
  - arrays and pointers are not the same thing

## array type v pointer type
- in many circumstances, array types are 'decayed' to pointer types
- the array name is mapped to a memory address, a pointer then holds the memory address
- careful:
  - an array is the memory address of the array
  - a pointer is the memory address where the memory address of the array is stored

## `size_t`
- `size_t` is an unsigned integer "type" that can be used to represent value sizes in bytes (8 bits)
  - guaranteed to be able to hold the size of the largest array
  - cannot be a negative value
- strictly you can use size_t for byte count or array length
  - a bit confusing bytes v. number of elements
  - in practice, int is often used but remember it is a signed type
- defined in stddef.h
  - the size of a value (int, double, etc.) will depend on the processor, compiler and OS
- is size_t really a type?
  - alias for unsigned long on 64-bit computers
  - unsiged int on 32-bit machines
```C
typedef unsigned long size_t;
```
- typedef is a keyword part of the C language
- creating an alias for another type:
```C
typedef <existing type> <alias name>
```
- useful to provide simpler names for complex types
- portability across platforms

## `size_t` for loop variables
```C
for (size_t i = 0; i < 10; i++) {
    printf(%zu\n", i);
}
```
- safer in some circumstances
- avoids mixing signed and unsigned values
  - the 10 is converted to unsigned to apply '<'
- for this module using int is fine
- size_t has dual role: size in bytes, unsigned int value

## sizeof
- C operator that returns the size of a type or value in bytes when the full type is known