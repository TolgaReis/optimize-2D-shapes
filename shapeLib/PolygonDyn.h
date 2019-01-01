#ifndef POLYGONDYN_H
#define POLYGONDYN_H
#include"Polygon.h"

namespace shape{
    class PolygonDyn: public Polygon{
    public:
        PolygonDyn();
        //no parameter constructor that initializes the shape array size to 1. _rotateDegree, _rotateX, _rotateY, _rotateDegree to 0
        //and color to red
        PolygonDyn(const PolygonDyn& PolygonDyn);
        //copy constructor of the PolygonDyn class
        PolygonDyn(vector<Point2D> point);
        //takes vector of Point2D objects to represent the PolygonDyn points. Enlarge accoring to size of the point vector
        PolygonDyn(const Point2D& point);
        //takes Point2D object as parameters
        PolygonDyn(const Rectangle& rectangle);
        //takes Rectangle object then converts it to PolygonDyn
        PolygonDyn(const Triangle& triangle);
        //takes Rectangle object then converts it to PolygonDyn
        PolygonDyn(const Circle& circle);
        //takes Circle object then converts it to PolygonDyn
        virtual void displayPoints() const override;
        //displays the points
        virtual Point2D& operator [](int index);
        //overloads [] operator for PolygonDyn objects arrays
        virtual double area() const noexcept override;
        //pure virtual area function that returns the area of the PolygonDyn
        virtual double perimeter() const noexcept override;
        //pure virtual perimeter function that returns the perimeter of the PolygonDyn
        virtual const PolygonDyn& operator ++(int) noexcept override;
        //virtual overloaded post increment operator that returns PolygonDyn reference
        virtual const PolygonDyn& operator ++() noexcept override;
        //virtual overloaded pre increment operator that returns PolygonDyn reference
        virtual const PolygonDyn& operator --(int) noexcept override;
        //virtual overloaded post decrement operator that returns PolygonDyn reference
        virtual const PolygonDyn& operator --() noexcept override;
        //virtual overloaded pre decrement operator that returns PolygonDyn reference
        virtual void draw(ostream& outputStream) const noexcept override;
        //virtual overloaded draw operator that is void
        PolygonDyn& operator =(const PolygonDyn& PolygonDyn);
        //overloads = operator for PolygonDyn objects
        bool operator ==(const PolygonDyn& PolygonDyn);
        //boolean == operator overload for PolygonDyn objects
        bool operator !=(const PolygonDyn& PolygonDyn);
        //boolean != operator overload for PolygonDyn objects
        PolygonDyn& operator +(const PolygonDyn& PolygonDyn);
        //binary + operator overload for PolygonDyn objects
        ~PolygonDyn();
        //destructor that frees the allocated memory by shape
    private:
        Point2D *shapes;
    };
}

#endif
