#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return (*this);
}

Intern::~Intern() {}

AForm* Intern::createShrubberyForm(const std::string& target) const {
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyForm(const std::string& target) const {
    return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialForm(const std::string& target) const {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    if (formName == "shrubbery creation") {
        std::cout << "Intern creates " << formName << std::endl;
        return createShrubberyForm(target);
    }
    else if (formName == "robotomy request") {
        std::cout << "Intern creates " << formName << std::endl;
        return createRobotomyForm(target);
    }
    else if (formName == "presidential pardon") {
        std::cout << "Intern creates " << formName << std::endl;
        return createPresidentialForm(target);
    }
    std::cout << "Intern cannot create " << formName << " form" << std::endl;
    return NULL;
} 