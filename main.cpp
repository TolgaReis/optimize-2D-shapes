#include<iostream>
#include<fstream>
#include<vector>
#include"shapeLib/Shape.h"
#include"shapeLib/Rectangle.h"
#include"shapeLib/Triangle.h"
#include"shapeLib/Circle.h"
#include"shapeLib/ComposedShape.h"
#include"shapeLib/PolygonVect.h"
#include"shapeLib/PolygonDyn.h"
using namespace std;
using namespace shape;

ostream& operator <<(ostream& outputStream, const Shape& rightSide);
//Overloaded global operator<< can be used for printing the shapes to SVG files
void printAll(ostream& outputStream, const vector<Shape*> rightSide);
//takes a vector of Shape pointers and prints all shapes to an SVG file
void printPoly(ostream& outputStream, const vector<Shape*> rightSide);
//takes a vector of Shape pointers and prints all Polygon shapes to an SVG file
vector<Polygon*> convertAll(const vector<Shape*> rightSide);
//takes a vector of Shape pointers, converts all shapes to Polygons and returns a new vector with the new shapes
void sortShapes(vector<Shape*> &rightSide);
//takes a vector of Shape pointers and increasingly sorts them with respect to their areas

int main(){
    ofstream outputStream;
    //output stream to write SVG file
    outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>\n";
    Rectangle rectangle[3] = {{}, {500, 500, "red"}, {0, 0, 10, 10, "yellow"}};
    //initialize 3 rectangle object with constructor
    Triangle triangle[3] = {{}, {100, 0, 0, 173.2, 200, 173.2, "red", 200}, {10, 0, 0, 17.32, 20, 17.32, "yellow", 0, 0, 0, 10}};
    //initialize 3 triangle object with constructor
    Circle circle[3] = {{}, {200, 200, 200, "red"}, {10, 10, 10, "yellow", 0, 0, 0}};
    //initialize 3 circle object with constructor
    Polygon::Point2D point(0, 0);
    PolygonVect polygonVect[5] = {{}, {point}, {rectangle[2]}, {triangle[2]}, {circle[2]}};
    //tests the constructors of the polygonVect class
    PolygonDyn polygonDyn[5] = {{}, {point}, {rectangle[2]}, {triangle[2]}, {circle[2]}};
    //tests the constructors of the polygonVect class

    cout << "***TEST PART OF THE PROGRAM***" << endl << endl;
    cout << "Overloaded << operator will be tested with classes." << endl;
    cout << "printAll function: " << endl;
    cout << "printAll.svg created." << endl;
    cout << "printAllTriangle.svg created." << endl;
    cout << "printAllCircle.svg created." << endl;
    outputStream.open("printAll.svg");
    outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
    vector<Shape*> shapes;
    shapes.push_back(&rectangle[1]);
    shapes.push_back(&triangle[2]);
    shapes.push_back(&circle[2]);
    printAll(outputStream, shapes);
    outputStream << "</svg>" << endl;
    outputStream.close();

    cout << "printPoly function: " << endl;
    outputStream.open("printPoly.svg");
    outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
    vector<Shape*> polygon;
    polygon.push_back(&polygonDyn[2]);
    printPoly(outputStream, polygon);
    outputStream << "</svg>" << endl;
    outputStream.close();

    cout << "Test sorting shapes: " << endl;
    sortShapes(shapes);
    for(Shape* i: shapes)
        cout << i->area();
    cout << endl;

    cout << "Test convertall: " << endl;
    for(Polygon* p: convertAll(shapes))
        p->displayPoints();

    //TEST PART OF THE RECTANGLE
    cout << "***Test Part of the Rectangle Class***" << endl << endl;
    cout << "rectangle[2] before increment: " << rectangle[2];
    cout << endl;
    cout << "rectangle[2] after post increment: " << rectangle[2]++;
    cout << endl;
    try{
        cout << "rectangle[2] after pre decrement: "<< --rectangle[2];
    }
    catch(shapeException& se){
        cout << se.what();
    }
    cout << endl;
    cout << "rectangle[2] after pre increment: " << ++rectangle[2];
    cout << endl;
    try{
        cout << "rectangle[2] after post decrement: "<< rectangle[2]++;
    }
    catch(shapeException& se){
        cout << se.what();
    }
    cout << endl;
    cout << "is rectangle[0] and rectangle[0] equal: " << (rectangle[0] == rectangle[0]);
    cout << endl;
    cout << "is rectangle[1] and rectangle[2] not equal: " << (rectangle[1] != rectangle[2]);
    cout << endl;
    cout << "is rectangle[1] larger than rectangle[2]: " << (rectangle[1] > rectangle[2]);
    cout << endl;
    cout << "is rectangle[1] larger or equal to rectangle[2]: " << (rectangle[1] >= rectangle[2]);
    cout << endl;
    cout << "is rectangle[2] smaller than rectangle[1]: " << (rectangle[2] < rectangle[1]);
    cout << endl;
    cout << "is rectangle[2] smaller than or equal to rectangle[1]: " << (rectangle[2] <= rectangle[1]);
    cout << endl << endl;

    //TEST PART OF TRIANGLE CLASS
    cout << "***Test Part of the Triangle Class***" << endl << endl;
    cout << "triangle[2] before increment: " << triangle[2];
    cout << endl;
    cout << "triangle[2] after post increment: " << triangle[2]++;
    cout << endl;
    try{
        cout << "triangle[2] after pre decrement: "<< --triangle[2];
    }
    catch(shapeException& se){
        cout << se.what();
    }
    cout << endl;
    cout << "triangle[2] after pre increment: " << ++triangle[2];
    cout << endl;
    try{
        cout << "triangle[2] after post decrement: "<< triangle[2]++;
    }
    catch(shapeException& se){
        cout << se.what();
    }
    cout << endl;
    cout << "is triangle[0] and triangle[0] equal: " << (triangle[0] == triangle[0]);
    cout << endl;
    cout << "is triangle[1] and triangle[2] not equal: " << (triangle[1] != triangle[2]);
    cout << endl;
    cout << "is triangle[1] larger than triangle[2]: " << (triangle[1] > triangle[2]);
    cout << endl;
    cout << "is triangle[1] larger or equal to triangle[2]: " << (triangle[1] >= triangle[2]);
    cout << endl;
    cout << "is triangle[2] smaller than triangle[1]: " << (triangle[2] < triangle[1]);
    cout << endl;
    cout << "is triangle[2] smaller than or equal to triangle[1]: " << (triangle[2] <= triangle[1]);
    cout << endl << endl;

    //TEST PART OF CIRCLE CLASS
    cout << "***Test Part of the Circle Class***" << endl << endl;
    cout << "circle[2] before increment: " << circle[2];
    cout << endl;
    cout << "circle[2] after post increment: " << circle[2]++;
    cout << endl;
    try{
        cout << "circle[2] after pre decrement: "<< --circle[2];
    }
    catch(shapeException& se){
        cout << se.what();
    }
    cout << endl;
    cout << "circle[2] after pre increment: " << ++circle[2];
    cout << endl;
    try{
        cout << "circle[2] after post decrement: "<< circle[2]++;
    }
    catch(shapeException& se){
        cout << se.what();
    }
    cout << endl;
    cout << "is circle[0] and circle[0] equal: " << (circle[0] == circle[0]);
    cout << endl;
    cout << "is circle[1] and circle[2] not equal: " << (circle[1] != circle[2]);
    cout << endl;
    cout << "is circle[1] larger than circle[2]: " << (circle[1] > circle[2]);
    cout << endl;
    cout << "is circle[1] larger or equal to circle[2]: " << (circle[1] >= circle[2]);
    cout << endl;
    cout << "is circle[2] smaller than circle[1]: " << (circle[2] < circle[1]);
    cout << endl;
    cout << "is circle[2] smaller than or equal to circle[1]: " << (circle[2] <= circle[1]);
    cout << endl << endl;

    //TEST PART OF THE POLYGONDYN
   cout << "***Test Part of The PolygonDyn Class***" << endl << endl;
   cout << "Coordinate points of the rectangle polygonDyn: points = '";
   polygonDyn[2].displayPoints();
   cout << "'" << endl;
   cout << "Size of the coordinates of the circle polygonDyn: " << polygonDyn[4].getSize() << endl;
   cout << "Rotate degree and coordinates of the polygonDyn polyline: rotate("
        << polygonDyn[3].getRotateDegree() << " "
        << polygonDyn[3].getRotateX() << " "
        << polygonDyn[3].getRotateY() << ")" << endl;
   cout << "Color of the circle polygonDyn: fill = '" << polygonDyn[4].getColor() << "'" << endl;
   cout << endl;
   cout << "First polygonDyn object info (before assignment): " << endl
        << "points= '";
   polygonDyn[0].displayPoints();
   cout << "'" << endl
        << "size: " << polygonDyn[0].getSize() << endl
        << "rotate("
        << polygonDyn[0].getRotateDegree() << " "
        << polygonDyn[0].getRotateX() << " "
        << polygonDyn[0].getRotateY() << ")" << endl
        << "fill= '" << polygonDyn[1].getColor() << "'" << endl;
   polygonDyn[0] = polygonDyn[2];
   cout << endl;
   cout << "First polygonDyn object info (after assignment): " << endl
        << "points= '";
   polygonDyn[0].displayPoints();
   cout << "'" << endl
        << "size: " << polygonDyn[0].getSize() << endl
        << "rotate("
        << polygonDyn[0].getRotateDegree() << " "
        << polygonDyn[0].getRotateX() << " "
        << polygonDyn[0].getRotateY() << ")" << endl
        << "fill= '" << polygonDyn[0].getColor() << "'" << endl;
   cout << "Are polygonDyn[0] and polygonDyn[2] equal: " << (polygonDyn[0] == polygonDyn[2]) << endl;
   cout << "Are polygonDyn[0] and polygonDyn[3] equal: " << (polygonDyn[0] == polygonDyn[3]) << endl;
   cout << endl;
   cout << "Are polygonDyn[0] and polygonDyn[2] not equal: " << (polygonDyn[0] != polygonDyn[2]) << endl;
   cout << "Are polygonDyn[0] and polygonDyn[3] not equal: " << (polygonDyn[0] != polygonDyn[3]) << endl;
   cout << "polygonDyn[0] + polygonDyn[3] points = '";
   polygonDyn[0] = polygonDyn[0] + polygonDyn[3];
   polygonDyn[0].displayPoints();
   cout << "'" << endl;
   cout << "Write polygonDyn rectangle, triangle and circle to svg file." << endl;
   outputStream.open("polygonDynRectangle.svg");
   outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
   outputStream << polygonDyn[2] << endl;
   outputStream << "</svg>";
   outputStream.close();

   outputStream.open("polygonDynTriangle.svg");
   outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
   outputStream << polygonDyn[3] << endl;
   outputStream << "</svg>";
   outputStream.close();

   outputStream.open("polygonDynCircle.svg");
   outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
   outputStream << polygonDyn[4] << endl;
   outputStream << "</svg>";
   outputStream.close();

   //TEST PART OF THE POLYGONVECT
  cout << "***Test Part of The PolygonVect Class***" << endl << endl;
  cout << "Coordinate points of the rectangle polygonDyn: points = '";
  polygonVect[2].displayPoints();
  cout << "'" << endl;
  cout << "Size of the coordinates of the circle polygonVect: " << polygonVect[4].getSize() << endl;
  cout << "Rotate degree and coordinates of the polygonVect polyline: rotate("
       << polygonVect[3].getRotateDegree() << " "
       << polygonVect[3].getRotateX() << " "
       << polygonVect[3].getRotateY() << ")" << endl;
  cout << "Color of the circle polygonVect: fill = '" << polygonVect[4].getColor() << "'" << endl;
  cout << endl;
  cout << "Are polygonVect[0] and polygonVect[0] equal: " << (polygonVect[0] == polygonVect[2]) << endl;
  cout << endl;
  cout << "Are polygonVect[0] and polygonVect[2] not equal: " << (polygonVect[0] != polygonVect[2]) << endl;
  cout << "Are polygonVect[0] and polygonVect[3] not equal: " << (polygonVect[0] != polygonVect[3]) << endl;
  cout << "Write polygonVect rectangle, triangle and circle to svg file." << endl;
  outputStream.open("polygonVectRectangle.svg");
  outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
  outputStream << polygonVect[2] << endl;
  outputStream << "</svg>";
  outputStream.close();

  outputStream.open("polygonVectTriangle.svg");
  outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
  outputStream << polygonVect[3] << endl;
  outputStream << "</svg>";
  outputStream.close();

  outputStream.open("polygonVectCircle.svg");
  outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
  outputStream << polygonVect[4] << endl;
  outputStream << "</svg>";
  outputStream.close();

    //TEST PART OF THE COMPOSEDSHAPE CLASS
   ComposedShape composedShape[9] = {{rectangle[1], rectangle[2]},
                                     {rectangle[1], triangle[2]},
                                     {rectangle[1], circle[2]},
                                     {triangle[1], rectangle[2]},
                                     {triangle[1], triangle[2]},
                                     {triangle[1], circle[2]},
                                     {circle[1], circle[2]},
                                     {circle[1], triangle[2]},
                                     {circle[1], circle[2]}};
   cout << endl;
   cout << "***Test Part of The ComposedShape Class***" << endl;
   cout << "Creates 9 svg files for small shapes inside container shapes: " << endl;
   cout << "1. rectangleInsideRectangle.svg" << endl
        << "2. triangleInsideRectangle.svg" << endl
        << "3. circleInsideRectangle.svg" << endl
        << "4. rectangleInsideTriangle.svg" << endl
        << "5. triangleInsideTriangle.svg" << endl
        << "6. circleInsideTriangle.svg" << endl
        << "7. rectangleInsideCircle.svg" << endl
        << "8. triangleInsideCircle.svg" << endl
        << "9. circleInsideCircle.svg" << endl;

   outputStream.open("rectangleInsideRectangle.svg");
   outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
   composedShape[0].optimalFit(rectangle[1], rectangle[2]);
   outputStream << composedShape[0] << endl;
   outputStream << "</svg>" << endl;
   outputStream.close();

   outputStream.open("triangleInsideRectangle.svg");
   outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
   composedShape[1].optimalFit(rectangle[1], triangle[2]);
   outputStream << composedShape[1] << endl;
   outputStream << "</svg>" << endl;
   outputStream.close();

   outputStream.open("circleInsideRectangle.svg");
   outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
   composedShape[2].optimalFit(rectangle[1], circle[2]);
   outputStream << composedShape[2] << endl;
   outputStream << "</svg>" << endl;
   outputStream.close();

   outputStream.open("rectangleInsideTriangle.svg");
   outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
   composedShape[3].optimalFit(triangle[1], rectangle[2]);
   outputStream << composedShape[3] << endl;
   outputStream << "</svg>" << endl;
   outputStream.close();

   outputStream.open("triangleInsideTriangle.svg");
   outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
   composedShape[4].optimalFit(triangle[1], triangle[2]);
   outputStream << composedShape[4] << endl;
   outputStream << "</svg>" << endl;
   outputStream.close();

   outputStream.open("circleInsideTriangle.svg");
   outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
   composedShape[5].optimalFit(triangle[1], circle[2]);
   outputStream << composedShape[5] << endl;
   outputStream << "</svg>" << endl;
   outputStream.close();

   outputStream.open("rectangleInsideCircle.svg");
   outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
   composedShape[6].optimalFit(circle[1], rectangle[2]);
   outputStream << composedShape[6] << endl;
   outputStream << "</svg>" << endl;
   outputStream.close();

   outputStream.open("triangleInsideCircle.svg");
   outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
   composedShape[7].optimalFit(circle[1], triangle[2]);
   outputStream << composedShape[7] << endl;
   outputStream << "</svg>" << endl;
   outputStream.close();

   outputStream.open("circleInsideCircle.svg");
   outputStream << "<svg  version='1.1' xmlns='http://www.w3.org/2000/svg'>" << endl;
   composedShape[8].optimalFit(circle[1], circle[2]);
   outputStream << composedShape[8] << endl;
   outputStream << "</svg>" << endl;
   outputStream.close();


    return 0;
}

