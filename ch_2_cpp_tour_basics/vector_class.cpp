#include <iostream>

class Vector {
private:
    double* elem;  // pointer to the elements
    int sz;        // size of the vector

public:
    // Constructor
    Vector(int s) : elem{new double[s]}, sz{s} {
        for (int i = 0; i < s; i++) {
            elem[i] = 0;  // Initialize all elements to 0
        }
    }

    // Destructor to free memory
    ~Vector() {
        delete[] elem;
    }

    // Get element at index
    double& operator[](int i) {
        if (i < 0 || i >= sz) {
            throw std::out_of_range("Index out of range");
        }
        return elem[i];
    }

    // Get size of vector
    int size() const {
        return sz;
    }
};

int main() {
    try {
        // Create a vector of size 5
        Vector v(5);

        // Set some values
        v[0] = 1.1;
        v[1] = 2.2;
        v[2] = 3.3;
        v[3] = 4.4;
        v[4] = 5.5;

        // Print all elements
        std::cout << "Vector elements: ";
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;

        // Demonstrate out of bounds exception
        std::cout << "Trying to access out of bounds index..." << std::endl;
        std::cout << v[5] << std::endl;  // This will throw an exception
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
} 