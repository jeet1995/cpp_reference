class Shape {
public:
    // Deleted copy constructor:
    // This explicitly prevents the creation of new Shape objects through copying
    // from an existing Shape object. The `= delete` syntax instructs the compiler
    // not to generate a default copy constructor and disallows its use.
    Shape(const Shape &other) = delete;

    // Deleted copy assignment operator:
    // This explicitly prevents the assignment of one existing Shape object to another
    // existing Shape object. The `= delete` syntax instructs the compiler not to
    // generate a default copy assignment operator and disallows its use.
    Shape &operator=(const Shape &other) = delete;

    // Deleted move constructor:
    // This explicitly prevents the creation of new Shape objects by moving resources
    // from a temporary (rvalue) Shape object. The `= delete` syntax instructs the
    // compiler not to generate a default move constructor and disallows its use.
    Shape(Shape &&other) = delete;

    // Deleted move assignment operator:
    // This explicitly prevents the assignment of a temporary (rvalue) Shape object
    // to an existing Shape object by moving resources. The `= delete` syntax instructs
    // the compiler not to generate a default move assignment operator and disallows its use.
    Shape &operator=(Shape &&other) = delete;
};
