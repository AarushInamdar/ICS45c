#include "rectangle.hpp"

class Square : public Rectangle {
	public:
	using Rectangle::Rectangle;

	Square(Point center, std::string name, int side);
	
	private:
	int side;

};


