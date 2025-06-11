#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat pr("m", 25);
        
        // Create forms using base class pointer
        AForm* shrub = new ShrubberyCreationForm("mai");
        AForm* robot = new RobotomyRequestForm("mai");
        AForm* pres = new PresidentialPardonForm("mai");

        // First sign the forms using beSigned
        // std::cout << "\n=== Signing Forms ===" << std::endl;
        shrub->beSigned(pr);
        robot->beSigned(pr);
        pres->beSigned(pr);

        // Then execute them
        // std::cout << "\n=== Executing Forms ===" << std::endl;
        pr.executeForm(*shrub);
        pr.executeForm(*robot);
        pr.executeForm(*pres);

        // Clean up memory
        delete shrub;
        delete robot;
        delete pres;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}