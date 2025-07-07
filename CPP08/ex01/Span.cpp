#include "Span.hpp"
#include <algorithm>
#include <climits>

// Orthodox Canonical Form
Span::Span() : _maxSize(0){}


Span::Span(unsigned int N) : _maxSize(N){}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers){}


Span::~Span(){}


Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return (*this);
}

// Member functions
void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
    {
        throw std::out_of_range("Span is full, cannot add more numbers");
    }
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
    {
        throw std::logic_error("Need at least 2 numbers to calculate span");
    }
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        unsigned int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
        {
            minSpan = span;
        }
    }
    
    return (minSpan);
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
    {
        throw std::logic_error("Need at least 2 numbers to calculate span");
    }
    
    std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
    
    return (*maxIt - *minIt);
} 