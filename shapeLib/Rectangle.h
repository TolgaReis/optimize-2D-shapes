/*
*Rectangle class that is derived from Shape class
*has properties of a rectangle
*/
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include"Shape.h"
using namespace std;

namespace shape{
    class Rectangle: public Shape{
    public:
        Rectangle();
        //no parameter constructor
        Rectangle(double width, double height, string color);
        //constructor that takes only width, height and color
        Rectangle(double x, double y, double width, double height, string color);
        //constructor that takes width, height, color and coordinates
        void set(double width, double height, string color);
        //setter as second constructor
        void set(double x, double y, double width, double height, string color);
        //setter as third constructor
        double getWidth() const;
        //getter of width
        double getHeight() const;
        //getter of height
        double getX() const;
        //getter of x
        double getY() const;
        //getter of y
        virtual void draw(ostream& outputStream) const noexcept override;
        //inherited draw function
        virtual double area() const noexcept override;
        //inherited area function
        virtual double perimeter() const noexcept override;
        //inherited perimeter function
        static double getTotalArea();
        //getter of static total area that returns all the area of Rectangles created so far
        static double getTotalPerimeter();
        //getter of static total perimeter that returns the perimeter of Rectangles created so far
        virtual const Rectangle& operator ++(int) noexcept override;
        //overloaded post increment operator that returns constant reference
        virtual const Rectangle& operator ++() noexcept override;
        //overloaded pre increment operator that returns constant reference
        virtual const Rectangle& operator --(int) override;
        //overloaded post decrement operator that returns constant reference
        virtual const Rectangle& operator --() override;
        //overloaded pre decrement operator that returns constant reference
        bool operator ==(const Rectangle& rightSide);
        //overloaded bool == operator
        bool operator !=(const Rectangle& rightSide);
        //overloaded bool != operator
        bool operator <(const Rectangle& rightSide);
        //overloaded bool < operator
        bool operator >(const Rectangle& rightSide);
        //overloaded bool > operator
        bool operator <=(const Rectangle& rightSide);
        //overloaded bool <= operator
        bool operator >=(const Rectangle& rightSide);
        //overloaded bool >= operator
        ~Rectangle();
    private:
        double _width, _height,
               _x, _y;
        static double _totalArea;
        static double _totalPerimeter;
    };
}

#endif
