#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib> // for strtol

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
            
            char* endPtr;
            int index = std::strtol(indexStr.c_str(), &endPtr, 10);
            if (*endPtr != '\0' || endPtr == indexStr.c_str() || index < 0) {
                std::cout << "Invalid index!" << std::endl;
            } else {
                phoneBook.displayContact(index);
            }
        }
    }
    return 0;
}