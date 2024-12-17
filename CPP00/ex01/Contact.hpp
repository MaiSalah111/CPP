#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    bool isValid;

public:
    Contact();
    ~Contact();
    
    // Individual setters
    bool setFirstName(const std::string& name);
    bool setLastName(const std::string& name);
    bool setNickname(const std::string& nick);
    bool setPhoneNumber(const std::string& number);
    bool setDarkestSecret(const std::string& secret);
    
    // Combined setter with validation
    bool setContact();
    
    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
    bool isValidContact() const;

    // Display methods
    void displayContactSummary(int index) const;
    void displayFullDetails() const;
};

#endif