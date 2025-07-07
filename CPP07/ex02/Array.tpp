#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

// Default constructor
template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
}

// Constructor with size
template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n)
{
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(0)
{
    if (other._size > 0)
    {
        _data = new T[other._size]();
        _size = other._size;
        for (unsigned int i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }
}

// Assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] _data;
        _data = NULL;
        _size = 0;
        if (other._size > 0)
        {
            _data = new T[other._size]();
            _size = other._size;
            for (unsigned int i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
    }
    return (*this);
}

// Destructor
template <typename T>
Array<T>::~Array()
{
    delete[] _data;
}

// Subscript operator (non-const)
template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::exception();
    return (_data[index]);
}

// Subscript operator (const)
template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::exception();
    return (_data[index]);
}

// size() member function
template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

#endif // ARRAY_TPP 