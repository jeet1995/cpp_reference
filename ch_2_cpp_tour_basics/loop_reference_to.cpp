//
// Created by Abhijeet Mohanty on 4/20/25.
//

#include <iostream>

int main() {
    // Initialize an array of integers
    int numbers[] = {1, 2, 3, 4, 5};
    
    // Using range-based for loop with reference
    // The '&' makes x a reference to each element, allowing modification if needed
    for (int& x : numbers) {
        // Multiply each element by 2 to demonstrate modification through reference
        x *= 2;
    }
    
    // Print the modified array using another range-based for loop
    // Here we use const reference since we're only reading
    for (const int& x : numbers) {
        // Print each element followed by a space
        std::cout << x << " ";
    }
    std::cout << std::endl;
    
    return 0;
}