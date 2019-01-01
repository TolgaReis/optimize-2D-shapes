#include"Triangle.h"

namespace shape{
    double Triangle::_totalArea = 0;
    double Triangle::_totalPerimeter = 0;
    Triangle::Triangle(): Shape(), _p1x(0), _p1y(0), _p2x(0), _p2y(0), _p3x(0), _p3y(0), _side(0){
        _totalArea += area();
        _totalPerimeter += perimeter();
    }
    Triangle::Triangle(double p1x, double p1y,
                       double p2x, double p2y,
                       double p3x, double p3y,
                       string color, double rotateDegree,
                       double rotateX, double rotateY, double side): Shape(rotateX, rotateY, rotateDegree, color),
                       _p1x(p1x), _p1y(p1y), _p2x(p2x), _p2y(p2y), _p3x(p3x), _p3y(p3y), _side(side){
        _totalArea += area();
        _totalPerimeter += perimeter();

    }
    Triangle::Triangle(double p1x, double p1y,
             double p2x, double p2y,
             double p3x, double p3y,
             string color, double side): Shape(color),
             _p1x(p1x), _p1y(p1y), _p2x(p2x), _p2y(p2y), _p3x(p3x), _p3y(p3y), _side(side){
        _totalArea += area();
        _totalPerimeter += perimeter();
    }
    void Triangle::set(double p1x, double p1y,
                       double p2x, double p2y,
                       double p3x, double p3y,
                       string color, double rotateDegree,
                       double rotateX, double rotateY, double side){
        _p1x = p1x;
        _p1y = p1y;
        _p2x = p2x;
        _p2y = p2y;
        _p3x = p3x;
        _p3y = p3y;
        _color = color;
        _rotateDegree = rotateDegree;
        _rotateX = rotateX;
        _rotateY = rotateY;
    }
    void Triangle::set(double p1x, double p1y,
                       double p2x, double p2y,
                       double p3x, double p3y,
                       string color, double side){
        _p1x = p1x;
        _p1y = p1y;
        _p2x = p2x;
        _p2y = p2y;
        _p3x = p3x;
        _p3y = p3y;
        _color = color;
        _side = side;
    }
    void Triangle::set(double p1x, double p1y,
                       double p2x, double p2y,
                       double p3x, double p3y,
                       string color){
        _p1x = p1x;
        _p1y = p1y;
        _p2x = p2x;
        _p2y = p2y;
        _p3x = p3x;
        _p3y = p3y;
        _color = _color;
    }
    void Triangle::set(double rotateDegree,
                       double rotateX, double rotateY){
        _rotateDegree = rotateDegree;
        _rotateX = rotateX;
        _rotateY = rotateY;
    }
    double Triangle::getP1X() const{ return _p1x; }
    double Triangle::getP1Y() const{ return _p1y; }
    double Triangle::getP2X() const{ return _p2x; }
    double Triangle::getP2Y() const{ return _p2y; }
    double Triangle::getP3X() const{ return _p3x; }
    double Triangle::getP3Y() const{ return _p3y; }
    double Triangle::getSide() const{ return _side; }
    double Triangle::area() const noexcept{
        return (_side * _side * SQRT3) / 4;
    }
    double Triangle::perimeter() const noexcept{
        return (_side * 3);
    }
    void Triangle::draw(ostream& outputStream) const noexcept{
        outputStream << "\n <polygon transform = 'rotate("
                         + to_string(_rotateDegree) + " "
                         + to_string(_rotateX) + " "
                         + to_string(_rotateY) + ")' "

                         + "points = '" + to_string(_p1x) + " "
                         + to_string(_p1y) + " "
                         + to_string(_p2x) + " "
                         + to_string(_p2y) + " "
                         + to_string(_p3x) + " "
                         + to_string(_p3y) + "' fill = '"
                         + _color + "' stroke = 'black' stroke-width = '1' />";
    }
    //THERE HAVE TO BE THROW EXCEPTION
    const Triangle& Triangle::operator ++() noexcept{
        Triangle *temp = new Triangle(_p1x++, _p1y++, _p2x++, _p2y++, _p3x++, _p3y++, _color, _side);
        return *temp;
    }
    const Triangle& Triangle::operator ++(int) noexcept{
        _p1x++;
        _p1y++;
        _p2x++;
        _p2y++;
        _p3x++;
        _p3y++;
        return *this;
    }
    const Triangle& Triangle::operator --(){
        if(_p1x - 1 < 0 || _p1y - 1 < 0 ||
           _p2x - 1 < 0 || _p2y - 1 < 0 ||
           _p3x - 1 < 0 || _p3y - 1 < 0)
            throw shapeException("Negative coordinate!");
        Triangle *temp = new Triangle(_p1x--, _p1y--, _p2x--, _p2y--, _p3x--, _p3y--, _color, _side);
        return *temp;
    }
    //THERE HAVE TO BE THROW EXCEPTION
    const Triangle& Triangle::operator --(int){
        if(_p1x - 1 < 0 || _p1y - 1 < 0 ||
           _p2x - 1 < 0 || _p2y - 1 < 0 ||
           _p3x - 1 < 0 || _p3y - 1 < 0)
            throw shapeException("Negative coordinate!");
        _p1x--;
        _p1y--;
        _p2x--;
        _p2y--;
        _p3x--;
        _p3y--;
        return *this;
    }
    bool Triangle::operator ==(const Triangle& rightSide) noexcept{
        return (this->area() == rightSide.area());
    }
    bool Triangle::operator !=(const Triangle& rightSide) noexcept{
        return !(this->area() == rightSide.area());
    }
    bool Triangle::operator <(const Triangle& rightSide) noexcept{
        return (this->area() < rightSide.area());
    }
    bool Triangle::operator >(const Triangle& rightSide) noexcept{
        return (this->area() > rightSide.area());
    }
    bool Triangle::operator <=(const Triangle& rightSide) noexcept{
        return (this->area() <= rightSide.area());
    }
    bool Triangle::operator >=(const Triangle& rightSide) noexcept{
        return (this->area() >= rightSide.area());
    }
    double Triangle::getTotalArea(){ return _totalArea; }
    double Triangle::getTotalPerimeter(){ return _totalPerimeter; }
    Triangle::~Triangle(){}
}
