// Write a program that inputs a sequence of Strings until the word stop is entered
// Hint: You compare strings using compareTo, as outlined in the preceding notes.

/**
 * main method
 */
void main() {
    Scanner s = new Scanner(System.in);

    System.out.println("enter text, or stop to exit");

    while (s.hasNext()) {
        String currentString = s.next();

        if (currentString.compareTo("stop") == 0) {
            break;
        } 

        System.out.println("read: " + currentString);
    }

    s.close();
    System.out.println("program exited");
}

