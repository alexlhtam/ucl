# include <stdio.h>

// Write a program to display the following, you may display only one character at a time:
//  ******
//  *****
//  ****
//  ***
//  **
//  *

int main(void) {
    
    for (int i = 6; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}