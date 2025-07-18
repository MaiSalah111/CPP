#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();

    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (file.is_open()) {
        file << "       _-_\n"
             << "    /~~   ~~\\\n"
             << " /~~         ~~\\\n"
             << "{               }\n"
             << " \\  _-     -_  /\n"
             << "   ~  \\\\ //  ~\n"
             << "_- -   | | _- _\n"
             << "  _ -  | |   -_\n"
             << "      // \\\\\n";
        file.close();
    }
} 