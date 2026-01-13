# include <stdio.h>

/**
 * Write a program using a while loop to display the thirteen times table, like this:
 * 1 * 13 = 13
 * 2 * 13 = 26
 * 3 * 13 = 39
 * and so on.
 */

int main(void) {

    for (int i = 1; i <= 10; i++) {
        printf("%d * 13 = %d\n", i, i * 13);
    }

    return 0;
} 