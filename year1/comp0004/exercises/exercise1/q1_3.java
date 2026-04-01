/*
 * Write a program to input 10 words, storing them as strings in an ArrayList<String> (not an
 * array), and then display the words in reverse sorted order
 */

/**
 * private helper method to build array string
 * @param s scanner s
 * @return list of 10 strings
 */
private ArrayList<String> getInputStrings(Scanner s) {
    ArrayList<String> inputStrings = new ArrayList<>();

    int count = 0;
    while (count < 10) {
        inputStrings.add(s.next());
        System.out.println("read in string: " + inputStrings.getLast());
        count++;
    }

    return inputStrings;
}

/**
 * private helper method that returns sorted arrays
 * @param inputList list of inputted strings
 * @return list of 10 sorted strings in reverse sorted order
 */
private ArrayList<String> sortArrayList(ArrayList<String> inputList) {
    inputList.sort(Comparator.reverseOrder());

    return inputList;
}

/**
 * main method
 */
void main() {
    Scanner s = new Scanner(System.in);

    System.out.println("input 10 strings: ");

    ArrayList<String> inputList = getInputStrings(s);

    s.close();

    System.out.println("input strings in reverse sorted order");
    System.out.println(sortArrayList(inputList));
}