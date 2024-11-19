#include "PhoneBook.h"

void PhoneBook::addContact(const Contact& contact) {
    contacts.push_back(contact);
}

void PhoneBook::removeContact(const char* name) {
    auto it = remove_if(contacts.begin(), contacts.end(),
        [name](const Contact& contact) { return strcmp(contact.getName(), name) == 0; });
    contacts.erase(it, contacts.end());
}

void PhoneBook::findContact(const char* name) const {
    for (const auto& contact : contacts) {
        if (strcmp(contact.getName(), name) == 0) {
            contact.display();
            return;
        }
    }
    cout << "Contact not found\n";
}

void PhoneBook::displayAll() const {
    for (const auto& contact : contacts) {
        contact.display();
        cout << "-----------------\n";
    }
}

void PhoneBook::saveToFile(const string& filename) const {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Failed to open file for writing\n";
        return;
    }

    size_t count = contacts.size();
    outFile.write(reinterpret_cast<const char*>(&count), sizeof(count));
    for (const auto& contact : contacts) {
        contact.saveToFile(outFile);
    }
}

void PhoneBook::loadFromFile(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Failed to open file for reading\n";
        return;
    }

    size_t count;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(count));
    contacts.clear();
    for (size_t i = 0; i < count; ++i) {
        Contact contact;
        contact.loadFromFile(inFile);
        contacts.push_back(contact);
    }
}