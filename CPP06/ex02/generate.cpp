#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate()
{
    std::srand(std::time(0) + std::rand());
    int r = std::rand() % 3;
    if (r == 0)
    {
        return (new A);
    }
    else if (r == 1)
    {
        return (new B);
    }
    else
    {
        return (new C);
    }
} 