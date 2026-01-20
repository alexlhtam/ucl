// Write a one-class program that has the following methods:
// • a method that inputs and returns a double value,
// • a method that takes two double parameters, adds them together and returns the square root of
// the result,
// • a main method to create an object and call the other two methods, displaying the result of calling
// the second method.

import java.util.Scanner;

/**
 * q1_5 class
 */
public class q1_5 {
    /**
     * class level scanner
     */
    Scanner s = new Scanner(System.in);

    /**
     * get a single input from user of type double
     * @return double input from user
     */
    public double getDoubleInput() {
        System.out.println("Enter a double: ");

        while (!this.s.hasNextDouble()) {
            String trash = this.s.next();
            System.out.println("Error: " + trash + " is not a number, try again: ");
        }

        return this.s.nextDouble();
    }

    /**
     * calculates the sqrt of the sum of two doubles
     * @param x double 1
     * @param y double 2
     * @return sqrt of x + y
     */
    public double squareRoot(double x, double y) {
        return Math.sqrt(x + y);
    }

    /**
     * main method
     * @param args
     */
    public static void main(String[] args) {
        q1_5 myProgram = new q1_5();
        double a = myProgram.getDoubleInput();
        double b = myProgram.getDoubleInput();

        double result = myProgram.squareRoot(a, b);

        System.out.println("result: " + result);
    }
}