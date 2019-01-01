#ifndef POLGONVECT_H
#define POLYGONVECT_H
#include"Polygon.h"

namespace shape{
    class PolygonVect: public Polygon{
    public:
         PolygonVect();
         //no parameter constructor that initializes the shape array size to 1. _rotateDegree, _rotateX, _rotateY, _rotateDegree to 0
         //and color to red
         PolygonVect(vector<Point2D> point);
         //takes vector of Point2D objects to represent the PolygonVect points. Enlarge accoring to size of the point vector
         PolygonVect(const Point2D& point);
         //takes Point2D object as parameters
         PolygonVect(const Rectangle& rectangle);
         //takes Rectangle object then converts it to PolygonVect
         PolygonVect(const Triangle& triangle);
         //takes Rectangle object then converts it to PolygonVect
         PolygonVect(const Circle& circle);
         //takes Circle object then converts it to PolygonVect
         virtual void displayPoints() const;
         //displays the points
         virtual Point2D& operator [](int index);
         //overloads [] operator for PolygonVect objects arrays
         virtual double area() const noexcept;
         //pure virtual area function that returns the area of the PolygonVect
         virtual double perimeter() const noexcept;
         //pure virtual perimeter function that returns the perimeter of the PolygonVect
         virtual PolygonVect& operator +(const PolygonVect& polygonVect);
         //binary + operator overload for PolygonVect objects
         virtual const PolygonVect& operator ++(int) noexcept;
         //virtual overloaded post increment operator that returns PolygonVect reference
         virtual const PolygonVect& operator ++() noexcept;
         //virtual overloaded pre increment operator that returns PolygonVect reference
         virtual const PolygonVect& operator --(int) noexcept;
         //virtual overloaded post decrement operator that returns PolygonVect reference
         virtual const PolygonVect& operator --() noexcept;
         //virtual overloaded pre decrement operator that returns PolygonVect reference
         virtual void draw(ostream& outputStream) const noexcept;
         //virtual overloaded draw operator that is void
         bool operator ==(const PolygonVect& rightSide) noexcept;
         //overloaded == operator returns bool
         bool operator !=(const PolygonVect& rightSide) noexcept;
         //overloaded != operator returns bool
         ~PolygonVect();
    private:
        vector<Polygon::Point2D> shapes;
    };
}

#endif
