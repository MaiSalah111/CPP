#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main()
{
    for (int i = 0; i < 3; ++i)
    {
        Base* ptr = generate();
        std::cout << "Pointer: ";
        identify(ptr);
        std::cout << "Reference: ";
        identify(*ptr);
        delete ptr;
        std::cout << "----" << std::endl;
    }
    return (0);
} 