#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int     currentSize;
    int     oldestIndex;

public:
    PhoneBook();
    ~PhoneBook();
    
    void addContact(const Contact& contact);
    void searchContact() const;
    void displayContact(int index) const;
};

#endif