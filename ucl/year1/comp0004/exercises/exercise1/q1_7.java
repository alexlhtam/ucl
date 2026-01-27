/**
 * write a method: public String toBase(int n, int b) that converts n to its String representation in
 * number base b, i.e. toBase(3, 2) will return "1 1". Put the method into a one-class program that
 * allows you to input values and use the method
 */

import java.util.Scanner;

public class q1_7 {
    static Scanner s = new Scanner(System.in);

    public static String toBase(int n, int b) {
        if (n == 0) return "0";

        String result = "";
        while (n > 0) {
            int digit = n % b;

            // if (result.length() == 0) {
            //     result += digit;
            // } else {
            //     result = digit + " " + result;
            // }

            result = (result.length() == 0 ?  digit : digit + " ") + result;

            n = n / b;
        }

        return result;
    }

    public static void main(String[] args) {
        System.out.print("Enter the integer to convert: ");
        int n = s.nextInt();
        System.out.print("Enter the base: ");
        int b = s.nextInt();
        System.out.println(toBase(n, b));
    }
}