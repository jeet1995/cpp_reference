class Vector {
public:
    int size;
    double *data;

    Vector(int size);

    // Destructor for the Vector class.
    // This special member function is automatically called when a Vector object
    // is destroyed (e.g., when it goes out of scope or is explicitly deleted
    // if it was allocated using 'new').
    ~Vector() {
        // Release dynamically allocated memory:
        // If the 'data' member (which is a pointer to an array of integers)
        // was allocated using 'new[]', this line ensures that the memory is
        // properly deallocated using 'delete[]'. This prevents memory leaks.
        delete[] data;

        // After deleting the dynamically allocated array, it's good practice to
        // set the 'data' pointer to null to avoid potential dangling pointer issues
        // if the pointer is accidentally used after the memory has been freed.
        data = nullptr;
    }

    // **Distinction between Copy Constructor and Copy Assignment Operator**

    // **Copy Constructor:**
    // - Purpose: To initialize a *new* object as a copy of an *existing* object.
    // - Invocation: Called during object creation when an object is initialized with another
    //   object of the same type (e.g., `MyClass obj2 = obj1;`). Also invoked when passing
    //   objects by value to functions, returning objects by value, and during temporary
    //   object creation.
    // - Behavior: Responsible for setting the initial state of the *newly created* object
    //   by copying data from the existing object.

    // **Copy Assignment Operator:**
    // - Purpose: To assign the value of one *existing* object to another *already existing* object.
    // - Invocation: Called when the assignment operator (`=`) is used between two objects
    //   of the same type that have already been constructed (e.g., `obj1 = obj2;`).
    // - Behavior: Responsible for modifying the state of the *already existing* left-hand
    //   side object to be a copy of the right-hand side object. This often involves:
    //     - Checking for self-assignment (`if (this == &other)`).
    //     - Releasing any resources owned by the left-hand side object.
    //     - Allocating new resources if necessary (for deep copying).
    //     - Copying the data from the right-hand side object.
    //     - Returning a reference to the left-hand side object (`return *this;`).

    // **Analogy:**
    // - Copy Constructor: Like using a blueprint of an existing house to *build a brand new house*.
    // - Copy Assignment Operator: Like taking an *already built house* and *remodeling it* to
    //   look exactly like another existing house.

    // **Why Both are Needed:**
    // - They handle different stages of an object's lifecycle:
    //   - Copy Constructor: Initialization of a new object.
    //   - Copy Assignment Operator: Modification of an existing object.
    // - For classes managing resources (e.g., dynamic memory), both are often necessary to
    //   ensure correct deep copying behavior in both initialization and assignment scenarios,
    //   preventing issues like shallow copies, memory leaks, and double deletion. This is
    //   a core concept related to the Rule of Three/Five/Zero in C++.

    // Copy constructor for the Vector class.
    // This special constructor is invoked automatically when a new Vector object
    // is initialized as a copy of an existing Vector object.
    // It takes a constant reference to another Vector object ('other') as its argument.
    // The 'const' keyword ensures that the 'other' Vector is not modified during the copying process.
    // The '&' indicates that 'other' is passed by reference, avoiding an unnecessary copy of the Vector itself.
    Vector(const Vector &other);

    // Copy assignment operator for the Vector class.
    // This special member function is invoked when one existing Vector object is assigned
    // the value of another existing Vector object using the assignment operator (=).
    // It takes a constant reference to another Vector object ('other') as its argument.
    // The 'const' keyword ensures that the 'other' Vector is not modified during the assignment.
    // The '&' indicates that 'other' is passed by reference for efficiency, avoiding an
    // unnecessary copy of the Vector being assigned from.
    Vector &operator=(const Vector &other);

    // Move constructor for the Vector class.
    // This special constructor is invoked when a new Vector object is initialized
    // from an rvalue reference (typically a temporary object or an object moved
    // explicitly using std::move()). Its purpose is to efficiently transfer
    // ownership of resources from the 'other' Vector to the newly created Vector
    // without performing a deep copy.
    Vector(const Vector &&other);

    // Move assignment operator for the Vector class.
    // This special member function is invoked when an existing Vector object is assigned
    // the value of an rvalue reference (typically a temporary object or an object moved
    // explicitly using std::move()). Its purpose is to efficiently transfer ownership
    // of resources from the 'other' Vector to the current Vector without performing
    // a deep copy.
    Vector &operator=(const Vector &&other);
};
