#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    // Orthodox Canonical Form
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    ~Span();
    Span& operator=(const Span& other);

    // Member functions
    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    
    // Bonus: add range of numbers
    template<typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        unsigned int remainingSpace = _maxSize - _numbers.size();
        unsigned int rangeSize = std::distance(begin, end);
        
        if (rangeSize > remainingSpace) {
            throw std::runtime_error("Not enough space to add all numbers");
        }
        
        _numbers.insert(_numbers.end(), begin, end);
    }
    
    // Getters for testing
    unsigned int getMaxSize() const { return _maxSize; }
    unsigned int getCurrentSize() const { return _numbers.size(); }
    const std::vector<int>& getNumbers() const { return _numbers; }
};

#endif 