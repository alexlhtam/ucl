// write a program to determine if an integer of type long entered via the keyboard is a palindrome

#include <stdio.h>


int check_palindrome(long num) {
    if (num < 0) return 0;

    if (num == 0) return 1;

    int digits = (int)log10(num) + 1; // (int) truncates towards zero, even for -ve vals
    long left_div = (long)pow(10, digits-1); // divisor for left most digit
    long right_div = 1; // for rightmost digit 


}

int main(void) {



    return 0;
}

