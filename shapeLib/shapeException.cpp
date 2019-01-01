#include"shapeException.h"

namespace shape{
    const char* shapeException::what() const throw(){
        return _c.c_str();
    }
}
