# include <stdio.h>
# include <stdlib.h>

// Write a program to display the following:
// ******** -3, 0-7
// *      * -2, 0, 7
// * #### * -1, 0, 2-5, 7
// * #  # * 0, 0, 2, 5, 7
// * #### * 1, 0, 2-5, 7
// *      * 2, 0, 7
// ******** 3, 0-7
// You may print only one character at a time.
// Hint: Think about the if statement.

int main(void) {

    for (int i = -3; i < 4; i++) {
        printf("*");
        switch (abs(i)) {
            case 3: 
                for (int j = 1; j < 7; j++) {
                    printf("*");
                }
                break;
            case 2:
                for (int j = 1; j < 7; j++) {
                    printf(" ");
                }
                break;
            case 1:
                for (int j = 1; j < 7; j++) {
                    if (j > 1 && j < 6) {
                        printf("#");
                    } else {
                        printf(" ");
                    }
                }
                break;
            case 0:
                for (int j = 1; j < 7; j++) {
                    if (j == 2 || j == 5) {
                        printf("#");
                    } else {
                        printf(" ");
                    }
                }
                break;                
        }
        printf("*\n");
    }


    return 0;
}