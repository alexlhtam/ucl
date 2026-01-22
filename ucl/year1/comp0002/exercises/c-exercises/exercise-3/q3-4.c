// Write a program that uses a function to calculate the product of a sequence of numbers
// specified by the user. For example, if the user specifies 4 to 8, the function calculates 4*5*6*7*8.
// Any range can be used, including the use of negative numbers, and the program must correctly
// determine the values in the range.

# include <stdio.h>


long calc_seq_prod(int low, int high) {
    long prod = 1;

    for (int i = low; i <= high; i++) {
        prod *= i;
    }

    return prod;
}

int main(void) {
    int a, b;

    printf("enter your lower bound followed by your upper bound: ");
    scanf("%i %i", &a, &b);

    if (b < a) { 
        printf("larger integer was inputted first, swapping numbers\n");
        int temp = a;
        a = b;
        b = temp;
    }

    printf("your product is: %ld\n", calc_seq_prod(a, b));

    return 0;
}