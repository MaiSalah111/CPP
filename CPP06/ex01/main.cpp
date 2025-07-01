#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    data.number = 42;
    data.text = "Hello, serialization!";

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << &data << std::endl;
    std::cout << "Deserialized pointer: " << ptr << std::endl;
    std::cout << "Data: number = " << ptr->number << ", text = " << ptr->text << std::endl;

    if (ptr == &data)
    {
        std::cout << "Success: pointers match!" << std::endl;
    }
    else
    {
        std::cout << "Error: pointers do not match!" << std::endl;
    }

    return (0);
} 