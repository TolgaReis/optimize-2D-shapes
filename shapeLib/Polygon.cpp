#include"Polygon.h"

namespace{
    bool isValidCoordinate(double x, double y, double limit){
        return (x >= limit && y >= limit);
    }
    //checks whether given coordinate is valid or not accoring to limit
    bool isValidRotate(double degree, double mod){
        return ((degree >= 0 && degree <= 360) && static_cast<int>(degree) % 60 == 0);
    }
    //checks whether rotate operation is valid or not
}
//this unnamed namespace includes check functions for polygon class

namespace shape{
    Polygon::Polygon(const Polygon& polygon): Shape(polygon._rotateX, polygon._rotateY, polygon._rotateDegree, polygon._color),
                                              _size(polygon._size){}
    Polygon::Polygon(vector<Point2D> point):  Shape(){}
    Polygon::Polygon(const Point2D& point): Shape(){}
    Polygon::Polygon(const Rectangle& rectangle):  Shape(0, 0, 0, rectangle.getColor()){}
    Polygon::Polygon(const Triangle& triangle): Shape(triangle.getRotateDegree(), triangle.getRotateX(),
                                                      triangle.getRotateY(), triangle.getColor()){}
    Polygon::Polygon(const Circle& circle): Shape(circle.getRotateDegree(), circle.getRotateX(),
                                                circle.getRotateY(), circle.getColor()){}
    const int Polygon::getSize() const{ return _size; }
    Polygon::~Polygon(){
    }
}
