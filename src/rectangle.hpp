#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape {
public:
    Rectangle(Point center, std::string name, int width, int height);

    double area() const ;

    void draw(std::ostream& out) const ;

    Rectangle* clone() const ;

protected:
    Rectangle(const Rectangle& other) = default;

private:
    int width;
    int height;
};

#endif
