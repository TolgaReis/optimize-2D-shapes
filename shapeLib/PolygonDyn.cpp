#include"PolygonDyn.h"

namespace shape{
    PolygonDyn::PolygonDyn(): Polygon(){
        _size = 1;
        shapes = new Point2D;
    }
    //no parameter constructor that initializes the shape array size to 1. _rotateDegree, _rotateX, _rotateY, _rotateDegree to 0
    //and color to red
    PolygonDyn::PolygonDyn(const PolygonDyn& polygonDyn): Polygon(){
        _size = polygonDyn._size;
        shapes = new Point2D[_size];
        for(int i = 0; i < _size; i++)
            shapes[i] = polygonDyn.shapes[i];
        _color = polygonDyn._color;
        _rotateDegree = polygonDyn._rotateDegree;
        _rotateX = polygonDyn._rotateX;
        _rotateY = polygonDyn._rotateY;
    }
    //copy constructor of the PolygonDyn class
    PolygonDyn::PolygonDyn(vector<Point2D> point): Polygon(){
        _size = point.size();
        shapes = new Point2D[_size];
        for(int i = 0; i < _size; i++)
            shapes[i] = point[i];
    }
    //takes vector of Point2D objects to represent the PolygonDyn points. Enlarge accoring to size of the point vector
    PolygonDyn::PolygonDyn(const Point2D& point): Polygon(){
        _size = 1;
        shapes = new Point2D[_size];
        shapes[0] = point;
    }
    //takes Point2D object as parameters
    PolygonDyn::PolygonDyn(const Rectangle& rectangle): Polygon(){
        _size = 4;
        shapes = new Point2D[_size];
        shapes[0].setCoordinate(rectangle.getX(), rectangle.getY());
        shapes[1].setCoordinate(rectangle.getX() + rectangle.getWidth(), rectangle.getY());
        shapes[2].setCoordinate(rectangle.getX() + rectangle.getWidth(), rectangle.getY() + rectangle.getHeight());
        shapes[3].setCoordinate(rectangle.getX(), rectangle.getY() + rectangle.getHeight());
        _color = rectangle.getColor();
        _area = rectangle.area();
        _perimeter = rectangle.perimeter();
    }
    //takes Rectangle object then converts it to PolygonDyn
    PolygonDyn::PolygonDyn(const Triangle& triangle){
        _size = 3;
        shapes = new Point2D[_size];
        shapes[0].setCoordinate(triangle.getP1X(), triangle.getP1Y());
        shapes[1].setCoordinate(triangle.getP2X(), triangle.getP2Y());
        shapes[2].setCoordinate(triangle.getP3X(), triangle.getP3Y());
        _rotateDegree = triangle.getRotateDegree();
        _rotateX = triangle.getRotateX();
        _rotateY = triangle.getRotateY();
        _color = triangle.getColor();
        _area = triangle.area();
        _perimeter = triangle.perimeter();
    }
    //takes Rectangle object then converts it to PolygonDyn
    PolygonDyn::PolygonDyn(const Circle& circle){
        _size = 100;
        shapes = new Point2D[_size];
        int i;
        for(i = 0; i < _size; i++)
            shapes[i].setCoordinate(circle.getX() + circle.getR()*cos(5.625*i*circle.getPI()/180),
                                    circle.getY() + circle.getR()*sin(5.625*i*circle.getPI()/180));
           //created with circle formula x = h + rcos(t), y = h + rsin(t)
        _rotateDegree = circle.getRotateDegree();
        _rotateX = circle.getRotateX();
        _rotateY = circle.getRotateY();
        _color = circle.getColor();
        _area = circle.area();
        _perimeter = circle.perimeter();
    }
    //takes Circle object then converts it to PolygonDyn
    void PolygonDyn::displayPoints() const{
        for(int i = 0; i < _size; i++)
            cout << shapes[i].getX() << " " << shapes[i].getY() << " ";
    }
    //displays the points
    Polygon::Point2D& PolygonDyn::operator [](int index){
        if(index >= 0)
            throw shapeException("Index is out of range!");
        return shapes[index];
    }
    //overloads [] operator for PolygonDyn objects arrays
    double PolygonDyn::area() const noexcept{ return _area; }
    //pure  area function that returns the area of the PolygonDyn
    double PolygonDyn::perimeter() const noexcept{ return _perimeter; }
    //pure  perimeter function that returns the perimeter of the PolygonDyn
    PolygonDyn& PolygonDyn::operator +(const PolygonDyn& polygonDyn){
        vector<Polygon::Point2D> buffer;
        int i;
        for(i = 0; i < _size; i++)
            buffer.push_back(shapes[i]);
        for(i = 0; i < polygonDyn._size; i++)
           buffer.push_back(polygonDyn.shapes[i]);
        PolygonDyn *polygon = new PolygonDyn(buffer);
        return *polygon;
    }
    //binary + operator overload for PolygonDyn objects
    const PolygonDyn& PolygonDyn::operator ++(int) noexcept{}
    // overloaded post increment operator that returns PolygonDyn reference
    const PolygonDyn& PolygonDyn::operator ++() noexcept{}
    // overloaded pre increment operator that returns PolygonDyn reference
    const PolygonDyn& PolygonDyn::operator --(int) noexcept{}
    // overloaded post decrement operator that returns PolygonDyn reference
    const PolygonDyn& PolygonDyn::operator --() noexcept{}
    // overloaded pre decrement operator that returns PolygonDyn reference
    void PolygonDyn::draw(ostream& outputStream) const noexcept{
        outputStream << "<polygon transform = 'rotate(" << _rotateDegree << " " << _rotateX << " " << _rotateY << ")' ";
        outputStream << "points = '";
        for(int i = 0; i < _size; i++)
            outputStream << shapes[i].getX() << " " << shapes[i].getY() << " ";
        outputStream << "' fill = '" << _color << "' stroke = ' black' stroke-width = '1' />" << endl;
    }
    // overloaded draw operator that is void
    PolygonDyn& PolygonDyn::operator =(const PolygonDyn& polygonDyn){
        if(_size != polygonDyn._size){
            delete[] shapes;
            _size = polygonDyn._size;
            shapes = new Point2D[_size];
        }
        for(int i = 0; i < _size; i++)
            shapes[i] = polygonDyn.shapes[i];
        _rotateDegree = polygonDyn._rotateDegree;
        _rotateX = polygonDyn._rotateX;
        _rotateY = polygonDyn._rotateY;
        _color = polygonDyn._color;
        return *this;
    }
    //overloads = operator for PolygonDyn objects
    bool PolygonDyn::operator ==(const PolygonDyn& polygonDyn){
        if(polygonDyn._size != _size)
            return false;
        else
            if(_rotateDegree == polygonDyn._rotateDegree &&
               _rotateX == polygonDyn._rotateX &&
               _rotateY == polygonDyn._rotateY &&
               _color == polygonDyn._color)
                for(int i = 0; i < _size ; i++)
                    if(!(shapes[i].getX() == polygonDyn.shapes[i].getX() && shapes[i].getY() == polygonDyn.shapes[i].getY()))
                        return false;
        return true;
    }
    //boolean == operator overload for PolygonDyn objects
    bool PolygonDyn::operator !=(const PolygonDyn& polygonDyn){
        return !(*this==polygonDyn);
    }
    //boolean != operator overload for PolygonDyn objects
    PolygonDyn::~PolygonDyn(){}
    //destructor that frees the allocated memory by shape
}
