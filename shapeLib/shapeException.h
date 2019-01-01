#ifndef SHAPEEXCEPTION_H
#define SHAPEEXCEPTION_H
#include<iostream>
#include<exception>
using namespace std;

namespace shape{
    class shapeException{
    public:
        shapeException(string c): _c(c){}
        const char* what() const throw();
    private:
        string _c;
    };
}
#endif
