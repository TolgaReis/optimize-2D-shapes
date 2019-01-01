/*
*ComposedShape class that is derived from Shape class. It composes two shapes
*/
#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H
#include"Shape.h"
#include"Rectangle.h"
#include"Triangle.h"
#include"Circle.h"
using namespace std;

namespace shape{
    class ComposedShape: public Shape{
    public:
        enum ShapeType{R, T, C};
        ComposedShape(){/*intentionally empty*/}
        //no paramater constructor
        ComposedShape(Rectangle containerRectangle, Rectangle smallRectangle,
                      Triangle containerTriangle, Triangle smallTriangle,
                      Circle containerCircle, Circle smallCircle)
        : Shape(), _cRectangle(containerRectangle), _sRectangle(smallRectangle),
                   _cTriangle(containerTriangle), _sTriangle(smallTriangle),
                   _cCircle(containerCircle), _sCircle(smallCircle){}
        ComposedShape(Rectangle containerRectangle, Rectangle smallRectangle)
        : Shape(), _cRectangle(containerRectangle), _sRectangle(smallRectangle)
        { containerShape = R; smallShape = R; }
        //constructor to fit rectangle inside rectangle
        ComposedShape(Rectangle rectangle, Triangle triangle)
        : Shape(), _cRectangle(rectangle), _sTriangle(triangle)
        { containerShape = R; smallShape = T; }
        //constructor to fit triangle inside rectangle
        ComposedShape(Rectangle rectangle, Circle circle)
        : Shape(), _cRectangle(rectangle), _sCircle(circle)
        { containerShape = R; smallShape = C; }
        //constructor to fit circle inside rectangle
        ComposedShape(Triangle triangle, Rectangle rectangle)
        : Shape(), _cTriangle(triangle), _sRectangle(rectangle)
        { containerShape = T; smallShape = R; }
        //constructor to fit rectangle inside triangle
        ComposedShape(Triangle containerTriangle, Triangle smallTriangle)
        : Shape(), _cTriangle(containerTriangle), _sTriangle(smallTriangle)
        { containerShape = T; smallShape = T; }
        //constructor to fit triangle inside triangle
        ComposedShape(Triangle triangle, Circle circle)
        : Shape(), _cTriangle(triangle), _sCircle(circle)
        { containerShape = T; smallShape = C; }
        //constructor to fit circle inside triangle
        ComposedShape(Circle circle, Rectangle rectangle)
        : Shape(), _cCircle(circle), _sRectangle(rectangle)
        { containerShape = C; smallShape = R; }
        //constructor to fit rectangle inside circle
        ComposedShape(Circle circle, Triangle triangle)
        : Shape(), _cCircle(circle), _sTriangle(triangle)
        { containerShape = C; smallShape = T; }
        //constructor to fit triangle inside circle
        ComposedShape(Circle containerCircle, Circle smallCircle)
        : Shape(), _cCircle(containerCircle), _sCircle(smallCircle)
        { containerShape = C; smallShape = C; }
        //constructor to fit circle inside circle

        void set(Rectangle containerRectangle, Rectangle smallRectangle)
        { _cRectangle = containerRectangle; _sRectangle = smallRectangle; containerShape = R; smallShape = R; }
        //setter to fit rectangle inside rectangle
        void set(Rectangle rectangle, Triangle triangle)
        { _cRectangle = rectangle; _sTriangle = triangle; containerShape = R; smallShape = T; }
        //setter to fit triangle inside rectangle
        void set(Rectangle rectangle, Circle circle)
        { _cRectangle = rectangle; _sCircle = circle; containerShape = R; smallShape = C; }
        //setter to fit circle inside rectangle
        void set(Triangle triangle, Rectangle rectangle)
        {_cTriangle = triangle; _sRectangle = rectangle; containerShape = T; smallShape = R; }
        //setter to fit rectangle inside triangle
        void set(Triangle containerTriangle, Triangle smallTriangle)
        { _cTriangle = containerTriangle; _sTriangle = smallTriangle; containerShape = T; smallShape = T; }
        //setter to fit triangle inside triangle
        void set(Triangle triangle, Circle circle)
        { _cTriangle = triangle; _sCircle = circle; containerShape = T; smallShape = C; }
        //setter to fit circle inside triangle
        void set(Circle circle, Rectangle rectangle)
        { _cCircle = circle; _sRectangle = rectangle; containerShape = C; smallShape = R; }
        //setter to fit rectangle inside circle
        void set(Circle circle, Triangle triangle)
        { _cCircle = circle; _sTriangle = triangle; containerShape = C; smallShape = T; }
        //setter to fit triangle inside circle
        void set(Circle containerCircle, Circle smallCircle)
        {_cCircle = containerCircle;_sCircle = smallCircle; containerShape = C; smallShape = C; }
        //setter to fit circle inside circle

