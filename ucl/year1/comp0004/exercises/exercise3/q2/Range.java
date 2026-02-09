package year1.comp0004.exercises.exercise3.q2;

import java.util.ArrayList;

/**
 * A Range represents a sequence, or range, of integers, for example 1 to 10, 3 to 15, or -6 to 3.
   Write a class Range in Java with the following methods:
 */
public class Range {

    private int lower;
    private int upper;

    public Range(int lower, int upper) {
        this.lower = lower;
        this.upper = upper;
    }

    public int getLower() {
        return this.lower;
    }

    public int getUpper() {
        return this.upper;
    }

    public boolean contains(int n) {
        return (this.upper >= n && this.lower <= n);
    }

    public ArrayList<Integer> getValues() {
        ArrayList<Integer> returnArray = new ArrayList<>();
        
        for (int i = this.lower; i < upper + 1; i++) {
            returnArray.add(i);
        }

        return returnArray;
    }
}