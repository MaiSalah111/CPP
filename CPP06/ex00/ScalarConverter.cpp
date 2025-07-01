#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <cctype>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter&){}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
    return (*this);
}
ScalarConverter::~ScalarConverter(){}

static bool isCharLiteral(const std::string& s)
{
    return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

static bool isIntLiteral(const std::string& s)
{
    char* end = NULL;
    errno = 0;
    long val = std::strtol(s.c_str(), &end, 10);
    (void) val;
    return (*end == '\0' && errno != ERANGE);
}

static bool isFloatLiteral(const std::string& s)
{
    if (s == "-inff" || s == "+inff" || s == "nanf")
        return (true);
    size_t len = s.length();
    if (len < 2 || s[len - 1] != 'f')
        return (false);
    char* end;
    errno = 0;
    std::strtof(s.c_str(), &end);
    return ((end == s.c_str() + len - 1) && errno != ERANGE);
}

static bool isDoubleLiteral(const std::string& s)
{
    if (s == "-inf" || s == "+inf" || s == "nan")
        return (true);
    char* end;
    errno = 0;
    std::strtod(s.c_str(), &end);
    return (*end == '\0' && errno != ERANGE);
}

static bool isDisplayable(char c)
{
    return (std::isprint(static_cast<unsigned char>(c)));
}

void ScalarConverter::convert(const std::string& literal)
{
    // Detect type
    bool isChar = isCharLiteral(literal);
    bool isInt = isIntLiteral(literal);
    bool isFloat = isFloatLiteral(literal);
    bool isDouble = isDoubleLiteral(literal);

    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;

    bool impossibleChar = false, impossibleInt = false;

    if (isChar)
    {
        c = literal[1];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (isInt)
    {
        long l = std::strtol(literal.c_str(), NULL, 10);
        if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
            impossibleInt = true;
        else
            i = static_cast<int>(l);
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    else if (isFloat)
    {
        if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        {
            if (literal == "-inff")
                f = -std::numeric_limits<float>::infinity();
            if (literal == "+inff")
                f = std::numeric_limits<float>::infinity();
            if (literal == "nanf")
                f = std::numeric_limits<float>::quiet_NaN();
        }
        else
        {
            f = std::strtof(literal.c_str(), NULL);
        }
        d = static_cast<double>(f);
        i = static_cast<int>(f);
        c = static_cast<char>(i);
        if (std::isnan(f) || std::isinf(f) || f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min())
            impossibleChar = true;
        if (std::isnan(f) || std::isinf(f) || f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
            impossibleInt = true;
    }
    else if (isDouble)
    {
        if (literal == "-inf" || literal == "+inf" || literal == "nan")
        {
            if (literal == "-inf")
                d = -std::numeric_limits<double>::infinity();
            if (literal == "+inf")
                d = std::numeric_limits<double>::infinity();
            if (literal == "nan")
                d = std::numeric_limits<double>::quiet_NaN();
        }
        else
        {
            d = std::strtod(literal.c_str(), NULL);
        }
        f = static_cast<float>(d);
        i = static_cast<int>(d);
        c = static_cast<char>(i);
        if (std::isnan(d) || std::isinf(d) || d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
            impossibleChar = true;
        if (std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            impossibleInt = true;
    }
    else
    {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
        return;
    }

    // char
    std::cout << "char: ";
    if (isChar)
        std::cout << "'" << c << "'" << std::endl;
    else if (impossibleChar || std::isnan(d) || std::isinf(d))
        std::cout << "impossible" << std::endl;
    else if (!isDisplayable(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;

    // int
    std::cout << "int: ";
    if (impossibleInt || std::isnan(d) || std::isinf(d))
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;

    // float
    std::cout << "float: ";
    if (std::isnan(f))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(f))
        std::cout << (f < 0 ? "-inff" : "+inff") << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    }

    // double
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan" << std::endl;
    else if (std::isinf(d))
        std::cout << (d < 0 ? "-inf" : "+inf") << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision(1) << d << std::endl;
    }
} 