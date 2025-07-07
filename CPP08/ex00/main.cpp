#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
    std::cout << "*** Testing easyfind with vector ***" << std::endl;
    std::vector<int> vec;
    for (int i = 1; i <= 10; ++i)
    {
        vec.push_back(i);
    }
    
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found value 5 at position: " << std::distance(vec.begin(), it) << std::endl;
        
        it = easyfind(vec, 10);
        std::cout << "Found value 10 at position: " << std::distance(vec.begin(), it) << std::endl;
        
        it = easyfind(vec, 1);
        std::cout << "Found value 1 at position: " << std::distance(vec.begin(), it) << std::endl;
        
        // Test with value not in container
        it = easyfind(vec, 42);
        std::cout << "This should not be printed" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }





    
    std::cout << "\n*** Testing easyfind with list ***" << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    
    try
    {
        std::list<int>::iterator it = easyfind(lst, 30);
        std::cout << "Found value 30 at position: " << std::distance(lst.begin(), it) << std::endl;
        
        it = easyfind(lst, 10);
        std::cout << "Found value 10 at position: " << std::distance(lst.begin(), it) << std::endl;
        
        // Test with value not in container
        it = easyfind(lst, 100);
        std::cout << "This should not be printed" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }





    
    
    std::cout << "\n*** Testing easyfind with deque ***" << std::endl;
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    deq.push_back(400);
    deq.push_back(500);
    
    try
    {
        std::deque<int>::iterator it = easyfind(deq, 300);
        std::cout << "Found value 300 at position: " << std::distance(deq.begin(), it) << std::endl;
        
        it = easyfind(deq, 500);
        std::cout << "Found value 500 at position: " << std::distance(deq.begin(), it) << std::endl;
        
        // Test with value not in container
        it = easyfind(deq, 999);
        std::cout << "This should not be printed" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return (0);
} 