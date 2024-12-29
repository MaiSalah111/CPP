#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed &object);
    Fixed &operator=(const Fixed &object);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif