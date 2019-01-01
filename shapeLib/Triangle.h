/*
*Triangle class that is derived from Shape class
*has properties of a Triangle
*/
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include"Shape.h"
using namespace std;

namespace shape{
    class Triangle: public Shape{
    public:
        Triangle();
        //no parameter constructor
        Triangle(double p1x, double p1y,
                 double p2x, double p2y,
                 double p3x, double p3y,
                 string color, double rotateDegree,
                 double rotateX, double rotateY, double side);
        //second triangle constructor
        Triangle(double p1x, double p1y,
                 double p2x, double p2y,
                 double p3x, double p3y,
                 string color, double side);
        //third triangle constructor
        void set(double p1x, double p1y,
                 double p2x, double p2y,
                 double p3x, double p3y,
                 string color, double rotateDegree,
                 double rotateX, double rotateY, double side);
        //first setter
        void set(double p1x, double p1y,
                 double p2x, double p2y,
                 double p3x, double p3y,
                 string color, double side);
        //second setter
        void set(double p1x, double p1y,
                 double p2x, double p2y,
                 double p3x, double p3y,
                 string color);
        //third setter
        void set(double rotateDegree,
                 double rotateX, double rotateY);
        //rotation setter
        double getP1X() const;
        //returns point 1 x coordinate
        double getP1Y() const;
        //returns point 1 y coordinate
        double getP2X() const;
        //returns point 2 x coordinate
        double getP2Y() const;
        //returns point 2 y coordinate
        double getP3X() const;
        //returns point 3 x coordinate
        double getP3Y() const;
        //returns point 3 y coordinate
        double getSide() const;
        //returns side of the triangle
        virtual void draw(ostream& outputStream) const noexcept override;
        //inherited draw function
        virtual double area() const noexcept override;
        //returns the area of the triangle
        virtual double perimeter() const noexcept override;
        //returns the perimeter of the triangle
        virtual const Triangle& operator ++() noexcept override;
        //overloaded pre increment operator that returns the triangle reference
        virtual const Triangle& operator ++(int) noexcept override;
        //overloaded post increment operator that returns the triangle reference
        virtual const Triangle& operator --() override;
        //overloaded pre decrement operator that returns the triangle reference
        virtual const Triangle& operator --(int) override;
        //overloaded post decrement operator that returns the triangle reference
        bool operator ==(const Triangle& rightSide) noexcept;
        //overloaded boolean == operator
        bool operator !=(const Triangle& rightSide) noexcept;
        //overloaded boolean != operator
        bool operator <(const Triangle& rightSide) noexcept;
        //overloaded boolean < operator
        bool operator >(const Triangle& rightSide) noexcept;
        //overloaded boolean > operator
        bool operator <=(const Triangle& rightSide) noexcept;
        //overloaded boolean <= operator
        bool operator >=(const Triangle& rightSide) noexcept;
        //overloaded boolean >= operator
        static double getTotalArea();
        //static getter of the _totalArea
        static double getTotalPerimeter();
        //static getter of the _totalPerimeter
        ~Triangle();
    private:
        double _p1x, _p1y,
               _p2x, _p2y,
               _p3x, _p3y, _side;
        static double _totalArea;
        static double _totalPerimeter;
    };
}

#endif
