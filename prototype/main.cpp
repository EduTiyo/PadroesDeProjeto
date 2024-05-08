#include <iostream>
#include <vector>

class Shape {
protected:
    int X;
    int Y;
    std::string color;

public:
    Shape(int x = 0, int y = 0, const std::string& color = "white")
        : X(x), Y(y), color(color) {}

    Shape(const Shape& source)
        : X(source.X), Y(source.Y), color(source.color) {}

    virtual Shape* clone() const = 0;

    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    Rectangle(int x = 0, int y = 0, const std::string& color = "white",
              int width = 0, int height = 0)
        : Shape(x, y, color), width(width), height(height) {}

    Rectangle(const Rectangle& source)
        : Shape(source), width(source.width), height(source.height) {}

    Shape* clone() const override {
        return new Rectangle(*this);
    }
};

class Circle : public Shape {
private:
    int radius;

public:
    Circle(int x = 0, int y = 0, const std::string& color = "white", int radius = 0)
        : Shape(x, y, color), radius(radius) {}

    Circle(const Circle& source)
        : Shape(source), radius(source.radius) {}

    Shape* clone() const override {
        return new Circle(*this);
    }
};

class Application {
private:
    std::vector<Shape*> shapes;

public:
    Application() {
        Circle* circle = new Circle(10, 10, "blue", 20);
        shapes.push_back(circle);

        Circle* anotherCircle = dynamic_cast<Circle*>(circle->clone());
        shapes.push_back(anotherCircle);

        Rectangle* rectangle = new Rectangle(0, 0, "red", 10, 20);
        shapes.push_back(rectangle);
    }

    ~Application() {
        for (auto shape : shapes) {
            delete shape;
        }
    }

    void businessLogic() {
        std::vector<Shape*> shapesCopy;

        for (auto shape : shapes) {
            shapesCopy.push_back(shape->clone());
        }
    }
};

int main() {
    Application app;
    app.businessLogic();
    return 0;
}
