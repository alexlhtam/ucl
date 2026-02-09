package year1.comp0004.exercises.exercise3;

/**
 * Write a class AddressBookEntry to represent an entry in an address book. An object of
    the class should store the name, phone number and email address for one person.
    The class should have a constructor to initialise a new object to represent a specific person, and
    getter methods to access each piece of information:
 */

public class AddressBookEntry {
    private String name;
    private String phone;
    private String email;

    public AddressBookEntry(String name, String phone, String email) {
        this.name = name;
        this.phone = phone;
        this.email = email;                   
    }

    public String getName() {
        return this.name;
    }

    public String getPhone() {
        return this.phone;
    }

    public String getEmail() {
        return this.email;
    }
}
