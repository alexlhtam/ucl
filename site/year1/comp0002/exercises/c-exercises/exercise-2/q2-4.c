# include <stdio.h>

// Write a program to display the following:
// *****
// *   *
// *   *
// *****
// You may display only one character at a time. You cannot have a statement such as:
// printf(“*****”);
// to output an entire line at once. A loop will be needed to write characters one at a time.
// Space characters should be output to display the spaces inside the shape.
// Hint: use nested loops.

int main(void) {
    for (int i = 0; i < 4; i++) {
        if (i == 0 || i == 3) {
            for (int j = 0; j < 5; j++) {
                printf("*");
            }
            printf("\n");
        } else {
            for (int j = 0; j < 5; j++) {
                if (j == 0 || j == 4) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}