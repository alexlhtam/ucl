# include <stdio.h>
# include <stdlib.h>

// Write a program to display the following, you may display only one character at a time:
// ***** 4 - 4
//  ***** 4 - 3
//   ***** 4 - 2
//    ***** 4 - 1
//     ***** 4 - 0
//    ***** 4 - 1
//   *****
//  *****
// *****

int main(void) {
    for (int i = -4; i <= 4; i++) {
        for (int j = 0; j < 4 - abs(i); j++) {
            printf(" ");
        }
        printf("*****\n");
    }
    return 0;
}