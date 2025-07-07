#include <iostream>
#include <list>
#include <stack>
#include "MutantStack.hpp"

int main()
{
    std::cout << "*** Testing MutantStack (Subject Example) ***" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    
    std::cout << "\n*** Comparing with std::list ***" << std::endl;
    {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        std::cout << lst.back() << std::endl;
        lst.pop_back();
        std::cout << lst.size() << std::endl;
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);
        
        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    
    std::cout << "\n*** Testing reverse iterators ***" << std::endl;
    {
        MutantStack<int> mstack;
        for (int i = 1; i <= 5; ++i)
        {
            mstack.push(i);
        }
        
        std::cout << "Forward iteration:" << std::endl;
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Reverse iteration:" << std::endl;
        for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "\n*** Testing const iterators ***" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);
        
        const MutantStack<int>& constStack = mstack;
        
        std::cout << "Using const iterators:" << std::endl;
        for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "\n*** Testing with different data types ***" << std::endl;
    {
        MutantStack<std::string> stringStack;
        stringStack.push("Hello");
        stringStack.push("World");
        stringStack.push("C++");
        stringStack.push("Module");
        stringStack.push("08");
        
        std::cout << "String stack contents:" << std::endl;
        for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "\n*** Testing stack operations ***" << std::endl;
    {
        MutantStack<int> mstack;
        
        std::cout << "Empty stack size: " << mstack.size() << std::endl;
        if (mstack.empty())
        {
            std::cout << "Is empty: true" << std::endl;
        }
        else
        {
            std::cout << "Is empty: false" << std::endl;
        }
        
        mstack.push(42);
        std::cout << "After push(42):" << std::endl;
        std::cout << "Size: " << mstack.size() << std::endl;
        std::cout << "Top: " << mstack.top() << std::endl;
        if (mstack.empty())
        {
            std::cout << "Is empty: true" << std::endl;
        }
        else
        {
            std::cout << "Is empty: false" << std::endl;
        }
        
        mstack.push(84);
        mstack.push(126);
        std::cout << "After adding more elements:" << std::endl;
        std::cout << "Size: " << mstack.size() << std::endl;
        std::cout << "Top: " << mstack.top() << std::endl;
        
        std::cout << "All elements (using iterator):" << std::endl;
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        mstack.pop();
        std::cout << "After pop():" << std::endl;
        std::cout << "Size: " << mstack.size() << std::endl;
        std::cout << "Top: " << mstack.top() << std::endl;
    }
    
    return (0);
} 