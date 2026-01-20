// Repeat Q1.5 but store the double values 
// in two instance variables rather than using
// parameters.
// Hint: you will need another instance method
// to call the input method to get values to
// store in each instance variable and to call 
// the other methods. This instance method should be public, 
// the others private. The input method 
// should be unchanged.

import java.util.Scanner;

/**
 * q1_6 class
 */
public class q1_6 {
    /*
     * class level scanner
     */
    Scanner s = new Scanner(System.in);

    /*
     * instant variable 1
     */
    double a;

    /*
     * instant variable 2
     */
    double b;

    /**
     * prompt the user for input, assign values to instance variables
     */
    public void getInputs() {
        System.out.print("A: ");
        this.a = getDoubleInput();
        System.out.print("B: ");
        this.b = getDoubleInput();
    }

    /**
     * get a single input from user of type double
     * @return double input from user
     */
    private double getDoubleInput() {
        System.out.println("enter a double: ");

        while (!this.s.hasNextDouble()) {
            String trash = this.s.next();
            System.out.println("Error: " + trash + " is not a number, try again:");
        }

        return this.s.nextDouble();
    }

    /**
     * calculates the sqrt of the sum of two doubles
     * @return sqrt of this.a + this.b
     */
    private double squareRoot() {
        return Math.sqrt(this.a + this.b);
    }

    /**
     * main method
     * @param args
     */
    public static void main(String[] args) {
        q1_6 myProgram = new q1_6();
        myProgram.getInputs();

        double result = myProgram.squareRoot();
        System.out.println("result: " + result);
    }
}