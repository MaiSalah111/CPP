#include "Bureaucrat.hpp"

int main()
{
	try {
    	Bureaucrat *mai = new Bureaucrat("mai", 2);
		std::cout << *mai << std::endl;
		mai->incrementGrade();
		std::cout << *mai<< std::endl;
		mai->incrementGrade();
		std::cout << *mai<< std::endl;
		mai->decrementGrade();
		std::cout << *mai<< std::endl;
		delete mai;
	} catch (std::exception& a) {
		std::cout << a.what();
	}
}