#include <iostream>
#include "Array.hpp"

int main() {
    std::cout << "Create an Array<int> of size 5 and fill it with i*2:" << std::endl;
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = i * 2;
    std::cout << "Array a: ";
    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "\nCopy a to b, modify b, and show both arrays (deep copy test):" << std::endl;
    Array<int> b = a;
    b[0] = 42;
    std::cout << "Array b (after copy and modify): ";
    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << b[i] << " ";
    std::cout << std::endl;
    std::cout << "Array a (should be unchanged): ";
    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "\nCreate an Array<std::string> and fill it:" << std::endl;
    Array<std::string> s(3);
    s[0] = "hello";
    s[1] = "world";
    s[2] = "!";
    std::cout << "String array: ";
    for (unsigned int i = 0; i < s.size(); ++i)
        std::cout << s[i] << " ";
    std::cout << std::endl;

    std::cout << "\nTest out-of-bounds access (should catch exception):" << std::endl;
    try {
        std::cout << "Accessing out of bounds: ";
        std::cout << a[10] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Caught exception!" << std::endl;
    }

    std::cout << "\nCreate an empty Array<int> and show its size:" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;

    return 0;
} 