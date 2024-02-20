#include "circle.hpp"
#include <iostream>
#include <numbers>

class Circle {
public:
    Circle(Point center, std::string name, int radius){

    }

    double area() const override{

    }
    void draw(std::ostream& out) const override{

    }
    Circle* clone() const override{

    }

protected:
    Circle(const Circle& other) = default{

    }
};