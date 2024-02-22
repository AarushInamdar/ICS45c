#include "shape.hpp"
#include <iostream>

Shape::Shape(Point center, std::string name) : center(center), name(std::move(name)) {
}

// prints this Shape's name and coordinates
// in this specific format followed by a newline:
// name(center.x, center.y), e.g., Circle_2(1, 2)
void Shape::print(std::ostream& out) const {
	out << this->name << " at (" << this->center.x << ", "<< this->center.y << ") area = " << this->area() << '\n';
}

// delete assignment to prevent accidental slicing
Shape& Shape::operator=(const Shape& other) = delete {
	if (this!=other) {
	this->name = other.name;
	this->center = other.center;
	}
	return *this;
}
/*
// computes and returns the area of this Shape
double Shape::area()  const{
}

// draws this Shape using character graphics
// (using algorithms given in write-up)
void Shape::draw(std::ostream& out)  const{
}

// create a new duplicate of this Shape
// allocated from the free store
// must be over-ridden by each concrete class
// to return a copy of itself


Shape* Shape::clone()  const {
	
}


// clean up any sub-storage owned by this Shape object
// protect the copy constructor to be used only by clone()

Shape::Shape(const Shape& other) : center(other.center), name(other.name) {
	
}
*/

