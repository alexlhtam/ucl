// Write a program to generate 10000 random doubles between -0.9999999 and +0.9999999.
// Print out the largest, smallest and the average values.
// Do you need an array? Think very carefully about this.
// Hint: Look at the documentation for class Random and find the method nextDouble.
// Another hint: Negative values?? Class Random also has nextBoolean...
// Note: Answers to the following questions involve writing programs consisting of two or more
// methods (not including the main method).

import java.util.Random;

private double generateCustomRandom(Random r) {
    return r.nextBoolean() ? r.nextDouble() : -r.nextDouble();
}


private void processStatistics(Random r, int iterations) {
    double min = Double.MAX_VALUE;
    double max = -Double.MAX_VALUE;
    double sum = 0;

    for (int i = 0; i < iterations; i++) {
        double n = generateCustomRandom(r);

        sum += n;

        min = Math.min(min, n);
        max = Math.max(max, n);
    }

    System.out.println("min: " + min);
    System.out.println("max: " + max);
    System.out.println("mean: " + sum/iterations);
}



void main() {
    processStatistics(new Random(), 10000);
}