ostream& operator <<(ostream& outputStream, const Shape& rightSide){
    rightSide.draw(outputStream);
}

void printAll(ostream& outputStream, const vector<Shape*> rightSide){
    for(Shape* i: rightSide)
        i->draw(outputStream);
}

void printPoly(ostream& outputStream, const vector<Shape*> rightSide){
    for(Shape* i: rightSide){
        if(dynamic_cast<Polygon*>(i))
            i->draw(outputStream);
    }
}

vector<Polygon*> convertAll(const vector<Shape*> rightSide){
    vector<Polygon*> polygon;
    for(Shape* i: rightSide){
        if(dynamic_cast<Rectangle*>(i)){
            Rectangle *rectangle = dynamic_cast<Rectangle*>(i);
            polygon.push_back(new PolygonVect(*rectangle));
        }
        else if(dynamic_cast<Triangle*>(i)){
            Triangle *triangle = dynamic_cast<Triangle*>(i);
            polygon.push_back(new PolygonVect(*triangle));
        }
        else if(dynamic_cast<Circle*>(i)){
            Circle *circle = dynamic_cast<Circle*>(i);
            polygon.push_back(new PolygonVect(*circle));
        }
    }
    return polygon;
}

void sortShapes(vector<Shape*> &rightSide){
    int i, j;
    Shape* temp;   // holding variable
    for (i=0; i< (rightSide.size() -1); i++)
        for(j = (i+1); j < rightSide.size(); j++){
            if (rightSide[i]->area() > rightSide[j]->area()){
                temp = rightSide[i];          // swap
                rightSide[i] = rightSide[j];
                rightSide[j] = temp;
            }
        }
}
