#pragma once
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Contact {
private:
    char* name;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string additionalInfo;

public:
    Contact(const char* name = "", const string& homePhone = "", const string& workPhone = "",
        const string& mobilePhone = "", const string& additionalInfo = "");
    Contact(const Contact& other);
    Contact& operator=(const Contact& other);
    ~Contact();

    const char* getName() const;
    void display() const;

    void saveToFile(ofstream& outFile) const;
    void loadFromFile(ifstream& inFile);
};

#endif