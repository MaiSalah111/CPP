#include "Form.hpp"

Form::Form() : 
    _name("Default Form"), 
    _isSigned(false), 
    _gradeRequiredToSign(150), 
    _gradeRequiredToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) :
    _name(name),
    _isSigned(false),
    _gradeRequiredToSign(gradeToSign),
    _gradeRequiredToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) :
    _name(other._name),
    _isSigned(other._isSigned),
    _gradeRequiredToSign(other._gradeRequiredToSign),
    _gradeRequiredToExecute(other._gradeRequiredToExecute) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return (*this);
}

Form::~Form() {}

const std::string& Form::getName() const { return (_name); }
bool Form::getIsSigned() const { return (_isSigned); }
int Form::getGradeRequiredToSign() const { return (_gradeRequiredToSign); }
int Form::getGradeRequiredToExecute() const { return (_gradeRequiredToExecute); }

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeRequiredToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() 
       << ", sign grade: " << form.getGradeRequiredToSign()
       << ", exec grade: " << form.getGradeRequiredToExecute()
       << ", signed: " << (form.getIsSigned() ? "yes" : "no");
    return (os);
} 