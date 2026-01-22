// Write a program that defines and calls a function to raise an integer to a positive integer power (e.g., x^y). 
// Provide a version of the function that uses a loop and another that uses recursion.

# include <stdio.h>

int r_power(int b, int exp) {
    if (exp == 0) return 1;

    return b * r_power(b, exp - 1);
}

int i_power(int b, int exp) {
    int res = 1;
    for (int i = 0; i < exp; i++) {
        res *= b;
    }

    return res;
}


int main(void) {
    int base, exponent;

    printf("Enter base followed by the exponent (ints): ");
    scanf("%i %i", &base, &exponent);

    printf("recursive call of %i ^ %i = %i\n", base, exponent, r_power(base, exponent));
    printf("iterative call of %i ^ %i = %i\n", base, exponent, i_power(base, exponent));

    return 0;
}