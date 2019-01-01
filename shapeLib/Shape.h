/*
*Abstract Shape class that other shapes derived from
*has some common operator overloads and functions
*/
#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"shapeException.h"
using namespace std;

namespace shape{
    class Shape{
    public:
        Shape();
        //no parameter constructor
        Shape(double rotateX, double rotateY, double rotateDegree, string color);
        //second constructor
        Shape(string color);
        //third constructor
        virtual double area() const noexcept = 0;
        //pure virtual area function that returns the area of the shape
        virtual double perimeter() const noexcept = 0;
        //pure virtual perimeter function that returns the perimeter of the shape
        double getRotateDegree() const;
        //returns the rotate degree
        double getRotateX() const;
        //returns rotate x coordinate
        double getRotateY() const;
        //returns rotate y coordinate;
        double getPI() const;
        //returns the PI number
        string getColor() const;
        //returns the color
        virtual const Shape& operator ++(int) noexcept = 0;
        //virtual overloaded post increment operator that returns shape reference
        virtual const Shape& operator ++() noexcept = 0;
        //virtual overloaded pre increment operator that returns shape reference
        virtual const Shape& operator --(int) = 0;
        //virtual overloaded post decrement operator that returns shape reference
        virtual const Shape& operator --() = 0;
        //virtual overloaded pre decrement operator that returns shape reference
        virtual void draw(ostream& outputstream) const noexcept = 0;
        //virtual overloaded draw operator that is void
        virtual bool operator ==(const Shape& rightSide) noexcept;
        //overloaded == operator returns bool
        virtual bool operator !=(const Shape& rightSide) noexcept;
        //overloaded != operator returns bool
        bool operator <(const Shape& rightSide) noexcept;
        //overloaded < operator returns bool
        bool operator >(const Shape& rightSide) noexcept;
        //overloaded > operator returns bool
        bool operator <=(const Shape& rightSide) noexcept;
        //overloaded <= operator returns bool
        bool operator >=(const Shape& rightSide) noexcept;
        //overloaded >= operator returns bool
        virtual ~Shape();
    protected:
        double _rotateX, _rotateY,
               _rotateDegree, PI = 3.1414, SQRT3 = 1.732;
        string _color;
    };
}

#endif
