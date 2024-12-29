#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &object);
    ~Fixed();

    Fixed &operator=(const Fixed &object);

    bool operator>(const Fixed &object) const;
    bool operator<(const Fixed &object) const;
    bool operator>=(const Fixed &object) const;
    bool operator<=(const Fixed &object) const;
    bool operator==(const Fixed &object) const;
    bool operator!=(const Fixed &object) const;

    Fixed operator+(const Fixed &object) const;
    Fixed operator-(const Fixed &object) const;
    Fixed operator*(const Fixed &object) const;
    Fixed operator/(const Fixed &object) const;

    Fixed &operator++();       // Prefix increment
    Fixed operator++(int);     // Postfix increment
    Fixed &operator--();       // Prefix decrement
    Fixed operator--(int);     // Postfix decrement

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif