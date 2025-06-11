#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

void printTestHeader(const std::string& testName) {
    std::cout << "\n=== " << testName << " ===" << std::endl;
}

void printBureaucratInfo(const Bureaucrat& bureaucrat) {
    std::cout << "Bureaucrat: " << bureaucrat << std::endl;
}

void printFormInfo(const AForm* form) {
    if (form) {
        std::cout << "Form: " << *form << std::endl;
    } else {
        std::cout << "Form: NULL" << std::endl;
    }
}

int main() {
    try {
        AForm* robot;
        AForm* president;
        AForm* shrub;
        Intern someRandomIntern;
        Bureaucrat a("mai", 3);

        president = someRandomIntern.makeForm("presidential pardon", "a");
        robot = someRandomIntern.makeForm("robotomy request", "b");
        shrub = someRandomIntern.makeForm("shrubbery creation", "c");

        // Sign the forms
        president->beSigned(a);
        robot->beSigned(a);
        shrub->beSigned(a);

        // Execute using Bureaucrat's executeForm
        a.executeForm(*robot);
        a.executeForm(*president);
        a.executeForm(*shrub);

        delete robot;
        delete president;
        delete shrub;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
} 