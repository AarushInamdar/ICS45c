#include "shape.hpp"
#include <iostream>

class Shape {
public:
    // construct this Shape with given center and name
    Shape(Point center, std::string name){
        
    }

    // prints this Shape's name and coordinates
    // in this specific format followed by a newline:
    // name(center.x, center.y), e.g., Circle_2(1, 2)
    void print(std::ostream& out) const {

    }

    // delete assignment to prevent accidental slicing
    Shape& operator=(const Shape& other) = delete{

    }

    // computes and returns the area of this Shape
    virtual double area() const = 0{

    }

    // draws this Shape using character graphics
    // (using algorithms given in write-up)
    virtual void draw(std::ostream& out) const = 0{

    }

    // create a new duplicate of this Shape
    // allocated from the free store
    // must be over-ridden by each concrete class
    // to return a copy of itself
    virtual Shape* clone() const = 0{

    }

    // clean up any sub-storage owned by this Shape object
    virtual ~Shape() = default{

    }
protected:
    // protect the copy constructor to be used only by clone()
    Shape(const Shape& other) = default{
        
    }

}