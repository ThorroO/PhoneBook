#include "PhoneBook.h"

int main() {
    PhoneBook phoneBook;

    phoneBook.addContact(Contact("John Doe", "123-456", "789-012", "345-678", "Friend from work"));
    phoneBook.addContact(Contact("Jane Smith", "987-654", "321-098", "654-321", "Neighbor"));

    cout << "All contacts:\n";
    phoneBook.displayAll();

    cout << "Searching for 'John Doe':\n";
    phoneBook.findContact("John Doe");

    phoneBook.removeContact("Jane Smith");

    cout << "All contacts after removal:\n";
    phoneBook.displayAll();

    phoneBook.saveToFile("contacts.dat");
    phoneBook.loadFromFile("contacts.dat");

    cout << "All contacts after reload:\n";
    phoneBook.displayAll();

    return 0;
}