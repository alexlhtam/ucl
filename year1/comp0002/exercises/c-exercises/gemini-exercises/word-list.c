// Exercise 3: Create a list of 3 words on the heap.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** create_word_list(void) {
    // We are hard-coding 3 rows/words for simplicity.
    const int NUM_WORDS = 3;
    
    // 1. Allocate the backbone (The list of pointers)
    //    char **list = malloc(NUM_WORDS * sizeof( ??? )); 
    char **list = malloc(NUM_WORDS * sizeof(char*));
    //    (Remember: The backbone holds pointers, so what's the size?)

    // 2. Error Check (if list == NULL)
    if (list == NULL) return NULL;

    // 3. Allocate and fill Row 0 (for "Hello")
    //    a. Allocate space for the string (strlen("Hello") + 1)
    //    b. Save that address into list[0]
    //    c. Copy the word "Hello" into the new space (strcpy)
    const char *word_0 = "Hello";
    int len_0 = strlen(word_0);
    list[0] = malloc(len_0 + 1);
    if (list[0] == NULL)  {
        free(list);
        return NULL;
    }
    strcpy(list[0], word_0);

    // 4. Allocate and fill Row 1 (for "C")
    const char *word_1 = "C";
    int len_1 = strlen(word_1);
    list[1] = malloc(len_1 + 1);
    if (list[1] == NULL) {
        free(list[0]);
        free(list);
        return NULL;
    }
    strcpy(list[1], word_1);
    
    // 5. Allocate and fill Row 2 (for "Programming")
    const char *word_2 = "Programming";
    int len_2 = strlen(word_2);
    list[2] = malloc(len_2 + 1);
    if (list[2] == NULL) {
        free(list[1]);
        free(list[0]);
        free(list);
        return NULL;
    }
    strcpy(list[2], word_2);

    return list;
}

void free_word_list(char** list, int count) {
    // Implement the free logic (reverse order of creation)
    // 1. Loop and free each individual string (list[i])
    for (int i = 0; i < count; i++) {
        free(list[i]);
    }
    // 2. Free the backbone (list)
    free(list);
}

int main(void) {
    char** myWords = create_word_list();

    if (myWords) {
        // Print them
        for (int i = 0; i < 3; i++) {
            printf("%s\n", myWords[i]);
        }
        // Free the memory
        free_word_list(myWords, 3);
    }
    return 0;
}