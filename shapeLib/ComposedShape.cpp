#include"ComposedShape.h"

namespace shape{
    double ComposedShape::area() const noexcept{
        double area = 0;
        for(Shape* i : shapes){
            if(dynamic_cast<Rectangle*>(i)){
                Rectangle *rectangle = dynamic_cast<Rectangle*>(i);
                area += rectangle->area();
            }
            else if(dynamic_cast<Triangle*>(i)){
                Triangle *triangle = dynamic_cast<Triangle*>(i);
                area += triangle->area();
            }
            else if(dynamic_cast<Circle*>(i)){
                Circle *circle = dynamic_cast<Circle*>(i);
                area +=circle->area();
            }
        }
    }
    double ComposedShape::perimeter() const noexcept{
        double perimeter = 0;
        for(Shape* i : shapes){
            if(dynamic_cast<Rectangle*>(i)){
                Rectangle *rectangle = dynamic_cast<Rectangle*>(i);
                perimeter += rectangle->perimeter();
            }
            else if(dynamic_cast<Triangle*>(i)){
                Triangle *triangle = dynamic_cast<Triangle*>(i);
                perimeter += triangle->perimeter();
            }
            else if(dynamic_cast<Circle*>(i)){
                Circle *circle = dynamic_cast<Circle*>(i);
                perimeter +=circle->perimeter();
            }
        }
    }
    const ComposedShape& ComposedShape::operator ++(int) noexcept{
        ComposedShape *composedShape = new ComposedShape(_cRectangle++, _sRectangle++,
                                                         _cTriangle++, _sTriangle++,
                                                         _cCircle++, _sCircle++);
        return *composedShape;
    }
    const ComposedShape& ComposedShape::operator ++() noexcept{
        _cRectangle++;
        _sRectangle++;
        _cTriangle++;
        _sTriangle++;
        _cCircle++;
        _sCircle++;
        return *this;
    }
    //virtual overloaded pre increment operator that returns shape reference
    const ComposedShape& ComposedShape::operator --(int){
        ComposedShape *composedShape = new ComposedShape(_cRectangle--, _sRectangle--,
                                                         _cTriangle--, _sTriangle--,
                                                         _cCircle--, _sCircle--);
        return *composedShape;
    }
    //shape classes throw exceptions
    const ComposedShape& ComposedShape::operator --(){
        _cRectangle--;
        _sRectangle--;
        _cTriangle--;
        _sTriangle--;
        _cCircle--;
        _sCircle--;
        return *this;
    }
    //shape classes throw exceptions
    void ComposedShape::draw(ostream& outputStream) const noexcept{
        int i;
        for(Shape* i : shapes){
            if(dynamic_cast<Rectangle*>(i)){
                Rectangle *rectangle = dynamic_cast<Rectangle*>(i);
                rectangle->draw(outputStream);
            }
            else if(dynamic_cast<Triangle*>(i)){
                Triangle *triangle = dynamic_cast<Triangle*>(i);
                triangle->draw(outputStream);
            }
            else if(dynamic_cast<Circle*>(i)){
                Circle *circle = dynamic_cast<Circle*>(i);
                circle->draw(outputStream);
            }
        }
    }
    //draw function for small rectangle inside rectangle
    void ComposedShape::optimalFit(Rectangle containerRectangle, Rectangle smallRectangle){
    int rowNumber,
        columnNumber,
        i, j;
    shapes.push_back(new Rectangle(containerRectangle.getX(), containerRectangle.getY(),
                     containerRectangle.getWidth(), containerRectangle.getHeight(), "red"));
    if(((containerRectangle.getHeight() / smallRectangle.getHeight()) * (containerRectangle.getWidth() / smallRectangle.getWidth())) >=
        ((containerRectangle.getHeight() / smallRectangle.getWidth()) * (containerRectangle.getWidth() / smallRectangle.getHeight()))){
        rowNumber = containerRectangle.getHeight() / smallRectangle.getHeight();
        columnNumber = containerRectangle.getWidth() / smallRectangle.getWidth();

        for(i = 0; i < rowNumber; i++)
            for(j = 0; j < columnNumber; j++){
                smallRectangle.set(smallRectangle.getWidth() * j, smallRectangle.getHeight() * i,
                                   smallRectangle.getWidth(), smallRectangle.getHeight(), "yellow");
                shapes.push_back(new Rectangle(smallRectangle.getX(), smallRectangle.getY(),
                                               smallRectangle.getWidth(), smallRectangle.getHeight(), "yellow"));
            }
        if((containerRectangle.getHeight() - smallRectangle.getHeight() * rowNumber) >= smallRectangle.getWidth()){
            for(i = 0; i < containerRectangle.getWidth() / smallRectangle.getHeight(); i++){
                smallRectangle.set(smallRectangle.getHeight() * i, smallRectangle.getHeight() * rowNumber,
                                   smallRectangle.getHeight(), smallRectangle.getWidth(), "yellow");
                shapes.push_back(new Rectangle(smallRectangle.getX(), smallRectangle.getY(),
                                               smallRectangle.getWidth(), smallRectangle.getHeight(), "yellow"));
            }
        }
        if((containerRectangle.getWidth() - smallRectangle.getWidth() * columnNumber) >= smallRectangle.getHeight()){
            for(i = 0; i < containerRectangle.getHeight() / smallRectangle.getWidth(); i++){
                smallRectangle.set(smallRectangle.getWidth() * columnNumber, smallRectangle.getWidth() * i,
                                   smallRectangle.getHeight(), smallRectangle.getWidth(), "yellow");
                shapes.push_back(new Rectangle(smallRectangle.getX(), smallRectangle.getY(),
                                               smallRectangle.getWidth(), smallRectangle.getHeight(), "yellow"));
            }
        }
    }
    else{
        rowNumber = containerRectangle.getHeight() / smallRectangle.getWidth();
        columnNumber = containerRectangle.getWidth() / smallRectangle.getHeight();

        for(i = 0; i < rowNumber; i++)
            for(j = 0; j < columnNumber; j++){
                smallRectangle.set(smallRectangle.getHeight() * j, smallRectangle.getWidth() * i,
                               smallRectangle.getHeight(), smallRectangle.getWidth(), "yellow");
                shapes.push_back(new Rectangle(smallRectangle.getX(), smallRectangle.getY(),
                                               smallRectangle.getWidth(), smallRectangle.getHeight(), "yellow"));
            }

        if((containerRectangle.getHeight() - smallRectangle.getWidth() * rowNumber) >= smallRectangle.getHeight()){
            for(i = 0; i < containerRectangle.getWidth() / smallRectangle.getWidth(); i++){
                smallRectangle.set(smallRectangle.getWidth() * i, smallRectangle.getWidth() * rowNumber,
                                   smallRectangle.getWidth(), smallRectangle.getHeight(), "yellow");
                shapes.push_back(new Rectangle(smallRectangle.getX(), smallRectangle.getY(),
                                               smallRectangle.getWidth(), smallRectangle.getHeight(), "yellow"));
            }
        }
        if((smallRectangle.getWidth() - smallRectangle.getHeight() * columnNumber) >= smallRectangle.getWidth()){
            for(i = 0; i < containerRectangle.getHeight() / smallRectangle.getHeight(); i++){
                smallRectangle.set(smallRectangle.getHeight() * columnNumber, smallRectangle.getHeight() * i,
                                   smallRectangle.getWidth(), smallRectangle.getHeight(), "yellow");
                shapes.push_back(new Rectangle(smallRectangle.getX(), smallRectangle.getY(),
                                               smallRectangle.getWidth(), smallRectangle.getHeight(), "yellow"));
            }
            }
        }
    }

