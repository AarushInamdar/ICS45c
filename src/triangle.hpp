#include "shape.hpp"
#include <alogirthm>

class Triangle: public Shape {
    public:
    Triangle(Point, center, std::string name, int height, int base);

    int area const override;

    void draw(std::ostream& out) const override;

    Triangle* clone() const override;

    protected:
    Triangle(const Triangle& other) = default;

    private:
    int height;
    int base;
};

#endif
