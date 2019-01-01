#ifndef POLYGON_H
#define POLYGON_H
#include<cmath>
#include"Shape.h"
#include"Rectangle.h"
#include"Triangle.h"
#include"Circle.h"
using namespace std;

namespace shape{
    class Polygon: public Shape{
       public:
          class Point2D{
           private:
               double _x, _y;
           public:
               Point2D(): _x(0), _y(0){/*intentionally empty*/}
               //no parameter constructor that initializes x and y
               Point2D(double x, double y): _x(x), _y(y){/*intentionally empty*/}
               //takes two parameter x and y and initializes the object point
               double getX() const{ return _x; }
               //getter function for x coordinate
               double getY() const{ return _y; }
               //getter function for y coordinate
               void setCoordinate(double x, double y){ _x = x; _y = y; }
               //setter function for x and y coordinate
           };
           //inner class that holds point coordinates
           Polygon(): Shape(), _size(1){}
           //no parameter constructor that initializes the shape array size to 1. _rotateDegree, _rotateX, _rotateY, _rotateDegree to 0
           //and color to red
           Polygon(const Polygon& polygon);
           //copy constructor of the Polygon class
           Polygon(vector<Point2D> point);
           //takes vector of Point2D objects to represent the Polygon points. Enlarge accoring to size of the point vector
           Polygon(const Point2D& point);
           //takes Point2D object as parameters
           Polygon(const Rectangle& rectangle);
           //takes Rectangle object then converts it to polygon
           Polygon(const Triangle& triangle);
           //takes Rectangle object then converts it to polygon
           Polygon(const Circle& circle);
           //takes Circle object then converts it to polygon
           const int getSize() const;
           //getter of the size of the shape array of polygon
           virtual void displayPoints() const = 0;
           //displays the points
           virtual double area() const noexcept = 0;
           //pure virtual area function that returns the area of the polygon
           virtual double perimeter() const noexcept = 0;
           //pure virtual perimeter function that returns the perimeter of the polygon
           virtual const Polygon& operator ++(int) noexcept = 0;
           //virtual overloaded post increment operator that returns polygon reference
           virtual const Polygon& operator ++() noexcept = 0;
           //virtual overloaded pre increment operator that returns polygon reference
           virtual const Polygon& operator --(int) noexcept = 0;
           //virtual overloaded post decrement operator that returns polygon reference
           virtual const Polygon& operator --() noexcept = 0;
           //virtual overloaded pre decrement operator that returns polygon reference
           virtual void draw(ostream& outputstream) const noexcept = 0;
           //virtual overloaded draw operator that is void
           bool operator ==(const Polygon& rightSide) noexcept;
           //overloaded == operator returns bool
           bool operator !=(const Polygon& rightSide) noexcept;
           //overloaded != operator returns bool
           bool operator <(const Polygon& rightSide) noexcept;
           //overloaded < operator returns bool
           bool operator >(const Polygon& rightSide) noexcept;
           //overloaded > operator returns bool
           bool operator <=(const Polygon& rightSide) noexcept;
           //overloaded <= operator returns bool
           bool operator >=(const Polygon& rightSide) noexcept;
           //overloaded >= operator returns bool
           ~Polygon();
           //destructor that frees the allocated memory by shape
       protected:
           int _size;
           double _area = 0, _perimeter = 0;
       };
}

#endif
