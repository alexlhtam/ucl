package year1.comp0004.exercises.exercise3;

import java.util.ArrayList;

/**
 *  Next write a class AddressBook, that uses a private ArrayList<AddressBookEntry>
    instance variable to store entries in an address book. The class should include methods to add,
    remove and search for entries. Note again, this class should not do any input or output.
 */
public class AddressBook {
    private ArrayList<AddressBookEntry> addressBook;

    public AddressBook() {
        this.addressBook = new ArrayList<AddressBookEntry>();
    }

    public void addEntry(AddressBookEntry a) {
        this.addressBook.add(a);
    }

    public AddressBookEntry searchEntryName(String name) {
        for (AddressBookEntry a : this.addressBook) {
            if (a.getName().equals(name)) {
                return a;
            }
        }

        // no matching entry found
        return null;
    }

    public boolean removeEntry(String name) {
        AddressBookEntry toRemove = searchEntryName(name);
        if (toRemove != null) {
            this.addressBook.remove(toRemove);
            return true;
        } else {
            return false;
        }
    }
}