/*
*Circle class that is derived from Shape class
*has properties of a Circle
*/
#ifndef CIRCLE_H
#define CIRCLE_H
#include"Shape.h"
using namespace std;

namespace shape{
    class Circle: public Shape{
    public:
        Circle();
        //no parameter constructor
        Circle(double cx,double cy,
               double r, string color,
               double rotateDegree,
               double rotateX, double rotateY);
        //full constructor
        Circle(double cx, double cy, double r, string color);
        //x, y, radius and color constructor
        void set(double cx,double cy,
                double r, string color,
                double rotateDegree,
                double rotateX, double rotateY);
        //setter for first constructor
        void set(double cx, double cy, double r, string color);
        //setter for second constructor
        double getX() const;
        //getter for x
        double getY() const;
        //getter for y
        double getR() const;
        //getter for radius
        virtual void draw(ostream& outputStream) const noexcept;
        //draw function
        virtual double area() const noexcept override;
        //returns the area of the Circle
        virtual double perimeter() const noexcept override;
        //returns the perimeter of the Circle
        virtual const Circle& operator ++(int) noexcept override;
        //virtual overloaded post increment operator that returns Circle reference
        virtual const Circle& operator ++() noexcept override;
        //virtual overloaded pre increment operator that returns Circle reference
        virtual const Circle& operator --(int) override;
        //THERE HAVE TO BE THROW EXCEPTION
        virtual const Circle& operator --() override;
        //THERE HAVE TO BE THROW EXCEPTION
        bool operator ==(const Circle& rightSide) noexcept;
        //overloaded boolean == operator
        bool operator !=(const Circle& rightSide) noexcept;
        //overloaded boolean != operator
        bool operator <(const Circle& rightSide) noexcept;
        //overloaded boolean < operator
        bool operator >(const Circle& rightSide) noexcept;
        //overloaded boolean > operator
        bool operator <=(const Circle& rightSide) noexcept;
        //overloaded boolean <= operator
        bool operator >=(const Circle& rightSide) noexcept;
        //overloaded boolean >= operator
        static double getTotalArea();
        //static getter of the _totalArea
        static double getTotalPerimeter();
        //static getter of the _totalPerimeter
        ~Circle();
    private:
        double _cx, _cy, _r, PI = 3.1414;
        static double _totalArea;
        static double _totalPerimeter;
    };
}

#endif
