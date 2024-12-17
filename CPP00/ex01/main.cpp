#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        if (std::cin.eof())
            break;
            
        if (command == "EXIT")
            break;
        else if (command == "ADD") {
            Contact newContact;
            if (newContact.setContact()) {
                phoneBook.addContact(newContact);
                std::cout << "Contact added successfully!" << std::endl;
            }
        }
        else if (command == "SEARCH") {
            phoneBook.searchContact();
            std::string indexStr;
            std::cout << "Enter index to display: ";
            std::getline(std::cin, indexStr);
            try {
                int index = std::stoi(indexStr);
                phoneBook.displayContact(index);
            } catch (...) {
                std::cout << "Invalid index!" << std::endl;
            }
        }
    }
    return 0;
}