/*
 * Write a program to input 10 doubles (values of type double) and store them in an array. Then
 * compute and display the average of the values input. Try entering negative as well as positive
 * numbers. Consider writing one method to do the input and another to compute the average.
 */

/**
 * helper function getting input of a list of 10 doubles, skipping bad input
 * @param s scanner s
 * @return list of 10 doubles
 */
private double[] getInputArray(Scanner s) {
    double[] doubles = new double[10];
    int count = 0;

    while (count < 10) {
        if (!s.hasNextDouble()) {
            System.out.println("skipping bad input");
            s.next();
        } else {
            doubles[count] = s.nextDouble();
            System.out.println("read in: " + doubles[count]);
            count++;
        }
    };
    
    return doubles;
}

/**
 * helper method calculating the mean of any list of doubles
 * @param inputArray
 * @return
 */
private double getAverage(double[] inputArray) {
    double sum = 0.0;
    
    for (double d : inputArray) {
        sum += d;
    }

    return sum / inputArray.length;
}

/**
 * main method
 */
void main() {
    Scanner s = new Scanner(System.in);

    System.out.println("input 10 numbers: ");

    double[] inputArray = getInputArray(s);

    s.close();

    System.out.println(getAverage(inputArray));
}