#include "Zombie.hpp"

int main() {
    // Creating a zombie on the heap
    Zombie* heapZombie = newZombie("Heap Walker");
    heapZombie->announce();
    
    // Creating a zombie on the stack
    randomChump("Stack Crawler");
    
    // Don't forget to delete heap-allocated zombie
    delete heapZombie;
    
    return 0;
} 