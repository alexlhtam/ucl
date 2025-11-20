# pointers

## processes
- C program is run in a process on Unix/Windows machines
  - each process has a pid - process identifier
- process created by the OS and manages the resources needed to run programs
- OS allocates processor time to each process
  - uses all cores available
- process strictly isolated from other processes
- processes define virtual address space
  - running a C program appears to be the only program running and has its own private memory
- processes run on top of a vritual memory system controlled by the OS
  - map process virtual memory to physical memory
  - allows programs to share real memory in a transparent way
  
## program address space
- a C program has virtual address space allocated by its process
  - conceptually continuous sequence of memory
    - actually divided into segments for different types of data and code
      - large unused gaps between active segments
    - measured in bytes
- each memory location in virtual address space has an address
  - 'number' of each memory location
  - conceptually byte oriented, starting from zero
- actual format of memory address depends on processor and OS

## pointers in C (unix/windows)
- pointer is a virtual memory address
  - location in memory of a variable, data struct or function
- pointer variable holds the address of the first byte of a value somewhere else in memory
- pointer size in bits must be big enough to represent all possible memory locations
  - 32 bits: 4 gigabytes
  - 64 bits: 16 exabytes (2^64)
- pointer values are ALWAYS virtual memory addresses
  - unless:
    - c code part of OS kernel
    - running on basic hardware with no OS

## pointer based data structures
- greater freedom and efficiency to access data
- linked lists
- trees

## C pointer types
- type name + `*`:
```c
int *p; // pointer to int
char *c; // pointer to char
```
- any type can be used to specify a pointer type
- pointer to pointer
```c
int **p; // pointer to pointer to int
int ***p; // pointer to pointer to pointer to int
```
- pointer to function
```c
int(*functionPointer) (int);
```
- a variable named functionPointer that is a pointer to a function with one int parameter that returns an int
  
## address-of operator &
- returns the address of a variable
```c
int i = 10;
int *p = &i; // p points at i
// if i goes out of scope the pointer will point at the same space
// the memory can (and probably will) be used by another variable
char c = 'a';
char *p = &c; // works for all types
double f;
double *p = &f;
double **q = &p; // pointer to a pointer
```

## de-reference or indirection operator
```c
int n = 10;
int *p = &n;
int t = *p; // get the value at by the pointer, t = 10
*p = 20; // assign value to the location pointed at n = 20
```

## example
```c
int f() {
    int i1, i2;
    int *p1, *p2;
    i1 = 5;
    p1 = &i1; //p1 points at i1
    i2 = *p1 / 2 + 10; // (5/2) + 10 = 2 + 10; i2 = 12
    p2 = p1; // p2 is assigned the value of p1 which points at i1
    printf("i1 = %d, i2 = $d, *p1 = %d, *p2 = %d\n",
        i1, i2, *p1, *p2);
}
// prints i1 = 5, i2 = 12, *p1 = 5, *p2 = 5
```

### pointers and arrays
```c
int myArray[6]; // type array of int size 6
```
- the type of myArray "decays" to int *, a pointer to the first element in the array
- `int *p = myArray;` // no & needed, decays instead
  - or `int *p = &(myArray[0]);`
- the same for strings:
  - `char s[] = "Hello";`
  - `char *p = s;`

## decays
- char word[10] -- word is of type char[10]
  - c has array types
  - this is a different type to char*
- the type of word can decay to char*, which is a character pointer
  - this is a type of implicit conversion
  - when the identifier word is used in an expression or the array is passed as argument to a function, the type decays to char*
  - applies to any pointer type
- square bracket syntax can still be used with a pointer

## pointer arithmetic
```c
int *p = myArray; // myArray decayed to a pointer
*p = 20; //myArray[0] = 20;
*(p + 1) = 30; // myArray[1] = 30, or p[1] = 30
```
- adding an offset to pointer gives the nth element in the array
- indirection `*` has higher precedence4 than +
- `int n = *(p + 5);  fetch myArray[5]`

## it's all pointers
- array square bracket syntax is just 'syntatic sugar' for pointer operations using pointer arithmetic
- `a[n]` is really `*(a + n)`
- array argument to a function is also a pointer
  - array type is not known in the function body

