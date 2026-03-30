// Exercise 1: Concatenate two strings into a new heap-allocated string.
// Example: join("Hot", "Dog") -> returns pointer to "HotDog"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* join(char* s1, char* s2) {
    // 1. Calculate length of s1
    int len_s1 = strlen(s1);
    // 2. Calculate length of s2
    int len_s2 = strlen(s2);
    // 3. Malloc enough space for s1 + s2 + null terminator
    char* new_str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
    if (new_str == NULL) return NULL;
    // 4. Copy s1 into the new space
    strcpy(new_str, s1);
    // 5. Append (strcat) s2 onto the end
    strcat(new_str, s2);
    // 6. Return the pointer
    return new_str;
}

int main(void) {
    char *part1 = "Super";
    char *part2 = "man";
    
    char *result = join(part1, part2);
    
    printf("Result: %s\n", result); // Should print "Superman"
    
    free(result);
    return 0;
}