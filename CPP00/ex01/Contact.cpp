#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() : isValid(false) {}
Contact::~Contact() {}

bool Contact::setFirstName(const std::string& name) {
    if (name.empty()) {
        std::cout << "First name cannot be empty." << std::endl;
        return false;
    }
    firstName = name;
    return true;
}

bool Contact::setLastName(const std::string& name) {
    if (name.empty()) {
        std::cout << "Last name cannot be empty." << std::endl;
        return false;
    }
    lastName = name;
    return true;
}

bool Contact::setNickname(const std::string& nick) {
    if (nick.empty()) {
        std::cout << "Nickname cannot be empty." << std::endl;
        return false;
    }
    nickname = nick;
    return true;
}

bool Contact::setPhoneNumber(const std::string& number) {
    if (number.empty()) {
        std::cout << "Phone number cannot be empty." << std::endl;
        return false;
    }
    phoneNumber = number;
    return true;
}

bool Contact::setDarkestSecret(const std::string& secret) {
    if (secret.empty()) {
        std::cout << "Darkest secret cannot be empty." << std::endl;
        return false;
    }
    darkestSecret = secret;
    return true;
}

bool Contact::setContact() {
    std::string input;
    
    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    if (!setFirstName(input)) return false;
    
    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    if (!setLastName(input)) return false;
    
    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    if (!setNickname(input)) return false;
    
    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    if (!setPhoneNumber(input)) return false;
    
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    if (!setDarkestSecret(input)) return false;
    
    isValid = true;
    return true;
}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }
bool Contact::isValidContact() const { return isValid; }

void Contact::displayContactSummary(int index) const {
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName);
    std::cout << "|" << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName);
    std::cout << "|" << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname);
    std::cout << "|" << std::endl;
}

void Contact::displayFullDetails() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}