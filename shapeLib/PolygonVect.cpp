#include"PolygonVect.h"

namespace shape{
    PolygonVect::PolygonVect(): Polygon(){}
    //no parameter constructor that initializes the shape array size to 1. _rotateDegree, _rotateX, _rotateY, _rotateDegree to 0
    //and color to red
    PolygonVect::PolygonVect(vector<Point2D> point): Polygon(point){
        for(int i = 0; i < point.size(); i++)
            shapes.push_back(point[i]);
    }
    //takes vector of Point2D objects to represent the PolygonVect points. Enlarge accoring to size of the point vector
    PolygonVect::PolygonVect(const Point2D& point): Polygon(point){
        shapes.push_back(point);
    }
    //takes Point2D object as parameters
    PolygonVect::PolygonVect(const Rectangle& rectangle): Polygon(rectangle){
        shapes.push_back(Point2D(rectangle.getX(), rectangle.getY()));
        shapes.push_back(Point2D(rectangle.getX() + rectangle.getWidth(), rectangle.getY()));
        shapes.push_back(Point2D(rectangle.getX() + rectangle.getWidth(), rectangle.getY() + rectangle.getHeight()));
        shapes.push_back(Point2D(rectangle.getX(), rectangle.getY() + rectangle.getHeight()));
        _area = rectangle.area();
        _perimeter = rectangle.perimeter();
    }
    //takes Rectangle object then converts it to PolygonVect
    PolygonVect::PolygonVect(const Triangle& triangle): Polygon(triangle){
        shapes.push_back(Point2D(triangle.getP1X(), triangle.getP1Y()));
        shapes.push_back(Point2D(triangle.getP2X(), triangle.getP2Y()));
        shapes.push_back(Point2D(triangle.getP3X(), triangle.getP3Y()));
        _area = triangle.area();
        _perimeter = triangle.perimeter();
    }
    //takes Rectangle object then converts it to PolygonVect
    PolygonVect::PolygonVect(const Circle& circle): Polygon(circle){
        for(int i = 0; i < 100; i++)
               shapes.push_back(Point2D(circle.getX() + circle.getR()*cos(5.625*i*circle.getPI()/180),
                                      circle.getY() + circle.getR()*sin(5.625*i*circle.getPI()/180)));
           //created with circle formula x = h + rcos(t), y = h + rsin(t)
        _area = circle.area();
        _perimeter = circle.perimeter();
    }
    //takes Circle object then converts it to PolygonVect
    void PolygonVect::displayPoints() const{
        for(int i = 0; i < shapes.size(); i++){
           cout << shapes[i].getX() << " " << shapes[i].getY() << " ";
       }
    }
    //displays the points
    Polygon::Point2D& PolygonVect::operator [](int index){
        if(index >= _size)
            throw shapeException("index is out of range!");
        return shapes[index];
    }
    //overloads [] operator for PolygonVect objects arrays
    double PolygonVect::area() const noexcept{ return _area; }
    //area function that returns the area of the PolygonVect
    double PolygonVect::perimeter() const noexcept{ return _perimeter; }
    //perimeter function that returns the perimeter of the PolygonVect
    PolygonVect& PolygonVect::operator +(const PolygonVect& polygonVect){
        for(int i = 0; i < polygonVect.shapes.size(); i++)
            shapes.push_back(polygonVect.shapes[i]);
    }
    //binary + operator overload for PolygonVect objects
    const PolygonVect& PolygonVect::operator ++(int) noexcept{}
    //virtual overloaded post increment operator that returns PolygonVect reference
    const PolygonVect& PolygonVect::operator ++() noexcept{}
    //virtual overloaded pre increment operator that returns PolygonVect reference
    const PolygonVect& PolygonVect::operator --(int) noexcept{}
    //virtual overloaded post decrement operator that returns PolygonVect reference
    const PolygonVect& PolygonVect::operator --() noexcept{}
    //virtual overloaded pre decrement operator that returns PolygonVect reference
    void PolygonVect::draw(ostream& outputStream) const noexcept{
        outputStream << "<polygon transform = 'rotate(" << _rotateDegree << " " << _rotateX << " " << _rotateY << ")' ";
        outputStream << "points = '";
        for(int i = 0; i < shapes.size(); i++)
            outputStream << shapes[i].getX() << " " << shapes[i].getY() << " ";
        outputStream << "' fill = '" << _color << "' stroke = ' black' stroke-width = '1' />" << endl;
    }
    //virtual overloaded draw operator that is void
    bool PolygonVect::operator ==(const PolygonVect& rightSide) noexcept{
        if(rightSide.shapes.size() != shapes.size())
           return false;
       else
           if(_rotateDegree == rightSide._rotateDegree &&
              _rotateX == rightSide._rotateX &&
              _rotateY == rightSide._rotateY &&
              _color == rightSide._color)
               for(int i = 0; i < _size ; i++)
                   if(!(shapes[i].getX() == rightSide.shapes[i].getX() && shapes[i].getY() == rightSide.shapes[i].getY()))
                       return false;
       return true;
    }
    //overloaded == operator returns bool
    bool PolygonVect::operator !=(const PolygonVect& rightSide) noexcept{
        return !(*this == rightSide);
    }
    //overloaded != operator returns bool
    PolygonVect::~PolygonVect(){}
}
