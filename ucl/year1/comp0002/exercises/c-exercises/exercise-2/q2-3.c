# include <stdio.h>

/**
 *  Repeat Q2.1 using do loop.
 */

int main(void) {
    int i = 0;

    do {

        printf("%d * 13 = %d", i, i * 13);
        i++;

    } while (i <= 10);

}