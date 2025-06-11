#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat mai("mai", 60);
        Form form("Tax Form", 50, 50);
        
        std::cout << mai << std::endl;
        std::cout << form << std::endl;
        
        mai.signForm(form);
        std::cout << form << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}