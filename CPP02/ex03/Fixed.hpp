#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &object);
    Fixed &operator=(const Fixed &object);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;
};

#endif