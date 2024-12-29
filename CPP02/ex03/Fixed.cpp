#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int value) {
    _fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &object) {
    *this = object;
}

Fixed &Fixed::operator=(const Fixed &object) {
    if (this != &object) {
        _fixedPointValue = object.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

float Fixed::toFloat() const {
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _fixedPointValue >> _fractionalBits;
}