// Write a version of the string copy function that takes a single string argument and creates a
// new copy in dynamic (heap) memory using malloc. 

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char* stringCopy (char *s) {
    int size = strlen(s) + 1;

    char *newString = malloc(size);

    if (newString == NULL) return NULL;

    // strcpy(target, source);
    strcpy(newString, s);

    return newString;
}

int main(void) {
    char *myStr = "Hello World";

    char *copy = stringCopy(myStr);

    printf("Original: %s\n", myStr);
    printf("Copy:     %s\n", copy);
    
    free(copy);

    return 0;
}