#include "Contact.h"

Contact::Contact(const char* name, const string& homePhone, const string& workPhone,
    const string& mobilePhone, const string& additionalInfo)
    : homePhone(homePhone), workPhone(workPhone), mobilePhone(mobilePhone), additionalInfo(additionalInfo) {
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
}

Contact::Contact(const Contact& other) : homePhone(other.homePhone), workPhone(other.workPhone),
mobilePhone(other.mobilePhone), additionalInfo(other.additionalInfo) {
    name = new char[strlen(other.name) + 1];
    strcpy_s(name, strlen(other.name) + 1, other.name);
}

Contact& Contact::operator=(const Contact& other) {
    if (this != &other) {
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy_s(name, strlen(other.name) + 1, other.name);

        homePhone = other.homePhone;
        workPhone = other.workPhone;
        mobilePhone = other.mobilePhone;
        additionalInfo = other.additionalInfo;
    }
    return *this;
}

Contact::~Contact() {
    delete[] name;
}

const char* Contact::getName() const {
    return name;
}

void Contact::display() const {
    cout << "Name: " << name << "\n"
        << "Home Phone: " << homePhone << "\n"
        << "Work Phone: " << workPhone << "\n"
        << "Mobile Phone: " << mobilePhone << "\n"
        << "Additional Info: " << additionalInfo << "\n";
}

void Contact::saveToFile(std::ofstream& outFile) const {
    size_t nameLength = strlen(name);
    outFile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
    outFile.write(name, nameLength);

    size_t homeLength = homePhone.size();
    outFile.write(reinterpret_cast<const char*>(&homeLength), sizeof(homeLength));
    outFile.write(homePhone.data(), homeLength);

    size_t workLength = workPhone.size();
    outFile.write(reinterpret_cast<const char*>(&workLength), sizeof(workLength));
    outFile.write(workPhone.data(), workLength);

    size_t mobileLength = mobilePhone.size();
    outFile.write(reinterpret_cast<const char*>(&mobileLength), sizeof(mobileLength));
    outFile.write(mobilePhone.data(), mobileLength);

    size_t additionalLength = additionalInfo.size();
    outFile.write(reinterpret_cast<const char*>(&additionalLength), sizeof(additionalLength));
    outFile.write(additionalInfo.data(), additionalLength);
}

void Contact::loadFromFile(std::ifstream& inFile) {
    delete[] name;

    size_t nameLength;
    inFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
    name = new char[nameLength + 1];
    inFile.read(name, nameLength);
    name[nameLength] = '\0';

    size_t homeLength;
    inFile.read(reinterpret_cast<char*>(&homeLength), sizeof(homeLength));
    homePhone.resize(homeLength);
    inFile.read(&homePhone[0], homeLength);

    size_t workLength;
    inFile.read(reinterpret_cast<char*>(&workLength), sizeof(workLength));
    workPhone.resize(workLength);
    inFile.read(&workPhone[0], workLength);

    size_t mobileLength;
    inFile.read(reinterpret_cast<char*>(&mobileLength), sizeof(mobileLength));
    mobilePhone.resize(mobileLength);
    inFile.read(&mobilePhone[0], mobileLength);

    size_t additionalLength;
    inFile.read(reinterpret_cast<char*>(&additionalLength), sizeof(additionalLength));
    additionalInfo.resize(additionalLength);
    inFile.read(&additionalInfo[0], additionalLength);
}