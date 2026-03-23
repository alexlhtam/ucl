package year1.comp0004.exercises.exercise3.q1;

public class AddressBookExample {
    public static void main(String[] args) {
        AddressBook aBook = new AddressBook();
        AddressBookEntry entry1 = new AddressBookEntry("Nicholas Alexander Hunt", "670318", "nhunt@gmail.com");
        AddressBookEntry entry2 = new AddressBookEntry("Joseph Louis Atkinson", "69420", "jatkinson@hotmail.com");

        aBook.addEntry(entry1);
        aBook.addEntry(entry2);

        System.out.println("Searching address book for Nick's entry: ");
        System.out.println(aBook.searchEntryName("Nicholas Alexander Hunt"));

    }
}