driver: shapeException.o Shape.o Rectangle.o Triangle.o Circle.o ComposedShape.o Polygon.o PolygonVect.o PolygonDyn.o main.o
	g++ -o driver shapeException.o Shape.o Rectangle.o Triangle.o Circle.o ComposedShape.o Polygon.o PolygonVect.o 
	PolygonDyn.o main.o

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

PolygonDyn.o: shapeLib/PolygonDyn.cpp
	g++ -c -std=c++11 shapeLib/PolygonDyn.cpp

PolygonVect.o: shapeLib/PolygonVect.cpp
	g++ -c -std=c++11 shapeLib/PolygonVect.cpp

Polygon.o: shapeLib/Polygon.cpp
	g++ -c -std=c++11 shapeLib/Polygon.cpp

ComposedShape.o: shapeLib/ComposedShape.cpp
	g++ -c -std=c++11 shapeLib/ComposedShape.cpp

Circle.o: shapeLib/Circle.cpp
	g++ -c -std=c++11 shapeLib/Circle.cpp

Triangle.o: shapeLib/Triangle.cpp
	g++ -c -std=c++11 shapeLib/Triangle.cpp

Rectangle.o: shapeLib/Rectangle.cpp
	g++ -c -std=c++11 shapeLib/Rectangle.cpp

Shape.o: shapeLib/Shape.cpp
	g++ -c -std=c++11 shapeLib/Shape.cpp

shapeException/shapeException.o: shapeException/shapeException.cpp
	g++ -c -std=c++11 shapeException/shapeException.cpp
