#include"Shape.h"

namespace shape{
    Shape::Shape(): _rotateX(0), _rotateY(0), _rotateDegree(0), _color("red"){}
    Shape::Shape(double rotateX, double rotateY, double rotateDegree, string color)
    : _rotateX(rotateX), _rotateY(rotateY), _rotateDegree(rotateDegree), _color(color){}
    Shape::Shape(string color): _color(color), _rotateX(0), _rotateY(0), _rotateDegree(0){}
    double Shape::getRotateDegree() const{ return _rotateDegree; }
    double Shape::getRotateX() const{ return _rotateX; }
    double Shape::getRotateY() const{ return _rotateY; }
    double Shape::getPI() const{ return PI; }
    string Shape::getColor() const{ return _color; }
    bool Shape::operator ==(const Shape& rightSide) noexcept{
        return (this->_rotateX == rightSide._rotateX &&
                this->_rotateY == rightSide._rotateY &&
                this->_rotateDegree == rightSide._rotateDegree &&
                this->_color == rightSide._color);
    }
    bool Shape::operator !=(const Shape& rightSide) noexcept{
        return (this->_rotateX != rightSide._rotateX &&
                this->_rotateY != rightSide._rotateY &&
                this->_rotateDegree != rightSide._rotateDegree &&
                this->_color != rightSide._color);
    }
    bool Shape::operator <(const Shape& rightSide) noexcept{
        return (this->_rotateX < rightSide._rotateX &&
                this->_rotateY < rightSide._rotateY &&
                this->_rotateDegree < rightSide._rotateDegree &&
                this->_color < rightSide._color);
    }
    bool Shape::operator >(const Shape& rightSide) noexcept{
        return (this->_rotateX > rightSide._rotateX &&
                this->_rotateY > rightSide._rotateY &&
                this->_rotateDegree > rightSide._rotateDegree &&
                this->_color > rightSide._color);
    }
    bool Shape::operator <=(const Shape& rightSide) noexcept{
        return (this->_rotateX <= rightSide._rotateX &&
                this->_rotateY <= rightSide._rotateY &&
                this->_rotateDegree <= rightSide._rotateDegree &&
                this->_color <= rightSide._color);
    }
    bool Shape::operator >=(const Shape& rightSide) noexcept{
        return (this->_rotateX >= rightSide._rotateX &&
                this->_rotateY >= rightSide._rotateY &&
                this->_rotateDegree >= rightSide._rotateDegree &&
                this->_color >= rightSide._color);
    }
    Shape::~Shape(){}
}