## reminder: arrays are not copied
```c
void modify(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    *(arr + i) *= 2; // modify array elements, or could be arr[i] *= 2
  }
}
```
- the pointer to the array copied to initialise parameter variable `arr`, but the array itself is not copied
  - points to same array where function call made from
  - in general, too expensive/inefficient to copy arrays
- modifying array elements modifies the same, single array
- function has the side-effect of modifying the array passed to it
  - e.g. array sorting functions will sort the array passed to it
  - original sequence of values will be overwritten

## size of an array that is not a vla
```c
int data[] = {1, 2, 3, 4, 5}; // data is of type int[5]
int size = sizeof(data) / sizeof(data[0]);
// size of entire array in bytes divided by size of array element in bytes
```
- `sizeof` can determine the size of an array defined using an array type
  - the type has enough info to allow this at compile time
  - array itself does not store its size at run time, it's the type that is used
  - number of array elements can be calculated
- pointer to array is just a pointer to memory location and cannot be used to determine the array size
- function like `modify(int arr[], int n)` needs a second parameter to pass in array size
  - array arr can be of any size (>0), allowing modify to work with any size int array
  - size zero cannot be defined as there is nothing to point at

## size of a vla array
- local array can be a variable length array
```c
int size = <calculate some size>
int array[size] = {} // VLA, all values initialsied to zero
```
= compiler will add the instructions to temporarily store array size in bytes
- at runtime, not compile time, sizeof can be used to get the size of the array (number of bytes)
- number of elements can be calculated as `sizeof(array) / sizeof(array[0])`

## valid operators for pointer arithmetic
- size of value pointed at is taken into account by all operators
  - if an int is 4 bytes, adding one to an int* pointer increments by 4 bytes
  - `+`, `-`: add, subtract int value to get a pointer to another value
  - `-`: difference between two pointers (e.g. subtract one pointer from another)
    - adding two pointers is not allowed
  - `++`, `--`: increment, decrement to next/prev value
  - `+=`, `-=`: like add, subtract
  - `*`, `/`: INVALID, DOESN'T MAKE ANY SENSE
  - comparison operators can also be used

## pointer arithmetic example
- adding up a collection of numbers in an array
```c
int anArray[] = {4, 6, 2, -1, 6, 8, 12, -4}; // 8 values
int *p, *end, sum = 0;
end = anArray + 8; // location after last element
for (p = anArray; p < end; p++) {
  sum += *p;
}
printf("Sum is: %i\n", sum);
```
## string length
- recall C strings are character arrays with \0 (NULL) marking the end of the string
```c
int stringLength(char *string) {
  char *c = string; 
  // do not modify pointer string, use temp pointer to access each char
  while (*c) { 
  // while pointer is not null, increment c until it reaches \0
    ++c;
  }
  // subtract pointer to null from pointer to first char in string to get number of chars
  return c - string;
}
```

## string copy
- array version:
```c
void strcpy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') { // cppy from[i] to to[i], and check if null
    i++;
  }
}
```
- pointer version 1:
```c
void strcpy(char *to, char *from) {
  while (*from) { // while from pointing to a char != null, copy char
    *to++ = *from++; // copy char using assignment, then post-increment operators
  }
  *to = '\0'; // add the final nulls
}
// when *from = '\0' the loop terminates before it can be copied over to the new str
```
- pointer version 2
```c
// move assignment into loop boolean expression
void strcpy(char *to, char *from) {
  while ((*to = *from) != '\0') { 
    to++;
    from++;
  } 
}
```
- pointer version 3
```c
void strcpy(char *to, char *from) {
  while ((*to++ = *from++) != '\0');
}
// same as version 2, moves increment operators inside loop boolean expression
```

- pointer version 4
```c
void strcpy(char *to, char *from) {
  while (*to++ = *from++);
}
// as the value of an assignment expression is the value of the right hand side,
// there is no need to test for '\0' seperately

// this is how an experienced C programmer would typically write the function
```

- strcpy
  - strcpy in the gcc standard C library is unsafe
  - just copies characters
  - does not check:
    - if memory is allocated
    - destination size compatability
    - if pointers are valid
    - if strings correctly null terminated
    - if arrays overlap

## swap
```c
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
```