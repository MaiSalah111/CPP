#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : currentSize(0), oldestIndex(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact& contact) {
    if (!contact.isValidContact()) {
        std::cout << "Cannot add invalid contact!" << std::endl;
        return;
    }
    
    contacts[oldestIndex] = contact;
    if (currentSize < 8)
        currentSize++;
    oldestIndex = (oldestIndex + 1) % 8;
}

void PhoneBook::searchContact() const {
    if (currentSize == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|     Index|First Name| Last Name| Nickname |" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    
    for (int i = 0; i < currentSize; i++) {
        contacts[i].displayContactSummary(i);
    }
    std::cout << "|-------------------------------------------|" << std::endl;
}

void PhoneBook::displayContact(int index) const {
    if (index < 0 || index >= currentSize) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    contacts[index].displayFullDetails();
}