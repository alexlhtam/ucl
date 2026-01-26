// Exercise 2: Return a new array containing only even numbers.
// The function will write the size of the new array into the memory pointed to by 'out_len'.

#include <stdio.h>
#include <stdlib.h>

int* get_evens(int* nums, int len, int* out_len) {
    int count = 0; // The counter for even numbers

    // 1. PASS 1: COUNT the even numbers
    // Loop through 'nums' from 0 up to 'len'
    // Inside the loop: check if a number is even (num % 2 == 0) and increment 'count'.
    for (int i = 0; i < len; i++) {
        if (nums[i] % 2 == 0) {
            count++;
        }
    }

    // 2. PASS 1.5: Report the length back to main
    *out_len = count;

   // Check for the edge case where no evens were found
    if (count == 0) return NULL; // No array to return

    // 3. PASS 2: Malloc and Build
    int *evens = malloc(count * sizeof(int));

    // Check for malloc failure
    if (evens == NULL) return NULL;

    int j = 0; // Counter for the NEW array (evens)

    // Loop through the ORIGINAL array again
    for (int i = 0; i < len; i++) {
        if (nums[i] % 2 == 0) {
            // Copy the even number into the next available slot 'j'
            evens[j] = nums[i]; 
            
            // Move the new array counter forward
            j++; 
        }
    }
        
    // 4. Return the new array
    return evens;
}