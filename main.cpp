#include <iostream>
using namespace std;

class Square {
protected:
    double side;

public:
    Square(double s) : side(s) {}

    double getSide() const {
        return side;
    }

    double area() const {
        return side * side;
    }
};

class Circle {
protected:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getRadius() const {
        return radius;
    }

    double area() const {
        return 3.14159265359 * radius * radius;
    }
};

class InscribedCircle : public Square, public Circle {
public:
    InscribedCircle(double side) : Square(side), Circle(side / 2.0) {}

    double getInscribedRadius() const {
        return getSide() / 2.0;
    }

    double area() const {
        return 3.14159265359 * getInscribedRadius() * getInscribedRadius();
    }
};

int main() {
    InscribedCircle inscribedCircle(4.0);

    cout << "Площадь квадрата: " << inscribedCircle.Square::area() << endl;
    cout << "Площадь вписанной окружности: " << inscribedCircle.area() << endl;

    return 0;
}
