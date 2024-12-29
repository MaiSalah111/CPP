#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &object) {
    std::cout << "Copy constructor called" << std::endl;
    *this = object;
}

Fixed &Fixed::operator=(const Fixed &object) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &object) {
        this->_fixedPointValue = object.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}