        void optimalFit(Rectangle containerRectangle, Rectangle smallRectangle);
        //optimization for small rectangle inside rectangle
        void optimalFit(Rectangle rectangle, Triangle triangle);
        //optimization for small triangle inside rectangle
        void optimalFit(Rectangle rectangle, Circle circle);
        //optimization for small circle inside rectangle
        void optimalFit(Triangle triangle, Rectangle rectangle);
        //optimization for small rectangle inside triangle
        void optimalFit(Triangle containerTriangle, Triangle smallTriangle);
        //optimization for small triangle inside triangle
        void optimalFit(Triangle triangle, Circle circle);
        //optimization for small circle inside triangle
        void optimalFit(Circle circle, Rectangle rectangle);
        //optimization for small rectangle inside circle
        void optimalFit(Circle circle, Triangle triangle);
        //optimization for small triangle inside circle
        void optimalFit(Circle containerCircle, Circle smallCircle);
        //optimization for small circle inside circle

        vector<Shape*> getShape(){ return shapes; }
        //returns the shape vector
        virtual double area() const noexcept override;
        //returns the area of the ComposedShape
        virtual double perimeter() const noexcept override;
        //returns the perimeter of the composedShape
        virtual const ComposedShape& operator ++(int) noexcept override;
        //virtual overloaded post increment operator that returns ComposedShape reference
        virtual const ComposedShape& operator ++() noexcept override;
        //virtual overloaded pre increment operator that returns ComposedShape reference
        virtual const ComposedShape& operator --(int)override;
        //THERE HAVE TO BE THROW EXCEPTION
        virtual const ComposedShape& operator --()override;
        //THERE HAVE TO BE THROW EXCEPTION
        ComposedShape& operator +=(const Rectangle& rectangle);
        //overloads += to add rectangle to this composedShape
        ComposedShape& operator +=(const Triangle& triangle);
        //overloads += to add triangle to this composedShape
        ComposedShape& operator +=(const Circle& circle);
        //overloads += to add circle to this composedShape
        bool operator ==(const ComposedShape& composedShape) noexcept;
        //overloaded boolean == operator
        bool operator !=(const ComposedShape& composedShape) noexcept;
        //overloaded boolean != operator
        bool operator <(const ComposedShape& composedShape) noexcept;
        //overloaded boolean < operator
        bool operator >(const ComposedShape& composedShape) noexcept;
        //overloaded boolean > operator
        bool operator <=(const ComposedShape& composedShape) noexcept;
        //overloaded boolean <= operator
        bool operator >=(const ComposedShape& composedShape) noexcept;
        //overloaded boolean >= operator
        virtual void draw(ostream& outputStream) const noexcept;
        //draw function for small rectangle inside rectangle
        friend ostream& operator <<(ostream& outputStream, const ComposedShape& composedShape);
        ~ComposedShape();
    private:
        Rectangle _cRectangle, _sRectangle;
        Triangle _cTriangle, _sTriangle;
        Circle _cCircle, _sCircle;
        ShapeType containerShape;
        ShapeType smallShape;
        vector<Shape*> shapes;
        const double SQRT2 = 1.414;
    };
}

#endif
