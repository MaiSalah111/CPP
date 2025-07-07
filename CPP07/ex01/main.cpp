#include <iostream>
#include "iter.hpp"

void printInt(const int &x)
{
    std::cout << x << std::endl;
}

void printStr(const std::string &s)
{
    std::cout << s << " ";
}

void increment(int &x)
{
    ++x;
}

class CustomClass
{
public:
    CustomClass(void) : _n(42)
    {
        return;
    }
    int get(void) const
    {
        return (this->_n);
    }
private:
    int _n;
};

std::ostream &operator<<(std::ostream &o, CustomClass const &a)
{
    o << a.get();
    return (o);
}

void printCustomClass(const CustomClass &x)
{
    std::cout << x << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Original int array:" << std::endl;
    iter(arr, len, printInt);
    std::cout << std::endl;
    iter(arr, len, increment);
    std::cout << "Incremented int array:" << std::endl;
    iter(arr, len, printInt);
    std::cout << std::endl;

    const std::string strArr[] = {"hello", "world", "!"};
    size_t strLen = sizeof(strArr) / sizeof(strArr[0]);
    std::cout << "Const string array:" << std::endl;
    iter(strArr, strLen, printStr);
    std::cout << std::endl;

    int tab[] = {0, 1, 2, 3, 4};
    CustomClass tab2[5];
    std::cout << "tab prints 0 to 4, each on a new line:" << std::endl;
    iter(tab, 5, printInt);
    std::cout << "tab2 is an array of 5 CustomClass objects, each initialized to 42, so five lines of 42:" << std::endl;
    iter(tab2, 5, printCustomClass);

    return (0);
} 