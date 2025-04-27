#include <iostream>

class Point {
public:
    Point(int x, int y);

    int getX() const {
        return x;
    };

    int getY() const {
        return y;
    }

private:
    int x;
    int y;
};

class Shape {
public:
    // Virtual function allowing derived classes to provide their own implementation.
    // - Returns a Point object.
    // - Takes no arguments.
    // - Does not modify the object's state (const).
    // - Makes the Shape class abstract (cannot be instantiated).
    // - Forces concrete derived classes to implement this function.
    virtual Point center() = 0;

    // p is passed by value
    // so p.getX() - the dot operator needs to be used for access
    virtual void move(Point p) = 0;

    // Virtual destructor for the Shape class.
    // It's crucial to make the destructor virtual in a base class that is part of an
    // inheritance hierarchy. This ensures that when a derived class object is deleted
    // through a base class pointer, the derived class's destructor is also called,
    // preventing potential resource leaks.
    virtual ~Shape() {
    }
};

class Rectangle final : public Shape {
public:
    // Constructor for the Rectangle class.
    // Takes the x and y coordinates of a corner (e.g., top-left),
    // and the width and height of the rectangle as input.
    Rectangle(int x, int y, int width, int height);

    // Overrides the virtual center() method inherited from the Shape base class.
    // This provides a specific implementation for calculating (and in this case, setting)
    // the center of a Rectangle.
    Point center() override {
        std::cout << "The rectangle instance has been centered!" << std::endl;
        this->x = 0;
        this->y = 0;
        return Point(0, 0);
    }

    // Overrides the virtual move() method inherited from the Shape base class.
    // This provides a specific implementation for moving the Rectangle by a given Point.
    void move(Point p) override {
        this->x += p.getX();
        this->y += p.getY();
        std::cout << "The rectangle instance moves!" << std::endl;
    }

    ~Rectangle() override {
    }

private:
    int x;
    int y;
    int width;
    int height;
};
