#include"Circle.h"

namespace shape{
    double Circle::_totalArea = 0;
    double Circle::_totalPerimeter = 0;
    Circle::Circle(): Shape(), _cx(0), _cy(0), _r(0){}
    Circle::Circle(double cx,double cy,
           double r, string color,
           double rotateDegree,
           double rotateX, double rotateY): Shape(rotateX, rotateY, rotateDegree, color), _cx(cx), _cy(cy), _r(r){
        _totalArea += area();
        _totalPerimeter += perimeter();
    }
    Circle::Circle(double cx, double cy, double r, string color): Shape(color), _cx(cx), _cy(cy), _r(r){
        _totalArea += area();
        _totalPerimeter += perimeter();
    }
    void Circle::set(double cx,double cy,
            double r, string color,
            double rotateDegree,
            double rotateX, double rotateY){
        _cx = cx;
        _cy = cy;
        _r = r;
        _color = color;
        _rotateDegree = rotateDegree;
        _rotateX = rotateX;
        _rotateY = rotateY;
    }
    void Circle::set(double cx, double cy, double r, string color){
        _cx = cx;
        _cy = cy;
        _r = r;
        _color = color;
    }
    double Circle::getX() const{ return _cx; }
    double Circle::getY() const{ return _cy; }
    double Circle::getR() const{ return _r; }
    void Circle::draw(ostream& outputStream) const noexcept{
        outputStream << "\n  <circle cx = '" + to_string(_cx) + "' cy = '" + to_string(_cy) +
                        "' " + "r = '" + to_string(_r) + "' fill = '" + _color + "' transform = 'rotate("
                        + to_string(_rotateDegree) + " "
                        + to_string(_rotateX) + " "
                        + to_string(_rotateY) + " "
                        + ")' />";
    }
    double Circle::area() const noexcept{ return (PI * _r * _r);}
    double Circle::perimeter() const noexcept{ return (2 * PI * _r);}
    const Circle& Circle::operator ++(int) noexcept{
        Circle *temp = new Circle(_cx++, _cy++, _r, _color, _rotateDegree, _rotateX, _rotateY);
        return *temp;
    }
    const Circle& Circle::operator ++() noexcept{
        _cx++;
        _cy++;
        return *this;
    }
    const Circle& Circle::operator --(int){
        if(_cx - 1 < 0 || _cy - 1 < 0)
            throw shapeException("Negative coordinate!");
        Circle *temp = new Circle(_cx--, _cy--, _r, _color, _rotateDegree, _rotateX, _rotateY);
        return *temp;
    }
    //THERE HAVE TO BE THROW EXCEPTION
    const Circle& Circle::operator --(){
        if(_cx - 1 < 0 || _cy - 1 < 0)
            throw shapeException("Negative coordinate!");
        _cx--;
        _cy--;
        return *this;
    }
    bool Circle::operator ==(const Circle& rightSide) noexcept{
        return (this->area() == rightSide.area());
    }
    bool Circle::operator !=(const Circle& rightSide) noexcept{
        return !(this->area() == rightSide.area());
    }
    bool Circle::operator <(const Circle& rightSide) noexcept{
        return (this->area() < rightSide.area());
    }
    bool Circle::operator >(const Circle& rightSide) noexcept{
        return (this->area() > rightSide.area());
    }
    bool Circle::operator <=(const Circle& rightSide) noexcept{
        return (this->area() <= rightSide.area());
    }
    bool Circle::operator >=(const Circle& rightSide) noexcept{
        return (this->area() >= rightSide.area());
    }
    double Circle::getTotalArea(){ return _totalArea; }
    double Circle::getTotalPerimeter(){ return _totalPerimeter; }
    Circle::~Circle(){}
}
