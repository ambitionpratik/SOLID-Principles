class Shape {
public:
    virtual std::string getType() = 0;
};

class AreaCalculator {
public:
    double calculateArea(Shape* shape) {
        if (shape->getType() == "circle") {
            // circle area logic
        } else if (shape->getType() == "rectangle") {
            // rectangle area logic
        }
        return 0;
    }
};

// AreaCalculator violets the OCP. If some other shape need to calculate area, then the method need to be changed.

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14 * radius * radius; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
};

class AreaCalculator {
public:
    double calculateArea(const Shape& shape) {
        return shape.area();
    }
};
