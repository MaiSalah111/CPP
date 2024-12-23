#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

int main() {
    int N = 5;
    Zombie* horde = zombieHorde(N, "Horde Walker");
    
    // Test all zombies in the horde
    for (int i = 0; i < N; i++) {
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }
    
    // Clean up the horde
    delete[] horde;
    
    return 0;
} 