    //optimization for small rectangle inside rectangle
    void ComposedShape::optimalFit(Rectangle rectangle, Triangle triangle){
        int i, j, k,
            rowNumber = rectangle.getHeight() / (triangle.getSide() * SQRT3 / 2),
            columnNumber1 =  rectangle.getWidth() / triangle.getSide(),
            columnNumber2 = (rectangle.getWidth() - triangle.getSide() / 2) / triangle.getSide();
            shapes.push_back(new Rectangle(rectangle.getX(), rectangle.getY(),
                                           rectangle.getWidth(), rectangle.getHeight(), "red"));
            for(i = 0; i < rowNumber; i++){
                for(j = 0; j < columnNumber1; j++){
                    triangle.set(triangle.getSide() * j, triangle.getSide() * i * SQRT3 / 2,
                                 triangle.getSide() * j + triangle.getSide(), triangle.getSide() * i * SQRT3 / 2,
                                 triangle.getSide() * j + triangle.getSide() / 2, (triangle.getSide() / 2) * (i + 1) * SQRT3, "yellow");
                    shapes.push_back(new Triangle(triangle.getP1X(), triangle.getP1Y(),
                                                  triangle.getP2X(), triangle.getP2Y(),
                                                  triangle.getP3X(), triangle.getP3Y(), "yellow", triangle.getSide()));
                }
                for(k = 1; k <= columnNumber2; k++){
                    triangle.set(triangle.getSide() * k , triangle.getSide() * i * SQRT3 / 2,
                                 triangle.getSide() * k - triangle.getSide() / 2, triangle.getSide() * SQRT3 * (i + 1) / 2,
                                 triangle.getSide() * k + triangle.getSide() / 2, triangle.getSide() * SQRT3 * (i + 1) / 2, "yellow");
                    shapes.push_back(new Triangle(triangle.getP1X(), triangle.getP1Y(),
                                                  triangle.getP2X(), triangle.getP2Y(),
                                                  triangle.getP3X(), triangle.getP3Y(), "yellow", triangle.getSide()));
                }
            }
    }
    //optimization for small triangle inside rectangle
    void ComposedShape::optimalFit(Rectangle rectangle, Circle circle){
        int i, j,
              rowNumber,
              columnNumber;

          rowNumber = rectangle.getHeight() / (circle.getR() * 2);
          columnNumber = rectangle.getWidth() / (circle.getR() * 2);
          shapes.push_back(new Rectangle(rectangle.getX(), rectangle.getY(),
                                         rectangle.getWidth(), rectangle.getHeight(), "red"));
          if(rectangle.getHeight() >= circle.getR() * 2 && rectangle.getWidth() >= circle.getR() * 2){
              for(i = 0; i < circle.getR() * rowNumber * 2; i += circle.getR() * 2)
                  for(j = 0; j < circle.getR() * columnNumber * 2; j += circle.getR() * 2){
                      circle.set(circle.getR() + j, circle.getR() + i, circle.getR(), "yellow");
                      shapes.push_back(new Circle(circle.getX(), circle.getY(), circle.getR(), "yellow"));
              }
          }
          if((rectangle.getWidth() - (circle.getR() * 2 * columnNumber)) >= circle.getR() * SQRT3 &&
              ((rectangle.getHeight() - (circle.getR() * 2 * rowNumber)) < circle.getR() * SQRT3)){
              for(i = 1; i <= columnNumber; i++){
                  circle.set(rectangle.getWidth() - circle.getR(), circle.getR() * i * 2, circle.getR(), "yellow");
                  shapes.push_back(new Circle(circle.getX(), circle.getY(), circle.getR(), "yellow"));
              }
          }
          else if((rectangle.getHeight() - (circle.getR() * 2 * rowNumber)) >= circle.getR() * SQRT3 &&
              ((rectangle.getWidth() - (circle.getR() * 2 * columnNumber)) < circle.getR() * SQRT3)){
              for(i = 1; i <= rowNumber; i++){
                  circle.set(circle.getR() * i * 2, circle.getR() - circle.getR(), circle.getR(), "yellow");
                  shapes.push_back(new Circle(circle.getX(), circle.getY(), circle.getR(), "yellow"));
              }
          }
          else if((rectangle.getHeight() - (circle.getR() * 2 * rowNumber)) >= circle.getR() * SQRT3 &&
              ((rectangle.getWidth() - (circle.getR() * 2 * columnNumber)) >= circle.getR() * SQRT3)){
              for(i = 1; i <= rowNumber; i++){
                  circle.set(circle.getR() * i * 2, rectangle.getHeight() - circle.getR(), circle.getR(), "yellow");
                  shapes.push_back(new Circle(circle.getX(), circle.getY(), circle.getR(), "yellow"));
              }
              for(i = 1; i < columnNumber; i++){
                  circle.set(rectangle.getWidth() - circle.getR(), circle.getR() * i * 2, circle.getR(), "yellow");
                  shapes.push_back(new Circle(circle.getX(), circle.getY(), circle.getR(), "yellow"));
              }
          }
    }
    //optimization for small circle inside rectangle
    void ComposedShape::optimalFit(Triangle triangle, Rectangle rectangle){
        int temp;
        if(rectangle.getWidth() < rectangle.getHeight()){
            temp = rectangle.getWidth();
            rectangle.set(rectangle.getHeight(), temp, "yellow");
        }
        int rowNumber = (triangle.getSide() * SQRT3 / 2 - rectangle.getWidth() * SQRT3 / 2) / rectangle.getHeight(),
                        columnNumber;
        shapes.push_back(new Triangle(triangle.getP1X(), triangle.getP1Y(),
                                      triangle.getP2X(), triangle.getP2Y(),
                                      triangle.getP3X(), triangle.getP3Y(), "red", triangle.getSide()));

        double firstHeight = rectangle.getWidth() * SQRT3 /2;
        int i, j;
        for(i = 1; i <= rowNumber; i++){
            for(j = 0; j < (int)((rectangle.getHeight() * (i - 1) + firstHeight) / firstHeight); j++){
                rectangle.set(((triangle.getSide() / 2 ) - (rectangle.getWidth() / 2) - ((i - 1) * rectangle.getHeight() / SQRT3))
                                + rectangle.getWidth() * j,
                                rectangle.getWidth() * SQRT3 / 2 + rectangle.getHeight() * (i - 1),
                                rectangle.getWidth(), rectangle.getHeight(), "yellow");
                shapes.push_back(new Rectangle(rectangle.getX(), rectangle.getY(),
                                               rectangle.getWidth(), rectangle.getHeight(), "yellow"));
            }
        }
    }
    //optimization for small rectangle inside triangle
    void ComposedShape::optimalFit(Triangle containerTriangle, Triangle smallTriangle){
        int i, j, k,
            rowNumber = (containerTriangle.getSide() * SQRT3 / 2) /(smallTriangle.getSide() * SQRT3 / 2),
            columnNumber;
            shapes.push_back(new Triangle(containerTriangle.getP1X(), containerTriangle.getP1Y(),
                                          containerTriangle.getP2X(), containerTriangle.getP2Y(),
                                          containerTriangle.getP3X(), containerTriangle.getP3Y(), "red", containerTriangle.getSide()));
            for(i = 0; i < rowNumber; i++){
                for(j = 0; j <= i; j++){
                    smallTriangle.set((containerTriangle.getSide()/ 2) - (i * smallTriangle.getSide() / 2) + smallTriangle.getSide() * j,
                                       smallTriangle.getSide() * SQRT3 / 2 * i,
                                       (containerTriangle.getSide() / 2) - (i * smallTriangle.getSide() / 2) + smallTriangle.getSide() * j - smallTriangle.getSide() / 2,
                                       smallTriangle.getSide() * SQRT3 / 2 * (i + 1),
                                       (containerTriangle.getSide() / 2) - (i * smallTriangle.getSide() / 2) + smallTriangle.getSide() * j + smallTriangle.getSide() / 2,
                                       smallTriangle.getSide() * SQRT3 / 2 * (i + 1), "yellow");
                    shapes.push_back(new Triangle(smallTriangle.getP1X(), smallTriangle.getP1Y(),
                                                  smallTriangle.getP2X(), smallTriangle.getP2Y(),
                                                  smallTriangle.getP3X(), smallTriangle.getP3Y(), "yellow",
                                                  smallTriangle.getRotateDegree(), smallTriangle.getRotateX(),
                                                  smallTriangle.getRotateY(), smallTriangle.getSide()));
                }
                for(k = 0; k < i; k++){
                    smallTriangle.set((containerTriangle.getSide() / 2) - (i * smallTriangle.getSide() / 2) + smallTriangle.getSide() * k,
                                       smallTriangle.getSide() * SQRT3 / 2 * i,
                                       (containerTriangle.getSide() / 2) - (i * smallTriangle.getSide() / 2) + smallTriangle.getSide() * k - smallTriangle.getSide() / 2,
                                       smallTriangle.getSide() * SQRT3 / 2 * (i + 1),
                                       (containerTriangle.getSide() / 2) - (i * smallTriangle.getSide() / 2) + smallTriangle.getSide() * k + smallTriangle.getSide() / 2,
                                       smallTriangle.getSide() * SQRT3 / 2 * (i + 1), "yellow", 60,
                                       (containerTriangle.getSide() / 2) - (i * smallTriangle.getSide() / 2) + smallTriangle.getSide() * k + smallTriangle.getSide() / 2,
                                       smallTriangle.getSide() * SQRT3 / 2 * (i + 1), smallTriangle.getSide());
                    shapes.push_back(new Triangle(smallTriangle.getP1X(), smallTriangle.getP1Y(),
                                                  smallTriangle.getP2X(), smallTriangle.getP2Y(),
                                                  smallTriangle.getP3X(), smallTriangle.getP3Y(), "yellow",
                                                  smallTriangle.getRotateDegree(), smallTriangle.getRotateX(),
                                                  smallTriangle.getRotateY(), smallTriangle.getSide()));
                }
                    smallTriangle.set(0, 0, 0);
                    //initialize rotation tools
            }

    }
    //optimization for small triangle inside triangle
    void ComposedShape::optimalFit(Triangle triangle, Circle circle){
        int i, j,
            rowNumber = (triangle.getSide() - circle.getR() * SQRT3 * 2) / (circle.getR() * 2) + 1,
            columnNumber;
            shapes.push_back(new Triangle(triangle.getP1X(), triangle.getP1Y(),
                                          triangle.getP2X(), triangle.getP2Y(),
                                          triangle.getP3X(), triangle.getP3Y(), "red", triangle.getSide()));
            for(i = 0; i < rowNumber; i++)
                for(j = 0; j <= i; j++){
                circle.set(triangle.getSide() / 2 - (circle.getR() * i) + (circle.getR() * 2 * j),
                                        (circle.getR() * 2) + (circle.getR() * SQRT3 * i), circle.getR(), "yellow");
                shapes.push_back(new Circle(circle.getX(), circle.getY(), circle.getR(), "yellow",
                                            circle.getRotateDegree(), circle.getRotateX(), circle.getRotateY()));
                }

    }
            //optimization for small circle inside triangle
    void ComposedShape::optimalFit(Circle circle, Rectangle rectangle){
        int i, j,
            rowNumber,
            columnNumber;

            Rectangle greatRectangle, smallRectangle;
            greatRectangle.set(circle.getR() * 2 / SQRT2, circle.getR() * 2 / SQRT2, "yellow");
            smallRectangle = rectangle;

            double difference = (circle.getR() * SQRT2 - circle.getR()) / SQRT2;
            shapes.push_back(new Circle(circle.getX(), circle.getY(), circle.getR(), "red"));

            if(((greatRectangle.getHeight() / smallRectangle.getHeight()) * (greatRectangle.getWidth() / smallRectangle.getWidth())) >=
                ((greatRectangle.getHeight() / smallRectangle.getWidth()) * (greatRectangle.getWidth() / smallRectangle.getHeight()))){
                rowNumber = greatRectangle.getHeight() / smallRectangle.getHeight();
                columnNumber = greatRectangle.getWidth() / smallRectangle.getWidth();

                for(i = 0; i < rowNumber; i++)
                    for(j = 0; j < columnNumber; j++){
                        smallRectangle.set(smallRectangle.getWidth() * j + difference, smallRectangle.getHeight() * i + difference,
                                           smallRectangle.getWidth(), smallRectangle.getHeight(), "yellow");
                        shapes.push_back(new Rectangle(smallRectangle.getX(), smallRectangle.getY(),
                                                       smallRectangle.getWidth(), smallRectangle.getHeight(), "yellow"));
                    }
                if((greatRectangle.getHeight() - smallRectangle.getHeight() * rowNumber) >= smallRectangle.getWidth()){
                    for(i = 0; i < greatRectangle.getWidth() / smallRectangle.getHeight(); i++){
                        smallRectangle.set(smallRectangle.getHeight() * i + difference, smallRectangle.getHeight() * rowNumber + difference,
                        smallRectangle.getHeight(), smallRectangle.getWidth(), "yellow");
                        shapes.push_back(new Rectangle(smallRectangle.getX(), smallRectangle.getY(),
                                                       smallRectangle.getWidth(), smallRectangle.getHeight(), "yellow"));
                    }
                }
                if((greatRectangle.getWidth() - smallRectangle.getWidth() * columnNumber) >= smallRectangle.getHeight()){
                    for(i = 0; i < greatRectangle.getHeight() / smallRectangle.getWidth(); i++){
                        smallRectangle.set(smallRectangle.getWidth() * columnNumber + difference, smallRectangle.getWidth() * i + difference,
                                           smallRectangle.getHeight(), smallRectangle.getWidth(), "yellow");
                        shapes.push_back(new Rectangle(rectangle.getX(), rectangle.getY(),
                                                       rectangle.getWidth(), rectangle.getHeight(), "yellow"));
                    }
                }
            }
            else{
                rowNumber = greatRectangle.getHeight() / smallRectangle.getWidth();
                columnNumber = greatRectangle.getWidth() / smallRectangle.getHeight();

                for(i = 0; i < rowNumber; i++)
                    for(j = 0; j < columnNumber; j++){
                        smallRectangle.set(smallRectangle.getHeight()* j + difference, smallRectangle.getWidth() * i + difference,
                                           smallRectangle.getHeight(), smallRectangle.getWidth(), "yellow");
                        shapes.push_back(new Rectangle(rectangle.getX(), rectangle.getY(),
                                                       rectangle.getWidth(), rectangle.getHeight(), "yellow"));
                    }

                if((greatRectangle.getHeight() - smallRectangle.getWidth() * rowNumber) >= smallRectangle.getHeight()){
                    for(i = 0; i < greatRectangle.getWidth() / smallRectangle.getWidth(); i++){
                        smallRectangle.set(smallRectangle.getWidth() * i + difference, smallRectangle.getWidth() * rowNumber + difference,
                                           smallRectangle.getWidth(), smallRectangle.getHeight(), "yellow");
                        shapes.push_back(new Rectangle(rectangle.getX(), rectangle.getY(),
                                                       rectangle.getWidth(), rectangle.getHeight(), "yellow"));
                    }
                }
                if((greatRectangle.getWidth() - smallRectangle.getHeight() * columnNumber) >= smallRectangle.getWidth()){
                    for(i = 0; i < greatRectangle.getHeight() / smallRectangle.getHeight(); i++){
                        smallRectangle.set(smallRectangle.getHeight() * columnNumber + difference, smallRectangle.getHeight() * i + difference,
                                           smallRectangle.getWidth(), smallRectangle.getHeight(), "yellow");
                        shapes.push_back(new Rectangle(rectangle.getX(), rectangle.getY(),
                                                       rectangle.getWidth(), rectangle.getHeight(), "yellow"));
                    }
                }
            }
    }
    //optimization for small rectangle inside circle
    void ComposedShape::optimalFit(Circle circle, Triangle triangle){
        int i, j, k,
            rowNumber = (circle.getR() * SQRT3 / 2) / (triangle.getSide() * SQRT3 / 2),
            columnNumber;
            Triangle temp = triangle;
            shapes.push_back(new Circle(circle.getX(), circle.getY(), circle.getR(), "red"));
            for(i = 0; i < rowNumber; i++){
                for(j = 0; j <= i; j++){
                    triangle.set(circle.getR() - (i * triangle.getSide() / 2) + triangle.getSide() * j,
                                 circle.getR() + triangle.getSide() * SQRT3 / 2 * i,
                                 circle.getR() - (i * triangle.getSide() / 2) + triangle.getSide() * j - triangle.getSide() / 2,
                                 circle.getR() + triangle.getSide() * SQRT3 / 2 * (i + 1),
                                 circle.getR() - (i * triangle.getSide() / 2) + triangle.getSide() * j + triangle.getSide() / 2,
                                 circle.getR() + triangle.getSide() * SQRT3 / 2 * (i + 1), "yellow");
                    shapes.push_back(new Triangle(triangle.getP1X(), triangle.getP1Y(),
                                                  triangle.getP2X(), triangle.getP2Y(),
                                                  triangle.getP3X(), triangle.getP3Y(), "yellow",
                                                  triangle.getRotateDegree(),triangle.getRotateX(),
                                                  triangle.getRotateY(), triangle.getSide()));
                    triangle = temp;
                    for(k = 60; k <= 300; k += 60){
                        triangle.set(circle.getR() - (i * triangle.getSide() / 2) + triangle.getSide() * j,
                                     circle.getR() + triangle.getSide() * SQRT3 / 2 * i,
                                     circle.getR() - (i * triangle.getSide() / 2) + triangle.getSide() * j - triangle.getSide() / 2,
                                     circle.getR() + triangle.getSide() * SQRT3 / 2 * (i + 1),
                                     circle.getR() - (i * triangle.getSide() / 2) + triangle.getSide() * j + triangle.getSide() / 2,
                                     circle.getR() + triangle.getSide() * SQRT3 / 2 * (i + 1), "yellow", k,
                                     circle.getR(), circle.getR(), triangle.getSide());
                        shapes.push_back(new Triangle(triangle.getP1X(), triangle.getP1Y(),
                                                      triangle.getP2X(), triangle.getP2Y(),
                                                      triangle.getP3X(), triangle.getP3Y(), "yellow",
                                                      triangle.getRotateDegree(), triangle.getRotateX(),
                                                      triangle.getRotateY(), triangle.getSide()));
                        triangle = temp;
                    }
                    if(i < rowNumber -1){
                        triangle.set(circle.getR() - (i * triangle.getSide() / 2) + triangle.getSide() * j - triangle.getSide() / 2,
                                     circle.getR() + triangle.getSide() * SQRT3 / 2 * (i + 1),
                                     circle.getR() - (i * triangle.getSide() / 2) + triangle.getSide() * j,
                                     circle.getR() + triangle.getSide() * SQRT3 / 2 * (i + 2),
                                     circle.getR() - (i * triangle.getSide() / 2) + triangle.getSide() * j + triangle.getSide() / 2,
                                     circle.getR() + triangle.getSide() * SQRT3 / 2 * (i + 1), "yellow");
                        shapes.push_back(new Triangle(triangle.getP1X(), triangle.getP1Y(),
                                                      triangle.getP2X(), triangle.getP2Y(),
                                                      triangle.getP3X(), triangle.getP3Y(), "yellow",
                                                      triangle.getRotateDegree(), triangle.getRotateX(),
                                                      triangle.getRotateY(), triangle.getSide()));
                        triangle = temp;
                        for(k = 60; k <= 300; k += 60){
                            triangle.set(circle.getR() - (i * triangle.getSide() / 2) + triangle.getSide() * j - triangle.getSide() / 2,
                                         circle.getR() + triangle.getSide() * SQRT3 / 2 * (i + 1),
                                         circle.getR() - (i * triangle.getSide() / 2) + triangle.getSide() * j,
                                         circle.getR() + triangle.getSide() * SQRT3 / 2 * (i + 2),
                                         circle.getR() - (i * triangle.getSide() / 2) + triangle.getSide() * j + triangle.getSide() / 2,
                                         circle.getR() + triangle.getSide() * SQRT3 / 2 * (i + 1), "yellow", k,
                                         circle.getR(), circle.getR(), triangle.getSide());
                            shapes.push_back(new Triangle(triangle.getP1X(), triangle.getP1Y(),
                                                          triangle.getP2X(), triangle.getP2Y(),
                                                          triangle.getP3X(), triangle.getP3Y(), "yellow",
                                                          triangle.getRotateDegree(), triangle.getRotateX(),
                                                          triangle.getRotateY(), triangle.getSide()));
                            triangle = temp;
                        }
                    }
                }
            }
    }
    //optimization for small triangle inside circle
    void ComposedShape::optimalFit(Circle containerCircle, Circle smallCircle){
        int i, j, k,
            rowNumber = (containerCircle.getR() - smallCircle.getR() * SQRT3 * 2) / (smallCircle.getR() * 2) + 2,
            columnNumber;
            Circle temp = smallCircle;
            shapes.push_back(new Circle(containerCircle.getX(), containerCircle.getY(), containerCircle.getR(), "red"));
            for(i = 0; i < rowNumber; i++){
                for(j = 0; j <= i; j++){
                    smallCircle.set(containerCircle.getR() - (smallCircle.getR() * i) + (smallCircle.getR() * 2 * j),
                    containerCircle.getR() + (smallCircle.getR() * SQRT3 * i), smallCircle.getR(), "yellow");
                    shapes.push_back(new Circle(smallCircle.getX(), smallCircle.getY(), smallCircle.getR(), "yellow",
                                                smallCircle.getRotateDegree(), smallCircle.getRotateX(), smallCircle.getRotateY()));
                    for(k = 60; k <= 300; k += 60){
                        smallCircle.set(containerCircle.getR() - (smallCircle.getR() * i) + (smallCircle.getR() * 2 * j),
                                        containerCircle.getR() + (smallCircle.getR() * SQRT3 * i), smallCircle.getR(), "yellow", k,
                                        containerCircle.getR(), containerCircle.getR());
                        shapes.push_back(new Circle(smallCircle.getX(), smallCircle.getY(), smallCircle.getR(), "yellow",
                                                    smallCircle.getRotateDegree(), smallCircle.getRotateX(), smallCircle.getRotateY()));
                        smallCircle = temp;
                    }
                }
            }
    }
    //optimization for small circle inside circle

