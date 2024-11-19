#pragma once
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"
#include <vector>

using namespace std;

class PhoneBook {
private:
    vector<Contact> contacts;

public:
    void addContact(const Contact& contact);
    void removeContact(const char* name);
    void findContact(const char* name) const;
    void displayAll() const;

    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif