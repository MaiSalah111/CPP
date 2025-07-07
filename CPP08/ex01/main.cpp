#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
    std::cout << "*** Basic Span Test (Subject Example) ***" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n*** Testing with addRange function ***" << std::endl;
    try
    {
        Span sp2 = Span(10);
        std::vector<int> numbers;
        numbers.push_back(1);
        numbers.push_back(5);
        numbers.push_back(10);
        numbers.push_back(15);
        numbers.push_back(20);
        sp2.addRange(numbers.begin(), numbers.end());
        
        std::cout << "Added 5 numbers using addRange" << std::endl;
        std::cout << "Current size: " << sp2.getCurrentSize() << std::endl;
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
        
        // Add more numbers individually
        sp2.addNumber(25);
        sp2.addNumber(30);
        std::cout << "Added 2 more numbers individually" << std::endl;
        std::cout << "Current size: " << sp2.getCurrentSize() << std::endl;
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
        
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n*** Testing error cases ***" << std::endl;
    try
    {
        Span sp3 = Span(2);
        sp3.addNumber(1);
        sp3.addNumber(2);
        sp3.addNumber(3); // Should throw exception
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try
    {
        Span sp4 = Span(1);
        sp4.addNumber(1);
        sp4.shortestSpan(); // Should throw exception
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try
    {
        Span sp5 = Span(0);
        sp5.addNumber(1); // Should throw exception
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n*** Testing with 10,000 numbers ***" << std::endl;
    try
    {
        Span sp6 = Span(10000);
        std::vector<int> largeNumbers;
        
        // Generate 10,000 random numbers
        std::srand(std::time(0));
        for (int i = 0; i < 10000; ++i)
        {
            largeNumbers.push_back(std::rand() % 1000000);
        }
        
        sp6.addRange(largeNumbers.begin(), largeNumbers.end());
        
        std::cout << "Successfully added 10,000 numbers" << std::endl;
        std::cout << "Current size: " << sp6.getCurrentSize() << std::endl;
        std::cout << "Shortest span: " << sp6.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp6.longestSpan() << std::endl;
        
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return (0);
} 