    ComposedShape& ComposedShape::operator +=(const Rectangle& rectangle){
        shapes.push_back(new Rectangle(rectangle.getX(), rectangle.getY(),
                                       rectangle.getWidth(), rectangle.getHeight(), "yellow"));
        return *this;
    }
    //overloads += to add rectangle to this composedShape
    ComposedShape& ComposedShape::operator +=(const Triangle& triangle){
        shapes.push_back(new Triangle(triangle.getP1X(), triangle.getP1Y(),
                                      triangle.getP2X(), triangle.getP2Y(),
                                      triangle.getP3X(), triangle.getP3Y(), "yellow",
                                      triangle.getRotateDegree(), triangle.getRotateX(),
                                      triangle.getRotateY(), triangle.getSide()));
        return *this;
    }
    //overloads += to add triangle to this composedShape
    ComposedShape& ComposedShape::operator +=(const Circle& circle){
        shapes.push_back(new Circle(circle.getX(), circle.getY(),
                                          circle.getR(), "yellow", circle.getRotateDegree(),
                                          circle.getRotateX(), circle.getRotateY()));
        return *this;
    }
    //overloads += to add circle to this composedShape

    ostream& operator <<(ostream& outputStream, const ComposedShape& composedShape){
        int i;
        for(Shape* i : composedShape.shapes){
            if(dynamic_cast<Rectangle*>(i)){
                Rectangle *rectangle = dynamic_cast<Rectangle*>(i);
                rectangle->draw(outputStream);
            }
            else if(dynamic_cast<Triangle*>(i)){
                Triangle *triangle = dynamic_cast<Triangle*>(i);
                triangle->draw(outputStream);
            }
            else if(dynamic_cast<Circle*>(i)){
                Circle *circle = dynamic_cast<Circle*>(i);
                circle->draw(outputStream);
            }
        }
        return outputStream;
    }
    //overloads << for composedShape object
    ComposedShape::~ComposedShape(){}
}
