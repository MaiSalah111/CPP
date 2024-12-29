#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &object);
    ~Fixed();

    Fixed &operator=(const Fixed &object);

    float toFloat() const;
    int toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif