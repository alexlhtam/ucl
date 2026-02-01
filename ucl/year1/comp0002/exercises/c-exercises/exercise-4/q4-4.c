// Write a function with the signature int strend(char *s, char *t) 
// that returns true (1)
// if the string pointed to by t occurs at the end of 
// the string pointed to by s. Otherwise the function
// returns false (0).

# include <stdio.h>
# include <string.h>

int strend(char *s, char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    if (len_t > len_s) return 0;

    // point where t begins in s
    char *end_of_s = s + (len_s - len_t);

    if (strcmp(end_of_s, t) == 0) return 1;

    return 0;
}


int main(void) {
    char *s1 = "Stackoverflow";
    char *t1 = "flow";
    
    char *s2 = "Hello";
    char *t2 = "World";

    printf("Test 1 (Should be 1): %d\n", strend(s1, t1));
    printf("Test 2 (Should be 0): %d\n", strend(s1, t2));

    return 0;
}