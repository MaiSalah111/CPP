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

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &object) {
    if (this != &object) {
        _fixedPointValue = object._fixedPointValue;
    }
    return *this;
}

bool Fixed::operator>(const Fixed &object) const {
    return _fixedPointValue > object._fixedPointValue;
}

bool Fixed::operator<(const Fixed &object) const {
    return _fixedPointValue < object._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &object) const {
    return _fixedPointValue >= object._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &object) const {
    return _fixedPointValue <= object._fixedPointValue;
}

bool Fixed::operator==(const Fixed &object) const {
    return _fixedPointValue == object._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &object) const {
    return _fixedPointValue != object._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &object) const {
    Fixed result;
    result._fixedPointValue = _fixedPointValue + object._fixedPointValue;
    return result;
}

Fixed Fixed::operator-(const Fixed &object) const {
    Fixed result;
    result._fixedPointValue = _fixedPointValue - object._fixedPointValue;
    return result;
}

Fixed Fixed::operator*(const Fixed &object) const {
    Fixed result;
    result._fixedPointValue = (_fixedPointValue * object._fixedPointValue) >> _fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed &object) const {
    Fixed result;
    result._fixedPointValue = (_fixedPointValue << _fractionalBits) / object._fixedPointValue;
    return result;
}

Fixed &Fixed::operator++() {
    _fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--() {
    _fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

int Fixed::getRawBits(void) const {
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}