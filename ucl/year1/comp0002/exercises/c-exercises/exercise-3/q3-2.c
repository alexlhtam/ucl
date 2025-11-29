// write a program that defines and calls a function to raise an integer to another positive integer
// provide a version that uses a loop and another that uses recursion

# include <stdio.h>


int iterative_power(int base, int power) {
    int x = base;
    for (int i = 0; i < power; i++) {
        x *= base;
    }

    return x;
}

int recursive_power(int base, int power) {
    if (power == 0) {
        return 1;
    } else {
        return base * recursive_power(base, power - 1);
    }
}

int main(void) {

    printf("3^3 iteratively: %d\n", iterative_power(3, 3));

    printf("2^4 recursively: %d\n", recursive_power(2, 4));

    return 0;
}
