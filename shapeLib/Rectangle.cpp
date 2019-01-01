#include"Rectangle.h"

namespace shape{
    double Rectangle::_totalArea = 0;
    //initializes the static total area
    double Rectangle::_totalPerimeter = 0;
    //initializes the static total perimeter
    Rectangle::Rectangle(): Shape(), _x(0), _y(0), _width(0), _height(0){}
    Rectangle::Rectangle(double width, double height, string color): Shape(color), _x(0), _y(0), _width(width), _height(height){
        _totalArea += area();
        _totalPerimeter += perimeter();
    }
    Rectangle::Rectangle(double x, double y, double width, double height, string color)
    : Shape(color), _x(x), _y(y), _width(width), _height(height){
        _totalArea += area();
        _totalPerimeter += perimeter();
    }
    void Rectangle::set(double width, double height, string color){
        _width = width;
        _height = height;
        _color = color;
    }
    void Rectangle::set(double x, double y, double width, double height, string color){
        _x = x;
        _y = y;
        _width = width;
        _height = height;
        _color = color;
    }
    double Rectangle::getWidth() const{ return _width; }
    double Rectangle::getHeight() const{ return _height; }
    double Rectangle::getX() const{ return _x; }
    double Rectangle::getY() const{ return _y; }
    void Rectangle::draw(ostream& outputStream) const noexcept{
        outputStream << "\n  <rect x = '" + to_string(_x) + "' y = '" + to_string(_y) +
                        "' width = '" + to_string(_width) + "' height = '" + to_string(_height) +
                        "' style = 'fill: " + _color + ";  stroke: black' />";
    }
    double Rectangle::area() const noexcept{
        return _width *_height;
    }
    double Rectangle::perimeter() const noexcept{
        return (_width + _height) * 2;
    }
    double Rectangle::getTotalArea(){
        return _totalArea;
    }
    double Rectangle::getTotalPerimeter(){
        return _totalPerimeter;
    }
    const Rectangle& Rectangle::operator ++(int) noexcept{
        Rectangle *temp = new Rectangle(_x++, _y++, _width, _height, _color);
        return *temp;
    }
    const Rectangle& Rectangle::operator ++() noexcept{
        _x++;
        _y++;
        return *this;
    }
    const Rectangle& Rectangle::operator --(int){
        if(_x - 1 < 0 || _y - 1 < 0)
            throw shapeException("Negative coordinate!");
        Rectangle *temp = new Rectangle(_x--, _y--, _width, _height, _color);
        return *temp;
    }
    const Rectangle& Rectangle::operator --(){
        if(_x - 1 < 0 || _y - 1 < 0)
            throw shapeException("Negative coordinate!");
        _x--;
        _y--;
        return *this;
    }
    bool Rectangle::operator ==(const Rectangle& rightSide){
        return (this->area() == rightSide.area());
    }
    //THERE HAVE TO BE THROW EXCEPTION
    bool Rectangle::operator !=(const Rectangle& rightSide){
        return !(this->area() == rightSide.area());
    }
    //THERE HAVE TO BE THROW EXCEPTION
    bool Rectangle::operator <(const Rectangle& rightSide){
        return (this->area() < rightSide.area());
    }
    //THERE HAVE TO BE THROW EXCEPTION
    bool Rectangle::operator >(const Rectangle& rightSide){
        return (this->area() > rightSide.area());
    }
    //THERE HAVE TO BE THROW EXCEPTION
    bool Rectangle::operator <=(const Rectangle& rightSide){
        return (this->area() <= rightSide.area());
    }
    //THERE HAVE TO BE THROW EXCEPTION
    bool Rectangle::operator >=(const Rectangle& rightSide){
        return (this->area() >= rightSide.area());
    }
    //THERE HAVE TO BE THROW EXCEPTION
    Rectangle::~Rectangle(){}
}
