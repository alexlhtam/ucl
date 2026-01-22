// Write a program to determine if an integer of type long entered via the keyboard is a
// palindrome (i.e., represents the same value when the digits are reversed, for example 123454321).

# include <stdio.h>

int check_pdrm(long num) {
    long reversed = 0;
    long original = num;

    while (num > 0) {
        reversed = (reversed * 10) + num % 10;
        num = num / 10;
    }

    return reversed == original;
}

int main(void) {
    long input;

    printf("Enter your long integer: ");
    scanf("%ld", &input);

    printf("%ld %s\n", input, check_pdrm(input) ? "is a palindrome": "is not a palindrome");

    return 0;
}