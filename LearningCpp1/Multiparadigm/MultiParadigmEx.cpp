

//Procedural Programming - Focuses on a sequence of instructions that operate on data

//Object Oriented Programming - Centers around objects that encapsulate data and behaviors

//Generic Programming - Focuses on writing reusable and type-independent code

//Functional Programming - Emphasizes immmutability, first-class functions, and declarative programming

//Concurrent Programming - Enables execution of code in parallel or asynchronously 

//Declararative Programming - Focuses on the "what" rather than the "how" of problem-solving

//Meta Programming - Writing code that generates orn manipulates other code at compile-time or runtime

//Systems Programming - Direct interaction with hardware and system resources

//Data=Oriented Programming - Organizes and structures programs based on data layout and access patterns for performance

//Will show example of Procedural, Object Oriented, and Generic


//I.e. A program to manage a collection of shapes (circles and rectangles) and calculate their areas.
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

using namespace std; 


// Generic Programming: Template for a function
template <typename T>
T getMax(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// OOP: Abstract base class (interface for shapes)
class Shape {
public:
    virtual double getArea() const = 0; // Pure virtual function
    virtual void display() const = 0;   // Pure virtual function
    virtual ~Shape() = default;        // Virtual destructor
};

// OOP: Derived class for Circle
class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(double r)/*  : radius(r) */ {
            this->radius = r;
        }
        double getArea() const override {
            return M_PI * radius * radius; // Area of circle
        }
        void display() const override {
            cout << "Circle with radius " << radius << ", Area: " << getArea() << endl;
        }
};

// OOP: Derived class for Rectangle
class Rectangle : public Shape {
    private:
        double width, height;
    public:
        Rectangle(double w, double h) : width(w), height(h) {}
            double getArea() const override {
                return width * height; // Area of rectangle
        }
        void display() const override {
           cout << "Rectangle with width " << width << " and height " << height << ", Area: " << getArea() << endl;
        }
};

/*
class Rectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height
*/

// Procedural Programming: Function to process shapes
void processShapes(const vector<shared_ptr<Shape>>& shapes) {
    cout << "Processing Shapes...\n";
    for (const auto& shape : shapes) {
        shape->display();
    }
    // Find and display the largest area
    double maxArea = 0.0;
    for (const auto& shape : shapes) {
        maxArea = getMax(maxArea, shape->getArea());
    }
    cout << "Largest Area: " << maxArea << "\n";
}

int main() {
    // Procedural Programming: Main flow of the program
    vector<shared_ptr<Shape>> shapes;
    shapes.push_back(make_shared<Circle>(5.0));
    shapes.push_back(make_shared<Rectangle>(4.0, 6.0));
    shapes.push_back(make_shared<Circle>(3.0));
    shapes.push_back(make_shared<Rectangle>(7.0, 2.0));

    processShapes(shapes);

    return 0;
}
